/*
 * Course: CS215-014
 * Project: Lab 3
 * Purpose: This program validates credit card numbers based on userinput
 * Author: Anthony Arnold
 */

#include <iostream>

using namespace std;

int main() {
	int credit_card;
	int digits[8]{};
	int i = 1;
	while (i !=0){
		cout << "Enter credit card number: ";
		cin >> credit_card;
		if (credit_card == -1) {
			cout << "Thank you for using \"Credit Card Validation\"!" << endl;
			return -1;
		}

		for (int i = 7; i >= 0; i--) {
			digits[i] = credit_card % 10;
			credit_card = credit_card / 10;
		}
		
		int even_placement_sum = digits[7] + digits[5] + digits[3] + digits[1];

		int dig4_x2 = (digits[4]) * 2;
		int dig6_x2 = (digits[6]) * 2;
		int dig2_x2 = (digits[2]) * 2;
		int dig0_x2 = (digits[0]) * 2;

		int dig6_1 = dig6_x2 / 10 % 10;
		int dig6_2 = dig6_x2 % 10;
		int dig4_1 = dig4_x2 / 10 % 10;
		int dig4_2 = dig4_x2 % 10;
		int dig2_1 = dig2_x2 / 10 % 10;
		int dig2_2 = dig2_x2 % 10;
		int dig0_1 = dig0_x2 / 10 % 10;
		int dig0_2 = dig0_x2 % 10;

		int odd_placement = dig6_1 + dig6_2 + dig4_1 + dig4_2 + dig2_1 + dig2_2 + dig0_2 + dig0_1;
		int digit_sum = odd_placement + even_placement_sum;

		int count = 0;  //counts iterations of next for loop
		int temp; // temporary value to be modified
		temp = digit_sum - digits[7];
		for (int i = 1; i <= 9; i++) {
			temp += 1;
			if (temp % 10 == 0) {
				i = 9;
				count--;
			}
			count++;
		}
		count += 1;

		if (digit_sum % 10 == 0) {
			cout << "Number is valid" << endl;
		}
		if (digit_sum % 10 != 0) {
			cout << "Number is not valid" << endl;
			cout << "Check digit should have been " << count << endl;
		}
	}
	return 0;
}