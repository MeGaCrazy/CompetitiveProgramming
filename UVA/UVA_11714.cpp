/*
*     simply to get the larget number he need to ask (n-1) number
*     then it's be two interval to ask for next one can be achieved by log2(n-1) :) 
*
*/


#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;

main() {
    ULL n;
    while (scanf("%lld", &n)!=EOF) {
        printf("%lld\n", n-1 + (ULL)log2(n-1));
    }
}