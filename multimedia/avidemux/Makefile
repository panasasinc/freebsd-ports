# assuming freebsd always has 16 byte aligned malloc as macos does. is this true?
# nls files not getting installed with nls=on. are they getting built?
# sync port options with current software options

PORTNAME=	avidemux
PORTVERSION=	${AVIDEMUX_VERSION}
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Simple GUI based video editor
WWW=		https://avidemux.org/

.include "${.CURDIR}/Makefile.common"

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux_core

post-configure: post-configure-common

post-install:
.for l in swscale.so.5 postproc.so.55 avutil.so.56 avcodec.so.58 avformat.so.58
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libADM6${l}
.endfor

.include <bsd.port.post.mk>
