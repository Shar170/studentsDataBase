#include "DataBase.h"

class Test {
	private:
		// Тест #1: Расчет среднего возраста для пустой базы данных
		void Test1() {
			std::vector<Student> database;
			std::cout << "Запуск теста 1: Расчет среднего возраста для пустой базы данных...\n";
			double averageAge1 = averageAgeStudents(database);
			if (averageAge1 == 0.0) {
				std::cout << "Тест 1 успешно пройден. Результат: " << averageAge1 << "\n\n";
			}
			else {
				std::cout << "Тест 1 не пройден. База данных имеет наполнение: " << averageAge1 << "\n\n";
			}
		};

		// Тест #2: Расчет среднего возраста для нескольких студентов
		void Test2() {
			std::vector<Student> database;
			std::cout << "Запуск теста 2: Расчет среднего возраста для нескольких студентов...\n";
			Student student1 = { "Иванов", 20, "Математика", 4.5 };
			Student student2 = { "Петров", 22, "Физика", 3.8 };
			Student student3 = { "Сидорова", 21, "Биология", 4.2 };
			database.push_back(student1);
			database.push_back(student2);
			database.push_back(student3);
			double averageAge2 = averageAgeStudents(database);
			double expectedAverage2 = (20.0 + 22.0 + 21.0) / 3;
			if (averageAge2 == expectedAverage2) {
				std::cout << "Тест 2 успешно пройден. Результат: " << averageAge2 << "\n\n";
			}
			else {
				std::cout << "Тест 2 не пройден. Ожидалось значение " << expectedAverage2 << ", но получено: " << averageAge2 << "\n\n";
			}

		};

		// Тест #3: Тестировании работы функции добавления студента
		void Test3() {
			std::vector<Student> database;
			std::cout << "Запуск теста 3: Добавление студента...\n";
			size_t initialSize = database.size();
			addStudent(database);
			if (database.size() == initialSize + 1) {
				std::cout << "Тест 3 успешно пройден. Размер базы данных увеличен.\n\n";
			}
			else {
				std::cout << "Тест 3 не пройден. Ожидалось увеличение размера базы данных.\n\n";
			}

		};

		// Тест #4: Попытка вывести базу данных
		void Test4() {
			std::vector<Student> database;
			std::cout << "Запуск теста 4: Вывод списка студентов...\n";
			// Здесь тест осуществляется путем визуальной проверки вывода, так что нет assert
			displayStudents(database);
		};

		// Тест #5: Попытка добавить студента с отрицательной успеваемостью
		void Test5() {
			std::vector<Student> database;
			size_t initialSize = database.size();
			std::cout << "Запуск теста 6: Попытка добавления студента с отрицательным возрастом...\n";
			Student student4 = { "Иванова", 15, "История", -3.0 };
			database.push_back(student4);
			if (database.size() == initialSize) {
				std::cout << "Тест 6 успешно пройден. Студент с отрицательной успеваемостью не добавлен.\n\n";
			}
			else {
				std::cout << "Тест 6 не пройден. Ожидалось, что студент с отрицательной успеваемостью не будет добавлен.\n\n";
			}
		};

		// Тест 6: Попытка добавления студента с отрицательным возрастом
		void Test6() {
			std::vector<Student> database;
			size_t initialSize = database.size();
			std::cout << "Запуск теста 6: Попытка добавления студента с отрицательным возрастом...\n";
			Student student4 = { "Иванова", -1, "История", 3.0 };
			database.push_back(student4);
			if (database.size() == initialSize) {
				std::cout << "Тест 6 успешно пройден. Студент с отрицательным возрастом не добавлен.\n\n";
			}
			else {
				std::cout << "Тест 6 не пройден. Ожидалось, что студент с отрицательным возрастом не будет добавлен.\n\n";
			}
		}
	public:
		// Тестовая функция для запуска всех имеющихся тестов программы
		void runAllTest() { Test1(); Test2(); Test3(); Test4(); Test5(); Test6(); };
};

int main() {
	Test test;
	test.runAllTest();
	return 0;
}
