/**
* @par 			Copyright (C): Personal CoderDMBai
* @file         stu_card_mana_sys.c
* @author       CoderDMBai
* @version      V1.0
* @date         2016.06.29
* @brief        ѧ��֤����ϵͳ
* @details
* @par History  
*				ʱ�䣺
*					2016��6��29��09:40:17 
*				BUG�������������޸�
*/
#include <stdio.h>
#include <conio.h>						//Console Input/Output������̨����������ļ�д 	���ڶ�getch��ͷ�ļ����ĵ��� 
#include <stdlib.h> 
#include <string.h>
#define NUM 40							//���ƽṹ����ÿ��Ԫ�صĴ�С						
#define N 70							//��������ѧ��������
#define P_W 17							//����������ĳ��� 
#define MIN_INPUT 0x20 					//���ƴ�ӡ�ַ���Χ 
#define MAX_INPUT 0x7e 					//���ƴ�ӡ�ַ���Χ
#define TRUE 1 
#define FALSE 0  

/**
	��������
*/
void return_menu();						//��������		���ܣ����ز˵� 
void choose_1();						//�������� 		���ܣ���ʾѡ��˵���Ĺ��� 
void choose_2();
void choose_3();
void login_password();					//��������		���ܣ���¼���� 
void welcome_1();						//��������		���ܣ���ʾ�˵�
void welcome_2();
void welcome_3(); 

/**
	�����ṹ��
*/
typedef struct{
	char sutdent_id[NUM];				//ѧ�� 
	char name[NUM];						//����
	char sex[NUM];						//�Ա� 
	char class_number[NUM];				//��� 
	char major[NUM];					//רҵ 
}STU;									//���ṹ����һ���������� STU 

/**
	��������
*/
STU info[N];							//����һ��ȫ�ֵĽṹ������ 
char inputFILE[] = "info.txt";			//��Ӧ�ó���ͬ���ļ����Զ����� info.txt �ļ�����Ϊ���� "w" ��Ȩ�޴򿪵��ļ� 
char l_pFile[] = "password.txt";		//��Ӧ�ó���ͬ���ļ����Զ����� password.txt �ļ�����Ϊ���� "w" ��Ȩ�޴򿪵��ļ�

/**
	��ӭ�˵�1�����˵���
*/
void welcome_1()
{
	printf("\n\n\t\t��ӭʹ��ѧ��֤�������\t\t\n\n"); 
    printf("��ѡ���ܣ�\n"); 
    printf("\n===================================================================\n"); 
    printf(" ||                ���������                                    ||\n");
	printf(" ||                                                              ||\n"); 
    printf(" ||               1.¼��ѧ����ѧ��֤��Ϣ(*����*)��               ||\n");
    printf(" ||               2.��ѯѧ����Ϣ(����ѧ��)��                     ||\n");
    printf(" ||               3.��ѯ�༶������ѧ����Ϣ(������)��           ||\n");
    printf(" ||               4.�޸�ѧ��֤��Ϣ(����ѧ��)��                   ||\n");
    printf(" ||               5.ɾ��ѧ��֤��Ϣ(����ѧ��)��                   ||\n");
    printf(" ||               6.�������롣                                   ||\n");
    printf(" ||               7.ͳ�ƹ��ܡ�                                   ||\n");
    printf(" ||               8.�˳�ϵͳ��                                   ||\n");
    printf("===================================================================\n"); 
    choose_1();
}

/**
	��ӭ�˵�2��������ʾ����һ��¼��ѧ����Ϣ���幦�ܲ˵���
*/
void welcome_2()
{
	printf("\n\n\t\t��ӭʹ��ѧ��֤�������\t\t\n\n"); 
    printf("��ѡ���ܣ�\n"); 
    printf("\n===================================================================\n"); 
    printf(" ||                ���������                                    ||\n");
	printf(" ||                                                              ||\n"); 
    printf(" ||               1.¼��ѧ��֤��Ϣ(������дԴ�ļ���Ϣ)��         ||\n");
    printf(" ||               2.��ԭ���������ѧ��֤��Ϣ��                   ||\n");
    printf(" ||                                                              ||\n");
    printf("===================================================================\n"); 
    choose_2();
}

