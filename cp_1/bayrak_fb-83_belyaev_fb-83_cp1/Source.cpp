#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
ifstream input("input.txt");
//ifstream input("input_wospace.txt");
void letters() {
	long double lenght = 0;
	string s;
	double frec[32];
	for (int i = 0; i < 32; i++) {
		frec[i] = 0;
	}
	char a;
	while (true) {
		getline(input, s);
		if (!input) {
			break;
		};
		for (int j = 0; j < s.length(); j++) {
			a = s[j];
			a = tolower(a);
			if (a >= 'à' && a <= 'ÿ') {
				frec[a + 32]++;
				lenght++;
			}
		}
	}
	for (int i = 0; i < 32; i++) {
		frec[i] = frec[i] / lenght;
	}
	char sample[32];
	sample[0] = 'à';
	for (int i = 1; i < 32; i++) {
		sample[i] = sample[0] + i;
	}
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			if (frec[i] > frec[j]) {
				double tmp = frec[i];
				frec[i] = frec[j];
				frec[j] = tmp;
				char tmpc = sample[i];
				sample[i] = sample[j];
				sample[j] = tmpc;
			}
		}
	}
	for (int i = 0; i < 32; i++) {
		cout << sample[i] << " - " << frec[i] << endl;
	}
	double h1 = 0;
	for (int i = 0; i < 32; i++) {
		if (frec[i] != 0) {
			h1 += (frec[i] * log2(frec[i]));
		}
	}
	cout << "h1 = " << -h1 << endl;
	double R = 1 - (-h1 / log2(32));
	cout << "R = " << R << endl << endl;
}

void bigrams_with() {
	string s;
	double h2 = 0;
	char sample[32];
	sample[0] = 'à';
	for (int i = 1; i < 32; i++) {
		sample[i] = sample[0] + i;
	}
	double blenght = 0;
	int bsample[32 * 32];
	double bfrec[32 * 32];
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			bsample[32 * i + j] = sample[i] * 32 + sample[j];
			bfrec[32 * i + j] = 0;
		}
	}
	input.clear();
	input.seekg(0, input.beg);
	while (true) {
		getline(input, s);
		if (!input) {
			break;
		};
		for (int j = 1; j < s.length(); j++) {
			if (s[j - 1] < 'à') s[j - 1] = tolower(s[j - 1]);
			if (s[j] < 'à') s[j] = tolower(s[j]);
			if (s[j - 1] >= 'à' && s[j - 1] <= 'ÿ' && s[j] >= 'à' && s[j] <= 'ÿ') {
				int b = 32 * (s[j - 1] + 32) + s[j] + 32;
				bfrec[b]++;
				blenght++;
			}

		}

	}
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			bfrec[32 * i + j] = bfrec[32 * i + j] / blenght;
		}
	}
	cout << fixed;
	cout.precision(7);
	cout << " ";
	for (int i = 0; i < 32; i++) {
		cout << "     " << sample[i] << "    ";
	}
	cout << endl;
	for (int i = 0; i < 32; i++) {
		cout << sample[i];
		for (int j = 0; j < 32; j++) {
			if (bfrec[32 * i + j] == 0) cout << "     0    ";
			else {
				cout << " ";
				cout << bfrec[32 * i + j];
			}
		}
		cout << endl;
	}
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			if (bfrec[32 * i + j] != 0) {
				h2 += (bfrec[32 * i + j] * log2(bfrec[32 * i + j]));
			}
		}

	}
	cout << "h2 = " << -h2 << endl;
	double R = 1 - (-h2 / log2(32*32));
	cout << "R = " << R << endl << endl;
}

void bigrams_without() {
	string s;
	double h2 = 0;
	char sample[32];
	sample[0] = 'à';
	for (int i = 1; i < 32; i++) {
		sample[i] = sample[0] + i;
	}
	double blenght = 0;
	int bsample[32 * 32];
	double bfrec[32 * 32];
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			bsample[32 * i + j] = sample[i] * 32 + sample[j];
			bfrec[32 * i + j] = 0;
		}
	}
	input.clear();
	input.seekg(0, input.beg);
	while (true) {
		getline(input, s);
		if (!input) {
			break;
		};
		for (int j = 1; j < s.length(); j+=2) {
			if (s[j - 1] < 'à') s[j - 1] = tolower(s[j - 1]);
			if (s[j] < 'à') s[j] = tolower(s[j]);
			if (s[j - 1] >= 'à' && s[j - 1] <= 'ÿ' && s[j] >= 'à' && s[j] <= 'ÿ') {
				int b = 32 * (s[j - 1] + 32) + s[j] + 32;
				bfrec[b]++;
				blenght++;
			}

		}

	}
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			bfrec[32 * i + j] = bfrec[32 * i + j] / blenght;
		}
	}
	cout << fixed;
	cout.precision(7);
	cout << " ";
	for (int i = 0; i < 32; i++) {
		cout << "     " << sample[i] << "    ";
	}
	cout << endl;
	for (int i = 0; i < 32; i++) {
		cout << sample[i];
		for (int j = 0; j < 32; j++) {
			if (bfrec[32 * i + j] == 0) cout << "     0    ";
			else {
				cout << " ";
				cout << bfrec[32 * i + j];
			}
		}
		cout << endl;
	}
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			if (bfrec[32 * i + j] != 0) {
				h2 += (bfrec[32 * i + j] * log2(bfrec[32 * i + j]));
			}
		}

	}
	cout << "h2 = " << -h2 << endl;
	double R = 1 - (-h2 / log2(32 * 32));
	cout << "R = " << R << endl << endl;
}
int main() {
	setlocale(LC_ALL, "Russian");
	
	letters();
	bigrams_with();
	bigrams_without();
	
	return 0;
}