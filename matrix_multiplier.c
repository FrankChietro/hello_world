#include<stdio.h>
#include<conio.h>


int main()
{

// Checks to see if the column in Matrix1 is equal to the row in Matrix2

    int row1, column1, row2, column2;
    printf("Matrix1 row(s) and column(s) ");

    scanf("%d %d", &row1, &column1);

    printf("Matrix2 row(s) and column(s) ");

    scanf("%d %d",&row2, &column2);

    while (column1 != row2 )
    {float avg;
        printf("Not correct \n\n");

        printf("Try Again");

        scanf("%d %d", &row1, &column1);

        printf("Matrix2 row(s) and column(s)");

        scanf("%d %d",&row2, &column2);
    }


    int NR1=row1;
    int NC1=column1;
    int NR2=row2;
    int NC2=column2;
    int Matrix1[NR1][NC1], Matrix2[NR2][NC2], Matrix3[NR1][NC2];
    int a,b,c;




// Matrix1 stored

    printf("Enter first Matrix\n");

    for (a=0;a<NR1;a++)
    {
        for (b=0;b<NC1;b++)
        {
            scanf("%d",&Matrix1[a][b]);
        }
    }

// Matrix2 stored
    printf("Enter second Matrix\n");

    for (a=0;a<NR2;a++)
    {
        for (b=0;b<NC2;b++)
        {
            scanf("%d",&Matrix2[a][b]);
        }
    }

// Setting Matrix3 to zero
    for(a=0;a<NR1;a++)
    {

        for(b=0;b<NC2;b++)
        {
          Matrix3[a][b]=0;
        }

    }


// Matrix1 and Matrix2 are multiplied


    for(a=0;a<NR1;a++)
    {
        for(b=0;b<NC2;b++)
        {
              for(c=0;c<NC1;c++)
              {
                  Matrix3[a][b] +=  Matrix1[a][c] * Matrix2[c][b];
              }
        }

    }
    printf("Answer is \n");

    for(a=0;a<NR1;a++)
    {
         for(b=0;b<NC2;b++)
         {
             printf("%d\t",Matrix3[a][b]);
         }
             printf("\n");

    }

//Computing Average of the Matrix3

    int i;
    int j;
    int temp=0;
    float avg;


    for(i=0;i<NR1;i++)
     {
         for(j=0;j<NC2;j++)
            {
                temp+=Matrix3[i][j];
            }


     }

     avg=(float)temp/(NR1*NC2);


     printf("Average is %lf",avg);


    return 0;


}

