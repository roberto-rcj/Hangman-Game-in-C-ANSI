
/*
 *  TITLE: HANGMAN GAME 
 *  AUTHOR: ROBERTO CAMPOS DOS REIS JUNIOR
 *  DATE: 17/11/2022
 *  VERSION: 1.00.00 
 *  DESCRIPTION: This is a normal Hangman game, that has an external file called 'words.txt'.
 *               inside this file, there are some words used by the program to play the game.
 *               The program automatically, choose an random word to the user guess it.
 *               The player can choose between 3 levels of difficult.
*/


#include "main.h"


char     word[30];        
int      attempts = 5;


int main(void){
	
	printf("\n HAGNMAN GAME \n");
	
	//	addWord();  //uncomment this line to be able to add a new word to your game
	
    randomWord(word);			//raffle a random word from your file "words.txt"
    userGuess(word, attempts);	//routine that contains the game logic for user guess and attempts


}
