#ifndef TASK_H
#define TASK_H

#include "../include/common.h"

typedef struct {
    int id;
    char title[MAX_TITLE];
    char category[MAX_CATEGORY];
    char deadline[MAX_DATE]; // Format: YYYY-MM-DD
    int completed;
} Task;

void addTask(Task *tasks, int *count);
void deleteTask(Task *tasks, int *count, int id);
void markTaskCompleted(Task *tasks, int count, int id); // Diubah menjadi int
void displayTasks(Task *tasks, int count);
void prioritizeTasks(Task *tasks, int count);
void saveToFile(Task *tasks, int count);
void loadFromFile(Task *tasks, int *count);

#endif