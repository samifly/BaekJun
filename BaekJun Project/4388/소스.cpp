#include <bits/stdc++.h>

using namespace std;

int main() {

	while (true) {

		string str1, str2; cin >> str1 >> str2;

		if (str1 == "0" && str2 == "0") break;

		if (str1.length() < str2.length()) swap(str1, str2);

		int len = min(str1.length(), str2.length());

		str1 = '0' + str1; str2 = '0' + str2;

		reverse(str1.begin(), str1.end());
		reverse(str2.begin(), str2.end());

		int cnt = 0;

		for (int i = 0; i < len; i++) {

			int c1 = str1[i] - '0', c2 = str2[i] - '0';

			if (c1 + c2 < 10)
				str1[i] = (c1 + c2) + '0';
			else {

				str1[i] = (c1 + c2 - 10) + '0';

				cnt++;

				int w = 1;

				while (true) {

					int num = (str1[i + w] - '0') + 1;

					if (num < 10) {

						str1[i + w] = num + '0';
						break;

					}
					else
						str1[i + w] = '0', cnt++;

					w++;

				}

			}

		}

		cout << cnt << "\n";

	}

	return 0;

}