#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 200


double** MyAllocate();
void MyReRead();
void  MatrixProduct();

//Reads File
int MyReadFile(char filename[]){

    FILE *fp;
    int N=0;
//Open the file
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Cannot open \" %s \" for reading.\n", filename);
        exit(1);
    }
    printf("File %s opened successfully\n", filename);

//Count the number of lines
    char ch;
    while(!feof(fp)){
      ch = fgetc(fp);
        if(ch == '\n'){
               N++;
      }
    }

//Close the file
    fclose(fp);

    return N;
}

//Allocates Memory
double** MyAllocate(int N){
    double **M;
//First allocate the memory for vectors of length N
    int i,j;
    M = (double **) malloc (N * sizeof (double *));
//Then allocate the memory for a vector of vectors
    for (i = 0; i < N; i++)    {
        M[i] = (double *) malloc (N * sizeof (double));
        for(j=0;j<N;j++){
            M[i][j]=0;
        }
    }
    return M;
}

//Re-Read File
void MyReRead(double ***M,int N,char filename[]){

    FILE *fp;
    int i,j;
    //open the file
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Cannot open \" %s \" for reading.\n", filename);
        exit(1);
    }
    printf("File %s opened successfully\n", filename);

//Read all rows and all columns
//With a double for loop
    for(i=0;i<N;i++){
            for(j=0;j<N-1;j++){
               fscanf (fp, "%lf ", &(*M)[i][j]);}
           fscanf (fp, "%lf\n ", &(*M)[i][N-1]);
    }
//Close the file
    fclose(fp);
}

//Matrix Product Function
void MatrixProduct(double **A,double **B, double ***C,int N){

    int i, j, k;
    int c;
          for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    (*C)[i][j]= 0;

                      for(k=0;k<N;k++)
                      {
                          (*C)[i][j] += A[i][k]*B[k][j];
                      }
                }
            }
        }

//Computes Average Function
float Average(double **D,int N){
    int l;
    int v;
    int temp=0;
    float avg;

    for(l=0;l<N;l++)
     {
         for(v=0;v<N;v++)
            {
                temp+=D[l][v];
            }

     }
     avg=(float)temp/(N*N);
     return avg;
}

//MAIN CODE
int main(){

//Size of the matrix TBD
        int N=0;
        char filename[MAX_FILE_NAME];
        printf("Enter file name: ");
        scanf("%s", filename);
//Read the file one time, to determine the number or rows
        N=MyReadFile(filename);
        printf("The number of rows in the file is N=%d\n",N);
        float avg;

//Allocate the memory for the matrix M
        double **M;
        M=MyAllocate(N);

//Repeat allocation for matrix C and D
        double **C, **D;
        C=MyAllocate(N);
        D=MyAllocate(N);

//Re-Read the file to upload the matrix (from the file, into the memory)
    MyReRead(&M,N,filename);

//Print the matrix M (from the file)
//Compute the powers and taking average of each Matrix

    int i,j,k;
    printf("Power (N) is %d\n",1);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           printf("%.2lf\t",M[i][j]);
        }
        printf("\n");
    }

avg=Average(M,N);
printf("Average of Matrix is %.2lf\n",avg);

//Compute C=M*M
MatrixProduct(M,M,&C,N);

printf("Power (N) is %d\n",2);
for(i=0;i<N;i++)
{
        for(j=0;j<N;j++)
        {
            printf("%.2lf\t",C[i][j]);
        }
    printf("\n");
}

avg=Average(C,N);
printf("Average of Matrix is %.2lf\n",avg);


for(i=2;i<N;i++)
{
//Compute C=C*M=M*M*M
    MatrixProduct(M,C,&D,N);
    printf("Power (N) is %d\n",i+1);

    for(k=0;k<N;k++)
    {
        for(j=0;j<N;j++)
        {
            printf("%.2lf\t",D[k][j]);
        }
        printf("\n");
    }

avg=0;
avg=Average(D,N);
printf("Average of Matrix is %.2lf\n",avg);

    for(k=0;k<N;k++)
    {
        for(j=0;j<N;j++)
        {
            C[k][j]=D[k][j];
            D[k][j]=0;
        }
    }

//Deallocate the memory
        for (i = 0; i < N; i++)    {
        free(M[i]); free(C[i]);free(D[i]);
    }
    free(M);free(C);free(D);
}
}
