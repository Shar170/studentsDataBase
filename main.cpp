// Added comments to the code for clarity
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Определение макроса для проверки равенства
#define ASSERT_EQUAL(actual, expected) \
    do { \
        if ((actual) != (expected)) { \
            std::cerr << "Assertion failed: " << #actual << " != " << #expected << "\n"; \
        } \
    } while (false)

// Определение макроса для проверки истинности выражения
#define ASSERT_TRUE(expr) \
    do { \
        if (!(expr)) { \
            std::cerr << "Assertion failed: " << #expr << " is false\n"; \
        } \
    } while (false)

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

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
void testAddStudent() {
    std::vector<Student> database;
    Student student;
    student.name = "John";
    student.age = 20;
    student.major = "Computer Science";
    student.gpa = 3.5;

    addStudent(database);

    // Проверяем, что база данных содержит только одного студента
    ASSERT_EQUAL(database.size(), 1);
    // Проверяем, что добавленный студент имеет ожидаемые значения
    ASSERT_EQUAL(database[0].name, "John");
    ASSERT_EQUAL(database[0].age, 20);
    ASSERT_EQUAL(database[0].major, "Computer Science");
    ASSERT_EQUAL(database[0].gpa, 3.5);
}

void testDisplayStudents() {
    std::vector<Student> database;
    Student student1, student2;
    student1.name = "Alice";
    student1.age = 22;
    student1.major = "Mathematics";
    student1.gpa = 3.8;

    student2.name = "Bob";
    student2.age = 21;
    student2.major = "Physics";
    student2.gpa = 3.7;

    database.push_back(student1);
    database.push_back(student2);

    // Создаем временный буфер для захвата вывода
    std::stringstream output_buffer;
    // Перенаправляем вывод в буфер
    std::streambuf* old_cout = std::cout.rdbuf(output_buffer.rdbuf());

    displayStudents(database);

    // Восстанавливаем вывод
    std::cout.rdbuf(old_cout);

    // Проверяем, что вывод содержит информацию о двух студентах
    std::string output = output_buffer.str();
    ASSERT_TRUE(output.find("Name: Alice") != std::string::npos);
    ASSERT_TRUE(output.find("Name: Bob") != std::string::npos);
}
void testCreateReport() {
    std::vector<Student> database;
    Student student1, student2;
    student1.name = "Eve";
    student1.age = 23;
    student1.major = "Chemistry";
    student1.gpa = 3.9;

    student2.name = "Charlie";
    student2.age = 24;
    student2.major = "Biology";
    student2.gpa = 3.6;

    database.push_back(student1);
    database.push_back(student2);

    createReport(database);

    // Проверяем, что файл student_report.txt был создан
    std::ifstream reportFile("student_report.txt");
    ASSERT_TRUE(reportFile.is_open());
    reportFile.close();

    // TODO: Дополнительная проверка содержания файла можно добавить здесь
}
void testMainMenu() {
    // Создаем буфер для захвата пользовательского ввода
    std::stringstream input_buffer;
    // Перенаправляем ввод из буфера
    std::streambuf* old_cin = std::cin.rdbuf(input_buffer.rdbuf());

    // Вводим последовательность действий: добавление студента и выход
    input_buffer << "1\nJohn\n20\nComputer Science\n3.5\n0\n";

    // Создаем временный буфер для захвата вывода
    std::stringstream output_buffer;
    // Перенаправляем вывод в буфер
    std::streambuf* old_cout = std::cout.rdbuf(output_buffer.rdbuf());

    // Запускаем главное меню
    int main();

    // Восстанавливаем ввод и вывод
    std::cin.rdbuf(old_cin);
    std::cout.rdbuf(old_cout);

    // Проверяем, что база данных содержит одного студента и выводит сообщение о выходе
    std::string output = output_buffer.str();
    ASSERT_TRUE(output.find("Student added to the database.") != std::string::npos);
    ASSERT_TRUE(output.find("Exiting the program.") != std::string::npos);
}
void testInvalidChoice() {
    // Создаем буфер для захвата пользовательского ввода
    std::stringstream input_buffer;
    // Перенаправляем ввод из буфера
    std::streambuf* old_cin = std::cin.rdbuf(input_buffer.rdbuf());

    // Вводим некорректный выбор: 5
    input_buffer << "5\n0\n";

    // Создаем временный буфер для захвата вывода
    std::stringstream output_buffer;
    // Перенаправляем вывод в буфер
    std::streambuf* old_cout = std::cout.rdbuf(output_buffer.rdbuf());

    // Запускаем главное меню
    int main();

    // Восстанавливаем ввод и вывод
    std::cin.rdbuf(old_cin);
    std::cout.rdbuf(old_cout);

    // Проверяем, что выводит сообщение о некорректном выборе
    std::string output = output_buffer.str();
    ASSERT_TRUE(output.find("Invalid choice. Please try again.") != std::string::npos);
}

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
