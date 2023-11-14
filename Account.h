#include "stdio.h"   
#include "stdlib.h"  
#include "string.h"
#include "locale.h"
#include "conio.h" 
#include <ctype.h> 
#include <stdlib.h>

#define HEADER1 "    ------------------------�ۻ���ϵͳ----------------------------\n"
#define HEADER2 "   |  ���      |  ��Ʒ����    |  ��Ʒ�۸�   |   ��Ʒ����   |\n"
#define HEADER3 "   |------------|--------------|-------------|--------------|\n"
#define FORMAT  "   |  %-6s    |  %-6s      |   %-6s    |    %-6s    |\n" 
#define DATA         p->num,p->name,p->price,p->sum
#define END     "   ---------------------------------------------------------------\n"
#define N 100

#define HEADER1Account "    ------------------------������Աϵͳ----------------------------\n"
#define HEADER2Account "   |  ���      |  ��Ա����    |  �˺�       |   ����       |\n"
#define HEADER3Account "   |------------|--------------|-------------|--------------|\n"
#define FORMATAccount  "   | %-10s |  %-10s  |  %-10s | %-10s   |\n" 
#define DATAAccount         p->num,p->name,p->id,p->password

int accountsaveflag=0;

typedef struct account{
	char num[10];
	char name[10]; 
	char id[10];
	char password[10];
}Account;


void AccountMenu(){
	system("cls");
	printf("                     ������Ա�˺�ϵͳ  \n");
	printf("                                        \n");
	printf("     ********************���˵�*************************\n");
	printf("     *	     1 �����˺�		2 ��ѯ�˺�                 *\n");
	printf("     *	     3 ɾ���˺�		4 ��ʾ�˺�                 *\n");
	printf("     *	     5 �����˺�		0 �˳�ϵͳ                *\n");
	printf("     ***************************************************\n");
}

void PrintAccountHeader()
{	printf(HEADER1Account);
	printf(HEADER2Account);
	printf(HEADER3Account);
}
void Wrong()          
{	printf("\n\n\n\n\n***********Error:�����д�! �����������**********\n");
	getch();
}

void Nofind()        
{	printf("\n=====>δ�ҵ�!\n");
}


void PrintAccountData(Account pp)
{	Account *p;
	p=&pp;
	printf(FORMATAccount,DATAAccount);
}


void DispAccount(Account temp[],int n)
{
	int i;
	if(n==0)
		printf("\n====>���޹�����Ա��\n");
	else
	{
		printf("\n\n");
		PrintAccountHeader();
		i=0;
		while(i<n)
		{
			PrintAccountData(temp[i]);
			i++;
			printf(HEADER3Account);
		}
	}
}



int LocateAccount(Account temp[],int n,char findmess[],char nameorphonenum[])
{
	int i = 0;
	if(strcmp(nameorphonenum,"id") == 0)	
	{
		while(i<n)
		{
			if(strcmp(temp[i].id,findmess)==0) //�ҵ�findmessֵ��Ӧ�ĺ��� 
				return i;
			i++;
		}
	}
	else if(strcmp(nameorphonenum,"name")==0)	
	{
		while(i<n)
		{
			if(strcmp(temp[i].name,findmess)==0)	//�ҵ�findmessֵ��Ӧ������ 
				return i;
			i++;
		}
	}
	//���Ҳ���������-1 
	return -1;	
} 

void AccountStringInput(char* t,int lens,char* notice)
{
	
	char str[255];
	do
	{
		printf(notice);	//��ʾ��ʾ�� 
		scanf("%s",str);
		//���г���У�飬����lensֵ��������	
		if(strlen(str)>lens)
			printf("\n�����涨����!\n");			
	}while(strlen(str)>lens); 
	//����������������浽�ַ���t�� 
	strcpy(t,str);
} 

int AddAccount(Account temp[],int n)
{
	char ch,num[10];
	int i;
	int flag = 0;
	system("cls");
	DispAccount(temp,n);
	while(1)	//һ�ο����������¼ 
	{
		while(1)	
		{//�����¼��ţ���֤�˱��û��ʹ�ã���������Ϊ0�����˳���Ӽ�¼���� 
			AccountStringInput(num,10,"������(��'0'�������˵�)��");	
			flag = 0;
			//����Ϊ0�����˳����������˵� 
			if(strcmp(num,"0") == 0) return n;
			i = 0;
			//��ѯ�������Ƿ���ڣ���������Ҫ����������
			while(i<n)
			{
				if(strcmp(temp[i].num,num) == 0)
				{
					flag =1;
					break;					 
				}
				i++;				
			}
			if(flag == 1)
			{
				getchar();
				printf("==>��� %s �Ѿ����ڣ�����һ�Σ�(y/n):",num);
				scanf("%c",&ch);
				if(ch == 'y' || ch == 'Y')
					continue;
				else	return n;
			}
			else break;		 
		}
		strcpy(temp[n].num,num);	//���ַ���num������tem[n].num��
		AccountStringInput(temp[n].name,15,"Name:");
		AccountStringInput(temp[n].id,15,"Id:");
		AccountStringInput(temp[n].password,15,"Password:");
		accountsaveflag = 1;
		n++; 
	}
	return n;
}

