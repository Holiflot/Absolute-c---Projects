/*One way to measure the amount of energy that is expended during exercise is to
use metabolic equivalents (MET). Here are some METS for various activities:
Running 6 MPH: 10 METS
Basketball: 8 METS
Sleeping: 1 MET
The number of calories burned per minute may be estimated using the formula
Calories/Minute = 0.0175 : 1 MET : (Weight in kilograms)
Write a program that inputs a subject’s weight in pounds, the number of METS for
an activity, and the number of minutes spent on that activity, and then outputs an
estimate for the total number of calories burned. One kilogram is equal to 2.2 pounds.*/
#include <iostream>
using namespace std;



int main() {
    int exercises,score,possible_score;
    double percentage;
    cout << "How many exercises to input?" << endl;
    cin >> exercises;
    double totalScore=0.0,totalPs=0.0;
    for(int i=0;i<exercises;i++){
        cout << "Score received for exercise " << i+1 << ":" << endl;
        cin >> score;
        cout << "Total points possible for exercise" << i+1 << ":" << endl;
        cin >> possible_score;
        totalScore+=score;
        totalPs+=possible_score;
    }
    percentage = totalScore/totalPs*100;
    cout << "Your total is" << totalScore << " out of " << totalPs <<", or %" << percentage << "." << endl;
    return 0;
}