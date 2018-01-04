#include<iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();
void PlayGame();
bool AskToPlayAgain();

int main()
{
	bool wannaplay = false;
	do 
	{
		PrintIntro();
		PlayGame();
		wannaplay = AskToPlayAgain();
	} while (wannaplay);
	
	return 0;
}

void PrintIntro()
{
	cout << "Welcome to guessing game!" << endl;
	return;
}

void PlayGame()
{
	constexpr int ur_turns = 5;
	cout << "You have total " <<ur_turns<<" turns to play!!"<< endl;
	for (int i=0; i<ur_turns; i++)
	{
		string Guess = GetGuess();
		cout << "You guessed: " << Guess << endl;
		cout<<endl;
	}
}

bool AskToPlayAgain()
{
	cout << "do you want to play again? [Yes/No] " << endl;
	string ur_reply = "";
	getline(cin, ur_reply);
	 
	return (ur_reply[0] == 'y') || (ur_reply[0] == 'Y');
}

string GetGuess()
{
	cout << "Enter Your Guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}
