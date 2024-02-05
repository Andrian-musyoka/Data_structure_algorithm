#include <stdio.h>
#include <string.h>

// Grade struct
struct Grade {
    int mark;
    char the_grade;
};

// Course struct
struct Course {
    char course_code[10];
    char course_name[50];
};

// Student struct
struct Student {
    char reg_number[20];
    char name[50];
    int age;
    struct Course course;
    struct Grade grades;
    int grades_set;  // Flag to check if grades are set
};

// Student Database struct
struct StudentDatabase {
    struct Student students[40];
    int num_students;
};

// Function prototypes
void addStudent(struct StudentDatabase* database, const struct Student* student);
void editStudentDetails(struct StudentDatabase* database, const char* reg_number, int new_age);
void addMarksAndCalculateGrades(struct StudentDatabase* database, const char* reg_number, int mark);
void displayStudentDetails(const struct StudentDatabase* database);

int main() {
    // Initialize student database
    struct StudentDatabase studentDB;
    studentDB.num_students = 0;

    // Adding courses
    struct Course computerScience = {"CS101", "Computer Science"};

    // Adding students
    struct Student student1 = {"12345", "John Doe", 20, computerScience, {0, 'E'}, 0};
    struct Student student2 = {"67890", "Jane Smith", 21, computerScience, {0, 'E'}, 0};

    // Adding students to the database
    addStudent(&studentDB, &student1);
    addStudent(&studentDB, &student2);

    // Displaying initial details
    displayStudentDetails(&studentDB);

    // Editing a student's details
    editStudentDetails(&studentDB, "12345", 21);

    // Displaying details after editing
    displayStudentDetails(&studentDB);

    // Adding marks and calculating grades
    addMarksAndCalculateGrades(&studentDB, "12345", 75);
    addMarksAndCalculateGrades(&studentDB, "67890", 55);

    // Displaying details after adding marks
    displayStudentDetails(&studentDB);

    return 0;
}

// Function to add a student to the database
void addStudent(struct StudentDatabase* database, const struct Student* student) {
    if (database->num_students < 40) {
        database->students[database->num_students] = *student;
        database->num_students++;
    } else {
        printf("Cannot add more than 40 students.\n");
    }
}

// Function to edit a student's details
void editStudentDetails(struct StudentDatabase* database, const char* reg_number, int new_age) {
    for (int i = 0; i < database->num_students; ++i) {
        if (strcmp(database->students[i].reg_number, reg_number) == 0) {
            database->students[i].age = new_age;
            printf("Details edited successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

// Function to add marks and calculate grades
void addMarksAndCalculateGrades(struct StudentDatabase* database, const char* reg_number, int mark) {
    for (int i = 0; i < database->num_students; ++i) {
        if (strcmp(database->students[i].reg_number, reg_number) == 0) {
            if (!database->students[i].grades_set) {
                database->students[i].grades.mark = mark;

                // Calculate grade
                if (mark > 69)
                    database->students[i].grades.the_grade = 'A';
                else if (mark > 59)
                    database->students[i].grades.the_grade = 'B';
                else if (mark > 49)
                    database->students[i].grades.the_grade = 'C';
                else if (mark > 39)
                    database->students[i].grades.the_grade = 'D';
                else
                    database->students[i].grades.the_grade = 'E';

                database->students[i].grades_set = 1;  // Set the flag to indicate grades are set
                printf("Marks and grades added successfully.\n");
                return;
            } else {
                printf("Grades already set for this student.\n");
                return;
            }
        }
    }
    printf("Student not found.\n");
}

// Function to display student details
void displayStudentDetails(const struct StudentDatabase* database) {
    for (int i = 0; i < database->num_students; ++i) {
        printf("Registration Number: %s\n", database->students[i].reg_number);
        printf("Name: %s\n", database->students[i].name);
        printf("Age: %d\n", database->students[i].age);
        printf("Course Code: %s\n", database->students[i].course.course_code);
        printf("Course Name: %s\n", database->students[i].course.course_name);
        printf("Grade: %c\n", database->students[i].grades.the_grade);
        printf("-------------------------\n");
    }
}
