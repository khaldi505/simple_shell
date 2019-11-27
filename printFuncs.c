#include "shellHeader.h"

/**
* strPrint - prints a string.
* @str: string.
* Return: void.
**/
void strPrint(const char *str)
{
int len = strLen(str);
int i;
for (i = 0; i < len; i++)
_putchar(str[i]);
}

#include <unistd.h>

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
