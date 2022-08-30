#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: 3x3 grid to computes
 * @grid2: 3x3 grid to sum
 *
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, res = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
				res = 1;
		}

	while (res == 1)
	{
		if (res == 1)
			print_grid1(grid1);
		res = will_topple(grid1);
	}
}

/**
 * will_topple - Create a toppling round
 * @grid1: 3x3 grid to computes
 *
 * Return: 1 its will topple, 0 otherwise
 */
int will_topple(int grid1[3][3])
{
	int i = 0, j = 0, bol = 0;
	int grid2[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i + 1 < 3)
					grid2[i + 1][j] += 1;
				if (i - 1 >= 0)
					grid2[i - 1][j] += 1;
				if (j + 1 < 3)
					grid2[i][j + 1] += 1;
				if (j - 1 >= 0)
					grid2[i][j - 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
				bol = 1;
		}
	return (bol);
}

/**
 * print_grid1 - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid1(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
