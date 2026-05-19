# fdrop

fdrop is a lightweight, command-line steganography tool written in modern C++ using the xmake build system. It allows you to conceal secret text messages inside the pixel data of uncompressed BMP images without visibly altering them, and decode them back later.

> "A dead drop (or fdrop) is a method of espionage used to pass items or information between two individuals using a secret location."

## Features

- **Modern C++**: Built utilizing clean object-oriented design and modern STL libraries.  
- **LSB Steganography**: Uses the Least Significant Bit (LSB) method starting from the 100th byte of the BMP file to store text data.  
- **Null-Terminator Safe**: Correctly encodes and decodes terminal characters (`\0`), making it fully compatible with UTF-8 and Cyrillic symbols.  
- **Xmake Integration**: Compiled and managed flawlessly using the modern xmake build utility.  

## Installation & Build

This project is optimized for Linux (especially Arch Linux) and requires xmake and a modern C++ compiler (like `g++` or `clang`).

### 1. Install dependencies (Arch Linux)

```bash
sudo pacman -S xmake gcc
```

### 2. Clone the repository

```bash
git clone https://github.com/wellmq/fdrop.git
cd fdrop
```

### 3. Build the project

```bash
xmake
```

The compiled executable `fdrop` will be generated directly in the root directory.

### Alternative: Manual Compilation (Without Xmake)

If you don't want to use Xmake (or simply prefer doing things the hard way), you can compile the project manually using standard g++:

```bash
g++ src/*.cpp -Isrc -o fdrop
```

⚠️ **Note:** Xmake is the official and supported way to build this project. If you choose to compile it manually or write your own Makefiles, you are entirely on your own. Any build issues arising from manual compilation are your responsibility. Good luck!

## Usage

### Hide text inside an image (Encoding)

```bash
./fdrop -e "Your secret message here" "input.bmp" "output.bmp"
```

### Retrieve the hidden text (Decoding)

```bash
./fdrop -d "output.bmp"
```

## Project Structure

- `src/` — C++ source files (`main.cpp`, encoders, decoders, and file I/O helpers).  
- `xmake.lua` — Xmake build configuration.  
- `arch-linux.bmp` — Default test image.
