// Name: 郭鈺晨(Yu-chen Kuo)
// Date: April, 19, 2022
// Last Update: April, 24, 2022
// Problem statement: Encoder Machine

#include <iostream>
#include <string>

using namespace std;

int main() {
	int m, n;
	char c1, c2;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) return 0;
		int tran[26][26] = {};

		//輸入條件
		for (int i = 0; i < m; i++) {
			cin >> c1 >> c2;
			tran[c1 - 'a'][c2 - 'a'] = 1;
		}

		//建立連結
		for (int l = 0; l < m; l++) {
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					if (tran[i][j] != 0) {
						for (int k = 0; k < 26; k++) {
							tran[i][k] += tran[j][k];
							if (tran[i][k] != 0) tran[i][k] = 1;
						}
					}
				}
			}
		}

		//輸入比較字串
		string s1, s2;
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;

			if (s1.length() != s2.length()) {
				cout << "no\n";
				continue;
			}

			int len = s1.length();
			bool flag = 0;

			for (int j = 0; j < len; j++) {
				if (s1[j] == s2[j]) {
					continue;
				}
				else if (tran[s1[j] - 'a'][s2[j] - 'a'] == 0) {
					flag = 1;
					break;
				}
			}

			if (!flag) cout << "yes\n";
			else cout << "no\n";
		}
	}
	return 0;
}