cmake_minimum_required(VERSION 3.5)

project(cpp-client)
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 23)

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message(STATUS "CMAKE_OSX_SYSROOT: ${CMAKE_OSX_SYSROOT}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

find_package(PkgConfig REQUIRED)

find_package(Boost COMPONENTS system filesystem thread REQUIRED)
if (Boost_FOUND)
    message(STATUS "Found Boost: ${Boost_LIBRARIES}")
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_LIBRARIES(${Boost_LIBRARIES})
endif (Boost_FOUND)

find_package(folly REQUIRED)
if (folly_FOUND)
    message(STATUS "Found folly2: ${FOLLY_LIBRARIES}")
    INCLUDE_DIRECTORIES(${folly_INCLUDE_DIRS})
    LINK_LIBRARIES(${FOLLY_LIBRARIES})
endif (folly_FOUND)

find_package(gflags REQUIRED)
message(STATUS "Found gflags: ${gflags_INCLUDE_DIRS} : ${gflags_LIBRARIES}")

add_executable(client src/main.cc src/process.cc)
