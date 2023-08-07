#include "shell.h"
/**
*numlen - counts zeros in tens power
*@n: the number input
*Return: returns count of digits
*/
int numlen(int n)
{
int count = 0;

while (n > 9 || n < -9)
{
n /= 10;
count++;
}
return (count);
}

/**
* int_to_string - turns an interger to string
* @number: interger input
* Return: the interger as string, null if failed
*/

char *int_to_string(int number)
{
int digits, tens, i;
char *res;

if (number < 0)
{
res = malloc(sizeof(char) * (numlen(number) + 3));
if (res == NULL)
{
return (NULL);
}
res[0] = '-';
digits = -number;
}
else
{
res = malloc(sizeof(char) * (numlen(number) + 2));
if (res == NULL)
{
return (NULL);
}
digits = number;
}

tens = 1;
for (i = 0; digits > 9 || digits < -9; i++)
{
digits /= 10;
tens *= 10;
}

for (i = numlen(number); i >= 0; i--)
{
res[i] = digits / tens + '0';
digits %= tens;
tens /= 10;
}

res[numlen(number) + (number < 0 ? 1 : 0)] = '\0';
return (res);
}

