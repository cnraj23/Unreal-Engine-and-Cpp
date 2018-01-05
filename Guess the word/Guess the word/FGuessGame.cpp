#include "FGuessGame.h"

FGuessGame::FGuessGame()
{
	Reset();
}

int32 FGuessGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FGuessGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FGuessGame::IsGameWon() const
{
	return bGameIsWon;
}



int32 FGuessGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

void FGuessGame::Reset()
{
	constexpr int32 MAX_TRIES = 4;
	const FString Hidden_Word = "door";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = Hidden_Word;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

FBullCowCount FGuessGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++; // incriment turn number
	FBullCowCount BullCowCount;
	int32 hiddenwrdLen = MyHiddenWord.length();
	

	for (int32 HWChar=0; HWChar<hiddenwrdLen; HWChar++)
	{
		for (int32 GChar = 0; GChar < hiddenwrdLen; GChar++)
		{
			if (Guess[HWChar] == MyHiddenWord[HWChar])
			{
				if (HWChar == GChar) 
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == hiddenwrdLen) 
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

EGuessStatus FGuessGame::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Invalid_Status;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}


	
}
