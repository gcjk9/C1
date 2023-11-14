#include "stdio.h"   
#include "stdlib.h"  
#include "string.h"
#include "locale.h"
#include "conio.h" 
#include <ctype.h> 
#include <stdlib.h>

#define HEADER1 "    ------------------------售货机系统----------------------------\n"
#define HEADER2 "   |  编号      |  商品名称    |  商品价格   |   商品数量   |\n"
#define HEADER3 "   |------------|--------------|-------------|--------------|\n"
#define FORMAT  "   |  %-6s    |  %-6s      |   %-6s    |    %-6s    |\n" 
#define DATA         p->num,p->name,p->price,p->sum
#define END     "   ---------------------------------------------------------------\n"
#define N 100

#define HEADER1Account "    ------------------------管理人员系统----------------------------\n"
#define HEADER2Account "   |  编号      |  人员名称    |  账号       |   密码       |\n"
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
	printf("                     管理人员账号系统  \n");
	printf("                                        \n");
	printf("     ********************主菜单*************************\n");
	printf("     *	     1 增加账号		2 查询账号                 *\n");
	printf("     *	     3 删除账号		4 显示账号                 *\n");
	printf("     *	     5 储存账号		0 退出系统                *\n");
	printf("     ***************************************************\n");
}

void PrintAccountHeader()
{	printf(HEADER1Account);
	printf(HEADER2Account);
	printf(HEADER3Account);
}
void Wrong()          
{	printf("\n\n\n\n\n***********Error:输入有错! 敲任意键继续**********\n");
	getch();
}

void Nofind()        
{	printf("\n=====>未找到!\n");
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
		printf("\n====>暂无管理人员！\n");
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
			if(strcmp(temp[i].id,findmess)==0) //找到findmess值对应的号码 
				return i;
			i++;
		}
	}
	else if(strcmp(nameorphonenum,"name")==0)	
	{
		while(i<n)
		{
			if(strcmp(temp[i].name,findmess)==0)	//找到findmess值对应的姓名 
				return i;
			i++;
		}
	}
	//若找不到，返回-1 
	return -1;	
} 

void AccountStringInput(char* t,int lens,char* notice)
{
	
	char str[255];
	do
	{
		printf(notice);	//显示提示符 
		scanf("%s",str);
		//进行长度校验，超过lens值重新输入	
		if(strlen(str)>lens)
			printf("\n超过规定长度!\n");			
	}while(strlen(str)>lens); 
	//将输入的字条串保存到字符串t中 
	strcpy(t,str);
} 

int AddAccount(Account temp[],int n)
{
	char ch,num[10];
	int i;
	int flag = 0;
	system("cls");
	DispAccount(temp,n);
	while(1)	//一次可输入多条记录 
	{
		while(1)	
		{//输入记录编号，保证此编号没有使用，若输入编号为0，则退出添加记录操作 
			AccountStringInput(num,10,"输入编号(按'0'返回主菜单)：");	
			flag = 0;
			//输入为0，则退出并返回主菜单 
			if(strcmp(num,"0") == 0) return n;
			i = 0;
			//查询输入编号是否存在，若存在则要求重新输入
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
				printf("==>编号 %s 已经存在，再试一次？(y/n):",num);
				scanf("%c",&ch);
				if(ch == 'y' || ch == 'Y')
					continue;
				else	return n;
			}
			else break;		 
		}
		strcpy(temp[n].num,num);	//将字符串num拷贝到tem[n].num中
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
	int select;		//查询方式选项 
	char searchinput[20];	//保存用户输入的查询内容 
	int p=0;
	//若数组为空 
	if(n<=0)
	{
		system("cls");
		printf("\n====>管理人员册中无记录！\n"); 
		getchar();
	}
	system("cls");
	printf("\n		====>1 按人员名称查找\n");
	printf("\n		====>2 按人员Id查找\n");
	printf("		请输入选项编号[1,2]:");
	scanf("%d",&select);
	if(select == 1)		//按姓名查询 
	{
		AccountStringInput(searchinput,10,"请输入一个已经存在的人员名称:");
		//在temp中查找姓名为searchinput的记录
		p=LocateAccount(temp,n,searchinput,"name");
		if(p!=-1)
		{
			PrintAccountHeader();
			PrintAccountData(temp[p]);
			printf("敲任意键返回......");
			getch();
		}
		else   Nofind();
		getchar();	 
	}
	else if(select == 2)	//按电话号码查询
	{
		AccountStringInput(searchinput,10,"请输入一个已经存在的Id:");
		p=LocateAccount(temp,n,searchinput,"id");
		if(p!=-1)
		{
			PrintAccountHeader();
			PrintAccountData(temp[p]);
			printf(END);
			printf("敲任意键返回......");
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
		printf("\n====>管理人员无记录!\n");
		getchar();
		return n;
	}
	system("cls");
	DispAccount(temp,n);
	printf("\n		====>1 根据人员名称进行删除\n");
	printf("\n		====>2 根据人员Id进行删除\n");
	printf("\n	请选择[1,2]:\n");
	scanf("%d",&sel);
	if(sel==1)
	{
		AccountStringInput(findmess,10,"输入一个已有的人员名称：");
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
			printf("\n==>删除成功!\n");
			n--;
			getchar();
			accountsaveflag=1;
		} 
		else Nofind();
		getchar();
	}
	else if(sel == 2)
	{
		AccountStringInput(findmess,10,"请输入一个已经存在的Id：");
		p=LocateAccount(temp,n,findmess,"id");
		getchar();
		if(p!=-1)
		{
			//删除此记录，后面记录向前移 
			for(i=p+1;i<n;i++)
			{
				strcpy(temp[i-1].num,temp[i].num);
				strcpy(temp[i-1].name,temp[i].name);
				strcpy(temp[i-1].id,temp[i].id);
				strcpy(temp[i-1].password,temp[i].password);
			}
			printf("\n====>删除成功!\n");
			n--;
			getchar();
			accountsaveflag=1; 
		}
		else Nofind();
		getchar();		 
	} 
	return n;
}

//未增加Wrong(),Nofind()函数，调用管理系统中的两个相同函数 

void SaveAccount(Account account[],int n)
{
	FILE* fp;
	int i=0;
	fp=fopen("c:\\AccountInformation.txt","w");
	if(fp==NULL)
	{
		printf("\n====>打开文件失败！\n");
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
		printf("\n\n====>完成文件保存，全部保存的记录有：%d 条\n",i);
		getchar();
		accountsaveflag=0;
	}
	else
	{
		system("cls");
		printf("无新记录被保存!\n");
		getchar(); 
	}
	fclose(fp);
}

void HeadAccount(Account account[],int n){
	strcpy(account[0].num,"0");
	strcpy(account[0].name,"初始人员");
	strcpy(account[0].id,"666");
	strcpy(account[0].password,"888");
	//SaveAccount(account,n);
}
