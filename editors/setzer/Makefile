PORTNAME=	setzer
DISTVERSIONPREFIX=v
DISTVERSION=	0.4.1
PORTREVISION=	19
CATEGORIES=	editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX editor written in Python with Gtk
WWW=		https://www.cvfosammmm.org/setzer/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgspell-1.so:textproc/gspell \
		libpoppler-glib.so:graphics/poppler-glib \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer.six>=0:textproc/py-pdfminer.six@${PY_FLAVOR} \
		xdg-open:devel/xdg-utils

USES=		desktop-file-utils gettext gnome meson pkgconfig python:3.5+ \
		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	cvfosammmm
GH_PROJECT=	Setzer
USE_GNOME=	glib20 gtk30 gtksourceview4 introspection pango pygobject3
USE_PYTHON=	py3kplist

SHEBANG_FILES=	scripts/* setzer.in

.include <bsd.port.mk>
