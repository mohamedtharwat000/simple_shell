# simple_shell

A simple shell implementation in C.

## Introduction  <!-- Brief introduction to the project -->

This project is a simple shell implementation in C, capable of running commands in both interactive and non-interactive modes. It provides a basic understanding of how shells work and serves as a starting point for further exploration and customization.

## Features  <!-- List of key features in the project -->

- Interactive and non-interactive modes
- Basic command execution
- Support for built-in commands

## Getting Started  <!-- Instructions for setting up and running the project -->

### Prerequisites  <!-- Software requirements for running the project -->

Ensure you have the following installed:

- C Compiler (e.g., GCC)
- Standard C Library Headers

### Installation  <!-- Steps to clone and compile the project -->

Clone the repository and compile the source code:

```bash
git clone https://github.com/mohamedtharwat000/simple_shell.git
cd simple_shell
gcc -o your_shell_name *.c
```

## Usage  <!-- Instructions for using the project -->

### Interactive Mode  <!-- How to use the shell interactively -->
Run the shell:

```bash
./your_shell
Enter commands interactively.
```

### Non-Interactive Mode  <!-- How to use the shell in non-interactive mode -->
Run the shell with a script:

```bash
./your_shell < script.txt
Provide a script with commands to execute non-interactively.
```

## File Structure  <!-- Overview of the project's file organization -->

- `AUTHORS`: List of contributors to the project.
- `README.md`: This file you're reading right now.
- `functions_*.c`: Source files containing various shell functions.
- `main.c`: Main entry point of the program.
- `main.h`: Header file with function prototypes and definitions.
- `shell.c`: Contains the main shell function to determine interactive/non-interactive mode.
- `shell_interactive.c` and `shell_noninteractive.c`: Implementations for each mode.
- Other source files: Additional functions and utilities.

## Contributing  <!-- Guidelines for contributing to the project -->

If you'd like to contribute to this project, please send to me.

## License  <!-- Information about the project's licensing -->

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
