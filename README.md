# chatgpt_clone

A simple raylib application that displays a window with text rendering. Built as a starting point for further development.

## Prerequisites

- CMake 3.20+
- MinGW-w64 (GCC) — ensure `gcc` is in your `PATH`
- Internet connection (first build only, to fetch raylib source)
- [Visual Studio Code](https://code.visualstudio.com/) (recommended)

### Recommended VS Code Extensions

Install these extensions for an enhanced development experience:

- **clangd** — C/C++ intellisense and code completion
- **SonarQube** — Code quality analysis
- **C/C++** — Microsoft's C/C++ extension (for debugging)
- **CMake Tools** — CMake integration
- **CodeLLDB** — Debugger for C/C++

> **Note:** These extensions are recommended but not required. You can build and run the project without them.

## VS Code Setup

### 1. Install Extensions

Install the recommended extensions listed in the Prerequisites section.

### 2. Configure clangd

The project includes a `.vscode/settings.json` that configures clangd to use the build directory for compile commands. After building, clangd will automatically provide intellisense.

### 3. Configure CMake Tools

CMake Tools will auto-detect the `CMakePresets.json` file. Use the preset named "default" for building.

### 4. Configure Debugger

For debugging, install the CodeLLDB extension. The project includes example launch configurations in the Debugging section below.

## Build

### Using CMake Presets (Recommended)

The project includes a `CMakePresets.json` file that defines build configurations:

```sh
# Configure using the default preset
cmake --preset default

# Build using the default preset
cmake --build --preset default
```

### Using Manual Commands (Alternative)

If you prefer manual configuration:

```sh
cmake -B build -S . -G Ninja -DCMAKE_C_COMPILER="gcc"
cmake --build build
```

### Build Output

The build process creates:
- `build/chatgpt_clone.exe` — The main executable
- `build/compile_commands.json` — Compilation database for clangd

## Run

```sh
build\chatgpt_clone.exe
```

## Debugging

### Prerequisites

- Install the **CodeLLDB** extension
- Build the project with debug symbols (included by default)

### Launch Configuration

Create a `.vscode/launch.json` file with the following content:

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug chatgpt_clone",
      "type": "lldb",
      "request": "launch",
      "program": "${workspaceFolder}/build/chatgpt_clone.exe",
      "args": [],
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false
    }
  ]
}
```

### Debugging Steps

1. Set breakpoints in your code by clicking in the gutter
2. Press `F5` or use Run > Start Debugging
3. The debugger will stop at your breakpoints
4. Use the Debug toolbar to step through code
5. Inspect variables in the Variables panel

### Debug Build

To ensure debug symbols are included, build with:

```sh
cmake --preset default -DCMAKE_BUILD_TYPE=Debug
cmake --build --preset default
```

## How It Works

- raylib is fetched and built from source via CMake `FetchContent` — no package manager required
- raylib and GLFW are statically linked into the final executable
- The resulting `.exe` is self-contained and runs on any Windows system with OpenGL 3.3 support

## Project Structure

```
chatgpt_clone/
├── CMakeLists.txt   # Build configuration
├── main.c           # Application entry point
└── README.md
```

## License

This project uses [raylib](https://www.raylib.com/) (zlib license).
