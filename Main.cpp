#include <iostream>
#include <string>
#include <random>

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
	// prompt user for password length
	cout << "Enter the desired password length: ";
	cin >> length;
	// prompt user for number of digits
	cout << "Enter the number of digits: ";
	cin >> numberOfNumbers;
	// prompt user for number of special characters
	cout << "Enter the number of special characters: ";
	cin >> numberOfSpecialChars;

	cout << "Password: " << generatePassword(length, numberOfNumbers, numberOfSpecialChars) << endl; // print the generated password

	return 0;
}