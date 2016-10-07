/*
 * Christian Martinez
 * CS 135L - 1006
 * Assignment #0?
 *
 * This program will demonstrate how to use if statements to control the flow of our program
 *
 * Problem:
 ** Develop the software of a pay at the pump terminal at a gas station
 ** The gas station offers 3 kinds of gas: Regular, Plus, and Supreme
 ** Regular rate: $0.71/gal | Plus rate: $0.84/gal | Supreme rate: $0.92/gal
 ** The gas station offers two car washes: Shining Diamond - $7.00 | Star Platinum - $12.00
 ** If Star Platinum is purchased, a 15% discount is applied to the gas cost 
 ** If more than 10 gallons of supreme gas is purchased, reduce the rate of gas by $0.07/gal
 *
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    const int L = 31, R = 8;     // Constants for formatting output
    const int MINGALLONS = 10;   // Constant for minimum gallons before discount is applied

    // Constants for discount amounts
    const double GASREDUCTION = 0.07, CARWASHDISCOUNT = 0.15;

    double gallonsPurchased, gasPrice, gasCost, totalCost;
    double washCost = 0.0;
    char gasType, input;
    bool platinum = false;

    // Say hi and prompt for gas type
    cout << "Greetings, purchaser of petroleum." << endl
         << "Welcome to Jojo's Bizzare Car Wash" << endl
         << setw(L+R+1) << setfill('~') << "~" << endl
         << "Pick your poison: " << endl
         << "    R - Regular\n    P - Plus\n    S - Supreme\n"
         << setw(L+R+1) << setfill('~') << "~" << endl;

    // Read in gas type and sanitize input 
    cin >> gasType; gasType = toupper(gasType);

    // Set gas price according to the input 
    if(gasType == 'R')
        gasPrice = 0.71;
    else if (gasType == 'P')
        gasPrice = 0.84;
    else if (gasType == 'S')
        gasPrice = 0.92;

    // Error out if the input was bad
    else{
        cout << "Error: We don't have that poison" << endl;
        return 1;
    }

    // Prompt for the number of gallons purchased and read in input 
    cout << "Enter number of gallons purchased: ";    cin >> gallonsPurchased;

    // If the user bought supreme gas and it was more than 10 gallons, reduce the cost 
    if(gallonsPurchased > 10 && gasType == 'S')
        gasPrice -= GASREDUCTION;

    // Prompt for a carwash and read and sanitize input 
    cout << "Would you like to purchase a carwash....(y/n)?" << endl;    cin >> input; input = toupper(input);

    // If the user wants a carwash
    if(input == 'Y'){

        // Prompt for the car wash type 
        cout << setw(L+R+1) << setfill('~') << "~" << endl
             << "Pick your level of cleanliness: " << endl
             << "    D - Shining Diamond\n    P - Star Platinum\n" << endl  
             << setw(L+R+1) << setfill('~') << "~" << endl;  
             
        // Read and sanitize 
        cin >> input; input = toupper(input);

        // If they want shining diamond, set the cost
        if(input == 'D')
           washCost = 7.00;
        // Otherwise set the cose for star platinum
        else{
           washCost = 12.00;
           platinum = true;
        }
    }

    gasCost = gasPrice * gallonsPurchased;

    if(platinum)
        gasCost = gasCost - (gasCost * CARWASHDISCOUNT);


    // Set the precision for dollars 
    cout << endl << endl << fixed << setprecision(2) << setfill(' ')

         // Show the gas type 
         << left << setw(L) << "Gas Type:" << " "
         << right << setw(R);

    if(gasType == 'R')
        cout << "Regular" << endl;
    else if (gasType == 'P')
        cout << "Plus" << endl;
    else if (gasType == 'S')
        cout << "Supreme" << endl;

    cout << left << setw(L) << "Gallons Purchased:" << " "
         << right << setw(R) << gallonsPurchased << endl
         << left << setw(L) << "Gas Price:" << "$"
         << right << setw(R) << gasPrice << "/gal" << endl << endl
         << left << setw(L) << "Gas Cost:" << "$"
         << right << setw(R) << gasCost << endl
         << left << setw(L) << "Car Wash Cost:" << "$"
         << right << setw(R) << washCost << endl;

    if(platinum){
        cout << left << setw(L) << "Platinum Savings:" << "$"
         << right << setw(R) << gasCost * CARWASHDISCOUNT << endl;
    }
    cout << left  << setw(L) << "Total Cost:" << "$"
         << right << setw(R) << gasCost + washCost << endl;

    return 0;
}
