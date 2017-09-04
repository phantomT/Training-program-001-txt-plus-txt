#pragma warning(disable:4996) //VS ���������� 

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>

char* get_name(void)											//�����������ַ
{
	char *name, *temp;
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
	/*################### ���ļ�1��2���������ϲ��ļ�"Output_file.txt" ###################*/

	FILE *fpa, *fpb, *fpc;
	char *file_name_1, *file_name_2;                //�ļ����ݴ�����  

	printf("�������ļ�1����Ե�ַ��");
	//scanf("%s", file_name_1);
	file_name_1=get_name();
	printf("Openning %s\n", file_name_1);                   //״̬��ʶ  

	if ((fpa = fopen(file_name_1, "r")) == NULL)            // ������ļ���ʹfpaָ����ļ�  
	{
		printf("Open failure...\n");                        // �����ʱ���������"�򲻿�"����Ϣ    
		exit(0);                                            // ��ֹ����  
	}

	printf("\n�������ļ�2����Ե�ַ��");
	//scanf("%s", file_name_2);
	file_name_2 = get_name();
	printf("Openning %s\n", file_name_2);                   //״̬��ʶ  

	if ((fpb = fopen(file_name_2, "r")) == NULL)            // ������ļ���ʹfpbָ����ļ�  
	{
		printf("Open failure...\n");                        // �����ʱ���������"�򲻿�"����Ϣ    
		exit(0);                                            // ��ֹ����  
	}


	if ((fpc = fopen("Output_file.txt", "w")) == NULL)      // ������ļ���ʹfpcָ����ļ�  
	{
		printf("Open failure...\n");                        // �����ʱ���������"�򲻿�"����Ϣ    
		exit(0);                                            // ��ֹ����  
	}
	printf("Building Output_file.txt\n");                   //״̬��ʶ  

	/*################### ���ļ�1��2�����ݸ��Ƶ��ļ�Output_file�� ###################*/

	char cha, chb;
	while ((cha = fgetc(fpa)) != EOF)
	{
		fputc(cha, fpc);
	}

	while ((chb = fgetc(fpb)) != EOF)
	{
		fputc(chb, fpc);
	}

	/*################### �ر��ļ�Output_file���ļ�1��2 ###################*/

	fclose(fpc);
	fclose(fpb);
	fclose(fpa);
}

void connect(void)
{
	/*################### ���ļ�1��2���������ϲ��ļ�"Output_file.txt" ###################*/

	FILE *fpa, *fpb, *fpc;
	char *file_name_1, *file_name_2;						//�ļ����ݴ�����  

	printf("�������ļ�1����Ե�ַ��");
	//scanf("%s", file_name_1);
	file_name_1 = get_name();
	printf("Openning %s\n", file_name_1);                   //״̬��ʶ  

	if ((fpa = fopen(file_name_1, "rb")) == NULL)            // ������ļ���ʹfpaָ����ļ�  
	{
		printf("Open failure...\n");                        // �����ʱ���������"�򲻿�"����Ϣ    
		exit(0);                                            // ��ֹ����  
	}

	printf("\n�������ļ�2����Ե�ַ��");
	//scanf("%s", file_name_2);
	file_name_2 = get_name();
	printf("Openning %s\n", file_name_2);                   //״̬��ʶ  

	if ((fpb = fopen(file_name_2, "rb")) == NULL)            // ������ļ���ʹfpbָ����ļ�  
	{
		printf("Open failure...\n");                        // �����ʱ���������"�򲻿�"����Ϣ    
		exit(0);                                            // ��ֹ����  
	}


	if ((fpc = fopen("Output_file.txt", "rwb")) == NULL)      // ������ļ���ʹfpcָ����ļ�  
	{
		printf("Open failure...\n");                        // �����ʱ���������"�򲻿�"����Ϣ    
		exit(0);                                            // ��ֹ����  
	}
	printf("Building Output_file.txt\n");                   //״̬��ʶ  

	/*################### ���ļ�1��2�����ݸ��Ƶ��ļ�Output_file�� ###################*/
	int last_a, last_b;										//�����ļ���С
	char *buff;

	fseek(fpa, 0, SEEK_END);								//���ҵ�һ���ļ��Ĵ�С
	last_a = ftell(fpa);
	buff = (char*)malloc(sizeof(char)*last_a);
	if (NULL == buff)
	{
		exit(1);
	}
	rewind(fpa);											//����һ���ļ�ָ���Ƶ���ͷ���������ǣ�

	fread(buff, 1,last_a, fpa);								//����һ���ļ�д��
	fwrite(buff, 1,last_a, fpc);

	free(buff);

	fseek(fpc, 0, SEEK_END);								//���ϲ��ļ���ָ���Ƶ����
	
	fseek(fpb, 0, SEEK_END);								//���ҵڶ����ļ��Ĵ�С
	last_b = ftell(fpb);
	buff = (char*)malloc(sizeof(char)*last_b);
	if (NULL == buff)
	{
		exit(1);
	}

	rewind(fpb);											//���ڶ����ļ�ָ���Ƶ���ͷ
	fread(buff, 1, last_b, fpb);							//���ڶ����ļ�д��
	fwrite(buff, 1, last_b, fpc);
	
	free(buff);

	/*################### �ر��ļ�Output_file���ļ�1��2 ###################*/

	fclose(fpc);
	fclose(fpb);
	fclose(fpa);
}

int main(void)
{
	printf("Program initiating...\n");

	connect();

	system("pause");

	return(0);
}
