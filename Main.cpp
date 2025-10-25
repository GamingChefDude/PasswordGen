#include <iostream>
#include <string>
#include <random>

using std::string;
using std::cout;
using std::endl;

string generatePassword(int length) {
	const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()"; // get all possible characters

	std::random_device rd; // obtain a random number from hardware
	std::default_random_engine engine(rd()); // seed the generator
	std::uniform_int_distribution<int> dist(0, characters.size() - 1); // define the range
	
	string password;
	for (int i = 0; i < length; i++) {
		int randomNum = dist(engine); // generate random index
		char randomChar = characters[randomNum]; // get character at random index
		password += randomChar; // append character to password
	}
	return password;
}

int main() {
	// top title
	cout << "--- Password Generator ---" << endl;
	cout << "--------------------------" << endl;

	// get lenght from user 
	int length;
	cout << "Enter the desired password length: ";
	std::cin >> length;

	string password = generatePassword(length);
	cout << password << endl;

	return 0;
}