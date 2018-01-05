#include<iostream>
#include <string>
#include "FGuessGame.h"


void PrintIntro();
std::string GetGuess();
void PlayGame();
bool AskToPlayAgain();

FGuessGame BCGame;
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
	constexpr int WORD_LEN = 9;
	std::cout << "Welcome to guessing game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LEN <<" letter word I am thinking of? "<<std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int maxTries = BCGame.GetMaxTries();
	
	
	std::cout << "You have total " << maxTries <<" turns to play!!"<< std::endl;
	for (int i=0; i<maxTries; i++)
	{
		std::string Guess = GetGuess(); 
		std::cout << std::endl;
		std::cout << "You guessed: " << Guess << std::endl;
		std::cout<<std::endl;
	}
	// TODO summarise game

}

bool AskToPlayAgain()
{
	std::cout << "do you want to play again? [Yes/No] " << std::endl;
	std::string ur_reply = "";
	getline(std::cin, ur_reply);
	 
	return (ur_reply[0] == 'y') || (ur_reply[0] == 'Y');
}

std::string GetGuess()
{
	std::cout << " Enter Your Guess: ";
	std::string Guess = "";
	getline(std::cin, Guess);
	return Guess;
}
