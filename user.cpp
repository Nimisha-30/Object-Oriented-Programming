#include "user.h"
#include "user.h"
#include "info.h"

#include <iostream>
#include <string>

using namespace std;

// Greeting function and sends user to get ID and password
void User::greeting()
{
    cout << endl << "Hello, user! Welcome to Ohri's Cafeteria!" << endl;
    getInfo();
    cout << endl << "Please enter your numerical ID and password." << endl;
    getUserCredentials();
}

// Asks user if they want to check out by themselves or with a cashier
void User::getInfo()
{
    cout << endl << "Option 1: Self check out --- Enter 1" << endl;
    cout << "Option 2: Check out by cashier --- Enter 2" << endl;
    try
    {
        cin >> choice;
        if(choice!=1 && choice!=2)
        {
            throw 5.55;
        }
    }
    catch(double m)
    {
        cout<<endl<<"Error 101"<<endl;
        cout<<"Enter a number from given options only."<<endl;
        getInfo();
    }
}

// Collects ID and password of user
void User::getUserCredentials()
{
    do
    {
        cout << "User ID: ";
        cin >> userid;
        cout << "Password: ";
        cin >> pwd;
    }
    while (choice == 1 && validateUser(userid, pwd) == false); // Will continue asking for ID and password if user wants to self-checkout and enters incorrect ID and password
}

// Validates if user entered right ID and password
bool User::validateUser(int proposedID, int proposedPassword)
{
    bool validate = false;
    try
    {
        for (int i = 0; i < 10; i ++) // Loops through records to check if user has been registered
        {
            if (proposedID == prevRegid[i] && proposedPassword == prevRegpwd[i])
            {
                validate = true;
            }
            else if (proposedID == prevExecid[i] && proposedPassword == prevExecpwd[i])
            {
                validate = true;
            }
        }
        if(validate == false)
        {
            throw 202;
        }
    }
    catch(int x)
    {
        cout<<endl<<"Error "<<x<<endl;
        cout<<"Incorrect user ID or password entered."<<endl;
    }
    return validate;
}

// Returns user ID
int User::getID()
{
    return userid;
}

// Sets user ID
void User::setID(int id)
{
    userid = id;
}

// Returns user password
int User::getPassword()
{
    return pwd;
}

// Sets user password
void User::setPassword(int uPassword)
{
    pwd = uPassword;
}

// Returns option
int User::getOption()
{
    return choice;
}

// Returns loyalty
int User::getLoyalty()
{
    return loyalty;
}

// Set loyalty
void User::setLoyalty(int level)
{
    loyalty = level;
}

// Checks if entered ID is unique
bool User::UniqueID(int proposedID)
{
    bool unique = true;
    for (int i = 0; i < 10; i ++)
    {
        // If proposedID is same as any previous ID, it will return false
        if (prevRegid[i] == proposedID || prevExecid[i] == proposedID)
        {
            unique = false;
            break;
        }
    }
    return unique;
}

// Function buy items
void User::buyItems()
{
    cout << endl << "Please enter the number of items you would like to purchase." << endl;
    // Outputs items and gets number of items bought
    for (int i = 0; i < 7; i ++)
    {
        try
        {
            cout << inventoryName[i] << " ($" << inventoryPrice[i] << "): ";
            cin >> itemsBought[i];
            if(itemsBought[i]<0||itemsBought[i]>50)
            {
                throw 303;
            }
        }
        catch(int y)
        {
            cout<<endl<<"Error "<<y<<endl;
            cout<<"Enter any number between 0 and 50 only."<<endl;
            buyItems();
        }
    }
    calculatePrice(); // Calls function to calculate price
}

void User::calculatePrice()
{
    for (int i = 0; i < 7; i ++)
    {
        totalPrice += itemsBought[i] * inventoryPrice[i]; // Calculates total price by multiplying number of items bought with price
    }
}

// Summarizes purchases and asks for money
void User::purchaseSummary()
{
    cout << endl << "Here is a summary of your purchases: " << endl;
    // Reading off user's purchases from two arrays (name of item and price of item)
    for (int i = 0; i < 7; i ++)
    {
        cout << inventoryName[i] << ": " << itemsBought[i] << " bought" << endl;
    }
    // Outputting total purchase price
    cout << endl << "Subtotal: $" << totalPrice << endl;
    // Loyalty discount
    if (loyalty == 0)
    {
        cout << endl << "Total: $" << totalPrice << endl;
    }
    else if (loyalty == 1)
    {
        cout << endl << "Total with 10% discount: $" << totalPrice * 0.9 << endl;
        totalPrice = totalPrice * 0.9;
    }
    else
    {
        cout << endl << "Total with 20% discount: $" << totalPrice * 0.8 << endl;
        totalPrice = totalPrice * 0.8;
    }
}

void User::amountPayable()
{
    float userAmount;
    // Ensuring that user pays price or more for change
    try
    {
        cout << endl << "Please enter the amount you would like to pay: ";
        cin >> userAmount;
        if(userAmount < totalPrice)
        {
            throw 404;
        }
    }
    catch(int z)
    {
        cout<<endl<<"Error "<<z<<endl;
        cout<<"Enter an amount greater than or equal to the amount that needs to be paid."<<endl;
        amountPayable();
    }
    if (userAmount > totalPrice)
    {
        cout << endl << "Your change: $" << userAmount - totalPrice << endl;
    }
}

// Adds new users or updates user's records with their ID and passwords
void User::updateRecords(int currentID, int newID, int currentPassword, int newPassword)
{
    // Finding which array to update based on loyalty level and then finding empty place in respective array
    bool alreadyUpdated = false;
    // Puts record into regular membership records
    if (getLoyalty() == 1)
    {
        for (int i = 0; i < 10; i ++)
        {
            if (prevRegid[i] == currentID) // Finds place in array in previous place and updates ID into that spot
            {
                prevRegid[i] = newID;
                prevRegpwd[i] = newPassword;
                alreadyUpdated = true;
                break; // Only does this once
            }
        }
        if (alreadyUpdated == false) // Runs conditional if the array hasn't been updated into a previous place (indicating new user)
        {
            for (int i = 0; i < 10; i ++)
            {
                if (prevRegid[i] == 0) // Finds empty place in array and updates ID into that spot
                {
                    prevRegid[i] = newID;
                    prevRegpwd[i] = newPassword;
                    alreadyUpdated = true;
                    break; // Only does this once
                }
            }
        }
    }
    else if (getLoyalty() == 2) // Puts record into executive membership records
    {
        for (int i = 0; i < 10; i ++)
        {
            if (prevExecid[i] == currentID) // Finds place in array in previous place and updates ID into that spot
            {
                prevExecid[i] = newID;
                prevExecpwd[i] = newPassword;
                alreadyUpdated = true;
                break; // Only does this once
            }
        }
        if (alreadyUpdated == false) // Runs conditional if the array hasn't been updated into a previous place (indicating new user)
        {
            for (int i = 0; i < 10; i ++)
            {
                if (prevExecid[i] == 0) // Finds empty place in array and updates ID into that spot
                {
                    prevExecid[i] = newID;
                    prevExecpwd[i] = newPassword;
                    alreadyUpdated = true;
                    break; // Only does this once
                }
            }
        }
    }
}
