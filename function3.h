#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string.h>
using namespace std;
const int size3 = 6;
int board3[size3][size3];
constexpr int sizeofTile3=116;
int previousboard3[size3][size3];
int previouscore3;
bool gamelost3;
int maxOp3, non0Tiles3;
int score3=0;
int highScore3;

void writehighscore3()
{
    fstream scor("score3.txt",ios::in|ios::binary);

     if(scor.is_open())
     {
        scor.read((char*)&highScore3,sizeof(highScore3));
     }
     else
     {
        cout<<"error";
     }

     scor.close();
}
void holdhighscore3(int score3)
{
int number;
fstream scor("score3.txt",ios::in|ios::binary);
scor.read((char*)&number,sizeof(number));
scor.close();


    if(score3>=number)
        {  fstream hscore("score3.txt",ios::out|ios::binary);
            number=score3;
            highScore3=number;
            hscore.write((char*)&highScore3,sizeof(highScore3));
            hscore.close();
        }

}
void saveboard3()
{

    for(int i=0;i<size3;i++)
    {

        for(int j=0;j<size3;j++)
        {
            previousboard3[i][j]=board3[i][j];
        }
    }
    previouscore3=score3;

}
bool checkpossiblemove3()
{
    for (int i = 0; i < size3; i++)
    {
        for (int j = 0; j < size3; j++)
        {
            if (board3[i][j] == 0 ||(i > 0 && board3[i][j] == board3[i - 1][j]) ||
                (i < size3 - 1 && board3[i][j] == board3[i + 1][j]) ||
                (j > 0 && board3[i][j] == board3[i][j - 1]) ||
                (j < size3 - 1 && board3[i][j] == board3[i][j + 1]))

            {
                return true;
            }
        }
    }

    return false;
}

void undo3()
{

    for(int i=0;i<size3;i++)
    {

        for(int j=0;j<size3;j++)
    {
        if(checkpossiblemove3())
        {board3[i][j]=previousboard3[i][j];}

    }
    }
    score3=previouscore3;
}

