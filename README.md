Build Command
cmake -B build -S . \
  -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
  
cmake --build build



CMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
This is NOT the build directory.
This is NOT the source directory.
This is an instruction to CMake:
“Before you configure the project, load this extra configuration file.”


🔧 What Is a Toolchain File?
A toolchain file tells CMake:
Which compiler to use
Where to search for libraries
Where to search for include files
How to link dependencies
Platform-specific behavior

Think of it as:
“CMake, here are extra rules before you configure the project.”



🔥 Why We Need It for vcpkg
Without toolchain:
find_package(nlohmann_json CONFIG REQUIRED)
CMake searches in:
/usr/lib
/usr/include
System paths

But your libraries are NOT there.


They are inside:
~/vcpkg/installed/x64-linux/
CMake does NOT know about this directory.



💡 What The vcpkg Toolchain Does
When you pass:
-DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake

CMake loads that file first.
That file:

Automatically installs missing packages (manifest mode)
Adds vcpkg include paths
Adds vcpkg library paths
Modifies CMAKE_PREFIX_PATH
Makes find_package() work

So now:
find_package(nlohmann_json CONFIG REQUIRED)
works because CMake now knows where to look.


Libraries are not present locally, so how are they available?
Answer:
Because we are using vcpkg in manifest mode.
You created:
vcpkg.json


When CMake runs with vcpkg toolchain:
It sees vcpkg.json
It checks required dependencies
If missing → vcpkg downloads & builds them automatically
Installs them in:
~/vcpkg/installed/x64-linux/
That’s why you don’t manually install anything.


Think of it like this:

Normal CMake:
CMake → System Libraries Only

CMake + vcpkg toolchain:
CMake
  ↓
Loads vcpkg toolchain
  ↓
vcpkg installs dependencies
  ↓
CMake sees dependencies
  ↓
Build works







