#include <pthread.h>
#include <iostream>
#include <semaphore.h>
#include <unistd.h>
#include<math.h>



class Matrix{
    public:
    const int MATRIX_DIMENSION = 4096; 
    const int NUM_THREADS = 25; 
};

Matrix matObj;

        double **A;
        double **B;
        double **C;
        
        const int THREAD_DIMENSION = matObj.MATRIX_DIMENSION / matObj.NUM_THREADS; 
        pthread_t * thread[25];
        using namespace std;
        
    void *MatrixMul (void * arg)
    {
        int index;
        index = (intptr_t) arg;
        int operation_Lower_Limit = ((index+1) * THREAD_DIMENSION) - THREAD_DIMENSION  ; 
        int operation_Upper_Limit = ((index+1) * THREAD_DIMENSION) - 1; 
        
        for(int i=operation_Lower_Limit;i<=operation_Upper_Limit;i++) 
                {
            for(int j=0 ;j<matObj.MATRIX_DIMENSION; j++)
            {
                for(int k=0;k<matObj.MATRIX_DIMENSION;k++)
                {
                    C[i][j]+=A[i][k]*B[k][j];
                    cout<<"MULTIPLY !!!";
                }
            }                                                                                                                                                                                                                                                                                                                                           
        }
        return NULL;
    }
    
    int main()
    {


        pthread_t * thread[matObj.NUM_THREADS];

        srand(time(0));
        //Assign memory for threads
        for(int i=0;i < matObj.NUM_THREADS;i++)
        {
        thread[i] = new pthread_t;
        }
    
        A = new double*[matObj.MATRIX_DIMENSION];
        for(int i = 0; i < matObj.MATRIX_DIMENSION; i++)
        {
            A[i] = new double[matObj.MATRIX_DIMENSION];
        }
        B = new double*[matObj.MATRIX_DIMENSION];
        for(int i = 0; i < matObj.MATRIX_DIMENSION; i++)
        {
            B[i] = new double[matObj.MATRIX_DIMENSION];
        }
        C = new double*[matObj.MATRIX_DIMENSION];
    
        for(int i = 0; i < matObj.MATRIX_DIMENSION; i++)
        {
            C[i] = new double[matObj.MATRIX_DIMENSION];
        }
        for(int i=0;i<matObj.MATRIX_DIMENSION;i++)
        {
            for(int j=0;j<matObj.MATRIX_DIMENSION;j++)
            {
                A[i][j] = rand() % 10000;
                B[i][j] = rand() % 10000;
                C[i][j] = 0;
            }
        }
        
        for(int i=0;i<matObj.NUM_THREADS;i++)
        {
        pthread_create( thread[ i ], NULL, (MatrixMul), (void *)(intptr_t) (i) );
        
        }
        for(int i=0;i<matObj.NUM_THREADS;i++)
        {
        pthread_join(*thread[i],NULL);
        }
        
        for (int i = 0; i < matObj.MATRIX_DIMENSION; i++)
        {
            delete[] A[i];
        }
        delete[] A;
        for (int i = 0; i < matObj.MATRIX_DIMENSION; i++)
        {
            delete[] B[i];
        }
        delete[] B;
        for (int i = 0; i < matObj.MATRIX_DIMENSION; i++)
        {
            delete[] C[i];
        }
        delete[] C;
        return(0);
    }