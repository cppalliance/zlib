//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/ZLib
//

#ifndef BOOST_ZLIB_IMPL_ERROR_HPP
#define BOOST_ZLIB_IMPL_ERROR_HPP

#include <type_traits>

namespace boost {
namespace system {

template<>
struct is_error_code_enum<::boost::zlib::error>
{
    static bool const value = true;
};

} // system
} // boost

namespace boost {
namespace zlib {

BOOST_ZLIB_DECL
error_code
make_error_code(error e);

} // zlib
} // boost

#endif
