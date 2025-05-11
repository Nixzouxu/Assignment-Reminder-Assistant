#include <stdio.h>
#include "task.h"
#include "../include/ui.h"

int main() {
    Task tasks[100];
    int count = 0;
    int choice;

    // Animasi loading saat program dimulai
    printLoadingAnimation(1500); // 1.5 detik
    printHeader("=== Task Reminder Assistant ===");

    loadFromFile(tasks, &count);
    printSuccess("Tasks loaded successfully!");

    do {
        printHeader("=== Task Reminder Assistant ===");
        printf("%s1. %sAdd Task\n", BOLD, GREEN);
        printf("%s2. %sDelete Task\n", BOLD, GREEN);
        printf("%s3. %sMark Task Completed\n", BOLD, GREEN);
        printf("%s4. %sDisplay Tasks\n", BOLD, GREEN);
        printf("%s5. %sExit\n", BOLD, GREEN);
        printf("%sChoose: %s", YELLOW, RESET);
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTask(tasks, &count);
                printSuccess("Task added successfully!");
                break;
            case 2: {
                int id;
                printHeader("=== Delete Task ===");
                printf("%sEnter task ID to delete: %s", YELLOW, RESET);
                scanf("%d", &id);
                deleteTask(tasks, &count, id);
                break;
            }
            case 3: {
                int id;
                printHeader("=== Mark Task Completed ===");
                printf("%sEnter task ID to mark completed: %s", YELLOW, RESET);
                scanf("%d", &id);
                markTaskCompleted(tasks, count, id);
                break;
            }
            case 4:
                printHeader("=== Task List ===");
                prioritizeTasks(tasks, count);
                displayTasks(tasks, count);
                break;
            case 5:
                saveToFile(tasks, count);
                printSuccess("Tasks saved. Exiting...");
                printLoadingAnimation(1000); // Animasi saat keluar
                break;
            default:
                printError("Invalid choice! Please try again.");
        }

        // Jeda agar pengguna dapat membaca pesan sebelum layar dibersihkan
        printf("\n%sPress Enter to continue...%s", YELLOW, RESET);
        getchar(); // Membersihkan buffer
        getchar(); // Menunggu input Enter
    } while (choice != 5);

    return 0;
}