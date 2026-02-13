#include "config.h"
#include <cstdlib>

int Config::get_port() {
    const char* port = std::getenv("SERVICE_PORT");
    if (port) {
        return std::stoi(port);
    }
    return 8080; // default
}

std::string Config::get_host() {
    const char* host = std::getenv("SERVICE_HOST");
    if (host) {
        return std::string(host);
    }
    return "0.0.0.0";
}
std::string Config::get_log_level() {
    const char* level = std::getenv("LOG_LEVEL");
    if (level) {
        return std::string(level);
    }
    return "info";
}

