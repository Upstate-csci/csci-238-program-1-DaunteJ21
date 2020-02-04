/********
 Author: D'daunte Jones
 Program: Money class - program assignment #1
 Due Date:2/3/2020
 Purpose:
 ********/
#include "money.h"

 // convert current currency values to a string
string Money::toString() {
    stringstream ss;
    ss << hundreds << " hundreds "<< tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << pennies << " pennies";
    return ss.str();
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {

    stringstream ss;
    ss.imbue(locale(""));
    ss << showbase << put_money(amount * 100);

    return ss.str();
}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    stringstream ss;
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> pennies;
    total = static_cast<double>(hundreds) * 100 + static_cast<double>(tens) * 10 + static_cast<double>(fives) * 5 + static_cast<double>(ones) * 1 + static_cast<double>(quarters) * .25 + static_cast<double>(dimes) * .10 + static_cast<double>(nickels) * 0.05 + static_cast<double>(pennies) * .01;
    cout << toString() << " = " << toCurrency(total);
    return ss.str();
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {
    stringstream ss;
    cin >> input;
    hundreds = input / 100;
    int j;
    j = static_cast<int>(input) % 100;
    tens = j / 10;
    j = j % 10;
    fives = j / 5;
    j = j % 5;
    ones = j / 1;
    j = j % 1;
    j = static_cast<int>(input * 100) % 100;
    float j2 = j;
    quarters = j2 / 25;
    j2 = static_cast<int>(j2) % 25;
    dimes = j2 / 10;
    j2 = static_cast<int>(j2) % 10;
    nickels = j2 / 5;
    j2 = static_cast<int>(j2) % 5;
    pennies = j2 / 1;
    j2 = static_cast<int>(j2) % 1;
    cout << toCurrency(input)  << " = " << toString();
    return "";
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    return "";
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    stringstream ss;
    double pay, result;
    float overall;
    cin >> pay >> overall;
    result = pay - overall;
    int j;
    hundreds = result / 100;
    j = static_cast<int>(result) % 100;
    tens = j / 10;
    j = j % 10;
    fives = j / 5;
    j = j % 5;
    ones = j / 1;
    j = j % 1;
    j = static_cast<int>(result * 100) % 100;
    float j2 = j;
    quarters = j2 / 25;
    j2 = static_cast<int>(j2) % 25;
    dimes = j2 / 10;
    j2 = static_cast<int>(j2) % 10;
    nickels = j2 / 5;
    j2 = static_cast<int>(j2) % 5;
    pennies = j2 / 1;
    j2 = static_cast<int>(j2) % 1;
    cout << "Change back on " << toCurrency(input) << " for purchase of " << toCurrency(pay) << " is " << toCurrency(result) << " which is " << toString();
    return ss.str();
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    stringstream ss;
    double result, pay;
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> pennies;
    total = static_cast<double>(hundreds) * 100 + static_cast<double>(tens) * 10 + static_cast<double>(fives) * 5 + static_cast<double>(ones) * 1 + static_cast<double>(quarters) * .25 + static_cast<double>(dimes) * .10 + static_cast<double>(nickels) * .5 + static_cast<double>(pennies) * .1;
    result = total - pay;
    int j;
    hundreds = result / 100;
    j = static_cast<int>(result) % 100;
    tens = j / 10;
    j = j % 10;
    fives = j / 5;
    j = j % 5;
    ones = j / 1;
    j = j % 1;
    j = static_cast<int>(result * 100) % 100;
    float j2 = j;
    quarters = j2 / 25;
    j2 = static_cast<int>(j2) % 25;
    dimes = j2 / 10;
    j2 = static_cast<int>(j2) % 10;
    nickels = j2 / 5;
    j2 = static_cast<int>(j2) % 5;
    pennies = j2 / 1;
    j2 = static_cast<int>(j2) % 1;
    cout << "Change back on " << toCurrency(total) << " for purchase of " << toCurrency(pay) << " is " << toCurrency(result) << " which is " << toString();
    return ss.str();
}