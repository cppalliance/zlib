# Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
# Copyright (c) 2021 Dmitry Arkhipov (grisumbras@gmail.com)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
# Official repository: https://github.com/cppalliance/zlib
#

cmake_minimum_required(VERSION 3.8...3.16)

if(BOOST_SUPERPROJECT_VERSION)
    set(BOOST_ZLIB_VERSION VERSION ${BOOST_SUPERPROJECT_VERSION})
endif()

project(boost_zlib VERSION "${BOOST_ZLIB_VERSION}" LANGUAGES C CXX)


set(BOOST_ZLIB_IS_ROOT OFF)
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(BOOST_ZLIB_IS_ROOT ON)
endif()

if(BOOST_ZLIB_IS_ROOT)
    include(CTest)
endif()
if(NOT BOOST_SUPERPROJECT_VERSION)
    option(BOOST_ZLIB_INSTALL "Install boost::zlib files" ON)
    option(BOOST_ZLIB_BUILD_TESTS "Build boost::zlib tests" ${BUILD_TESTING})
else()
    set(BOOST_ZLIB_BUILD_TESTS ${BUILD_TESTING})
endif()


include(GNUInstallDirs)
if(BOOST_ZLIB_IS_ROOT)
    # Building inside Boost tree, but as a separate project e.g. on Travis or
    # other CI, or when producing Visual Studio Solution and Projects. This is
    # when we have to add dependencies to the project manually.
    foreach(lib
        # direct dependencies
        assert
        config
        core
        static_assert
        system
        throw_exception

        # indirect dependencies
        predef
        winapi
    )
        add_subdirectory(../${lib} libs/${lib} EXCLUDE_FROM_ALL)
        set(target boost_${lib})
        if(TARGET ${target})
          get_target_property(lib_type ${target} TYPE)
          if(NOT ${lib_type} STREQUAL INTERFACE_LIBRARY)
            set_property(TARGET ${target} PROPERTY FOLDER _deps/${lib})
          endif()
        endif()
    endforeach()
endif()


file(GLOB_RECURSE BOOST_ZLIB_HEADERS CONFIGURE_DEPENDS
    include/boost/*.hpp
    include/boost/*.ipp
)

set(BOOST_ZLIB_SOURCES src/src.cpp)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/include/boost" PREFIX "" FILES ${BOOST_ZLIB_HEADERS})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX "" FILES ${BOOST_ZLIB_SOURCES})


add_library(boost_zlib ${BOOST_ZLIB_HEADERS} ${BOOST_ZLIB_SOURCES})
add_library(Boost::zlib ALIAS boost_zlib)
target_compile_features(boost_zlib PUBLIC cxx_constexpr)
target_compile_definitions(boost_zlib PUBLIC BOOST_ZLIB_NO_LIB=1)
if(BOOST_SUPERPROJECT_VERSION)
    target_include_directories(boost_zlib PUBLIC "${PROJECT_SOURCE_DIR}/include")
else()
    target_include_directories(boost_zlib
        PUBLIC
            "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
            "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
    )
endif()
target_link_libraries(boost_zlib
    PUBLIC
        Boost::assert
        Boost::config
        Boost::core
        Boost::static_assert
        Boost::system
        Boost::throw_exception
)


if(BUILD_SHARED_LIBS)
    target_compile_definitions(boost_zlib PUBLIC BOOST_ZLIB_DYN_LINK=1)
else()
    target_compile_definitions(boost_zlib PUBLIC BOOST_ZLIB_STATIC_LINK=1)
endif()


if(BOOST_ZLIB_INSTALL AND NOT BOOST_SUPERPROJECT_VERSION)
    install(TARGETS boost_zlib
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    )
endif()


if(BOOST_ZLIB_BUILD_TESTS)
    add_subdirectory(test)
endif()
