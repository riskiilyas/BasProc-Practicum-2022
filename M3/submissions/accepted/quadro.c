#include <stdio.h>
int N, ctr = 1;

int quadronacci(int n) {
    if (n >= 1 && n <= 3){
        if(n==ctr) {
            printf("0, ");
            ctr++;
        }
        return 0;
    } else if (n == 4){
        if(n==ctr) {
            printf("1, ");
            ctr++;
        }
        return 1;
    }
    
    int element = quadronacci(n-4) + quadronacci(n-3) + quadronacci(n-2) + quadronacci(n-1);
    if(n==ctr) {
        if(ctr==N) printf("%d", element);
        else printf("%d, ", element);
        ctr++;
    }
    return element;
}

int main() {
    scanf("%d", &N);
    if(N==1) {
        printf("0");
    } else if(N==2) {
        printf("0, 0");
    } else if(N ==3) {
        printf("0, 0, 0");
    } else if(N==4) {
        printf("0, 0, 0, 1");
    } else {
        quadronacci(N);
    }
    
    return 0;
}