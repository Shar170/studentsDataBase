#include <iostream>
#include "database.h"

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
        case 3: {
            std::cout << "Введите название файла: ";
            std::string filename;
            std::cin >> filename;
            
            readDataFromCSVFile(database, filename);
        }
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
