//#include <iostream>
#include "Password.h"

namespace {
    string password;
    //確認是否正確合法
    bool isValid() {
        if (password.length() < 8) return false;
        bool nonLetter = false;
        for (int i = 0; i < password.length(); i++) {
            if (!(password[i] >= 'a' && password[i] <= 'z')) nonLetter = true;
        }
        return nonLetter;
    }
}


namespace Authenticate {
    //string password;
    //輸入密碼
    void inputPassword()
    {
        do
        {
            cout << "Enter your password (at least 8 characters " <<
                "and at least one non-letter)" << endl;
            cin >> password;
        } while (!isValid());
    }

    //取得密碼
    string getPassword()
    {
        return password;
    }
}

