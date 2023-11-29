


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string.h>


using namespace std;
//This header file works for the hard game part including all the function for hard game optioin
const int size=4;
int board[size][size];

constexpr int sizeofTile=175;
int previousboard[size][size];
int previouscore;
bool gamelost;
int maxOp, non0Tiles;
int score=0;
int highScore;

void writehighscore()//This function writes the value of a global variable named highScore to a file named “score.tx"
{
    fstream scor("score.txt",ios::in|ios::binary);//It declares a variable of type fstream, which is a class that can both read and write from/to files,It opens the file “score.txt” in binary mode , which means that it will write data to the file

     if(scor.is_open())// calling the is_open member function.If the file was opened successfully, it reads the value of highScore
     {
        scor.read((char*)&highScore,sizeof(highScore));
     }
     else//If the file was not opened successfully, it prints an error message to the standard output using cout
     {
        cout<<"error";
     }

     scor.close();//It closes the file by calling the close member function
}
void holdhighscore(int score)//This function compares the value of a parameter named score with the value stored in a file named “score.txt” and updates the file if score is higher
{
int number;
fstream scor("score.txt",ios::in|ios::binary);
scor.read((char*)&number,sizeof(number));
scor.close();
    if(score>=number)//If score is greater than or equal to number, it It assigns score to number and highScore, which are global variables.
        {  fstream hscore("score.txt",ios::out|ios::binary);
            number=score;
            highScore=number;
            hscore.write((char*)&highScore,sizeof(highScore));
            hscore.close();//writes highscore to the file
        }

}
void saveboard()//This function copies the values of a global 2D array named board and a global variable named score to another global 2D array named previousboard and another global variable named previouscore. It does this by using nested for loops to iterate over each element of board and assign it to previousboard, and then assigning score to previouscore. This function is presumably used to save a snapshot of the game state before making a move.
{

    for(int i=0;i<size;i++)
    {

        for(int j=0;j<size;j++)
        {
            previousboard[i][j]=board[i][j];
        }
    }
    previouscore=score;

}
bool checkpossiblemove()//This function checks if there is any possible move left on the board. It does this by using nested for loops to iterate over each tile on the board and checking if it is empty (has a value of 0) or if it has the same value as any of its adjacent tiles (up, down, left or right). If any of these conditions are true, it returns true, meaning that there is a possible move. If none of these conditions are true for any tile, it returns false, meaning that there is no possible move
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == 0 ||(i > 0 && board[i][j] == board[i - 1][j]) ||
                (i < size - 1 && board[i][j] == board[i + 1][j]) ||
                (j > 0 && board[i][j] == board[i][j - 1]) ||
                (j < size - 1 && board[i][j] == board[i][j + 1]))

            {
                return true;
            }
        }
    }

    return false;
}

void undo()//This function copies the values of previousboard and previouscore back to board and score, effectively undoing the last move. It does this by using nested for loops to iterate over each element of previousboard and assign it to board, and then assigning previouscore to score.
{

    for(int i=0;i<size;i++)
    {

        for(int j=0;j<size;j++)
    {
        if(checkpossiblemove())
       {
           board[i][j]=previousboard[i][j];
       }

    }
    }
    score=previouscore;
}

