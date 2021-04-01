//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/ZLib
//

// Test that header file is self-contained.
#include <boost/zlib/error.hpp>

#include "test_suite.hpp"
#include <memory>

namespace boost {
namespace zlib {

class error_test
{
public:
    void check(char const* name, error ev)
    {
        auto const ec = make_error_code(ev);
        auto const& cat = make_error_code(
            static_cast<zlib::error>(0)).category();
        BOOST_TEST(std::string{ec.category().name()} == name);
        BOOST_TEST(! ec.message().empty());
        BOOST_TEST(
            std::addressof(ec.category()) == std::addressof(cat));
        BOOST_TEST(cat.equivalent(
            static_cast<std::underlying_type<error>::type>(ev),
                ec.category().default_error_condition(
                    static_cast<std::underlying_type<error>::type>(ev))));
        BOOST_TEST(cat.equivalent(ec,
            static_cast<std::underlying_type<error>::type>(ev)));
    }

    void run()
    {
        check("boost.zlib", error::need_buffers);
        check("boost.zlib", error::end_of_stream);
        check("boost.zlib", error::need_dict);
        check("boost.zlib", error::stream_error);

        check("boost.zlib", error::invalid_block_type);
        check("boost.zlib", error::invalid_stored_length);
        check("boost.zlib", error::too_many_symbols);
        check("boost.zlib", error::invalid_code_lengths);
        check("boost.zlib", error::invalid_bit_length_repeat);
        check("boost.zlib", error::missing_eob);
        check("boost.zlib", error::invalid_literal_length);
        check("boost.zlib", error::invalid_distance_code);
        check("boost.zlib", error::invalid_distance);

        check("boost.zlib", error::over_subscribed_length);
        check("boost.zlib", error::incomplete_length_set);

        check("boost.zlib", error::general);
    }
};

TEST_SUITE(error_test, "zlib.error");

} // zlib
} // boost
