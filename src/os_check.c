#include "php.h"
#include "stdio.h"

int IS_WINDOWS;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
IS_WINDOWS = 1;
#else
IS_WINDOWS = 0;
#endif

PHP_FUNCTION(isWindows);
PHP_FUNCTION(isLinux);
PHP_FUNCTION(getOS);

const zend_function_entry os_check_functions[] = {
    PHP_FE(isWindows, NULL)
    PHP_FE(isLinux, NULL)
    PHP_FE(getOS, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry os_check_module_entry = {
    STANDARD_MODULE_HEADER,
    "os_check",
    os_check_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    "1.0",
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(os_check)

PHP_FUNCTION(isWindows)
{
    RETURN_BOOL(IS_WINDOWS);
}

PHP_FUNCTION(isLinux)
{
    RETURN_BOOL(!IS_WINDOWS);
}

PHP_FUNCTION(getOS)
{
    if (IS_WINDOWS == 1) {
        RETURN_STRING("WINDOWS", 1);
    } else {
        RETURN_STRING("LINUX", 1);
    }
}