#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// 4.2
typedef struct{
    char *flavor;
    int popularity_number;
    int quantity;
}Gelato;

typedef struct{
    char *manager;
    int num_staff;
    Gelato **arr;
}AlgosStore;

typedef struct{
    char *CEO;
    AlgosStore **arr;
}AlgosGelatos;

void print_gelatos(AlgosGelatos algo){
    int i = 0;
    printf("CEO: %s\n", algo.CEO);
    while(algo.arr[i]){
        printf("Name of Manager: %s\n", algo.arr[i]->manager);
        printf("Number of staff members: %d\n", algo.arr[i]->num_staff);
        int j = 0;
        printf("Gelato flavors:\n");
        while(algo.arr[i]->arr[j]->flavor){
            printf("\t%s, %d, %d\n",algo.arr[i]->arr[j]->flavor, algo.arr[i]->arr[j]->popularity_number, algo.arr[i]->arr[j]->quantity);
            j++;
        }i++;
    }
}

int distributor(AlgosGelatos *store, AlgosStore **arr){
    return 1;
}


// 4.3
int check_2038(long long int curr_time, long long int n){
    /**
     return 1 if max time is exceeded. return 0 if stays safe.
     **/
    long long int max_seconds = 0b1 >> n;
    printf("%lld\n", max_seconds);
    if (curr_time > max_seconds +1){
        return 1;
    }
    return 0;
}

//int *create_time(int length, int *time){
//  int new_length;
//return new_length;

//}

int main(void){
    AlgosGelatos algo;
    algo.arr = malloc(sizeof(AlgosStore*)*3);
    algo.CEO = "Ryan";
    for(int i=0; i<3;i++){
        algo.arr[i] = malloc(sizeof(AlgosStore));
    }
    algo.arr[3] = NULL;

    algo.arr[0]->manager = "Steve";
    algo.arr[1]->manager = "Jeff";
    algo.arr[2]->manager = "Bob";

    algo.arr[0]->num_staff = 10;
    algo.arr[1]->num_staff = 20;
    algo.arr[2]->num_staff = 30;

    algo.arr[0]->arr = malloc(sizeof(Gelato*));
    algo.arr[0]->arr[0] = malloc(sizeof(Gelato));
    algo.arr[0]->arr[1] = NULL;

    algo.arr[1]->arr = malloc(sizeof(Gelato*));
    algo.arr[1]->arr[0] = malloc(sizeof(Gelato));
    algo.arr[1]->arr[1] = NULL;

    algo.arr[2]->arr = malloc(sizeof(Gelato*));
    algo.arr[2]->arr[0] = malloc(sizeof(Gelato));
    algo.arr[2]->arr[1] = NULL;

    algo.arr[0]->arr[0]->flavor = "Mango";
    algo.arr[0]->arr[0]->popularity_number = 5;
    algo.arr[0]->arr[0]->quantity = 7;

    algo.arr[1]->arr[0]->flavor = "Strawberry";
    algo.arr[1]->arr[0]->popularity_number = 10;
    algo.arr[1]->arr[0]->quantity = 14;

    algo.arr[2]->arr[0]->flavor = "Banana";
    algo.arr[2]->arr[0]->popularity_number = 15;
    algo.arr[2]->arr[0]->quantity = 21;

    print_gelatos(algo);
}

