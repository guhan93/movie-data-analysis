#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct movie
{
    char a[1034][2000];
};
struct movieset
{
    char act_name[1000];
    char dir_name[50];
    char name[50];
    int prod_budget[1000];
    int Boxoffice[50];
    int outcome[50];
    float rating[50];
    float act_rating[50];
    float dir_rating[50];
};
void movie_1(struct movie *m)
{
    int i;
    FILE*fp=fopen("movie.csv","r");
    do
    {
        char csv[2000];
        fgets(csv,2000,(FILE*)fp);
        getdata(csv,m);
    }while((getc(fp))!=EOF);
    fclose(fp);
}
void getdata(char csv[],struct movie*m)
{
    static int i=0;
    char *token=strtok(csv,",");
    while(token!=NULL)
    {
        strcpy(m->a[i],token);
        token=strtok(NULL,",");
        i++;
    }
}
void sep(struct movieset *b,struct movie *a)
{
    int i,k,l=0;
    for(i=3,k=0;i<895,k<100;i+9,k++)
    {
        b->prod_budget[k]=atoi(a->a[i]);
    }
}


void display_director(struct movieset *g)
{
    int n=100;
    for(int i=0;i<n;i++)
    {
        printf("\n%d",g->prod_budget[i]);
    }
}
void main()
{
    struct movieset f;
    struct movie fm;
    int choice;
    while(1)
    {
        printf("\nMENU:\n Enter your choice:\n 1. Display movies by director\n 2. Top rated movies\n 3. Descriptive analysis on ratings\n 4. Predictive analysis on collection\n 5. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: display_director(&f);break;
            //case 2: top_rated();break;
            //case 3: descriptive();break;
            //case 4: predictive();break;
            //case 5: return;break;
            //default: printf("\n Invalid choice");break;

        }

    }
}

