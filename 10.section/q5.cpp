/*This programming project is based on Programming Projects 7.8 and 5.7. Write
a program that outputs a histogram of grades for an assignment given to a class of
students. The program should input each student’s grade as an integer and store
the grade in a vector. Grades should be entered until the user enters -1 for a grade.
The program should then scan through the vector and compute the histogram. In
computing the histogram, the minimum value of a grade is 0, but your program
should determine the maximum value entered by the user. Use a dynamic array to
store the histogram. Output the histogram to the console.*/

#include <iostream>
using namespace std;


class Student {
private:
    string name;
    int numClasses;
    string* classList;

public:
    Student() {
        name = "";
        numClasses = 0;
        classList = nullptr;
    }

    ~Student() {
        delete[] classList;
    }

    void InputData() {
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter number of classes: ";
        cin >> numClasses;
        cin.ignore();
        classList = new string[numClasses];
        for (int i = 0; i < numClasses; i++) {
            cout << "Enter name of class " << i + 1 << ": ";
            getline(cin, classList[i]);
        }
    }

    void OutputData() {
        cout << "Student Name: " << name << endl;
        cout << "Number of Classes: " << numClasses << endl;
        cout << "Class List: ";
        for (int i = 0; i < numClasses; i++) {
            cout << classList[i];
            if (i != numClasses - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    void ResetClasses() {
        numClasses = 0;
        delete[] classList;
        classList = nullptr;
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            name = other.name;
            numClasses = other.numClasses;
            delete[] classList;
            classList = new string[numClasses];
            for (int i = 0; i < numClasses; i++) {
                classList[i] = other.classList[i];
            }
        }
        return *this;
    }
};
int main()
{
Student s1, s2;
s1.InputData(); // Input data for student 1
cout << "Student 1's data:" << endl;
s1.OutputData(); // Output data for student 1
cout << endl;
s2 = s1;
cout << "Student 2's data after assignment from student 1:" << endl;
s2.OutputData(); // Should output same data as for student 1
s1.ResetClasses();
cout << "Student 1's data after reset:" << endl;
s1.OutputData(); // Should have no classes
cout << "Student 2's data, should still have original classes:" << endl;
s2.OutputData(); // Should still have original classes
cout << endl;
return 0;
}
