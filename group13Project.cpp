/* **************************************************************************************
AEM 249 Group 13 - Matt Creasey, Karly Williams, Andrew Walker, Russell Smith, Ian Artrip
18 April 2021
The purpose of this program is to calculate the drag on six different types of aircraft.
For the first 5, we are using predetermined values from 5 real-world aircraft.
For the 6th option, the user will enter custom values to find the drag.
****************************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;
double presetMath(double num1, double num2); // function declaration
double customMath(); // function for custom values (Case 6)

int main() {

int userChoice; // declaring integer to store user menu choice
double answer;

std::cout << "\nHello! This program will calculate the drag of a specific aircraft.\nOptions 1 through 5 are predetermined, and option 6 is custom.\n" << endl;

std::cout << "Option 1: Boeing 747 (Commercial Jet)\n";
std::cout << "Option 2: Cessna 172 (General Aviation)\n";
std::cout << "Option 3: General Dynamics F-16 (Fighter Jet)\n";
std::cout << "Option 4: LearJet 24 (Business Jet)\n";
std::cout << "Option 5: General Atomics MQ-1 Predator (UAV)\n";
std::cout << "Option 6: Custom Values (You decide)\n" << endl;

std::cout << "Choose your number 1-6: \n"; // present choices to the user
std::cin >> userChoice; // store value from user

  switch(userChoice) {

    case 1: { // user has chosen Boeing 747 (Commercial Jet)
    std::cout << "\nYou have chosen the Boeing 747.\n" << endl;
      double ra = 5500;
      double cDrag = 0.031;
      answer = presetMath(ra, cDrag); // calling the function here
      std::cout << "\nThe total drag is " << answer << " Newtons.\n" << endl;
    break; }

    case 2: { // user has chosen Cessna 172 (General Aviation)
    std::cout << "\nYou have chosen the Cessna 172.\n" << endl;
      double ra = 174;
      double cDrag = 0.01;
      answer = presetMath(ra, cDrag); // calling function
      std::cout << "\nThe total drag is " << answer << " Newtons.\n" << endl;
    break; }

    case 3: { // user has chosen General Dynamics F-16 (Fighter Jet)
    std::cout << "\nYou have chosen the F-16.\n" << endl;
      double ra = 300;
      double cDrag = 0.0282;
      answer = presetMath(ra, cDrag); // calling function
      std::cout << "\nThe total drag is " << answer << " Newtons.\n" << endl;
    break; }

    case 4: { // user has chosen Learjet 24 (Business Jet)
    std::cout << "\nYou have chosen the Learjet 24.\n" << endl;
      double ra = 231.77;
      double cDrag = 0.022;
      answer = presetMath(ra, cDrag); // calling function
      std::cout << "\nThe total drag is " << answer << " Newtons.\n" << endl;
    break; }

    case 5: { // user has chosen General Atomics MQ-1 (UAV)
    std::cout << "\nYou have chosen the MQ-1 Predator.\n" << endl;
      double ra = 123.30;
      double cDrag = 0.03;
      answer = presetMath(ra, cDrag); // calling function
      std::cout << "\nThe total drag is " << answer << " Newtons.\n" << endl;
    break; }

    case 6: {// user has chosen to input custom values
    std::cout << "\nYou have chosen to input custom values.\n" << endl;
      answer = customMath(); // calling function, this might not work
      std::cout << "\nThe total drag is " << answer << " Newtons.\n" << endl;
    break; }

} // end switch statement

} // end main

double presetMath(double num1, double num2) { // doing the calculations for options 1-5
    double resultLBF;
    double resultNewtons;
    double userV;
    double userP;
    double userV2;

    label:

    std::cout << "\nPlease enter the velocity in feet per second: " << endl; // read velocity from user
    std::cin >> userV;
    userV2 = userV * userV;

    std::cout << "\nPlease enter the density from 0.0562 to 0.0812: " << endl; // read density from user
    std::cin >> userP;

    if (userP < 0.0562 || userP > 0.0812) {
      std::cout << "\nInvalid response. Please re-enter a valid number." << endl;
      goto label; }

    // RA is num1, Cd is num2
    resultLBF = num2 * ((userP * userV2)/(2)) * num1;
    resultNewtons = resultLBF * 4.448;

    return resultNewtons; // send answer to original case to print

} // end presetMath function



double customMath() { // this is the function for custom values (Case 6)
    double resultLBF, resultNewtons;
    double userV, userV2;
    double userP, userRA, userCD;

    label:

    std::cout << "Please enter the velocity of the aircraft in feet per second: " << endl;
    std::cin >> userV;
    userV2 = userV * userV;

    std::cout << "\nNow enter the density from 0.0562 to 0.0812: " << endl;
    std::cin >> userP;

      if (userP < 0.0562 || userP > 0.0812) {
        std::cout << "\nInvalid response. Please re-enter a valid number." << endl;
        goto label; }

    std::cout << "\nPlease enter the Reference Area of the aircraft wing: " << endl;
    std::cin >> userRA;

    std::cout << "\nFinally, please enter the Drag Coefficient of the aircraft: " << endl;
    std::cin >> userCD;

    resultLBF = userCD * ((userP * userV2)/(2)) * userRA;
    resultNewtons = resultLBF * 4.448;

    return resultNewtons;

} // end customMath function
