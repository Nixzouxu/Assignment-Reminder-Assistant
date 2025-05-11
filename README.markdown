# Task Reminder Assistant

Welcome to the **Task Reminder Assistant**, a simple yet powerful Command Line Interface (CLI) application built in C. This project is designed to help you manage your tasks efficiently by allowing you to add, delete, mark tasks as completed, display tasks with prioritization based on deadlines, and save your progress. The application includes a user-friendly interface with colors, borders, and basic animations to enhance the experience. It is an excellent project for beginners, especially students in their second semester of computer science, and can serve as a portfolio piece to showcase your programming skills.

This README will guide you step-by-step through installing, running, and using the project, as well as troubleshooting common issues and contributing to its development.

## Table of Contents
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [File Structure](#file-structure)
- [Customization](#customization)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Features
- **Add Tasks:** Input new tasks with a title, category, and deadline.
- **Delete Tasks:** Remove tasks by their unique ID.
- **Mark Tasks Completed:** Mark a task as completed using its ID.
- **Display Tasks:** View all tasks with details (ID, title, category, deadline, and status) in a formatted table.
- **Prioritize Tasks:** Automatically sort tasks by deadline to help you focus on urgent ones.
- **Persistent Storage:** Save and load tasks to/from a file (`data/tasks.txt`) to retain data between sessions.
- **Enhanced UI:** Features colorful text (green for success, red for errors, yellow for prompts), ASCII borders, and a simple loading animation.
- **Cross-Platform:** Works on Windows, Linux, and macOS with minimal adjustments.

## Prerequisites
Before you can install and run this project, ensure you have the following tools installed on your computer:

### Required Software
1. **GCC Compiler:**
   - A C compiler to build the program.
   - **Windows:** Install MinGW (Minimalist GNU for Windows) via [MinGW-w64](https://www.mingw-w64.org/) or MSYS2 ([https://www.msys2.org/](https://www.msys2.org/)).
   - **Linux:** Install GCC using your package manager (e.g., `sudo apt install gcc` on Ubuntu).
   - **macOS:** Install GCC via Homebrew with `brew install gcc`.
   - Verify installation by typing `gcc --version` in your terminal or Command Prompt.

2. **Make (Optional but Recommended):**
   - A build automation tool to simplify compilation.
   - **Windows:** Install with MinGW or MSYS2 (`pacman -S make`).
   - **Linux/macOS:** Usually pre-installed; install with `sudo apt install make` (Ubuntu) or `brew install make` (macOS) if missing.
   - Verify with `make --version`.

3. **Git (Optional):**
   - Used to clone the repository. Install from [https://git-scm.com/](https://git-scm.com/) and verify with `git --version`.

4. **Terminal or Command Line Interface:**
   - **Windows:** Command Prompt, PowerShell, or Windows Terminal.
   - **Linux/macOS:** Default terminal (e.g., Terminal or iTerm2).

### System Requirements
- **Operating System:** Windows 10+, Linux, or macOS.
- **RAM:** Minimum 1GB (recommended 4GB for smooth performance).
- **Disk Space:** Approximately 10MB for the project files and compiled executable.

## Installation
Follow these steps to set up the Task Reminder Assistant on your computer:

### Step 1: Clone or Download the Repository
1. **Using Git (Recommended):**
   - Open your terminal or Command Prompt.
   - Navigate to the directory where you want to store the project (e.g., `cd C:\Users\YourName\Projects` on Windows or `cd ~/Projects` on Linux/macOS).
   - Clone the repository:
     ```
     git clone https://github.com/yourusername/task-reminder.git
     ```
     (Replace `yourusername` and `task-reminder` with the actual GitHub URL if you host it there.)
   - Move into the project directory:
     ```
     cd task-reminder
     ```

2. **Manual Download:**
   - Download the ZIP file from the GitHub repository (if available) or copy the project files manually.
   - Extract the ZIP file to a folder (e.g., `C:\Users\YourName\Projects\task-reminder`).
   - Open a terminal and navigate to that folder.

### Step 2: Verify Folder Structure
Ensure the project folder contains the following files and directories:
- `src/`: Contains source files (`main.c`, `task.c`, `ui.c`).
- `include/`: Contains header files (`common.h`, `task.h`, `ui.h`).
- `data/`: Contains the `tasks.txt` file for storing tasks (create this folder with `mkdir data` if it’s missing).
- `Makefile`: Automates the compilation process.
- `README.md`: This file.
- `.gitignore`: Ignores temporary files.

If any files are missing, copy the code from the project documentation or let the developer know.

### Step 3: Compile the Project
There are two methods to compile the project:

#### Method 1: Using Makefile (Recommended)
1. Ensure `make` is installed (see Prerequisites).
2. In the terminal, run:
   ```
   make
   ```
   - This generates an executable file named `task_reminder` (or `task_reminder.exe` on Windows).
3. If you encounter errors (e.g., `make not found`), use `mingw32-make` on Windows or install `make`.

#### Method 2: Using GCC Manually
1. Run the following command in the terminal:
   ```
   gcc -Iinclude -Wall -g src/main.c src/task.c src/ui.c -o task_reminder
   ```
   - `-Iinclude`: Tells the compiler where to find header files.
   - `-Wall`: Enables all warning messages.
   - `-g`: Adds debugging information.
   - Replace `src/ui.c` with other source files if you modify the project.
2. This creates the `task_reminder` executable.

### Step 4: Run the Program
- **Windows:** Type `./task_reminder.exe` and press Enter.
- **Linux/macOS:** Type `./task_reminder` and press Enter.
- The program will start with a loading animation and display the main menu.

## Usage
Once the program is running, follow these steps to use it:

### Main Menu
The program displays a colorful menu with the following options:
1. **Add Task:** Enter a new task with a title, category, and deadline.
2. **Delete Task:** Remove a task by entering its ID.
3. **Mark Task Completed:** Mark a task as completed using its ID.
4. **Display Tasks:** View all tasks in a table format, sorted by deadline.
5. **Exit:** Save tasks and exit the program.

### Step-by-Step Example
1. **Start the Program:**
   - Run `./task_reminder` (or `.exe` on Windows). You’ll see a loading animation followed by the main menu.
2. **Add a Task:**
   - Select option `1`.
   - Enter the task title (e.g., `Finish Report`).
   - Enter the category (e.g., `Work`).
   - Enter the deadline (e.g., `2025-05-15`).
   - Press Enter after each input. A success message will confirm the task is added.
3. **Display Tasks:**
   - Select option `4` to see all tasks in a formatted table.
4. **Mark a Task Completed:**
   - Select option `3`, enter the task ID (e.g., `1`), and press Enter.
5. **Exit:**
   - Select option `5` to save your tasks and exit. A loading animation will play before the program closes.

### Input Format
- **Title and Category:** Up to 100 and 50 characters, respectively. Avoid special characters that might cause parsing issues.
- **Deadline:** Use the format `YYYY-MM-DD` (e.g., `2025-05-15`).
- **ID:** A unique number assigned to each task, visible in the task list.

## How It Works
- **Data Storage:** Tasks are stored in memory as a `Task` struct array and saved to `data/tasks.txt` in CSV format (e.g., `id,title,category,deadline,completed`).
- **Prioritization:** The `prioritizeTasks` function sorts tasks by deadline using a bubble sort algorithm.
- **UI Enhancements:** The `ui.c` file handles colors (using ANSI escape codes), borders, and animations for a better user experience.
- **File Handling:** The `loadFromFile` and `saveToFile` functions manage persistent storage.

## File Structure
Here’s a breakdown of the project’s organization:
- **`src/`:** Contains the source code.
  - `main.c`: The main program logic and menu.
  - `task.c`: Functions for task management (add, delete, etc.).
  - `ui.c`: UI-related functions (colors, animations, borders).
- **`include/`:** Contains header files.
  - `common.h`: Defines constants like `MAX_TITLE`.
  - `task.h`: Declares task management functions.
  - `ui.h`: Declares UI functions.
- **`data/`:** Stores task data.
  - `tasks.txt`: CSV file for saving tasks.
- **`Makefile`:** Automates compilation.
- **`README.md`:** This documentation.
- **`.gitignore`:** Excludes temporary files (e.g., `.o`, `.exe`).

## Customization
You can enhance the project further:
- **Add More Colors:** Modify `ui.h` to include additional ANSI color codes (e.g., `\x1B[35m` for magenta).
- **Change Animation:** Adjust the `printLoadingAnimation` function in `ui.c` to use different characters or durations.
- **Add Features:** Implement sorting by category or adding reminders with timestamps (requires additional libraries like `time.h`).
- **Improve UI:** Add more ASCII art or dynamic tables using libraries like `ncurses` (for advanced users).

To customize, edit the relevant `.c` or `.h` files, recompile with `make`, and test the changes.

## Troubleshooting
If you encounter issues, try these solutions:

- **Compilation Errors:**
  - **Error: `gcc not found`:** Ensure GCC is installed and added to your PATH (see Prerequisites).
  - **Error: `cannot find -linclude`:** Check the compilation command. Use `gcc -Iinclude -Wall -g ...` and ensure `include/` exists.
  - **Error: `header file not found`:** Verify `include/` contains `common.h`, `task.h`, and `ui.h`.

- **Runtime Issues:**
  - **Tasks Not Saving:** Ensure the `data/` folder exists and is writable. Create it with `mkdir data`.
  - **Colors Not Working (Windows):** Use Windows Terminal or PowerShell. Add `system("");` in `main.c` under `#ifdef _WIN32` to enable ANSI.
  - **Program Crashes:** Check input lengths (e.g., don’t exceed `MAX_TITLE` or `MAX_DATE`) and report the error.

- **General Tips:**
  - Run `make clean` and recompile if changes don’t reflect.
  - Share the error message with the developer for assistance.

## Contributing
We welcome contributions to improve this project! Here’s how you can help:
1. **Fork the Repository:** Create your own copy on GitHub.
2. **Clone Your Fork:** Use `git clone` to work locally.
3. **Make Changes:** Edit files, add features, or fix bugs.
4. **Test Thoroughly:** Ensure the program compiles and runs without errors.
5. **Submit a Pull Request:** Push your changes and request a merge on the original repository.

Please follow these guidelines:
- Write clear commit messages (e.g., `Add UI animation`).
- Add comments to your code for clarity.
- Test on multiple platforms if possible.

## License
This project is licensed under the **MIT License**. Feel free to use, modify, and distribute it as long as you include the original copyright notice. See the [LICENSE](LICENSE) file for details (create one if missing).

## Contact
For questions, suggestions, or support:
- **Email:** [m.hafidz9999@gmail.com](mailto:m.hafidz9999@gmail.com).
- **GitHub Issues:** Report bugs or feature requests at the repository’s Issues tab.
- **Developer:** [Nixzouxu].

Thank you for using the Task Reminder Assistant! Happy coding!