cmake_minimum_required(VERSION 3.14)
set(PROJECT_NAME witsml_server)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp
    network/HttpServer.h
    network/HttpServer.cpp

    core/messages/Ping.h
    core/messages/Ping.cpp
    core/messages/Pong.h
    core/messages/Pong.cpp
    core/messages/Authorize.h
    core/messages/Authorize.cpp
    core/messages/Acknowledge.h
    core/messages/Acknowledge.cpp
    core/messages/OpenSession.h
    core/messages/OpenSession.cpp
    core/messages/CloseSession.h
    core/messages/CloseSession.cpp
    core/messages/RequestSession.h
    core/messages/RequestSession.cpp
    core/messages/ProtocolException.h
    core/messages/ProtocolException.cpp
    core/messages/AuthorizeResponse.h
    core/messages/AuthorizeResponse.cpp

    core/factories/MessageFactory.h
    core/factories/MessageFactory.cpp
)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)

add_executable(${PROJECT_NAME}
  ${PROJECT_SOURCES}
)
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Network
)
