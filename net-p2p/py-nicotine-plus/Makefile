PORTNAME=	nicotine-plus
DISTVERSION=	3.2.0
CATEGORIES=	net-p2p python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical client for the Soulseek file sharing network
WWW=		https://github.com/Nicotine-Plus/nicotine-plus/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=1.42:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gobject3>=3.16:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gdbm>=3.6:databases/py-gdbm@${PY_FLAVOR}

USES=		gettext-tools gnome python:3.5+
USE_GNOME=	gtk30
USE_PYTHON=	autoplist concurrent distutils unittest

.include <bsd.port.mk>
