#pragma once
#include "Student.h"
#include <vector>
#include <algorithm>
#include <fstream>

class Course
{
private:
    std::string courseId;
    std::string courseName;
    std::vector<Student> studentList;
    bool isStudentType(const std::string& studentType, const double& grade);
public:
    Course();
    Course(const std::string& courseId, const std::string& courseName, const std::vector<Student>& studentList = std::vector<Student>());
    void printStudentList();
    void enrollStudent(const std::vector<Student>& studentList);
    void enrollStudent(const Student& student);
    void unenrollStudent(const std::vector<std::string>& studentIdList);
    void unenrollStudent(const std::string& studentId);
    std::vector<Student> getStudentList(const std::string& studentType = "XUATSAC");
    int getPassedStudent();
    void sortStudentList(const std::string& sortBy = "NAME", const bool& isIncreasing = true);
    void saveCourse(const std::string& filePath);
    void readCourse(const std::string& filePath);
};