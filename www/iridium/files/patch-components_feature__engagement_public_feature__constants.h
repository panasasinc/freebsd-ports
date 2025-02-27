--- components/feature_engagement/public/feature_constants.h.orig	2023-01-17 19:19:00 UTC
+++ components/feature_engagement/public/feature_constants.h
@@ -32,7 +32,7 @@ BASE_DECLARE_FEATURE(kIPHDummyFeature);
 BASE_DECLARE_FEATURE(kEnableIPH);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHBatterySaverModeFeature);
 BASE_DECLARE_FEATURE(kIPHDesktopSharedHighlightingFeature);
 BASE_DECLARE_FEATURE(kIPHDesktopTabGroupsNewGroupFeature);
@@ -185,7 +185,8 @@ BASE_DECLARE_FEATURE(kIPHOverflowMenuTipFeature);
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHAutofillVirtualCardSuggestionFeature);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) ||
