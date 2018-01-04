#include<iostream>
#include <string>

using namespace std;

void PrintIntro()
{
	constexpr int World_len = 5;
	cout << "Welcome to guessing game!" << endl;
	cout << "can you guess the word of length " << World_len << endl;
	return;
}



int main()
{
	PrintIntro();
	cout << "Enter Your Guess: ";
	string Guess = "";
	getline(cin, Guess);
	cout << "You guessed: " << Guess << endl;

	return 0;

}