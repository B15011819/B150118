#include<stdio.h>
void menu( )        
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ��Ʒ��Ϣ���� ********\n");
		printf("******** 3. ��Ʒ������ ********\n");
		printf("******** 4. ��Ʒ���ͳ�� ********\n");
     printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     
{
		printf("%%%%%%%% 1. ������Ʒ��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����Ʒ��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸���Ʒ��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )    
{
		printf("@@@@@@@@ 1. ������Ʒ��� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ���ݼ۸����� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )   
{		printf("&&&&&&&& 1. �������������Ʒ &&&&&&&&\n");
		printf("&&&&&&&& 2. �������������Ʒ &&&&&&&&\n");
		printf("&&&&&&&& 3. �����۶�������Ʒ &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    
{
		printf("######## 1. ����Ʒ��Ų�ѯ   ########\n");
		printf("######## 2. ����Ʒ���Ʋ�ѯ   ########\n");
		printf("######## 3. ���۸�������ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage()    	     

{  
		int choice;
     
do
	    {   
         menuBase( );                  
         printf("ѡ����Ҫʹ�õ�ѡ��: ");
		 scanf("%d",&choice);	          
		 switch(choice)
		     {
			   case 1:	break;
			   case 2:  printf("��������Ʒ���\n");
					    break;
			   case 3:  printf("��������Ʒ���\n");
					    break;
			   case 0: break;
		    }
		}
		while(choice);
return 0;                             
}
void scoreManage()          
{  
	int choice;
	do
	{
		menuScore( );                        
		printf("ѡ����Ҫʹ�õ�ѡ��:\n");
		scanf("%d",&choice);	                 
		switch(choice)
		{
			case 1:   break;
			case 2:   break;		
			case 0:   break;
		}
	}while(choice);
}
void countManage()               
{
		int choice;
		do
		{
			menuCount( );                        
			printf("ѡ����Ҫʹ�õ�ѡ��:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:  break;
				case 2:  break;
				case 3:  break;
				case 0:  break;
			}
		}while (choice);
}
void searchManage()               
{
    int choice;
do
{
			menuSearch( );                         
			printf("ѡ����Ҫʹ�õ�ѡ��:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("���������ѯ��Ʒ���:\n");
				          break;
				case 2:   printf("���������ѯ��Ʒ����:\n");
				      	  break;   
				case 3:   printf("���������ѯ��Ʒ�۸�����:\n");
				          break;
				case 0:   break;
			}
		 
	    }while (choice);
}
int main()    
{
	int choice;
	menu();
    printf("��ѡ����Ҫʹ�õ�ѡ��: ");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:  break;
			case 2:  baseManage();    
			   	     break;
			case 3:  scoreManage();     
					 break;
			case 4: countManage();     
					break;
			case 5: searchManage();     
				     break;
          case 0: break;
		}
		return 0;
}