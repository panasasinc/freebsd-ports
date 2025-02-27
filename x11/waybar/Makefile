PORTNAME=	waybar
DISTVERSION=	0.9.17
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Highly customizable Wayland bar for Sway and wlroots-based compositors
WWW=		https://github.com/Alexays/Waybar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libdate-tz.so:devel/date \
		libjsoncpp.so:devel/jsoncpp \
		libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog \
		libwayland-client.so:graphics/wayland \
		libxkbregistry.so:x11/libxkbcommon
TEST_DEPENDS=	catch>0:devel/catch

FLAVORS=	default nopulse
default_CONFLICTS_INSTALL=	${PORTNAME}-nopulse
nopulse_CONFLICTS_INSTALL=	${PORTNAME}
nopulse_PKGNAMESUFFIX=		-nopulse

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtkmm30
GH_ACCOUNT=	Alexays
GH_PROJECT=	Waybar
MESON_ARGS=	-Dtests=disabled
PLIST_FILES=	bin/${PORTNAME} \
		etc/xdg/${PORTNAME}/config \
		etc/xdg/${PORTNAME}/style.css

# XXX Add pkg-config support to devel/date
.if exists(${.CURDIR}/files/date.pc.in)
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${WRKDIR}"
SUB_FILES+=	date.pc
.endif

OPTIONS_DEFINE=	DBUS EVDEV GLS ICONSFONT JACK MANPAGES MPD MPRIS PULSEAUDIO SNDIO UDEV UPOWER
OPTIONS_DEFAULT=DBUS EVDEV GLS ICONSFONT JACK MANPAGES MPD MPRIS PULSEAUDIO SNDIO UDEV UPOWER
.if ${FLAVOR:U} == nopulse
OPTIONS_EXCLUDE=PULSEAUDIO
.endif

DBUS_LIB_DEPENDS=	libdbusmenu-gtk3.so:devel/libdbusmenu
DBUS_MESON_ENABLED=	dbusmenu-gtk

EVDEV_DESC=		Keyboard state via libevdev
EVDEV_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
EVDEV_LIB_DEPENDS=	libevdev.so:devel/libevdev \
			libinotify.so:devel/libinotify \
			libinput.so:x11/libinput
EVDEV_MESON_ENABLED=	libevdev libinput

GLS_DESC=		Use gtk-layer-shell library for popups support
GLS_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
GLS_MESON_ENABLED=	gtk-layer-shell

ICONSFONT_DESC=		Install Font Awesome to properly render icons
ICONSFONT_RUN_DEPENDS=	font-awesome>0:x11-fonts/font-awesome

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_MESON_ENABLED=	jack

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man5/${PORTNAME}-backlight.5.gz \
			man/man5/${PORTNAME}-battery.5.gz \
			man/man5/${PORTNAME}-bluetooth.5.gz \
			man/man5/${PORTNAME}-clock.5.gz \
			man/man5/${PORTNAME}-cpu.5.gz \
			man/man5/${PORTNAME}-custom.5.gz \
			man/man5/${PORTNAME}-disk.5.gz \
			man/man5/${PORTNAME}-gamemode.5.gz \
			man/man5/${PORTNAME}-idle-inhibitor.5.gz \
			man/man5/${PORTNAME}-inhibitor.5.gz \
			man/man5/${PORTNAME}-keyboard-state.5.gz \
			man/man5/${PORTNAME}-memory.5.gz \
			man/man5/${PORTNAME}-mpd.5.gz \
			man/man5/${PORTNAME}-mpris.5.gz \
			man/man5/${PORTNAME}-network.5.gz \
			man/man5/${PORTNAME}-pulseaudio.5.gz \
			man/man5/${PORTNAME}-river-mode.5.gz \
			man/man5/${PORTNAME}-river-tags.5.gz \
			man/man5/${PORTNAME}-river-window.5.gz \
			man/man5/${PORTNAME}-sndio.5.gz \
			man/man5/${PORTNAME}-states.5.gz \
			man/man5/${PORTNAME}-sway-language.5.gz \
			man/man5/${PORTNAME}-sway-mode.5.gz \
			man/man5/${PORTNAME}-sway-scratchpad.5.gz \
			man/man5/${PORTNAME}-sway-window.5.gz \
			man/man5/${PORTNAME}-sway-workspaces.5.gz \
			man/man5/${PORTNAME}-temperature.5.gz \
			man/man5/${PORTNAME}-tray.5.gz \
			man/man5/${PORTNAME}-upower.5.gz \
			man/man5/${PORTNAME}-wlr-taskbar.5.gz \
			man/man5/${PORTNAME}-wlr-workspaces.5.gz \
			man/man5/${PORTNAME}.5.gz \
			${NULL}

MPD_DESC=		Music Player Daemon support
MPD_LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient
MPD_MESON_ENABLED=	mpd

MPRIS_DESC=		Media Player Remote Interfacing Specification via playerctl
MPRIS_LIB_DEPENDS=	libplayerctl.so:multimedia/playerctl
MPRIS_MESON_ENABLED=	mpris

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_ENABLED=	pulseaudio

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_USES=		localbase:ldflags
SNDIO_MESON_ENABLED=	sndio

UDEV_DESC=		Monitor backlight level via libudev
UDEV_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libudev.so:devel/libudev-devd
UDEV_MESON_ENABLED=	libudev

UPOWER_DESC=		Monitor battery capacity via UPower
UPOWER_LIB_DEPENDS=	libupower-glib.so:sysutils/upower
UPOWER_MESON_ENABLED=	upower_glib

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build
# Temporarily use ConsoleKit2 like sysutils/gnome-settings-daemon
	@${REINPLACE_CMD} -e 's,/login1,/ConsoleKit/Manager,' \
		-e 's,login1\([".]\),ConsoleKit\1,g' \
		${WRKSRC}/src/modules/gamemode.cpp \
		${WRKSRC}/src/modules/inhibitor.cpp \
		${WRKSRC}/src/modules/upower/upower.cpp
# Respect PREFIX for icons
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/src/modules/wlr/taskbar.cpp

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dtests=enabled"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
