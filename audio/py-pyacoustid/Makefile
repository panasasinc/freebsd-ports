PORTNAME=	pyacoustid
PORTVERSION=	1.2.2
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bindings for Chromaprint acoustic fingerprinting and the Acoustid API
WWW=		https://github.com/beetbox/pyacoustid

LICENSE=	MIT

LIB_DEPENDS=	libchromaprint.so:audio/chromaprint
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}audioread>=0:audio/py-audioread@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
