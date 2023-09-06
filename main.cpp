#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;

    Student() { }

    Student(std::string data[4]) {
        name = data[0];
        age = std::stoi(data[1]);
        major = data[2];
        gpa = std::stoi(data[3]);
    }
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

void readDataFromCSVFile(std::vector<Student>& database) {
    std::cout << "Введите название файла: ";
    std::string filename;
    std::cin >> filename;


    char delimiter = ',';
    std::string line;



    std::ifstream file(filename);

    if (file.fail()) {
        throw "File doesn't exists";
        return;
    }

    int num_str = 0;

    while (std::getline(file, line)) {
        num_str++;
        bool correct_input = true;

        std::stringstream stream(line);

        std::string student_data[4];
        std::getline(stream, student_data[0], delimiter);
        std::getline(stream, student_data[1], delimiter);
        std::getline(stream, student_data[2], delimiter);
        std::getline(stream, student_data[3], delimiter);

        for (auto str : student_data) {
            if (str.empty()) {
                std::cout << "Value can't be null in " + std::to_string(num_str) + " row\n";
                correct_input = false;
                break;
            }
        }

        if (!correct_input)
            continue;

        Student student(student_data);
        database.push_back(student);
    }

    file.close();
}

void getDatabaseCSVFile(const std::vector<Student>& database) {
    std::cout << "Выгрузка началась...\n";

    std::ofstream file("Выгрузка.csv");
    for (Student student : database) {
        file << student.name << ','
            << student.age << ','
            << student.major << ','
            << student.gpa << std::endl;
    }

    file.close();
    std::cout << "Выгрузка завершена\n";
}

void testForAddingStudent() {
    std::vector<Student> database;

    try
    {
        addStudent(database);
    }
    catch (const std::exception&)
    {
        std::cout << "Test for adding failed\n";
    }

    std::cout << "Test for adding passed\n";
}

void testForOutputFile() {
    std::vector<Student> database;
    std::string test[4]{ "Test", "40", "Test", "100" };
    database.push_back(Student(test));

    try
    {
        getDatabaseCSVFile(database);
        std::ifstream file("Выгрузка.csv");
        if (file.fail())
            throw "Incorrect work";
    }
    catch (const std::exception&)
    {
        std::cout << "Test for get db file failed\n";
    }

    std::cout << "Test for get db file passed\n";
}

void testForReadingFilesCorrect() {
    std::vector<Student> database;

    try
    {
        readDataFromCSVFile(database);
        if (database.size() != 4)
            throw "Incorrect work";
    }
    catch (const std::exception&)
    {
        std::cout << "Test for reading 1 failed\n";
    }

    std::cout << "Test for reading 1 passed\n";
}

void testForReadingFilesIncorrect() {
    std::vector<Student> database;

    try
    {
        readDataFromCSVFile(database);
        if (database.size() != 4)
            throw "Incorrect work";
    }
    catch (const std::exception&)
    {
        std::cout << "Test for reading 1 failed\n";
    }

    std::cout << "Test for reading 1 passed\n";
}

void testForInCorrectFileData() {
    std::vector<Student> database;

    try
    {
        readDataFromCSVFile(database);
        if (database.size() != 3)
            throw "Incorrect work";
    }
    catch (const std::exception&)
    {
        std::cout << "Test for reading 2 failed\n";
    }

    std::cout << "Test for reading 2 passed\n";
}

void testsForApp() {
    testForAddingStudent();
    testForOutputFile();
    testForReadingFilesCorrect();
    testForReadingFilesIncorrect();
    testForInCorrectFileData();
}

int main() {
    setlocale(LC_ALL, "RU");

    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Загрузить студентов из файла\n";
        std::cout << "4. Выгрузить данные в файл\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addStudent(database);
            break;
        case 2:
            displayStudents(database);
            break;
        case 3:
            readDataFromCSVFile(database);
            break;
        case 4:
            getDatabaseCSVFile(database);
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
