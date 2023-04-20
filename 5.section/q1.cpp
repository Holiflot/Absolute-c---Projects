/*Write a program that reads in the average monthly rainfall for a city for each
month of the year and then reads in the actual monthly rainfall for each of the
previous 12 months. The program then prints out a nicely formatted table showing
the rainfall for each of the previous 12 months as well as how much above or below
average the rainfall was for each month. The average monthly rainfall is given for
the months January, February, and so forth, in order. To obtain the actual rainfall
for the previous 12 months, the program first asks what the current month is and
then asks for the rainfall figures for the previous 12 months. The output should
correctly label the months.
There are a variety of ways to deal with the month names. One straightforward
method is to code the months as integers and then do a conversion before doing the
output. A large switch statement is acceptable in an output function. The month
input can be handled in any manner you wish, as long as it is relatively easy and
pleasant for the user.
After you have completed the previous program, produce an enhanced version
that also outputs a graph showing the average rainfall and the actual rainfall for
each of the previous 12 months. The graph should be similar to the one shown in
Display 5.4, except that there should be two bar graphs for each month, and they
should be labeled as the average rainfall and the rainfall for the most recent month.
Your program should ask the user whether he or she wants to see the table or the
bar graph, and then should display whichever format is requested. Include a loop
that allows the user to see either format as often as the user wishes until the user
requests that the program end.*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// function prototypes
void printTable(string months[], double avgRainfall[], double actualRainfall[]);

int main()
{
    string months[12] = {"January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November", "December"};
    double avgRainfall[12];
    double actualRainfall[12];
    int currentMonth;

    cout << "Enter the average rainfall (in inches) for each month of the year:" << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << months[i] << ": ";
        cin >> avgRainfall[i];
    }

    cout << endl << "What is the current month (1 for January, 2 for February, etc.)? ";
    cin >> currentMonth;
    cout << "Enter the actual rainfall (in inches) for the previous 12 months:" << endl;
    for (int i = 0; i < 12; i++)
    {
        int monthIndex = (currentMonth - i - 2 + 12) % 12;
        cout << months[monthIndex] << ": ";
        cin >> actualRainfall[monthIndex];
    }

    // print table of data
    cout << endl;
    printTable(months, avgRainfall, actualRainfall);

    return 0;
}

void printTable(string months[], double avgRainfall[], double actualRainfall[])
{
    cout << setw(10) << left << "Month" << setw(20) << left << "Actual Rainfall" << setw(20) << left << "Avg. Rainfall" << setw(20) << left << "Difference" << endl;
    for (int i = 0; i < 12; i++)
    {
        double difference = actualRainfall[i] - avgRainfall[i];
        cout << setw(10) << left << months[i] << setw(20) << left << actualRainfall[i] << setw(20) << left << avgRainfall[i] << setw(20) << left << difference << endl;
    }
}
