#include <iostream>
using namespace std;
int main(){
    double amountOfSweetener;
    double weightOfMouse;
    double weightOfdieter;
    double weightOfFriend;
    double amountOfMAxSoda;
    double const rate = 0.001;
    cout << "Enter the weight of the mouse : ";
    cin >>  weightOfMouse;

    cout << "Enter the amount of sweetener needed to kill the mouse : ";
    cin >> amountOfSweetener;

    cout << "Enter the weight at which the dieter will stop dieting : ";
    cin >> weightOfFriend;

    double amountOfKillingPerson = weightOfFriend*(amountOfSweetener/weightOfMouse);
    amountOfMAxSoda = amountOfKillingPerson / rate;
    cout << "The maximum amount of diet soda that can be consumed without dying is: " << amountOfMAxSoda << endl;
    return 0;
}