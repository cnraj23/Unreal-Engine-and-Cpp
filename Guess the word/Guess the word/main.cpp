#include<iostream>
#include <string>
#include "FGuessGame.h"

using FText = std::string;
using int32 = int;

void Printintro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

FGuessGame BCGame;

int32 main()
{
	bool wannaplay = false;
	do 
	{
		Printintro();
		PlayGame();

		wannaplay = AskToPlayAgain();
	} while (wannaplay);
	
	return 0;
}

void Printintro()
{
	std::cout << "Welcome to guessing game!" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() <<" letter word I am thinking of? "<<std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 maxTries = BCGame.GetMaxTries();
	
	
	std::cout << "You have total " << maxTries <<" turns to play!!"<< std::endl;
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= maxTries)
	{
		FText Guess = GetGuess(); 
		
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "  Cows = " << BullCowCount.Cows << std::endl;
		std::cout<<std::endl;
	}
	// TODO summarise game
	PrintGameSummary();
	return;
}

bool AskToPlayAgain()
{
	std::cout << "do you want to play again? [Yes/No] " << std::endl;
	FText ur_reply = "";
	getline(std::cin, ur_reply);
	 
	return (ur_reply[0] == 'y') || (ur_reply[0] == 'Y');
}

FText GetGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << ". Enter Your Guess: ";
		
		getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << "letter word \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter word without repeating letters \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter word with lower case \n";
			break;
		default:
			break;

		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
} 

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "You WIN!! " << std::endl;
	}
	else
	{
		std::cout << "You lose!! " << std::endl;
	}
}