#pragma warning(disable:4996) //VS ���������� 

#include <stdio.h>  
#include <stdlib.h>  

void main(void)
{
	printf("Program initiating...\n");

	/*################### ���ļ�1��2���������ϲ��ļ�"Output_file.txt" ###################*/

	FILE *fpa, *fpb, *fpc;
	char file_name_1[200], file_name_2[200];                //�ļ����ݴ�����  

	printf("�������ļ�1����Ե�ַ��");
	scanf("%s", file_name_1);
	printf("Openning %s\n", file_name_1);                   //״̬��ʶ  

	if ((fpa = fopen(file_name_1, "r")) == NULL)            // ������ļ���ʹfpaָ����ļ�  
	{
		printf("Open failure...\n");                        // �����ʱ���������"�򲻿�"����Ϣ    
		exit(0);                                            // ��ֹ����  
	}

	printf("\n�������ļ�2����Ե�ַ��");
	scanf("%s", file_name_2);
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

	system("pause");

}
