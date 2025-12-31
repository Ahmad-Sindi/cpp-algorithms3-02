#include <iostream>
#include <iomanip> // For output formatting (setw)
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

/*
 * Algorithm Challenge & Problem Solving
 * Level 3 – Challenge#2 (Sum of Each Row in a 3x3 Matrix)
 *
 * This program fills a 3x3 matrix with random numbers, prints the matrix, then calculates and displays the sum of each row.
 *
 * This challenge focuses on:
 * - Working with 2D arrays (matrices)
 * - Traversing rows and columns using loops
 * - Applying decomposition by separating logic into functions
 * - Strengthening understanding of data structure traversal
 */

using namespace std;

// Generates a random number between From and To (inclusive)
int RandNumb(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Fills the matrix with random numbers
void FillMatrxRandom(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++) // Loop through rows
    {
        for (short j = 0; j < Cols; j++) // Loop through columns
        {
            arr[i][j] = RandNumb(1, 99); // Assign random value
        }
    }
}

// Prints the 3x3 matrix
void Print3Mat(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Calculates the sum of a specific row
int RowSum(int arr[3][3], short RowNumb, short Cols)
{
    int Sum = 0;

    // Traverse all columns of the given row
    for (short j = 0; j < Cols; j++)
    {
        Sum += arr[RowNumb][j];
    }

    return Sum;
}

// Prints the sum of each row in the matrix
void PrintSumRows(int arr[3][3], short Rows, short Cols)
{
    cout << "\nThe following are the sums of each row in the matrix:\n";

    for (short i = 0; i < Rows; i++)
    {
        cout << "Row " << i + 1 << " Sum = "
             << setw(3) << RowSum(arr, i, Cols) << endl;
    }
}

int main()
{
    // Seed random number generator
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrxRandom(arr, 3, 3);

    cout << "The following is a 3x3 Random Matrix:\n\n";
    Print3Mat(arr, 3, 3);

    PrintSumRows(arr, 3, 3);

    return 0;
}
