//����BCC����ģ�ͣ���ͳ�������ԭ�ӷֲ���� 
#include<stdio.h>
#include<math.h>
#define M n*n*n
#define P 2*M-1
int n,q,i,j;
int m,p,k;
void f1()
{
	printf("---------------------------------\n");
    printf("0--��������ģ��\n");
	printf("1--����ԭ�Ӽ����ͳ��\n");
    printf("---------------------------------\n");
    printf("����ѡ��ǰ�����ֽ��в˵�ѡ��\n") ;
} 

void f2()
{
	printf("�Ƿ����ɾ����ԭ�����ꣿ\n"); 
    printf("-----------------------------\n");
    printf("0--��\n");
	printf("1--��\n");
    printf("-----------------------------\n");
    printf("����ѡ��ǰ�����ֽ��в˵�ѡ��\n") ;
}

void f3()
{
	printf("���������ĳһ��ԭ�ӵ����������ǣ�\n");
    printf("---------------------------------\n");
    printf("0--����\n");
	printf("1--����\n");
    printf("---------------------------------\n");
    printf("����ѡ��ǰ�����ֽ��в˵�ѡ��\n") ;
}

void f4()
{
	printf("���ѡ��\n");
    printf("---------------------------------\n");
    printf("1--������ھ���\n");
	printf("2--������ھ��뼰�ý���ԭ����Ŀ\n");
    printf("---------------------------------\n");
    printf("����ѡ��ǰ�����ֽ��в˵�ѡ��\n") ;
}

