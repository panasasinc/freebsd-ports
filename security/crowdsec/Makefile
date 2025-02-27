PORTNAME=	crowdsec
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	marco@crowdsec.net
COMMENT=	CrowdSec lightweight and collaborative security engine
WWW=		https://github.com/crowdsecurity/crowdsec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git@lite

USES=		gmake go:1.19,no_targets

USE_GITHUB=	yes
GH_ACCOUNT=	crowdsecurity
GH_PROJECT=	crowdsec
GH_TAGNAME=	${DISTVERSIONFULL}-freebsd
_BUILD_TAG=	8a738f5b
USE_RC_SUBR=	crowdsec

MAKE_ARGS=	BUILD_VERSION="${DISTVERSIONFULL}" \
		BUILD_TAG="${_BUILD_TAG}" \
		BUILD_VENDOR_FLAGS="-mod=vendor -modcacherw" \
		DEFAULT_CONFIGDIR="${PREFIX}/etc/crowdsec" \
		DEFAULT_DATADIR="/var/db/crowdsec/data"

ALL_TARGET=	build

SUB_FILES=	pkg-deinstall pkg-install pkg-message crowdsec.cron upgrade-hub

OPTIONS_DEFINE=	FIREWALL_BOUNCER
OPTIONS_DEFAULT=

FIREWALL_BOUNCER_DESC=	Depend on security/crowdsec-firewall-bouncer
FIREWALL_BOUNCER_RUN_DEPENDS=	crowdsec-firewall-bouncer>=0.0.23.r2:security/crowdsec-firewall-bouncer

PLUGIN_DIR=	${PREFIX}/lib/crowdsec/plugins
STAGE_PLUGINS=	${STAGEDIR}${PLUGIN_DIR}
STAGE_BIN=	${STAGEDIR}${PREFIX}/bin

post-patch:
	@${REINPLACE_CMD} 's,/etc/crowdsec/,${ETCDIR}/,g' \
		${WRKSRC}/config/config.yaml

	@${REINPLACE_CMD} 's,/var/lib/,/var/db/,g' \
		${WRKSRC}/config/config.yaml

do-install:
	#
	# Binaries
	#

	${INSTALL_PROGRAM} ${WRKSRC}/cmd/crowdsec/crowdsec ${STAGE_BIN}/
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/crowdsec-cli/cscli ${STAGE_BIN}/
	${LN} -s cscli ${STAGE_BIN}/crowdsec-cli

	@${MKDIR} ${STAGE_PLUGINS}
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/notifications/email/notification-email ${STAGE_PLUGINS}/
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/notifications/http/notification-http ${STAGE_PLUGINS}/
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/notifications/slack/notification-slack ${STAGE_PLUGINS}/
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/notifications/splunk/notification-splunk ${STAGE_PLUGINS}/

	#
	# Configuration
	#

	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@(cd ${WRKSRC}/config && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR})

	@${MV} ${STAGEDIR}${ETCDIR}/acquis.yaml \
		${STAGEDIR}${ETCDIR}/acquis.yaml.sample

	@${MV} ${STAGEDIR}${ETCDIR}/config.yaml \
		${STAGEDIR}${ETCDIR}/config.yaml.sample

	@${MV} ${STAGEDIR}${ETCDIR}/console.yaml \
		${STAGEDIR}${ETCDIR}/console.yaml.sample

	@${MV} ${STAGEDIR}${ETCDIR}/profiles.yaml \
		${STAGEDIR}${ETCDIR}/profiles.yaml.sample

	# managed by "cscli simulation"
	@${MV} ${STAGEDIR}${ETCDIR}/simulation.yaml \
		${STAGEDIR}${ETCDIR}/simulation.yaml.sample

	#
	# Plugin configuration
	#

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/email
	@${MV} ${WRKSRC}/plugins/notifications/email/email.yaml \
		${STAGEDIR}${ETCDIR}/notifications/email.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/http
	@${MV} ${WRKSRC}/plugins/notifications/http/http.yaml \
		${STAGEDIR}${ETCDIR}/notifications/http.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/slack
	@${MV} ${WRKSRC}/plugins/notifications/slack/slack.yaml \
		${STAGEDIR}${ETCDIR}/notifications/slack.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/splunk
	@${MV} ${WRKSRC}/plugins/notifications/splunk/splunk.yaml \
		${STAGEDIR}${ETCDIR}/notifications/splunk.yaml.sample

	# updated by "cscli machines" at first service start
	@${MV} ${STAGEDIR}${ETCDIR}/local_api_credentials.yaml \
		${STAGEDIR}${ETCDIR}/local_api_credentials.yaml.sample

	# updated by "cscli capi" at first service start
	@${MV} ${STAGEDIR}${ETCDIR}/online_api_credentials.yaml \
		${STAGEDIR}${ETCDIR}/online_api_credentials.yaml.sample

	#
	# Data
	#

	@${MKDIR} ${STAGEDIR}${ETCDIR}/hub
	@${MKDIR} ${STAGEDIR}/var/db/crowdsec/data

	#
	# Cron
	#

	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/crowdsec
	${INSTALL_DATA} ${WRKDIR}/upgrade-hub \
		${STAGEDIR}${PREFIX}/libexec/crowdsec/upgrade-hub

	#
	# Cleanup
	#

	@${RM} ${STAGEDIR}${ETCDIR}/acquis_win.yaml
	@${RM} ${STAGEDIR}${ETCDIR}/config_win_no_lapi.yaml
	@${RM} ${STAGEDIR}${ETCDIR}/config_win.yaml
	@${RM} ${STAGEDIR}${ETCDIR}/crowdsec.cron.daily
	@${RM} ${STAGEDIR}${ETCDIR}/crowdsec.service
	@${RM} ${STAGEDIR}${ETCDIR}/dev.yaml
	@${RM} ${STAGEDIR}${ETCDIR}/user.yaml
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/email
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/http
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/slack
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/splunk

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
	${INSTALL_DATA} ${WRKDIR}/crowdsec.cron ${STAGEDIR}${PREFIX}/etc/cron.d/crowdsec

.include <bsd.port.mk>
