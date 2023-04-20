/*Programming Projects
1. Write a grading program for a class with the following grading policies:
a. There are two quizzes, each graded on the basis of 10 points.
b. There is one midterm exam and one final exam, each graded on the basis of
100 points.
c. The final exam counts for 50% of the grade, the midterm counts for 25%, and
the two quizzes together count for a total of 25%. (Do not forget to normalize
the quiz scores. They should be converted to a percentage before they are averaged
in.)
Any grade of 90 or more is an A, any grade of 80 or more (but less than 90) is a
B, any grade of 70 or more (but less than 80) is a C, any grade of 60 or more (but
less than 70) is a D, and any grade below 60 is an F. The program will read in the
student’s scores and output the student’s record, which consists of two quiz and
two exam scores as well as the student’s average numeric score for the entire course
and final letter grade. Define and use a structure for the student record.*/
#include <iostream>
using namespace std;
int const studentNumber = 3;
struct StudentNote
{
    double q1[studentNumber],q2[studentNumber];
    double midterm[studentNumber];
    double final[studentNumber];
};
void input(StudentNote& sn);
double* calculateAvarage(StudentNote& sn,double* avrg);
void output(StudentNote& sn,double* studentAvarage);


int main(){
    StudentNote snote;
    cout << "Please enter all students notes." << endl;
    input(snote);
    double studentAvarage[studentNumber];
    calculateAvarage(snote,studentAvarage);
    output(snote,studentAvarage);
}
void input(StudentNote& sn){
    for(int i=0;i<studentNumber; i++){
        cout << "q1: ";
        cin >> sn.q1[i];
        cout << "q2: ";
        cin >> sn.q2[i];
        cout << "midterm: ";
        cin >> sn.midterm[i];
        cout << "final: ";
        cin >> sn.final[i];
    }
    
}
double* calculateAvarage(StudentNote& sn,double* avrg){
    for(int i=0;i<studentNumber; i++){
        avrg[i]+=(sn.q1[i]+sn.q2[i]/2)*10*25/100+sn.midterm[i]*25/100+sn.final[i]*50/100;
    }
    return avrg;
}
void output(StudentNote& sn,double* avrg){
    char note[studentNumber];
    for(int i=0;i<studentNumber; i++){
        cout << i+1 <<". Student avarage: " << avrg[i];
        if(avrg[i] >=90)
            note[i]='A';
        else if(avrg[i]>=80 && avrg[i] <90)
            note[i]='B';
        else if(avrg[i]>=70 && avrg[i] <80)
            note[i]='C';
        else if(avrg[i]>=60 && avrg[i] <70)
            note[i]='D';
        else 
            note[i]='F';
        cout << " Student note: " << note[i] << endl;
    }
}