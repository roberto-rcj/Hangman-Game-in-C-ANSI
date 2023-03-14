
#include"main.h"

/**************************************************************************************************************************************/
void randomWord(char* secretWord)
{
	//local variables
    int aux;
    int numberOfWords = 0;
    int randNumber = 0;
	
	//open the file words.txt and verify errors
    FILE* f; 
    f = fopen("words.txt", "r");    
    if(!f) 
    {
        printf(" ERROR, FILE NOT FOUND ");
        exit(1);
    } 

	//search on the first line of file, the total number of words and create a random number to choose a new random word
    fscanf(f, "%d", &numberOfWords);    
    srand(time(0));
    randNumber = rand() % numberOfWords; 

	
    for(aux = 0; aux < randNumber; aux++){  
        fscanf(f, "%s", secretWord);            
    }

    fclose(f);  //close the file
}

/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
void userGuess(char* secretWord, int attempts)  //routine that contains the logic of the game and users attempts control
{
	int i = 0;
	bool foundLetter = false;
	char letter, auxString[strlen(secretWord)];
	
	//fill the auxiliary string with the character '-' and shows on the screen
	for(i = 0; i < strlen(secretWord); i++)
	{
		auxString[i] = '-';
		printf(" %c ", auxString[i]);
	} 

	//repet this code until the user winnig or losing the game
	do
	{
		printf(" \n Choose a letter \n");
		printf(" Total lives: %d  \n\n", attempts);
		scanf(" %c", &letter); //user enter a letter

		//scan for all string seeking for the user´s letter
		for(i = 0; i < strlen(secretWord); i++)
		{
			//if the letter is found, store the letter, print on the screen that charactere and change the flag
			if(secretWord[i] == letter)
			{
				printf(" %c ", letter);
				auxString[i] = letter;
				foundLetter = true;
			}
			//else, print the charactere
			else
			{
				printf(" %c ", auxString[i]);	
			}
		}
		//after the process of string scanning, if no one letter is found, attempts are decremented
		if(!foundLetter)
			{
				attempts--;
			}
		foundLetter = false; //restart the flag
		
	}while((attempts > 0) && (strcmp(auxString, secretWord))); //do this action until the number of attempts reaches zero or finding the string
	
	//after the end of process, shows on the screen the result
	if(attempts == 0)
	{
		loserDraw();
	}
	
	else
	{
		winnerDraw();
	}	
}
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/
void addWord(void)
{
	//local variables
	int aux;
    int numberOfWords = 0;
    char newWord[30];
    
    //clear screen, ask for user a new word then capture it
    system("cls");		
    printf("\n Write a new word\n");
    gets(newWord);
    system("cls");
    
    //open the file words.txt and verify errors
	FILE* f; 
    f = fopen("words.txt", "r+");    
    if(!f) 
    {
        printf(" ERROR, FILE NOT FOUND ");
        exit(1);
    } 
    
    //scan the first line of file that contains the total number of words
    fscanf(f,"%d", &numberOfWords);   
    
    //add +1 to te total number of words and change it
    numberOfWords++;
    fseek(f, 0, SEEK_SET);
    fprintf(f,"%d", numberOfWords);
    
    //go to the end of file and add the new word at the last position
    fseek(f, 0, SEEK_END);
    fprintf(f,"%s", newWord);
    
    //close the file
    fclose(f);   
}
