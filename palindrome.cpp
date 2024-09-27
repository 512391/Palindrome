/*
  author: Jay Williamson
  date: 9/4/2024
  this program tells whether or not a certain text is palindromic(same backwords and forwards)
 */

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//checks if the character array is palindromic
bool isPalindrome(char characterArray[], int lastIndex)
{
  
  for(int i =0; i < lastIndex/2; i++)
    {
      cout << characterArray[i] << ", " << characterArray[lastIndex-i] << "\n";

      //checks if the 2 characters that are the equidistant from either end are the same
      if(characterArray[i] != characterArray[lastIndex-i])
	{ 
	  return false;
	}
    }

  return true;
}

int main()
{
  char wordArray[80];
  char unpunctuatedWordArray[80];

  //clears the array
  for(int i = 0; i < sizeof(wordArray)-1; i++)
    {
      wordArray[i] = (char)-1;
    }

  //gets input
  cout << "enter a string to see if it is palindromic \n";
  cin.getline(wordArray, sizeof(wordArray));

  int currentIndexInUnpunctuated = 0;

  //regulates the array
  for(int i = 0; i < sizeof(wordArray)-1; i++)
    {
      //checks if the spot is emptu
      if((int)wordArray[i] != -1)
	{
	  //makes uppercase lowercase and puts it in the array
	  if((int)wordArray[i] > 64 && (int)wordArray[i] < 91)
	    {
	      wordArray[i] = tolower(wordArray[i]);

	      unpunctuatedWordArray[currentIndexInUnpunctuated] = wordArray[i];
	      currentIndexInUnpunctuated++;
	    }//puts lowercase in the array
	  else if((int)wordArray[i] > 96 && (int)wordArray[i] < 123)
	    {
	      unpunctuatedWordArray[currentIndexInUnpunctuated] = wordArray[i];
	      currentIndexInUnpunctuated++;
	    }
	}
    }
  
  currentIndexInUnpunctuated--;

  //checks if it is palindromic
  if(isPalindrome(unpunctuatedWordArray, currentIndexInUnpunctuated))
    {
      cout << "it is palindromic";
    }
  else
    {
      cout << "it is not palindromic";
    }
}
