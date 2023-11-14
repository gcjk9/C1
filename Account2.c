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
	printf("                     �ۻ���ϵͳ  \n");
	printf("                                        \n");
	printf("     ********************�û�ѡ��*******************\n");
	printf("     *	     1 �ۻ�Ա		2 �˿�             *\n");
	printf("     ***********************************************\n");
}

void ShoperMenu() {
	system("cls");
	printf("                     ��Ʒ����ϵͳ  \n");
	printf("                                        \n");
	printf("     ********************���˵�*************************\n");
	printf("     *	     1 ���Ӳ�Ʒ		2 ��ʾ��Ʒ             *\n");
	printf("     *	     3 ɾ����Ʒ		4 ��ѯ��Ʒ             *\n");
	printf("     *	     5 �޸Ĳ�Ʒ		6 �����Ʒ             *\n");
	printf("     *	     7 �����Ʒ		8 �����¼             *\n");
	printf("     *	     9 �˺�ϵͳ	   10 ͳ�ƽ��   0 �˳�ϵͳ*\n");
	printf("     ***************************************************\n");
}
void CustomsMenu() {
	system("cls");
	printf("                     �˿͹���ϵͳ  \n");
	printf("                                        \n");
	printf("     ********************���˵�*************************\n");
	printf("     *	     1 ��ʾ��Ʒ		2 ��ѯ��Ʒ             *\n");
	printf("     *	     3 �����Ʒ		4 �����Ʒ  0 �˳�ϵͳ *\n");
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
	printf("���������������");
	return -1;
	}
	else{
		return i;
	} 
}

