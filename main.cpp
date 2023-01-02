#include <iostream>
#include <string>

#include "user.h"
#include "SelfCheck.h"
#include "CashierCheck.h"
#include "info.h"

using namespace std;

int main()
{
    // Declaring variables
    int userIsRegistered = 0; // 0 = not registered, 1 = regular membership, 2 = executive membership

    // Declare initial struct with pre-existing records for users and cashier
    info regRecords[10] = {{10, 34}, {51, 20}, {23, 45}, {39, 58}, {78, 90}, {46, 80}, {20, 97}, {59, 31}, {101, 40}};
    info execRecords[10] = {{516, 890}, {613, 120}, {572, 891}, {591, 491}, {681, 681}, {230, 814}, {901, 423}, {629, 984}, {294, 283}};
    info cashierRecords[10] = {{1617, 2492}, {8191, 2904}};

    // Declaring objects
    User initialUser(regRecords, execRecords, cashierRecords, 0, 0, 0);

    initialUser.greeting(); // Giving greeting to user and prompting user to enter ID and password

    // Checking records if user is a registered customer and what type of loyalty they are
    for (int i = 0; i < 10; i ++)
    {
        //
        if (regRecords[i].usid == initialUser.getID() && regRecords[i].pwd == initialUser.getPassword())
        {
            userIsRegistered = 1;
            break;
        }
        else if (execRecords[i].usid == initialUser.getID() && execRecords[i].pwd == initialUser.getPassword())
        {
            userIsRegistered = 2;
            break;
        }
        else
        {
            userIsRegistered = 0;
        }
    }

    initialUser.setLoyalty(userIsRegistered); // Updating record of user class with registration type

    // Initializing additional objects
    SelfCheck selfUser(regRecords, execRecords, cashierRecords, initialUser.getID(), initialUser.getPassword(), initialUser.getLoyalty());
    CashierCheck cashierUser(regRecords, execRecords, cashierRecords, initialUser.getID(), initialUser.getPassword(), initialUser.getLoyalty());

    // If user is already registered, then they will have the choice to either self-checkout or get a checkout with the cashier
    if (userIsRegistered == 1 || userIsRegistered == 2)
    {

        // Starting class flow based on loyalty level
        if (initialUser.getOption() == 1)
        {
            selfUser.greeting();
        }
        else
        {
            cashierUser.greeting();
        }
    }

    // If user is not registered, then they will automatically be placed with a cashier
    else
    {
        // If user accidentally wants a self-checkout but is not registered, it will output that they are going to a cashier
        if (initialUser.getOption() == 1)
        {
            cout << endl << "Transferring to cashier..." << endl;
        }
        cashierUser.greeting();
    }
    cout << endl << "Thank you for using the Ohri application. Have a great day!" << endl;
    return 0;
}
