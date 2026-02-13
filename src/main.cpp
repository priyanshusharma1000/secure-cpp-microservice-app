#include <spdlog/spdlog.h>
#include "config.h"
#include "server.h"

int main() {
    auto level = Config::get_log_level();

    if (level == "debug")
        spdlog::set_level(spdlog::level::debug);
    else if (level == "info")
        spdlog::set_level(spdlog::level::info);
    else if (level == "warn")
        spdlog::set_level(spdlog::level::warn);
    else if (level == "error")
        spdlog::set_level(spdlog::level::err);

    Server server;
    server.run();
    return 0;
}
