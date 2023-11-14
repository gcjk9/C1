#include "Account.h"

int saveflag=0;

typedef struct goods {
	char num[6];
	char name[6];
	char price[6];
	char sum[6];
	int total;
} GOODS;

void SelectUser() {
	printf("                     售货机系统  \n");
	printf("                                        \n");
	printf("     ********************用户选择*******************\n");
	printf("     *	     1 售货员		2 顾客             *\n");
	printf("     ***********************************************\n");
}

void ShoperMenu() {
	system("cls");
	printf("                     产品管理系统  \n");
	printf("                                        \n");
	printf("     ********************主菜单*************************\n");
	printf("     *	     1 增加产品		2 显示产品             *\n");
	printf("     *	     3 删除产品		4 查询产品             *\n");
	printf("     *	     5 修改产品		6 插入产品             *\n");
	printf("     *	     7 排序产品		8 保存记录             *\n");
	printf("     *	     9 账号系统	   10 统计结果   0 退出系统*\n");
	printf("     ***************************************************\n");
}
void CustomsMenu() {
	system("cls");
	printf("                     顾客购物系统  \n");
	printf("                                        \n");
	printf("     ********************主菜单*************************\n");
	printf("     *	     1 显示产品		2 查询产品             *\n");
	printf("     *	     3 排序产品		4 购买产品  0 退出系统 *\n");
	printf("     ***************************************************\n");
}

void printheader() {
	printf(HEADER1);
	printf(HEADER2);
	printf(HEADER3);
}

void printdata(GOODS pp) {
	GOODS *p;
	p=&pp;
	printf(FORMAT,DATA);
}

int PD(){
	int i,r;
	r=scanf ("%d", &i);
	
	if(r==0){
	printf("输入错误，重新输入");
	return -1;
	}
	else{
		return i;
	} 
}

void Disp(GOODS temp[],int n) {
	int i;
	if(n==0)
		printf("\n====>购物机中暂无商品！\n");
	else {
		printf("\n\n");
		printheader();
		i=1;
		while(i<n) {
			printdata(temp[i]);
			i++;
			printf(HEADER3);
		}
	}
}

void Dispa(GOODS *temp,int n)
{
	int i;
	if(n == 0)
		printf("\n====>购物机中尚无记录!\n");
	else
	{
		printf("\n\n");
		printheader();
		i = 1;
		while(i<n)
		{
			printdata(temp[i]);
			i++;
			printf(HEADER3);
		}
	}
} 




int Locate(GOODS temp[],int n,char findmess[],char nameorphonenum[]) {
	int i = 0;
	if(strcmp(nameorphonenum,"num") == 0) {
		while(i<n) {
			if(strcmp(temp[i].num,findmess)==0)
				return i;
			i++;
		}
	} else if(strcmp(nameorphonenum,"name")==0) {
		while(i<n) {
			if(strcmp(temp[i].name,findmess)==0)
				return i;
			i++;
		}
	}
	return -1;
}

void stringinput(char* t,int lens,char* notice) {

	char str[255];
	do {
		printf(notice);
		scanf("%s",str);
		if(strlen(str)>lens)
			printf("\n超过规定长度!\n");
	} while(strlen(str)>lens);
	strcpy(t,str);
}


int Add(GOODS temp[],int n) {
	char ch,num[10];
	int i;
	int flag = 0;
	system("cls");
	Disp(temp,n);
	while(1) {
		while(1) {
			stringinput(num,10,"输入编号(按'0'返回主菜单)：");
			flag = 0;
			if(strcmp(num,"0") == 0) return n;
			i = 0;
			while(i<n) {
				if(strcmp(temp[i].num,num) == 0) {
					flag =1;
					break;
				}
				i++;
			}
			if(flag == 1) {
				getchar();
				printf("==>编号 %s 已经存在，再试一次？(y/n):",num);
				scanf("%c",&ch);
				if(ch == 'y' || ch == 'Y')
					continue;
				else	return n;
			} else break;
		}
		strcpy(temp[n].num,num);
		stringinput(temp[n].name,15,"Name:");
		stringinput(temp[n].price,15,"price:");
		stringinput(temp[n].sum,15,"Sum:");
		saveflag = 1;
		n++;
	}
	return n;
}


