cmake_minimum_required(VERSION 3.20)
project(secure_cpp_microservice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


find_package(httplib CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)






add_executable(server
    src/main.cpp
    src/server.cpp
    src/config.cpp
    src/metrics.cpp
)
target_include_directories(server PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_definitions(server PRIVATE CPPHTTPLIB_OPENSSL_SUPPORT)



target_link_libraries(server
    PRIVATE
    httplib::httplib
    nlohmann_json::nlohmann_json
    spdlog::spdlog
    OpenSSL::SSL
    OpenSSL::Crypto
)



#testing
enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(tests
    tests/metrics_test.cpp
    src/metrics.cpp
)

target_include_directories(tests PRIVATE include)

target_link_libraries(tests
    PRIVATE
    GTest::gtest
    GTest::gtest_main
    nlohmann_json::nlohmann_json
)

add_test(NAME MetricsTests COMMAND tests)
