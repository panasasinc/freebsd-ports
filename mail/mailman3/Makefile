PORTNAME=	mailman
PORTVERSION=	3.3.7
CATEGORIES=	mail
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	einar@isnic.is
COMMENT=	GNU Mailing List Management System, Core
WWW=		http://www.list.org/

LICENSE=	GPLv3+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosmtpd>=1.1:mail/py-aiosmtpd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}alembic>=1.8.0:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}atpublic>0:devel/py-atpublic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.14.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}falcon>=3.0.0:www/py-falcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flufl.bounce>=4.0:mail/py-flufl.bounce@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flufl.i18n>=3.2:devel/py-flufl.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flufl.lock>=5.2:devel/py-flufl.lock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazr.config>0:devel/py-lazr.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>0:devel/py-zope.configuration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.event>0:devel/py-zope.event@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}authres>0:mail/py-authres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}authheaders>0:mail/py-authheaders@${PY_FLAVOR}

USES=		cpe python:3.5+
CPE_VENDOR=	gnu
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	mailman

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

USERS=		mailman
GROUPS=		mailman

NO_ARCH=	yes

.include <bsd.port.mk>