void Qur(GOODS temp[],int n) {
	int select;
	char searchinput[20];
	int p=0;
	if(n<=0) {
		system("cls");
		printf("\n====>商品清单中无记录！\n");
		getchar();
	}
	system("cls");
	printf("\n		====>1 按商品名称查找\n");
	printf("\n		====>2 按商品编号查找\n");
	printf("		请输入选项编号[1,2]:");
	scanf("%d",&select);
	if(select == 1) {
		stringinput(searchinput,10,"请输入一个已经存在的商品名称:");
		p=Locate(temp,n,searchinput,"name");
		if(p!=-1) {
			printheader();
			printdata(temp[p]);
			printf("敲任意键返回......");
			getch();
		} else   Nofind();
		getchar();
	} else if(select == 2) {
		stringinput(searchinput,10,"请输入一个已经存在的编号:");
		p=Locate(temp,n,searchinput,"num");
		if(p!=-1) {
			printheader();
			printdata(temp[p]);
			printf(END);
			printf("敲任意键返回......");
			getchar();
		} else Nofind();
		getchar();
	} else Wrong();
	getchar();
}


int Del(GOODS temp[],int n) {
	int sel,isdel=-1;
	char findmess[20];
	int p=0,i=0;
	if(n<=0) {
		system("cls");
		printf("\n====>商品清单无记录!\n");
		getchar();
		return n;
	}
	system("cls");
	Disp(temp,n);
	printf("\n		====>1 根据商品名称进行删除\n");
	printf("\n		====>2 根据商品编号进行删除\n");
	printf("\n	请选择[1,2]:\n");
	scanf("%d",&sel);
	if(sel==1) {
		stringinput(findmess,10,"输入一个已有的商品名称：");
		p=Locate(temp,n,findmess,"name");
		getchar();
		if(p!=-1) {
			printf("是否删除？（1/0）");
			while(isdel!=1&&isdel!=0){
				printf("请输入！");
				isdel=PD();	
			}
			if(isdel==1){		
			for(i=p+1; i<n; i++) {
				strcpy(temp[i-1].num,temp[i].num);
				strcpy(temp[i-1].name,temp[i].name);
				strcpy(temp[i-1].price,temp[i].price);
				strcpy(temp[i-1].sum,temp[i].sum);
			}
			printf("\n==>删除成功!\n");
			n--;
			getchar();
			saveflag=1;
			}
			else {
				printf("\n==>删除失败!\n");
			};
		} else Nofind();
		getchar();
	} else if(sel == 2) {
		stringinput(findmess,10,"请输入一个已经存在的编号：");
		p=Locate(temp,n,findmess,"num");
		getchar();
		if(p!=-1) {
			printf("是否删除？（1/0）");
			
			while(isdel!=1&&isdel!=0){
				printf("请输入！");
				isdel=PD();	
			}
			if(isdel==1){
			for(i=p+1; i<n; i++) {
				strcpy(temp[i-1].num,temp[i].num);
				strcpy(temp[i-1].name,temp[i].name);
				strcpy(temp[i-1].price,temp[i].price);
				strcpy(temp[i-1].sum,temp[i].sum);
			}
			printf("\n====>删除成功!\n");
			n--;
			getchar();
			saveflag=1;
		}
		else{
			
		};
		} else Nofind();
		getchar();
	}
	return n;
}

