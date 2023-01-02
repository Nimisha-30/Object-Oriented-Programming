#include "CashierCheck.h"
#include "user.h"

#include <iostream>
#include <string>

using namespace std;

// Function to greet user to cashier
void CashierCheck::greeting()
{
    // Variables for storing options and cashier information
    int userOption;
    int tempCashierID;
    int tempCashierPassword;
    // Getting cashier login
    do
    {
        cout << endl << "Please enter the cashier's ID: ";
        cin >> tempCashierID;
        cout << "Please enter the cashier's password: ";
        cin >> tempCashierPassword;
    }
    while (validateCashier(tempCashierID, tempCashierPassword) == false);
    cout << endl << "Welcome to the cashier check in program!" << endl;
    do
    {
        cout << endl << "Enter 1 if you would like to buy your items, or 2 to review your customer data." << endl;
        cin >> userOption;
        if(userOption != 1 && userOption != 2)
        {
                cout<<endl<<"Error 444"<<endl;
                cout<<"Enter a number from given options only."<<endl;
        }
    }
    while (userOption != 1 && userOption != 2); // Validates option
    // Calls function to view data or calls function to buy items based on userOption
    if (userOption == 2)
    {
       dataEntry();
    }
    else
    {
        User::buyItems();
        User::purchaseSummary();
        User::amountPayable();
    }
}

// Function to ensure that cashier is registered. Returns true if registered, and false if not registered
bool CashierCheck::validateCashier(int cashID, int cashPass)
{
    bool validate = false;
    try
    {
        for (int i = 0; i < 10; i ++) // Loops through records to check if cashier has been registered
        {
            if (cashID == cashierid[i] && cashPass == cashierpwd[i])
            {
                validate = true;
            }
        }
        if(validate == false)
        {
            throw 333;
        }
    }
    catch(int q)
    {
        cout<<endl<<"Error "<<q<<endl;
        cout<<"Incorrect user ID or password entered."<<endl;
    }
    return validate;
}

// Portal to enter data
void CashierCheck::dataEntry()
{
    // Variable for storing option and previous ID. Also storing cashier's id and password
    int dataOption;
    int currentID = User::getID();
    int currentPassword = User::getPassword();
    cout << "Welcome to the data entry home page! What would you like to update? " << endl;
    try
    {
        cout << endl << "Enter 1 to Review your information " << endl;
        cout << "Enter 2 to Update information " << endl;
        cout << "Enter 3 to Sign up for loyalty " << endl;
        cout << "Enter 4 to Quit " << endl;
        cin >> dataOption;
        if(dataOption != 1 && dataOption != 2 && dataOption != 3 && dataOption != 4)
        {
            throw 1.11;
        }
    }
    catch(double n)
    {
        cout<<endl<<"Error 111"<<endl;
        cout<<"Enter a number from given options only."<<endl;
        dataEntry();
    }
    // Calls respective function based on option asked by user. Quit option will skip the following conditionals
    if (dataOption == 1)
    {
        checkInfo();
    }
    else if (dataOption == 2)
    {
        updateInfo();
        User::updateRecords(currentID, User::getID(), currentPassword, User::getPassword());
    }
    else if (dataOption == 3)
    {
        getLoyalty();
        User::updateRecords(currentID, User::getID(), currentPassword, User:: getPassword()); // Calls function update records with new member
    }
    summaryOfMembers(); // Calls function to get an information summary of all member
    greeting();
}

// Outputs all customer information (ID, password, email)
void CashierCheck::checkInfo()
{
   cout << endl << "You have the following customer info: " << endl;
   cout << "Customer ID: " << User::getID() << endl;
   cout << "Customer Password: " << User::getPassword() << endl;
}

// Function to update previous information with new information
void CashierCheck::updateInfo()
{
    // Variable to store user's option
    char userOption;
    cout << endl << "You can now update your customer information: " << endl;
    // Asks if user wants to update ID
    do
    {
        cout << "Your old user ID is: " << User::getID() << endl;
        cout << "Would you like to change your ID (y/n)? " << endl;
        cin >> userOption;
    }
    while (userOption != 'y' && userOption != 'n');
    // If the user wants to update the ID, it will make sure that there are no ID that are identical to the one entered
    if (userOption == 'y')
    {
        int newUserID;
        do
        {
           cout << "Please enter your new user ID: ";
           cin >> newUserID;
        }
        while (newUserID == User::getID() || UniqueID(newUserID) == false); // Makes sure that entered ID is not identical to the previous and makes sure that ID is not identical to other IDs
        User::setID(newUserID); // Sets new ID
    }
    userOption = ' '; // Clearing user option for use in another case
    // Asks user if they would like to change the password and validates option
    do
    {
        cout << "Your old password: " << User::getPassword() << endl;
        cout << "Would you like to change your password (y/n)?" << endl;
        cin >> userOption;
    }
    while (userOption != 'y' && userOption != 'n');
    // Changes password and validates if password is unique
    if (userOption == 'y')
    {
        int newPassword;
        do
        {
            cout << "Please enter your new password: ";
            cin >> newPassword;
        }
        while (newPassword == User::getPassword()); // Makes sure that entered password is not identical to the previous password
        User::setPassword(newPassword); // Sets new password
    }
}

