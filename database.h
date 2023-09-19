#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <cassert>
#include <sstream>
#include <string>
using std::istringstream;
using std::string;
using std::cout;

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};
// Commit 2
// Added a function to add a student to the database
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Enter the student's name: ";
    std::cin >> student.name;
    std::cout << "Enter the student's age: ";
    std::cin >> student.age;
    std::cout << "Enter the student's major: ";
    std::cin >> student.major;
    std::cout << "Enter the student's GPA: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Student added to the database.\n";
}

// Commit 3
// Added a function to display all students from the database
void displayStudents(const std::vector<Student>& database) {
    std::cout << "List of students:\n";
    for (const Student& student : database) {
        std::cout << "Name: " << student.name << "\n";
        std::cout << "Age: " << student.age << "\n";
        std::cout << "Major: " << student.major << "\n";
        std::cout << "GPA: " << student.gpa << "\n\n";
    }
}

// Commit 4
// Added a function to create a report and save it to a file
void createReport(const std::vector<Student>& database) {
    std::ofstream outFile("student_report.txt"); // Open the file for writing

    if (outFile.is_open()) {
        outFile << "Student Report:\n";
        for (const Student& student : database) {
            outFile << "Name: " << student.name << "\n";
            outFile << "Age: " << student.age << "\n";
            outFile << "Major: " << student.major << "\n";
            outFile << "GPA: " << student.gpa << "\n\n";
        }
        outFile.close(); // Close the file
        std::cout << "Report saved to the file student_report.txt\n";
    }
    else {
        std::cerr << "Error opening the file for writing.\n";
    }
}
// Commit 5
// Updated the main function with a new menu option to create and save a report
int main() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add a student\n";
        std::cout << "2. Display the list of students\n";
        std::cout << "3. Create and save a report\n"; // New option
        std::cout << "0. Exit\n";
        std::cout << "Select an action: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addStudent(database);
            break;
        case 2:
            displayStudents(database);
            break;
        case 3:
            createReport(database); // Call the function to create a report
            break;
        case 0:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
