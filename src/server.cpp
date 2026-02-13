#include "server.h"
#include "config.h"
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

void Server::run() {
    httplib::Server server;

    server.Get("/health", [](const httplib::Request&, httplib::Response& res) {
        nlohmann::json response = {
            {"status", "ok"}
        };
        res.set_content(response.dump(), "application/json");
    });

    auto host = Config::get_host();
    auto port = Config::get_port();

    spdlog::info("Starting server on {}:{}", host, port);
    server.listen(host.c_str(), port);
}
