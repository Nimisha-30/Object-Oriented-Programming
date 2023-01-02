#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include "info.h"

using namespace std;

class User
{
private:
    int choice;// Variable for user to select cashier or self-checkout options
    float totalPrice = 0;// Variable for the price
    int itemsBought[7];// Array for number of items bought
    string inventoryName[7] = {"Tea", "Coffee", "Black Tea", "Black coffee", "Sandwich", "Burger", "Pizza"};// Array for all product names
    float inventoryPrice[7] = {10, 10, 12, 12, 20, 30, 50};// Array for all prices

protected:
    int userid = 0;
    int pwd = 0;
    int loyalty = 0;// Stores user's loyalty level (0 is not registered, 1 is regular loyalty, 2 is executive loyalty)

public:
    int prevRegid[10];
    int prevRegpwd[10];
    int prevExecid[10];
    int prevExecpwd[10];
    int cashierid[10];
    int cashierpwd[10];
    User(info regid[10], info execid[10], info cashierRec[10], int enteredid, int enteredpwd, int enteredLoyalty)
    {
        for (int i=0;i<10;i++)
        {
            prevRegid[i] = regid[i].usid;
            prevRegpwd[i] = regid[i].pwd;
            prevExecid[i] = execid[i].usid;
            prevExecpwd[i] = execid[i].pwd;
            cashierid[i] = cashierRec[i].usid;
            cashierpwd[i] = cashierRec[i].pwd;
        }
        userid = enteredid;
        pwd = enteredpwd;
        loyalty = enteredLoyalty;
    }
    void greeting();// Initial greeting for user to welcome to cafe and gets ID and how user wants to checkout items
    void getInfo();// Asks whether user wants cashier or self-checkout
    void getUserCredentials();// Gets id and password from user
    bool validateUser(int proposedID, int proposedPassword);// Validates if user is registered with entered ID and password
    void buyItems();// Function to count number of items user wishes to purchase
    void calculatePrice();// Function to calculate the total price of all goods
    void purchaseSummary();// Gives summary of all purchases
    void amountPayable();//Amount exchanged
    int getID();// Returns ID of user
    int getLoyalty();// Returns loyalty type of user
    int getOption();// Returns choice of user's pay (self or cashier)
    int getPassword();// Returns password of user
    void setID(int id);// Setting ID of user
    void setLoyalty(int level);// Setting loyalty of user
    void setPassword(int uPassword);// Setting password of user
    void updateRecords(int currentID, int newID, int currentPassword, int newPassword);// Updating regular and executive members records with new user
    bool UniqueID (int proposedID);// Checks if proposed ID has already been used
};

#endif // USER_H_INCLUDED
