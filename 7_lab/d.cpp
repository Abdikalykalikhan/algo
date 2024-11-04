#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

double getGPA(string mark) {
    if (mark == "A+") return 4.00;
    if (mark == "A") return 3.75;
    if (mark == "B+") return 3.50;
    if (mark == "B") return 3.00;
    if (mark == "C+") return 2.50;
    if (mark == "C") return 2.00;
    if (mark == "D+") return 1.50;
    if (mark == "D") return 1.00;
    
    
    return 0.00;
}

struct Student {
    string lastname;
    string firstname;
    double totalGPA;

    Student(string ln, string fn, double gpa) : lastname(ln), firstname(fn), totalGPA(gpa) {}
};

bool compareStudents(const Student &a, const Student &b) {
    if (a.totalGPA != b.totalGPA) 
        return a.totalGPA < b.totalGPA;
    if (a.lastname != b.lastname)
        return a.lastname < b.lastname; 
    return a.firstname < b.firstname;   
}

int main() {
    int n;
    cin >> n;

    vector<Student> students;

    for (int i = 0; i < n; ++i) {
        string lastname, firstname;
        int numSubjects;
        cin >> lastname >> firstname >> numSubjects;

        double totalWeightedGPA = 0;
        int totalCredits = 0;

        for (int j = 0; j < numSubjects; ++j) {
            int  credits;
            string mark;
            cin >> mark >> credits;
            double gpa = getGPA(mark);
            totalWeightedGPA += gpa * credits;
            totalCredits += credits;
        }

        double overallGPA = totalWeightedGPA / totalCredits;

        students.push_back(Student(lastname, firstname, overallGPA));
    }

    sort(students.begin(), students.end(), compareStudents);

    for (const auto &student : students) {
        cout << student.lastname << " " << student.firstname << " ";
        cout << fixed << setprecision(3) << student.totalGPA << endl;
    }

    return 0;
}