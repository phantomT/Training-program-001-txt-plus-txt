#pragma warning(disable:4996) //VS 编译声明？ 

#include <stdio.h>  
#include <stdlib.h>  

char* get_name(void)											//不定长输入地址
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

void combine(void)
{
	/*################### 打开文件1和2，并建立合并文件"Output_file.txt" ###################*/

	FILE *fpa, *fpb, *fpc;
	char *file_name_1, *file_name_2;                //文件名暂存数组  

	printf("请输入文件1的相对地址：");
	//scanf("%s", file_name_1);
	file_name_1=get_name();
	printf("Openning %s\n", file_name_1);                   //状态标识  

	if ((fpa = fopen(file_name_1, "r")) == NULL)            // 打开输出文件并使fpa指向此文件  
	{
		printf("Open failure...\n");                        // 如果打开时出错，就输出"打不开"的信息    
		exit(0);                                            // 终止程序  
	}

	printf("\n请输入文件2的相对地址：");
	//scanf("%s", file_name_2);
	file_name_2 = get_name();
	printf("Openning %s\n", file_name_2);                   //状态标识  

	if ((fpb = fopen(file_name_2, "r")) == NULL)            // 打开输出文件并使fpb指向此文件  
	{
		printf("Open failure...\n");                        // 如果打开时出错，就输出"打不开"的信息    
		exit(0);                                            // 终止程序  
	}


	if ((fpc = fopen("Output_file.txt", "w")) == NULL)      // 打开输出文件并使fpc指向此文件  
	{
		printf("Open failure...\n");                        // 如果打开时出错，就输出"打不开"的信息    
		exit(0);                                            // 终止程序  
	}
	printf("Building Output_file.txt\n");                   //状态标识  

	/*################### 将文件1和2的内容复制到文件Output_file中 ###################*/

	char cha, chb;
	while ((cha = fgetc(fpa)) != EOF)
	{
		fputc(cha, fpc);
	}

	while ((chb = fgetc(fpb)) != EOF)
	{
		fputc(chb, fpc);
	}

	/*################### 关闭文件Output_file和文件1、2 ###################*/

	fclose(fpc);
	fclose(fpb);
	fclose(fpa);
}

int main(void)
{
	printf("Program initiating...\n");

	combine();

	system("pause");

	return(0);
}