void QurAccount(Account temp[],int n)
{
	int select;		//��ѯ��ʽѡ�� 
	char searchinput[20];	//�����û�����Ĳ�ѯ���� 
	int p=0;
	//������Ϊ�� 
	if(n<=0)
	{
		system("cls");
		printf("\n====>������Ա�����޼�¼��\n"); 
		getchar();
	}
	system("cls");
	printf("\n		====>1 ����Ա���Ʋ���\n");
	printf("\n		====>2 ����ԱId����\n");
	printf("		������ѡ����[1,2]:");
	scanf("%d",&select);
	if(select == 1)		//��������ѯ 
	{
		AccountStringInput(searchinput,10,"������һ���Ѿ����ڵ���Ա����:");
		//��temp�в�������Ϊsearchinput�ļ�¼
		p=LocateAccount(temp,n,searchinput,"name");
		if(p!=-1)
		{
			PrintAccountHeader();
			PrintAccountData(temp[p]);
			printf("�����������......");
			getch();
		}
		else   Nofind();
		getchar();	 
	}
	else if(select == 2)	//���绰�����ѯ
	{
		AccountStringInput(searchinput,10,"������һ���Ѿ����ڵ�Id:");
		p=LocateAccount(temp,n,searchinput,"id");
		if(p!=-1)
		{
			PrintAccountHeader();
			PrintAccountData(temp[p]);
			printf(END);
			printf("�����������......");
			getchar();			
		}
		else Nofind();
		getchar();		 
	}
	else Wrong();
	getchar();	 
}

int DelAccount(Account temp[],int n)
{
	int sel;
	char findmess[20];
	int p=0,i=0;
	if(n<=0)
	{
		system("cls");
		printf("\n====>������Ա�޼�¼!\n");
		getchar();
		return n;
	}
	system("cls");
	DispAccount(temp,n);
	printf("\n		====>1 ������Ա���ƽ���ɾ��\n");
	printf("\n		====>2 ������ԱId����ɾ��\n");
	printf("\n	��ѡ��[1,2]:\n");
	scanf("%d",&sel);
	if(sel==1)
	{
		AccountStringInput(findmess,10,"����һ�����е���Ա���ƣ�");
		p=LocateAccount(temp,n,findmess,"name");
		getchar();
		if(p!=-1)
		{
			for(i=p+1;i<n;i++)
			{
				strcpy(temp[i-1].num,temp[i].num);
				strcpy(temp[i-1].name,temp[i].name);
				strcpy(temp[i-1].id,temp[i].id);
				strcpy(temp[i-1].password,temp[i].password);				
			}
			printf("\n==>ɾ���ɹ�!\n");
			n--;
			getchar();
			accountsaveflag=1;
		} 
		else Nofind();
		getchar();
	}
	else if(sel == 2)
	{
		AccountStringInput(findmess,10,"������һ���Ѿ����ڵ�Id��");
		p=LocateAccount(temp,n,findmess,"id");
		getchar();
		if(p!=-1)
		{
			//ɾ���˼�¼�������¼��ǰ�� 
			for(i=p+1;i<n;i++)
			{
				strcpy(temp[i-1].num,temp[i].num);
				strcpy(temp[i-1].name,temp[i].name);
				strcpy(temp[i-1].id,temp[i].id);
				strcpy(temp[i-1].password,temp[i].password);
			}
			printf("\n====>ɾ���ɹ�!\n");
			n--;
			getchar();
			accountsaveflag=1; 
		}
		else Nofind();
		getchar();		 
	} 
	return n;
}

//δ����Wrong(),Nofind()���������ù���ϵͳ�е�������ͬ���� 

void SaveAccount(Account account[],int n)
{
	FILE* fp;
	int i=0;
	fp=fopen("c:\\AccountInformation.txt","w");
	if(fp==NULL)
	{
		printf("\n====>���ļ�ʧ�ܣ�\n");
		getchar();	
	}	
	for(i=0;i<n;i++)
	{
		if(fwrite(&account[i],sizeof(Account),1,fp)==1)
			continue;
		else
			break;
	}
	if(i>0)
	{
		getchar();
		printf("\n\n====>����ļ����棬ȫ������ļ�¼�У�%d ��\n",i);
		getchar();
		accountsaveflag=0;
	}
	else
	{
		system("cls");
		printf("���¼�¼������!\n");
		getchar(); 
	}
	fclose(fp);
}

void HeadAccount(Account account[],int n){
	strcpy(account[0].num,"0");
	strcpy(account[0].name,"��ʼ��Ա");
	strcpy(account[0].id,"666");
	strcpy(account[0].password,"888");
	//SaveAccount(account,n);
}
