#include "menger.h"

/**
 * power - Power function
 * @n: Base
 * @index: Number Power
 *
 * Return: The result
 **/
int power(int n, int index)
{
	if (index > 0)
		return (n * power(n, index - 1));
	return (1);
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Is the level of the Menger Sponge to draw
 *
 * return: Is lower than 0, your function must do nothing
 */
void menger(int level)
{
	int n, row, col, tmpRow, tmpCol, c;

	if (level < 0)
		return;

	if (level == 0)
	{
		putchar(0x23);
		putchar(0xA);
		return;
	}

	n = power(3, level);
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			tmpRow = row;
			tmpCol = col;
			c = '#';
			while (tmpRow || tmpCol)
			{
				if (tmpRow % 3 == 1 && tmpCol % 3 == 1)
					c = ' ';
				tmpRow /= 3;
				tmpCol /= 3;
			}
			putchar(c);
		}
		putchar('\n');
	}
}
