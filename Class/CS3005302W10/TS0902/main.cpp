// Name: ³¢à±±á(Yu-chen Kuo)
// Date: April, 19, 2022
// Last Update: May, 27, 2022
// Problem statement: Namespace

#include "Password.h"
#include "User.h"

using namespace Authenticate;

int main()
{
    inputUserName();
    inputPassword();
    cout << "Your username is " << getUserName() <<
        " and your password is: " <<
        getPassword() << endl;
    return 0;
}
