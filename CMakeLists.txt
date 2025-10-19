cmake_minimum_required(VERSION 3.20)
project(openai_hello CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find libcurl (the HTTP engine the wrapper uses under the hood)
find_package(CURL REQUIRED)

add_executable(main_executable src/main.cpp)

# - "openai/openai.hpp" via ${PROJECT_ROOT}/external
# - "nlohmann/json.hpp" via ${PROJECT_ROOT}/external/openai
target_include_directories(main_executable PRIVATE
  ${CMAKE_SOURCE_DIR}/external
  ${CMAKE_SOURCE_DIR}/external/openai
)

target_link_libraries(main_executable PRIVATE CURL::libcurl)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  target_compile_options(main_executable PRIVATE -Wall -Wextra -Wpedantic)
endif()