void Modify(GOODS temp[],int n) {
	char findmess[20];
	int p=0;
	if(n<=0) {
		system("cls");
		printf("\n ====>商品清单无记录！\n");
		getchar();
	}
	system("cls");
	printf("修改商品信息记录");
	Disp(temp,n);
	stringinput(findmess,10,"请输入一个已经存在的商品名字：");
	p=Locate(temp,n,findmess,"name");
	if(p!=-1) {
		printf("Number:%s,\n",temp[p].num);
		printf("Name:%s,",temp[p].name);
		stringinput(temp[p].name,15,"请输入商品名字：");
		printf("Name:%s,",temp[p].price);
		stringinput(temp[p].price,15,"请输入商品价格：");
		printf("Name:%s,",temp[p].sum);
		stringinput(temp[p].sum,15,"请输入商品数量：");
		printf("\n ====>修改成功！\n");
		getchar();
		Disp(temp,n);
		getchar();
		saveflag=1;
	} else {
		Nofind();
		getchar();
	}
}
void  Mod(int p,GOODS temp[],int n){
	int select;
	if(p!=-1) {
		printf("\n		====>1 修改编号\n");
		printf("\n		====>2 修改名字\n");
		printf("\n		====>3 修改价格\n");
		printf("\n		====>4 修改数量\n");
		printf("\n	请选择[1,4]:\n");
		select=PD(); 
		if(select<5&&select>0){
		switch(select){
			case 1:
				printf("Num:%s,",temp[p].num);
			stringinput(temp[p].num,15,"请输入商品编号：");
			break; 
			case 2:
				printf("Name:%s,",temp[p].name);
			stringinput(temp[p].name,15,"请输入商品名称：");
			break; 
			case 3:
				printf("Price:%s,",temp[p].price);
			stringinput(temp[p].price,15,"请输入商品价格：");
			break; 
			case 4:
				printf("Sum:%s,",temp[p].sum);
			stringinput(temp[p].sum,15,"请输入商品数量：");
			break; 
		}
	}
	else{
		printf("输入错误！");
	}
		
		printf("\n ====>修改成功！\n");
		getchar();
		Disp(temp,n);
		getchar();
		saveflag=1;
	} else {
		Nofind();
		getchar();
	}
}

void Modifya(GOODS temp[],int n) {
	char findmess[20];
	int p=0;
	int select;
	if(n<=0) {
		system("cls");
		printf("\n ====>商品清单无记录！\n");
		getchar();
	}
	system("cls");
	printf("修改商品信息记录");
	Disp(temp,n);
	printf("\n		====>1 根据编号修改\n");
	printf("\n		====>2 根据名称修改\n");
	printf("\n	请选择[1,2]:\n");
	select=PD();
	if(select<3&&select>0){
		switch(select){
			case 1:
				stringinput(findmess,10,"请输入一个已经存在的商品编号：");
				p=Locate(temp,n,findmess,"num");
				Mod(p,temp,n);
				break;
			case 2:
				stringinput(findmess,10,"请输入一个已经存在的商品名字：");
				p=Locate(temp,n,findmess,"name");
				Mod(p,temp,n);
				break;
		}
	} 
	
}

int Insert(GOODS temp[],int n) {
	int ch;
	char num[10],s[10];
	GOODS newinfo;
	int flag=0,i=0,kkk=0;
	system("cls");
	Disp(temp,n);
	while(1) {
		stringinput(s,10,"请输入一个记录编号，待播入的记录将位于该记录的后面:");
		flag=0;
		i=0;
		while(i<n) {
			if(strcmp(temp[i].num,s)==0) {
				kkk=i;
				flag=1;
				break;
			}
			i++;
		}
		if(flag==1)
			break;
		else {
			getchar();
			printf("\n====>编号%s 不存在，再试一次？(1/0):",s);
			scanf("%d",&ch);
			if(ch==1)
				continue;
			else
				return n;
		}
	}

	while(1) {
		stringinput(num,10,"请输入新的编号：");
		i=0;
		flag=0;
		while(i<n) {
			if(strcmp(temp[i].num,num)==0) {
				flag=1;
				break;
			}
			i++;
		}
		if(flag==1) {
			getchar();
			printf("\n====>Sorry,编号 %s 已经存在，再试一次?(y/n):",num);
			scanf("%d",&ch);
			if(ch==1)
				continue;
			else
				return n;
		} else break;
	}
	strcpy(newinfo.num,num);
	stringinput(newinfo.name,15,"Name:");
	stringinput(newinfo.price,15,"Price:");
	stringinput(newinfo.sum,15,"Sum:");

	saveflag=1;
	for(i=n-1; i>kkk; i--) {
		strcpy(temp[i+1].num,temp[i].num);
		strcpy(temp[i+1].name,temp[i].name);
		strcpy(temp[kkk+1].price,newinfo.price);
		strcpy(temp[kkk+1].sum,newinfo.sum);
	}
	strcpy(temp[kkk+1].num,newinfo.num);
	strcpy(temp[kkk+1].name,newinfo.name);
	strcpy(temp[kkk+1].price,newinfo.price);
	strcpy(temp[kkk+1].sum,newinfo.sum);

	n++;
	Disp(temp,n);
	printf("\n\n");
	getchar();
	return n;
}

