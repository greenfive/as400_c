/*******************************************************************************
 * stdint.h                                                                    *
 *                                                                             *
 * support for standardized integer data types for use on OS/400 V4R5          *
 * partly as defined in the ANSI C99 standard                                  *
 * put together by Ralph Graulich                                              *
 *                                                                             *
 * audit trail                                                                 *
 * 11-MAY-2026  rg  first version                                              *
 * 17-MAX-2026  rg  added include guards, additional data types, and minimum   *
 *                  and maximum value definitions                              *
 *                                                                             *
 * TODO                                                                        *
 * - add "least" types                                                         *
 * - add "fast" types                                                          *
 * - add "pointer" types                                                       *
 *******************************************************************************
 * This is free and unencumbered software released into the public domain.     *
 *                                                                             *
 * Anyone is free to copy, modify, publish, use, compile, sell, or             *
 * distribute this software, either in source code form or as a compiled       *
 * binary, for any purpose, commercial or non-commercial, and by any           *
 * means.                                                                      *
 *                                                                             *
 * In jurisdictions that recognize copyright laws, the author or authors       *
 * of this software dedicate any and all copyright interest in the             *
 * software to the public domain. We make this dedication for the benefit      *
 * of the public at large and to the detriment of our heirs and                *
 * successors. We intend this dedication to be an overt act of                 *
 * relinquishment in perpetuity of all present and future rights to this       *
 * software under copyright law.                                               *
 *                                                                             *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,             *
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF          *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.      *
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR           *
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,       *
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR       *
 * OTHER DEALINGS IN THE SOFTWARE.                                             *
 *                                                                             *
 * For more information, please refer to <https://unlicense.org/>              *
 *******************************************************************************
 */

/*
 * include guard to permit including stdint.h more than once
 */
#ifndef __STDINT_H
#define __STDINT_H

/*
 * include limits.h if not already included, so we have access to the limits
 * and ranges of data types defined there
 * if limits.h does not define the limits needed, this stdint.h provides
 * sane defaults instead
 * define __NO_INC_SYS_LIMITS_H if you want to use only the limits defined in
 * this version of stdint.h and not rely on the values defined in limits.h
 * provided with the OS - you can always manually include limits.h if you
 * want to override your "no include" define for a particular part of your
 * source code tree
 */
#ifndef __NO_INC_SYS_LIMITS_H
#ifndef __LIMITS_H
  #include <limits.h>
#endif /* __LIMITS_H */
#endif /* __NO_INC_SYS_LIMITS_H */


/*
 * -----------------------------------------------------------------------------
 * definitions for generic data types
 * -----------------------------------------------------------------------------
 */
#ifndef _INT8_T
#define _INT8_T
typedef signed char         int8_t;
#endif /* _INT8_T */

#ifndef _INT16_T
#define _INT16_T
typedef signed short       int16_t;
#endif /* _INT16_T */

#ifndef _INT32_T
#define _INT32_T
typedef signed int         int32_t;
#endif /* _INT32_T */

#ifdef __EXTENDED__
/* long long is only defined when langlvl is extended */
#ifndef _INT64_T
#define _INT64_T
typedef signed long long   int64_t;
#endif /* _INT64_T */
#endif /* __EXTENDED__ */

#ifndef _UINT8_T
#define _UINT8_T
typedef unsigned char       uint8_t;
#endif /* _UINT8_T */

#ifndef _UINT16_T
#define _UINT16_T
typedef unsigned short     uint16_t;
#endif /* _UINT16_T */

#ifndef _UINT32_T
#define _UINT32_T
typedef unsigned int       uint32_t;
#endif /* _UINT32_T */

#ifdef __EXTENDED__
/* long long is only defined when langlvl is extended */
#ifndef _UINT64_T
#define _UINT64_T
typedef unsigned long long uint64_t;
#endif /* _UINT64_T */
#endif /* __EXTENDED__ */


