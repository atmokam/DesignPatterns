#include <iostream>
#include <string>
#include <memory>

class Subject {
public:
    void setSubjectName(const std::string& subjectName)
    {
        this->subjectName = subjectName;
    }

    void setNumberOfStudents(int numberOfStudents)
    {
        this->numberOfStudents = numberOfStudents;
    }

    void setProfessorName(const std::string& professorName)
    {
        this->professorName = professorName;
    }

    void printInfo() const
    {
        std::cout << "Subject: " << subjectName << std::endl;
        std::cout << "Professor: " << professorName << std::endl;
        std::cout << "Number of students: " << numberOfStudents << std::endl;
    }

private:
    std::string subjectName;
    std::string professorName;
    int numberOfStudents;
};

class SubjectBuilder {
private:
    std::unique_ptr<Subject> subject;
public:
    SubjectBuilder() : subject(std::make_unique<Subject>()) {}

    void setSubjectName(const std::string& subjectName)
    {
        subject->setSubjectName(subjectName);
    }

    void setProfessorName(const std::string& professorName)
    {
        subject->setProfessorName(professorName);
    }

    void setNumberOfStudents(int numberOfStudents)
    {
        subject->setNumberOfStudents(numberOfStudents);
    }

    std::unique_ptr<Subject> build() const
    {
        return std::make_unique<Subject>(subject); 
    }

};

int main()
{
    SubjectBuilder builder;

    builder.setSubjectName("Quantum Mechanics");
    builder.setProfessorName("Prof. John Doe");
    builder.setNumberOfStudents(27);

    std::unique_ptr<Subject> subject = builder.build();
    subject->printInfo();

    return 0;
}