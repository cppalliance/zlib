//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/ZLib
//

#ifndef BOOST_ZLIB_SRC_HPP
#define BOOST_ZLIB_SRC_HPP

/*

This file is meant to be included once,
in a translation unit of the program.

*/

#ifndef BOOST_ZLIB_SOURCE
#define BOOST_ZLIB_SOURCE
#endif

// We include this in case someone is using
// src.hpp as their main JSON header file
// https://github.com/boostorg/json/issues/223#issuecomment-689264149
#include <boost/zlib.hpp>

#include <boost/zlib/core/detail/config.hpp>

#include <boost/zlib/core/impl/error.ipp>
#include <boost/zlib/core/impl/string.ipp>
#include <boost/zlib/detail/impl/deflate_stream.ipp>
#include <boost/zlib/detail/impl/inflate_stream.ipp>

#endif
