PORTNAME=	phonebox-plugin
DISTVERSION=	0.0.4b1
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	phonebox_plugin-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Phone numbers management plugin for NetBox
WWW=		https://github.com/iDebugAll/phonebox_plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_VER=${PYTHON_VER}

.include <bsd.port.mk>
