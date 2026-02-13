#include "metrics.h"
#include <nlohmann/json.hpp>

std::string MetricsService::health_status() const {
    nlohmann::json response = {
        {"status", "ok"}
    };

    return response.dump();
}
