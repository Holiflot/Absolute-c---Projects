/*A liter is 0.264179 gallons. Write a program that will read in the number of liters
of gasoline consumed by the user’s car and the number of miles traveled by the
car and will then output the number of miles per gallon the car delivered. Your
program should allow the user to repeat this calculation as often as the user wishes.
Define a function to compute the number of miles per gallon. Your program
should use a globally defined constant for the number of liters per gallon.*/
#include <iostream>
using namespace std;
double  calculate(double mil, double liter);
double const gallon_to_liter=0.264179;
int main(){
    
    double mil,liter;
    char choose;
    do{
        cout << "How many miles have you traveled ?" << endl;
        cin >> mil;
        cout << "How much liter gasoline does your car use?" << endl;
        cin >> liter;
        double mg = calculate(mil,liter);
        cout << "Your vehicle has consumed " << mg << " miles/gallon." << endl;
        cout << "Dou you want to repeat this calculate?" << endl;
        cin >> choose;
    }while(choose =='y' || choose =='Y');
    return 0;
}

double calculate(double mil, double liter){
    double gallons = liter * gallon_to_liter;
    return  mil/gallons;
}