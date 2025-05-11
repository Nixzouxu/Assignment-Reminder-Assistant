#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task.h"
#include "../include/ui.h"

void addTask(Task *tasks, int *count) {
    if (*count >= 100) {
        printError("Task list is full!");
        return;
    }

    Task newTask;
    newTask.id = *count + 1;
    newTask.completed = 0;

    printf("%sEnter task title: %s", YELLOW, RESET);
    getchar(); // Clear buffer
    fgets(newTask.title, MAX_TITLE, stdin);
    newTask.title[strcspn(newTask.title, "\n")] = 0;

    printf("%sEnter task category: %s", YELLOW, RESET);
    fgets(newTask.category, MAX_CATEGORY, stdin);
    newTask.category[strcspn(newTask.category, "\n")] = 0;

    printf("%sEnter deadline (YYYY-MM-DD): %s", YELLOW, RESET);
    fgets(newTask.deadline, MAX_DATE, stdin);
    newTask.deadline[strcspn(newTask.deadline, "\n")] = 0;

    tasks[*count] = newTask;
    (*count)++;
}

void deleteTask(Task *tasks, int *count, int id) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (tasks[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            (*count)--;
            found = 1;
            printSuccess("Task deleted successfully!");
            break;
        }
    }
    if (!found) printError("Task not found!");
}

void markTaskCompleted(Task *tasks, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (tasks[i].id == id) {
            tasks[i].completed = 1;
            printSuccess("Task marked as completed!");
            return;
        }
    }
    printError("Task not found!");
}

void displayTasks(Task *tasks, int count) {
    if (count == 0) {
        printError("No tasks available.");
        return;
    }

    printBorder(60, '*');
    printf("%sID | Title          | Category       | Deadline   | Status%s\n", BOLD, RESET);
    printBorder(60, '*');
    for (int i = 0; i < count; i++) {
        printf("%-2d | %-15s | %-15s | %-11s | %s%s%s\n",
               tasks[i].id, tasks[i].title, tasks[i].category,
               tasks[i].deadline,
               tasks[i].completed ? GREEN : YELLOW,
               tasks[i].completed ? "Completed" : "Pending",
               RESET);
    }
    printBorder(60, '*');
}

void prioritizeTasks(Task *tasks, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(tasks[j].deadline, tasks[j + 1].deadline) > 0) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
    printSuccess("Tasks prioritized by deadline.");
}

void saveToFile(Task *tasks, int count) {
    FILE *file = fopen("data/tasks.txt", "w");
    if (!file) {
        printError("Error opening file!");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%s,%d\n",
                tasks[i].id, tasks[i].title, tasks[i].category,
                tasks[i].deadline, tasks[i].completed);
    }
    fclose(file);
}

void loadFromFile(Task *tasks, int *count) {
    FILE *file = fopen("data/tasks.txt", "r");
    if (!file) return;

    *count = 0;
    while (*count < 100 && fscanf(file, "%d,%[^,],%[^,],%[^,],%d\n",
                                  &tasks[*count].id, tasks[*count].title,
                                  tasks[*count].category, tasks[*count].deadline,
                                  &tasks[*count].completed) == 5) {
        (*count)++;
    }
    fclose(file);
}