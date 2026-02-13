#include <gtest/gtest.h>
#include "metrics.h"
#include <nlohmann/json.hpp>

TEST(MetricsServiceTest, HealthStatusReturnsOk) {
    MetricsService service;

    auto result = service.health_status();

    auto parsed = nlohmann::json::parse(result);

    EXPECT_EQ(parsed["status"], "ok");
}
