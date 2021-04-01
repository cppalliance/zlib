//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/ZLib
//

#ifndef BOOST_ZLIB_STRING_HPP
#define BOOST_ZLIB_STRING_HPP

#include <boost/zlib/core/detail/config.hpp>
#include <boost/zlib/core/string_type.hpp>

namespace boost {
namespace zlib {

/** Returns `true` if two strings are equal, using a case-insensitive comparison.

    The case-comparison operation is defined only for low-ASCII characters.

    @param lhs The string on the left side of the equality

    @param rhs The string on the right side of the equality
*/
BOOST_ZLIB_DECL
bool
iequals(
    zlib::string_view lhs,
    zlib::string_view rhs);

/** A case-insensitive less predicate for strings.

    The case-comparison operation is defined only for low-ASCII characters.

    As of C++14, containers using this class as the `Compare` type will take part
    in heterogeneous lookup if the search term is implicitly convertible to
    @ref string_view.
*/
struct iless
{
    BOOST_ZLIB_DECL
    bool
    operator()(
        string_view lhs,
        string_view rhs) const;

    using is_transparent = void;
};

/** A case-insensitive equality predicate for strings.

    The case-comparison operation is defined only for low-ASCII characters.

    As of C++14, containers using this class as the `Compare` type will take part
    in heterogeneous lookup if the search term is implicitly convertible to
    @ref string_view.
*/
struct iequal
{
    bool
    operator()(
        string_view lhs,
        string_view rhs) const
    {
        return iequals(lhs, rhs);
    }

    using is_transparent = void;
};

} // zlib
} // boost

#ifdef BOOST_ZLIB_HEADER_ONLY
#include <boost/zlib/core/impl/string.ipp>
#endif

#endif
