#include<stdio.h>
#include<conio.h>
#include<string.h>
int checkNumber(char *str)
{
	int i, count = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			count++;
	}
	if (count >= 1)
		return 1;
	else
		return 0;
}
int checkUpper(char* str)
{
	int i, count = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			count++;
	}
	if (count >= 1)
		return 1;
	else
		return 0;
}
int checkSpecial(char* str)
{
	int i, count = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if ((str[i] >= 33 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64) || (str[i] >= 91 && str[i] <= 96) || (str[i] >= 123 && str[i] <= 126))
			count++;
	}
	if (count >= 1)
		return 1;
	else
		return 0;
}
int noSpace(char* str)
{
	int i, flag = 1;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
			flag = 0;
	}
	if (flag == 1)
		return 1;
	else
		return 0;
}
int main()
{
	int i, flag = 1;
	char str[100];
	while (flag == 1)
	{
		printf(">> Enter string: ");
		fgets(str, sizeof(str), stdin);
		str[strcspn(str, "\n")] = '\0';
		if (checkNumber(&str) == 1 && checkUpper(&str) == 1 && checkSpecial(&str) == 1 && noSpace(&str) == 1)
		{
			printf("Your string \"%s\" is valid.", str);
			flag = 0;
		}
		else
			printf("Your string \"%s\" is invalid, please type again.\n", str);
	}
	return 0;
}