#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
FILE *fp;
struct movie{
    char *act_name;
    char *dir_name;
    char *name;
    int prod_budget;
    int Boxoffice;
    int outcome;
    float rating;
    float act_rating;
    float dir_rating;
}m[41];

int n = 41;
void insert_data()
{
    m[0].act_name="rajini";
    m[0].dir_name="ranjith";
    m[0].name="kaala";
    m[0].prod_budget=140;
    m[0].Boxoffice=159;
    m[0].outcome=50;
    m[0].rating=7.0;
    m[0].act_rating=7.9;
    m[0].dir_rating=7.3;

    m[1].act_name="rajini";
    m[1].dir_name="ranjith";
    m[1].name="kabali";
    m[1].prod_budget=120;
    m[1].Boxoffice=302;
    m[1].outcome=223.5;
    m[1].rating=6.4;
    m[1].act_rating=7.0;
    m[1].dir_rating=6.8;

    m[2].act_name="rajini";
    m[2].dir_name="ravikumar";
    m[2].name="linga";
    m[2].prod_budget=131;
    m[2].Boxoffice=89;
    m[2].outcome=0;
    m[2].rating=5.8;
    m[2].act_rating=6.2;
    m[2].dir_rating=6.0;

    m[3].act_name="rajini";
    m[3].dir_name="soundarya";
    m[3].name="kochadaiiyan";
    m[3].prod_budget=106;
    m[3].Boxoffice=81;
    m[3].outcome=32;
    m[3].rating=6.5;
    m[3].act_rating=6.9;
    m[3].dir_rating=5.7;

    m[4].act_name="rajini";
    m[4].dir_name="shankar";
    m[4].name="enthiran";
    m[4].prod_budget=132;
    m[4].Boxoffice=290;
    m[4].outcome=110;
    m[4].rating=8.1;
    m[4].act_rating=7.9;
    m[4].dir_rating=8.0;

    m[5].act_name="rajini";
    m[5].dir_name="shankar";
    m[5].name="sivaji";
    m[5].prod_budget=70;
    m[5].Boxoffice=136;
    m[5].outcome=52;
    m[5].rating=7.5;
    m[5].act_rating=7.8;
    m[5].dir_rating=8.0;

    m[6].act_name="rajini";
    m[6].dir_name="shankar";
    m[6].name="sivaji";
    m[6].prod_budget=70;
    m[6].Boxoffice=136;
    m[6].outcome=52;
    m[6].rating=7.5;
    m[6].act_rating=7.8;
    m[6].dir_rating=8.0;

    m[7].act_name="rajini";
    m[7].dir_name="vasu";
    m[7].name="chandramukhi";
    m[7].prod_budget=28;
    m[7].Boxoffice=90;
    m[7].outcome=38;
    m[7].rating=7.0;
    m[7].act_rating=7.3;
    m[7].dir_rating=7.0;

    m[8].act_name="rajini";
    m[8].dir_name="suresh";
    m[8].name="baba";
    m[8].prod_budget=41;
    m[8].Boxoffice=36;
    m[8].outcome=-6;
    m[8].rating=4.8;
    m[8].act_rating=5.5;
    m[8].dir_rating=4.5;

    m[9].act_name="rajini";
    m[9].dir_name="ravikumar";
    m[9].name="padayappa";
    m[9].prod_budget=14;
    m[9].Boxoffice=90;
    m[9].outcome=56;
    m[9].rating=8.1;
    m[9].act_rating=8.2;
    m[9].dir_rating=8.0;

    m[10].act_name="rajini";
    m[10].dir_name="ravikumar";
    m[10].name="muthu";
    m[10].prod_budget=8;
    m[10].Boxoffice=30;
    m[10].outcome=18;
    m[10].rating=7.5;
    m[10].act_rating=7.3;
    m[10].dir_rating=7.0;

    m[11].act_name="karthik";
    m[11].dir_name="pandiraj";
    m[11].name="kadaikutty_singam";
    m[11].prod_budget=36;
    m[11].Boxoffice=72;
    m[11].outcome=54;
    m[11].rating=7.1;
    m[11].act_rating=7.2;
    m[11].dir_rating=7.0;

    m[12].act_name="karthik";
    m[12].dir_name="pandiraj";
    m[12].name="kadaikutty_singam";
    m[12].prod_budget=36;
    m[12].Boxoffice=72;
    m[12].outcome=54;
    m[12].rating=7.1;
    m[12].act_rating=7.2;
    m[12].dir_rating=7.0;

    m[13].act_name="karthik";
    m[13].dir_name="vinoth";
    m[13].name="theeran_ahigaaram_ondru";
    m[13].prod_budget=45;
    m[13].Boxoffice=72;
    m[13].outcome=40;
    m[13].rating=8.4;
    m[13].act_rating=8.6;
    m[13].dir_rating=8.4;

    m[14].act_name="karthik";
    m[14].dir_name="mainratnam";
    m[14].name="kaatru_veliyidai";
    m[14].prod_budget=34;
    m[14].Boxoffice=32;
    m[14].outcome=2;
    m[14].rating=5.9;
    m[14].act_rating=6.5;
    m[14].dir_rating=6.0;

    m[15].act_name="karthik";
    m[15].dir_name="vamsi_paidipally";
    m[15].name="thozha";
    m[15].prod_budget=40;
    m[15].Boxoffice=110;
    m[15].outcome=70;
    m[15].rating=8.0;
    m[15].act_rating=8.3;
    m[15].dir_rating=7.5;

    m[16].act_name="karthik";
    m[16].dir_name="gokul";
    m[16].name="kaashmora";
    m[16].prod_budget=51;
    m[16].Boxoffice=61;
    m[16].outcome=11;
    m[16].rating=5.6;
    m[16].act_rating=5.8;
    m[16].dir_rating=6.0;

    m[17].act_name="karthik";
    m[17].dir_name="gokul";
    m[17].name="kaashmora";
    m[17].prod_budget=51;
    m[17].Boxoffice=61;
    m[17].outcome=11;
    m[17].rating=5.6;
    m[17].act_rating=5.8;
    m[17].dir_rating=6.0;

    m[18].act_name="karthik";
    m[18].dir_name="venkat_prabhu";
    m[18].name="biriyani";
    m[18].prod_budget=36;
    m[18].Boxoffice=52;
    m[18].outcome=22;
    m[18].rating=5.8;
    m[18].act_rating=5.9;
    m[18].dir_rating=5.5;

    m[19].act_name="karthik";
    m[19].dir_name="ranjith";
    m[19].name="madras";
    m[19].prod_budget=25;
    m[19].Boxoffice=14;
    m[19].outcome=-11;
    m[19].rating=2.3;
    m[19].act_rating=2.0;
    m[19].dir_rating=1.5;

    m[20].act_name="dhanush";
	m[20].dir_name="vetrimaran";
	m[20].name="vada chennai";
	m[20].prod_budget=60;
	m[20].Boxoffice=90;
	m[20].outcome=92;
	m[20].rating=8.9;
	m[20].act_rating=8.9;
	m[20].dir_rating=7.9;

	m[21].act_name="dhanush";
	m[21].dir_name="balaji_mohan";
	m[21].name="maari 2";
	m[21].prod_budget=30;
	m[21].Boxoffice=29;
	m[21].outcome=34;
	m[21].rating=5.9;
	m[21].act_rating=6;
	m[21].dir_rating=6;

	m[22].act_name="dhanush";
	m[22].dir_name="soundarya";
	m[22].name="vip 2";
	m[22].prod_budget=20;
	m[22].Boxoffice=39;
	m[22].outcome=37;
	m[22].rating=5.5;
	m[22].act_rating=6.6;
	m[22].dir_rating=5.2;

    m[23].act_name="dhanush";
	m[23].dir_name="durai_senthil";
	m[23].name="kodi";
	m[23].prod_budget=35;
	m[23].Boxoffice=53;
	m[23].outcome=57;
	m[23].rating=6.8;
	m[23].act_rating=7;
	m[23].dir_rating=6.7;

	m[24].act_name="dhanush";
	m[24].dir_name="durai_senthil";
	m[24].name="kodi";
	m[24].prod_budget=35;
	m[24].Boxoffice=53;
	m[24].outcome=57;
	m[24].rating=6.8;
	m[24].act_rating=7;
	m[24].dir_rating=6.7;

	m[25].act_name="dhanush";
	m[25].dir_name="KVAnand";
	m[25].name="anegan";
	m[25].prod_budget=49;
	m[25].Boxoffice=45;
	m[25].outcome=50;
	m[25].rating=6.7;
	m[25].act_rating=8.7;
	m[25].dir_rating=7.8;

	m[26].act_name="dhanush";
	m[26].dir_name="velraj";
	m[26].name="thanga_magan";
	m[26].prod_budget=33;
	m[26].Boxoffice=31;
	m[26].outcome=38;
	m[26].rating=6;
	m[26].act_rating=8.7;
	m[26].dir_rating=5.5;

	m[27].act_name="dhanush";
	m[27].dir_name="velraj";
	m[27].name="vip 1";
	m[27].prod_budget=12;
	m[27].Boxoffice=65;
	m[27].outcome=69;
	m[27].rating=6;
	m[27].act_rating=8.7;
	m[27].dir_rating=7.8;

	m[28].act_name="dhanush";
	m[28].dir_name="bharat_bala";
	m[28].name="mariyaan";
	m[28].prod_budget=25;
	m[28].Boxoffice=35;
	m[28].outcome=39;
	m[28].rating=7.2;
	m[28].act_rating=8.7;
	m[28].dir_rating=7;

	m[29].act_name="dhanush";
	m[29].dir_name="sakunan";
	m[29].name="naiyaandi";
	m[29].prod_budget=10;
	m[29].Boxoffice=6;
	m[29].outcome=8;
	m[29].rating=2,9;
	m[29].act_rating=8.7;
	m[29].dir_rating=4.2;

	m[30].act_name="dhanush";
	m[30].dir_name="aishwarya";
	m[30].name="Three";
	m[30].prod_budget=20;
	m[30].Boxoffice=40;
	m[30].outcome=45;
	m[30].rating=6.8;
	m[30].act_rating=8.7;
	m[30].dir_rating=7.5;

	m[31].act_name="vijay";
	m[31].dir_name="ARMurugadoss";
	m[31].name="sarkar";
	m[31].prod_budget=150;
	m[31].Boxoffice=250;
	m[31].outcome=100;
	m[31].rating=9.5;
	m[31].act_rating=8.5;
	m[31].dir_rating=9;

	m[32].act_name="vijay";
	m[32].dir_name="atlee";
	m[32].name="mersal";
	m[32].prod_budget=120;
	m[32].Boxoffice=251;
	m[32].outcome=80;
	m[32].rating=8.1;
	m[32].act_rating=7.5;
	m[32].dir_rating=8.5;

	m[33].act_name="vijay";
	m[33].dir_name="atlee";
	m[33].name="theri";
	m[33].prod_budget=65;
	m[33].Boxoffice=150;
	m[33].outcome=80;
	m[33].rating=7.2;
	m[33].act_rating=8;
	m[33].dir_rating=8.5;

	m[34].act_name="vijay";
	m[34].dir_name="bharathan";
	m[34].name="bhairava";
	m[34].prod_budget=85;
	m[34].Boxoffice=110;
	m[34].outcome=75;
	m[34].rating=6.2;
	m[34].act_rating=9.5;
	m[34].dir_rating=8;

	m[35].act_name="vijay";
	m[35].dir_name="chimbu_devan";
	m[35].name="puli";
	m[35].prod_budget=118;
	m[35].Boxoffice=100;
	m[35].outcome=60;
	m[35].rating=4.7;
	m[35].act_rating=7.5;
	m[35].dir_rating=7;

	m[36].act_name="vijay";
	m[36].dir_name="Neason";
	m[36].name="jilla";
	m[36].prod_budget=50;
	m[36].Boxoffice=85;
	m[36].outcome=80;
	m[36].rating=6.3;
	m[36].act_rating=8.5;
	m[36].dir_rating=8;

	m[37].act_name="vijay";
	m[37].dir_name="ARMurugadoss";
	m[37].name="kaththi";
	m[37].prod_budget=70;
	m[37].Boxoffice=15;
	m[37].outcome=20;
	m[37].rating=8;
	m[37].act_rating=7;
	m[37].dir_rating=8;

	m[38].act_name="vijay";
	m[38].dir_name="Vijay";
	m[38].name="thalaiva";
	m[38].prod_budget=50;
	m[38].Boxoffice=42;
	m[38].outcome=30;
	m[38].rating=6.3;
	m[38].act_rating=9.5;
	m[38].dir_rating=7.5;

	m[39].act_name="vijay";
	m[39].dir_name="shankar";
	m[39].name="nanban";
	m[39].prod_budget=60;
	m[39].Boxoffice=180;
	m[39].outcome=60;
	m[39].rating=6.1;
	m[39].act_rating=8.5;
	m[39].dir_rating=9;

	m[40].act_name="vijay";
	m[40].dir_name="ARMurugadoss";
	m[40].name="kaththi";
	m[40].prod_budget=70;
	m[40].Boxoffice=15;
	m[40].outcome=25;
	m[40].rating=7.9;
	m[40].act_rating=6.5;
	m[40].dir_rating=6.8;

}

