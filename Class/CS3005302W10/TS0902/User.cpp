#include "User.h"

namespace {
	string username;

	//�T�{�O�_���T�X�k
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
	//��J�ϥΪ̦W��
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}

	//���o�ϥΪ̦W��
	string getUserName()
	{
		return username;
	}
}