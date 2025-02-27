PORTNAME=	gcc
PORTVERSION=	12.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GCC
PKGNAMEPREFIX=	${TARGETARCH}-
PKGNAMESUFFIX=	${SUFFIX}

MAINTAINER=	jhb@FreeBSD.org
COMMENT=	Cross GNU Compiler Collection for ${TARGETARCH}
WWW=		https://gcc.gnu.org/

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

IGNORE_FreeBSD_12= Not supported on FreeBSD 12

BUILD_DEPENDS=	${BU_PREFIX}-as:devel/binutils@${BU_FLAVOR} \
		objdump:devel/binutils
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
RUN_DEPENDS=	${BU_PREFIX}-as:devel/binutils@${BU_FLAVOR}

FLAVORS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 riscv64
TARGETARCH=	${FLAVOR}

USES=		compiler:c++11-lang cpe gmake iconv libtool makeinfo tar:xz
CPE_VENDOR=	gnu

PLIST_SUB=	OPSYS=${OPSYS:tl} \
		SUFFIX=${SUFFIX} \
		TARGETARCH=${TARGETARCH} \
		GCC_TARGET=${GCC_TARGET} \
		GCC_VERSION=${PORTVERSION}

SUB_FILES=	xtoolchain.mk
SUB_LIST=	BU_PREFIX=${BU_PREFIX} \
		GCC_TARGET=${GCC_TARGET} \
		SUFFIX=${SUFFIX}

SUFFIX=		${PORTVERSION:C/([0-9]+).*/\1/}

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS+=--target=${GCC_TARGET} --disable-nls --enable-languages=c,c++ \
		--enable-gnu-indirect-function \
		--enable-initfini-array \
		--program-prefix=${GCC_TARGET}- \
		--program-suffix=${SUFFIX} \
		--without-headers \
		--with-gmp=${LOCALBASE} \
		--with-pkgversion="FreeBSD Ports Collection for ${PKGNAMEPREFIX:C/-//g}" \
		--with-system-zlib \
		--without-zstd \
		--with-gxx-include-dir=/usr/include/c++/v1/ \
		--with-sysroot="/" \
		--with-as=${LOCALBASE}/bin/${BU_PREFIX}-as \
		--with-ld=${LOCALBASE}/bin/${BU_PREFIX}-ld

.if ${TARGETARCH:Mpowerpc64*}
CONFIGURE_ARGS+=--with-abi=elfv2
.endif

ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc

.include <bsd.port.pre.mk>

.if ${TARGETARCH:Marm*}
TARGET_ABI=	gnueabi
BU_FLAVOR=	arm_${TARGET_ABI}
BU_PREFIX=	arm-${TARGET_ABI}-${OPSYS:tl}${OSREL}
.else
TARGET_ABI=	unknown
BU_FLAVOR=	${TARGETARCH}
BU_PREFIX=	${GCC_TARGET}
.endif
GCC_TARGET=	${TARGETARCH:S/amd64/x86_64/}-${TARGET_ABI}-${OPSYS:tl}${OSREL}

post-patch:
	@${REINPLACE_CMD} -e '/LIBSTDCXX/ s/stdc\+\+/c\+\+/g ' \
		${WRKSRC}//gcc/cp/g++spec.cc
	@${REINPLACE_CMD} -e '/LOCAL_INCLUDE_DIR/ d ' \
		${WRKSRC}//gcc/Makefile.in

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-unknown-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-unknown-${OPSYS:tl}${OSREL}
.endif

.if ${TARGETARCH:Marm*} || ${TARGETARCH} == "aarch64"
. if ${CHOSEN_COMPILER_TYPE} == clang
MAKE_ARGS+=CXXFLAGS=-fbracket-depth=512
. endif
.endif

.if ${TARGETARCH} == "amd64" || ${TARGETARCH} == "powerpc64"
CONFIGURE_ARGS+=--enable-multilib
.endif

.if ${ARCH} == "aarch64"
PLIST_SUB+=	PLUGINS="@comment plugin does not build"
.else
PLIST_SUB+=	PLUGINS=""
.endif

.if ${TARGETARCH} == "amd64" || ${TARGETARCH} == "i386"
PLIST_SUB+=	FLOAT_H="@comment "
.else
PLIST_SUB+=	FLOAT_H=""
.endif

PLIST=		${.CURDIR}/pkg-plist

.if ${TARGETARCH} == "aarch64"
PLIST+=		${.CURDIR}/pkg-plist.aarch64
.endif
.if ${TARGETARCH} == "aarch64" || ${TARGETARCH:Marm*}
PLIST+=		${.CURDIR}/pkg-plist.arm
.endif
.if ${TARGETARCH:Marm*}
PLIST+=		${.CURDIR}/pkg-plist.arm_gnueabi
.endif
.if ${TARGETARCH} == "amd64"
PLIST+=		${.CURDIR}/pkg-plist.amd64
.endif
.if ${TARGETARCH} == "amd64" || ${TARGETARCH} == "i386"
PLIST+=		${.CURDIR}/pkg-plist.i386
.endif
.if ${TARGETARCH:Mpowerpc64*}
PLIST+=		${.CURDIR}/pkg-plist.powerpc64
.elif ${TARGETARCH:Mpowerpc*}
PLIST+=		${.CURDIR}/pkg-plist.powerpc
.endif
.if ${TARGETARCH:Mriscv*}
PLIST+=		${.CURDIR}/pkg-plist.riscv
.endif

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/${GCC_TARGET}-${GCC_TARGET}-*
	@${RM} ${STAGEDIR}${PREFIX}/share/info/*
	@${RM} ${STAGEDIR}${PREFIX}/man/man7/*
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/gcc/${GCC_TARGET}/${PORTVERSION}/include-fixed
.if ${TARGETARCH} == "amd64" || ${TARGETARCH} == "i386"
	# Conflicts with sys/x86/include/float.h
	${RM} ${STAGEDIR}${PREFIX}/lib/gcc/${GCC_TARGET}/${PORTVERSION}/include/float.h
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/share/toolchains/
	${INSTALL_DATA} ${WRKDIR}/xtoolchain.mk \
		${STAGEDIR}${PREFIX}/share/toolchains/${TARGETARCH}-gcc${SUFFIX}.mk

.include <bsd.port.post.mk>
