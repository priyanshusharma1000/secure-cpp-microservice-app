#pragma once
#include <string>

class Config {
public:
    static int get_port();
    static std::string get_host();
    static std::string get_log_level();

};
