#ifndef CASHIERCHECK_H_INCLUDED
#define CASHIERCHECK_H_INCLUDED

#include "user.h"
#include "info.h"

//CashierCheck is a class for checkout by cashier. It is derived in a public fashion from the base class of User.

class CashierCheck : public User
{
public:
    CashierCheck(info regularID[10], info execID[10], info cashierRec[10], int enteredID, int enteredPassword, int enteredLoyalty) : User(regularID, execID, cashierRec, enteredID, enteredPassword, enteredLoyalty)
    {}
    void greeting(); // Overriding greeting of User base class
    void dataEntry(); // Asks user what they would like to do with the cashier
    void checkInfo(); // Allows user to check their own information
    void updateInfo(); // Allows user to update their information
    void getLoyalty(); // Allows user to get a new loyalty and gets ID and other necessary details
    void summaryOfMembers(); // Outputs summary of all existing records
    bool validateCashier(int cashID, int cashPass); // Checks to make sure cashier is registered
};

#endif // CASHIERCHECK_H_INCLUDED
