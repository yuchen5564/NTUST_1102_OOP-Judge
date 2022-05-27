//#include <iostream>
#include "Password.h"

namespace {
    string password;
    //�T�{�O�_���T�X�k
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
    //��J�K�X
    void inputPassword()
    {
        do
        {
            cout << "Enter your password (at least 8 characters " <<
                "and at least one non-letter)" << endl;
            cin >> password;
        } while (!isValid());
    }

    //���o�K�X
    string getPassword()
    {
        return password;
    }
}

