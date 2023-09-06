#include <iostream>
#include <vector>
#include <string>

struct Student {
	std::string name;
	int age;
	std::string major;
	double averageScore;
	double gpa;
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

//Фукция для подсчета суммы всех средних баллов студентов
double averageScoreSum(const std::vector<Student>& database) {
	double sum = 0;

	for (const Student& student : database) {
		sum += student.averageScore;
	}
	return sum;
}