/**
	��ӭ�˵�3��������ʾ�����ߵ�ͳ�ƾ��幦�ܲ˵� ��
*/
void welcome_3()
{
	printf("\n\n\t\t��ӭʹ��ѧ��֤�������\t\t\n\n"); 
    printf("��ѡ���ܣ�\n"); 
    printf("\n===================================================================\n"); 
    printf(" ||                ���������                                    ||\n");
	printf(" ||                                                              ||\n"); 
    printf(" ||               1.��							                 ||\n");
    printf(" ||               2.��                                           ||\n");
    printf(" ||               3.��                                           ||\n");
    printf(" ||               4.��                                           ||\n");
    printf(" ||               5.��                                           ||\n");
    printf(" ||               6.��                                           ||\n");
    printf(" ||               7.��                                           ||\n");
    printf(" ||               8.��                                           ||\n");
    printf("===================================================================\n"); 
    choose_3();
}

/**
	���������ӡ�Ǻ� 
*/
void GetPassword_print_star(char* password,int maxsize)
{ 
	char ch; 
	int i=0; 
	
	int bIsEcho=TRUE; 
	
	//while( ! kbhit() && i<iMaxSize ) 
	while( ( ch = (char)getch() ) && i < maxsize ) 
	{ 
		//ch = (unsigned char)getch(); 
		bIsEcho=TRUE; 
		
		if ( ch == 13) 
		{ 
			password[i++]=0; 
			break; 
		} 
		else if ( ch >= MIN_INPUT && ch <= MAX_INPUT) /*���пɴ�ӡ�ַ�*/ 
		{ 
			password[i++]=ch; 
		} 
		else if ( ch == 8 && i> 0 ) /*�˸��*/ 
		{ 
			password[i--] = 0; 
			bIsEcho = FALSE; 
			putchar( ch ); 
			putchar( ' ' ); 
			putchar( ch ); 
		} 
		else 
			bIsEcho = FALSE; 
		if(bIsEcho)  
			putchar('*'); 
	} 
	password[i]=0; 
	return; 
}

/**
	�״ε�½���õ�½����
*/
void first_login_password()
{
	char new_password[P_W],test_password[P_W];
	
	if(fopen(l_pFile,"r") == NULL)
	{
		printf("\n\n\t\t��ӭʹ��ѧ��֤�������\t\t\n\n"); 
		printf("�״ε�½��Ҫ���õ�½���룺\n");
		printf("����������(16λ����or��ĸ)��\n");
		GetPassword_print_star(new_password,P_W);
		
		printf("\n��ȷ������(16λ����or��ĸ)��\n");
		GetPassword_print_star(test_password,P_W);
		
		if(strcmp(new_password,test_password)==0)
		{
			FILE *file;
			file = fopen(l_pFile,"w");
			fprintf(file,"%s",new_password);
			fclose(file);
			printf("\n�������óɹ���");
			return_menu();
		}
		else
		{
			int i;
			
			while(i != 1)
			{
				printf("\n�����������,���������룡\n");
				printf("��ȷ������(16λ����or��ĸ)��\n");
				GetPassword_print_star(test_password,P_W);
				if(strcmp(new_password,test_password)==0)
				{
					FILE *file;
					file = fopen(l_pFile,"w");
					fprintf(file,"%s",new_password);
					fclose(file);
					printf("\n�������óɹ���");
					i = 1;	
				}
			} 
		return_menu();
		return;
		}
	}
	else
	{
		login_password();
		return;
	}
}