void SelectSort(GOODS temp[],int n) {
	int i,j,indexmin,select;
	GOODS newinfo;
	if(n<=0) {
		system("cls");
		printf("\n====>尚无记录！\n");
		getchar();
	}
	system("cls");
	Disp(temp,n);
	getchar();
	printf("	==>1 按编号升序排序	 ==>2 按价格升序排序   \n");
	scanf("%d",&select);
	if(select==1) {
		for(i=0; i<n; i++) {
			indexmin=i;
			for(j=i+1; j<n; j++)
				if(strcmp(temp[j].num,temp[indexmin].num)<0)
					indexmin=j;
			newinfo=temp[i];
			temp[i]=temp[indexmin];
			temp[indexmin]=newinfo;
		}
		Disp(temp,n);
		getchar();
		saveflag=1;
		printf("\n	====>完成排序!\n");
		getchar();
	} else if(select==2) {
		for(i=0; i<n; i++) {
			indexmin=i;
			for(j=i+1; j<n; j++)
				if(strcmp(temp[j].price,temp[indexmin].price)<0)
					indexmin=j;
			newinfo=temp[i];
			temp[i]=temp[indexmin];
			temp[indexmin]=newinfo;
		}
		Disp(temp,n);
		getchar();
		saveflag=1;
		printf("\n		====>完成排序！\n");
		getchar();
	} else {
		Wrong();
		getchar();
	}
}



void Save(GOODS good[],int n) {
	FILE* fp;
	int i=0;
	fp=fopen("c:\\ShoppingMachine.txt","w");
	if(fp==NULL) {
		printf("\n====>打开文件失败!\n");
		getchar();
	}
	for(i=0; i<n; i++) {
		if(fwrite(&good[i],sizeof(GOODS),1,fp)==1)
			continue;
		else
			break;
	}
	if(i>0) {
		getchar();
		printf("\n\n====>完成文件保存，全部保存的记录有：%d 条\n",i);
		getchar();
		saveflag=0;
	} else {
		system("cls");
		printf("无新记录被保存!\n");
		getchar();
	}
	fclose(fp);
}

int PassAccount(Account account[],int n,char id[],char password[]) {
	int i=0;
	while(i<n) {
		if(strcmp(account[i].id,id)==0) {
			if(strcmp(account[i].password,password)==0)
				return 1;
			else
				return 0;
		}
		i++;
	}
	return -1;
}

int Locatea(GOODS temp[],int n,char findmess[],char nameorphonenum[],int p[]) {
	int i = 0;
	int sum=0;
	if(strcmp(nameorphonenum,"num") == 0) {
		while(i<n) {
			if(strcmp(temp[i].num,findmess)==0)
				return i;
			i++;
		}
	} else if(strcmp(nameorphonenum,"name")==0) {
		while(i<n) {
			if(strcmp(temp[i].name,findmess)==0)
			{
			    p[sum]=i;
				sum++;
			}
			i++;
		}
		sum;
		return sum;
	}
	return -1;
}

