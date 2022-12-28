#include<stdio.h>
#include<string.h>
#include<math.h>

void sort(char arr[], int n){
    int i, j;
    char temp; 
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    char str[500];
    int k, n;

    scanf("%s", str);
    getchar();
    scanf("%d", &k);
    n = strlen(str);

    int max_size = 0;
    char max_sum[20];

    for (int i = 0; i < n - k + 1; i++) {
        char arr[k], ctr = 0;
        
        for (int j = 0; j < k; j++)
                arr[ctr++] = str[i + j];

        sort(arr, ctr);
        if(strcmp(arr, max_sum)>0){
            max_size = ctr;
            strcpy(max_sum, arr);
        }
    }

    for (int i = 0; i < max_size; i++){
        printf("%c", max_sum[i]);
    }
    
    return 0;
}