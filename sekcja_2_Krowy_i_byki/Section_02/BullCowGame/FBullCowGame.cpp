#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() {	Reset(); }

int32 FBullCowGame::GetMaxTries() const {	return MyMaxTries; }
int32 FBullCowGame::GetCurentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


bool FBullCowGame::IsGameWon() const { return bGameIsWon;}



void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	
	MyMaxTries = MAX_TRIES;	   	  
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}




EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; // TODO write function
	}
	else if (false) // if the gues isn't all lowercase 
	{
		return EGuessStatus::Not_Lowercase; // TODO write function
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong 
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{
		return EGuessStatus::OK;
	}

	
		
	// otherwise
		// return OK
}



// recieves a VALID guess, increiments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	

	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLenght = MyHiddenWord.length(); // assuming same lenghth as guess


	// loop through all letters in the hidden word 
	for (int32 MHWChar = 0; MHWChar < WordLenght; MHWChar++) {
		// compare letters agains the guess
		for (int32 GChar = 0; GChar < WordLenght; GChar++) {
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { // if htey're in the same place
					BullCowCount.Bulls++; 	//incriment bulls
				}
				else {
					BullCowCount.Cows++; //must be a cow
				}					
			}
		}
	}
	if (BullCowCount.Bulls == WordLenght) 	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}
