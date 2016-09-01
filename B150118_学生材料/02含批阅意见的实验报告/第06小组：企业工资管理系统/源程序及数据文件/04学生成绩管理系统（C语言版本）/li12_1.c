/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"employee.h"

void printHead( )      /*��ӡԱ����Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%6s%6s%8s%6s%6s\n","����","����","�Ա�","��������","˰��","����","�ܹ���","����");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. Ա����Ч���� ********\n");
		printf("******** 4. ����ͳ�Ʒ��� ********\n");
        printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ����Ա����¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��Ա����¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸�Ա����¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )     /*3��Ա�����ʹ���˵�����*/
{
		printf("@@@@@@@@ 1. ����Ա������ @@@@@@@@\n");
		printf("@@@@@@@@ 2. ���ݹ������� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4������ͳ�Ʒ����˵�����*/
{
		printf("&&&&&&&& 1. ���ܹ���˰�� &&&&&&&&\n");
		printf("&&&&&&&& 2. ���ܻ������� &&&&&&&&\n");
		printf("&&&&&&&& 3. ���ܽ����� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. �����Ų�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 3. �����β�ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Employee emp[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*�����Ž��в���ɾ���޸ģ����Ų����ظ�*/
{  
		int choice,t,find[NUM];
     Employee s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readEmp(&s,1);       /*����һ���������Ա����¼*/
					 n=insertEmp(emp,n,s);   /*���ú�������Ա����¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ����Ա������*/
					 n=deleteStu(emp,n,s);   /*���ú���ɾ��ָ�����ŵ�Ա����¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵ�Ա������*/
				      t=searchEmp(emp,n,s,1,find) ; /*���ú�������ָ�����ŵ�Ա����¼*/
				      if (t)                 /*����ù��ŵļ�¼����*/
					 {
						  readEmp(&s,1);   /*����һ��������Ա����¼��Ϣ*/
					      emp[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ù��ŵļ�¼������*/ 
 printf("this employee is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void scoreManage(Employee emp[],int n)          /*�ú������Ա�����ʹ�����*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(emp,n);         /*������Ա���Ĺ���*/
					  break;
			case 2:   calcuRank(emp,n);         /*��������Ա���Ĺ���������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[3][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ�ܹ���˰�ѡ��ܻ������ʡ��ܽ�����*/
int i;
    printf(s);                                  /*�����s�������������ʵ���ʾ��Ϣ*/
    for (i=0;i<3;i++)                           /*i������һ�ſ�*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Employee emp[],int n)               /*�ú�����ɹ���ͳ�Ʒ�������*/
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,emp,n);                 /*���ô˺������ܹ���˰�ѡ��ܻ������ʡ��ܽ�����*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("Ա���ܹ���˰����:\n",mark,0);  /*�����˰��*/
				      break;
				case 2:   printMarkCourse("Ա���ܻ���������:\n",mark,1);  /*����ܻ�������*/
				      break;
				case 3:   printMarkCourse("Ա���ܽ�������:\n",mark,2);  /*����ܽ���*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Employee emp[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
Employee s;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a employee\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*�������ѯԱ���Ĺ���*/
					  break;
				case 2:   printf("Input a employee\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯԱ��������*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.rank);          /*�������ѯԱ��������*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchEmp(emp,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printEmp(&emp[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Employee emp[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortEmp(emp,n,1);         /*��������С�����˳�������¼*/ 
          	 printStu(emp,n);          /*��������С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(emp,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(emp,n);     /* 3. Ա�����ʹ���*/
					break;
			case 4: countManage(emp,n);     /* 4. ����ͳ�Ʒ���*/
					break;
			case 5: searchManage(emp,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Employee emp[NUM];                /*����ʵ��һά����洢Ա����¼*/
      int choice,n;
	 n=readFile(emp);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(emp);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(emp,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortEmp(emp,n,1);                   /*�����ļ�ǰ��������С��������*/ 
	     saveFile(emp,n);                   /*����������ļ�*/
      return 0;
}
/*��student.c�ļ�����������*/
#include "employee.h"
#include <stdio.h>

int readEmp(Emlpoyee  *emp, int n)          /*����ѧ����¼ֵ��ѧ��Ϊ0������涨������¼ʱֹͣ*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one employee\'s information\n");
		printf("num:  ");
	     scanf("%ld", &emp[i].num);
		if (emp[i].num==0) break;
		printf("name: ");
		scanf("%s",emp[i].name);	
		printf("sex:  ");
		scanf("%s",emp[i].sex);
    	     emp[i].total=0;                /*�ܷ���Ҫ������ã���ֵ��Ϊ0*/
		printf("Input three courses of the employee:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%d",&emp[i].score[j]);	
		}
		emp[i].rank=0;                 /*������Ҫ�����ܷ������㣬��ֵ��Ϊ0*/
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printEmp ( Employee  *emp , int n)       /*�������ѧ����¼��ֵ*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", emp[i].num);
		printf("%8s", emp[i].name);
		printf("%8s", emp[i].sex);
		for (j=0;j<3;j++)
		   printf("%6d",emp[i].score[j]);
	    printf("%7d",emp[i].total);
	    printf("%5d\n",emp[i].rank);
	}
}

int equal(Employee s1,Employee s2,int condition)  /*����ж�����Student��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return s1.num==s2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	     return s1.rank==s2.rank;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��ܷ�*/
		return s1.total==s2.total;
	else return 1;                       /*�����������1*/
} 

int larger(Employee s1,Employee s2,int condition)  /*����condition�����Ƚ�����Student��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return s1.num>s2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܷ�*/
		return s1.total>s2.total;	
	else return 1; /*�����������1*/
}

void reverse(Employee emp[],int n)             /*����Ԫ������*/
{
	int i;
	Employee temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=emp[i];
		emp[i]=emp[n-1-i];
		emp[n-1-i]=temp;
	}
}

void calcuTotal(Employee emp[],int n)         /*��������ѧ�����ܷ�*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*���ѭ����������ѧ����¼*/
	{
		emp[i].total =0;
		for (j=0;j<3;j++)               /*�ڲ�ѭ���������Ź���*/
			emp[i].total +=emp[i].score[j];
	}	
}

void calcuRank(Employee emp[],int n)          /*�����ּܷ�������ѧ�����������ɼ���ͬ��������ͬ*/
{
	int i ;                       
	sortEmp(emp,n,2);                     /*�ȵ���sortStu�㷨�����ܷ���С��������*/
	reverse(emp,n);                      /*�����ã����ܷ��ɴ�С������*/
	emp[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(emp[i],emp[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܷ����*/
			emp[i].rank=emp[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			emp[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}

void calcuMark(double m[3][3],Employee emp[],int n) /*�����ſε���ߡ���͡�ƽ����*/
/*������ʽ������ά����m�ĵ�һά�������ſΣ��ڶ�ά������ߡ���͡�ƽ����*/
{
	int i,j;
	for (i=0;i<3;i++)                 /*�����ſε���߷�*/		
	{ 
		m[i][0]=emp[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<emp[j].score[i])
				m[i][0]=emp[j].score[i];
	}
	for (i=0;i<3;i++)                  /*�����ſε���ͷ�*/
	{ 
		m[i][1]=emp[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>emp[j].score[i])
				m[i][1]=emp[j].score[i];
	}
	for (i=0;i<3;i++)                 /*�����ſε�ƽ����*/
	{ 
		m[i][2]=emp[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=emp[j].score[i];
		m[i][2]/=n;
	}
}

void sortEmp(Employee emp[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Employee t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(emp[minpos],emp[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=emp[i];
			emp[i]=emp[minpos];
			emp[minpos]=t;
		}
	}
}

int searchEmp(Employee emp[],int n,Employee s,int condition,int f[ ])  /*��stu��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(emp[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertEmp(Employee emp[],int n,Employee s)              /*��stu��������ѧ�ŵ�������һ��Ԫ��s*/
{
	int i;
	sortEmp(emp,n,1);                              /*�Ȱ�ѧ������*/
	for (i=0;i<n;i++)
	{
		if (equal(emp[i],s,1))                      /*ѧ����ͬ��������룬��֤ѧ�ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*��ѧ�Ŵ�С��������*/
	{
		if (!larger(emp[i],s,1))                    /*���s���ڵ�ǰԪ��stu[i]�����˳�ѭ��*/
		break;
		emp[i+1]=emp[i];                         /*����Ԫ��stu[i]����һ��λ��*/
	}
	emp[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteEmp(Employee emp[],int n,Employee s)            /*��������ɾ��ָ��ѧ�ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(emp[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(stu[i],s,1)����*/ 
		emp[j]=emp[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}
