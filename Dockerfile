# ---------- STAGE 1: BUILD ----------
FROM ubuntu:22.04 AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    curl \
    zip \
    unzip \
    pkg-config \
    ca-certificates



# Install vcpkg using zip snapshot (faster + reliable)
WORKDIR /opt

RUN curl -L https://github.com/microsoft/vcpkg/archive/refs/heads/master.zip -o vcpkg.zip \
    && unzip vcpkg.zip \
    && mv vcpkg-master vcpkg \
    && rm vcpkg.zip \
    && /opt/vcpkg/bootstrap-vcpkg.sh -disableMetrics


ENV VCPKG_ROOT=/opt/vcpkg

# Copy project
WORKDIR /app
COPY . .

# Build project using vcpkg toolchain
RUN rm -rf build
RUN cmake -S . -B build \
    -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake \
    -DCMAKE_BUILD_TYPE=Release

RUN cmake --build build

# ---------- STAGE 2: RUNTIME ----------
FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    ca-certificates

WORKDIR /app

# Copy binary from builder
COPY --from=builder /app/build/server .

# Copy certificates
COPY certs certs

EXPOSE 8080

CMD ["./server"]
