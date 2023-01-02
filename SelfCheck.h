#ifndef SELFCHECK_H_INCLUDED
#define SELFCHECK_H_INCLUDED

#include "user.h"
#include "info.h"

//SelfCheck is a class for self-checkout. It is derived in a public fashion from the base class of User.

class SelfCheck : public User
{
public:
    SelfCheck(info regularID[10], info execID[10], info cashierRec[10], int enteredID, int enteredPassword, int enteredLoyalty) : User(regularID, execID, cashierRec, enteredID, enteredPassword, enteredLoyalty)
    {}
    void greeting(); // Overriding greeting of User base class
};

#endif // SELFCHECK_H_INCLUDED
