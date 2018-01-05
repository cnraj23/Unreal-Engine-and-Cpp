#include "FGuessGame.h"

FGuessGame::FGuessGame()
{
	Reset();
}

int FGuessGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FGuessGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FGuessGame::IsGameWon() const
{
	return false;
}

void FGuessGame::Reset()
{
	MyCurrentTry = 1;
	constexpr int MAX_TRIES = 4;
	MyMaxTries = MAX_TRIES;
	return;
}

bool FGuessGame::CheckGuessValidity(std::string)
{
	return false;
}