/**
	���״ε�½�����½����
*/
void login_password()
{
	int i = 0, j = 3;
	char new_password[P_W], old_password[P_W];
	
	printf("\n\n\t\t��ӭʹ��ѧ��֤�������\t\t\n\n"); 
	
	while(i < 3)
	{
		FILE *file;
		file = fopen(l_pFile,"r");
		fscanf(file,"%s",old_password);
		fclose(file);
		printf("���������룺\n");
		GetPassword_print_star(new_password,P_W); 
		if(strcmp(old_password,new_password) == 0)
		{
			system("cls");
			welcome_1();
			return;
		}
		if(i < 2)
		{
			printf("\n����������벻��ȷ!\n");
			if(j != 0)
			{
				j --;
				printf("������ %d �λ��ᣡ\n",j);
			}
		}
		i++;
	}
	printf("\n���������벻��ȷ�Ѿ�3��,����ǿ���˳�ϵͳ!");
	exit(0); 
}

/**
	1.¼��ѧ��֤��Ϣ(������дԴ�ļ���Ϣ)
*/
void logging_new_data()
{
	int i;
	char ch;
	FILE *fp;
	
	fp = fopen(inputFILE,"w");
	
	//printf("�밴˳��¼��ѧ����ѧ�š��������Ա𡢰�š�רҵ\n");
	printf("��������д��Ϣ��\n"); 
	
	for(i=0; i<N; i++)
	{
		printf("********�� %d ��ѧ����Ϣ********\n",i+1);
		printf("\tѧ�ţ� ");
		scanf("%s",info[i].sutdent_id);
		printf("\t������ ");
		scanf("%s",info[i].name);
		printf("\t�Ա� ");
		scanf("%s",info[i].sex);
		printf("\t��ţ� ");
		scanf("%s",info[i].class_number);
		printf("\tרҵ�� ");
		scanf("%s",info[i].major);
		
		fprintf(fp,"%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
		
		printf("�Ƿ����¼��(��1��������������������˵�)��");
		fflush(stdin);
	    scanf("%c",&ch);
	    if(ch=='1')
		{	
			continue;
		}
	    else
		{
			fclose(fp);
			system("cls");
			welcome_1();
		}
	}
	fclose(fp);
}

/**
	2.��ԭ���������ѧ��֤��Ϣ
*/
void logging_old_data()					
{
	int i;
	char ch;
	FILE *fp;
	
	fp = fopen(inputFILE,"a");
	
	//printf("�밴˳��¼��ѧ����ѧ�š��������Ա𡢰�š�רҵ\n");
	printf("��������д��Ϣ��\n"); 
	
	for(i=0; i<N; i++)
	{
		printf("********�� %d ��ѧ����Ϣ********\n",i+1);
		printf("\tѧ�ţ� ");
		scanf("%s",info[i].sutdent_id);
		printf("\t������ ");
		scanf("%s",info[i].name);
		printf("\t�Ա� ");
		scanf("%s",info[i].sex);
		printf("\t��ţ� ");
		scanf("%s",info[i].class_number);
		printf("\tרҵ�� ");
		scanf("%s",info[i].major);
		
		fprintf(fp,"%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
		
		printf("�Ƿ����¼��(��1��������������������˵�)��");
		fflush(stdin);
	    scanf("%c",&ch);
	    if(ch=='1')
		{	
			continue;
		}
	    else
		{
			fclose(fp);
			system("cls");
			welcome_1();
		}
	}
	fclose(fp);
} 

/**
	��ѯѧ����Ϣ(����ѧ��)
*/
void search_student()					
{
	int i, k = 1, l = 1;
	char j[NUM];
	STU arr[N]; 
	FILE *fp;
	fp = fopen(inputFILE,"r");
	
	for(i=0; i<N; i++)
	{
		fscanf(fp,"%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
		//printf("%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
	}
	fclose(fp);
	
	printf("���������ѯѧ����Ϣ��ѧ�ţ�");
	fflush(stdin);
	gets(j);
	
	for(i=0; i<N; i++)
	{
		if(strcmp(j,info[i].sutdent_id) == 0)	
		{
			if(l)						//����˰�����ʱ����ʾѧ�š���������Ϣ��bug��		�����ڰ��������ȷʱ��Ҳֻ�����һ����ʾ��Ϣ 
			{
				printf("\t\tѧ��\t\t����\t\t�Ա�\t\t���\t\tרҵ\n");
			}
			printf("\t%s\t\t%s\t\t%s\t\t%s\t%s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
			k = 0;
			l = 0;
		}
	}
	if(k)
	{
		printf("\n���޴��ˣ�����ϸ�˶ԣ�\n"); 
	} 
	return_menu();
	return;
}

/**
	��ѯ�༶������ѧ����Ϣ(������)
*/
void search_class()					
{
	int i, k = 1, l = 1;
	char j[NUM];
	FILE *fp;
	fp = fopen(inputFILE,"r");
	
	for(i=0; i<N; i++)
	{
		fscanf(fp,"%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
		//printf("%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
	}
	fclose(fp);
	
	printf("���������ѯ�༶�İ�ţ�");
	fflush(stdin);
	gets(j);
	
	for(i=0; i<N; i++)
	{
		if(strcmp(j,info[i].class_number) == 0)
		{
			if(l)						//����˰�����ʱ����ʾѧ�š���������Ϣ��bug��		�����ڰ��������ȷʱ��Ҳֻ�����һ����ʾ��Ϣ 
			{
				printf("\t\tѧ��\t\t����\t\t�Ա�\t\t���\t\tרҵ\n");
			}
			printf("\t%s\t\t%s\t\t%s\t\t%s\t%s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
			k = 0;
			l = 0; 
		}
	}
	if(k)
	{
		printf("\n������İ�Ų���ȷ������ϸ�˶�!\n");
	}
	return_menu();
	return;
}

/**
	�޸�ѧ��֤��Ϣ(����ѧ��)
*/
void change_student()					
{
	int i, k = 1;							
	char j[NUM];
	FILE *fp;
	fp = fopen(inputFILE,"r");
	
	for(i=0; i<N; i++)
	{
		fscanf(fp,"%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
		//printf("%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
	}
	fclose(fp);
	
	printf("��������޸�ѧ����Ϣ��ѧ�ţ�");
	fflush(stdin);
	gets(j);
	 
	for(i=0; i<N; i++)
	{
		if(strcmp(j,info[i].sutdent_id) == 0)
		{
			printf("********������¼��������Ϣ********\n");
			
			printf("\tѧ�ţ� ");
			fflush(stdin);
			scanf("%s",info[i].sutdent_id);
			printf("\t������ ");
			fflush(stdin);
			scanf("%s",info[i].name);
			printf("\t�Ա� ");
			fflush(stdin);
			scanf("%s",info[i].sex);
			printf("\t��ţ� ");
			fflush(stdin);
			scanf("%s",info[i].class_number);
			printf("\tרҵ�� ");
			fflush(stdin);
			scanf("%s",info[i].major);
			
			k = 0;
			//scanf("%s%s%s%s%s",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
			//fprintf(fp,"\n%4s %4s %4s %4s %4s\n",info[i].sutdent_id,info[i].name,info[i].sex,[i].class_number,info[i].major);
		}
	}
	if(k)
	{
		printf("\n������İ����������ϸ�˶�\n");
	}
	
	fp = fopen(inputFILE,"w");
	for(i=0; i<N; i++)
	{
		fprintf(fp,"%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
	}
	fclose(fp);
	return_menu();
	return;
}

/**
	ɾ��ѧ��֤��Ϣ(����ѧ��)
*/
void delete_student()					
{
	
	int i;
	char j[NUM];
	FILE *fp;
	fp = fopen(inputFILE,"r");
	
	for(i=0; i<N; i++)
	{
		fscanf(fp,"%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
		//printf("%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
	}
	fclose(fp);
	
	printf("�������ɾ��ѧ��֤��Ϣ��ѧ�ţ�");
	fflush(stdin);
	gets(j);
	
	fp = fopen(inputFILE,"w");
	for(i=0; i<N; i++)
	{
		if(strcmp(j,info[i].sutdent_id) == 0)
		{
			continue;
		}
		else
		{
			fprintf(fp,"%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
		}
	}
	fclose(fp);
	printf("\n�ɹ�ɾ����\n");
	return_menu();
	return;
}

/**
	��������	
*/
void change_password()							
{
	int i = 0, j = 3;
	char ago_password[P_W], new_password[P_W], old_password[P_W], test_password[P_W];
	FILE *file;
	file = fopen(l_pFile,"r");
	fscanf(file,"%s",ago_password);
	fclose(file);
	
	while(i<3)
	{
		printf("�������ʼ���룺\n");
		GetPassword_print_star(old_password,P_W);
		
		if(strcmp(ago_password,old_password)==0)
		{
			printf("\n������������(16λ����or��ĸ)��\n");
			GetPassword_print_star(new_password,P_W);
			printf("\n��ȷ������(16λ����or��ĸ)��\n");
			GetPassword_print_star(test_password,P_W);
			
			if(strcmp(new_password,test_password)==0)
			{
				file = fopen(l_pFile,"w");
				fprintf(file,"%s",new_password);
				fclose(file);
				printf("\n�������óɹ���");
				//�ӷ��ز˵�����,�����˳������� 
				return_menu();
				return;
			}
			else
			{
				int k;
				
				while(k != 1)
				{
					printf("\n�����������,���������룡\n");
					printf("��ȷ������(16λ����or��ĸ)��\n");
					GetPassword_print_star(test_password,P_W);
					if(strcmp(new_password,test_password)==0)
					{
						file = fopen(l_pFile,"w");
						fprintf(file,"%s",new_password);
						fclose(file);
						k = 1;
						printf("\n�������óɹ���");
						//�ӷ��ز˵�����,�����˳������� 
						return_menu();
						return;
					}
				}
			
			}	 
		}
		if(i < 2)
		{
			printf("\n����������벻��ȷ!\n");
			if(j != 0)
			{
				j --;
				printf("������ %d �λ��ᣡ\n",j);
			}
		}
		i++;
	}
	printf("\n���������벻��ȷ�Ѿ�3��!");
	return_menu();
	return;
} 

/**
	���ܶԽ�
*/
void choose_1() 
{
	int i;
	printf("��ѡ�� ");
	fflush(stdin);
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			system("cls");
			welcome_2();				//¼��ѧ����ѧ��֤��Ϣ
			break;
		case 2:
			search_student();			//��ѯѧ����Ϣ(����ѧ��)
			break;
		case 3:
			search_class();				//��ѯ�༶������ѧ����Ϣ(������)
			break;
		case 4:
			change_student();			//�޸�ѧ��֤��Ϣ(����ѧ��)
			break;
		case 5:
			delete_student();			//ɾ��ѧ��֤��Ϣ(����ѧ��)
			break;
		case 6:							 
			change_password();			//�������� 
			break;
		case 7:
			printf("\nδ�����.......\n");
			return_menu();
			break;
		case 8:
			exit(0);
			break;
		default :
			printf("\n�������󣡣���\n"); 
			return_menu();
			break;
	}
}

/**
	¼��ѧ����Ϣ
*/
void choose_2()
{
	int i;
	printf("��ѡ�� ");
	fflush(stdin);
	scanf("%d",&i);
	if(1 == i)
	{
		logging_new_data();
		return;	
	}
	else if(2 == i)
	{					//��"a"�ķ�ʽ���ļ� 
		logging_old_data();
		return;
	}
	else
	{
		printf("\n����������\n");
		return_menu(); 
	} 
}

/**
	����չ
*/
void choose_3()
{
	
}

/**
	���ز˵� or �˳�ϵͳ��
*/
void return_menu()
{
	char ch;
	printf("\n��ѡ��:�� 1 ������ҳ��. ��������˳�:");
	fflush(stdin);
    scanf("%c",&ch);
    if(ch=='1')
	{	
		system("cls");
		welcome_1();
	}
    else
	{
		exit(0);
	} 
} 

/**
	������
*/
main()
{
	first_login_password(); 
} 
