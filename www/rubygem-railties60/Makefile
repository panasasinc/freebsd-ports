PORTNAME=	railties
PORTVERSION=	6.0.6
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks
WWW=		https://github.com/rails/rails/tree/master/railties \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack60 \
		rubygem-activesupport60>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport60 \
		rubygem-method_source>=0:devel/rubygem-method_source \
		rubygem-rake>=0.8.7:devel/rubygem-rake \
		rubygem-thor>=0.20.3<2.0:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rails

CONFLICTS_INSTALL=	rubygem-railties4 rubygem-railties5 rubygem-railties50

PORTSCOUT=	limit:^6\.0\.

.include <bsd.port.mk>
