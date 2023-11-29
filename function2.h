#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string.h>

using namespace std;

const int size2 = 5;
int board2[size2][size2];

constexpr int sizeofTile2=140;
int previousboard2[size2][size2];
int previouscore2;
bool gamelost2;
int maxOp2, non0Tiles2;
int score2=0;
int highScore2;

void writehighscore2()
{
    fstream scor("score2.txt",ios::in|ios::binary|ios::app);

     if(scor.is_open())
     {
        scor.read((char*)&highScore2,sizeof(highScore2));
     }
     else
     {
        cout<<"error";
     }

     scor.close();
}
void holdhighscore2(int score)
{
int number;
fstream scor("score2.txt",ios::in|ios::binary);
scor.read((char*)&number,sizeof(number));
scor.close();


    if(score>=number)
        {  fstream hscore("score2.txt",ios::out|ios::binary);
            number=score;
            highScore2=number;
            hscore.write((char*)&highScore2,sizeof(highScore2));hscore.close();
        }

}
void saveboard2()
{

    for(int i=0;i<size2;i++)
    {

        for(int j=0;j<size2;j++)
        {
            previousboard2[i][j]=board2[i][j];
        }
    }
    previouscore2=score2;

}
bool checkpossiblemove2()
{
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (board2[i][j] == 0 ||(i > 0 && board2[i][j] == board2[i - 1][j]) ||
                (i < size2 - 1 && board2[i][j] == board2[i + 1][j]) ||
                (j > 0 && board2[i][j] == board2[i][j - 1]) ||
                (j < size2 - 1 && board2[i][j] == board2[i][j + 1]))

            {
                return true;
            }
        }
    }

    return false;
}

void undo2()
{

    for(int i=0;i<size2;i++)
    {

        for(int j=0;j<size2;j++)
    {
        if(checkpossiblemove2())
        {
            board2[i][j]=previousboard2[i][j];
        }


    }
    }
    score2=previouscore2;
}

