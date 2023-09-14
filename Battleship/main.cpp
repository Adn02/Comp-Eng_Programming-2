#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <string.h>
#include <time.h>
using namespace std;

int displayBoard (vector<vector<int>> board, int boardSize) {
    //This function displays a visual Battleship board of size boardSize.
    string letterString = "\n   A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    string icons = "-~X";
    cout << letterString.substr(0,3+2*boardSize) << endl << endl;
    for (int i = 0; i < boardSize; i++) {
        cout << i+1;
        if (i < 9) {
            cout << " ";
        }
        cout << " ";
        for (int j = 0; j < boardSize; j++) {
            cout << icons.substr(board[i][j],1) << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> addRandomShip (vector<vector<int>> board, int boardSize, int shipSize) {
    //This function randomly places a "ship" of length shipSize on a 2d vector
    //of size boardSize, treating "ships" as 1s and empy space as 0s. This
    //function also ensures that the ship being placed does not overlap with
    //existing ships. It returns the altered board.

    bool validPlacement;
    int orientation;
    int x;
    int y;
    int i;

    do {
        //Loops until a randomly chosen ship is confirmed as a valid placement.
        validPlacement = true;
        x = rand() % boardSize;
        y = rand() % boardSize;
        orientation = rand() % 2; //0 is horizontal, 1 is vertical

        if (orientation == 0) {
            if ((x + shipSize - 1) > (boardSize - 1)) {
                validPlacement = false;
	        }
        } else {
            if ((y + shipSize - 1) > (boardSize - 1)) {
                validPlacement = false;
	        }
        }
        if (validPlacement == true) {
            if (orientation == 0) {
	            for (i = x; i <= (x + shipSize - 1); i++) {
                    if (board[i][y] == 1 or i >= boardSize) {
                        validPlacement = false;
                    }
                }
            } else {
                for (i = y; i <= (x + shipSize - 1); i++) {
                    if (board[x][i] == 1 or i >= boardSize) {
                        validPlacement = false;
                    }
                }
            }
        }
    } while (validPlacement == false);
    
    if (orientation == 0) {
        for (i = x; i <= (x + shipSize - 1); i++) {
	        board[i][y] = 1;
        }
    } else {
        for (i = y; i <= (y + shipSize - 1); i++) {
            board[x][i] = 1;
	    }
    }
    return board;
}

int main () {
    
    srand(time(0));
    
    int remainingShips;
    int boardSize;
    string input;
    
    cout << "Welcome to Battleship! Please select a difficulty:\n(e)asy\n(m)edium\n(h)ard\n";
    cin >> input;
    switch (input.at (0)) {
        case 'e':
        boardSize = 5;
        break;
    case 'm':
        boardSize = 8;
        break;
    case 'h':
        boardSize = 10;
        break;
    default:
        cout << "\nYou didn't choose a valid difficulty!\n";
    }
    
    //Initialize game data based on difficulty
    vector<vector<int>> board (boardSize, vector<int>(boardSize));
    vector<vector<int>> playerBoard (boardSize, vector<int>(boardSize));
    
    board = addRandomShip(board, boardSize, 2);
    board = addRandomShip(board, boardSize, 3);
    board = addRandomShip(board, boardSize, 4);
    
    do {
        //Main game control loop. Loops until  all ships are destroyed, aka
        //the board is void of 1s.
        cout << "\nInput a location (In the format A1)\n";
        string locationInput;
        
        cin >> locationInput;
        while (locationInput.at(0) < 'A' or locationInput.at(0) > 'Z' or locationInput.at(1) < '0' or locationInput.at(1) > '9') {
            cout << "Invalid syntax. Try again.\n";
            cin >> locationInput;
        }
        
        int locationY = locationInput.at(0)-'A';
        int locationX = stoi(locationInput.substr(1))-1;
        
        playerBoard[locationX][locationY] = 1;
    
        if (board[locationX][locationY] == 1) {
            cout << "\nYou hit a ship!" << endl;
            board[locationX][locationY] = 0;
            playerBoard[locationX][locationY] = 2;
        } else {
            cout << "\nYou missed, Try again." << endl;
        }
        
        displayBoard(playerBoard,  boardSize);
        
        remainingShips = 0;
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if(board[i][j] == 1) {
                    remainingShips++;
                }
            }
        }
    } while (remainingShips > 0);
    
    cout << "You win, You sunk all the battleships!";
  
    return 0;

}



