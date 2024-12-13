#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//new PR
#define FILE_NAME "users.txt"

typedef struct {
    int id;
    char name[50];
    int age;
} User;

void createUser();
void readUsers();
void updateUser();
void deleteUser();
void initializeFile();

int main() {
    int choice;
    initializeFile();

    do {
        printf("\n--- User Management System ---\n");
        printf("1. Add New User\n");
        printf("2. Display All Users\n");
        printf("3. Update User Details\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                readUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void initializeFile() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error initializing file.\n");
        exit(1);
    }
    fclose(file);
}

void createUser() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    User user;
    printf("Enter User ID: ");
    scanf("%d", &user.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", user.name);
    printf("Enter Age: ");
    scanf("%d", &user.age);

    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully!\n");
}

void readUsers() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    User user;
    printf("\n--- User Records ---\n");
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        printf("ID: %d | Name: %s | Age: %d\n", user.id, user.name, user.age);
    }
    fclose(file);
}

void updateUser() {
    int id, found = 0;
    printf("Enter the User ID to update: ");
    scanf("%d", &id);

    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    User user;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == id) {
            found = 1;
            printf("Enter new Name: ");
            scanf(" %[^\n]", user.name);
            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }
        fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("User updated successfully!\n");
    } else {
        printf("User ID not found.\n");
    }
}

void deleteUser() {
    int id, found = 0;
    printf("Enter the User ID to delete: ");
    scanf("%d", &id);

    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    User user;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id != id) {
            fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("User deleted successfully!\n");
    } else {
        printf("User ID not found.\n");
    }
}