dnl $Id$
dnl config.m4 for extension lingdang

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(lingdang, for lingdang support,
dnl Make sure that the comment is aligned:
dnl [  --with-lingdang             Include lingdang support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(lingdang, whether to enable lingdang support,
dnl Make sure that the comment is aligned:
[  --enable-lingdang           Enable lingdang support])

if test "$PHP_LINGDANG" != "no"; then
  dnl Write more examples of tests here...

  dnl # get library FOO build options from pkg-config output
  dnl AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  dnl AC_MSG_CHECKING(for libfoo)
  dnl if test -x "$PKG_CONFIG" && $PKG_CONFIG --exists foo; then
  dnl   if $PKG_CONFIG foo --atleast-version 1.2.3; then
  dnl     LIBFOO_CFLAGS=`$PKG_CONFIG foo --cflags`
  dnl     LIBFOO_LIBDIR=`$PKG_CONFIG foo --libs`
  dnl     LIBFOO_VERSON=`$PKG_CONFIG foo --modversion`
  dnl     AC_MSG_RESULT(from pkgconfig: version $LIBFOO_VERSON)
  dnl   else
  dnl     AC_MSG_ERROR(system libfoo is too old: version 1.2.3 required)
  dnl   fi
  dnl else
  dnl   AC_MSG_ERROR(pkg-config not found)
  dnl fi
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBDIR, LINGDANG_SHARED_LIBADD)
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)

  dnl # --with-lingdang -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/lingdang.h"  # you most likely want to change this
  dnl if test -r $PHP_LINGDANG/$SEARCH_FOR; then # path given as parameter
  dnl   LINGDANG_DIR=$PHP_LINGDANG
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for lingdang files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       LINGDANG_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$LINGDANG_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the lingdang distribution])
  dnl fi

  dnl # --with-lingdang -> add include path
  dnl PHP_ADD_INCLUDE($LINGDANG_DIR/include)

  dnl # --with-lingdang -> check for lib and symbol presence
  dnl LIBNAME=lingdang # you may want to change this
  dnl LIBSYMBOL=lingdang # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $LINGDANG_DIR/$PHP_LIBDIR, LINGDANG_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_LINGDANGLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong lingdang lib version or lib not found])
  dnl ],[
  dnl   -L$LINGDANG_DIR/$PHP_LIBDIR -lm
  dnl ])
  
	PHP_REQUIRE_CXX()
    PHP_SUBST(LINGDANG_SHARED_LIBADD)
	PHP_ADD_LIBRARY(stdc++, 1, LINGDANG_SHARED_LIBADD)
	lingdang_source_file=" \
						lingdang.cpp \
						getcpu.cpp \
						getmac.cpp \
						getharddisk.cpp\
						getboard.cpp"
						
						
  PHP_NEW_EXTENSION(lingdang, $lingdang_source_file, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
