#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif
#include "../include/ui.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux/Mac
    #endif
}
void printHeader(const char *title) {
    clearScreen();
    printBorder(50, '=');
    printf("%s%s%s\n", BOLD, BLUE, title);
    printBorder(50, '=');
}

void printBorder(int length, char symbol) {
    for (int i = 0; i < length; i++) {
        printf("%c", symbol);
    }
    printf("\n");
}

void printLoadingAnimation(int duration_ms) {
    printf("Loading");
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout); // Memastikan teks langsung ditampilkan
        #ifdef _WIN32
            Sleep(duration_ms / 3); // Windows
        #else
            usleep((duration_ms / 3) * 1000); // Linux/Mac (usleep menggunakan mikrodetik)
        #endif
    }
    printf("\n");
}

void printSuccess(const char *message) {
    printf("%s%s%s\n", GREEN, message, RESET);
}

void printError(const char *message) {
    printf("%s%s%s\n", RED, message, RESET);
}