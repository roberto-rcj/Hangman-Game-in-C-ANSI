
	TITLE:		HAGMAN GAME
	AUTHOR:		ROBERTO CAMPOS DOS REIS JUNIOR
	DATE:		22/11/2022
	VERSION:	1.00.00
	LANGUAGEM:	C ANSI
	DESCRIPTION:	This is a normal Hangman game with 3 levels
			of difficulty. the higher the degree of difficulty,
			less attempts you have to guess the correct word.
			The sequence bellow shows the logic of the game:
			
			1 - game starts raffling a random word from the file "words.txt";
			3 - The number of letters is shown on the screen with '-'
			3 - the users press a letter on the keyboard then press ENTER;
			4 - the screen updates with the results:
		
			---->	4.1 - wrong letter reduces in one point the total life;
			
			---->	4.2 - correct letter changes '-' for the correct letter
			
			5 - This routine repeats until the end of game:		
			
			---->	5.1 - the player lost because number of lives finished before guess all letters;
			
			---->	5.2 - the player won because all letters were guessed;
			
			6 - The game over appears on the screen and the game is finished.

	OBSERVATIONS: 	The file 'words.txt' contains all words used in the game.
			The words are organized in lines, one and only one word for each line.
			The first line of the file contains the total number of words! it is important to dont crash the game and logic.
			If you change any word or number of words, be aware to change correctly the number of words in the first line! 
			
