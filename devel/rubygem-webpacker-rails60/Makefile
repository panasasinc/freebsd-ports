PORTNAME=	webpacker
PORTVERSION=	5.4.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use Webpack to manage app-like JavaScript modules in Rails
WWW=		https://github.com/rails/webpacker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport60>=5.2:devel/rubygem-activesupport60 \
		rubygem-rack-proxy>=0.6.1:www/rubygem-rack-proxy \
		rubygem-railties60>=5.2:www/rubygem-railties60 \
		rubygem-semantic_range>=2.3.0:devel/rubygem-semantic_range \
		yarn:www/yarn

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
