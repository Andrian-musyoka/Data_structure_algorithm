#include <iostream>
#include <iomanip>
#include <string>

const int MAX_STUDENTS = 40;

// Define Course struct
struct Course {
    std::string course_code;
    std::string course_name;
};

// Define Grade struct
struct Grade {
    int mark;
    char the_grade;
};

// Define Student struct
struct Student {
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grades;
    bool grades_calculated; // Flag to indicate if grades have been calculated
};

// Function to calculate grade based on marks
char calculateGrade(int mark) {
    if (mark > 69) return 'A';
    else if (mark > 59) return 'B';
    else if (mark > 49) return 'C';
    else if (mark > 39) return 'D';
    else return 'E';
}

// Function to add a student
void addStudent(Student students[], int& numStudents) {
    if (numStudents < MAX_STUDENTS) {
        Student newStudent;

        // Input details for the new student
        std::cout << "Enter registration number: ";
        std::cin >> newStudent.registration_number;

        std::cout << "Enter name: ";
        std::cin.ignore(); // Ignore newline character
        std::getline(std::cin, newStudent.name);

        std::cout << "Enter age: ";
        std::cin >> newStudent.age;

        std::cout << "Enter course code: ";
        std::cin >> newStudent.course.course_code;

        std::cout << "Enter course name: ";
        std::cin.ignore();
        std::getline(std::cin, newStudent.course.course_name);

        // Set grades_calculated flag to false initially
        newStudent.grades_calculated = false;

        // Add the new student to the array
        students[numStudents++] = newStudent;

        std::cout << "Student added successfully.\n";
    }
    else {
        std::cout << "Maximum number of students reached.\n";
    }
}

// Function to edit a student's details
void editStudent(Student students[], int numStudents) {
    std::string regNumber;
    std::cout << "Enter registration number of the student to edit: ";
    std::cin >> regNumber;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].registration_number == regNumber) {
            // Input new details for the student
            std::cout << "Enter new registration number: ";
            std::cin >> students[i].registration_number;

            std::cout << "Enter new name: ";
            std::cin.ignore();
            std::getline(std::cin, students[i].name);

            std::cout << "Enter new age: ";
            std::cin >> students[i].age;

            std::cout << "Enter new course code: ";
            std::cin >> students[i].course.course_code;

            std::cout << "Enter new course name: ";
            std::cin.ignore();
            std::getline(std::cin, students[i].course.course_name);

            std::cout << "Student details edited successfully.\n";
            return;
        }
    }

    std::cout << "Student with registration number " << regNumber << " not found.\n";
}

// Function to add marks and calculate grades for a student
void addMarksAndCalculateGrades(Student& student) {
    if (!student.grades_calculated) {
        std::cout << "Enter marks for " << student.name << ": ";
        std::cin >> student.grades.mark;

        // Calculate grade based on marks
        student.grades.the_grade = calculateGrade(student.grades.mark);

        // Set grades_calculated flag to true
        student.grades_calculated = true;

        std::cout << "Marks and grades added successfully.\n";
    }
    else {
        std::cout << "Grades for " << student.name << " have already been calculated and cannot be altered.\n";
    }
}

// Function to display student details
void displayStudentDetails(const Student& student) {
    std::cout << "Registration Number: " << student.registration_number << "\n";
    std::cout << "Name: " << student.name << "\n";
    std::cout << "Age: " << student.age << "\n";
    std::cout << "Course Code: " << student.course.course_code << "\n";
    std::cout << "Course Name: " << student.course.course_name << "\n";

    if (student.grades_calculated) {
        std::cout << "Marks: " << student.grades.mark << "\n";
        std::cout << "Grade: " << student.grades.the_grade << "\n";
    }
    else {
        std::cout << "Marks and grades have not been calculated yet.\n";
    }

    std::cout << "------------------------\n";
}

// Function to display all students
void displayAllStudents(const Student students[], int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        displayStudentDetails(students[i]);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    int choice;
    do {
        std::cout << "1. Add a student\n";
        std::cout << "2. Edit a student's details\n";
        std::cout << "3. Add marks and calculate grades for a student\n";
        std::cout << "4. Display all students\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, numStudents);
                break;
            case 2:
                editStudent(students, numStudents);
                break;
            case 3:
                int studentIndex;
                std::cout << "Enter the index of the student: ";
                std::cin >> studentIndex;

                if (studentIndex >= 0 && studentIndex < numStudents) {
                    addMarksAndCalculateGrades(students[studentIndex]);
                }
                else {
                    std::cout << "Invalid index.\n";
                }
                break;
            case 4:
                displayAllStudents(students, numStudents);
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
