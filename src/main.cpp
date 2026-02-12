#include <httplib.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

int main() {
    httplib::Server server;

    server.Get("/health", [](const httplib::Request&, httplib::Response& res) {
        nlohmann::json response = {
            {"status", "ok"}
        };

        res.set_content(response.dump(), "application/json");
    });

    spdlog::info("Starting server on port 8080...");
    server.listen("0.0.0.0", 8080);

    return 0;
}

