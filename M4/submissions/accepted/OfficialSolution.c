#include <stdio.h>
#include <string.h>
typedef struct Contestant{
    char name[20];
    int foodPerMinute;
    struct Contestant* teammate;
} Contestant;

int main() {
    
    int n, minute;
    scanf("%d %d", &n, &minute);
    
    Contestant arr[n];

    for (int i = 0; i < n; i++){
        Contestant c;
        scanf("%s", c.name);
        getchar();
        scanf("%d", &(c.foodPerMinute));

        arr[i] = c;
    }

    for (int i = 0; i < n/2; i++){
        char n1[20], n2[20];
        scanf("%s", n1);
        getchar();
        scanf("%s", n2);
        getchar();

        for (int j = 0; j < n; j++){
            if (!strcmp(n1, arr[j].name)){
                for(int k = 0; k < n; k++) {
                    if(!strcmp(n2, arr[k].name)) {
                        arr[j].teammate = &arr[k];
                        arr[k].teammate = NULL;
                        break;
                    }
                }
                break;   
            }
        }        
    }

    Contestant winner;
    int maxEaten = -1;
    for (int i = 0; i < n; i++){
        if (arr[i].teammate==NULL) continue;
        
        int totalEaten = (arr[i].foodPerMinute + ((arr[i].teammate)->foodPerMinute)) * minute;
        if (totalEaten > maxEaten){
            maxEaten = totalEaten;
            winner = arr[i];
        }
    }

    printf("%s & %s Win!\nTotal Eaten: %d", winner.name, winner.teammate->name, maxEaten);
    
    return 0;
}
