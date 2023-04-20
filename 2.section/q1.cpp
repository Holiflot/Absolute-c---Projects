/*A metric ton is 35,273.92 ounces. Write a program that will read the weight of a
package of breakfast cereal in ounces and output the weight in metric tons as well
as the number of boxes needed to yield one metric ton of cereal.*/
#include <iostream>
using namespace std;

int main() {
    double cost, inflation_rate;
    int years;
    // read input from user
    cout << "Maddenin bugünkü maliyeti nedir? ";
    cin >> cost;

    cout << "Maddenin kaç yıl sonra satın alınacağı? ";
    cin >> years;

    cout << "Enflasyon oranı nedir (yüzde olarak)? ";
    cin >> inflation_rate;
    inflation_rate = inflation_rate /100;

    for(int i =0;i<years;i++){
        cost += cost*inflation_rate;
    }
    cout << "present value of the item is " << cost << "$" << endl;
    return 0;
}