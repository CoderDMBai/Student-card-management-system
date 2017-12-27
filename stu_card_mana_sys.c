/**
* @par 			Copyright (C): Personal CoderDMBai
* @file         stu_card_mana_sys.c
* @author       CoderDMBai
* @version      V1.0
* @date         2016.06.29
* @brief        学生证管理系统
* @details
* @par History  
*				时间：
*					2016年6月29日09:40:17 
*				BUG：第六个功能修复
*/
#include <stdio.h>
#include <conio.h>						//Console Input/Output（控制台输入输出）的简写 	用于对getch的头文件包的导入 
#include <stdlib.h> 
#include <string.h>
#define NUM 40							//控制结构体中每个元素的大小						
#define N 70							//控制输入学生的数量
#define P_W 17							//定义了密码的长度 
#define MIN_INPUT 0x20 					//控制打印字符范围 
#define MAX_INPUT 0x7e 					//控制打印字符范围
#define TRUE 1 
#define FALSE 0  

/**
	函数声明
*/
void return_menu();						//函数声明		功能：返回菜单 
void choose_1();						//函数声明 		功能：提示选择菜单里的功能 
void choose_2();
void choose_3();
void login_password();					//函数声明		功能：登录密码 
void welcome_1();						//函数声明		功能：提示菜单
void welcome_2();
void welcome_3(); 

/**
	声明结构体
*/
typedef struct{
	char sutdent_id[NUM];				//学号 
	char name[NUM];						//姓名
	char sex[NUM];						//性别 
	char class_number[NUM];				//班号 
	char major[NUM];					//专业 
}STU;									//给结构体起一个别名叫做 STU 

/**
	变量声明
*/
STU info[N];							//定义一个全局的结构体数组 
char inputFILE[] = "info.txt";			//在应用程序同级文件下自动生成 info.txt 文件，因为是以 "w" 的权限打开的文件 
char l_pFile[] = "password.txt";		//在应用程序同级文件下自动生成 password.txt 文件，因为是以 "w" 的权限打开的文件

/**
	欢迎菜单1（主菜单）
*/
void welcome_1()
{
	printf("\n\n\t\t欢迎使用学生证管理程序\t\t\n\n"); 
    printf("请选择功能：\n"); 
    printf("\n===================================================================\n"); 
    printf(" ||                请输入序号                                    ||\n");
	printf(" ||                                                              ||\n"); 
    printf(" ||               1.录入学生的学生证信息(*慎用*)。               ||\n");
    printf(" ||               2.查询学生信息(输入学号)。                     ||\n");
    printf(" ||               3.查询班级内所有学生信息(输入班号)。           ||\n");
    printf(" ||               4.修改学生证信息(输入学号)。                   ||\n");
    printf(" ||               5.删除学生证信息(输入学号)。                   ||\n");
    printf(" ||               6.更改密码。                                   ||\n");
    printf(" ||               7.统计功能。                                   ||\n");
    printf(" ||               8.退出系统。                                   ||\n");
    printf("===================================================================\n"); 
    choose_1();
}

/**
	欢迎菜单2（用于显示功能一的录入学生信息具体功能菜单）
*/
void welcome_2()
{
	printf("\n\n\t\t欢迎使用学生证管理程序\t\t\n\n"); 
    printf("请选择功能：\n"); 
    printf("\n===================================================================\n"); 
    printf(" ||                请输入序号                                    ||\n");
	printf(" ||                                                              ||\n"); 
    printf(" ||               1.录入学生证信息(将会重写源文件信息)。         ||\n");
    printf(" ||               2.在原基础上添加学生证信息。                   ||\n");
    printf(" ||                                                              ||\n");
    printf("===================================================================\n"); 
    choose_2();
}

/**
	欢迎菜单3（用于显示功能七的统计具体功能菜单 ）
*/
void welcome_3()
{
	printf("\n\n\t\t欢迎使用学生证管理程序\t\t\n\n"); 
    printf("请选择功能：\n"); 
    printf("\n===================================================================\n"); 
    printf(" ||                请输入序号                                    ||\n");
	printf(" ||                                                              ||\n"); 
    printf(" ||               1.。							                 ||\n");
    printf(" ||               2.。                                           ||\n");
    printf(" ||               3.。                                           ||\n");
    printf(" ||               4.。                                           ||\n");
    printf(" ||               5.。                                           ||\n");
    printf(" ||               6.。                                           ||\n");
    printf(" ||               7.。                                           ||\n");
    printf(" ||               8.。                                           ||\n");
    printf("===================================================================\n"); 
    choose_3();
}

/**
	输入密码打印星号 
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
		else if ( ch >= MIN_INPUT && ch <= MAX_INPUT) /*所有可打印字符*/ 
		{ 
			password[i++]=ch; 
		} 
		else if ( ch == 8 && i> 0 ) /*退格键*/ 
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
	首次登陆设置登陆密码
