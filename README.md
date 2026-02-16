<<<<<<< HEAD
Build Command

cmake -B build -S . \
  -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake

  or tu run cmake in manifest mode use this command

  cmake -B build -S . \
  -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake \
  -DVCPKG_FEATURE_FLAGS=manifests

  
=======
# 🧰 C++ Dependency Management using CMake + vcpkg

## 📌 Project Overview

This project demonstrates how modern C++ projects manage external dependencies using **CMake** and **vcpkg (Manifest Mode)**.

The goal is to simulate an industry-style build workflow where dependencies are **automatically installed during the build** without any manual setup.

---

## 🔧 Tech Stack

- CMake (Build System)
- vcpkg (C++ Package Manager)
- Manifest Mode Dependency Management
- Modern CMake (`find_package`)

---

## 🏗️ Project Structure

```
project-root/
├── src/
├── include/
├── vcpkg.json
└── CMakeLists.txt
```

---

## 🧱 Step 1 — Why Dependency Management Matters

Real-world C++ projects depend on external libraries such as:

- nlohmann_json  
- fmt  
- spdlog  
- boost  

Manually installing libraries is:

- Time consuming  
- Error prone  
- Hard to reproduce on other machines  

We solve this using **vcpkg Manifest Mode**.

---

## 📦 Step 2 — vcpkg Manifest File

The project includes a dependency manifest:

```
vcpkg.json
```

### Example

```json
{
  "dependencies": [
    "nlohmann-json"
  ]
}
```

This file tells vcpkg:

> “These are the libraries my project needs.”

---

## ⚙️ Step 3 — Build Commands

Run from the project root:

```bash
cmake -B build -S . \
  -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake

>>>>>>> a42604abd33849b61e8b7c1061dd604e0baf7ba7
cmake --build build
```

---

## 🛠️ Step 4 — Understanding the Toolchain File

Command used:

```
-DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
```

This is **not**:

- A build directory  
- A source directory  

It is an instruction to CMake:

> “Before configuring the project, load this extra configuration file.”

---

## 🔍 Step 5 — What Is a Toolchain File?

A toolchain file tells CMake:

- Which compiler to use  
- Where to search for libraries  
- Where to search for header files  
- How to link dependencies  
- Platform-specific configuration  

Think of it as:

```
CMake + Extra Rules = Toolchain
```

---

## ❌ What Happens Without vcpkg?

When CMake sees:

```cmake
find_package(nlohmann_json CONFIG REQUIRED)
```

CMake searches only in system locations:

```
/usr/lib
/usr/include
```

But our libraries are actually inside:

```
~/vcpkg/installed/x64-linux/
```

By default, CMake does not know this path.

---

## 🔄 Step 6 — What the vcpkg Toolchain Does

When the toolchain file is passed:

```bash
-DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
```

CMake loads vcpkg before project configuration.

The toolchain automatically:

- Detects `vcpkg.json`
- Checks required dependencies
- Downloads missing packages
- Builds the libraries
- Adds include paths
- Adds library paths
- Updates `CMAKE_PREFIX_PATH`
- Makes `find_package()` work seamlessly

---

## 📥 Step 7 — Automatic Dependency Installation

When CMake runs:

```
CMake → Loads vcpkg toolchain
       → Detects vcpkg.json
       → Installs missing packages automatically
```

Libraries are installed to:

```
~/vcpkg/installed/x64-linux/
```

This means:

- No manual installation  
- No setup scripts  
- No dependency mismatch  

---

## 🧠 Step 8 — Build Workflow Architecture

### ❌ Traditional CMake

```
CMake → Searches System Libraries Only → Build may fail
```

### ✅ CMake + vcpkg Toolchain

```
CMake
  ↓
Loads vcpkg toolchain
  ↓
vcpkg installs dependencies
  ↓
CMake discovers libraries
  ↓
Build succeeds 🎉
```

---

## 🏆 What This Setup Demonstrates

- Modern C++ dependency management  
- Reproducible builds across machines  
- Automatic dependency installation  
- Clean developer onboarding  
- Industry-standard CMake workflow  

---

## 💡 Key Learnings

- What a CMake toolchain file is  
- How vcpkg integrates with CMake  
- Difference between system libraries and package manager libraries  
- How `find_package()` works internally  
- How Manifest Mode automates dependency installation  

---

## 🎯 Result

A fully automated build system where:

- Dependencies are declared once  
- Installed automatically  
- Detected by CMake  
- Built consistently on any machine  

---
