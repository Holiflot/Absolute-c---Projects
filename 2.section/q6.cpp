/*An employee is paid at a rate of $16.78 per hour for regular hours worked in a
week. Any hours over that are paid at the overtime rate of one and one-half times
that. From the worker’s gross pay, 6% is withheld for Social Security tax, 14% is
withheld for federal income tax, 5% is withheld for state income tax, and $10 per
week is withheld for union dues. If the worker has three or more dependents, then
an additional
$35 is withheld to cover the extra cost of health insurance beyond what
the employer pays. Write a program that will read in the number of hours worked in
a week and the number of dependents as input and that will then output the worker’s
gross pay, each withholding amount, and the net take-home pay for the week.*/
#include <iostream>
using namespace std;



int main() {
    double const pi = 3.14;
    double const specificWeightOfWater = 62.4;
    double g = 10.0;
    double sphere_weight,sphere_radius,buoyantForce;
    cout << "Please enter sphere weight in pounds and radius in fit" << endl;
    cin >> sphere_weight >> sphere_radius;
    double sphere_volume = 4.0/3.0*pi*sphere_radius*sphere_radius*sphere_radius; 
    buoyantForce = sphere_volume * specificWeightOfWater;
    if( buoyantForce >= sphere_weight*g)
         cout << "The sphere will float." << endl;
    else
        cout << "The sphere will sink." << endl;
    return 0;
}