void savegame2()
{
    ofstream saveFile("saved2.dat",ios::binary|ios::out);
    saveFile.write(reinterpret_cast<char*>(&board2),sizeof(board2));
    saveFile.write((char*)&score2,sizeof(score2));
    saveFile.close();
}
int loadgame2()
{
    ifstream loadFile("saved2.dat",ios::binary|ios::in);
    loadFile.read(reinterpret_cast<char*>(&board2),sizeof(board2));
    loadFile.read((char*)&score2,sizeof(score2));
    loadFile.close();
      for(int i=0;i<size2;i++){
        for(int j=0;j<size2;j++){
            if(board2[i][j]!=0)
                return 1;
        }
    }
    return 0;
}
void maxOpForUpDown2(int &x, int y, int col)
{
    int freq, diffTiles, mostFreq = 0;
    for (int i = 0; i < size2; i++)
    {
        freq = 0;
        diffTiles = 1;
        for (int j = 0; j < size2; j++)
        {
            if (board2[i][col] == board2[j][col])
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
        if (mostFreq >= 2 && diffTiles >= 2&&y>4&& board2[0][col]==board2[1][col])
        {
            x = 2;
        }
        else if(mostFreq>=4||(diffTiles==2&&y==4))
        {
            x=2;
        } else if(mostFreq==2&&diffTiles==2){
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
void maxOpForLeftRi2(int &x, int y, int row)
{
    int freq, diffTiles, mostFreq = 0;
    for (int i = 0; i < size2; i++)
    {
        freq = 0;
        diffTiles = 1;
        for (int j = 0; j < size2; j++)
        {
            if (board2[row][i] == board2[row][j])
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
        if (mostFreq > 2 && diffTiles >= 2&&y>=4 && board2[row][0]==board2[row][1])
        {
            x = 2;
        }
        else if(mostFreq>=4||(diffTiles==2&&y==4))
        {
            x=2;
        }
        else if(mostFreq==2&&diffTiles==2){
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
void AddTile2()
{
    int row, col;
    do
    {
        row = rand() % size2;
        col = rand() % size2;
    } while (board2[row][col] != 0);
    board2[row][col] = (rand() % 2 + 1) * 2;
}
void newGame2()
{score2=0;
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            board2[i][j] = 0;
        }
    }

    AddTile2();
    AddTile2();
}
void moveUp2()
{
saveboard2();


    for (int j = 0; j < size2; j++)
    {
        non0Tiles2 = 0;
        for (int i = 0; i < size2; i++)
        {
            if (board2[i][j] != 0)
                {non0Tiles2++;}
        }
        maxOpForUpDown2(maxOp2, non0Tiles2, j);
        int i = 1;
        while (i < size2)
        {
            if (board2[i][j] == 0)
            {
                i++;
                continue;
            }
            if (board2[i - 1][j] == 0)
            {
                board2[i - 1][j] = board2[i][j];
                board2[i][j] = 0;
                if (i > 1)
                  {  i--;}
                continue;
            }
            if (board2[i - 1][j] == board2[i][j] && maxOp2 > 0)
            {
                board2[i - 1][j] *= 2;
                score2 += (2*board2[i][j]);
                board2[i][j] = 0;
                maxOp2--;
            }
            i++;
        }
    }

    AddTile2();
}
void moveDown2()
{
saveboard2();

    for (int j = 0; j < size2; j++)
    {
        non0Tiles2 = 0;
        for (int i = 0; i < size2; i++)
        {
            if (board2[i][j] != 0)
              {  non0Tiles2++;}
        }
        maxOpForUpDown2(maxOp2, non0Tiles2, j);
        int i = 3;
        while (i >= 0)
        {
            if (board2[i][j] == 0)
            {
                i--;
                continue;
            }
            if (board2[i + 1][j] == 0)
            {
                board2[i + 1][j] = board2[i][j];
                board2[i][j] = 0;
                if (i < 3)
                  {  i++;}
                continue;
            }
            if (board2[i + 1][j] == board2[i][j] && maxOp2 > 0)
            {
                board2[i + 1][j] *= 2;
                score2 += (2*board2[i][j]);
                board2[i][j] = 0;
                maxOp2--;
            }
            i--;
        }
    }

    AddTile2();
}
void moveLeft2()
{
saveboard2();

    for (int i = 0; i < size2; i++)
    {
        non0Tiles2 = 0;
        for (int j = 0; j < size2; j++)
        {
            if (board2[i][j] != 0)
                {non0Tiles2++;}
        }
    maxOpForLeftRi2(maxOp2, non0Tiles2, i);
        int j = 1;
        while (j < size2)
        {
            if (board2[i][j] == 0)
            {
                j++;
                continue;
            }
            if (board2[i][j - 1] == 0)
            {
                board2[i][j - 1] = board2[i][j];
                board2[i][j] = 0;
                if (j > 1)
                   { j--;}
                continue;
            }
            if (board2[i][j - 1] == board2[i][j] && maxOp2 > 0)
            {
                board2[i][j - 1] *= 2;
                score2 += (2*board2[i][j]);
                board2[i][j] = 0;
                maxOp2--;
            }
            j++;
        }
    }

    AddTile2();
}
void moveRight2()
{saveboard2();
    for (int i = 0; i < size2; i++)
    {
        non0Tiles2 = 0;
        for (int j = 0; j < size2; j++)
        {
            if (board2[i][j] != 0)
               { non0Tiles2++;}
        }
        maxOpForLeftRi2(maxOp2, non0Tiles2, i);

        int j = 3;
        while (j >= 0)
        {
            if (board2[i][j] == 0)
            {
                j--;
                continue;
            }
            if (board2[i][j + 1] == 0)
            {
                board2[i][j + 1] = board2[i][j];
                board2[i][j] = 0;
                if (j < 3)
                   { j++;}
                continue;
            }
            if (board2[i][j + 1] == board2[i][j] && maxOp2 > 0)
            {
                board2[i][j + 1] *= 2;
                score2 += (2*board2[i][j]);
                board2[i][j] = 0;
                maxOp2--;
            }
            j--;
        }
    }

    AddTile2();
}



bool gameover2()
{
    if (!checkpossiblemove2())
    {
        gamelost2 = true;
        return true;
    }

    return false;
}
bool win2()
{    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (board2[i][j] == 2048)

            {
                return true;
            }
        }
    }
    return false;
}