void savegame3()
{
    ofstream saveFile("saved3.dat",ios::binary|ios::out);
    saveFile.write(reinterpret_cast<char*>(&board3),sizeof(board3));
    saveFile.write((char*)&score3,sizeof(score3));
    saveFile.close();
}
int loadgame3()
{
    ifstream loadFile("saved3.dat",ios::binary|ios::in);
    loadFile.read(reinterpret_cast<char*>(&board3),sizeof(board3));
    loadFile.read((char*)&score3,sizeof(score3));
    loadFile.close();
    for(int i=0;i<size3;i++){
        for(int j=0;j<size3;j++){
            if(board3[i][j]!=0)
                return 1;
        }
    }
    return 0;
}
void maxOpForUpDown3(int &x, int y, int col)
{
    int freq, diffTiles, mostFreq = 0;
    for (int i = 0; i < size3; i++)
    {
        freq = 0;
        diffTiles = 1;
        for (int j = 0; j < size3; j++)
        {
            if (board3[i][col] == board3[j][col])
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
         if (mostFreq >= 2 && diffTiles >= 2&&board3[0][col]==board3[1][col]&&y>5)
        {
            x = 3;
        }
        else if(mostFreq>=2&&diffTiles>=2)
        {
            x=2;
        }
    }
    else if (y <= 3)
    {
        x = 1;
    }
}
void maxOpForLeftRi3(int &x, int y, int row)
{
    int freq, diffTiles, mostFreq = 0;
    for (int i = 0; i < size3; i++)
    {
        freq = 0;
        diffTiles = 1;
        for (int j = 0; j < size3; j++)
        {
            if (board3[row][i] == board3[row][j])
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

        if (mostFreq >= 2 && diffTiles >= 2&&board3[row][0]==board3[row][1]&&y>5)
        {
            x = 3;
        }
        else if(mostFreq>=2&&diffTiles>=2)
        {
            x=2;
        }

    }
    else if (y > 1)
    {
        x = 1;
    }
}
void AddTile3()
{
    int row, col;
    do
    {
        row = rand() % size3;
        col = rand() % size3;
    } while (board3[row][col] != 0);
    board3[row][col] = (rand() % 2 + 1) * 2;
}
void newGame3()
{
    for (int i = 0; i < size3; i++)
    {
        for (int j = 0; j < size3; j++)
        {
            board3[i][j] = 0;
        }
    }
    score3=0;
    AddTile3();
    AddTile3();
}
void moveUp3()
{
saveboard3();


    for (int j = 0; j < size3; j++)
    {
        non0Tiles3 = 0;
        for (int i = 0; i < size3; i++)
        {
            if (board3[i][j] != 0)
                {non0Tiles3++;}
        }
        maxOpForUpDown3(maxOp3, non0Tiles3, j);
        int i = 1;
        while (i < size3)
        {
            if (board3[i][j] == 0)
            {
                i++;
                continue;
            }
            if (board3[i - 1][j] == 0)
            {
                board3[i - 1][j] = board3[i][j];
                board3[i][j] = 0;
                if (i > 1)
                  {  i--;}
                continue;
            }
            if (board3[i - 1][j] == board3[i][j] && maxOp3 > 0)
            {
                board3[i - 1][j] *= 2;
                score3 += (2*board3[i][j]);
                board3[i][j] = 0;
                maxOp3--;
            }
            i++;
        }
    }

    AddTile3();
}
void moveDown3()
{
saveboard3();

    for (int j = 0; j < size3; j++)
    {
        non0Tiles3 = 0;
        for (int i = 0; i < size3; i++)
        {
            if (board3[i][j] != 0)
              {  non0Tiles3++;}
        }
        maxOpForUpDown3(maxOp3, non0Tiles3, j);
        int i = 4;
        while (i >= 0)
        {
            if (board3[i][j] == 0)
            {
                i--;
                continue;
            }
            if (board3[i + 1][j] == 0)
            {
                board3[i + 1][j] = board3[i][j];
                board3[i][j] = 0;
                if (i < 4)
                  {  i++;}
                continue;
            }
            if (board3[i + 1][j] == board3[i][j] && maxOp3 > 0)
            {
                board3[i + 1][j] *= 2;
                score3 += (2*board3[i][j]);
                board3[i][j] = 0;
                maxOp3--;
            }
            i--;
        }
    }

    AddTile3();
}
void moveLeft3()
{
saveboard3();

    for (int i = 0; i < size3; i++)
    {
        non0Tiles3 = 0;
        for (int j = 0; j < size3; j++)
        {
            if (board3[i][j] != 0)
                {non0Tiles3++;}
        }
    maxOpForLeftRi3(maxOp3, non0Tiles3, i);
        int j = 1;
        while (j < size3)
        {
            if (board3[i][j] == 0)
            {
                j++;
                continue;
            }
            if (board3[i][j - 1] == 0)
            {
                board3[i][j - 1] = board3[i][j];
                board3[i][j] = 0;
                if (j > 1)
                   { j--;}
                continue;
            }
            if (board3[i][j - 1] == board3[i][j] && maxOp3 > 0)
            {
                board3[i][j - 1] *= 2;
                score3 += (2*board3[i][j]);
                board3[i][j] = 0;
                maxOp3--;
            }
            j++;
        }
    }

    AddTile3();
}
void moveRight3()
{saveboard3();
    for (int i = 0; i < size3; i++)
    {
        non0Tiles3= 0;
        for (int j = 0; j < size3; j++)
        {
            if (board3[i][j] != 0)
               { non0Tiles3++;}
        }
        maxOpForLeftRi3(maxOp3, non0Tiles3, i);

        int j = 4;
        while (j >= 0)
        {
            if (board3[i][j] == 0)
            {
                j--;
                continue;
            }
            if (board3[i][j + 1] == 0)
            {
                board3[i][j + 1] = board3[i][j];
                board3[i][j] = 0;
                if (j < 4)
                   { j++;}
                continue;
            }
            if (board3[i][j + 1] == board3[i][j] && maxOp3 > 0)
            {
                board3[i][j + 1] *= 2;
                score3 += (2*board3[i][j]);
                board3[i][j] = 0;
                maxOp3--;
            }
            j--;
        }
    }

    AddTile3();
}



bool gameover3()
{
    if (!checkpossiblemove3())
    {
        gamelost3 = true;
        return true;
    }

    return false;
}

