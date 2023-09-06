#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> groups = {"КС-40", "КС-43", "КС-46"};

struct Student {
    string name;
    int age;
    string major;
    double gpa;
	string group;
};

// Функция для добавления студента в базу данных
void addStudent(vector<Student>& database) {
    Student student;
	int group_number;
    cout << "Введите имя студента: ";
    cin >> student.name;
    cout << "Введите возраст студента: ";
    cin >> student.age;
    cout << "Введите специальность студента: ";
    cin >> student.major;
    cout << "Введите средний балл студента: ";
    cin >> student.gpa;
	cout << "Выберите группу студента: " << "\n";
	for (int i = 1; i <= groups.size(); i++)
		cout << i << ". " << groups[i - 1] << "\n";
	cin >> group_number; 
	while (group_number < 1 || group_number > groups.size()) {
		cout << "Введите правильный номер: ";
		cin >> group_number; 
	}
	student.group = groups[group_number - 1];
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
        cout << "Средний балл: " << student.gpa << "\n";
		cout << "Группа: " << student.group << "\n\n";
    }
}

int main() {
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

    return 0;
}
