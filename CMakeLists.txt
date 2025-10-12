cmake_minimum_required(VERSION 3.20)
project(openai_hello CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)

add_executable(hello src/main.cpp)

# - "openai/openai.hpp" via ${PROJECT_ROOT}/external
# - "nlohmann/json.hpp" via ${PROJECT_ROOT}/external/openai
target_include_directories(hello PRIVATE
  ${CMAKE_SOURCE_DIR}/external
  ${CMAKE_SOURCE_DIR}/external/openai
)

target_link_libraries(hello PRIVATE CURL::libcurl)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  target_compile_options(hello PRIVATE -Wall -Wextra -Wpedantic)
endif()

