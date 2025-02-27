PORTNAME=	ipfs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/ipfs/go-ipfs/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-go
DISTNAME=	go-ipfs-source

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	IPFS implementation in Go
WWW=		https://github.com/ipfs/go-ipfs

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE

USES=		cpe go:1.18,modules

CPE_VENDOR=	protocol

GO_TARGET=	./cmd/ipfs:ipfs-go

NO_WRKSUBDIR=	yes

USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX}

SUB_FILES=	${FULLNAME}
SUB_LIST=	IPFS_USER=${IPFS_USER} \
		IPFS_GROUP=${IPFS_GROUP} \
		IPFS_HOME=${IPFS_HOME}
PLIST_SUB=	IPFS_USER=${IPFS_USER} \
		IPFS_GROUP=${IPFS_GROUP} \
		IPFS_HOME=${IPFS_HOME}

IPFS_USER?=	${FULLNAME}
IPFS_GROUP?=	${FULLNAME}
IPFS_HOME?=	/var/db/${FULLNAME}

USERS=		${IPFS_USER}
GROUPS=		${IPFS_GROUP}

FULLNAME=	${PORTNAME}${PKGNAMESUFFIX}

post-install:
	@${MKDIR} ${STAGEDIR}${IPFS_HOME}

.include <bsd.port.mk>
