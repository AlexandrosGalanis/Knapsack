//Alexandros Galanis icsd14027 Diakritos Sakos tou Listi(Sunexia apo lab05)
//O(2^n)
//dynamic programming
#include <iostream>

using namespace std;

int max(int a,int b){
    return (a > b)? a : b;
}

int knapSack(int AvailableSpace, int weights[], int values[] , int lenght){
    int i,w;
    int Sack[lenght + 1][AvailableSpace + 1];

    for(i = 0 ; i <= lenght ; i++){
        for(w = 0; w <= AvailableSpace; w++){
            if(i == 0 || w == 0){
                Sack[i][w] = 0;
            }else if(weights[i - 1] <= w){
                Sack[i][w] = max(values[i - 1]+ Sack[i - 1][w-weights[i - 1]], Sack[i - 1][w]);
            }else{
                Sack[i][w] = Sack[i - 1][w];
            }
        }
    }

    return Sack[lenght][AvailableSpace];
}

int main(){

    int values[] = {60 , 100 , 120};
    int weights[] = {10 , 20 , 30};

    int AvailableSpace = 50;
    cout<<knapSack(AvailableSpace, weights, values, 3);

    return 0 ;
}
