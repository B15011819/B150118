#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"book.h"

void printHead( )      /*��ӡͼ����Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%6s%6s%8s%6s\n","����","����","���","����ͼ���Ƽ�","����ͼ���Ƽ�","����ͼ���Ƽ�","������");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ͼ����Ϣ���� ********\n");
		printf("******** 4. ������ͳ�� ********\n");
        printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ����ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸�ͼ���¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuAmount( )     /*3��ͼ����Ϣ����˵�����*/
{
		printf("@@@@@@@@ 1. ������������ @@@@@@@@\n");
		printf("@@@@@@@@ 2. ������������ @@@@@@@@\n");
        printf("@@@@@@@@ 3. ������������ @@@@@@@@\n");
		printf("@@@@@@@@ 4. ������������ @@@@@@@@\n");
		printf("@@@@@@@@ 5. ������������ @@@@@@@@\n");
		printf("@@@@@@@@ 6. ������������ @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuQuantity( )    /*4��ͼ��������ͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ��ÿ�ա��¡������������ &&&&&&&&\n");
		printf("&&&&&&&& 2. ��ÿ�ա��¡������������ &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ����Ų�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 3. �����߲�ѯ   ########\n");
		printf("######## 4. ������ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}
int baseManage(Book boo[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{  
		int choice,t,find[NUM];
     Book s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readBook(&s,1);       /*����һ���������ͼ���¼*/
					 n=insertBook(boo,n,s);   /*���ú�������ͼ���¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ����ͼ����*/
					 n=deleteBook(boo,n,s);   /*���ú���ɾ��ָ����ŵ�ͼ���¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵ�ͼ����*/
				      t=searchBook(boo,n,s,1,find) ; /*���ú�������ָ����ŵ�ͼ���¼*/
				      if (t)                 /*�����ͼ��ļ�¼����*/
					 {
						  readBook(&s,1);   /*����һ��������ͼ���¼��Ϣ*/
					      book[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ñ�ŵļ�¼������*/ 
 printf("this book is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void scoreManage(Book boo[],int n)          /*�ú������ͼ�������*/
{  
	int choice;
	do
	{
		menuAmount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(boo,n);         /*��ͼ����������*/
					  break;
			case 2:   calcuTotal(boo,n);         /*��ͼ����������*/
					  break;
			case 3:   calcuTotal(boo,n);         /*��ͼ����������*/
					  break;
			case 4:   calcuRank(boo,n);         /*������������*/
				      break;	
			case 5:   calcuRank(boo,n);         /*������������*/
				      break;	
			case 6:   calcuRank(boo,n);         /*������������*/
				      break;	
			case 0:   break;
		}
	}while(choice);
}

void quantityManage(Book boo[],int n)               /*�ú������������ͳ�ƹ���*/
{
		int choice;
		do
		{
			menuQuantity( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			readValue(value,boo,n);                 /*���ô˺�����ÿ�ա��¡�����ߺ����������*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printValueQuantity("���������Ϊ:\n",value,0);  /*������������*/
				      break;
				case 2:   printValueQuantity("���������Ϊ:\n",value,1);  /*������������*/
				      break;
				case 0:   break;
			}
		}while (choice);
}


void searchManage(book boo[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
book s;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a book\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*�������ѯ�鱾�ı��*/
					  break;
				case 2:   printf("Input a book\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯ�鱾������*/		  
				      break;   
				case 3:   printf("Input a writer will be searched:\n");
				      scanf("%d",&s.writer);            /*�������ѯ�鱾������*/
			          break;
				case 3:   printf("Input a category will be searched:\n");
				      scanf("%d",&s.category);          /*�������ѯ�鱾�����*/
					  break;
				case 0:   break;
			}	
                 if (choice>=1&&choice<=4)
			{ 
				findnum=searchBoo(boo,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printBoo(&boo[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}
int runMain(Book boo[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortBook(boo,n,1);         /*�������С�����˳�������¼*/ 
          	     printBook(boo,n);          /*�������С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(boo,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: amountManage(boo,n);     /* 3. ͼ����Ϣ����*/
					break;
			case 4: quantityManage(boo,n);     /* 4. ������ͳ��*/
					break;
			case 5: searchManage(boo,n);     /* 5. ����������ѯ*/
				     break;
            case 0: break;
		}
		return n;
}
int main( )
{
		Book boo[NUM];                /*����ʵ��һά����洢ͼ���¼*/
      int choice,n;
	 n=readFile(boo);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(boo);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(boo,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortBoo(boo,n,1);                   /*�����ļ�ǰ�������С��������*/ 
	     saveFile(boo,n);                   /*����������ļ�*/
      return 0;
}
