// Agata Wicikowska
// TicTacToe 9x9

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

char tab[9][9], again, winner;
int row, column, player = 'X', AI = 'O', box = 5, move = 0, x = 0, y = 0, win = 0, opt, a, b, c;
int chooseTab[9], i, *box1;


int * minimax(char gracz, int poziom, int x, int y)
{
  int licznik = 0;
  int w,k,i,j;
    int tb1[2]; //krzaczy się
  // sprawdzamy, czy jest wygrana
    srand(time(NULL));
    for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
        if(tab[i+x][j+y] == 0)
        {
            tab[i+x][j+y] = gracz;
            w = i; k = j;  // gdyby by³ remis
            licznik++;     // zliczamy wolne pola

            tab[i+x][j+y] = 0;
            if(tab[i+x][j+y] == 0 && tab[i+x+1][j+y] == 0 && tab[i+x+2][j+y] == 0 && tab[i+x][j+y+1] == 0 && tab[i+x+1][j+y+1] == 0 && tab[i+x+2][j+y+1] == 0 && tab[i+x][j+y+2] == 0 && tab[i+x+1][j+y+2] == 0 && tab[i+x+2][j+y+2] == 0)
            {
                int ax=rand()%3+x,by=rand()%3+y;
                tab[ax][by] = 'O';
                tb1[0]=ax;
                tb1[1]=by;
                return tb1;
            }
            else
            {
                if(!poziom) tab[i+x][j+y] = gracz;
                tb1[i+x,j+y];
                return tb1;
            }
      }

  // sprawdzamy, czy jest remis

  if(licznik == 1)
  {
    if(!poziom) tab[w][k] = gracz;
    return 0;
  }

  // wybieramy najkorzystniejszy ruch dla gracza

  int v;
  int vmax;

  vmax = gracz == 'X' ? 2 : -2;

  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      if(tab[i+x][j+y] == 0)
      {
        if(i+x < 3 && j+y < 3)
            {
                tab[i+x][j+y] = gracz;
                box = 1;
            }
            else if(i+x < 3 && j+y > 2 && j+y < 6)
            {
                tab[i+x][j+y] = gracz;
                box = 2;
            }
            else if(i+x < 3 && j+y > 5 && j+y < 9)
            {
                tab[i+x][j+y] = gracz;
                box = 3;
            }
            else if(i+x > 2 && i+x < 6 && j+y < 3)
            {
                tab[i+x][j+y] = gracz;
                box = 4;
            }
            else if(i+x > 2 && i+x < 6 && j+y > 2 && j+y < 6)
            {
                tab[i+x][j+y] = gracz;
                box = 5;
            }
            else if(i+x > 2 && i+x < 6 && j+y > 5 && j+y < 9)
            {
                tab[i+x][j+y] = gracz;
                box = 6;
            }
            else if(i+x > 5 && i+x < 9 && j+y < 3)
            {
                tab[i+x][j+y] = gracz;
                box = 7;
            }
            else if(i+x > 5 && i+x < 9 && j+y > 2 && j+y < 6)
            {
                tab[i+x][j+y] = gracz;
                box = 8;
            }
            else if(i+x > 5 && i+x < 9 && j+y > 5 && j+y < 9)
            {
                tab[i+x][j+y] = gracz;
                box = 9;
            }
        v = box = minimax('O', poziom + 1,i+x,j+y);
						move = box;
        tab[i+x][j+y] = 0;

        if(((gracz == 'X') && (v < vmax)) || ((gracz == 'O') && (v > vmax)))
        {
          vmax = v; w = i; k = j;
        }
      }

   if(!poziom) tab[w][k] = gracz;

   return vmax;
}
void drawTab()
{
	printf("        TicTacToe 9x9\n\n");
	printf("     0|1|2  3|4|5  6|7|8");
	printf("\n\n");

	for (row = 0; row < 9; row++)
	{
		if (box == 1 && row == 1)
		{
			printf("%d | >", row);
		}
		else if (box == 4 && row == 4)
		{
			printf("%d | >", row);
		}
		else if (box == 7 && row == 7)
		{
			printf("%d | >", row);
		}
		else
		{
			printf("%d |  ", row);
		}

		for (column = 0; column < 9; column++)
		{
			printf("%c", tab[row][column]);
			if (box == 1 && column == 2 && row == 1)
			{
				printf("< ");
			}
			else if (box == 4 && column == 2 && row == 4)
			{
				printf("< ");
			}
			else if (box == 7 && column == 2 && row == 7)
			{
				printf("< ");
			}

			else if (box == 2 && column == 2 && row == 1)
			{
				printf(" >");
			}
			else if (box == 2 && column == 5 && row == 1)
			{
				printf("< ");
			}
			else if (box == 5 && column == 2 && row == 4)
			{
				printf(" >");
			}
			else if (box == 5 && column == 5 && row == 4)
			{
				printf("< ");
			}
			else if (box == 8 && column == 2 && row == 7)
			{
				printf(" >");
			}
			else if (box == 8 && column == 5 && row == 7)
			{
				printf("< ");
			}

			else if (box == 3 && column == 8 && row == 1)
			{
				printf("< ");
			}
			else if (box == 3 && column == 5 && row == 1)
			{
				printf(" >");
			}
			else if (box == 6 && column == 8 && row == 4)
			{
				printf("< ");
			}
			else if (box == 6 && column == 5 && row == 4)
			{
				printf(" >");
			}
			else if (box == 9 && column == 8 && row == 7)
			{
				printf("< ");
			}
			else if (box == 9 && column == 5 && row == 7)
			{
				printf(" >");
			}

			else if (column % 3 == 2)
			{
				printf("  ");
			}
			else
			{
				printf("|");
			}

		}
		printf("\n");
		if (row % 3 == 2)
		{
			printf("\n");
		}
		else
		{
			printf("     -----  -----  -----\n");
		}
	}
	printf("        Choose field:\n            ");
	for (i = 0; i < 9; i++)
	{
		chooseTab[i] = i + 1;
	}
	for (i = 0; i < 9; i++)
	{
		chooseTab[i];
		printf("%d", chooseTab[i]);
		if (i % 3 == 2)
		{
			printf("\n            ");
		}
		else
		{
			printf("|");
		}
	}
	printf("0 - clear\n");

	while (scanf("%d", &move) != 1)
	{
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
	}
	system("cls");
}

