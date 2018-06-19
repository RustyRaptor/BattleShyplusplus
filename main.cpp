#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>



int i, j;
int turn;
const int X = 100; // X size of game board
const int Y = 100; // Y size
char board[X][Y];
int Xlen = sizeof(board)/sizeof(*board);
int Ylen = sizeof(board[0])/sizeof(*board[0]);
int shipRow;
int shipCol;
int guessRow;
int guessCol;



void createBoard(int xsize, int ysize) {
        for ( i = 0; i < xsize; i++ ) { // outer loop iterates rows
                for ( j = 0; j < ysize; j++ ) { // inner loop iterates cols
                        board[i][j] = '0';
                }
        }
}


void printBoard(auto board) {
        // display the matrix
        for ( i = 0; i < X; i++ ) {
                for ( j = 0; j < Y; j++ ) {
                std::cout << board[i][j] << " ";
                }
                std::cout << std::endl;
        }
}

int randomCol(int col){
        srand ( time(0));
        return std::rand() %col;
}

int randomRow(int row){
        srand ( time(0));
        return std::rand() %row;
}

int main(int argc, char *argv[])
{
        QCoreApplication a(argc, argv);

        std::cout << sizeof(board)/sizeof(*board) << std::endl;
        std::cout << "Loading coordinates..." << std::endl;
        createBoard(X, Y);
        std::cout << "Loading ship data..." << std::endl;
        shipRow = randomRow(Xlen);
        shipCol = randomCol(Ylen);
        std::cout << "Let's play Battleship!" << std::endl;
        printBoard(board);

        for(turn = 0; turn < 100000; turn++) {
                srand ( time(0));
                guessRow = randomRow(Xlen);
                srand ( time(0));
                guessCol = randomCol(Ylen);

                // if the player hits...
                if((guessRow == shipRow) && (guessCol == shipCol)) {
                        std::cout << "Target neutralized!" << std::endl;
                        // we turn the "0" into "+" when the player hits
                        board[guessRow][guessCol] = '+';
                        break;
                }

                else{
                        // if the player picks a location off the grid...
                        if ((guessRow < 0 || guessRow >= X) ||
                                        (guessCol < 0 || guessCol >= X)){
                                std::cout << "Coordinates undefined!"
                                          << std::endl;
                        }
                        // else if the player strikes a previously hit location.
                        else if (board[guessRow][guessCol] == 'X'){
                                std::cout << "Coordinates already hit!"
                                          << std::endl;
                                printBoard(board);
                        }
                        else{
                            std::cout << "Target missed!" << std::endl;
                            // we turn the "0" into an "X" when we miss
                            board[guessRow][guessCol] = 'X';

                        }
                        // This is the turn system.
                        std::cout << "Turn: " << turn + 1 << std::endl;
                }
                if (turn == 8){
                        std::cout << "Defeat!" << std::endl;
                        std::cout << "The target location was: "
                                  << shipRow << "," << shipCol
                                  << std::endl;
                }
                printBoard(board);
        }

        return a.exec();
}







//# prompt player to set difficulty
//difficulty = raw_input('Set difficulty. Must be 1, 2, or 3:')


//# check if the input was a number
//def checkifdigit(dif):
//    while not dif.isdigit():
//        dif = raw_input('That\'s not a number. Please enter a number 1, 2, or 3:')
//    return dif


//# check if the input number was in the correct range
//def checkrange(dif):
//    while int(dif) > 3 or int(dif) < 0:
//        dif = raw_input('That number is too high or too low please pick a number 1, 2, or 3:')
//    return dif


//difficulty = checkifdigit(difficulty)
//difficulty = checkrange(difficulty)

//# here is where the settings for each difficulty is set.
//if difficulty == '1':
//    for x in range(3):
//        board.append(['O'] * 3)
//    a = 3
//elif difficulty == '2':
//    for x in range(5):
//        board.append(['0'] * 5)
//    a = 5
//elif difficulty == '3':
//    for x in range(7):
//        board.append(['0'] * 7)
//    a = 7


//# This function will allow us to generate a random coordinate for the ship's location
//def random_row(board):
//    return randint(0, len(board) - 1)





