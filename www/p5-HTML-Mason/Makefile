PORTNAME=	HTML-Mason
PORTVERSION=	1.59
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	High-performance, dynamic web site authoring system
WWW=		https://metacpan.org/release/HTML-Mason

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Cache-Cache>=1:devel/p5-Cache-Cache \
		p5-Class-Container>=0.07:devel/p5-Class-Container \
		p5-Exception-Class>=1.15:devel/p5-Exception-Class \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Log-Any>=0.08:devel/p5-Log-Any \
		p5-Params-Validate>=0.70:devel/p5-Params-Validate
TEST_DEPENDS=	p5-CHI>=0.210:devel/p5-CHI \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	MODPERL

MODPERL_BUILD_DEPENDS=	p5-libapreq2>=0:www/p5-libapreq2
MODPERL_RUN_DEPENDS=	p5-libapreq2>=0:www/p5-libapreq2
MODPERL_USES=		apache:run

post-patch:
	@${REINPLACE_CMD} -e '/bin\/convert/d' ${WRKSRC}/Makefile.PL

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/blib/script/mason.pl ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
