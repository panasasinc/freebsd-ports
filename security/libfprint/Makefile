PORTNAME=	libfprint
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://people.freedesktop.org/~anarsoul/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library for fingerprint reader devices
WWW=		http://www.reactivated.net/fprint/wiki/Libfprint

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnss3.so:security/nss \
		libnspr4.so:devel/nspr

GNU_CONFIGURE=	yes
USES=		gnome libtool magick:6 pathfix pkgconfig tar:xz xorg
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USE_XORG=	pixman
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-DHAVE_MEMMEM
MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
