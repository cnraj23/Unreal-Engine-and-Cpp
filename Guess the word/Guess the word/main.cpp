#include<iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrint();
void LetsLoop();


int main()
{
	PrintIntro();
	LetsLoop();
	
	return 0;

}

void PrintIntro()
{
	constexpr int ur_turns = 5;
	cout << "Welcome to guessing game!" << endl;

	cout << "can you guess the word of length " << ur_turns << endl;
	return;
}

void LetsLoop()
{
	for (int i=0; i<5; i++)
	{
		GetGuessAndPrint();
		cout<<endl;
	}
}

string GetGuessAndPrint()
{
	

	cout << "Enter Your Guess: ";
	string Guess = "";
	getline(cin, Guess);
	cout << "You guessed: " << Guess << endl;
	return Guess;
}
