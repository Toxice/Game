# Tic-Tac-Toe with Minimax — Programming Assignment

## Objective

Implement a complete Tic-Tac-Toe game in C with an AI opponent using the Minimax algorithm.

You are given a project skeleton with multiple .c and .h files.  
Your task is to complete the missing logic.

⸻

## Constraints

### You must respect the following limitations:  
	•	Use only:  
	•	Arrays  
	•	Pointers  
	•	Functions  
	•	Loops and conditionals  

⸻

### Provided File Structure

	tictactoe/  
	├── main.c        # Game loop (already implemented)  
	├── game.h        # Board API declarations  
	├── game.c        # Board logic (you must complete)  
	├── minimax.h     # Minimax API  
	└── minimax.c     # AI logic (you must complete)  


⸻

## Game Rules
	•	Board is 3 x 3
	•	Human player uses: X
	•	AI uses: O
	•	Players alternate turns  
	•	Input format: two integers → row col (0-based indexing)  

### Example input:

	1 2

	This means: row = 1, column = 2

⸻

## Your Tasks

### Part 1 — Board Management (game.c)

You must implement:

	Function		Purpose 
	init_board		Initialize board with empty cells  
	print_board		Display the board in terminal  
	is_move_valid	Check legality of a move  
	apply_move		Place a symbol (X or O)  
	is_board_full	Detect draw conditions  
	check_winner	Detect a winner  


⸻

## Part 2 — AI Logic (minimax.c)

### You must implement:

    Function	      Purpose  
    minimax           Recursive game tree search  
    find_best_move	  Choose optimal AI move  


You must not use randomness.

Link:  
	https://www.youtube.com/watch?v=l-hh51ncgDI&pp=ygURbWluIG1heCBhbGdvcml0aG0%3D  



⸻

## How the Program Works

### Flow managed by main.c:
	1.	Initialize board  
	2.	Alternate between:  
	    •	Human input  
	    •	AI using find_best_move()  
	3.	Game ends on:  
	    •	Win  
	    •	Draw  

You do NOT need to modify main.c.

⸻

Compilation:

### Create the appropriate Makefile with:
    make all #compile everything
    make run #compile and run the program


⸻

### Execution

	./tictactoe


⸻

### Expected Behavior  
	•	Human enters moves via terminal    
	•	AI always plays optimally  
	•	Game ends correctly:  
	•	Human win  
	•	AI win  
	•	Draw  
⸻

### Bonus (Optional)  
	•	Alpha-Beta pruning  
	•	Move depth tracking (win sooner / lose later)  
	•	Clean board visualization  
	•	4 in a row implementation.
		http://blog.gamesolver.org 

⸻

### Good luck !