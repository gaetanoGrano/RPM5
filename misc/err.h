/* 4.4BSD utility functions for error messages.
   Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#ifndef	_ERR_H
#define	_ERR_H	1

#define	__need___va_list
#include <stdarg.h>
#ifndef __ptr_t
#define	__ptr_t		void *
#endif
#ifndef	__GNUC_VA_LIST
# define __gnuc_va_list	__ptr_t
#endif

#ifndef __attribute__
# if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__
#  define __attribute__(Spec) /* empty */
# endif
# if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 7)
#  define __format__ format
#  define __printf__ printf
# endif
#endif

#if defined(__cplusplus) || (defined(__STDC__) && __STDC__)
# if !defined(__GLIBC__) || !defined(__P)
#   undef  __P
#   define __P(protos) protos
# endif
#else
#  undef  __P
#  define __P(protos) ()
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Print "program: ", FORMAT, ": ", the standard error string for errno,
   and a newline, on stderr.  */
extern void warn __P ((__const char *__format, ...))
     __attribute__ ((__format__ (__printf__, 1, 2)));
extern void vwarn __P ((__const char *__format, __gnuc_va_list))
     __attribute__ ((__format__ (__printf__, 1, 0)));

/* Likewise, but without ": " and the standard error string.  */
extern void warnx __P ((__const char *__format, ...))
     __attribute__ ((__format__ (__printf__, 1, 2)));
extern void vwarnx __P ((__const char *__format, __gnuc_va_list))
     __attribute__ ((__format__ (__printf__, 1, 0)));

/* Likewise, and then exit with STATUS.  */
extern void err __P ((int __status, __const char *__format, ...))
     __attribute__ ((__noreturn__, __format__ (__printf__, 2, 3)));
extern void verr __P ((int __status, __const char *__format, __gnuc_va_list))
     __attribute__ ((__noreturn__, __format__ (__printf__, 2, 0)));
extern void errx __P ((int __status, __const char *__format, ...))
     __attribute__ ((__noreturn__, __format__ (__printf__, 2, 3)));
extern void verrx __P ((int __status, __const char *, __gnuc_va_list))
     __attribute__ ((__noreturn__, __format__ (__printf__, 2, 0)));

#ifdef __cplusplus
}
#endif

#endif	/* err.h */