*/
void first_login_password()
{
	char new_password[P_W],test_password[P_W];
	
	if(fopen(l_pFile,"r") == NULL)
	{
		printf("\n\n\t\t欢迎使用学生证管理程序\t\t\n\n"); 
		printf("首次登陆需要设置登陆密码：\n");
		printf("请输入密码(16位数字or字母)：\n");
		GetPassword_print_star(new_password,P_W);
		
		printf("\n请确认密码(16位数字or字母)：\n");
		GetPassword_print_star(test_password,P_W);
		
		if(strcmp(new_password,test_password)==0)
		{
			FILE *file;
			file = fopen(l_pFile,"w");
			fprintf(file,"%s",new_password);
			fclose(file);
			printf("\n密码设置成功！");
			return_menu();
		}
		else
		{
			int i;
			
			while(i != 1)
			{
				printf("\n密码输入错误,请重新输入！\n");
				printf("请确认密码(16位数字or字母)：\n");
				GetPassword_print_star(test_password,P_W);
				if(strcmp(new_password,test_password)==0)
				{
					FILE *file;
					file = fopen(l_pFile,"w");
					fprintf(file,"%s",new_password);
					fclose(file);
					printf("\n密码设置成功！");
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
	非首次登陆输入登陆密码
*/
void login_password()
{
	int i = 0, j = 3;
	char new_password[P_W], old_password[P_W];
	
	printf("\n\n\t\t欢迎使用学生证管理程序\t\t\n\n"); 
	
	while(i < 3)
	{
		FILE *file;
		file = fopen(l_pFile,"r");
		fscanf(file,"%s",old_password);
		fclose(file);
		printf("请输入密码：\n");
		GetPassword_print_star(new_password,P_W); 
		if(strcmp(old_password,new_password) == 0)
		{
			system("cls");
			welcome_1();
			return;
		}
		if(i < 2)
		{
			printf("\n您输入的密码不正确!\n");
			if(j != 0)
			{
				j --;
				printf("您还有 %d 次机会！\n",j);
			}
		}
		i++;
	}
	printf("\n您输入密码不正确已经3次,您被强制退出系统!");
	exit(0); 
}

/**
	1.录入学生证信息(将会重写源文件信息)
*/
void logging_new_data()
{
	int i;
	char ch;
	FILE *fp;
	
	fp = fopen(inputFILE,"w");
	
	//printf("请按顺序录入学生的学号、姓名、性别、班号、专业\n");
	printf("请慎重填写信息：\n"); 
	
	for(i=0; i<N; i++)
	{
		printf("********第 %d 个学生信息********\n",i+1);
		printf("\t学号： ");
		scanf("%s",info[i].sutdent_id);
		printf("\t姓名： ");
		scanf("%s",info[i].name);
		printf("\t性别： ");
		scanf("%s",info[i].sex);
		printf("\t班号： ");
		scanf("%s",info[i].class_number);
		printf("\t专业： ");
		scanf("%s",info[i].major);
		
		fprintf(fp,"%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
		
		printf("是否继续录入(按1继续，按任意键返回主菜单)：");
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
	2.在原基础上添加学生证信息
*/
void logging_old_data()					
{
	int i;
	char ch;
	FILE *fp;
	
	fp = fopen(inputFILE,"a");
	
	//printf("请按顺序录入学生的学号、姓名、性别、班号、专业\n");
	printf("请慎重填写信息：\n"); 
	
	for(i=0; i<N; i++)
	{
		printf("********第 %d 个学生信息********\n",i+1);
		printf("\t学号： ");
		scanf("%s",info[i].sutdent_id);
		printf("\t姓名： ");
		scanf("%s",info[i].name);
		printf("\t性别： ");
		scanf("%s",info[i].sex);
		printf("\t班号： ");
		scanf("%s",info[i].class_number);
		printf("\t专业： ");
		scanf("%s",info[i].major);
		
		fprintf(fp,"%s %s %s %s %s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
		
		printf("是否继续录入(按1继续，按任意键返回主菜单)：");
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
	查询学生信息(输入学号)
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
	
	printf("请输入待查询学生信息的学号：");
	fflush(stdin);
	gets(j);
	
	for(i=0; i<N; i++)
	{
		if(strcmp(j,info[i].sutdent_id) == 0)	
		{
			if(l)						//解决了班号输错时会显示学号、姓名等信息的bug。		但是在班号输入正确时，也只会输出一次提示信息 
			{
				printf("\t\t学号\t\t姓名\t\t性别\t\t班号\t\t专业\n");
			}
			printf("\t%s\t\t%s\t\t%s\t\t%s\t%s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
			k = 0;
			l = 0;
		}
	}
	if(k)
	{
		printf("\n查无此人，请仔细核对！\n"); 
	} 
	return_menu();
	return;
}

/**
	查询班级内所有学生信息(输入班号)
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
	
	printf("请输入待查询班级的班号：");
	fflush(stdin);
	gets(j);
	
	for(i=0; i<N; i++)
	{
		if(strcmp(j,info[i].class_number) == 0)
		{
			if(l)						//解决了班号输错时会显示学号、姓名等信息的bug。		但是在班号输入正确时，也只会输出一次提示信息 
			{
				printf("\t\t学号\t\t姓名\t\t性别\t\t班号\t\t专业\n");
			}
			printf("\t%s\t\t%s\t\t%s\t\t%s\t%s\n",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
			k = 0;
			l = 0; 
		}
	}
	if(k)
	{
		printf("\n您输入的班号不正确，请仔细核对!\n");
	}
	return_menu();
	return;
}

/**
	修改学生证信息(输入学号)
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
	
	printf("请输入待修改学生信息的学号：");
	fflush(stdin);
	gets(j);
	 
	for(i=0; i<N; i++)
	{
		if(strcmp(j,info[i].sutdent_id) == 0)
		{
			printf("********请重新录入下列信息********\n");
			
			printf("\t学号： ");
			fflush(stdin);
			scanf("%s",info[i].sutdent_id);
			printf("\t姓名： ");
			fflush(stdin);
			scanf("%s",info[i].name);
			printf("\t性别： ");
			fflush(stdin);
			scanf("%s",info[i].sex);
			printf("\t班号： ");
			fflush(stdin);
			scanf("%s",info[i].class_number);
			printf("\t专业： ");
			fflush(stdin);
			scanf("%s",info[i].major);
			
			k = 0;
			//scanf("%s%s%s%s%s",info[i].sutdent_id,info[i].name,info[i].sex,info[i].class_number,info[i].major);
			//fprintf(fp,"\n%4s %4s %4s %4s %4s\n",info[i].sutdent_id,info[i].name,info[i].sex,[i].class_number,info[i].major);
		}
	}
	if(k)
	{
		printf("\n您输入的班号有误，请仔细核对\n");
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
	删除学生证信息(输入学号)
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
	
	printf("请输入待删除学生证信息的学号：");
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
	printf("\n成功删除！\n");
	return_menu();
	return;
}

/**
	更改密码	
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
		printf("请输入初始密码：\n");
		GetPassword_print_star(old_password,P_W);
		
		if(strcmp(ago_password,old_password)==0)
		{
			printf("\n请输入新密码(16位数字or字母)：\n");
			GetPassword_print_star(new_password,P_W);
			printf("\n请确认密码(16位数字or字母)：\n");
			GetPassword_print_star(test_password,P_W);
			
			if(strcmp(new_password,test_password)==0)
			{
				file = fopen(l_pFile,"w");
				fprintf(file,"%s",new_password);
				fclose(file);
				printf("\n密码设置成功！");
				//加返回菜单函数,或者退出程序函数 
				return_menu();
				return;
			}
			else
			{
				int k;
				
				while(k != 1)
				{
					printf("\n密码输入错误,请重新输入！\n");
					printf("请确认密码(16位数字or字母)：\n");
					GetPassword_print_star(test_password,P_W);
					if(strcmp(new_password,test_password)==0)
					{
						file = fopen(l_pFile,"w");
						fprintf(file,"%s",new_password);
						fclose(file);
						k = 1;
						printf("\n密码设置成功！");
						//加返回菜单函数,或者退出程序函数 
						return_menu();
						return;
					}
				}
			
			}	 
		}
		if(i < 2)
		{
			printf("\n您输入的密码不正确!\n");
			if(j != 0)
			{
				j --;
				printf("您还有 %d 次机会！\n",j);
			}
		}
		i++;
	}
	printf("\n您输入密码不正确已经3次!");
	return_menu();
	return;
} 

/**
	功能对接
*/
void choose_1() 
{
	int i;
	printf("请选择： ");
	fflush(stdin);
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			system("cls");
			welcome_2();				//录入学生的学生证信息
			break;
		case 2:
			search_student();			//查询学生信息(输入学号)
			break;
		case 3:
			search_class();				//查询班级内所有学生信息(输入班号)
			break;
		case 4:
			change_student();			//修改学生证信息(输入学号)
			break;
		case 5:
			delete_student();			//删除学生证信息(输入学号)
			break;
		case 6:							 
			change_password();			//更改密码 
			break;
		case 7:
			printf("\n未完待续.......\n");
			return_menu();
			break;
		case 8:
			exit(0);
			break;
		default :
			printf("\n输入有误！！！\n"); 
			return_menu();
			break;
	}
}

/**
	录入学生信息
*/
void choose_2()
{
	int i;
	printf("请选择： ");
	fflush(stdin);
	scanf("%d",&i);
	if(1 == i)
	{
		logging_new_data();
		return;	
	}
	else if(2 == i)
	{					//以"a"的方式打开文件 
		logging_old_data();
		return;
	}
	else
	{
		printf("\n您输入有误！\n");
		return_menu(); 
	} 
}

/**
	待扩展
*/
void choose_3()
{
	
}

/**
	返回菜单 or 退出系统。
*/
void return_menu()
{
	char ch;
	printf("\n请选择:按 1 返回主页面. 按任意键退出:");
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
	主函数
*/
main()
{
	first_login_password(); 
} 
