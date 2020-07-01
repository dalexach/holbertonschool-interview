#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * go_right - if the case if move to the direction go_right
 * @line: pointer to a first number
 * @size: size of the array
 */
void go_right(int *line, size_t size)
{
	size_t i, j;

	for (i = size; i > 0; i--)
	{
		for (j = i - 1; j > 0; j--)
		{
			if (line[i - 1] != 0)
			{
				if (line[i - 1] == line[j - 1])
				{
					line[i - 1] = line[i - 1] + line[j - 1];
					line[j - 1] = 0;
					break;
				}
				if (line[i - 1] != line[j - 1] &&
				    line[j - 1] != 0)
					break;
			}
			if (line[i - 1] == 0)
			{
				if (line[j - 1] != 0)
				{
					line[i - 1] = line[j - 1];
					line[j - 1] = 0;
					i++;
					break;
				}
			}
		}
	}
}

/**
 * go_left - if the case if move to the direction go_left
 * @line: pointer to a first number
 * @size: size of the array
 */
void go_left(int *line, size_t size)
{
	size_t i, j, p;

	for (i = 0, j = 0; i < size;)
	{
		if (line[i] == 0)
			while (line[i] == 0)
				i++;
		if (i == (size - 1))
			break;

		j = i + 1;
		if (line[j] == 0)
			while (line[j] == 0)
				j++;

		if (line[i] == line[j])
		{
			line[i] = line[i] + line[j];
			line[j] = 0;
			i = j + 1;
		}
		else
			i++;
		j = 0;
	}

	for (i = 0, p = 0; i < size; i++)
		if (line[i] != 0)
			line[p++] = line[i];
	while (p < size)
		line[p++] = 0;
}

/**
 * slide_line - slide & merge it to the go_left or to the go_right
 * @line: pointer to an arrray of int conteining size n
 * @size: Number of elements in line
 * @direction: directions
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == 0)
		go_left(line, size);
	if (direction == 1)
		go_right(line, size);
	return (1);
}
