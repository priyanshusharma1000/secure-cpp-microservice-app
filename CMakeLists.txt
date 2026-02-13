cmake_minimum_required(VERSION 3.20)
project(secure_cpp_microservice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(httplib CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)


add_executable(server
    src/main.cpp
    src/server.cpp
    src/config.cpp
)
target_include_directories(server PRIVATE ${CMAKE_SOURCE_DIR}/include)



target_link_libraries(server
    PRIVATE
    httplib::httplib
    nlohmann_json::nlohmann_json
    spdlog::spdlog
)
