PORTNAME=	formencode
PORTVERSION=	1.3.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FormEncode-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	HTML form validation, generation, and conversion package
WWW=		https://www.formencode.org/

LICENSE=	PSFL

OPTIONS_DEFINE=	DOCS

USES=		dos2unix gettext-runtime:run python:3.6+ zip
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
