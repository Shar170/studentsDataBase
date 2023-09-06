#include <iostream>
#include <vector>
#include <string>

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
    std::cout << std::endl;


    char delimiter = ',';
    std::string line;



    std::ifstream file(filename);

    while (std::getline(file, line)) {
        std::stringstream stream(line);

        std::string student_data[4];
        std::getline(stream, student_data[0], delimiter);
        std::getline(stream, student_data[1], delimiter);
        std::getline(stream, student_data[2], delimiter);
        std::getline(stream, student_data[3], delimiter);

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
