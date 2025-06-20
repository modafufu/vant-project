cmake_minimum_required(VERSION 3.12)
project(VANET_AUTHENTICATION LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -O0")

set(GMP_INCLUDE_DIR "/usr/include/x86_64-linux-gnu")
set(GMP_LIBRARY "/usr/lib/x86_64-linux-gnu/libgmp.so")

find_package(OpenSSL REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${GMP_INCLUDE_DIR}
    /usr/local/include
)

link_directories(
    /usr/local/lib
    /usr/lib/x86_64-linux-gnu
)

add_executable(vanet_auth
    src/main.cpp
    src/zk_snark.cpp
)

target_link_libraries(vanet_auth
    ${GMP_LIBRARY}
    gmp
    gmpxx
    ssl
    crypto
    pthread
    dl
)

install(TARGETS vanet_auth DESTINATION bin)

message(STATUS "GMP配置验证：")
message(STATUS "  - 头文件路径: ${GMP_INCLUDE_DIR}/gmp.h")
message(STATUS "  - 库文件路径: ${GMP_LIBRARY}")