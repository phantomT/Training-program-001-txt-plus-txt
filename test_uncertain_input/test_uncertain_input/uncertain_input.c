#pragma warning(disable:4996) //VS ±‡“Î…˘√˜£ø 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* get_name(void)
{
	char *name, *temp;
	char ch;
	int j = 1;
	
	name = (char*)malloc(sizeof(char)*(j + 1));
	if (NULL == name)
	{
		exit(1);
	}

	while ((name[j - 1] = getchar()) != '\n')
	{
		j++;
		temp = (char*)malloc(j + 1);
		if (NULL == temp)
		{
			exit(1);
		}
		name[j - 1] = '\0';
		strcpy(temp, name);
		free(name);

		name = (char*)malloc(sizeof(char)*(j + 1));
		if (NULL == name)
		{
			exit(1);
		}
		strcpy(name, temp);
		free(temp);
	}

	name[j - 1] = '\0';

	return(name);
}

int main()
{
	char* name;
	printf("please tell me the address:");
	name = get_name();
	printf("%s\n", name);
}