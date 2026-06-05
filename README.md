## C++ Sandbox Repo

### Setting up a new project
The template folder `cpp-template` has the following structure:

```
project/
|-- CMakeLists.txt
|-- src/
|-- include/
|-- tests/
|-- build/
```

Short breakdown:
- `CMakeLists.txt` builds configuration for the project (name, C++ version, source files to compile, libraries to link, executables to create, test targets)
- `src/` contains implementation (`.cpp` code) files: function definitions, actual program run in `main.cpp`, etc.
- `include/` contains public header (`.h`/`.hpp`) files. You'll learn more about this later. For now, you can think of it as simply the "what" of the project (just function headers) where as `src/` contains the "how" (actual implementation).
- `tests/` contains unit tests
- `build/` contains generated build artifacts. This directory is created by CMake, you should not need to edit anything here and should not commit these to Git.

You can copy over the folder for a new project and work from that blank template. The only update you should have to make is in the `CMakeLists.txt` file, where you need to update both instances of the `MyProject` placeholder text with the actual name of the project.

When you are ready to start running and compiling code, within the terminal, `cd` into the `build/` director and run the code `cmake ..` to configure, and then `cmake --build .` to build, then run `./MyProject` from the command line (with the updated name of `MyProject` that you changed when you copied the template and started working) which should print any output from the code into the terminal.