void Disp(GOODS temp[],int n) {
	int i;
	if(n==0)
		printf("\n====>�������������Ʒ��\n");
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
		printf("\n====>����������޼�¼!\n");
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
			printf("\n�����涨����!\n");
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
			stringinput(num,10,"������(��'0'�������˵�)��");
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
				printf("==>��� %s �Ѿ����ڣ�����һ�Σ�(y/n):",num);
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
		printf("\n====>��Ʒ�嵥���޼�¼��\n");
		getchar();
	}
	system("cls");
	printf("\n		====>1 ����Ʒ���Ʋ���\n");
	printf("\n		====>2 ����Ʒ��Ų���\n");
	printf("		������ѡ����[1,2]:");
	scanf("%d",&select);
	if(select == 1) {
		stringinput(searchinput,10,"������һ���Ѿ����ڵ���Ʒ����:");
		p=Locate(temp,n,searchinput,"name");
		if(p!=-1) {
			printheader();
			printdata(temp[p]);
			printf("�����������......");
			getch();
		} else   Nofind();
		getchar();
	} else if(select == 2) {
		stringinput(searchinput,10,"������һ���Ѿ����ڵı��:");
		p=Locate(temp,n,searchinput,"num");
		if(p!=-1) {
			printheader();
			printdata(temp[p]);
			printf(END);
			printf("�����������......");
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
		printf("\n====>��Ʒ�嵥�޼�¼!\n");
		getchar();
		return n;
	}
	system("cls");
	Disp(temp,n);
	printf("\n		====>1 ������Ʒ���ƽ���ɾ��\n");
	printf("\n		====>2 ������Ʒ��Ž���ɾ��\n");
	printf("\n	��ѡ��[1,2]:\n");
	scanf("%d",&sel);
	if(sel==1) {
		stringinput(findmess,10,"����һ�����е���Ʒ���ƣ�");
		p=Locate(temp,n,findmess,"name");
		getchar();
		if(p!=-1) {
			printf("�Ƿ�ɾ������1/0��");
			while(isdel!=1&&isdel!=0){
				printf("�����룡");
				isdel=PD();	
			}
			if(isdel==1){		
			for(i=p+1; i<n; i++) {
				strcpy(temp[i-1].num,temp[i].num);
				strcpy(temp[i-1].name,temp[i].name);
				strcpy(temp[i-1].price,temp[i].price);
				strcpy(temp[i-1].sum,temp[i].sum);
			}
			printf("\n==>ɾ���ɹ�!\n");
			n--;
			getchar();
			saveflag=1;
			}
			else {
				printf("\n==>ɾ��ʧ��!\n");
			};
		} else Nofind();
		getchar();
	} else if(sel == 2) {
		stringinput(findmess,10,"������һ���Ѿ����ڵı�ţ�");
		p=Locate(temp,n,findmess,"num");
		getchar();
		if(p!=-1) {
			printf("�Ƿ�ɾ������1/0��");
			
			while(isdel!=1&&isdel!=0){
				printf("�����룡");
				isdel=PD();	
			}
			if(isdel==1){
			for(i=p+1; i<n; i++) {
				strcpy(temp[i-1].num,temp[i].num);
				strcpy(temp[i-1].name,temp[i].name);
				strcpy(temp[i-1].price,temp[i].price);
				strcpy(temp[i-1].sum,temp[i].sum);
			}
			printf("\n====>ɾ���ɹ�!\n");
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
		printf("\n ====>��Ʒ�嵥�޼�¼��\n");
		getchar();
	}
	system("cls");
	printf("�޸���Ʒ��Ϣ��¼");
	Disp(temp,n);
	stringinput(findmess,10,"������һ���Ѿ����ڵ���Ʒ���֣�");
	p=Locate(temp,n,findmess,"name");
	if(p!=-1) {
		printf("Number:%s,\n",temp[p].num);
		printf("Name:%s,",temp[p].name);
		stringinput(temp[p].name,15,"��������Ʒ���֣�");
		printf("Name:%s,",temp[p].price);
		stringinput(temp[p].price,15,"��������Ʒ�۸�");
		printf("Name:%s,",temp[p].sum);
		stringinput(temp[p].sum,15,"��������Ʒ������");
		printf("\n ====>�޸ĳɹ���\n");
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
		printf("\n		====>1 �޸ı��\n");
		printf("\n		====>2 �޸�����\n");
		printf("\n		====>3 �޸ļ۸�\n");
		printf("\n		====>4 �޸�����\n");
		printf("\n	��ѡ��[1,4]:\n");
		select=PD(); 
		if(select<5&&select>0){
		switch(select){
			case 1:
				printf("Num:%s,",temp[p].num);
			stringinput(temp[p].num,15,"��������Ʒ��ţ�");
			break; 
			case 2:
				printf("Name:%s,",temp[p].name);
			stringinput(temp[p].name,15,"��������Ʒ���ƣ�");
			break; 
			case 3:
				printf("Price:%s,",temp[p].price);
			stringinput(temp[p].price,15,"��������Ʒ�۸�");
			break; 
			case 4:
				printf("Sum:%s,",temp[p].sum);
			stringinput(temp[p].sum,15,"��������Ʒ������");
			break; 
		}
	}
	else{
		printf("�������");
	}
		
		printf("\n ====>�޸ĳɹ���\n");
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
		printf("\n ====>��Ʒ�嵥�޼�¼��\n");
		getchar();
	}
	system("cls");
	printf("�޸���Ʒ��Ϣ��¼");
	Disp(temp,n);
	printf("\n		====>1 ���ݱ���޸�\n");
	printf("\n		====>2 ���������޸�\n");
	printf("\n	��ѡ��[1,2]:\n");
	select=PD();
	if(select<3&&select>0){
		switch(select){
			case 1:
				stringinput(findmess,10,"������һ���Ѿ����ڵ���Ʒ��ţ�");
				p=Locate(temp,n,findmess,"num");
				Mod(p,temp,n);
				break;
			case 2:
				stringinput(findmess,10,"������һ���Ѿ����ڵ���Ʒ���֣�");
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
		stringinput(s,10,"������һ����¼��ţ�������ļ�¼��λ�ڸü�¼�ĺ���:");
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
			printf("\n====>���%s �����ڣ�����һ�Σ�(1/0):",s);
			scanf("%d",&ch);
			if(ch==1)
				continue;
			else
				return n;
		}
	}

	while(1) {
		stringinput(num,10,"�������µı�ţ�");
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
			printf("\n====>Sorry,��� %s �Ѿ����ڣ�����һ��?(y/n):",num);
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
		printf("\n====>���޼�¼��\n");
		getchar();
	}
	system("cls");
	Disp(temp,n);
	getchar();
	printf("	==>1 �������������	 ==>2 ���۸���������   \n");
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
		printf("\n	====>�������!\n");
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
		printf("\n		====>�������\n");
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
		printf("\n====>���ļ�ʧ��!\n");
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
		printf("\n\n====>����ļ����棬ȫ������ļ�¼�У�%d ��\n",i);
		getchar();
		saveflag=0;
	} else {
		system("cls");
		printf("���¼�¼������!\n");
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
	int select;		//��ѯ��ʽѡ�� 
	char searchinput[20];	//�����û�����Ĳ�ѯ���� 
	int p[5];
	int q;
	int sum;
	int i;
	//������Ϊ�� 
	if(n<=0)
	{
		system("cls");
		printf("\n====>�绰�����޼�¼��\n"); 
		getchar();
	}
	system("cls");
	printf("\n		====>1 �����Ʋ���\n");
	printf("\n		====>2 ����Ų���\n");
	printf("		������ѡ����[1,2]:");
	scanf("%d",&select);
	if(select == 1)		//��������ѯ 
	{
		stringinput(searchinput,10,"������һ���Ѿ����ڵĲ�Ʒ����:");
		//��temp�в�������Ϊsearchinput�ļ�¼
		sum=Locatea(temp,n,searchinput,"name",p);
		if(sum!=-1)
		{
			printheader();
			for(i=0;i<sum;i++){	
			printdata(temp[p[i]]);
			printf(HEADER3);
		}
			printf("�����������......");
			getch();
		}
		else   Nofind();
		getchar();	 
	}
	else if(select == 2)	//���绰�����ѯ
	{
		stringinput(searchinput,10,"������һ���Ѿ����ڵĲ�Ʒ���:");
		q=Locate(temp,n,searchinput,"num");
		if(q!=-1)
		{
			printheader();
			printdata(temp[q]);
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

void BuyGoods(GOODS temp[],int n) {
	char findmess[20];
	int p=0;
	int i=0;

	if(n<=0) {
		system("cls");
		printf("\n ====>��Ʒ�嵥�޼�¼��\n");
		getchar();
	}
	system("cls");
	printf("������Ʒ��Ϣ��¼");
	Disp(temp,n);
	stringinput(findmess,10,"������һ���Ѿ����ڵ���Ʒ��ţ�");
	p=Locate(temp,n,findmess,"num");
	if(p!=-1) {
		printf("��Ʒ�����:%s,\n",temp[p].num);
		printf("��Ʒ������:%s\n",temp[p].name);
		printf("��Ʒʣ�������%s\n",temp[p].sum);
		if(*temp[p].sum=='0') {
			printf("����Ʒ���ۿգ�");
		} else {
			int i;
			int isbuy;
			int t=0;
			int s;
			char c[6];
			printf("����Ʒ�ļ۸�Ϊ:%s\n",temp[p].price);
			printf("�Ƿ���(1/0)");
			scanf("%d",&isbuy);
			if(isbuy == 1) {
				s=atoi(temp[p].sum)-1;
				itoa(s,c,10);
				//int sumGoods=(int)*temp[p].sum-1;
				//char *ptr=(char *)&sumGoods;
				//for(i=0; i<sizeof(4); i++) c[i]=ptr[i];
				strcpy(temp[p].sum,c);
				temp[0].total+=atoi(temp[p].price);
				printf("\n ====>����ɹ���\n");

				printf("����Ʒʣ�������%s",temp[p].sum);
				getchar();
			} else {
				printf("ȡ������ɹ���");
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
	strcpy(goods[0].name,"��");
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
	printf("\n====>�ɹ����ļ����ܹ���%d����¼.\n",count);
	printf("\n �����������");
	
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
	printf("\n====>�ɹ����ļ����ܹ���%d��������Ա��¼.\n",accountcount);
	printf("\n �����������");
	getchar();

	if(accountcount==0) {
		accountcount++;
		HeadAccount(account,accountcount);
	}


	while(1) {
		system("cls");
		SelectUser();
		printf("\n             ���������ѡ��0~2:");
		select=PD();
		if(select==0) {
			if(saveflag == 1) {
				getchar();
				printf("\n==>�Ƿ�Ҫ���Ѿ��޸ĵļ�¼���浽�ļ���(1/0):");
				scanf("%d",&ch);
				if(ch == 1)
					Save(good,count);
			}
			printf("\n===>лл��ʹ�ñ�ϵͳ��");
			getchar();
			break;
		}
		int i,j;
		char id[10];
		char pw[10];
		switch(select) {
			case 1:
				printf("�������ʺţ�\n");
				scanf("%s",id);
				printf("���������룺\n");
				scanf("%s",pw);
				if(PassAccount(account,accountcount,id,pw)==1) {

					while(1) {
						ShoperMenu();
						printf("\n             a���������ѡ��0~9:");
						select=PD();
						if(select==0) {
							if(saveflag == 1) {
								getchar();
								printf("\n==>�Ƿ�Ҫ���Ѿ��޸ĵļ�¼���浽�ļ���(y/n):");
								scanf("%c",&ch);
								if(ch == 'y' || ch == 'Y')
									Save(good,count);
							}
							printf("\n===>лл��ʹ�ñ�ϵͳ��");
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
									printf("\n             ���������ѡ��0~4:");
									select=PD();
									if(select==0) {
										if(accountsaveflag == 1) {
											getchar();
											printf("\n==>�Ƿ�Ҫ���Ѿ��޸ĵļ�¼���浽�ļ���(1/0):");
											scanf("%d",&ch);
											if(ch ==1)
												SaveAccount(account,accountcount);
										}
										printf("\n===>лл��ʹ�ñ�ϵͳ��");
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
									 printf("�����۶�Ϊ��%dԪ",good[0].total);

							default:
								Wrong();
								getchar();
								break;
						}
					}
				} else if(PassAccount(account,accountcount,id,pw)==0) {
					printf("��������\n");
				} else {
					printf("�˺Ż���������\n");
					printf("�����������");
					getchar();
					getchar();
				}
				break;
			case 2:
				while(1) {
					CustomsMenu();
					printf("\n             ���������ѡ��0~4:");
					select=PD();
					if(select==0) {
						if(saveflag == 1) {
							getchar();
							printf("\n==>�Ƿ�Ҫ���Ѿ��޸ĵļ�¼���浽�ļ���(1/0):");
							scanf("%d",&ch);
							if(ch ==1)
								Save(good,count);
						}
						printf("\n===>лл��ʹ�ñ�ϵͳ��");
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









