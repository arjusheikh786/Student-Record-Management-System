#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    char department[50];
    int passingYear;
    float cgpa;
};

struct Student students[100];
int count = 0;


// --------------CRUD (Create, Read, Update, Delete)---------- //

void addStudent() {
    printf("Enter Roll: ");
    scanf("%d", &students[count].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter Department: ");
    scanf(" %[^\n]", students[count].department);
    printf("Enter Passing Year: ");
    scanf("%d", &students[count].passingYear);
    printf("Enter CGPA: ");
    scanf("%f", &students[count].cgpa);

    count++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    printf("\n--- Student List ---\n");
    if (count == 0) {
        printf("No students found.\n");
        return;
    }
    printf("Roll   | Name            | Dept          | Year | CGPA\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d | %-15s | %-12s | %-4d | %.2f\n",
               students[i].roll,
               students[i].name,
               students[i].department,
               students[i].passingYear,
               students[i].cgpa);
    }
    printf("---------------------------------------------------------\nTotal: %d\n", count);
}

void searchStudent() {
    int roll;
    printf("Enter Roll to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("\nFound Student:\n");
            printf("Roll: %d\nName: %s\nDepartment: %s\nPassing Year: %d\nCGPA: %.2f\n",
                   students[i].roll,
                   students[i].name,
                   students[i].department,
                   students[i].passingYear,
                   students[i].cgpa);
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent() {
    int roll;
    printf("Enter Roll to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}



// ---------- LOG IN ---------- //

int login() {
    char user[20], pass[20];
    const char username[] = "admin";
    const char password[] = "1234";

    printf("===== Student Record Management Login =====\n");

    for (int i = 1; i <= 3; i++) {
        printf("\nLogin Attempt %d/3\n", i);
        printf("Enter Username: ");
        scanf("%s", user);
        printf("Enter Password: ");
        scanf("%s", pass);

        if (strcmp(user, username) == 0 && strcmp(pass, password) == 0) {
            printf("\nLogin Successful!\n");
            return 1;
        } else {
            printf("Wrong username or password.\n");
        }
    }
    return 0;
}


// ---------- MAIN ---------- //

int main() {
    if (!login()) {
        printf("\nAccess Denied. Exiting...\n");
        return 0;
    }

    int choice;
    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Delete Student\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
