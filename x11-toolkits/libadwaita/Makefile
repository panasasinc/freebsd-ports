PORTNAME=	libadwaita
PORTVERSION=	1.2.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Building blocks for modern GNOME applications
WWW=		https://www.gtk.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sassc:textproc/sassc
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libgraphene-1.0.so:graphics/graphene

USES=		gettext gnome meson ninja pkgconfig tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf2 gtk40 introspection:build

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