/*
 * -----------------------------------------------------------------------------
 * definitions for minimum and maximum for the data types
 * -----------------------------------------------------------------------------
 * reuse suitable definitions if they already exist, for example if limits.h
 * was included correctly
 * otherwise we will define our own and therefore provide sane defaults instead
 * -----------------------------------------------------------------------------
 */
#ifndef _INT8_MIN
#define _INT8_MIN
#ifdef SCHAR_MIN
#define INT8_MIN SCHAR_MIN
#else
#define INT8_MIN (-128)
#endif /* SCHAR_MIN */
#endif /* _INT8_MIN */

#ifndef _INT8_MAX
#define _INT8_MAX
#ifdef SCHAR_MAX
#define INT8_MAX SCHAR_MAX
#else
#define INT8_MAX 127
#endif /* SCHAR_MAX */
#endif /* _INT8_MAX */

#ifndef _INT16_MIN
#define _INT16_MIN
#ifdef SHRT_MIN
#define _INT16_MIN SHRT_MIN
#else
#define _INT16_MIN (-32768)
#endif /* SHRT_MIN */
#endif /* _INT16_MIN */

#ifndef _INT16_MAX
#define _INT16_MAX
#ifdef SHRT_MAX
#define _INT16_MAX SHRT_MAX
#else
#define _INT16_MAX 32767
#endif /* SHRT_MAX */
#endif /* _INT16_MAX */

#ifndef _INT32_MIN
#define _INT32_MIN
#ifdef INT_MIN
#define _INT32_MIN INT_MIN
#else
#define _INT32_MIN (-2147483647-1)
#endif /* INT_MIN */
#endif /* _INT32_MIN */

#ifndef _INT32_MAX
#define _INT32_MAX
#ifdef INT_MAX
#define _INT32_MAX INT_MAX
#else
#define _INT32_MAX 2147483647
#endif /* INT_MAX */
#endif /* _INT32_MAX */

#ifdef __EXTENDED__
/* long long is only defined when langlvl is extended */
#ifndef _INT64_MIN
#define _INT64_MIN
#ifdef LONGLONG_MIN
#define _INT64_MIN LONGLONG_MIN
#else
#define _INT64_MIN (-9223372036854775807LL-1LL)
#endif /* LONGLONG_MIN */
#endif /* _INT64_MIN */
#endif /* __EXTENDED__ */

#ifdef __EXTENDED__
/* long long is only defined when langlvl is extended */
#ifndef _INT64_MAX
#define _INT64_MAX
#ifdef LONGLONG_MAX
#define _INT64_MAX LONGLONG_MAX
#else
#define _INT64_MAX 9223372036854775807LL
#endif /* LONGLONG_MAX */
#endif /* _INT64_MAX */
#endif /* __EXTENDED__ */

#ifndef _UINT8_MAX
#define _UINT8_MAX
#ifdef UCHAR_MAX
#define UINT8_MAX UCHAR_MAX
#else
#define UINT8_MAX 255U
#endif /* UCHAR_MAX */
#endif /* _UINT8_MAX */

#ifndef _UINT16_MAX
#define _UINT16_MAX
#ifdef USHRT_MAX
#define _UINT16_MAX USHRT_MAX
#else
#define _UINT16_MAX 65535U
#endif /* USHRT_MAX */
#endif /* _UINT16_MAX */

#ifndef _UINT32_MAX
#define _UINT32_MAX
#ifdef UINT_MAX
#define _UINT32_MAX UINT_MAX
#else
#define _UINT32_MAX 4294967295U
#endif /* UINT_MAX */
#endif /* _UINT32_MAX */

#ifdef __EXTENDED__
/* long long is only defined when langlvl is extended */
#ifndef _UINT64_MAX
#define _UINT64_MAX
#ifdef ULONGLONG_MAX
#define _UINT64_MAX ULONGLONG_MAX
#else
#define _UINT64_MAX 18446744073709551615ULL
#endif /* ULONGLONG_MAX */
#endif /* _UINT64_MAX */
#endif /* __EXTENDED__ */


#ENDIF /* __STDINT_H */
