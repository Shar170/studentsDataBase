#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    string major;
    double gpa;
};

void deleteStudent(vector<Student>& database, string name)
{
    if (database.empty()) { cout << "The database is empty, the search for students is impossible!" << endl; return; };

    int count = 0;

    for (int i = 0; i < database.size(); i++)
    {
        if (database[i].name == name)
        {
            database.erase(database.begin() + i);
            count++;
            i--;
        }
    }

    if (count == 0)
    {
        cout << "No matches found!" << endl;
    }
}

// Функция для добавления студента в базу данных
void addStudent(vector<Student>& database) {
    Student student;
    cout << "Введите имя студента: ";
    cin >> student.name;
    cout << "Введите возраст студента: ";
    cin >> student.age;
    cout << "Введите специальность студента: ";
    cin >> student.major;
    cout << "Введите средний балл студента: ";
    cin >> student.gpa;

    database.push_back(student);

    cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const vector<Student>& database) {
    cout << "Список студентов:\n";
    for (const Student& student : database) {
        cout << "Имя: " << student.name << "\n";
        cout << "Возраст: " << student.age << "\n";
        cout << "Специальность: " << student.major << "\n";
        cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

int main() {

    setlocale(LC_ALL, "ru");

    vector<Student> database;

    int choice;
    do {
        cout << "Меню:\n";
        cout << "1. Добавить студента\n";
        cout << "2. Вывести список студентов\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(database);
            break;
        case 2:
            displayStudents(database);
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    displayStudents(database);

    return 0;
}