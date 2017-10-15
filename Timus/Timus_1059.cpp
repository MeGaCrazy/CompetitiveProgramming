/**
*   Idea : just simulate the prcoess 
*
*
**/

#include "bits/stdc++.h"

int main()
{
    int n = 0, i = 0;

    scanf("%d", &n);

    puts("0");
    for(i = 1; i <= n; i++){
        printf("X\n*\n%d\n+\n", i);
    }

	return 0;
}