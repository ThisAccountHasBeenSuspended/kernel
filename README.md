# kernel
It was an experimental 64-bit kernel project that was never continued.

<img src="screenshot.png?raw=true" alt="QEMU screenshot"/>

# 📋 Prerequisites
- A text editor such as [VS Code](https://code.visualstudio.com/).
- [Docker](https://www.docker.com/) for creating our build-environment.
- [QEMU](https://www.qemu.org/) for emulating our operating system.

# 💾 Getting Started
Start by cloning the repository with:
`git clone --recursive https://github.com/ThisAccountHasBeenSuspended/kernel.git`

## Setup
Build an image for our build-environment:
`docker build buildenv -t kernel-buildenv`

## Build
Enter build environment:
- Linux or MacOS: `docker run --rm -it -v "$(pwd)":/root/env kernel-buildenv`
- Windows (PowerShell): `docker run --rm -it -v "${pwd}:/root/env" kernel-buildenv`

### Commands
Build all:
`make`

Remove all build files:
`make clean`

Leave the build environment:
`exit`

## Emulate
You can emulate this kernel with [QEMU](https://www.qemu.org/) and the following console command:
`qemu-system-x86_64 -drive format=raw,file=build/kernel.iso`

## Cleanup
Remove the build-evironment image:
`docker rmi kernel-buildenv -f`

# 📝 License
This project is licensed under [MIT](https://github.com/ThisAccountHasBeenSuspended/kernel/blob/main/LICENSE)
