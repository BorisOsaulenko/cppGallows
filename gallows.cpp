#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "./words.hpp"

class GallowsGame
{
private:
    std::string secretWord;
    std::vector<char> guessedLetters;
    std::set<char> triedLetters;
    int maxTries;
    int currentTries;

public:
    GallowsGame(std::string word, int max) : secretWord(word), maxTries(max), currentTries(0)
    {
        guessedLetters = std::vector<char>(secretWord.length(), '_');
        triedLetters = std::set<char>();
    }

    void displayGuessedWord()
    {
        for (char letter : guessedLetters)
        {
            std::cout << letter << " ";
        }
        std::cout << std::endl;
    }

    bool isWordGuessed()
    {
        return secretWord == std::string(guessedLetters.begin(), guessedLetters.end());
    }

    bool guessLetter(char letter)
    {
        // check if letter is uppercase
        if (letter > 'A' && letter < 'Z')
        {
            letter = letter - 32;
        };

        if (triedLetters.find(letter) != triedLetters.end())
        {
            std::cout << "You already mentioned that letter." << std::endl;
            return false;
        };

        triedLetters.insert(letter);

        if (secretWord.find(letter) != std::string::npos)
        {
            for (int i = 0; i < secretWord.length(); i++)
            {
                if (secretWord[i] == letter)
                {
                    guessedLetters[i] = letter;
                }
            }
            return true;
        }

        currentTries++;
        return false;
    }

    int getCurrentTries()
    {
        return currentTries;
    };

    bool isGameOver()
    {
        return currentTries >= maxTries || isWordGuessed();
    }
};

int main()
{

    std::string word = getRandomWord();
    int maxTries = 6;

    GallowsGame game(word, maxTries);

    while (!game.isGameOver())
    {
        std::cout << "Current Word: ";
        game.displayGuessedWord();

        char guess;
        std::cout << "Guess a letter: ";
        std::cin >> guess;

        if (!game.guessLetter(guess))
        {
            std::cout << "Incorrect guess. Tries left: " << maxTries - game.getCurrentTries() << std::endl;
        }
    }

    if (game.isWordGuessed())
    {
        std::cout << "Congratulations! You guessed the word." << std::endl;
    }
    else
    {
        std::cout << "Out of tries. The word was: " << word << std::endl;
    }

    return 0;
}