int main()
{
	printf("��ã�׼���ù������BCC����ģ������\n");
menu: 
//�˵�ѡ�� 
    f1();
    scanf("%d",&q);
	if(q==0)
	printf("������һ��ʼ�ɣ�\n");
	if(q==1) 
	{printf("�㻹û�������ģ��!������ѡ��˵���\n"); goto menu; }	
//��������ģ�� 
	printf("��ȷ�����빹����ģ�ʹ�С��N x N x N��,\n");
	printf("������Nֵ��\n");
	scanf("%d",&n);
    f2();
    scanf("%d",&q);
	int a[M][3];
    float b[M][3];	
//���ɸ����� 
    if(q==1)printf("ģ�͸���������Ϊ��\n"); 
    for(m=0;m<n;m++)
		for(p=0;p<n;p++)
		     for(k=0;k<n;k++)
				{
				if(q==1)printf("(%d,%d,%d)\n",m,p,k);
				a[i][0]=m;
				a[i][1]=p;
				a[i][2]=k;
				i++;
				}
   printf("ģ�͸���������Ϊ��\n"); 
    for(m=1;m<=2*n-1;m+=2)
		for(p=1;p<=2*n-1;p+=2)
		     for(k=1;k<=2*n-1;k+=2)
				{
				if(q==1)printf("(%d/2,%d/2,%d/2)\n",m,p,k);
				b[j][0]=(float)m/2;
				b[j][1]=(float)p/2;
				b[j][2]=(float)k/2;
				j++;
				if(n==1){break;} 
				}
	printf("��������Խ���ԭ�Ӽ����ͳ���ˣ�\n");	
//����ԭ�Ӽ����ͳ��
    f3();
    scanf("%d",&q);
         //��ѯ�Ƕ����������� 
if(q==0)
{
    int s1=0,o;
    int d[3];
    int sum=0;
    float c[P],s2=0,t;
    printf("��������Ҫ��ѯ��ԭ�����꣡\n");
    for(i=0;i<3;i++)
    scanf("%d",&d[i]);
//����ԭ������������ԭ�ӵľ��벢���� 
    for(i=0;i<M;i++)
  {
  	if(n==1)break; 
  	if(a[i][0]==d[0]&&a[i][1]==d[1]&&a[i][2]==d[2])continue;
	for(j=0;j<3;j++)
        {
		 s1+=(a[i][j]-d[j])*(a[i][j]-d[j]);
		}
     c[sum++]=sqrt(s1);
     s1=0;
  }
    for(i=0;i<M;i++)
  {
	 for(j=0;j<3;j++)
        {
		s2+=(b[i][j]-d[j])*(b[i][j]-d[j]);
		}
     c[sum++]=sqrt(s2);
     s2=0; 
  }   
    for(i=0;i<P;i++)
  {
  	 o=i;
  	 for(j=i+1;j<P;j++)
  	  {
  	  	if(c[o]>c[j])
  	  	 {
  	  	 	o=j;
		 }
	  }
	 t=c[i];
	 c[i]=c[o];
	 c[o]=t;
  }
	choose1: 
    f4();
    scanf("%d",&q);
//���������ھ��� 
 if(q==1) 
 {
   printf("�ɽ���Զԭ��5�����ھ���Ϊ��������ͬ�Ĳ��ظ�ͳ�ƣ���\n");
   	sum=0;
   	for(i=0;i<P;i++)
   	{
	if(c[i]==c[i-1]&&i!=0)continue;
   	printf("%.3f\n",c[i]);
   	sum++;
   	if(sum==5)break;
    }
 }
//������н��ھ��뼰�ý���ԭ����Ŀ 
 if(q==2)
 {
    int num=0,h=0;
   	for(i=0;i<P;i++)
   	{
	if(c[i]==c[i-1]&&i!=0)continue;
   	printf(" %.3f ",c[i]);h++;
   	if(h%5==0)printf("\n");//ÿ���5���س� 
    }
    float g[h];
    for(i=0;i<P;i++)
   	{
   	 if(c[i]==c[i-1]&&i!=0)continue;
   	 g[num++]=c[i];
    }
    num=0;
    printf("\n���ǵĸ����ֱ��ǣ�\n"); 
    for(i=0;i<h;i++)
   	{
   	  for(j=0;j<P;j++)
   	    {
   	    	if(g[i]==c[j])num++;
		}
   	 printf("%3d��",num);
   	 if((i+1)%5==0)printf("\n");//ÿ���5���س� 
   	 num=0;
    }
 }
   printf("\n�Ƿ���������yes(0),no(1)\n");
   scanf("%d",&q);
   if(q==0)goto choose1;
   if(q==1)q++;
}
         //��ѯ�������������� 
if(q==1)
{
    int o;
    float e[3];
    int sum=0;
    float c[P],s1=0,s2=0,t;
    printf("��������Ҫ��ѯ��ԭ�����꣡\n");
    for(i=0;i<3;i++)
    scanf("%f",&e[i]);
//����ԭ������������ԭ�ӵľ��벢����
    for(i=0;i<M;i++)
  {
	for(j=0;j<3;j++)
        {
		 s1+=(a[i][j]-e[j])*(a[i][j]-e[j]);
		}
     c[sum++]=sqrt(s1);
     s1=0;
  }
    for(i=0;i<M;i++)
    {
    if(n==1)break; 
  	if(b[i][0]==e[0]&&b[i][1]==e[1]&&b[i][2]==e[2])continue;
	 for(j=0;j<3;j++)
        {
		s2+=(b[i][j]-e[j])*(b[i][j]-e[j]);
		}
     c[sum++]=sqrt(s2);
     s2=0; 
    }   
    for(i=0;i<P;i++)
  {
  	 o=i;
  	 for(j=i+1;j<P;j++)
  	  {
  	  	if(c[o]>c[j])
  	  	 {
  	  	 	o=j;
		 }
	  }
	 t=c[i];
	 c[i]=c[o];
	 c[o]=t;
  }
	choose2: 
    f4();
    scanf("%d",&q);
//���������ھ���
 if(q==1) 
 {
   printf("�ɽ���Զԭ��5�����ھ���Ϊ��������ͬ�Ĳ��ظ�ͳ�ƣ���\n");
   	sum=0;
   	for(i=0;i<P;i++)
   	{
	if(c[i]==c[i-1]&&i!=0)continue;
   	printf("%.3f\n",c[i]);
   	sum++;
   	if(sum==5)break;
    }
 }
//������н��ھ��뼰�ý���ԭ����Ŀ 
 if(q==2)
 {
    int num=0,h=0;
   	for(i=0;i<P;i++)
   	{
	if(c[i]==c[i-1]&&i!=0)continue;
   	printf(" %.3f ",c[i]);h++;
   	if(h%5==0)printf("\n");//ÿ���5���س� 
    }
    float g[h];
    for(i=0;i<P;i++)
   	{
   	 if(c[i]==c[i-1]&&i!=0)continue;
   	 g[num++]=c[i];
    }
    num=0;
    printf("\n���ǵĸ����ֱ��ǣ�\n"); 
    for(i=0;i<h;i++)
   	{
   	  for(j=0;j<P;j++)
   	    {
   	    	if(g[i]==c[j])num++;
		}
   	 printf("%3d��",num);
   	 if((i+1)%5==0)printf("\n");//ÿ���5���س� 
   	 num=0;
    }  
 }
   printf("\n�Ƿ���������yes(0),no(1)\n");
   scanf("%d",&q);
   if(q==0) goto choose2;
   if(q==1)q--;
}
//�������� 
	printf("�ڴ���һ��ģ�͹���!"); 
    return 0;
} 

