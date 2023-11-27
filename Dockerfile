FROM gcc:latest

# Install oh-my-zsh
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    entr \
    clang \
    clang-format \
    cmake \
    gdb \
    wget

SHELL ["/bin/zsh", "-c"]

WORKDIR /usr/src/app