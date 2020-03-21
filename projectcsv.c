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
    int prod_budget[50];
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
    /*for(i=0;i<1000;i++)
    {
        printf("%s",csv[i]);
    }*/
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


void display_director(struct movieset *b)
{
    int n=100;
    //char dir[24];
    //printf("\n Enter the Directors Name:");
    //scanf("%s",dir);
    for(int i=0;i<n;i++)
    {
        printf("%s",b->prod_budget[i]);
        /*if(strcmp(dir,m[i].dir_name)==0)
        {
            printf("\nactor: %s\ndirector: %s\nbudget: %d\nboxoffice: %d\noutcome: %d\nrating: %.1f\nactor rating: %.1f\ndirector rating: %.1f",m[i].act_name,m[i].dir_name,m[i].prod_budget,m[i].Boxoffice,m[i].outcome,m[i].rating,m[i].act_rating,m[i].dir_rating);
            printf("\n\n");
        }*/
    }
}

/*void top_rated()
{
    for(int i=0;i<n;i++)
    {
        if(m[i].rating > 8.0)
        {
            printf("\nactor: %s\ndirector: %s\nbudget: %d\nboxoffice: %d\noutcome: %d\nrating: %.1f\nactor rating: %.1f\ndirector rating: %.1f",m[i].act_name,m[i].dir_name,m[i].prod_budget,m[i].Boxoffice,m[i].outcome,m[i].rating,m[i].act_rating,m[i].dir_rating);
            printf("\n\n");
        }
    }
}


void descriptive()
{
    float avg,var,sd,sum=0,sum_square=0,count=0;
    char nam[24];
    int ch;
    printf("\n Please enter actor or director: 1. Actor 2. Director");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1: printf("\n Enter the actor name: ");scanf("%s",nam);
                for(int i=0;i<n;i++)
                {
                    if(strcmp(nam,m[i].act_name)==0)
                    {
                      sum= sum+m[i].act_rating;
                      sum_square= sum_square+ (m[i].act_rating * m[i].act_rating);
                      count++;
                    }
                }
                avg= sum/count;
                var = (sum_square/count)- (avg * avg);
                sd = sqrt(var);
                printf("\n The average actor rating is: %.1f \n The variance is : %.1f \n The Standard deviation is : %.1f",avg,var,sd);
                break;

        case 2: printf("\n Enter the director name: ");scanf("%s",nam);
                for(int i=0;i<n;i++)
                {
                    if(strcmp(nam,m[i].dir_name)==0)
                    {
                      sum= sum+m[i].dir_rating;
                      sum_square= sum_square+ (m[i].dir_rating * m[i].dir_rating);
                      count++;
                    }
                }
                avg= sum/count;
                var = (sum_square/count)- (avg * avg);
                sd = sqrt(var);
                printf("\n The average director rating is: %.1f \n The variance is : %.1f \n The Standard deviation is : %.1f",avg,var,sd);
                break;

        default: printf("\n Invalid choice");break;
    }

}


void predictive()
{
    float coefficient,sum_p=0,sum_o=0,sum_square_p=0,sum_square_o=0,sum_po=0,denominator,a0,a1,input_budget,output;
    int i;
    for(i=0;i<n;i++)
    {
        sum_p= sum_p + (float)m[i].prod_budget; sum_o = sum_o + (float) m[i].outcome;
        sum_po= sum_po + (m[i].prod_budget * m[i].outcome);
        sum_square_p += m[i].prod_budget * m[i].prod_budget;
        sum_square_o += m[i].outcome * m[i].outcome;

    }
    coefficient = ((n*sum_po)-(sum_o*sum_p))/ sqrt(((n*sum_square_p)-(sum_p*sum_p)) * ((n*sum_square_o)-(sum_o*sum_o)) ) ;
    printf("\n The correlation coefficient is : %f", coefficient);

    denominator = (n * sum_square_p) - (sum_p * sum_p);
    a0 = ((sum_o * sum_square_p) - (sum_p * sum_po) )/ denominator;
    a1 = ((n * sum_po) - (sum_p * sum_o)) / denominator;
    printf("\n The regression equation is : \n y = %fx + %f",a1, a0);
    printf("\n Enter the budget: "); scanf("%f",&input_budget);
    output = (a1*input_budget) + a0;
    printf("\n The predicted outcome is : %f",output);




}*/
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