void savegame()//This function writes the values of board and score to a binary file named “saved.dat”
{
    ofstream saveFile("saved.dat",ios::binary|ios::out);// It opens the file “saved.dat” in binary mode and output mode, writes board and score to it using reinterpret_cast and write member functions, and closes it using close member function
    saveFile.write(reinterpret_cast<char*>(&board),sizeof(board));
    saveFile.write((char*)&score,sizeof(score));
    saveFile.close();
}
int loadgame()//This function reads the values of board and s core from a binary file named “saved.dat”
{
    ifstream loadFile("saved.dat",ios::binary|ios::in);//It opens the file “saved.dat” in binary mode and input mode, reads board and score from it using reinterpret_cast and read member functions, and closes it using close member function. This function is presumably used to resume a saved game state
    loadFile.read(reinterpret_cast<char*>(&board),sizeof(board));
    loadFile.read((char*)&score,sizeof(score));
    loadFile.close();
      for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(board[i][j]!=0)
                return 1;
        }
    }
    return 0;
}
void maxOpForUpDown(int &x, int y, int col)
{
    int freq, diffTiles, mostFreq = 0;
    for (int i = 0; i < size; i++)
    {
        freq = 0;
        diffTiles = 1;
        for (int j = 0; j < size; j++)
        {
            if (board[i][col] == board[j][col])
            {
                freq++;
                if (freq > mostFreq)
                    mostFreq = freq;
            }
            else
            {
                diffTiles++;
            }
        }
    }

    if (y > 3)
    {
        if (mostFreq == 2 && diffTiles == 2&&board[0][col]==board[1][col])
        {
            x = 2;
        }
        else if(mostFreq==4)
        {
            x=2;
        }
        else
        {
            x = 1;
        }
    }
    else if (y > 1)
    {
        x = 1;
    }
}
void maxOpForLeftRi(int &x, int y, int row)
{
    int freq, diffTiles, mostFreq = 0;
    for (int i = 0; i < size; i++)
    {
        freq = 0;
        diffTiles = 1;
        for (int j = 0; j < size; j++)
        {
            if (board[row][i] == board[row][j])
            {
                freq++;
                if (freq > mostFreq)
                  {  mostFreq = freq;}
            }
            else
            {
                diffTiles++;
            }
        }
    }

    if (y > 3)
    {
        if (mostFreq == 2 && diffTiles == 2 && board[row][0]==board[row][1])
        {
            x = 2;
        }
        else if(mostFreq==4)
        {
            x=2;
        }
        else
        {
            x = 1;
        }
    }
    else if (y > 1)
    {
        x = 1;
    }
}
void AddTile()// This function adds a new tile to the board with a random value of either 2 or 4
{
    int row, col;
    do
    {
        row = rand() % size;
        col = rand() % size;
    } while (board[row][col] != 0);
    board[row][col] = (rand() % 2 + 1) * 2;
}
void newGame()//This function starts a new game by resetting the board and adding two new tiles. It does this by using nested for loops to iterate over each tile on the board and setting its value to 0, and then calling the AddTile function twice
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }
    score=0;
    AddTile();
    AddTile();

}
void moveUp()
{
saveboard();


    for (int j = 0; j < size; j++)
    {
        non0Tiles = 0;
        for (int i = 0; i < size; i++)
        {
            if (board[i][j] != 0)
                {non0Tiles++;}
        }
        maxOpForUpDown(maxOp, non0Tiles, j);
        int i = 1;
        while (i < 4)
        {
            if (board[i][j] == 0)
            {
                i++;
                continue;
            }
            if (board[i - 1][j] == 0)
            {
                board[i - 1][j] = board[i][j];
                board[i][j] = 0;
                if (i > 1)
                  {  i--;}
                continue;
            }
            if (board[i - 1][j] == board[i][j] && maxOp > 0)
            {
                board[i - 1][j] *= 2;
                score += (2*board[i][j]);
                board[i][j] = 0;
                maxOp--;
            }
            i++;
        }
    }

    AddTile();
}
void moveDown()
{
saveboard();

    for (int j = 0; j < size; j++)
    {
        non0Tiles = 0;
        for (int i = 0; i < size; i++)
        {
            if (board[i][j] != 0)
              {  non0Tiles++;}
        }
        maxOpForUpDown(maxOp, non0Tiles, j);
        int i = 2;
        while (i >= 0)
        {
            if (board[i][j] == 0)
            {
                i--;
                continue;
            }
            if (board[i + 1][j] == 0)
            {
                board[i + 1][j] = board[i][j];
                board[i][j] = 0;
                if (i < 2)
                  {  i++;}
                continue;
            }
            if (board[i + 1][j] == board[i][j] && maxOp > 0)
            {
                board[i + 1][j] *= 2;
                score += (2*board[i][j]);
                board[i][j] = 0;
                maxOp--;
            }
            i--;
        }
    }

    AddTile();
}
void moveLeft()
{
saveboard();

    for (int i = 0; i < size; i++)
    {
        non0Tiles = 0;
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] != 0)
                {non0Tiles++;}
        }
    maxOpForLeftRi(maxOp, non0Tiles, i);
        int j = 1;
        while (j < 4)
        {
            if (board[i][j] == 0)
            {
                j++;
                continue;
            }
            if (board[i][j - 1] == 0)
            {
                board[i][j - 1] = board[i][j];
                board[i][j] = 0;
                if (j > 1)
                   { j--;}
                continue;
            }
            if (board[i][j - 1] == board[i][j] && maxOp > 0)
            {
                board[i][j - 1] *= 2;
                score += (2*board[i][j]);
                board[i][j] = 0;
                maxOp--;
            }
            j++;
        }
    }

    AddTile();
}
void moveRight()
{saveboard();
    for (int i = 0; i < size; i++)
    {
        non0Tiles = 0;
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] != 0)
               { non0Tiles++;}
        }
        maxOpForLeftRi(maxOp, non0Tiles, i);

        int j = 2;
        while (j >= 0)
        {
            if (board[i][j] == 0)
            {
                j--;
                continue;
            }
            if (board[i][j + 1] == 0)
            {
                board[i][j + 1] = board[i][j];
                board[i][j] = 0;
                if (j < 2)
                   { j++;}
                continue;
            }
            if (board[i][j + 1] == board[i][j] && maxOp > 0)
            {
                board[i][j + 1] *= 2;
                score += (2*board[i][j]);
                board[i][j] = 0;
                maxOp--;
            }
            j--;
        }
    }

    AddTile();
}


bool gameover()//This function checks if the game is over by calling the checkpossiblemove function. If there is no possible move left, it sets a global variable named gamelost to true and returns true, meaning that the game is over. If there is a possible move left, it returns false, meaning that the game is not over
{
    if (!checkpossiblemove())
    {
        gamelost = true;
        return true;
    }

    return false;
}

bool win()
{    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == 2048)

            {
                return true;
            }
        }
    }
    return false;
}







