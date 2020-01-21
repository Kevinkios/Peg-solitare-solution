# Peg-solitare-solution
a solution to the chess game peg solitare
Peg solitaire is a traditional game, played with marbles (O) sat on wooden board. The game begins in some known state e.g.:
. . O	. .
. .	O	.	.
O O . O O
. . O . .
. . O . .
The pegs can take another peg by jumping it (as in draughts) going up, down, left or right. For the above board, the next board would look like:

. . . . .
. . . . .
O O O O O
. . O . .
. . O . . 

. . O . .
. . O . .
. . O O O
. . O . .
. . O . .

. . O . .
. . O . .
O O O O O
. . . . .
. . . . .

. . O . .
. . O . .
O O O . .
. . O . .
. . O . .

You are going to read in a 5x5 board and find the correct moves to return it to the completed state:
. . . . .
. . . . .
. . O . .
. . . . .
. . . . .
To do this you will use a list of boards. The initial board is put into this list. Each board in the list is, in turn, read from the list and all possible moves from that board added into the list. The next board is taken, and all its resulting boards are added, and so on. However, one problem with is that repeated boards may be put into the list and ‘cycles’ occur. This soon creates an explosively large number of boards (several million). You can solve this by only adding a board into the list if an identical one has never been put into the list before. Each structure in the list will contain (amongst other things) a board and information allowing its parent board to be identified, i.e. the board that it was created from.
