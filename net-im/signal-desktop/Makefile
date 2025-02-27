PORTNAME=	signal-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2.0
CATEGORIES=	net-im
MASTER_SITES=	LOCAL/mikael/signal-desktop/:yarn \
		LOCAL/mikael/signal-desktop/:electron_gyp \
		LOCAL/mikael/signal-desktop/:npm \
		https://build-artifacts.signal.org/desktop/:sqlcipher
DISTFILES=	signal-desktop-${DISTVERSION}-yarn-cache.tar.gz:yarn \
		signal-desktop-${DISTVERSION}-electron-gyp-cache.tar.gz:electron_gyp \
		signal-desktop-${DISTVERSION}-npm-cache.tar.gz:npm \
		sqlcipher-4.5.2--3.0.7-4587e88a4219cb76fd595a5b73f82bfd919b235d75626f40783525f4f58a7503.tar.gz:sqlcipher
		

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Cross-platform centralized encrypted messaging service
WWW=		https://signal.org/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	${LOCALBASE}/lib/libringrtc.so:multimedia/ringrtc \
		${LOCALBASE}/lib/libsignal_node.so:net-im/libsignal-node \
		app-builder>0:devel/app-builder \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		npm:www/npm-node16 \
		${LOCALBASE}/lib/libcrypto.a:security/openssl-devel \
		vips>0:graphics/vips \
		yarn:www/yarn-node16
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libatspi.so:accessibility/at-spi2-core \
		libcups.so:print/cups \
		libdbus-1.so:devel/dbus \
		libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2 \
		libFLAC.so:audio/flac \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpng16.so:graphics/png \
		libsnappy.so:archivers/snappy \
		libwebp.so:graphics/webp \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence

USES=		desktop-file-utils gettext-runtime gl gnome jpeg xorg
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_PROJECT=	Signal-Desktop

USE_GL=		gbm gl
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 libxml2 libxslt pango
USE_XORG=	x11 xcb xcomposite xdamage xext xfixes xi xrandr xrender xtst

PACKAGE_ENV=	SIGNAL_ENV=production
MAKE_ENV+=	ELECTRON_OVERRIDE_DIST_PATH=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} \
		HOME=${WRKDIR} \
		PLAYWRIGHT_BROWSERS_PATH=${WRKDIR}/.cache \
		PLAYWRIGHT_SKIP_BROWSER_DOWNLOAD=true \
		PLAYWRIGHT_SKIP_VALIDATE_HOST_REQUIREMENTS=true \
		USE_SYSTEM_APP_BUILDER=true \
		SOURCE_DATE_EPOCH=${_BUILD_DATE}

# Don't download electron binary distribution on electron node_modules installation
MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1

# Don't create __pycache__ directory when executing node-gyp
# This is a workaround to avoid filesystem violations during poudriere build
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1

MAKE_ENV+=	ESBUILD_BINARY_PATH=${WRKDIR}/esbuild-freebsd-64/package/bin/esbuild

_BUILD_DATE=	$$(date +'%s')

ELECTRON_VER_MAJOR=	21

# ll work/.cache/yarn/v6 | egrep "ringrtc|signal-client|npm-better-sqlite3|esbuild-freebsd-64"
NPM_SIGNAL_DIR=		npm-@signalapp-libsignal-client-0.21.1-381d6162ae0e7719dc625780c1d6c3f9f558c33d-integrity
NPM_RINGRTC_DIR=	npm-ringrtc-2.22.0-9a9d9fbc1ca43e7a0707a960ce9642dbf82dc64a/
NPM_SQLITE3_DIR=	npm-@signalapp-better-sqlite3-8.0.3-c279ca3f1d1e7f6554d2a629d717e96e1ec45809-integrity/
NPM_PLAYWRITE_DIR=	npm-playwright-core-1.17.1-a16e0f89284a0ed8ae6d77e1c905c84b8a2ba022-integrity
NPM_ESBUILD_VERS=	0.15.8

