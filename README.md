# Simple Shell Project
This project implements a simple UNIX command interpreter shell in C programming language, capable of running commands in both interactive and non-interactive modes. It provides a basic understanding of how shells work and serves as a starting point for further exploration and customization.


## Main Features
- Runs in both interactive (REPL) and non-interactive modes
- Implements built-in `exit` and `env` commands
- Splits input into tokens using a delimiter
- Forks processes to execute commands from `$PATH`
- Searches across list of paths to locate commands
- Outputs error if command not found
- Counts number of commands executed


## Code Files
- functions_builtins.c
- functions_count_tokens.c  
- functions_execute_fork.c
- functions_free.c
- functions_get_path.c
- functions_getc.c
- functions_getline.c 
- functions_handle_execution.c
- functions_ignore_spaces.c
- functions_is_builtin.c
- functions_number_to_string.c
- functions_putc.c
- functions_search_path.c 
- functions_split.c
- functions_string_strlen.c
- main.c
- main.h
- shell.c
- shell_interactive.c
- shell_noninteractive.c


## Function Definitions
### Main Shell Functions
**shell**
- Decides whether to run in interactive or non-interactive mode

**shell_interactive** 
- Implements REPL loop prompting for user input  

**shell_noninteractive**
- Reads input from stdin and executes

### Execute Command Functions
**handle_execution**
- Parses input and executes commands  

**execute_fork**
- Spawns process and runs command using execve

### Path Functions
**get_path**
- Gets PATH environment variable 

**search_path**
- Finds full path for command from PATH


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

## Contributing  <!-- Guidelines for contributing to the project -->

If you'd like to contribute to this project, please send to me.

## License  <!-- Information about the project's licensing -->

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
