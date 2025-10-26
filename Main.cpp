#include <iostream>
#include <string>
#include <random>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::cin;

string generatePassword(int length, int amountNumbers, int amountSpecialChars) {
	const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // get all possible characters 
	const string digits = "0123456789"; // get all possible digits
	const string specialChars = "!@#$%^&*()-_=+[]{}|;:',.<>?/"; // get all possible special characters

	std::random_device rd; // obtain a random number from hardware
	std::default_random_engine engine(rd()); // seed the generator
	// difine ranges
	std::uniform_int_distribution<int> totalDist(0, characters.size() - 1); // define the range for total length
	std::uniform_int_distribution<int> digitsDist(0, digits.size() - 1); // define the range for digits
	std::uniform_int_distribution<int> specialDist(0, specialChars.size() - 1); // define the range for special characters

	// generate required numbers
	string numbers = "";
	for (int i = 0; i < amountNumbers; i++) {
		int randomNum = digitsDist(engine); // generate random index for digit
		char randomChar = digits[randomNum]; // get digit at random index
		numbers += randomChar; // append digit to numbers string
	}

	// generate required special characters
	string specialCharacters = "";
	for (int i = 0; i < amountSpecialChars; i++) {
		int randomNum = specialDist(engine); // generate random index for special character
		char randomChar = specialChars[randomNum]; // get special character at random index
		specialCharacters += randomChar; // append special character to specialCharacters string
	}

	length -= numbers.size() + specialCharacters.size(); // get new length after adding required numbers and special characters
	//cout << "Length after numbers: " << length << endl; // debug line

	// generate the rest of the password
	string password = "";
	for (int i = 0; i < length; i++) {
		int randomNum = totalDist(engine); // generate random index
		char randomChar = characters[randomNum]; // get character at random index
		password += randomChar; // append character to password
	}

	password += numbers + specialCharacters; // append numbers and special characters to password
	std::shuffle(password.begin(), password.end(), engine); // shuffle the password to randomize character positions
	return password;
}

int main() {
	// top title
	cout << "--- Password Generator ---" << endl;
	cout << "--------------------------" << endl;

	// get requirements from user 
	int length;
	int numberOfNumbers;
	int numberOfSpecialChars;
	// define min and max length
	int minLength = 6;
	int maxLength = 24;
	// loop until valid length is provided
	for (int i = 0; i < 1; i++) {
		// prompt user for password length
		cout << "Enter the desired password length: ";
		cin >> length;
		// check if length is valid
		if (length < minLength || length > maxLength) {
			// print error message
			if (length < minLength) {
				cout << "Error: Password length must be at least " << minLength << " characters." << endl;
				i--;
			}
			else {
				cout << "Error: Password length must not exceed " << maxLength << " characters." << endl;
				i--;
			}
		}
	}

	for (int i = 0; i < 1; i++) {
		// prompt user for number of digits  
		cout << "Enter the number of digits: ";
		cin >> numberOfNumbers;
		// prompt user for number of special characters
		cout << "Enter the number of special characters: ";
		cin >> numberOfSpecialChars;

		// check if the legnth will have at least one letter
		if (numberOfNumbers + numberOfSpecialChars == length) {
			cout << "Password can not be just numbers and special characters." << endl;
			cout << "Please include at least one letter." << endl;
			i--;
		}
		else if (numberOfNumbers + numberOfSpecialChars > length) {
			cout << "Error: The sum of digits and special characters exceeds the total password length." << endl;
			cout << "Please enter valid amount of numbers and special characters." << endl;
			i--;
		}
	}
	
	// give the generated password to user
	cout << "Password: " << generatePassword(length, numberOfNumbers, numberOfSpecialChars) << endl; // print the generated password

	return 0;
}