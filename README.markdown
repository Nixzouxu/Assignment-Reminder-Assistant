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
3. If you encounter errors (e.g., `make not found`), use `