void clear()
{
	for (row = 0; row<9; row++)
	{
		for (column = 0; column < 9; column++)
		{
			tab[row][column] = 0;
		}
	}
	win = 0;
	box = 5;
}
void aiMove()
{
	if (move >= 0 && move < 10)
	{
		switch (move)
		{
		case 0:
		{
			clear();
		}
		break;

		case 1:
			switch (box)
			{
			case 1:
			{
				if (tab[0][0] == 0)
				{
					tab[0][0] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';
					}
				}
			}
			break;
			case 2:
			{
				if (tab[0][3] == 0)
				{
					tab[0][3] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}

			}
			break;
			case 3:
			{
				if (tab[0][6] == 0)
				{
					tab[0][6] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[3][0] == 0)
				{
					tab[3][0] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[3][3] == 0)
				{
					tab[3][3] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[3][6] == 0)
				{
					tab[3][6] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[6][0] == 0)
				{
					tab[6][0] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[6][3] == 0)
				{
					tab[6][3] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[6][6] == 0)
				{
					tab[6][6] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 2:
		{
			switch (box)
			{
			case 1:
			{
				if (tab[0][1] == 0)
				{
					tab[0][1] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[0][4] == 0)
				{
					tab[0][4] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[0][7] == 0)
				{
					tab[0][7] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[3][1] == 0)
				{
					tab[3][1] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[3][4] == 0)
				{
					tab[3][4] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[3][7] == 0)
				{
					tab[3][7] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[6][1] == 0)
				{
					tab[6][1] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[6][4] == 0)
				{
					tab[6][4] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[6][7] == 0)
				{
					tab[6][7] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;
		}

		case 3:
			switch (box)
			{
			case 1:
			{
				if (tab[0][2] == 0)
				{
					tab[0][2] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[0][5] == 0)
				{
					tab[0][5] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[0][8] == 0)
				{
					tab[0][8] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[3][2] == 0)
				{
					tab[3][2] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';
					}
				}
			}
			break;
			case 5:
			{
				if (tab[3][5] == 0)
				{
					tab[3][5] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[3][8] == 0)
				{
					tab[3][8] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[6][2] == 0)
				{
					tab[6][2] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[6][5] == 0)
				{
					tab[6][5] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[6][8] == 0)
				{
					tab[6][8] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,0,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 4:
			switch (box)
			{
			case 1:
			{
				if (tab[1][0] == 0)
				{
					tab[1][0] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[1][3] == 0)
				{
					tab[1][3] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[1][6] == 0)
				{
					tab[1][6] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[4][0] == 0)
				{
					tab[4][0] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[4][3] == 0)
				{
					tab[4][3] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[4][6])
				{
					tab[4][6] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[7][0] == 0)
				{
					tab[7][0] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[7][3] == 0)
				{
					tab[7][3] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[7][6] == 0)
				{
					tab[7][6] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 5:
			switch (box)
			{
			case 1:
			{
				if (tab[1][1] == 0)
				{
					tab[1][1] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[1][4] == 0)
				{
					tab[1][4] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[1][7] == 0)
				{
					tab[1][7] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[4][1] == 0)
				{
					tab[4][1] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[4][4] == 0)
				{
					tab[4][4] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[4][7] == 0)
				{
					tab[4][7] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[7][1] == 0)
				{
					tab[7][1] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[7][4] == 0)
				{
					tab[7][4] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[7][7] == 0)
				{
					tab[7][7] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 6:
			switch (box)
			{
			case 1:
			{
				if (tab[1][2] == 0)
				{
					tab[1][2] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[1][5] == 0)
				{
					tab[1][5] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[1][8] == 0)
				{
					tab[1][8] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[4][2] == 0)
				{
					tab[4][2] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[4][5] == 0)
				{
					tab[4][5] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[4][8] == 0)
				{
					tab[4][8] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[7][2] == 0)
				{
					tab[7][2] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[7][5] == 0)
				{
					tab[7][5] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[7][8] == 0)
				{
					tab[7][8] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,3,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 7:
			switch (box)
			{
			case 1:
			{
				if (tab[2][0] == 0)
				{
					tab[2][0] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[2][3] == 0)
				{
					tab[2][3] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[2][6] == 0)
				{
					tab[2][6] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[5][0] == 0)
				{
					tab[5][0] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[5][3] == 0)
				{
					tab[5][3] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[5][6] == 0)
				{
					tab[5][6] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[8][0] == 0)
				{
					tab[8][0] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[8][3] == 0)
				{
					tab[8][3] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[8][6] == 0)
				{
					tab[8][6] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,0);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 8:
			switch (box)
			{
			case 1:
			{
				if (tab[2][1] == 0)
				{
					tab[2][1] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[2][4] == 0)
				{
					tab[2][4] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[2][7] == 0)
				{
					tab[2][7] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[5][1] == 0)
				{
					tab[5][1] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[5][4] == 0)
				{
					tab[5][4] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[5][7] == 0)
				{
					tab[5][7] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[8][1] == 0)
				{
					tab[8][1] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[8][4] == 0)
				{
					tab[8][4] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[8][7] == 0)
				{
					tab[8][7] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,3);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 9:
			switch (box)
			{
			case 1:
			{
				if (tab[2][2] == 0)
				{
					tab[2][2] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[2][5] == 0)
				{
					tab[2][5] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[2][8] == 0)
				{
					tab[2][8] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[5][2] == 0)
				{
					tab[5][2] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[5][5] == 0)
				{
					tab[5][5] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[5][8] == 0)
				{
					tab[5][8] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[8][2] == 0)
				{
					tab[8][2] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }
					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[8][5] == 0)
				{
					tab[8][5] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[8][8] == 0)
				{
					tab[8][8] = player;
					box = move;
					if (player == 'X')
					{
						box1 = minimax('O',0,6,6);
						if (*(box1+0) == 0 && *(box1+1) == 0)
                        {
                            box = 1;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 1)
                        {
                            box = 2;
                        }
						else if (*(box1+0) == 0 && *(box1+1) == 2)
                        {
                            box = 3;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 0)
                        {
                            box = 4;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 1)
                        {
                            box = 5;
                        }
						else if (*(box1+0) == 1 && *(box1+1) == 2)
                        {
                            box = 6;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 0)
                        {
                            box = 7;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 1)
                        {
                            box = 8;
                        }
						else if (*(box1+0) == 2 && *(box1+1) == 2)
                        {
                            box = 9;
                        }

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
		break;
		}
	}
}

void inputMove()
{
	if (move >= 0 && move < 10)
	{
		switch (move)
		{
		case 0:
		{
			clear();
		}
		break;

		case 1:
			switch (box)
			{
			case 1:
			{
				if (tab[0][0] == 0)
				{
					tab[0][0] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[0][3] == 0)
				{
					tab[0][3] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';
					}
					else
					{
						player = 'X';

					}
				}

			}
			break;
			case 3:
			{
				if (tab[0][6] == 0)
				{
					tab[0][6] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[3][0] == 0)
				{
					tab[3][0] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[3][3] == 0)
				{
					tab[3][3] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[3][6] == 0)
				{
					tab[3][6] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[6][0] == 0)
				{
					tab[6][0] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[6][3] == 0)
				{
					tab[6][3] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[6][6] == 0)
				{
					tab[6][6] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 2:
		{
			switch (box)
			{
			case 1:
			{
				if (tab[0][1] == 0)
				{
					tab[0][1] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[0][4] == 0)
				{
					tab[0][4] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[0][7] == 0)
				{
					tab[0][7] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[3][1] == 0)
				{
					tab[3][1] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[3][4] == 0)
				{
					tab[3][4] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[3][7] == 0)
				{
					tab[3][7] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[6][1] == 0)
				{
					tab[6][1] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[6][4] == 0)
				{
					tab[6][4] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[6][7] == 0)
				{
					tab[6][7] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;
		}

		case 3:
			switch (box)
			{
			case 1:
			{
				if (tab[0][2] == 0)
				{
					tab[0][2] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[0][5] == 0)
				{
					tab[0][5] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[0][8] == 0)
				{
					tab[0][8] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[3][2] == 0)
				{
					tab[3][2] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';
					}
					else
					{
						player = 'X';
					}
				}
			}
			break;
			case 5:
			{
				if (tab[3][5] == 0)
				{
					tab[3][5] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[3][8] == 0)
				{
					tab[3][8] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[6][2] == 0)
				{
					tab[6][2] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[6][5] == 0)
				{
					tab[6][5] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[6][8] == 0)
				{
					tab[6][8] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 4:
			switch (box)
			{
			case 1:
			{
				if (tab[1][0] == 0)
				{
					tab[1][0] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[1][3] == 0)
				{
					tab[1][3] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[1][6] == 0)
				{
					tab[1][6] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[4][0] == 0)
				{
					tab[4][0] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[4][3] == 0)
				{
					tab[4][3] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[4][6])
				{
					tab[4][6] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[7][0] == 0)
				{
					tab[7][0] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[7][3] == 0)
				{
					tab[7][3] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[7][6] == 0)
				{
					tab[7][6] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 5:
			switch (box)
			{
			case 1:
			{
				if (tab[1][1] == 0)
				{
					tab[1][1] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[1][4] == 0)
				{
					tab[1][4] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[1][7] == 0)
				{
					tab[1][7] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[4][1] == 0)
				{
					tab[4][1] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[4][4] == 0)
				{
					tab[4][4] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[4][7] == 0)
				{
					tab[4][7] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[7][1] == 0)
				{
					tab[7][1] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[7][4] == 0)
				{
					tab[7][4] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[7][7] == 0)
				{
					tab[7][7] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 6:
			switch (box)
			{
			case 1:
			{
				if (tab[1][2] == 0)
				{
					tab[1][2] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[1][5] == 0)
				{
					tab[1][5] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[1][8] == 0)
				{
					tab[1][8] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[4][2] == 0)
				{
					tab[4][2] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[4][5] == 0)
				{
					tab[4][5] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[4][8] == 0)
				{
					tab[4][8] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[7][2] == 0)
				{
					tab[7][2] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[7][5] == 0)
				{
					tab[7][5] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[7][8] == 0)
				{
					tab[7][8] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 7:
			switch (box)
			{
			case 1:
			{
				if (tab[2][0] == 0)
				{
					tab[2][0] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[2][3] == 0)
				{
					tab[2][3] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[2][6] == 0)
				{
					tab[2][6] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[5][0] == 0)
				{
					tab[5][0] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[5][3] == 0)
				{
					tab[5][3] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[5][6] == 0)
				{
					tab[5][6] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[8][0] == 0)
				{
					tab[8][0] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[8][3] == 0)
				{
					tab[8][3] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[8][6] == 0)
				{
					tab[8][6] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 8:
			switch (box)
			{
			case 1:
			{
				if (tab[2][1] == 0)
				{
					tab[2][1] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[2][4] == 0)
				{
					tab[2][4] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[2][7] == 0)
				{
					tab[2][7] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[5][1] == 0)
				{
					tab[5][1] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[5][4] == 0)
				{
					tab[5][4] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[5][7] == 0)
				{
					tab[5][7] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[8][1] == 0)
				{
					tab[8][1] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[8][4] == 0)
				{
					tab[8][4] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[8][7] == 0)
				{
					tab[8][7] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
			break;

		case 9:
			switch (box)
			{
			case 1:
			{
				if (tab[2][2] == 0)
				{
					tab[2][2] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 2:
			{
				if (tab[2][5] == 0)
				{
					tab[2][5] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 3:
			{
				if (tab[2][8] == 0)
				{
					tab[2][8] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 4:
			{
				if (tab[5][2] == 0)
				{
					tab[5][2] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 5:
			{
				if (tab[5][5] == 0)
				{
					tab[5][5] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 6:
			{
				if (tab[5][8] == 0)
				{
					tab[5][8] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 7:
			{
				if (tab[8][2] == 0)
				{
					tab[8][2] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 8:
			{
				if (tab[8][5] == 0)
				{
					tab[8][5] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			case 9:
			{
				if (tab[8][8] == 0)
				{
					tab[8][8] = player;
					box = move;
					if (player == 'X')
					{
						player = 'O';

					}
					else
					{
						player = 'X';

					}
				}
			}
			break;
			}
		break;
		}
	}
}

void checkwin()
{
	if (box == 1)
	{
		x = 0;
		y = 0;
		if (tab[y + 0][x + 0] == tab[y + 0][x + 1] && tab[y + 0][x + 1] == tab[y + 0][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 1][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 1][x + 2] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 1][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 1][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 2][x + 1] && tab[y + 2][x + 1] == tab[y + 2][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 0] && tab[y + 1][x + 0] == tab[y + 2][x + 0] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 2][x + 0] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 0][x + 1] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 1] && tab[y + 0][x + 1] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 1] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 1];
		}

		else if (tab[y + 0][x + 2] == tab[y + 1][x + 2] && tab[y + 1][x + 2] == tab[y + 2][x + 2] && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 2] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 2];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 0][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}
		else if (tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 3;
		}
		else
		{
			win = 4;
		}
	}

	if (box == 2)
	{
		x = 3;
		y = 0;
		if (tab[y + 0][x + 0] == tab[y + 0][x + 1] && tab[y + 0][x + 1] == tab[y + 0][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 1][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 1][x + 2] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 1][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 1][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 2][x + 1] && tab[y + 2][x + 1] == tab[y + 2][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 0] && tab[y + 1][x + 0] == tab[y + 2][x + 0] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 2][x + 0] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 0][x + 1] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 1] && tab[y + 0][x + 1] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 1] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 1];
		}

		else if (tab[y + 0][x + 2] == tab[y + 1][x + 2] && tab[y + 1][x + 2] == tab[y + 2][x + 2] && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 2] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 2];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 0][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}
		else if (tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 3;
		}
		else
		{
			win = 4;
		}
	}

	if (box == 3)
	{
		x = 6;
		y = 0;
		if (tab[y + 0][x + 0] == tab[y + 0][x + 1] && tab[y + 0][x + 1] == tab[y + 0][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 1][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 1][x + 2] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 1][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 1][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 2][x + 1] && tab[y + 2][x + 1] == tab[y + 2][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 0] && tab[y + 1][x + 0] == tab[y + 2][x + 0] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 2][x + 0] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 0][x + 1] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 1] && tab[y + 0][x + 1] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 1] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 1];
		}

		else if (tab[y + 0][x + 2] == tab[y + 1][x + 2] && tab[y + 1][x + 2] == tab[y + 2][x + 2] && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 2] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 2];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 0][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}
		else if (tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 3;
		}
		else
		{
			win = 4;
		}
	}

	if (box == 4)
	{
		x = 0;
		y = 3;
		if (tab[y + 0][x + 0] == tab[y + 0][x + 1] && tab[y + 0][x + 1] == tab[y + 0][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 1][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 1][x + 2] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 1][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 1][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 2][x + 1] && tab[y + 2][x + 1] == tab[y + 2][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 0] && tab[y + 1][x + 0] == tab[y + 2][x + 0] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 2][x + 0] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 0][x + 1] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 1] && tab[y + 0][x + 1] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 1] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 1];
		}

		else if (tab[y + 0][x + 2] == tab[y + 1][x + 2] && tab[y + 1][x + 2] == tab[y + 2][x + 2] && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 2] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 2];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 0][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}
		else if (tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 3;
		}
		else
		{
			win = 4;
		}
	}

	if (box == 5)
	{
		x = 3;
		y = 3;
		if (tab[y + 0][x + 0] == tab[y + 0][x + 1] && tab[y + 0][x + 1] == tab[y + 0][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 1][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 1][x + 2] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 1][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 1][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 2][x + 1] && tab[y + 2][x + 1] == tab[y + 2][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 0] && tab[y + 1][x + 0] == tab[y + 2][x + 0] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 2][x + 0] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 0][x + 1] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 1] && tab[y + 0][x + 1] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 1] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 1];
		}

		else if (tab[y + 0][x + 2] == tab[y + 1][x + 2] && tab[y + 1][x + 2] == tab[y + 2][x + 2] && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 2] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 2];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 0][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}
		else if (tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 3;
		}
		else
		{
			win = 4;
		}
	}

	if (box == 6)
	{
		x = 6;
		y = 3;
		if (tab[y + 0][x + 0] == tab[y + 0][x + 1] && tab[y + 0][x + 1] == tab[y + 0][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 1][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 1][x + 2] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 1][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 1][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 2][x + 1] && tab[y + 2][x + 1] == tab[y + 2][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 0] && tab[y + 1][x + 0] == tab[y + 2][x + 0] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 2][x + 0] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 0][x + 1] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 1] && tab[y + 0][x + 1] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 1] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 1];
		}

		else if (tab[y + 0][x + 2] == tab[y + 1][x + 2] && tab[y + 1][x + 2] == tab[y + 2][x + 2] && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 2] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 2];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 0][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}
		else if (tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 3;
		}
		else
		{
			win = 4;
		}
	}

	if (box == 7)
	{
		x = 0;
		y = 6;
		if (tab[y + 0][x + 0] == tab[y + 0][x + 1] && tab[y + 0][x + 1] == tab[y + 0][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 1][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 1][x + 2] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 1][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 1][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 2][x + 1] && tab[y + 2][x + 1] == tab[y + 2][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 0] && tab[y + 1][x + 0] == tab[y + 2][x + 0] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 2][x + 0] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 0][x + 1] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 1] && tab[y + 0][x + 1] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 1] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 1];
		}

		else if (tab[y + 0][x + 2] == tab[y + 1][x + 2] && tab[y + 1][x + 2] == tab[y + 2][x + 2] && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 2] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 2];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 0][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}
		else if (tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 3;
		}
		else
		{
			win = 4;
		}
	}

	if (box == 8)
	{
		x = 3;
		y = 6;
		if (tab[y + 0][x + 0] == tab[y + 0][x + 1] && tab[y + 0][x + 1] == tab[y + 0][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 1][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 1][x + 2] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 1][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 1][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 2][x + 1] && tab[y + 2][x + 1] == tab[y + 2][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 0] && tab[y + 1][x + 0] == tab[y + 2][x + 0] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 2][x + 0] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 0][x + 1] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 1] && tab[y + 0][x + 1] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 1] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 1];
		}

		else if (tab[y + 0][x + 2] == tab[y + 1][x + 2] && tab[y + 1][x + 2] == tab[y + 2][x + 2] && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 2] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 2];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 0][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}
		else if (tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 3;
		}
		else
		{
			win = 4;
		}
	}

	if (box == 9)
	{
		x = 6;
		y = 6;
		if (tab[y + 0][x + 0] == tab[y + 0][x + 1] && tab[y + 0][x + 1] == tab[y + 0][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 1][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 1][x + 2] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 1][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 1][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 2][x + 1] && tab[y + 2][x + 1] == tab[y + 2][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 0] && tab[y + 1][x + 0] == tab[y + 2][x + 0] && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 2][x + 0] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 0][x + 1] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 1] && tab[y + 0][x + 1] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 1] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 1];
		}

		else if (tab[y + 0][x + 2] == tab[y + 1][x + 2] && tab[y + 1][x + 2] == tab[y + 2][x + 2] && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 2] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 2];
		}

		else if (tab[y + 0][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 2][x + 2] && tab[y + 0][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 0][x + 0];
		}

		else if (tab[y + 2][x + 0] == tab[y + 1][x + 1] && tab[y + 1][x + 1] == tab[y + 0][x + 2] && tab[y + 2][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 0][x + 2] != 0)
		{
			win = 1;
			winner=tab[y + 2][x + 0];
		}
		else if (tab[y + 0][x + 0] != 0 && tab[y + 0][x + 1] != 0 && tab[y + 0][x + 2] != 0 && tab[y + 1][x + 0] != 0 && tab[y + 1][x + 1] != 0 && tab[y + 1][x + 2] != 0 && tab[y + 2][x + 0] != 0 && tab[y + 2][x + 1] != 0 && tab[y + 2][x + 2] != 0)
		{
			win = 3;
		}
		else
		{
			win = 4;
		}
	}

	if (win == 1)
	{
		printf("%c win!\n",winner);
	}
	else if (win == 3)
	{
		printf("Draw!\n");
	}
}

void playAgain()
{
	if (win == 1 && win != 4)
	{
		printf("Play again?\ny/n\n");
		scanf("%s", &again);
		switch (again)
		{
		case 'y':
		{
			system("cls");
			clear();
		}
		break;
		case 'n':
		{
			exit(0);
		}
		break;
		default:
		{
			printf("Wrong! Write y/n\n");
		}
		break;
		}
	}
}

int main()
{
    printf("New game:\n1 - Player vs. Player\n2 - Player vs. Computer\n");
    scanf("%d", &opt);
	system("cls");
    if(opt == 1)
    {
        while (1)
        {
            drawTab();
            inputMove();
            checkwin();
            playAgain();
        }
    }
    else if(opt == 2)
    {
        while (1)
        {
            drawTab();
            aiMove();
            checkwin();
            playAgain();
        }
    }
    else
    {
        printf("Only 1 or 2\n");
    }
	system("PAUSE");
	return 0;
}
