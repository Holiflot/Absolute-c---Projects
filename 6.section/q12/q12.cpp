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
    cout << "a" << endl;
    ifstream file("vegetables.txt");
    cout << "a" << endl;
    if (file.is_open()) {
        cout << "a" << endl;
        while (getline(file, line)) {
            cout << line << endl;
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