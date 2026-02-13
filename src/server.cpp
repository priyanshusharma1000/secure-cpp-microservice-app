#include "server.h"
#include "config.h"
#include "metrics.h"
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

void Server::run() {
    httplib::Server server;
    MetricsService metrics;

  server.Get("/health", [&metrics](const httplib::Request&, httplib::Response& res) {
        res.set_content(metrics.health_status(), "application/json");
    });

    auto host = Config::get_host();
    auto port = Config::get_port();

    spdlog::info("Starting server on {}:{}", host, port);
    server.listen(host.c_str(), port);
}
