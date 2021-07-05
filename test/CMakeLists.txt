#
# Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
# Copyright (c) 2021 Dmitry Arkhipov (grisumbras@gmail.com)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
# Official repository: https://github.com/cppalliance/zlib
#


if(NOT TARGET tests)
    add_custom_target(tests)
    set_property(TARGET tests PROPERTY FOLDER _deps)
endif()


file(GLOB BOOST_ZLIB_TESTS_FILES CONFIGURE_DEPENDS Jamfile *.cpp *.hpp)
list(APPEND BOOST_ZLIB_TESTS_FILES
    extern/zlib-1.2.11/adler32.c
    extern/zlib-1.2.11/compress.c
    extern/zlib-1.2.11/crc32.c
    extern/zlib-1.2.11/deflate.c
    extern/zlib-1.2.11/infback.c
    extern/zlib-1.2.11/inffast.c
    extern/zlib-1.2.11/inflate.c
    extern/zlib-1.2.11/inftrees.c
    extern/zlib-1.2.11/trees.c
    extern/zlib-1.2.11/uncompr.c
    extern/zlib-1.2.11/zutil.c
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "" FILES ${BOOST_ZLIB_TESTS_FILES})
add_executable(boost_zlib-tests ${BOOST_ZLIB_TESTS_FILES})
target_include_directories(boost_zlib-tests PRIVATE .)
target_link_libraries(boost_zlib-tests PRIVATE Boost::zlib)
add_test(NAME boost_zlib-tests COMMAND boost_zlib-tests)
add_dependencies(tests boost_zlib-tests)
