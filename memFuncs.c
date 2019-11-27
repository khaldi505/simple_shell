#include "shellHeader.h"

/** strCat - Concatinates two strings with manual allocation.
  * @str1: first string.
  * @str2: second string.
  * Return: pointer to the newly created string
  **/
void freeArr(char **str)
{
int i = 0;
while (str[i]) {
  free(str[i]);
  i++;
}
free(str);
}
