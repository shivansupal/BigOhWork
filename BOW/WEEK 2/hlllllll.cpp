#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

char playerName[30];
int userSymbol, computerSymbol, gameCount = 0;
int board[3][3];

void displayBoard() {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0)
                cout << ".\t";
            else if (board[i][j] == userSymbol)
                cout << "X\t";
            else
                cout << "O\t";
        }
        cout << endl;
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }

    if ((board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;

    return false;
}

void playerInput() {
    int row, col;
    cout << "Enter row: ";
    cin >> row;
    cout << "Enter column: ";
    cin >> col;

    row--;
    col--;

    if (row > 2 || col > 2 || row < 0 || col < 0 || board[row][col] != 0) {
        cout << "Invalid move. Try again.\n";
        playerInput();
    } else {
        board[row][col] = userSymbol;
    }
}

int defend(int board[3][3], int symbol, int opponentSymbol, int moveCount) {
    if (moveCount < 3)
        return 0;

    for (int i = 0; i < 3; i++) {
        if (board[i][0] + board[i][1] + board[i][2] == 2 * symbol && board[i][0] != opponentSymbol && board[i][1] != opponentSymbol && board[i][2] != opponentSymbol) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = computerSymbol;
                    cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                    return 1;
                }
            }
        } else if (board[0][i] + board[1][i] + board[2][i] == 2 * symbol && board[0][i] != opponentSymbol && board[1][i] != opponentSymbol && board[2][i] != opponentSymbol) {
            for (int j = 0; j < 3; j++) {
                if (board[j][i] == 0) {
                    board[j][i] = computerSymbol;
                    cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                    return 1;
                }
            }
        }
    }

    if (board[0][0] + board[1][1] + board[2][2] == 2 * symbol && board[0][0] != opponentSymbol && board[1][1] != opponentSymbol && board[2][2] != opponentSymbol) {
        for (int i = 0; i < 3; i++) {
            if (board[i][i] == 0) {
                board[i][i] = computerSymbol;
                cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                return 1;
            }
        }
    } else if (board[0][2] + board[1][1] + board[2][0] == 2 * symbol && board[0][2] != opponentSymbol && board[1][1] != opponentSymbol && board[2][0] != opponentSymbol) {
        for (int i = 0; i < 3; i++) {
            if (board[i][2 - i] == 0) {
                board[i][2 - i] = computerSymbol;
                cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                return 1;
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] + board[i][1] + board[i][2] == 2 * symbol && board[i][0] != opponentSymbol && board[i][1] != opponentSymbol && board[i][2] != opponentSymbol) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 0) {
                        board[i][j] = computerSymbol;
                        cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                        return 1;
                    }
                }
            } else if (board[0][i] + board[1][i] + board[2][i] == 2 * symbol && board[0][i] != opponentSymbol && board[1][i] != opponentSymbol && board[2][i] != opponentSymbol) {
                for (int j = 0; j < 3; j++) {
                    if (board[j][i] == 0) {
                        board[j][i] = computerSymbol;
                        cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int attack(int board[3][3]) {
    int i, j;

    if (board[0][0] + board[0][2] + board[2][0] + board[2][2] == userSymbol + computerSymbol || board[0][0] + board[0][2] + board[2][0] + board[2][2] == userSymbol + 2 * computerSymbol) {
        for (i = 0; i < 3; i++) {
            if (board[i][0] + board[i][1] + board[i][2] == computerSymbol && (board[i][0] == computerSymbol || board[i][1] == computerSymbol || board[i][2] == computerSymbol)) {
                if (i == 1) {
                    for (j = 0; j < 3; j++) {
                        if (board[i][j] == 0) {
                            board[i][j] = computerSymbol;
                            cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                            return 1;
                        }
                    }
                } else {
                    for (j = 2; j >= 0; j--) {
                        if (board[i][j] == 0) {
                            board[i][j] = computerSymbol;
                            cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                            return 1;
                        }
                    }
                }
            }

            if (board[0][i] + board[1][i] + board[2][i] == computerSymbol && (board[0][i] == computerSymbol || board[1][i] == computerSymbol || board[2][i] == computerSymbol)) {
                if (i == 1) {
                    for (j = 0; j < 3; j++) {
                        if (board[j][i] == 0) {
                            board[j][i] = computerSymbol;
                            cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                            return 1;
                        }
                    }
                } else {
                    for (j = 2; j >= 0; j--) {
                        if (board[j][i] == 0) {
                            board[j][i] = computerSymbol;
                            cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                            return 1;
                        }
                    }
                }
            }
        }

        if (board[0][0] + board[1][1] + board[2][2] == computerSymbol && (board[0][0] == computerSymbol || board[1][1] == computerSymbol || board[2][2] == computerSymbol)) {
            for (i = 2; i >= 0; i--) {
                if ((board[i][i] == 0) && ((board[i][0] + board[i][1] + board[i][2] == computerSymbol && (board[i][0] == computerSymbol || board[i][1] == computerSymbol || board[i][2] == computerSymbol)) || ((board[0][i] + board[1][i] + board[2][i] == computerSymbol) && (board[0][i] == computerSymbol || board[1][i] == computerSymbol || board[2][i] == computerSymbol)))) {
                    board[i][i] = computerSymbol;
                    cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                    return 1;
                }
            }
            for (i = 2; i >= 0; i--) {
                if (board[i][i] == 0) {
                    if ((board[i][0] + board[i][1] + board[i][2] == userSymbol && (board[i][0] == userSymbol || board[i][1] == userSymbol || board[i][2] == userSymbol)) && (board[0][i] + board[1][i] + board[2][i] == userSymbol && (board[0][i] == userSymbol || board[1][i] == userSymbol || board[2][i] == userSymbol))) {
                        board[i][i] = computerSymbol;
                        cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                        return 1;
                    }
                }
            }

            for (i = 2; i >= 0; i--) {
                if (board[i][i] == 0) {
                    board[i][i] = computerSymbol;
                    cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                    return 1;
                }
            }
        } else if (board[0][2] + board[1][1] + board[2][0] == computerSymbol && (board[0][2] == computerSymbol || board[1][1] == computerSymbol || board[2][0] == computerSymbol)) {
            for (i = 2; i >= 0; i--) {
                if (board[i][2 - i] == 0 && ((board[i][0] + board[i][1] + board[i][2] == computerSymbol && (board[i][0] == computerSymbol || board[i][1] == computerSymbol || board[i][2] == computerSymbol)) || ((board[0][2 - i] + board[1][2 - i] + board[2][2 - i] == computerSymbol) && (board[0][2 - i] == computerSymbol || board[1][2 - i] == computerSymbol || board[2][2 - i] == computerSymbol)))) {
                    board[i][2 - i] = computerSymbol;
                    cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                    return 1;
                }
            }

            for (i = 2; i >= 0; i--) {
                if (board[i][2 - i] == 0) {
                    if ((board[i][0] + board[i][1] + board[i][2] == userSymbol && (board[i][0] == userSymbol || board[i][1] == userSymbol || board[i][2] == userSymbol)) && (board[0][2 - i] + board[1][2 - i] + board[2][2 - i] == userSymbol && (board[0][2 - i] == userSymbol || board[1][2 - i] == userSymbol || board[2][2 - i] == userSymbol))) {
                        board[i][2 - i] = computerSymbol;
                        cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                        return 1;
                    }
                }
            }

            for (i = 2; i >= 0; i--) {
                if (board[i][2 - i] == 0) {
                    board[i][2 - i] = computerSymbol;
                    cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                    return 1;
                }
            }
        }
    }
    return 0;
}

void computerMove(int board[3][3], int turn) {
    int moveCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 0)
                moveCount++;
        }
    }

    if (defend(board, computerSymbol, userSymbol, moveCount))
        return;
    else if (defend(board, userSymbol, computerSymbol, moveCount))
        return;
    else if (attack(board))
        return;

    if (moveCount < 3) {
        while (1) {
            int i = rand() % 3;
            int j = rand() % 3;

            if (board[i][j] == 0) {
                board[i][j] = computerSymbol;
                cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }

    int i = rand() % 3;
    int j = rand() % 3;

    while (board[i][j] != 0) {
        i = rand() % 3;
        j = rand() % 3;
    }

    board[i][j] = computerSymbol;
    cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
}

void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
}

void playGame() {
    resetBoard();
    displayBoard();
    int turn = 1;

    while (1) {
        if (turn % 2 != 0)
            playerInput();
        else
            computerMove(board, turn);

        displayBoard();

        if (checkWin()) {
            if (turn % 2 != 0) {
                cout << playerName << " wins!\n";
            } else {
                cout << "Computer wins!\n";
            }
            gameCount++;
            break;
        } else if (turn == 9) {
            cout << "It's a draw!\n";
            gameCount++;
            break;
        }

        turn++;
    }
}

int main() {
    srand(time(0));

    cout << "Enter your name: ";
    cin.getline(playerName, 30);

    cout << "Choose your symbol (1 for X, 2 for O): ";
    cin >> userSymbol;

    if (userSymbol == 1)
        computerSymbol = 2;
    else
        computerSymbol = 1;

    while (1) {
        playGame();
        cout << "Do you want to play again? (1 for yes, 0 for no): ";
        int choice;
        cin >> choice;
        if (choice == 0) {
            cout << "Thanks for playing! You played " << gameCount << " games.\n";
            break;
        }
    }

    return 0;
}
