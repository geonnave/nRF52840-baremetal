# nRF52840 baremetal
Dead simple, no requirements (not even nrf*.h), baremetal code for a nRF52840 device.

Compile, link, and flash with: `make clean all flash`

# Dependencies

#### Here's what you need:
- Software to write code:
    - any text editor ([VS Code](https://code.visualstudio.com/), [neovim](https://neovim.io/), etc.) ¹
- Software to build your project:
    - any Unix-like terminal
    - [arm-none-eabi toolchain](https://developer.arm.com/downloads/-/gnu-rm) ¹
    - [make](https://www.gnu.org/software/make/) ¹
- Software to talk to your board: [J-Link](https://www.segger.com/downloads/jlink/)

¹ probably also available from your package manager.

#### And here's what you DO NOT need:
- An IDE
- Manufacturer-provided code, headers or blobs
