for (int i = 0; i < r1; i++)       // Loop 1
{
    for (int j = 0; j < c2; j++)   // Loop 2
    {
        for (int k = 0; k < c1; k++)  // Loop 3
        {
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}