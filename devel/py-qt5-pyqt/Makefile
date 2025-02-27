PORTNAME=	pyqt
PORTVERSION=	${PYQT_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQT_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtCore module
WWW=		https://riverbankcomputing.com/software/pyqt

PYQT_DIST=	yes

LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5 \
		libdbus-1.so:devel/dbus
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>1:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>1:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR}

USES=		pkgconfig python:3.8+ pyqt:5 qt:5
USE_PYTHON=	concurrent flavors py3kplist
USE_PYQT=	qtbuilder sip pysip
USE_QT=		connectivity core dbus declarative designer gui help imageformats location \
		multimedia network opengl printsupport quick3d remoteobjects \
		sensors serialport speech sql svg testlib webchannel webkit websockets \
		widgets x11extras xml xmlpatterns \
		buildtools:build qmake:build

PORTSCOUT?=	limit:^${_QT_VERSION:R}

post-extract:
	${RM} -r ${WRKSRC}/pyuic/uic/port_v2

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
