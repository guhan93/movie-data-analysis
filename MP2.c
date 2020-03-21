#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct data
{
	char a[1034][2000];
};
struct gset
{
	float bud[100],out[100];
};
void year_1(struct data *dat)
{
  FILE *fp=fopen("movie_stat (2).csv","r");
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
    for(i=12,k=0;i<895,k<100;i=i+9,k++)
    {
        b->bud[k]=atof(a->a[i]);
    }
    /*for(i=4,k=0;i<35,k<12;i=i+3,k++)
    {
        b->income[k]=atof(a->a[i]);
    }
    for(i=5,k=0;i<36,k<12;i=i+3,k++)
    {
        b->profit[k]=atof(a->a[i]);
    }*/
}
float show_data(struct gset *s)
{
	int i;

	//printf("\t\t\t\t\t\t\t\tMonth\tYear\t  Income\t Profit ");
    for(i=0;i<100;i++)
	{
	    printf("%.2f",s->bud[i]);
		//printf("\n\t\t\t\t\t\t\t\tMarch\t %.0f\t %.2f\t%.2f",s->year[i],s->income[i],s->profit[i]);
	}
	//printf("\n\t\t\t\t\t\t\t\tIncome and profit values are in Rs Crores");
	return 0;
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
			//case 2:central_tendency(&tata);break;
			//case 3:corr_reg(&tata);break;
			//case 4:prediction(&tata);break;
			case 5:printf("\n\t\t\t\t\t\t\t\t\t\t Thank You!!");
			exit(0);break;
		}
	}
	printf("\n");
}

