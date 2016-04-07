//Program for calculating solid angle coverage of VANDLE bars
//
//
//Written by S. Taylor, 4/7/16

#include <iostream>
#include <cmath>

using namespace std;
    //variables
    double length, width, flightpath;//cm
    double bartype, bar_total_number;
    double single_coverage, array_coverage;//sr
    double single_percent, array_percent;//%
    double x, y;//placeholders for formulas
    const double pi = 3.14159265358979323846;

    //calculates solid angle coverage in steradians and % for single bar and
    //for the number of that type in the array together.
    void calculations(int L, int W){
    x=L/(2*flightpath);
    y=W/(2*flightpath);
    double numerator, denominator;//to make code easier to read
    numerator=1+pow(x,2)+pow(y,2);
    denominator=(1+pow(x,2))*(1+pow(y,2));
    single_coverage=4*acos(sqrt((numerator/denominator)));
    single_percent=(single_coverage/(4*pi))*100;
    array_coverage=single_coverage*bar_total_number;
    array_percent=(array_coverage/(4*pi))*100;
    }

int main()
{

    cout << "Enter Bar Type(1=small,2=medium,3=large): " << endl;
    cin >> bartype;
    cout << "Enter Flightpath Length(cm): " << endl;
    cin >> flightpath;
    cout << "Enter # Of Bars Of This Type: " << endl;
    cin >> bar_total_number;

    //sets bar type info
    if(bartype==1){
    length=60;//cm
    width=3;//cm
    calculations(length,width);
    }
    else if(bartype==2){
    length=120;//cm
    width=6;//cm
    calculations(length,width);
    }
    else if(bartype==3){
    length=200;//cm
    width=5;//cm
    calculations(length,width);
    }
    else{
    cout << "ERROR: PLEASE PICK BAR TYPE" << endl;
    }

    //Outputs answers
    cout << "Single Bar Coverage(sr)= " << single_coverage << endl;
    cout << "Single Bar Coverage(%)= " << single_percent << endl;
    cout << "Total Of All Bars Coverage(sr)= " << array_coverage << endl;
    cout << "Total Of All Bars Coverage(%)= " << array_percent << endl;
    return 0;
}