// Function to get a new account/loyalty
void CashierCheck::getLoyalty()
{
    // Variables used in the function
    int loyaltyLevel;
    int newID;
    int newPassword;
    cout << endl << "Here are the following options regarding loyalty levels: " << endl;
    cout << "Regular loyalty: 10% off on any purchase." << endl;
    cout << "Executive loyalty: 20% off on any purchase." << endl;
    // Outputs loyalty level of user
    cout << endl << "Your current loyalty level is: ";
    if (User::getLoyalty() == 0)
    {
        cout << "Not registered" << endl;
    }
    else if (User::getLoyalty() == 1)
    {
        cout << "Regular loyalty" << endl;
    }
    else
    {
        cout << "Executive loyalty" << endl;
    }
    cout << endl << "Please enter your new loyalty level." << endl;
    // Gets new loyalty level and validates function
    do
    {
        try
        {
            cout << endl << "Option 1: Regular loyalty --- Please enter 1. " << endl;
            cout << "Option 2: Executive loyalty --- Please enter 2. " << endl;
            cin >> loyaltyLevel;
            if(loyaltyLevel != 1 && loyaltyLevel != 2)
            {
                throw 222;
            }
        }
        catch(int p)
        {
            cout<<endl<<"Error "<<p<<endl;
            cout<<"Enter a number from given options only."<<endl;
        }
    }
    while(loyaltyLevel != 1 && loyaltyLevel != 2);
    User::setLoyalty(loyaltyLevel); // Setting loyalty in base class
    cout << endl << "Your current user ID is: " << User::getID() << endl;
    // Gets user's ID until it is unique from previously entered IDs
    do
    {
        cout << "Please enter your desired ID: ";
        cin >> newID;
    }
    while (newID == User::getID() || UniqueID(newID) == false);
    User::setID(newID); // Setting ID in base class
    cout << endl << "Your old password is: " << User::getPassword() << endl;
    // Gets user's new password until it is unique from previously entered password
    do
    {
        cout << "Please enter your password: ";
        cin >> newPassword;
    }
    while (newPassword == User::getPassword());
    User::setPassword(newPassword); // Setting password
}

// Gives summary of all members
void CashierCheck::summaryOfMembers()
{
    cout << endl << "Here are the following records of all users in the cafe. For privacy, no passwords will be displayed." << endl;
    // Sorting arrays via bubble sort
    for (int i = 0; i < 10; i ++)
    {
        for (int j = 0; j < 9; j ++)
        {
            if (prevRegid[j + 1] < prevRegid[j])
            {
                int tempID = prevRegid[j];
                //string tempEmail = prevRegEmails[j];
                prevRegid[j] = prevRegid[j + 1];
                //prevRegEmails[j] = prevRegEmails[j + 1];
                prevRegid[j + 1] = tempID;
                //prevRegEmails[j + 1] = tempEmail;
            }
            if (prevExecid[j + 1] < prevExecid[j])
            {
                int tempID = prevExecid[j];
                //string tempEmail = prevExecEmails[j];
                prevExecid[j] = prevExecid[j + 1];
                //prevExecEmails[j] = prevExecEmails[j + 1];
                prevExecid[j + 1] = tempID;
                //prevExecEmails[j + 1] = tempEmail;
            }
        }
    }
    // Outputs regular members ID
    cout << endl << "Regular membership members: " << endl;
    for (int i = 0; i < 10; i ++)
    {
        cout << "ID of Member " << i + 1 <<": " << prevRegid[i] << endl;
    }
    // Outputs executive members ID and email
    cout << endl << "Executive membership members: " << endl;
    for (int i = 0; i < 10; i ++)
    {
        cout << "ID of Member " << i + 1 <<": " << prevExecid[i] << endl;
    }
}
