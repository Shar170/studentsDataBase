#include "gtest/gtest.h"
#include "database.h"

//���� �� �������� ����� ��������
TEST(CorrectOutput, TestForCreatingOputputFile) {
    remove("��������.csv");

    std::vector<Student> database;
    std::string test[4]{ "Test", "40", "Test", "100" };
    database.push_back(Student(test));
    getDatabaseCSVFile(database);

    std::ifstream file("��������.csv");
    EXPECT_EQ(file.fail(), false);

    remove("��������.csv");
}

//��� �� ������������ ����� ��������
TEST(CorrectOutput, TestForCorrectOutputFile) {
    std::vector<Student> database;
    std::string test[4]{ "Test", "40", "Test", "100" };
    database.push_back(Student(test));
    getDatabaseCSVFile(database);

    database.pop_back();
    readDataFromCSVFile(database, "��������.csv");

    EXPECT_EQ(database.front().name, test[0]);
    EXPECT_EQ(database.front().age, std::stoi(test[1]));
    EXPECT_EQ(database.front().major, test[2]);
    EXPECT_EQ(database.front().gpa, std::stoi(test[3]));
}

//���� �� ������ ��������� ������������ �����
TEST(CorrectInputFile, TestForCorrectInputFile) {
    std::vector<Student> database;
    readDataFromCSVFile(database, "test1.csv");
    EXPECT_EQ(database.size(), 4);
}

//���� �� ������ ����������� ������������ �����
TEST(IncorrectInputFile, TestForIncorrectInputFile) {
    std::vector<Student> database;
    readDataFromCSVFile(database, "test2.csv");
    EXPECT_EQ(database.size(), 3);
}

//���� �� ������ ��������������� �����
TEST(FileDoesntExists, TestForNoFileAdd) {
    testing::internal::CaptureStdout();

    std::vector<Student> database;
    readDataFromCSVFile(database, "NOSUCHFILE.csv");

    std::string actual_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("File doesn't exists\n", actual_output);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}