#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 9
float central_tendency();
struct data
{
	char a[1034][2000];
};
struct gset
{
	float year[12],profit[12],income[12];
};
void year_1(struct data *dat)
{
  FILE *fp=fopen("Data.csv","r");
  do
  {
    char csv[2000];
    fgets(csv,2000,(FILE*)fp);
    getdata(csv,dat);
  }while((getc(fp))!=EOF);
  fclose(fp);
}
void getdata(char csv[],struct data *dat)
{
  static int i=0;
  char *token=strtok(csv,",");
  while(token!=NULL)
    {
      strcpy(dat->a[i],token);
      token=strtok(NULL,",");
      i++;
    }
}
void sep(struct gset *b,struct data *a)
{
    int i,k=0,l=0;
    for(i=3,k=0;i<34,k<12;i=i+3,k++)
    {
        b->year[k]=atof(a->a[i]);
    }
    for(i=4,k=0;i<35,k<12;i=i+3,k++)
    {
        b->income[k]=atof(a->a[i]);
    }
    for(i=5,k=0;i<36,k<12;i=i+3,k++)
    {
        b->profit[k]=atof(a->a[i]);
    }
}
float show_data(struct gset *s)
{
	int i;

	printf("\t\t\t\t\t\t\t\tMonth\tYear\t  Income\t Profit ");
    for(i=0;i<11;i++)
	{
		printf("\n\t\t\t\t\t\t\t\tMarch\t %.0f\t %.2f\t%.2f",s->year[i],s->income[i],s->profit[i]);
	}
	printf("\n\t\t\t\t\t\t\t\tIncome and profit values are in Rs Crores");
	return 0;
}
float central_tendency(struct gset *g)
{
	printf("\n\t\t\t\t\t\t\t\tCalculating central tendency values on Profit data\n");
	int i,j,n=11,k=0,c=1,max=0,mode;
    float x=0.0,y=0.0,t,b[12]={0.0},sum=0.0;
    //MEAN CALCULATION
    for(i=0;i<n;i++)
    {
        sum+=g->profit[i];
    }
    x=(float)sum/(float)n;
    printf("\t\t\t\t\t\t\t\tMean\t=Rs %f Crores",x);
    //MEDIAN CALCULATION
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(g->profit[i]>g->profit[j])
            {
                t=g->profit[i];
                g->profit[i]=g->profit[j];
                g->profit[j]=t;
            }
        }
    }
    if(n%2==0)
    y=(float)(g->profit[n/2]+g->profit[(n-1)/2])/2;
    else
    y=g->profit[(n-1)/2];
    printf("\n\t\t\t\t\t\t\t\tMedian\t=Rs %f Crores",y);
    //MODE CALCULATION
    for(i=0;i<n-1;i++)
    {
        mode=0;
        for(j=i+1;j<n;j++)
        {
            if(g->profit[i]==g->profit[j])
            {
                mode++;
            }
        }
        if((mode>max)&&(mode!=0))
        {
            k=0;
            max=mode;
            b[k]=g->profit[i];
            k++;
        }
        else if(mode==max)
        {
            b[k]=g->profit[i];
            k++;
        }
    }
    for(i=0;i<n;i++)
    {
        if(g->profit[i]==b[i])
        c++;
    }
    if(c==n)
    printf("\n\t\t\t\t\t\t\t\tThere is no mode");
    else
    {
        printf("\nMode\t= ");
        for(i=0;i<k;i++)
        printf("%d ",b[i]);
    }
}
float corr_reg(struct gset *r)
{
    int i,ch;
    float xsum=0.0,ysum=0.0,xmean=0.0,ymean=0.0,diff[12]={0.0},diff_1[12]={0.0},diff_2[12]={0.0},diff_3[12]={0.0},diff_4[12]={0.0},num=0.0,denom=0.0,b,a,denom_1=0.0,denom_2=0.0,corr=0.0;
    printf("\n 1.Correlation and Regression between year and profit");
    printf("\n 2.Correlation and Regression between income and profit");
    printf("\nEnter your choice :");
    scanf("%d",&ch);
    /*for(i=0;i<11;i++)
    {
        printf("\n%.2f",r->profit[i]);
    }*/
    if(ch==1)
    {
        for(i=0;i<11;i++)
            {
                xsum+=r->year[i];
                ysum+=r->profit[i];
            }
	    xmean=xsum/11.0;
	    ymean=ysum/11.0;
	    for(i=0;i<11;i++)
            {
                diff[i]=r->year[i]-xmean;
                diff_1[i]=r->profit[i]-ymean;
            }
        for(i=0;i<11;i++)
            {
                num+=(diff[i]*diff_1[i]);
                denom+=(diff[i]*diff[i]);
                denom_1+=(diff_1[i]*diff_1[i]);
            }
        b=num/denom;
        printf("%f",b);
	    a=ymean-(b*xmean);
	    denom_2=sqrt(denom*denom_1);
	    corr=num/denom_2;
	    for(i=0;i<11;i++)
            {
                diff_2[i]=diff[i]*diff[i];
		        diff_3[i]=diff[i]*diff_1[i];
            }
        for(i=0;i<11;i++)
	        {
	            diff_4[i]=diff[i]*diff_1[i];
            }
    /*for(i=0;i<11;i++)
	{
		printf("\n\t\t\t\t %.0f\t %.2f\t%.2f \t%.2f \t%.2f \t%f \t%.2f",r->year[i],r->profit[i],diff[i],diff_1[i],diff_2[i],diff_3[i],diff_4[i]);
	}*/
	    //printf("\n\t\t\t\t\t The required equation is:Y=%.2f+%.2fX",a,b);
	    //printf("\n\t\t\t\t\t Correlation :%.2f",corr);
    }
    else if(ch==2)
    {
        for(i=0;i<11;i++)
            {
                xsum+=r->income[i];
                ysum+=r->profit[i];
            }
	    xmean=xsum/11.0;
	    ymean=ysum/11.0;
	    for(i=0;i<11;i++)
            {
                diff[i]=r->income[i]-xmean;
                diff_1[i]=r->profit[i]-ymean;
            }
        for(i=0;i<11;i++)
            {
                num+=(diff[i]*diff_1[i]);
                denom+=(diff[i]*diff[i]);
                denom_1+=(diff_1[i]*diff_1[i]);
            }
        b=num/denom;
	    a=ymean-(b*xmean);
	    denom_2=sqrt(denom*denom_1);
	    corr=num/denom_2;
	    for(i=0;i<11;i++)
            {
                diff_2[i]=diff[i]*diff[i];
		        diff_3[i]=diff[i]*diff_1[i];
            }
        for(i=0;i<11;i++)
	        {
	            diff_4[i]=diff[i]*diff_1[i];
            }
    /*for(i=0;i<11;i++)
	{
		printf("\n\t\t\t\t %.0f\t %.2f\t%.2f \t%.2f \t%.2f \t%f \t%.2f",r->income[i],r->profit[i],diff[i],diff_1[i],diff_2[i],diff_3[i],diff_4[i]);
	}*/
        //printf("\n\t\t\t\t\t The required equation is:Y=%.2f+%.2fX",a,b);
	    //printf("\n\t\t\t\t\t Correlation :%.2f",corr);
    }
}
float prediction(struct gset *p)
{
    int i,ch;
    /*for(i=0;i<11;i++)
    {
        printf("\n%.2f",p->profit[i]);
    }*/
	float xsum=0.0,ysum=0.0,xmean=0.0,ymean=0.0,diff[10]={0.0},diff_1[10]={0.0},num=0.0,denom=0.0,b,a,x=0.0,y;
    printf("\n 1.Value prediction from year");
    printf("\n 2.Value prediction from income");
    printf("\n Enter your choice :");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("\n Enter a year:");
	    scanf("%f",&x);
	    for(i=0;i<11;i++)
            {
                xsum+=p->year[i];
		        ysum+=p->profit[i];
	        }
	    xmean=xsum/11.0;
	    ymean=ysum/11.0;
	    for(i=0;i<11;i++)
	        {
		        diff[i]=p->year[i]-xmean;
		        diff_1[i]=p->profit[i]-ymean;
	        }
	    for(i=0;i<11;i++)
	        {
		       num+=(diff[i]*diff_1[i]);
		       denom+=(diff[i]*diff[i]);
	        }
	    b=num/denom;
	    printf("%f",b);
	    a=ymean-(b*xmean);
	    y=a+(b*x);
	    printf("\n\t\t\t\t\t The Predicted Profit amount is %f",y);
    }
    else if(ch==2)
    {
        printf("\n Enter the amount of income in Rs Crores:");
	    scanf("%f",&x);
	    for(i=0;i<11;i++)
            {
                xsum+=p->income[i];
		        ysum+=p->profit[i];
	        }
	    xmean=xsum/11.0;
	    ymean=ysum/11.0;
	    for(i=0;i<11;i++)
	        {
		        diff[i]=p->income[i]-xmean;
		        diff_1[i]=p->profit[i]-ymean;
	        }
	    for(i=0;i<11;i++)
	        {
		       num+=(diff[i]*diff_1[i]);
		       denom+=(diff[i]*diff[i]);
	        }
	    b=num/denom;
	    a=ymean-(b*xmean);
	    y=a+(b*x);
	    printf("\n\t\t\t\t\t The Predicted Profit amount is %f",y);
    }
}
int main()
{
  struct gset tata;
  struct data a1;
  year_1(&a1);
  sep(&tata,&a1);

	int ch;
	while(1)
	{
		printf("\n1.Show data");
		printf("\n2.Measures of central tendency");
		printf("\n3.Correlation and Regression");
		printf("\n4.Value prediction");
		printf("\n5.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:show_data(&tata);break;
			case 2:central_tendency(&tata);break;
			case 3:corr_reg(&tata);break;
			case 4:prediction(&tata);break;
			case 5:printf("\n\t\t\t\t\t\t\t\t\t\t Thank You!!");
			exit(0);break;
		}
	}
	printf("\n");
}





