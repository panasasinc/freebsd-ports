PORTNAME=	devise-two-factor
PORTVERSION=	4.0.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise
WWW=		https://github.com/tinfoil/devise-two-factor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport5>=0<7.1:devel/rubygem-activesupport5 \
		rubygem-attr_encrypted>=1.3<4:security/rubygem-attr_encrypted \
		rubygem-devise-rails5>=4.0<5:devel/rubygem-devise-rails5 \
		rubygem-railties5>=0<7.1:www/rubygem-railties5 \
		rubygem-rotp>=6.0<7:devel/rubygem-rotp

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.

.include <bsd.port.mk>
