PORTNAME=	imp
PORTVERSION=	6.2.27
PORTREVISION=	1
CATEGORIES=	mail www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde web based webmail system
WWW=		https://www.horde.org/apps/imp/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Requires php74
EXPIRATION_DATE=	2023-03-31
BROKEN=	runtime error with php80

USES=		horde cpe php
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		Horde_Auth \
		Horde_Browser \
		Horde_Cache \
		Horde_Compress \
		Horde_Core \
		Horde_Crypt \
		Horde_Css_Parser \
		Horde_Date \
		Horde_Editor \
		Horde_Exception \
		Horde_Icalendar \
		Horde_Image \
		Horde_Imap_Client \
		Horde_Itip \
		Horde_ListHeaders \
		Horde_LoginTasks \
		Horde_Mail \
		Horde_Mail_Autoconfig \
		Horde_Mime \
		Horde_Mime_Viewer \
		Horde_Nls \
		Horde_Notification \
		Horde_Pack \
		Horde_Perms \
		Horde_SpellChecker \
		Horde_Stream \
		Horde_Stream_Filter \
		Horde_Stream_Wrapper \
		Horde_Support \
		Horde_Text_Filter \
		Horde_Text_Flowed \
		Horde_Tree \
		Horde_Url \
		Horde_Util \
		Horde_Vfs \
		Horde_View
IGNORE_WITH_PHP=81 82

CONFLICTS_INSTALL=	php*-horde-imp

.include <bsd.port.mk>
