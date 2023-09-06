//构建BCC晶体模型，并统计其近邻原子分布情况 
#include<stdio.h>
#include<math.h>
#define M n*n*n
#define P 2*M-1
int n,q,i,j;
int m,p,k;
void f1()
{
	printf("---------------------------------\n");
    printf("0--构建晶体模型\n");
	printf("1--晶体原子间近邻统计\n");
    printf("---------------------------------\n");
    printf("输入选项前的数字进行菜单选择：\n") ;
} 

void f2()
{
	printf("是否生成晶体各原子坐标？\n"); 
    printf("-----------------------------\n");
    printf("0--否\n");
	printf("1--是\n");
    printf("-----------------------------\n");
    printf("输入选项前的数字进行菜单选择：\n") ;
}

void f3()
{
	printf("你想输入的某一个原子的坐标类型是：\n");
    printf("---------------------------------\n");
    printf("0--顶点\n");
	printf("1--体心\n");
    printf("---------------------------------\n");
    printf("输入选项前的数字进行菜单选择：\n") ;
}

void f4()
{
	printf("输出选择：\n");
    printf("---------------------------------\n");
    printf("1--输出近邻距离\n");
	printf("2--输出近邻距离及该近邻原子数目\n");
    printf("---------------------------------\n");
    printf("输入选项前的数字进行菜单选择：\n") ;
}

int main()
{
	printf("你好！准备好构建你的BCC晶体模型了吗？\n");
menu: 
//菜单选择 
    f1();
    scanf("%d",&q);
	if(q==0)
	printf("那我们一起开始吧！\n");
	if(q==1) 
	{printf("你还没构建你的模型!请重新选择菜单！\n"); goto menu; }	
//构建晶体模型 
	printf("请确定你想构建的模型大小（N x N x N）,\n");
	printf("请输入N值：\n");
	scanf("%d",&n);
    f2();
    scanf("%d",&q);
	int a[M][3];
    float b[M][3];	
//生成各坐标 
    if(q==1)printf("模型各顶点坐标为：\n"); 
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
   printf("模型各体心坐标为：\n"); 
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
	printf("现在你可以进行原子间近邻统计了！\n");	
//晶体原子间近邻统计
    f3();
    scanf("%d",&q);
         //查询是顶点坐标的情况 
if(q==0)
{
    int s1=0,o;
    int d[3];
    int sum=0;
    float c[P],s2=0,t;
    printf("请输入需要查询的原子坐标！\n");
    for(i=0;i<3;i++)
    scanf("%d",&d[i]);
//求解该原子与所有其它原子的距离并保存 
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
//输出五个近邻距离 
 if(q==1) 
 {
   printf("由近到远原子5个近邻距离为（距离相同的不重复统计）：\n");
   	sum=0;
   	for(i=0;i<P;i++)
   	{
	if(c[i]==c[i-1]&&i!=0)continue;
   	printf("%.3f\n",c[i]);
   	sum++;
   	if(sum==5)break;
    }
 }
//输出所有近邻距离及该近邻原子数目 
 if(q==2)
 {
    int num=0,h=0;
   	for(i=0;i<P;i++)
   	{
	if(c[i]==c[i-1]&&i!=0)continue;
   	printf(" %.3f ",c[i]);h++;
   	if(h%5==0)printf("\n");//每输出5个回车 
    }
    float g[h];
    for(i=0;i<P;i++)
   	{
   	 if(c[i]==c[i-1]&&i!=0)continue;
   	 g[num++]=c[i];
    }
    num=0;
    printf("\n它们的个数分别是：\n"); 
    for(i=0;i<h;i++)
   	{
   	  for(j=0;j<P;j++)
   	    {
   	    	if(g[i]==c[j])num++;
		}
   	 printf("%3d个",num);
   	 if((i+1)%5==0)printf("\n");//每输出5个回车 
   	 num=0;
    }
 }
   printf("\n是否继续输出？yes(0),no(1)\n");
   scanf("%d",&q);
   if(q==0)goto choose1;
   if(q==1)q++;
}
         //查询是体心坐标的情况 
if(q==1)
{
    int o;
    float e[3];
    int sum=0;
    float c[P],s1=0,s2=0,t;
    printf("请输入需要查询的原子坐标！\n");
    for(i=0;i<3;i++)
    scanf("%f",&e[i]);
//求解该原子与所有其它原子的距离并保存
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
//输出五个近邻距离
 if(q==1) 
 {
   printf("由近到远原子5个近邻距离为（距离相同的不重复统计）：\n");
   	sum=0;
   	for(i=0;i<P;i++)
   	{
	if(c[i]==c[i-1]&&i!=0)continue;
   	printf("%.3f\n",c[i]);
   	sum++;
   	if(sum==5)break;
    }
 }
//输出所有近邻距离及该近邻原子数目 
 if(q==2)
 {
    int num=0,h=0;
   	for(i=0;i<P;i++)
   	{
	if(c[i]==c[i-1]&&i!=0)continue;
   	printf(" %.3f ",c[i]);h++;
   	if(h%5==0)printf("\n");//每输出5个回车 
    }
    float g[h];
    for(i=0;i<P;i++)
   	{
   	 if(c[i]==c[i-1]&&i!=0)continue;
   	 g[num++]=c[i];
    }
    num=0;
    printf("\n它们的个数分别是：\n"); 
    for(i=0;i<h;i++)
   	{
   	  for(j=0;j<P;j++)
   	    {
   	    	if(g[i]==c[j])num++;
		}
   	 printf("%3d个",num);
   	 if((i+1)%5==0)printf("\n");//每输出5个回车 
   	 num=0;
    }  
 }
   printf("\n是否继续输出？yes(0),no(1)\n");
   scanf("%d",&q);
   if(q==0) goto choose2;
   if(q==1)q--;
}
//结束程序 
	printf("期待下一次模型构建!"); 
    return 0;
} 

