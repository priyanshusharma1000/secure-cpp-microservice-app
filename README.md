# 🔐 Secure C++ Microservice — End-to-End Modern C++ + DevOps

## 📌 Project Overview

This project demonstrates how to build a **production-style C++ backend microservice** using modern C++ tooling, security, containerization and CI/CD.

The goal is to simulate an **industry-grade development workflow** where a simple HTTP server evolves into a:

* Secure HTTPS service
* Testable architecture
* Containerized application
* Automatically built and deployed system

This repository represents a **complete backend engineering journey**.

---

## 🔧 Tech Stack

* C++20
* CMake (Build System)
* vcpkg (Dependency Manager – Manifest Mode)
* cpp-httplib (HTTP/HTTPS Server)
* OpenSSL (TLS Encryption)
* nlohmann/json (JSON Handling)
* spdlog (Logging)
* GoogleTest (Unit Testing)
* Docker (Multi-Stage Build)
* GitHub Actions (CI/CD)

---

## 🏗️ Project Structure

```
secure-cpp-microservice/
├── src/
│   ├── main.cpp
│   ├── server.cpp
│   ├── config.cpp
│   └── metrics.cpp
│
├── include/
│   ├── server.hpp
│   ├── config.hpp
│   └── metrics.hpp
│
├── tests/
│   └── metrics_test.cpp
│
├── vcpkg.json
├── CMakeLists.txt
├── Dockerfile
└── .github/workflows/
```

---

# 🟢 Phase 1 — Solving C++ Dependency Hell (vcpkg + CMake)

## ❌ Problem

Real-world C++ projects depend on external libraries.

Manually installing them is:

* Time consuming
* Hard to reproduce
* Error-prone across machines

A fresh machine often cannot build the project.

## ✅ Solution

We used **vcpkg Manifest Mode** with CMake toolchain integration.

Dependencies are declared in:

```
vcpkg.json
```

```json
{
  "dependencies": [
    "cpp-httplib",
    "nlohmann-json",
    "spdlog"
  ]
}
```

## ⚙️ Build Command

```bash
cmake -B build -S . \
 -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake

cmake --build build
```

## 🧠 What the Toolchain Does

When passed, the toolchain:

* Detects `vcpkg.json`
* Installs missing libraries automatically
* Adds include and library paths
* Makes `find_package()` work seamlessly

## 🎯 Result

A **reproducible build** that works on any machine without manual setup.

---

# 🟡 Phase 2 — Hardcoded Apps Are Not Deployable

## ❌ Problem

Server configuration was hardcoded:

```cpp
server.listen("0.0.0.0", 8080);
```

Different environments require different configs.

## ✅ Solution

We introduced an **ENV-based configuration module**.

Environment variables supported:

| Variable     | Default |
| ------------ | ------- |
| SERVICE_HOST | 0.0.0.0 |
| SERVICE_PORT | 8080    |
| LOG_LEVEL    | info    |

## 🎯 Result

The service became **runtime configurable** and deployment-ready.

---

# 🧪 Phase 3 — Untestable Code Is Dangerous

## ❌ Problem

Business logic was tightly coupled to HTTP layer.

Testing required running the server.

## ✅ Solution

We separated layers:

```
Transport Layer (HTTP)
Business Logic (MetricsService)
```

Added **GoogleTest** integration.

Run tests:

```bash
cd build
ctest
```

## 🎯 Result

Fast, isolated, automated unit tests.

---

# 🔐 Phase 4 — HTTP Is Insecure

## ❌ Problem

Traffic over HTTP is readable by anyone.

Not production safe.

## ✅ Solution

We integrated **OpenSSL** and enabled HTTPS.

Server now runs using TLS certificates.

Test endpoint:

```bash
curl -k https://localhost:8080/health
```

## 🎯 Result

Secure encrypted communication.

---

# 🐳 Phase 5 — “Works on My Machine” Problem

## ❌ Problem

Application required manual setup and compilers.

Not portable.

## ✅ Solution — Multi-Stage Docker Build

We created a **two-stage Docker image**:

### Stage 1 — Builder

* Installs compilers + vcpkg
* Builds the project

### Stage 2 — Runtime

* Copies only final binary
* Generates TLS certs at runtime
* Runs secure server

Run with:

```bash
docker build -t secure-cpp-service .
docker run -p 8080:8080 secure-cpp-service
```

## 🎯 Result

A portable production container.

---

# ⚙️ Phase 6 — Automating the Software Lifecycle

## ❌ Problem

Manual builds and deployments do not scale.

## ✅ Solution — CI/CD with GitHub Actions

### CI Pipeline

Runs on every push:

* Install dependencies
* Build project
* Run tests
* Validate Docker build

### CD Pipeline

Runs on push to main:

* Login to DockerHub securely
* Build Docker image
* Push latest image automatically

## 🎯 Result

Fully automated **build → test → deploy** workflow.

---

# 🧠 Final Workflow Architecture

```
Developer Push
      ↓
GitHub Actions CI
(Build + Test + Docker Build)
      ↓
GitHub Actions CD
(Build Image + Push to DockerHub)
      ↓
Deploy Anywhere 🚀
```

---

# 🏆 What This Project Demonstrates

* Modern C++ backend engineering
* Secure HTTPS service development
* Dependency management using vcpkg
* Unit testing and modular architecture
* Containerization best practices
* CI/CD automation for C++ services

---

# 🎯 Final Result

A **secure, testable, containerized and auto-deployed C++ microservice** built using industry-grade practices.

---

⭐ If you like this project, consider giving it a star!
