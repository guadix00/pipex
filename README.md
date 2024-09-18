# Pipex

## Project Overview

Pipex is a C programming project designed to emulate the behavior of a UNIX pipeline. It provides an opportunity to delve into system calls like `fork`, `pipe`, `exit`, `wait`, `waitpid`, `access`, and `execve`. The aim is to build a simplified UNIX pipeline by leveraging these system calls to create and manage multiple processes, ensuring effective communication between them.

## Execute Pipex

Run the program with the following command:
```
./pipex infile "command1" "command2" outfile
```
This will execute the commands as if you were running:
```
< infile command1 | command2 > outfile
```

## Project Arquitecture

The project has the following structure:

- **`src/pipex.c`**: Main file of the program. This is where the parent process and two child processes are created, and the necessary structure for the pipeline is initialized.
- **`src/exec.c`**: File where the path of the commands is found, and their existence is verified with `access`. The commands are executed using `execve`.
- **`src/pipex_utils.c`**: Contains auxiliary functions for error handling and memory management.
- **`src/pipex.h`**: Header file that declares the functions and structures used throughout the program.