void display_director()
{   char dir[24];
     if((fp=fopen("movie.txt","rb"))==NULL)
              printf("\n Error the file does not exists");
     else
     {
    printf("\n Enter the Directors Name:");
     scanf("%s",dir);
     for(int i=0;i<n;i++)
    {
        if(strcmp(dir,m[i].dir_name)==0)
        {
            printf("\nactor: %s\ndirector: %s\nmoviename: %s\nbudget: %d\nboxoffice: %d\noutcome: %d\nrating: %.1f\nactor rating: %.1f\ndirector rating: %.1f",m[i].act_name,m[i].dir_name,m[i].name,m[i].prod_budget,m[i].Boxoffice,m[i].outcome,m[i].rating,m[i].act_rating,m[i].dir_rating);
            printf("\n\n");
        }
    }
}
}
void top_rated()
{
    if((fp=fopen("movie.txt","rb"))==NULL)
              printf("\n Error the file does not exists");
    else
    {
    for(int i=0;i<n;i++)
    {
        if(m[i].rating > 8.0)
        {
            printf("\nactor: %s\ndirector: %s\nmoviename: %s\nbudget: %d\nboxoffice: %d\noutcome: %d\nrating: %.1f\nactor rating: %.1f\ndirector rating: %.1f",m[i].act_name,m[i].dir_name,m[i].name,m[i].prod_budget,m[i].Boxoffice,m[i].outcome,m[i].rating,m[i].act_rating,m[i].dir_rating);
            printf("\n\n");
        }
    }
}
}

