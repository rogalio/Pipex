![Pipex Image](https://i.imgur.com/8g0WQ3V.png)

# Pipex Project :electric_plug: :computer:

## About Pipex :page_facing_up:

Pipex is an exciting coding project that emulates the behavior of the Unix `pipe` command (`|`) in C. It showcases efficient use of file descriptors, process creation with `fork`, and inter-process communication with Unix pipes.

## Features :sparkles:

- **Unix Pipe Emulation**: Mimics the behavior of Unix pipes to connect commands.
- **Process Management**: Utilizes `fork` to create child processes for command execution.
- **Error Handling**: Robust error handling for a seamless user experience.
- **File Descriptor Management**: Efficient handling of file I/O operations.

## How it Works :gear:

The project reads commands from the command line, creates a pipeline of processes, and connects their input and output streams accordingly. It primarily involves creating two processes using `fork`, where one process handles the input and the other handles the output.

## Code Structure :file_folder:

- `cmdline_parser.c`: Parses command line arguments and validates their count.
- `error_handling.c`: Contains functions for error reporting and handling.
- `file_handling.c`: Manages file operations like opening, checking permissions, etc.
- `pipe_creation.c`: Handles the creation and management of pipes between processes.
- `pipex_bonus.c`: Implements the bonus part, handling multiple pipes and the "here_doc" feature.
- `pipex_utils_bonus.c`: Utility functions for the bonus part, including file opening and usage instructions.
- `pipex_utils.c`: Utility functions for finding executable paths and executing commands.
- `pipex.c`: The main function that orchestrates the flow of the program.

## Installation and Compilation :wrench:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/rogalio/Pipex
   ```
2. **Compile the Project**:
   ```bash
   make
   ```
   This will compile the `pipex` program.

## Usage :bookmark_tabs:

Execute the program with the following syntax:
_./pipex file1 cmd1 cmd2 file2_
Where `file1` and `file2` are filenames, and `cmd1` and `cmd2` are Unix commands.

## Theoretical Aspects :books:

Pipex demonstrates inter-process communication using Unix pipes. It involves concepts like file descriptors, `fork` for process creation, and `execve` for executing commands. Error handling and file permissions are key aspects of its robust design.

## Contribution :handshake:

Contributions are welcome! If you have suggestions or improvements, feel free to fork the repository and submit a pull request.

## License :balance_scale:

This project is licensed under MIT. For more details, see the LICENSE file in the repository.

---

:star: Don't forget to star this project if you find it useful!
