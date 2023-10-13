#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 20
void signup() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter a username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';


    FILE* file = fopen("users.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s,%s\n", username, password);
        fclose(file);
        printf("Signup successful!\n");
    } else {
        printf("Error: Failed to open file.\n");
    }
}
int login() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';


    FILE* file = fopen("users.txt", "r");
    if (file != NULL) {
        char line[MAX_LENGTH * 2];
        while (fgets(line, sizeof(line), file) != NULL) {
            line[strcspn(line, "\n")] = '\0'

            char* savedUsername = strtok(line, ",");
            char* savedPassword = strtok(NULL, ",");

            if (savedUsername != NULL && savedPassword != NULL &&
                strcmp(username, savedUsername) == 0 && strcmp(password, savedPassword) == 0) {
                fclose(file);
                printf("Login successful!\n");
                return 1;
            }
        }

        fclose(file);
    }

    printf("Invalid username or password. Please try again.\n");
    return 0;
}
int main() {
    int loggedIn = 0;
    int choice;

    printf("Welcome to the Signup and Login Console App!\n");

    while (!loggedIn) {
        printf("Choose an option:\n");
        printf("1. Signup\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                loggedIn = login();
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }


    return 0;
}
