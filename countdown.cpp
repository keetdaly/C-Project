// countdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include "stdlib.h"
#include "time.h"



void pickLetters(char c, int i, char letters[]);
void readFile(char letters[], char userWord[]);


int main()
{	

	char letters[11]; //store random characters from user
	char userWord[10]; //store users input
	int i; //counter
	char c; //to pick consonant or vowel
	int check = 1; //so game can be repeated
	do
	{
		srand(time(NULL));
		for (i = 0; i < 9; i++)
		{
			printf("Please enter a character\n");
			printf("Enter v for a vowel and c for a consonant ");
			printf("\n");
			fflush(stdin);
			scanf_s("\n%c", &c);
			printf("\n");
			
			pickLetters(c, i, letters);
		}

		for (i = 0; i < 9; i++)
		{
			printf("%c", letters[i]);
		}
		printf("\n");

		printf("Enter the longest word you can find!\n");
		fflush(stdin);
		scanf("\n%s", userWord); //had a bug when using scanf_s here for some reason, scanf fixed it
		

		readFile(letters, userWord);
		
		printf("Would you like to play again?\n");
		printf("Enter 1 to play again, 0 to exit\n");
		scanf_s("\n%d", &check);
	} while (check == 1);
	
	return 0;
}

void pickLetters(char c, int i, char letters[])
{

	int d;

	//based on letter frequencies from wikipedia
	if (c == 'v')
	{
		d = rand() % 38100;
		if (d <= 8167)
		{
			letters[i] = 'a';
		}
		if (d > 8167 && d <= 20869)
		{
			letters[i] = 'e';
		}
		if (d > 20869 && d <= 27835)
		{
			letters[i] = 'i';
		}
		if (d > 27835 && d <= 35342)
		{
			letters[i] = 'o';
		}
		if (d > 35342 && d <= 38100)
		{
			letters[i] = 'u';
		}
		


	}

	else if (c == 'c')
	{
		d = rand() % 61900;
		if (d <= 1492)
		{
			letters[i] = 'b';
		}
		else if (d <= 4274)
		{
			letters[i] = 'c';
		}
		else if (d <= 8527)
		{
			letters[i] = 'd';
		}
		else if (d <= 10755)
		{
			letters[i] = 'f';
		}
		else if (d <= 12770)
		{
			letters[i] = 'g';
		}
		else if (d <= 18864)
		{
			letters[i] = 'h';
		}
		else if (d <= 19017)
		{
			letters[i] = 'j';
		}
		else if (d <= 19789)
		{
			letters[i] = 'k';
		}
		else if (d <= 23814)
		{
			letters[i] = 'l';
		}
		else if (d <= 26220)
		{
			letters[i] = 'm';
		}
		else if (d <= 32969)
		{
			letters[i] = 'n';
		}
		else if (d <= 34898)
		{
			letters[i] = 'p';
		}
		else if (d <= 34993)
		{
			letters[i] = 'q';
		}
		else if (d <= 40980)
		{
			letters[i] = 'r';
		}
		else if (d <= 47307)
		{
			letters[i] = 's';
		}
		else if (d <= 56363)
		{
			letters[i] = 't';
		}
		else if (d <= 57341)
		{
			letters[i] = 'v';
		}
		else if (d <= 59702)
		{
			letters[i] = 'w';
		}
		else if (d <= 59852)
		{
			letters[i] = 'x';
		}
		else if (d <= 61826)
		{
			letters[i] = 'y';
		}
		else if (d <= 61900)
		{
			letters[i] = 'z';
		}
	}
	else
	{
		printf("Why must you make me put in all these error checkers\n");
		printf("You're a silly moo did you know that?\n");
		printf("Just pick c or v please \n");
		fflush(stdin);
		scanf_s("\n%c", &c);
		pickLetters(c, i, letters);
	}
}



void readFile(char letters[], char userWord[])
{
	FILE *fptr;

	char wordTemp[10];
	char word[9];
	char lettersTemp[11]; 
	int i; //counters
	int j;
	int charCheck;
	

	fptr = fopen("C:\\Users\\keith\\Desktop\\webster.txt", "r");
	if (fptr == NULL)
	{
		printf("Error opening file!\n");
		return;
	}

	while (!feof(fptr))
	{
		fscanf(fptr, "%s", word);
		letters[9] = '\0'; //had a bug where garbage characters appeared after last character, this line fixed it 
		strcpy(lettersTemp, letters);
	
		charCheck = 0;
		
		for (i = 0; i < strlen(word); i++)
		{
			for (j = 0; j < strlen(lettersTemp); j++)
			{
				
				if (word[i] == lettersTemp[j])
				{
					
					lettersTemp[j] = 'A'; //so letters aren't repeated
					charCheck++;
					
					break;
				}
			}
		}
		
		if (charCheck == strlen(word) && strlen(word) > 5)
		{
			printf("We have a potential word!\n");
			printf("Word is %s\n", word);
		}
		if (strcmp(word, userWord) == 0)
		{
			strcpy(wordTemp, word);
		}
		
		
	}
	if (strlen(wordTemp) > 1)
	{
		printf("You got the word %s! You get %d points!\n", wordTemp, strlen(wordTemp));
	}
}


