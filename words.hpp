#include <string>
#include <iostream>

using namespace std;

// used caesar cipher to encrypt and decrypt words
//  6 letters up

#ifndef WORDS
#define WORDS

string word1 = "nkrru";      // hello
string word2 = "cuxrj";      // world
string word3 = "muujhek";    // goodbye
string word4 = "yayvktyout"; // suspension
string word5 = "ixoiqkz";    // cricket
string word6 = "zomkx";      // tiger
string word7 = "jurvnot";    // dolphin
string word8 = "krkvngtz";   // elefant
string word9 = "qgtmgxuu";   // kangaroo
string word10 = "fkhxg";     // zebra

string words[10] = {word1, word2, word3, word4, word5, word6, word7, word8, word9, word10};

string decodeWord(string word)
{
    string decodedWord = "";
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] < 'a' + 6)
        {
            decodedWord += ('z' - 6) + (word[i] - 'a') + 1;
        }
        else
        {
            decodedWord += word[i] - 6;
        }
    }

    return decodedWord;
};

string getRandomWord()
{
    srand(time(0));
    int random = rand() % 10;
    return decodeWord(words[random]);
}

#endif