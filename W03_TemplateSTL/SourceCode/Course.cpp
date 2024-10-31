#include "Course.h"

Course::Course() : courseId("Unknown"), courseName("Unknown"), studentList(std::vector<Student>()) {}

Course::Course(const std::string& courseId, const std::string& courseName, const std::vector<Student>& studentList) : courseId(courseId), courseName(courseName), studentList(studentList){}

void Course::enrollStudent(const std::vector<Student>& studentList)
{
    for (int i = 0; i < studentList.size(); i++)
        this->studentList.push_back(studentList[i]);
}

void Course::printStudentList()
{
    for (int i = 0; i < studentList.size(); i++)
        std::cout << studentList[i] << "\n";
}

void Course::enrollStudent(const Student& student)
{
    this->studentList.push_back(student);
}

void Course::unenrollStudent(const std::vector<std::string>& studentIdList)
{
    for (int i = 0; i < studentIdList.size(); i++)
    {
        for (int j = 0; j < studentList.size(); j++)
            if (studentList[j].getStudentID() == studentIdList[i])
                studentList.erase(studentList.begin() + j);
    }
}

void Course::unenrollStudent(const std::string& studentId)
{
    for (int j = 0; j < studentList.size(); j++)
        if (studentList[j].getStudentID() == studentId)
            studentList.erase(studentList.begin() + j);
}

bool Course::isStudentType(const std::string& studentType, const double& grade)
{
    if (studentType == "XUATSAC")
    {
        if (grade >= 9)
            return true;
        
        return false;
    }
    else if (studentType == "GIOI")
    {
        if (grade >= 8 && grade < 9)
            return true;
        return false;
    }    
    else if (studentType == "KHA")
    {
        if (grade >= 7 && grade < 8)
            return true;
        return false;
    }
    else if (studentType == "TRUNGBINH")
    {
        if (grade >= 5 && grade < 7)
            return true;
        return false;
    }

    if (grade < 5)
        return true;

    return false;
}

std::vector<Student> Course::getStudentList(const std::string& studentType)
{
    std::vector<Student> stList;
    
    for (int i = 0; i < studentList.size(); i++)
        if (isStudentType(studentType, studentList[i].getGrade()))
            stList.push_back(studentList[i]);
    
    return stList;
}

int Course::getPassedStudent()
{
    int numPassedStudents = 0;

    for (int i = 0; i < studentList.size(); i++)
        if (studentList[i].getGrade() >= 5)
            numPassedStudents++;

    return numPassedStudents;
}

void Course::sortStudentList(const std::string& sortBy, const bool& isIncreasing)
{
    if (sortBy == "NAME") 
    {
        std::sort(studentList.begin(), studentList.end(), [isIncreasing](Student a, Student b) 
        {
            if (isIncreasing) 
            {
                return a.getFullname() < b.getFullname();
            } 
            else 
            {
                return a.getFullname() > b.getFullname();
            }
        });
    } 
    else
    {
        std::sort(studentList.begin(), studentList.end(), [isIncreasing](Student a, Student b) 
        {
            if (isIncreasing) 
            {
                return a.getGrade() < b.getGrade();
            } 
            else 
            {
                return a.getGrade() > b.getGrade();
            }
        });
    }
}

void Course::saveCourse(const std::string& filePath)
{
    std::ofstream outFile(filePath);
    if (!outFile) {
        return;
    }

    outFile << courseId << "\n";
    outFile << courseName << "\n";

    outFile << studentList.size() << "\n";

    for (int i = 0; i < studentList.size(); i++) 
    {
        outFile << studentList[i].getStudentID() << "\n";
        outFile << studentList[i].getGrade() << "\n";
        outFile << studentList[i].getFullname() << "\n";
    }

    outFile.close();
}
void Course::readCourse(const std::string& filePath)
{
    std::ifstream inFile(filePath);
    if (!inFile) {
        return;
    }

    std::getline(inFile, courseId);
    std::getline(inFile, courseName);

    int studentCount;
    inFile >> studentCount;
    inFile.ignore(); 

    studentList.clear();

    for (int i = 0; i < studentCount; ++i) 
    {
        std::string studentId;
        double grade;
        std::string fullname;

        std::getline(inFile, studentId);
        inFile >> grade;
        inFile.ignore();  
        std::getline(inFile, fullname);

        Student student(studentId, grade, fullname);
        studentList.push_back(student);
    }

    inFile.close();
}