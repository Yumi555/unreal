#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() {	Reset(); }

int32 FBullCowGame::GetMaxTries() const {	return MyMaxTries; }
int32 FBullCowGame::GetCurentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";	   	  
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return;
}



bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}


// recieves a VALID guess, increiments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in the guess
	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLenght; i++) {
		// compare letters agains the hidden word
		for (int32 j = 0; j < HiddenWordLenght; j++) {
			//if they match then
			if (Guess[i] == MyHiddenWord[i]) {
				if (i == j) { // if htey're in the same place
					BullCowCount.Bulls++; 	//incriment bulls
				}
				else {
					BullCowCount.Cows++; //incriment cows if
				}					
			}
		}
	}

	return BullCowCount;
}
