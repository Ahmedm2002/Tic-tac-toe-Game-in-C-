#include <iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<ncurses.h>
using namespace std;
class player{
    private: 
        string playerName;
        char playerChar ;
    public: 
        void setName();
        void setChar();
        string showName();
        char showChar();
        int wins = 0;
};
bool charUsed = false;
char currentPlayer = '\0';
void displayboard(char board[][3], int rows);
char checkWinner(char board[][3], int rows);
bool validteInput(int row, int col);
bool checkTie(char board[][3], int rows);
int main() 
{
    const int rows = 3; 
    const int cols = 3;    
    system("clear");
    std::cout<<"\n\t\t*--------------Welcome to the Tic Tac Toe Game--------------*\n";
    char board[rows][cols] = 
    {   
        {'\0', '\0', '\0'},
        {'\0', '\0', '\0'},
        {'\0', '\0', '\0'},
    };   
    player p1, p2;
    std::cout<<"Enter Names of the Players\n";
    std::cout<<"Player 1: ";
    p1.setName();
    p1.setChar();
    std::cout<<"Player 2: ";
    p2.setName();
    p2.setChar();
    system("clear");
    std::cout<<endl;
    char playAgain = 'y';
    cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
    cout << left << setw(15) << "Name" << setw(15) << "Char Allocated" << endl;
    cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
    cout << left << setw(15) << p1.showName() << setw(7) << right << p1.showChar() << endl;
    cout << left << setw(15) << p2.showName() << setw(7) << right << p2.showChar() << endl;
    cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
    cout << endl;
    cout << "Instructions:\n";
    cout << "1. Players will take turns to enter the row and column of their move.\n";
    cout << "2. Rows and columns are numbered from 1 to 3.\n";
    cout << "3. The player who first completes a horizontal, vertical, or diagonal line with their character wins the game.\n";
    cout << "4. The game ends in a tie if all cells are filled, and no player wins.\n";
    cout << "5. Have fun playing Tic Tac Toe!\n\n";
    cout << "Press any character to continue: " << getchar() << endl;
    system("clear");
    do
    {
        currentPlayer = 'X';
        system("clear");
        displayboard(board, rows);
        int i = 0;
        for(; i < 9 ; i++)
        {
            int rInput , cInput;
            if(currentPlayer == 'X')
            {
              std::cout<<"Current Player (X): "<<p1.showName()<<endl;
            }
            else 
            std::cout<<"Current Player (0): "<<p2.showName()<<endl;

            std::cout<<"Enter the move ( Row, Column ): ";
            cin>>rInput>>cInput;
            rInput--;
            cInput--;
            if(validteInput(rInput, cInput))
            {
                if(board[rInput][cInput] == '\0')
                {
                    board[rInput][cInput] = currentPlayer;
                    currentPlayer = (currentPlayer == 'X') ? '0' : 'X';
                    cout<<"this block was executed\n";
                }
                else 
                {
                    std::cout<<"Charcter Already Present\n";
                    std::cout<<"Try Again\n";
                    i--;
                    cout<<currentPlayer<<endl;
                }
                system("clear");
                displayboard(board, rows);
                rInput = -1;
                cInput = -1;
                if( i >= 4)
                {   
                    
                    char winner = checkWinner(board, rows);
                    if(winner != '\0')
                    {   
                        if(winner == 'X')
                        {
                            std::cout<<"Congratulaion !! "<<p1.showName()<<" You have Won The Game\n";
                            p1.wins++;
                        }
                        else 
                        {
                            std::cout<<"Congratulaion !! "<<p2.showName()<<" You have Won The Game\n";
                            p2.wins++;
                        }
                        break;
                    }
                    else if (checkTie(board, rows))
                    {
                        break;
                    }
                } 
            }
            else 
            {
                std::cout<<endl;
                i--;
            }
       }  
        std::cout<<"Do you Want to Play Again (Y/N): \n";
        cin>>playAgain;
        if (playAgain != 'n' || playAgain != 'N')
        {
            for(int i= 0 ; i< rows; i++)
            {
                for(int j =0 ; j< cols; j++)
                {
                    board[i][j] = '\0';
                }
            }
            currentPlayer = 'X';
        }
    } while(playAgain != 'n' && playAgain != 'N');
    std::cout << "\n\n*---------------------Result---------------------*\n\n";
    std::cout << setw(15) << "Name" << setw(10) << "Wins" << endl;
    std::cout << setfill(' ');
    std::cout << setw(25)<<setfill('-');
    std::cout << setfill(' ')<<endl;
    std::cout << setw(15) << p1.showName() << setw(10) << p1.wins << endl;
    std::cout << setw(15) << p2.showName() << setw(10) << p2.wins << endl;
    return 0;
}
void displayboard(char board[][3], int rows) 
{    
    std::cout << "\n";
    for (int i = 0; i < 3; ++i) 
    {
        std::cout<<"\t\t";
        for (int j = 0; j < 3; ++j) 
        {
            if(board[i][j] == '\0')
            {
                std::cout<<i+1<<","<<j+1<<"\t";
            }
            else 
                std::cout<<board[i][j]<< "\t";
        }
        std::cout <<"\n\n";
    }
}
void player::setName()
{
    getline(cin, playerName);
}
void player::setChar()
{
    if(!charUsed)
    {
        playerChar = 'X';
        charUsed = true;
    }
    else 
    playerChar = '0';
}
string player :: showName()
{
    return playerName;
}
char player :: showChar()
{
    return playerChar;
}
char checkWinner(char board[][3], int rows) {
    char winner = '\0';
    for(int i = 0 ; i < 3 ; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '\0') {
            winner = board[i][0];
            break;
        }
    }
    for(int j = 0 ; j < 3 ; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '\0') {
            winner = board[0][j];
            break;
        }
    }   
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '\0')
    {
        winner = board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '\0')
    {
        winner = board[0][2];
    }
    return winner;
}
bool validteInput(int row, int col)
{
    if(row < 0 || row > 3 || col < 0 || col > 3)
    {
        std::cout<<"Invalid Move. Try Again\n";
        return false;
    }
    else 
    return true;
}
bool checkTie(char board[][3], int rows)
{
    for(int i = 0 ; i < rows ; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j] == '\0')
            {
                return false;
            }
        }
    }
    return true;
}