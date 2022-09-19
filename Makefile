tictactoe : tictactoe.o printBoard.o CheckForWinner.o
	g++ -o tictactoe tictactoe.o printBoard.o CheckForWinner.o

printBoard.o : printBoard.cpp tictactoe.h
	g++ -c printBoard.cpp 

CheckForWinner.o : CheckForWinner.cpp tictactoe.h
	g++ -c CheckForWinner.cpp

tictactoe.o : tictactoe.cpp 
	g++ -c tictactoe.cpp 

clean:
	rm *.o output