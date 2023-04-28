/*21CP046-BVM engineering college
  Project for ES105
  ("MATRIX CALCULATOR")*/

#include<stdio.h>
#include<iostream>
using namespace std;

int i, j, k;
    int matrixA[10][10];
    int matrixB[10][10];
    int rowA, colA;
    int rowB, colB;
    int operation;
    char again = 'Y';
    int scalar = 0;
    int add = 1;
    int sub = -1;

    void readMatrix(int array[10][10], int rows, int colums){
    int i, j;
    for (i = 0; i < rows; i++){
        printf("\t%d entries for row %d: ", colums, i + 1);
        for (j = 0; j < colums; j++){
            scanf("%d", &array[i][j]);
        }
    }
    return;
}

void printMatrix(int array[10][10], int rows, int colums){
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < colums; j++){
            printf("\t%d", array[i][j]);
        }
        printf("\n");
    }
}

void matrixAddSub(int arrayone[10][10], int arraytwo[10][10], int rows, int colums, int mul){
    int i, j;
    int sumM[10][10];
    int scaM[10][10];
    for (i = 0; i < rows; i++){
        for (j = 0; j < colums; j++){
            scaM[i][j] = mul * arraytwo[i][j];
            }
        }

    for (i = 0; i < rows; i++){
        for (j = 0; j < colums; j++){
            sumM[i][j] = arrayone[i][j] + scaM[i][j];
            printf("\t%d", sumM[i][j]);
        }
        printf("\n");
    }
}

void matrixScalarMultiply(int array[10][10], int scalar, int rows, int colums){
    int i, j;
    int scaM[10][10];
    for (i = 0; i < rows; i++){
        for (j = 0; j < colums; j++){
            scaM[i][j] = scalar * array[i][j];
            printf("%d\t", scaM[i][j]);
        }
        printf("\n");
    }
}

void matrixMultiply(int arrayone[10][10], int arraytwo[10][10], int rowsA, int columsA,int columsB){
    int i, j, k;
    int mulM[10][10];

    for (i = 0; i<rowsA; ++i)
        for (j = 0; j<columsB; ++j)
        {
            mulM[i][j] = 0;
        }

    for (i = 0; i<rowsA; ++i)
        for (j = 0; j<columsB; ++j)
            for (k = 0; k<columsA; ++k)
            {
                mulM[i][j] += arrayone[i][k] * arraytwo[k][j];
            }
    printf("\nOutput Matrix:\n");
    for (i = 0; i<rowsA; ++i)
        for (j = 0; j<columsB; ++j)
        {
            printf("\t%d ", mulM[i][j]);
            if (j == columsB - 1)
                printf("\n\n");
        }
}

