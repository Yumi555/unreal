#pragma once
#include <string>

using FString = std::string;
using int32 = int;


// two integers initialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame {
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value
	bool CheckGuessValidity(FString); // TODO make a more rich return value
	FBullCowCount SubmitGuess(FString);
	



// Please try and ignore this  and focus on things above
private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

};
