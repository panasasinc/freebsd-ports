PORTNAME=	binaryen
DISTVERSIONPREFIX=	version_
DISTVERSION=	105
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiler infrastructure and toolchain library for WebAssembly
WWW=		https://github.com/WebAssembly/binaryen

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake cpe python:3.6+,build compiler:c++11-lang
CPE_VENDOR=	webassembly
USE_GITHUB=	yes
GH_ACCOUNT=	WebAssembly
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBINARYEN_VERSION_INFO=${DISTVERSION}
LDFLAGS+=	-Wno-unused-command-line-argument

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