void Qura(GOODS temp[],int n)
{
	int select;		//查询方式选项 
	char searchinput[20];	//保存用户输入的查询内容 
	int p[5];
	int q;
	int sum;
	int i;
	//若数组为空 
	if(n<=0)
	{
		system("cls");
		printf("\n====>电话簿中无记录！\n"); 
		getchar();
	}
	system("cls");
	printf("\n		====>1 按名称查找\n");
	printf("\n		====>2 按编号查找\n");
	printf("		请输入选项编号[1,2]:");
	scanf("%d",&select);
	if(select == 1)		//按姓名查询 
	{
		stringinput(searchinput,10,"请输入一个已经存在的产品名称:");
		//在temp中查找姓名为searchinput的记录
		sum=Locatea(temp,n,searchinput,"name",p);
		if(sum!=-1)
		{
			printheader();
			for(i=0;i<sum;i++){	
			printdata(temp[p[i]]);
			printf(HEADER3);
		}
			printf("敲任意键返回......");
			getch();
		}
		else   Nofind();
		getchar();	 
	}
	else if(select == 2)	//按电话号码查询
	{
		stringinput(searchinput,10,"请输入一个已经存在的产品编号:");
		q=Locate(temp,n,searchinput,"num");
		if(q!=-1)
		{
			printheader();
			printdata(temp[q]);
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

void BuyGoods(GOODS temp[],int n) {
	char findmess[20];
	int p=0;
	int i=0;

	if(n<=0) {
		system("cls");
		printf("\n ====>商品清单无记录！\n");
		getchar();
	}
	system("cls");
	printf("购买商品信息记录");
	Disp(temp,n);
	stringinput(findmess,10,"请输入一个已经存在的商品编号：");
	p=Locate(temp,n,findmess,"num");
	if(p!=-1) {
		printf("商品编号是:%s,\n",temp[p].num);
		printf("商品名称是:%s\n",temp[p].name);
		printf("商品剩余件数：%s\n",temp[p].sum);
		if(*temp[p].sum=='0') {
			printf("该商品已售空！");
		} else {
			int i;
			int isbuy;
			int t=0;
			int s;
			char c[6];
			printf("该商品的价格为:%s\n",temp[p].price);
			printf("是否购买？(1/0)");
			scanf("%d",&isbuy);
			if(isbuy == 1) {
				s=atoi(temp[p].sum)-1;
				itoa(s,c,10);
				//int sumGoods=(int)*temp[p].sum-1;
				//char *ptr=(char *)&sumGoods;
				//for(i=0; i<sizeof(4); i++) c[i]=ptr[i];
				strcpy(temp[p].sum,c);
				temp[0].total+=atoi(temp[p].price);
				printf("\n ====>购买成功！\n");

				printf("该商品剩余件数：%s",temp[p].sum);
				getchar();
			} else {
				printf("取消购买成功！");
			}
		}
		getchar();
		Save(temp,n);
		saveflag=1;
	} else {
		Nofind();
		getchar();
	}
}

void HeadGoods(GOODS goods[],int n){
	strcpy(goods[0].num,"00");
	strcpy(goods[0].name,"空");
	strcpy(goods[0].price,"00");
	strcpy(goods[0].sum,"00");
	goods[0].total=0;
}

int main(int argc,char *argv[]) {
	GOODS good[N];
	Account account[N];
	FILE* fp;
	FILE* fpaccount;
	int select;
	int ch;
	int count=0;
	int accountcount=0;
	fp=fopen("c:\\ShoppingMachine.txt","a+");
	if(fp==NULL) {
		printf("\n======>can not open file!\n");
		exit(0);
	}

	while(!feof(fp))
		if(fread(&good[count],sizeof(GOODS),1,fp)==1)
			count++;
	fclose(fp);
	printf("\n====>成功打开文件，总共有%d条记录.\n",count);
	printf("\n 按任意键继续");
	
		if(count==0) {
		count++;
		HeadGoods(good,count);
	}

	fpaccount=fopen("c:\\AccountInformation.txt","a+");
	if(fpaccount==NULL) {
		printf("\n======>can not open file!\n");
		exit(0);
	}
	while(!feof(fpaccount))
		if(fread(&account[accountcount],sizeof(Account),1,fpaccount)==1)
			accountcount++;
	fclose(fpaccount);
	printf("\n====>成功打开文件，总共有%d条管理人员记录.\n",accountcount);
	printf("\n 按任意键继续");
	getchar();

	if(accountcount==0) {
		accountcount++;
		HeadAccount(account,accountcount);
	}


	while(1) {
		system("cls");
		SelectUser();
		printf("\n             请输入你的选择0~2:");
		select=PD();
		if(select==0) {
			if(saveflag == 1) {
				getchar();
				printf("\n==>是否要将已经修改的记录保存到文件？(1/0):");
				scanf("%d",&ch);
				if(ch == 1)
					Save(good,count);
			}
			printf("\n===>谢谢您使用本系统！");
			getchar();
			break;
		}
		int i,j;
		char id[10];
		char pw[10];
		switch(select) {
			case 1:
				printf("请输入帐号：\n");
				scanf("%s",id);
				printf("请输入密码：\n");
				scanf("%s",pw);
				if(PassAccount(account,accountcount,id,pw)==1) {

					while(1) {
						ShoperMenu();
						printf("\n             a请输入你的选择0~9:");
						select=PD();
						if(select==0) {
							if(saveflag == 1) {
								getchar();
								printf("\n==>是否要将已经修改的记录保存到文件？(y/n):");
								scanf("%c",&ch);
								if(ch == 'y' || ch == 'Y')
									Save(good,count);
							}
							printf("\n===>谢谢您使用本系统！");
							getchar();
							break;
						}
						switch(select) {

							case 1:
								count = Add(good,count);
								break;

							case 2:
								system("cls");
								Disp(good,count);
								getch();
								break;

							case 3:
								count =Del(good,count);
								break;

							case 4:
								Qur(good,count);
								getch();
								break;

							case 5:
								Modifya(good,count);
								break;

							case 6:
								count = Insert(good,count);
								break;

							case 7:
								SelectSort(good,count);
								break;

							case 8:
								Save(good,count);
								break;
							case 9:
								while(1) {
									AccountMenu();
									printf("\n             请输入你的选择0~4:");
									select=PD();
									if(select==0) {
										if(accountsaveflag == 1) {
											getchar();
											printf("\n==>是否要将已经修改的记录保存到文件？(1/0):");
											scanf("%d",&ch);
											if(ch ==1)
												SaveAccount(account,accountcount);
										}
										printf("\n===>谢谢您使用本系统！");
										getchar();
										break;
									}
									switch(select) {

										case 1:
											system("cls");
											accountcount = AddAccount(account,accountcount);
											getch();
											break;

										case 2:
											QurAccount(account,accountcount);
											getch();
											break;

										case 3:
											accountcount = DelAccount(account,accountcount);
											break;

										case 4:
											DispAccount(account,accountcount);
											getch();
											break;

										case 5:
											SaveAccount(account,accountcount);
											getch();
											break;

										default:
											Wrong();
											getchar();
											break;
									}
								}
								break;
								case 10:
									 printf("总销售额为：%d元",good[0].total);

							default:
								Wrong();
								getchar();
								break;
						}
					}
				} else if(PassAccount(account,accountcount,id,pw)==0) {
					printf("密码有误！\n");
				} else {
					printf("账号或密码有误！\n");
					printf("按任意键返回");
					getchar();
					getchar();
				}
				break;
			case 2:
				while(1) {
					CustomsMenu();
					printf("\n             请输入你的选择0~4:");
					select=PD();
					if(select==0) {
						if(saveflag == 1) {
							getchar();
							printf("\n==>是否要将已经修改的记录保存到文件？(1/0):");
							scanf("%d",&ch);
							if(ch ==1)
								Save(good,count);
						}
						printf("\n===>谢谢您使用本系统！");
						getchar();
						break;
					}
					switch(select) {

						case 1:
							system("cls");
							Dispa(&good[0],count);
							getch();
							break;

						case 2:
							Qura(good,count);
							getch();
							break;

						case 3:
							SelectSort(good,count);
							break;

						case 4:
							BuyGoods(good,count);
							getch();
							break;


						default:
							Wrong();
							getchar();
							break;
					}
				}

				break;

		}

	}

}









