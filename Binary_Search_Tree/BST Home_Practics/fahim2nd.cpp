#include <bits/stdc++.h>
using namespace std;

struct DateOfBirth {
    int day;
    int month;
    int year;
};

class Student {
private:
    string name;
    int rollNumber;
    int age;
    char gender;
    double grades[5]; // Assuming 5 subjects

public:
    void inputStudentInfo() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender (M/F/O): ";
        cin >> gender;

        cout << "Enter Date of Birth (Day Month Year): ";
        cin >> dob.day >> dob.month >> dob.year;

        cout << "Enter Grades for 5 subjects: ";
        for (int i = 0; i < 5; ++i) {
            cin >> grades[i];
        }
    }

    void displayStudentInfo() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Date of Birth: " << dob.day << "/" << dob.month << "/" << dob.year << endl;
        cout << "Grades: ";
        for (int i = 0; i < 5; ++i) {
            cout << grades[i] << " ";
        }
        cout << endl;
    }

    void displayAge() const {
        // Calculate age based on current year
        int currentYear = 2023; // Update with current year
        int studentAge = currentYear - dob.year;
        cout << "Age: " << studentAge << " years" << endl;
    }

    double calculateGPA() const {
        double total = 0.0;
        for (int i = 0; i < 5; ++i) {
            total += grades[i];
        }
        return total / 5.0;
    }

    bool isLegalAge() const {
        return age >= 18;
    }

    string getGenderCategory() const {
        if (gender == 'M') return "Male";
        if (gender == 'F') return "Female";
        return "Other";
    }

    static bool compareByName(const Student& s1, const Student& s2) {
        return s1.name < s2.name;
    }

    static bool compareByRollNumber(const Student& s1, const Student& s2) {
        return s1.rollNumber < s2.rollNumber;
    }

    bool operator==(int roll) const {
        return rollNumber == roll;
    }

private:
    DateOfBirth dob;
};

int main() {
    vector<Student> students;

    // Input student information
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        Student student;
        cout << "Enter details for Student " << i + 1 << endl;
        student.inputStudentInfo();
        students.push_back(student);
        cout << endl;
    }

    // Display student details
    cout << "Student Details:\n";
    for (const Student& student : students) {
        student.displayStudentInfo();
        student.displayAge();
        cout << "GPA: " << student.calculateGPA() << endl;
        cout << "Legal Age: " << (student.isLegalAge() ? "Yes" : "No") << endl;
        cout << "Gender: " << student.getGenderCategory() << endl;
        cout << endl;
    }

    // Sorting students by name
    sort(students.begin(), students.end(), Student::compareByName);

    // Search roll number
    int searchRoll;
    cout << "Enter a roll number to search for: ";
    cin >> searchRoll;

    auto it = find(students.begin(), students.end(), searchRoll);
    if (it != students.end()) {
        cout << "Student found:\n";
        it->displayStudentInfo();
    } else {
        cout << "Student with roll number " << searchRoll << " not found.\n";
    }

    return 0;
}
