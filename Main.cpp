﻿#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "DataBase.h"

int main() {
    setlocale(LC_ALL, "Ru");
    std::vector<Student> database;

    int choice;
    double averageAge; // Переменная объявлена здесь, вне switch

    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Вывести средний возраст студентов\n";
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
            averageAge = averageAgeStudents(database); // Используем переменную внутри switch
            if (averageAge == 0.0) {
                std::cout << "База данных пуста.\n";
            }
            else {
                std::cout << "Средний возраст студентов: " << averageAge << " лет\n";
            }
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
