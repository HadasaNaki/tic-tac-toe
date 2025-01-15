FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    libgtest-dev \
    python3 \
    python3-pip \
    git

RUN cd /usr/src/gtest && \
    cmake CMakeLists.txt && \
    make && \
    cp lib/*.a /usr/lib

RUN pip3 install pytest

WORKDIR /app

COPY src/ ./src/

COPY tests/ ./tests/

COPY CMakeLists.txt .

COPY .github/workflows/ci.yml ./.github/workflows/

RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    cmake --build .

CMD ["./build/src/tictactoe"]