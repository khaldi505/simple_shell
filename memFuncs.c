#include "shellHeader.h"

/**
* freeArr - frees an array pointer.
* @str: the array.
* Return: void.
**/
void freeArr(char **str)
{
int i = 0;
if (!str)
return;
while (str[i])
{
free(str[i]);
i++;
}
free(str);
}
