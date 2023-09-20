#include "database.h"

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
