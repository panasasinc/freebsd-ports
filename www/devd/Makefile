PORTNAME=	devd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9
PORTREVISION=	11
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Local webserver for developers
WWW=		https://github.com/cortesi/devd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	cortesi

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}
GH_TUPLE=	golang:sys:fead79001313:golang_sys/vendor/golang.org/x/sys_fead79001313

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_fead79001313 ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
