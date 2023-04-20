/*The type Point is a fairly simple data type, but under another name (the template
class pair) this data type is defined and used in the C++ Standard Template Library,
although you need not know anything about the Standard Template Library
to do this exercise. Write a definition of a class named Point that might be used to
store and manipulate the location of a point in the plane. You will need to declare
and implement the following member functions:
a. A member function set that sets the private data after an object of this class is
created.
b. A member function to move the point by an amount along the vertical and
horizontal directions specified by the first and second arguments.
c. A member function to rotate the point by 90 degrees clockwise around the
origin.
d. Two const inspector functions to retrieve the current coordinates of the point.
Document these functions with appropriate comments. Embed your class in a test
program that requests data for several points from the user, creates the points, then
exercises the member functions.*/
#include <iostream>
using namespace std;

class Point{
    public:
        void input();
        void setPoint(int x, int y);
        int getHorizontal()const;
        int getVertical()const;
        void clockwise90(int rotate);
        void move(int moveX,int moveY);
        void output()const;
    private:
        int horizontal;
        int vertical;
};
void  Point::setPoint(int x, int y){
    horizontal = x;
    vertical = y;
}
int Point::getHorizontal()const{return  horizontal;}
int Point::getVertical()const{return  vertical;}
void Point::move(int moveX, int moveY){
    horizontal +=moveX;
    vertical +=moveY;
}
void Point::clockwise90(int rotate){
    int temp=0;
    for(int i=0;i<rotate;i++){
        temp=horizontal;
        horizontal=vertical;
        vertical=-temp;
    }
}
void Point::input(){
    int x,y;
    cout << "Enter Horizontal value: ";
    cin >> x;
    cout << "Enter Vertical value: ";
    cin >> y;
    setPoint(x,y);
}
void Point::output()const{
    cout << "X axis: " << horizontal  << " y axis: " << vertical << endl;
}
int main(){
    int input;
    int moveX,moveY,rotate;
    cout << "How many inputs do you enter?" << endl;
    cin >> input;
    Point p[input];
    for(int i=0;i<input;i++){
        p[i].input();
        p[i].output();
        cout <<"how much do you want to move the x and y axis? Please enter first x axis." << endl;
        cin >>moveX >> moveY;
        p[i].move(moveX,moveY);
        p[i].output();
        cout << "How many times do you want to rotate points clockwise 90?"<< endl;
        cin >> rotate;
        p[i].clockwise90(rotate);
        p[i].output();
    }
        

    return 0;
}