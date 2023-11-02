#include<iostream>

using namespace std;

bool isCardValid(int digits[], int size);

int main() {

	const int MAX_SIZE = 8;
	int digits[MAX_SIZE];

	cout << "Enter 8-digit card # or Q to quit: ";
	int card_num;
	cin >> card_num;
	if (cin.fail() == true) {
		return 0;
	}

	for (int x = 0; x < MAX_SIZE; x++) {
		digits[x] = card_num % 10;
		card_num /= 10;
	}



	if (isCardValid(digits, MAX_SIZE) == true) {
		cout << "Card is valid.";
	}
	else { cout << "Card is not valid"; }
}


bool isCardValid(int digits[], int size) {
	int count = 0;
	int every_other = 0;
	int left_out = 0;
	int sum;

	int single_digit;

	for (int i = 0; i < size; i++) {
		single_digit = digits[i];
		count++;

		if (count % 2) {
			single_digit * 2;
			left_out = left_out + single_digit;
		}
		else {
			every_other = every_other + single_digit;
		}
	}

	sum = every_other + left_out;
	if (sum % 10) {
		return false;
	}
	else {
		return true;
	}

}