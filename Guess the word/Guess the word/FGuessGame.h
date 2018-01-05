#pragma once
#include<string>

class FGuessGame {
public:
	FGuessGame();

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(std::string);


private:
	// values are initialized in constructor
	int MyCurrentTry;
	int MyMaxTries;
};