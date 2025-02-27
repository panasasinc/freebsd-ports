PORTNAME=	tree-sitter-graph
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Construct graphs from parsed source code
WWW=		https://docs.rs/tree-sitter-graph/*/tree_sitter_graph/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	tree-sitter

CARGO_FEATURES=	cli
CARGO_CRATES=	ahash-0.4.7 \
		aho-corasick-0.7.20 \
		anyhow-1.0.68 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cc-1.0.78 \
		cfg-if-1.0.0 \
		clap-3.2.23 \
		clap_lex-0.2.4 \
		colored-2.0.0 \
		dirs-3.0.2 \
		dirs-sys-0.3.7 \
		env_logger-0.9.3 \
		getrandom-0.2.8 \
		hashbrown-0.9.1 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		indexmap-1.9.2 \
		indoc-1.0.8 \
		itoa-1.0.5 \
		lazy_static-1.4.0 \
		libc-0.2.139 \
		libloading-0.7.4 \
		log-0.4.17 \
		memchr-2.5.0 \
		once_cell-1.17.0 \
		os_str_bytes-6.4.1 \
		proc-macro2-1.0.49 \
		quote-1.0.23 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.7.0 \
		regex-syntax-0.6.28 \
		ryu-1.0.12 \
		serde-1.0.152 \
		serde_derive-1.0.152 \
		serde_json-1.0.91 \
		smallvec-1.10.0 \
		string-interner-0.12.2 \
		strsim-0.10.0 \
		syn-1.0.107 \
		termcolor-1.1.3 \
		textwrap-0.16.0 \
		thiserror-1.0.38 \
		thiserror-impl-1.0.38 \
		tree-sitter-0.20.9 \
		tree-sitter-config-0.19.0 \
		tree-sitter-highlight-0.20.1 \
		tree-sitter-loader-0.19.0 \
		tree-sitter-python-0.19.1 \
		tree-sitter-tags-0.20.2 \
		unicode-ident-1.0.6 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
