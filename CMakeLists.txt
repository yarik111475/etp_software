cmake_minimum_required(VERSION 3.14)
set(PROJECT_NAME etp_software)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ETP_COMMON_INCLUDE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/etp_common/src
    )

#spdlog
set(SPDLOG_MASTER_PROJECT OFF)
set(SPDLOG_INSTALL OFF)
set(SPDLOG_BUILD_SHARED OFF)

#boost
if(WIN32)
    set(BOOST_ROOT "C:/boost")
    set(BOOST_INCLUDEDIR "C:/boost/include")
    set(BOOST_LIBRARYDIR "C:/boost/lib")
endif()

if(LINUX)
    set(BOOST_ROOT "/usr")
    set(BOOST_INCLUDEDIR "/usr/include")
    set(BOOST_LIBRARYDIR "/usr/lib")
endif()

set(Boost_DEBUG 1)
set(Boost_USE_STATIC_LIBS ON)

add_definitions( -DHAS_BOOST )
if(WIN32)
    #add_definitions(-DBOOST_USE_WINDOWS_H)
    add_definitions(-D_WIN32_WINNT=0x0601)
endif()

add_subdirectory(etp_server/src)
add_subdirectory(etp_client/src)
add_subdirectory(lib/etp_common/src)
add_subdirectory(lib/3rdparty/spdlog-1.9.2)