ESBUILD_ARCH=		${ARCH:S/aarch64/arm/:S/amd64//}
NODE_ARCH=		${ARCH:S/aarch64/arm64/:S/amd64/x64/}
APP_OUT_DIR=		linux-${ARCH:S/aarch64/arm64-/:S/amd64//}unpacked

PLIST_SUB=		NODE_ARCH=${NODE_ARCH} \
			SHARP_ARCH=${ARCH:S/aarch64/arm64v8/:S/amd64/x64/}

do-build:
	${ECHO_CMD} 'yarn-offline-mirror "../yarn-cache"' > ${WRKSRC}/.yarnrc

# electron-builder is stupid and tries to open ${LOCALBASE}/share/electron21/electron with WRITE priv
# copy ${LOCALBASE}/share/electron21 in WRKDIR
# it's needed for the do-install phase, it's here because of this issue
# https://github.com/MikaelUrankar/signal-desktop/issues/6 (I don't know why it fails though)
	@${RM} -r ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	@${CP} -pR ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	${CHMOD} -R a+w ${WRKDIR}/electron${ELECTRON_VER_MAJOR}

	# Install libsignal_node.so and libringrtc.so binaries in the yarn cache
	${MKDIR} ${WRKDIR}/.cache/yarn/v6/${NPM_SIGNAL_DIR}/node_modules/@signalapp/libsignal-client/prebuilds/freebsd-${NODE_ARCH} \
		 ${WRKDIR}/.cache/yarn/v6/${NPM_RINGRTC_DIR}/node_modules/ringrtc/build/freebsd
	${CP} ${LOCALBASE}/lib/libsignal_node.so \
		${WRKDIR}/.cache/yarn/v6/${NPM_SIGNAL_DIR}/node_modules/@signalapp/libsignal-client/prebuilds/freebsd-${NODE_ARCH}/node.napi.node
	${CP} ${LOCALBASE}/lib/libringrtc.so \
		${WRKDIR}/.cache/yarn/v6/${NPM_RINGRTC_DIR}/node_modules/ringrtc/build/freebsd/libringrtc-${NODE_ARCH}.node

	${MKDIR} ${WRKDIR}/.cache/yarn/v6/${NPM_SQLITE3_DIR}/node_modules/@signalapp/better-sqlite3/deps
	${CP} ${DISTDIR}/sqlcipher-4.5.2--3.0.7-4587e88a4219cb76fd595a5b73f82bfd919b235d75626f40783525f4f58a7503.tar.gz \
		${WRKDIR}/.cache/yarn/v6/${NPM_SQLITE3_DIR}/node_modules/@signalapp/better-sqlite3/deps/sqlcipher.tar.gz

	# patch-package can't patch playwright-core, patch the yarn cache instead
	${CP} ${FILESDIR}/playwrigth-registry.js \
	 	${WRKDIR}/.cache/yarn/v6/${NPM_PLAYWRITE_DIR}/node_modules/playwright-core/lib/utils/registry.js

	# patch-package can't patch sqlite3 on aarch64, patch the yarn cache instead
	cd ${WRKDIR}/.cache/yarn/v6 && ${PATCH} -s -N -i ${FILESDIR}/sqlite3.gyp.diff

	${MKDIR} ${WRKDIR}/esbuild-freebsd-64
	${TAR} -xf ${WRKDIR}/yarn-cache/esbuild-freebsd-${ESBUILD_ARCH}64-${NPM_ESBUILD_VERS}.tgz -C ${WRKDIR}/esbuild-freebsd-64

# 	# For online build
#	${RM} ${WRKDIR}/.npmrc
#	cd ${WRKSRC} && \
#		${SETENV} ${MAKE_ENV} yarn install --frozen-lockfile --ignore-optional
#	cd ${WRKSRC} && \
#		${SETENV} ${MAKE_ENV} yarn generate
#	cd ${WRKSRC} && \
#		${SETENV} ${MAKE_ENV} yarn build:webpack

	# For offline build
	${ECHO_CMD} offline=true > ${WRKDIR}/.npmrc
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} yarn install --frozen-lockfile --ignore-optional --offline
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} yarn --offline generate
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} yarn --offline build:webpack

do-install:
# taken from https://github.com/tagattie/FreeBSD-Electron/blob/master/Mk/Uses/electron.mk#L387
# and editors/vscode
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PACKAGE_ENV} yarn run electron-builder \
			--linux --dir --config.npmRebuild=false \
			--config.electronVersion=${ELECTRON_VER_MAJOR} \
			--config.electronDist=${WRKDIR}/electron${ELECTRON_VER_MAJOR}

	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${BUILD_WRKSRC}/dist/${APP_OUT_DIR} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/images/signal-logo-desktop-linux.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/signal-desktop.png
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.for f in chromedriver mksnapshot v8_context_snapshot_generator
	${RM} ${STAGEDIR}${DATADIR}/${f}
.endfor
	${RM} -r ${STAGEDIR}${DATADIR}/gen
	${RM} -r ${STAGEDIR}${DATADIR}/node_headers
	${RM} -r ${STAGEDIR}${DATADIR}/resources/completions
	${RLN} ${STAGEDIR}${DATADIR}/signal-desktop ${STAGEDIR}${PREFIX}/bin

create-caches-tarball:
	# do some cleanup first
	${RM} -r  ${WRKDIR}/.npm/_logs ${WRKDIR}/.npm/_update-notifier-last-checked ${WRKDIR}/.cache/yarn/v6/.tmp
	${FIND} ${WRKDIR}/.cache -type f -perm 755 -exec file {} \; | ${EGREP} "ELF|PE32+|Mach-O" | ${AWK} -F ':' '{print $$1}' | ${XARGS} ${RM}

	cd ${WRKDIR} && \
		${TAR} czf signal-desktop-${DISTVERSION}-yarn-cache.tar.gz .cache yarn-cache
	cd ${WRKDIR} && \
		${TAR} czf signal-desktop-${DISTVERSION}-electron-gyp-cache.tar.gz .electron-gyp
	cd ${WRKDIR} && \
		${TAR} czf signal-desktop-${DISTVERSION}-npm-cache.tar.gz .npm

.include <bsd.port.mk>
