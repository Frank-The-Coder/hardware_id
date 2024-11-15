/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2018 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Qingtao Liu                                                            |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
extern "C"{
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_lingdang.h"
}
#include "getcpu.h"
#include "getmac.h"
#include "getharddisk.h"
#include "getboard.h"

/* If you declare any globals in php_lingdang.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(lingdang)
*/

/* True global resources - no need for thread safety here */
static int le_lingdang;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("lingdang.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_lingdang_globals, lingdang_globals)
    STD_PHP_INI_ENTRY("lingdang.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_lingdang_globals, lingdang_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_lingdang_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_lingdang_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "lingdang", arg);

	RETURN_STR(strg);
}

PHP_FUNCTION(ld_get_cpu_id)
{
	//zend_string *str=strpprintf(0,"%s","getcpu");
	const char* ch=getcpu();
	zend_string *str=strpprintf(0,"%s",ch);
	RETURN_STR(str);
}
PHP_FUNCTION(ld_get_mac_addr){

		const char *ch=getmac();
		zend_string *str=strpprintf(0,"%s",ch);
		RETURN_STR(str);
}
PHP_FUNCTION(ld_get_board_id)
{
	char *dir=NULL;
	size_t dirlen;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &dir, &dirlen) == FAILURE) {
		return;
	}
	const char *ch=getboardserial(dir);
	zend_string *str=strpprintf(0,"%s",ch);
	RETURN_STR(str);
}
PHP_FUNCTION(ld_get_harddrive_id)
{
		zval serialNumbers;
	array_init(&serialNumbers);
	//RETURN_STR(str);
		RETURN_ARR(Z_ARR(serialNumbers));
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_lingdang_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_lingdang_init_globals(zend_lingdang_globals *lingdang_globals)
{
	lingdang_globals->global_value = 0;
	lingdang_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(lingdang)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(lingdang)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(lingdang)
{
#if defined(COMPILE_DL_LINGDANG) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(lingdang)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(lingdang)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "lingdang support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ lingdang_functions[]
 *
 * Every user visible function must have an entry in lingdang_functions[].
 */
const zend_function_entry lingdang_functions[] = {
	PHP_FE(confirm_lingdang_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(ld_get_cpu_id,NULL)
	PHP_FE(ld_get_mac_id,NULL)
	PHP_FE(ld_get_harddisk_id,NULL)
	PHP_FE(ld_get_board_id,NULL)
	PHP_FE_END	/* Must be the last line in lingdang_functions[] */
};
/* }}} */

/* {{{ lingdang_module_entry
 */
zend_module_entry lingdang_module_entry = {
	STANDARD_MODULE_HEADER,
	"lingdang",
	lingdang_functions,
	PHP_MINIT(lingdang),
	PHP_MSHUTDOWN(lingdang),
	PHP_RINIT(lingdang),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(lingdang),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(lingdang),
	PHP_LINGDANG_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_LINGDANG
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
extern "C"
{
	ZEND_GET_MODULE(lingdang)
}
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
