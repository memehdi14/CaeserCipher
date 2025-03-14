#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT_LENGTH 100
#define SHIFT 9
#define HISTORY_FILE "cipher_history.txt"


void encry(char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((input[i] - 'A' + SHIFT) % 26) + 'A';
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = ((input[i] - 'a' + SHIFT) % 26) + 'a';
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0';
}


void decry(char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((input[i] - 'A' - SHIFT + 26) % 26) + 'A';
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = ((input[i] - 'a' - SHIFT + 26) % 26) + 'a';
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0';
}

void write_to_history(const char *operation, const char *input, const char *output) {
    FILE *history_file = fopen(HISTORY_FILE, "a");
    if (!history_file) {
        printf("\n[Error] Could not open history file for writing.\n");
        return;
    }

    fprintf(history_file, "Operation: %s\nInput: %s\nOutput: %s\n\n", operation, input, output);
    fclose(history_file);
}


void display_history() {
    char line[MAX_TEXT_LENGTH];
    FILE *history_file = fopen(HISTORY_FILE, "r");

    if (!history_file) {
        printf("\n[No History Found] There are no previous records.\n");
        return;
    }

    printf("\n========== Cipher History ==========\n");
    while (fgets(line, sizeof(line), history_file)) {
        printf("%s", line);
    }
    printf("=====================================\n");

    fclose(history_file);
}


void process_file_content() {
    char filename[MAX_TEXT_LENGTH];
    char input[MAX_TEXT_LENGTH];
    char output[MAX_TEXT_LENGTH];
    int choice;

    printf("\nEnter the filename (with extension): ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("\n[Error] Could not open file: %s\n", filename);
        return;
    }

    if (fgets(input, sizeof(input), file) == NULL) {
        printf("\n[Error] File is empty or unreadable.\n");
        fclose(file);
        return;
    }
    input[strcspn(input, "\n")] = '\0';
    fclose(file);

    printf("\nFile Content: %s\n", input);
    printf("\nChoose an operation:\n");
    printf("[1] Encrypt\n");
    printf("[2] Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encry(input, output);
        printf("\n[Success] Encrypted string: %s\n", output);
        write_to_history("Encrypt (from file)", input, output);
    } else if (choice == 2) {
        decry(input, output);
        printf("\n[Success] Decrypted string: %s\n", output);
        write_to_history("Decrypt (from file)", input, output);
    } else {
        printf("\n[Error] Invalid choice.\n");
    }
}

void print_banner() {
    printf("=====================================\n");
    printf("|         WELCOME TO CIPHERCRYPT     |\n");
    printf("|       ENCRYPT & DECRYPT STRINGS    |\n");
    printf("|        HISTORY IS SAVED SAFELY     |\n");
    printf("=====================================\n");
}

void print_menu() {
    printf("\n------------ MAIN MENU ------------\n");
    printf("[1] Encrypt a string\n");
    printf("[2] Decrypt a string\n");
    printf("[3] View history\n");
    printf("[4] Process content from file\n");
    printf("[5] Exit\n");
    printf("-----------------------------------\n");
    printf("Enter your choice: ");
}

int main() {
    char input[MAX_TEXT_LENGTH], output[MAX_TEXT_LENGTH];
    int choice;

    print_banner();

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("\nEnter string to encrypt: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                encry(input, output);
                printf("\n[Success] Encrypted string: %s\n", output);
                write_to_history("Encrypt", input, output);
                break;

            case 2:
                printf("\nEnter string to decrypt: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                decry(input, output);
                printf("\n[Success] Decrypted string: %s\n", output);
                write_to_history("Decrypt", input, output);
                break;

            case 3:
                display_history();
                break;

            case 4:
                process_file_content();
                break;

            case 5:
                printf("\nThank you for using CipherCrypt! Goodbye!\n");
                return 0;

            default:
                printf("\n[Error] Invalid choice. Please try again.\n");
        }
    }
}