void descriptive()
{
    float avg,var,sd,sum=0,sum_square=0,count=0;
    char nam[24];
    int ch;
     if((fp=fopen("movie.txt","rb"))==NULL)
              printf("\n Error the file does not exists");
    else
    {
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
}
void predictive()
{
    float coefficient,sum_p=0,sum_o=0,sum_square_p=0,sum_square_o=0,sum_po=0,denominator,a0,a1,input_budget,output;
    int i;
     if((fp=fopen("movie.txt","rb"))==NULL)
              printf("\n Error the file does not exists");
    else
    {
    for(i=0;i<n;i++)
    {
        sum_p= sum_p + (float)m[i].prod_budget; sum_o = sum_o + (float) m[i].outcome;
        sum_po= sum_po + (m[i].prod_budget * m[i].outcome);
        sum_square_p += m[i].prod_budget * m[i].prod_budget;
        sum_square_o += m[i].outcome * m[i].outcome;

    }
    coefficient = ((n*sum_po)-(sum_o*sum_p))/ sqrt(((n*sum_square_p)-(sum_p*sum_p)) * ((n*sum_square_o)-(sum_o*sum_o)) ) ;
    printf("\n The correlation coefficient is between the production budget and profit output : %f", coefficient);

    denominator = (n * sum_square_p) - (sum_p * sum_p);
    a0 = ((sum_o * sum_square_p) - (sum_p * sum_po) )/ denominator;
    a1 = ((n * sum_po) - (sum_p * sum_o)) / denominator;
    printf("\n The regression equation is : \n y = %fx + %f",a1, a0);
    printf("\n Enter the production budget: "); scanf("%f",&input_budget);
    output = (a1*input_budget) + a0;
    printf("\n The predicted collection profit is : %f",output);




}
}
void main()
{
    int choice;
    insert_data();
    while(1)
    {
        printf("\nMENU:\n Enter your choice:\n 1. Display movies by director\n 2. Top rated movies\n 3. Descriptive analysis on ratings\n 4. Predictive analysis on collection\n 5. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: display_director();break;
            case 2: top_rated();break;
            case 3: descriptive();break;
            case 4: predictive();break;
            case 5: return;break;
            default: printf("\n Invalid choice");break;

        }

    }
}

