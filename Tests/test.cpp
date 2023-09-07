#include "pch.h"
#include "database.h"

//Test without students
TEST(ConsoleApplication2, averageScoreTestingNoStudents) {
	std::vector<Student> database;

	EXPECT_EQ(averageScoreSum(database), 0);
}

//Test with one student
TEST(ConsoleApplication2, averageScoreTestingOneStudent) {
	std::vector<Student> database;
	database.push_back({"", 5, "", 5 });

	EXPECT_EQ(averageScoreSum(database), 5);
}

//Test with int average numbers
TEST(ConsoleApplication2, averageScoreTestingInt) {
	std::vector<Student> database;
	database.push_back({ "", 5, "", 5 });
	database.push_back({ "", 5, "", 15 });
	database.push_back({ "", 5, "", 10 });

	EXPECT_EQ(averageScoreSum(database), 30);
}

//Test with double average numbers
TEST(ConsoleApplication2, averageScoreTestingDouble) {
	std::vector<Student> database;
	database.push_back({ "", 5, "", 5.3 });
	database.push_back({ "", 5, "", 15.8 });
	database.push_back({ "", 5, "", 10.33 });

	EXPECT_EQ(averageScoreSum(database), 31.43);
}

//Test with double average numbers 10 students
TEST(ConsoleApplication2, averageScoreTestingTenStudents) {
	std::vector<Student> database;
	Student student;
	database.push_back({ "", 5, "", 5.83 });
	database.push_back({ "", 5, "", 15.798 });
	database.push_back({ "", 5, "", 10.552 });
	database.push_back({ "", 5, "", 50.93 });
	database.push_back({ "", 5, "", 65.352 });
	database.push_back({ "", 5, "", 100 });
	database.push_back({ "", 5, "", 33.95 });
	database.push_back({ "", 5, "", 98.95 });
	database.push_back({ "", 5, "", 30.55 });
	database.push_back({ "", 5, "", 73.28 });

	EXPECT_EQ(averageScoreSum(database), 485.192);
}

//Test with double average numbers 20 students
TEST(ConsoleApplication2, averageScoreTestingStudent) {
	std::vector<Student> database;
	database.push_back({ "", 5, "", 5.83 });
	database.push_back({ "", 5, "", 15.798 });
	database.push_back({ "", 5, "", 10.552 });
	database.push_back({ "", 5, "", 50.93 });
	database.push_back({ "", 5, "", 65.352 });
	database.push_back({ "", 5, "", 100 });
	database.push_back({ "", 5, "", 33.95 });
	database.push_back({ "", 5, "", 98.95 });
	database.push_back({ "", 5, "", 30.55 });
	database.push_back({ "", 5, "", 73.28 });

	database.push_back({ "", 5, "", 95.96 });
	database.push_back({ "", 5, "", 73.21 });
	database.push_back({ "", 5, "", 87.85 });
	database.push_back({ "", 5, "", 65.987 });
	database.push_back({ "", 5, "", 33.54 });
	database.push_back({ "", 5, "", 100 });
	database.push_back({ "", 5, "", 90 });
	database.push_back({ "", 5, "", 74.75 });
	database.push_back({ "", 5, "", 98.58 });
	database.push_back({ "", 5, "", 58.36 });

	EXPECT_NEAR(averageScoreSum(database), 1263.429, 1e-3);
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}