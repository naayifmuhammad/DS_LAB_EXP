#include <stdio.h>

#define maxArraySize 20

int size, UniversalSet[maxArraySize] = {0}, A[maxArraySize] = {0}, B[maxArraySize] = {0}, compliment_A[maxArraySize] = {0}, compliment_b[maxArraySize] = {0}, difference[maxArraySize] = {0}, union_AB[maxArraySize] = {0}, intersection_AB[maxArraySize] = {0};

void readArrays();

void main()
{
    int i;
    // Use to read the universal set and bit vectors of set A and set B
    readArrays();

    // First print Universal set, set A and set B

    // universal set
    printf("\nUniversal set : ");
    for (i = 0; i < size; i++)
        printf("%d ", UniversalSet[i]);

    // set A
    printf("\nSet A : ");
    for (i = 0; i < size; i++)
        if (UniversalSet[i] && A[i])
            printf("%d ", UniversalSet[i]);

    // Set B
    printf("\nSet B : ");
    for (i = 0; i < size; i++)
        if (UniversalSet[i] && B[i])
            printf("%d ", UniversalSet[i]);

    // Now to perform operation on set A and set B:

    // Union
    printf("\nUnion of A & B\n");
    for (i = 0; i < size; i++)
        if (A[i] || B[i])
            printf("%d ", UniversalSet[i]);

    printf("\nIntersection of A & B\n");
    for (i = 0; i < size; i++)
        if (A[i] && B[i])
            printf("%d ", UniversalSet[i]);
    printf("\nA compliment\n");
    for (i = 0; i < size; i++)
    {
        compliment_A[i] = 1 - A[i];
        if (UniversalSet[i] && compliment_A[i])
            printf("%d", UniversalSet[i]);
    }
    printf("\nB compliment\n");
    for (i = 0; i < size; i++)
    {
        compliment_b[i] = 1 - B[i];
        if (UniversalSet[i] && compliment_b[i])
            printf("%d", UniversalSet[i]);
    }
    printf("\nA-B\n");
    for (i = 0; i < size; i++)
    {
        if (A[i] && compliment_b[i])
            printf("%d", UniversalSet[i]);
    }
    printf("\nB-A\n");
    for (i = 0; i < size; i++)
    {
        if (B[i] && compliment_A[i])
            printf("%d", UniversalSet[i]);
    }
}

void readArrays()
{
    int i;
    printf("Enter the desired size of your universal set: ");
    scanf("%d", &size);
    printf("Enter the elements for the Universal set [Size = %d] :\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &UniversalSet[i]);
    printf("Enter the elements for set A [Bitvector form]:\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &A[i]);
    printf("Enter the elements for set B [Bitvector form]:\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &B[i]);
}
