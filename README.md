# cpp-project-starter <!-- omit in toc -->

- [Description](#description)
- [Simple usage](#simple-usage)
- [Dependencies](#dependencies)
  - [Required dependencies](#required-dependencies)
  - [Optional dependencies](#optional-dependencies)
  - [Build dependencies](#build-dependencies)
- [Docker Instructions](#docker-instructions)

## Description

Basic scaffolding for future C++ projects using the CMake build system.

## Simple usage

In a new project folder run:

```bash
git pull https://github.com/qnimbus/cpp-project-starter
```

## Dependencies

Note about install commands:
- for Windows I use [choco](https://chocolatey.org/install).
- for MacOS I use [brew](https://brew.sh/).
- In case of an error in cmake, make sure that the dependencies are on the PATH.


### TL;DI - Too Long, Didn't Install <!-- omit in toc -->

If you don't feel like installing the dependencies yourself, you can use this docker image
See the [Docker instructions](#docker-instructions) below.

### Required dependencies

1. [CMake 3.20+]
  <details>
  <summary>Install Command</summary>

  - Debian/Ubuntu:

      sudo apt-get install cmake

  - Windows:

      choco install cmake -y

  - MacOS:

      brew install cmake

  </details>


2. [Conan]
  <details>
  <summary>Install Command</summary>

  - Via pip - https://docs.conan.io/en/latest/installation.html#install-with-pip-recommended

      pip install --user conan

  - Windows:

      choco install conan -y

  - MacOS:

      brew install conan

  </details>


### Optional dependencies

...

### Build dependencies

...


## Docker Instructions

If you have [Docker] installed, you can run this in your terminal, when the Dockerfile is in your working directory:

```bash
docker build --tag=my_project:latest .
docker run -it my_project:latest
```

This command will put you in a `bash` session in a Ubuntu 20.04 Docker container with all of the tools listed in the [Dependencies](#dependencies)section already installed. Additionally, you will have `g++-10` and `clang++-11` installed as the default versions of `g++` and `clang++`.

If you want to build this container using some other versions of gcc and clang you may do so with the `GCC_VER` and `LLVM_VER` arguments:

```bash
docker build --tag=myproject:latest --build-arg GCC_VER=9 --build-arg LLVM_VER=10 .
```

The CC and CXX environment variables are set to GCC version 10 by default. If you wish to use clang as your default CC and CXX environment variables you may do so like this:

```bash
docker build --tag=my_project:latest --build-arg USE_CLANG=1 .
```

You will be logged in as root, so you will see the `#` symbol as your prompt. You will be in a directory that contains a copy of the `cpp_starter_project`; any changes you make to your local copy will not be updated in the Docker image until you rebuild it. If you need to mount your local copy directly in the Docker image, see [Docker volumes docs].

**TL;DR**:

```bash
docker run -it \
  -v absolute_path_on_host_machine:absolute_path_in_guest_container \
  my_project:latest
```

You can configure and build [as directed above](#build) using these commands:

```bash
/starter_project# mkdir build
/starter_project# cmake -S . -B ./build
/starter_project# cmake --build ./build
```

You can configure and build using `clang-11`, without rebuilding the container,
with these commands:

```bash
/starter_project# mkdir build
/starter_project# CC=clang CXX=clang++ cmake -S . -B ./build
/starter_project# cmake --build ./build
```

The `ccmake` tool is also installed; you can substitute `ccmake` for `cmake` to
configure the project interactively. All of the tools this project supports are installed in the Docker image;
enabling them is as simple as flipping a switch using the `ccmake` interface. Be aware that some of the sanitizers conflict with each other, so be sure to run them separately.

[CMake 3.20+]:https://cmake.org/
[Conan]:https://conan.io/
[docker]:https://www.docker.com
[Docker volumes docs]:https://docs.docker.com/storage/volumes/
