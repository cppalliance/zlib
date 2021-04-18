//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/ZLib
//

#ifndef BOOST_ZLIB_CORE_DETAIL_CONFIG_HPP
#define BOOST_ZLIB_CORE_DETAIL_CONFIG_HPP

// Available to every header
#include <boost/config.hpp>
#include <boost/version.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/static_assert.hpp>

/*
    _MSC_VER and _MSC_FULL_VER by version:

    14.0 (2015)             1900        190023026
    14.0 (2015 Update 1)    1900        190023506
    14.0 (2015 Update 2)    1900        190023918
    14.0 (2015 Update 3)    1900        190024210
*/

#if defined(BOOST_MSVC)
# if BOOST_MSVC_FULL_VER < 190024210
#  error Boost.ZLib requires C++11: Visual Studio 2015 Update 3 or later needed
# endif

#elif defined(BOOST_GCC)
# if(BOOST_GCC < 40801)
#  error Boost.ZLib requires C++11: gcc version 4.8 or later needed
# endif

#else
# if \
    defined(BOOST_NO_CXX11_DECLTYPE) || \
    defined(BOOST_NO_CXX11_HDR_TUPLE) || \
    defined(BOOST_NO_CXX11_TEMPLATE_ALIASES) || \
    defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#  error Boost.ZLib requires C++11: a conforming compiler is needed
# endif

#endif

#define BOOST_ZLIB_DEPRECATION_STRING \
    "This is a deprecated interface, #define BOOST_ZLIB_ALLOW_DEPRECATED to allow it"

# if defined(BOOST_ZLIB_DOCS)
#  define BOOST_ZLIB_DECL
# else
#  if (defined(BOOST_ZLIB_DYN_LINK) || defined(BOOST_ALL_DYN_LINK)) && !defined(BOOST_ZLIB_STATIC_LINK)
#   if defined(BOOST_ZLIB_SOURCE)
#    define BOOST_ZLIB_DECL        BOOST_SYMBOL_EXPORT
#    define BOOST_ZLIB_CLASS_DECL  BOOST_SYMBOL_EXPORT
#    define BOOST_ZLIB_BUILD_DLL
#   else
#    define BOOST_ZLIB_DECL        BOOST_SYMBOL_IMPORT
#    define BOOST_ZLIB_CLASS_DECL  BOOST_SYMBOL_IMPORT
#   endif
#  endif // shared lib
#  ifndef  BOOST_ZLIB_DECL
#   define BOOST_ZLIB_DECL
#  endif
#  if !defined(BOOST_ZLIB_SOURCE) && !defined(BOOST_ALL_NO_LIB) && !defined(BOOST_ZLIB_NO_LIB)
#   define BOOST_LIB_NAME boost_zlib
#   if defined(BOOST_ALL_DYN_LINK) || defined(BOOST_ZLIB_DYN_LINK)
#    define BOOST_DYN_LINK
#   endif
#   include <boost/config/auto_link.hpp>
#  endif
# endif


#ifndef BOOST_ZLIB_DECL
#define BOOST_ZLIB_DECL
#endif
#ifndef BOOST_ZLIB_CLASS_DECL
#define BOOST_ZLIB_CLASS_DECL
#endif

#endif
