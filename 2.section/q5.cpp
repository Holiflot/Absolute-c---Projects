/*Write a program that determines whether a meeting room is in violation of fire law
regulations regarding the maximum room capacity. The program will read in the
maximum room capacity and the number of people to attend the meeting. If the
number of people is less than or equal to the maximum room capacity, the program
announces that it is legal to hold the meeting and tells how many additional people
may legally attend. If the number of people exceeds the maximum room capacity, the
program announces that the meeting cannot be held as planned due to fire regulations
and tells how many people must be excluded in order to meet the fire regulations.*/
#include <iostream>
using namespace std;



int main() {
    for(int t=0;t < 10; t ++){
        for(int o=0;o<10;o++){
            for(int g=0;g<10;g++){
                for(int d=0;d<10;d++){
                    if (t != o && t != g && t != d && o != g && o != d && g != d) {
                        int too = 100*t+10*o+o;
                        int good = 1000*g+100*o+10*o+d;
                        if(too*4==good){
                            cout << "T = " << t << endl;
                            cout << "O = " << t << endl;
                            cout << "G = " << g << endl;
                            cout << "D = " << d << endl; 
                        }
                    }
                }
            }
        } 
    }
    return 0;
}
