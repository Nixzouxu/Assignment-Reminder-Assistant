#ifndef UI_H
#define UI_H

// ANSI Color Codes
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define BOLD    "\x1B[1m"

// UI Functions
void clearScreen();
void printHeader(const char *title);
void printBorder(int length, char symbol);
void printLoadingAnimation(int duration_ms);
void printSuccess(const char *message);
void printError(const char *message);

#endif