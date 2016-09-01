/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"product.h"

void printHead( )      /*��ӡ��Ʒ��Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%6s%6s\n","","��Ʒ���","����","Ʒ��","�۸�","���");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2.��Ʒ��Ϣ���� ********\n");
		printf("******** 3.��Ʒ���ͳ�� ********\n");
     printf("********  4. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ������Ʒ��¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����Ʒ��¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸���Ʒ��¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuPrice( )     /*3����Ʒ�۸����˵�����*/
{
		printf("@@@@@@@@ 1. ������Ʒ�ܼ� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ���ݼ۸����� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4����Ʒ���ͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ����϶� &&&&&&&&\n");
		printf("&&&&&&&& 2. �������� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ����Ʒ��Ų�ѯ   ########\n");
		printf("######## 2. �����Ʋ�ѯ   ########\n");
		printf("######## 3. ��Ʒ�Ʋ�ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Product pro[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{  
		int choice,t,find[NUM];
     Product s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readPro(&s,1);       /*����һ�����������Ʒ��¼*/
					 n=insertPro(pro,n,s);   /*���ú���������Ʒ��¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ������Ʒ���*/
					 n=deletePro(pro,n,s);   /*���ú���ɾ��ָ����ŵ���Ʒ��¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵ���Ʒ���*/
				      t=searchPro(pro,n,s,1,find) ; /*���ú�������ָ����ŵ���Ʒ��¼*/
				      if (t)                 /*����ñ�ŵļ�¼����*/
					 {
						  readPro(&s,1);   /*����һ����������Ʒ��¼��Ϣ*/
					      pro[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ñ�ŵļ�¼������*/ 
 printf("this product is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void priceManage(Product pro[],int n)          /*�ú��������Ʒ�۸������*/
{  
	int choice;
	do
	{
		menuPrice( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(pro,n);         /*��������Ʒ���ܼ۸�*/
					  break;
			case 2:   calcuRank(pro,n);         /*������Ʒ�ļ۸�������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void countManage(Student stu[],int n)               /*�ú��������Ʒ���ͳ�ƹ���*/
{
		int choice;
		double mark[2][2];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(count,pro,n);                 /*���ô˺�������϶༰������Ʒ*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("���϶���Ʒ��:\n",mark,0);  /*������϶���Ʒ*/
				      break;
				case 2:   printMarkCourse("��������Ʒ��:\n",mark,1);  /*�����������Ʒ*/
				      break;
				case 0:   break;
			}
		}while (choice);
}






void searchManage(Product pro[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
Product s;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a product\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*�������ѯ��Ʒ�ı��*/
					  break;
				case 2:   printf("Input a product\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯ��Ʒ������*/		  
				      break;   
				case 3:   printf("Input a brand will be searched:\n");
				      scanf("%d",&s.brand);          /*�������ѯ��Ʒ��Ʒ��*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchPro(pro,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printPro(&pro[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Product pro[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortPro(pro,n,1);         /*�������С�����˳�������¼*/ 
          	 printPro(pro,n);          /*�������С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(pro,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: priceManage(pro,n);     /* 3. ��Ʒ�۸����*/
					break;
			case 4: countManage(pro,n);     /* 4. ���ͳ��*/
					break;
			case 5: searchManage(stu,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}


int baseManage(Product pro[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{  
		int choice,t,find[NUM];
    Product  s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readPro(&s,1);       /*����һ�����������Ʒ��¼*/
					 n=insertPro(pro,n,s);   /*���ú���������Ʒ��¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ������Ʒ���*/
					 n=deletePro(pro,n,s);   /*���ú���ɾ��ָ����ŵ���Ʒ��¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵ���Ʒ���*/
				      t=searchPro(pro,n,s,1,find) ; /*���ú�������ָ����ŵ���Ʒ��¼*/
				      if (t)                 /*����ñ�ŵļ�¼����*/
					 {
						  readPro(&s,1);   /*����һ����������Ʒ��¼��Ϣ*/
					      pro[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ñ�ŵļ�¼������*/ 
 printf("this product is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}


int main( )
{
		Product pro[NUM];                /*����ʵ��һά����洢��Ʒ��¼*/
      int choice,n;
	 n=readFile(pro);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(pro);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(pro,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortPro(pro,n,1);                   /*�����ļ�ǰ�������С��������*/ 
	     saveFile(pro,n);                   /*����������ļ�*/
      return 0;
}

