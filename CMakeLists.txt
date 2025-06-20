cmake_minimum_required(VERSION 3.12)
project(VANET_AUTHENTICATION LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 调试配置
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -O0")

# 1. 显式设置GMP路径（Debian标准路径）
set(GMP_INCLUDE_DIR "/usr/include/x86_64-linux-gnu")
set(GMP_LIBRARY "/usr/lib/x86_64-linux-gnu/libgmp.so")

# 2. 依赖查找
find_package(OpenSSL REQUIRED)

# 3. 包含目录（现代CMake推荐使用target_include_directories）
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/libsnark
    ${CMAKE_SOURCE_DIR}/libff
    ${GMP_INCLUDE_DIR}  # 显式添加GMP头文件路径
    /usr/local/include
)

# 4. 库路径配置
link_directories(
    /usr/local/lib
    /usr/lib/x86_64-linux-gnu  # 标准库路径
)

# 添加编译选项以定义椭圆曲线
add_definitions(-DCURVE_ALT_BN128)

# 5. 可执行文件
add_executable(vanet_auth
    src/main.cpp
    src/initialization.cpp
    src/registration.cpp
)

# 6. 链接库（直接使用绝对路径确保可靠性）
target_link_libraries(vanet_auth
    snark
    ff
    ${GMP_LIBRARY}  # 使用绝对路径链接 GMP
    gmp             # 添加 GMP 库
    gmpxx           # 添加 GMP 的 C++ 接口库
    ssl
    crypto
    pthread
    dl
)

# 7. 安装规则
install(TARGETS vanet_auth DESTINATION bin)

# 8. 验证配置
message(STATUS "GMP配置验证:")
message(STATUS "  - 头文件路径: ${GMP_INCLUDE_DIR}/gmp.h")
message(STATUS "  - 库文件路径: ${GMP_LIBRARY}")