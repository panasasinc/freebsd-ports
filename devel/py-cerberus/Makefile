PORTNAME=	Cerberus
PORTVERSION=	1.3.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Lightweight, extensible validation tool for Python dictionaries
WWW=		https://github.com/pyeve/cerberus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

# Not to be confused with devel/py-pycerberus which fulfils a quite
# different function.

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
