PORTNAME=	pyradio
DISTVERSION=	0.8.9.36
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Curses based Internet radio player
WWW=		https://github.com/coderholic/pyradio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${PKGNAMEPREFIX}dnspython>=2.2.1:dns/py-dnspython@${PY_FLAVOR} \
		${PKGNAMEPREFIX}psutil>=5.9.2:sysutils/py-psutil@${PY_FLAVOR} \
		${PKGNAMEPREFIX}requests>=2.28.1:www/py-requests@${PY_FLAVOR} \
		${PKGNAMEPREFIX}wheel>=0.38.4:devel/py-wheel@${PY_FLAVOR} \
		bash:shells/bash
RUN_DEPENDS=	${PKGNAMEPREFIX}dnspython>=2.2.1:dns/py-dnspython@${PY_FLAVOR} \
		${PKGNAMEPREFIX}psutil>=5.9.2:sysutils/py-psutil@${PY_FLAVOR} \
		${PKGNAMEPREFIX}requests>=2.28.1:www/py-requests@${PY_FLAVOR} \
		${PKGNAMEPREFIX}wheel>=0.38.4:devel/py-wheel@${PY_FLAVOR} \
		bash:shells/bash

USES=		desktop-file-utils python:3.7+
USE_GITHUB=	yes
GH_ACCOUNT=	coderholic
USE_PYTHON=	autoplist distutils

PLIST_FILES=	share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png
PORTDOCS=	*

OPTIONS_DEFINE=			DOCS
OPTIONS_DEFAULT=		MPV
OPTIONS_SINGLE=			MEDIA_PLAYER
OPTIONS_SINGLE_MEDIA_PLAYER=	MPLAYER MPV VLC

# override predefined
MPV_DESC=	Mpv media player support
VLC_DESC=	VLC media player support

DOCS_PLIST_FILES=	man/man1/pyradio.1.gz \
			man/man1/pyradio_rb.1.gz \
			man/man1/pyradio_server.1.gz
MPLAYER_RUN_DEPENDS+=	mplayer:multimedia/mplayer
MPV_RUN_DEPENDS+=	mpv:multimedia/mpv
VLC_RUN_DEPENDS+=	vlc:multimedia/vlc

post-patch:
	${SED} -i.bak -e 's/\(distro =\) None/\1 ${OPSYS}/' \
	 -e 's/\(enable_notifications =\) -1/\1 0/' \
	 	${WRKSRC}/pyradio/config

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/pyradio*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}/

post-install:
	${INSTALL_DATA} ${WRKSRC}/devel/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}/${PORTNAME}.desktop
	${INSTALL_DATA} ${WRKSRC}/devel/${PORTNAME}.png \
	       	${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
