// Hangman
// The Classic game "Hangman"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

int main()
{
	//Prepearing
	const int MAX_WRONG = 8; // Maximum allowed number of wrongs
	std::vector<std::string>Words; // A selection of words for riddles

	Words.push_back("GUESS");
	Words.push_back("HANGMAN");
	Words.push_back("DIFFICULT");
	Words.push_back("VLADISLAV");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(Words.begin(), Words.end());

	const std::string THE_WORD = Words[0]; //the word to guess
	int WrongTry = 0; // A number of incorrect options

	std::string soFar(THE_WORD.size(), '-'); // The part of the word is open at the moment
	std::string Used = ""; // Already guessed letters

	std::cout << "Welcome to Hangman. Good luck!\n";

	//The main cycle
	while ((WrongTry < MAX_WRONG) && (soFar != THE_WORD))
	{
		std::cout << "\n\nYou have " << (MAX_WRONG - WrongTry);
		std::cout << " incorrect guesses left.\n";
		std::cout << "\nYou've used the folowing letters:\n" << Used << std::endl;
		std::cout << "\nSo far, the word is:\n" << soFar << std::endl;

		char Guess;
		std::cout << "\n\nEnter your guess: ";
		std::cin >> Guess;
		Guess = toupper(Guess); // Convert to upper case

		// Since the hidden word is written in uppercase
	

	while (Used.find(Guess) != std::string::npos)
	{
		std::cout << "\nYou've already guessed " << Guess << std::endl;
		std::cout << "Enter your guess: ";
		std::cin >> Guess;
		Guess = toupper(Guess);
	}

	Used += Guess;

	if (THE_WORD.find(Guess) != std::string::npos)
	{
		std::cout << "That's right! " << Guess << " is in the word.\n";
		// Update variable soFar, include in it the new guessed letter

		for (int i = 0; i < THE_WORD.length(); i++)
		{
			if (THE_WORD[i] == Guess)
			{
				soFar[i] = Guess;
			}
		}
	}
	else
	{
		std::cout << "Sorry, " << Guess << "isn't in the word.\n";
		WrongTry++;
	}
}
	// Finish of the game
	
	if (WrongTry == MAX_WRONG)
	{
		std::cout << "\nYou've been hanged!";
	}
	else
	{
		std::cout << "You guessed it! " << THE_WORD << std::endl;
	}
	std::cout << "\nThe word was " << THE_WORD << std::endl;

	return 0;
}
