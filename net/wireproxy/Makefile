PORTNAME=	wireproxy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Wireguard client that exposes itself as a socks5 proxy
WWW=		https://github.com/octeep/wireproxy

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.19,modules

GO_MODULE=	github.com/octeep/wireproxy
GO_TARGET=	./cmd/wireproxy

PLIST_FILES=	bin/wireproxy

.include <bsd.port.mk>
