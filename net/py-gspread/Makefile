PORTNAME=	gspread
PORTVERSION=	5.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Google Spreadsheets Python API
WWW=		http://burnash.github.io/gspread/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>2.2.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>1.12.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth-oauthlib>0.4.1:security/py-google-auth-oauthlib@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	burnash

.include <bsd.port.mk>
