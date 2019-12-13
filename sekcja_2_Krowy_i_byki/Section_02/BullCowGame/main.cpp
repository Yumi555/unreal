/* This is the console executable, that makes use of the BullCow Class
This acts as the view in a MVC pattern and is responsible for all user
interaction. For game logic see the FBullCowGame class/
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game


// the entry point for our application
int main() 
{
	std::cout << BCGame.GetCurentTry();

	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		//TODO ADD A GAME SUMMARY
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	
	return 0; // exit the application
}


// introduce the game
void PrintIntro() 
{
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	std::cout << MaxTries << std::endl;

	// loop asking for guesses while the game is NOT won
	// and there are still tries remainig
	while ( ! BCGame.IsGameWon() && BCGame.GetCurentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
			   
		// Submint valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	// TODO summarise game
}


// loop continually until the user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";

	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurentTry();
		std::cout << "Try " << CurrentTry << ".Enter your guess: ";		
		std::getline(std::cin, Guess);

		// check status and give feedback
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without reapeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;


		default:
			// assume the guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you wanna play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
	


	return false;
}
