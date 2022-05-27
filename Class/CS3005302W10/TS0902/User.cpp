#include "User.h"

namespace {
	string username;

	//確認是否正確合法
	bool isValid() {
		if (username.length() != 8) return false;
		bool nonLetter = false;
		for (int i = 0; i < username.length(); i++) {
			if (!(username[i] >= 'a' && username[i] <= 'z')) nonLetter = true;
		}
		return !nonLetter;
	}
}

namespace Authenticate {
	//輸入使用者名稱
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}

	//取得使用者名稱
	string getUserName()
	{
		return username;
	}
}