# MiniLibC

A custom, lightweight implementation of the C Standard Library (libc) from scratch, designed to interface directly with Linux system calls. 

This project was built to deepen my understanding of operating system internals, memory management, and the low-level mechanics of how C programs interact with the Linux kernel without relying on the standard GNU C Library (glibc).

## Features

This implementation provides core functionalities typically found in the standard C library, including:

*   **System Call Wrappers:** Direct interfacing with the Linux kernel using assembly.
*   **Memory Management:** 
    *   Dynamic memory allocation (`malloc`, `free`, `calloc`, `realloc`).
    *   Memory mapping and unmapping (`mmap`, `munmap`).
    *   Implementation of a custom memory block list (`mem_list`) to track allocations.
*   **Input/Output Operations:**
    *   File descriptor manipulation (`open`, `close`, `read`, `write`, `lseek`, `truncate`, `ftruncate`).
    *   Standard output functions (`puts`).
*   **Process Control:**
    *   Process termination (`exit`).
    *   Execution suspension (`sleep`, `nanosleep`).
*   **String Manipulation:**
    *   Common string and memory operations (e.g., `strlen`, `strcpy`, `strcmp`, `memcpy`, `memset`, etc.).
*   **File Status:**
    *   Retrieving file attributes (`stat`, `fstat`, `fstatat`).

## Tech Stack

*   **Language:** C
*   **Architecture:** x86_64
*   **OS:** Linux
*   **Build System:** Make

## Project Structure

The project is organized into several modules for clarity and maintainability:

*   `crt/`: C runtime startup code (e.g., `_start`, `__libc_start_main`).
*   `include/`: Header files defining the API for the standard library functions and internal structures.
*   `io/`: Implementations of file and standard I/O functions.
*   `mm/`: Memory management implementations (`malloc`, `mmap`, etc.).
*   `process/`: Process control functions (`exit`, `sleep`).
*   `stat/`: Functions for retrieving file status.
*   `string/`: String and memory block manipulation functions.
*   `syscall.c`: The core mechanism for invoking Linux system calls.

## How to Build and Use

### Prerequisites
*   A Linux environment (x86_64 architecture).
*   GCC (GNU Compiler Collection).
*   Make.

### Building the Library

1.  Clone the repository:
    ```bash
    git clone [https://github.com/yourusername/minilibc.git](https://github.com/stefanitastoica/MiniLibC.git)
    cd minilibc
    ```
2.  Run `make` to compile the library. This will typically generate the object files and the final library file (e.g., a static `.a` or shared `.so` library, depending on the `Makefile` configuration).
    ```bash
    make
    ```
