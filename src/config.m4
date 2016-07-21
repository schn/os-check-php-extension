PHP_ARG_ENABLE(os_check, Enable OS check support)

if test "$PHP_OS_CHECK" = "yes"; then
   AC_DEFINE(HAVE_OS_CHECK, 1, [You have OS check extension])
   PHP_NEW_EXTENSION(os_check, os_check.c, $ext_shared)
fi