void matrixTranspose(int array[10][10], int rows, int colums){
    int i,j;
    int tranM[10][10];

    for (i=0;i<rows;i++)
    {
        for(j=0;j<colums;j++)
        {
            tranM[i][j]=array[j][i];
            printf("\t%d", tranM[i][j]);
        }
        printf("\n");
    }
}
void addmatrix(){
			printf("\nEnter the #rows and #cols for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("Enter the #rows and #cols for matrix B: ");
            scanf("%d%d", &rowB, &colB);

            while ((rowA != rowB) && (colA != colB)){
                printf("\nMatrices must be the same size\n");
                printf("\nEnter the #rows and #cols for matrix A: ");
                scanf("%d%d", &rowA, &colA);

                printf("Enter the #rows and #cols for matrix B: ");
                scanf("%d%d", &rowB, &colB);

            }

            printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA);
            readMatrix(matrixA, rowA, colA);
            printf("\n\tMatrix A\n\n");
            printMatrix(matrixA, rowA, colA);

            printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB);
            readMatrix(matrixB, rowB, colB);
            printf("\n\tMatrix B\n\n");
            printMatrix(matrixB, rowB, colB);

            printf("\nThe Sum of matrixA + matrixB is : \n");
            matrixAddSub(matrixA, matrixB, rowA, colA, add);
}
void submatrix(){printf("\nEnter the #rows and #cols for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("Enter the #rows and #cols for matrix B: ");
            scanf("%d%d", &rowB, &colB);

            while ((rowA != rowB) && (colA != colB)){
                printf("\nMatrices must be the same size\n");
                printf("\nEnter the #rows and #cols for matrix A: ");
                scanf("%d%d", &rowA, &colA);

                printf("Enter the #rows and #cols for matrix B: ");
                scanf("%d%d", &rowB, &colB);
            }

            printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA);
            readMatrix(matrixA, rowA, colA);
            printf("\n\t\tMatrix A\n\n");
            printMatrix(matrixA, rowA, colA);

            printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB);
            readMatrix(matrixB, rowB, colB);
            printf("\n\t\tMatrix B\n\n");
            printMatrix(matrixB, rowB, colB);

            printf("\nThe difference between matrixA - matrixB is : \n");
            matrixAddSub(matrixA, matrixB, rowA, colA, sub);
            

}
void multiplyscale(){printf("\nEnter the scalar: ");
            scanf("%d", &scalar);
            printf("\nThe scalar is: %d ", scalar);

            printf("\nEnter the #rows and #cols for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA);
            readMatrix(matrixA, rowA, colA);
            printf("\n\t\tMatrix A\n\n");
            printMatrix(matrixA, rowA, colA);

            printf("\nThe scalar multiplication between matrixA * %d is: \n", scalar);
            matrixScalarMultiply(matrixA, scalar, rowA, colA);

           
}
void mulmatrix(){printf("\nEnter the #rows and #cols for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("Enter the #rows and #cols for matrix B: ");
            scanf("%d%d", &rowB, &colB);

            while (colA != rowB)
            {
                printf("\n\nError! column of first matrix not equal to row of second.\n\n");
                printf("\nEnter the #rows and #cols for matrix A: ");
                scanf("%d%d", &rowA, &colA);

                printf("Enter the #rows and #cols for matrix B: ");
                scanf("%d%d", &rowB, &colB);
            }

            printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA);
            readMatrix(matrixA, rowA, colA);
            printf("\n\t\tMatrix A\n\n");
            printMatrix(matrixA, rowA, colA);

            printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB);
            readMatrix(matrixB, rowB, colB);
            printf("\n\t\tMatrix B\n\n");
            printMatrix(matrixB, rowB, colB);

            matrixMultiply(matrixA, matrixB, rowA, colA, colB);
}
void trans(){printf("\nEnter the #rows and #cols for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA);
            readMatrix(matrixA, rowA, colA);
            printf("\n\t\tMatrix A\n\n");
            printMatrix(matrixA, rowA, colA);

            printf("\nThe Transpode of matrixA is: \n");
            matrixTranspose(matrixA, rowA, colA);

}
void printMatrix2(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void inverseMatrix(double** matrix, int n) {
    double** inverse = new double*[n];
    for (int i = 0; i < n; i++) {
        inverse[i] = new double[n];
        for (int j = 0; j < n; j++) {
            inverse[i][j] = 0;
        }
    }

    // Creating the identity matrix
    for (int i = 0; i < n; i++) {
        inverse[i][i] = 1;
    }

    // Performing row operations to get the inverse matrix
    for (int i = 0; i < n; i++) {
        double temp = matrix[i][i];
        for (int j = 0; j < n; j++) {
            matrix[i][j] /= temp;
            inverse[i][j] /= temp;
        }
        for (int j = 0; j < n; j++) {
            if (i != j) {
                temp = matrix[j][i];
                for (int k = 0; k < n; k++) {
                    matrix[j][k] -= matrix[i][k] * temp;
                    inverse[j][k] -= inverse[i][k] * temp;
                }
            }
        }
    }

    cout << "Inverse of the matrix is:" << endl;
    printMatrix2(inverse, n);

    // Freeing the memory
    for (int i = 0; i < n; i++) {
        delete[] inverse[i];
    }
    delete[] inverse;
}

void inverse(){int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    double** matrix = new double*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
        for (int j = 0; j < n; j++) {
            cout << "Enter the element at row " << i+1 << " and column " << j+1 << ": ";
            cin >> matrix[i][j];
        }
    }

    inverseMatrix(matrix, n);

    // Freeing the memory
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

}

int main()
{
	int ch;
        printf("\nOperation Menu\n");
        printf("\t1. to Add\n");
        printf("\t2. to Subtract\n");
        printf("\t3. to Scalar Multiply\n");
        printf("\t4. to Multiply two matrices\n");
        printf("\t5. to Transpose\n");
        printf("\t6. to Inverse\n");
        printf("Enter your choice: ");
 do{
        cin>>ch;
		switch(ch)
		{
			case 1:
				addmatrix();
				break;
			case 2:
				submatrix();
				break;
			case 3:
				multiplyscale();
				break;
			case 4:
				mulmatrix();
				break;
			case 5:
				trans();
				break;
			case 6:
				inverse();
				break;
            default:
                cout<<"Enter value between 1-6"<<endl;
                break;
		}
	}while(ch!=7);
	return 0;
}
