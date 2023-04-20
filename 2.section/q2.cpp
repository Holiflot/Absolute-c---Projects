/*A government research lab has concluded that an artificial sweetener commonly
used in diet soda will cause death in laboratory mice. A friend of yours is desperate
to lose weight but cannot give up soda. Your friend wants to know how much diet
soda it is possible to drink without dying as a result. Write a program to supply
the answer. The input to the program is the amount of artificial sweetener needed
to kill a mouse, the weight of the mouse, and the weight of the dieter. To ensure
the safety of your friend, be sure the program requests the weight at which the
dieter will stop dieting, rather than the dieter’s current weight. Assume that diet
soda contains one-tenth of 1% artificial sweetener. Use a variable declaration with
the modifier const to give a name to this fraction. You may want to express the
percentage as the double value 0.001.*/
#include <iostream>
using namespace std;

int main() {
    double debt;
    double monthlyPayment;
    double interest_amount;
    double interest_rate_monthly = 1.5;
    double total_interest_amount=0;
    int month = 0;
    cout << "How much money do you have debt ?" << endl;
    cin >> debt;
    cout << "How much money do you pay monthly ?" << endl;
    cin >> monthlyPayment;
    while(debt > 0){
        interest_amount = debt*1.5/100;
        if(debt < monthlyPayment -interest_amount){
            monthlyPayment = debt+interest_amount;
            cout << "last montly payment is " << monthlyPayment << "$"<< endl;
        }
        debt-= monthlyPayment-interest_amount;
        total_interest_amount += interest_amount;
        month ++;
        cout << debt << endl;
    }
    cout << "Your debt will be finish after " << month << " month." << endl; 
    return 0;
}