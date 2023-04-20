/*Your Community Supported Agriculture (CSA) farm delivers a box of fresh fruits
and vegetables to your house once a week. For this Programming Project, define
the class BoxOfProduce that contains exactly three bundles of fruits or vegetables.
You can represent the fruits or vegetables as an array of type string. Add accessor
and mutator functions to get or set the fruits or vegetables stored in the array. Also
write an output function that displays the complete contents of the box on the
console.
Next, write a main function that creates a BoxOfProduce with three items
randomly selected from this list:
Broccoli
Tomato
Kiwi
Kale
Tomatillo
This list should be stored in a text file that is read in by your program. For now
you can assume that the list contains exactly five types of fruits or vegetables.
Do not worry if your program randomly selects duplicate produce for the three
items. Next, the main function should display the contents of the box and allow
the user to substitute any one of the five possible fruits or vegetables for any of the
fruits or vegetables selected for the box. After the user is done with substitutions
output the final contents of the box to be delivered.*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class BoxOfProduce{
    public:
    void setBoxOfProduce(string item1,string item2,string item3);
    void input();
    void output();
    private:
    string veg[3];
};
void BoxOfProduce::setBoxOfProduce(string item1,string item2,string item3){
    veg[0]=item1;
    veg[1]=item2;
    veg[2]=item3;
}
void BoxOfProduce::input(){
    string line = "";
    string temp[5];
    int i=0;
    ifstream file("vegetables.txt");
    if (file.is_open()) {
        cout << "a" << endl;
        while (getline(file, line)) {
            temp[i]=line;
            i++;
        }
        file.close();
    }
    else {
        cerr << "Failed to open produce options file" << endl;
        exit(1);
    }
    srand(time(nullptr));
    string item1= temp[rand()%5];
    string item2= temp[rand()%5];
    string item3= temp[rand()%5];
    setBoxOfProduce(item1,item2,item3);
}
void BoxOfProduce::output(){

        cout << "Box of produce vegs:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << i+1 <<"- " << veg[i] << endl;

        }
}

int main(){
    BoxOfProduce veg1;
    veg1.input();
    veg1.output();
    return 0;
}