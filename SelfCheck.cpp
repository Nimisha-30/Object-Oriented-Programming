#include "SelfCheck.h"
#include "user.h"

#include <iostream>

using namespace std;

// Overriding base class greeting function
void SelfCheck::greeting()
{
    cout << endl << "Welcome to the self-checkout counter. Please indicate how many items you will be buying: " << endl;
    User::buyItems();
    User::purchaseSummary();
    User::amountPayable();
}
