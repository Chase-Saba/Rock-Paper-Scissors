#include <iostream>
#include <ctime>
#include <random>
using namespace std;

class Charles_Alg {
    public: 
    char Algorithm1(char opp_array[]);
    char Algorithm2(char opp_array[]);
    
};

char Algorithm1(char opp_array[]){
    //completly random algorithm
    int num = rand() % 3 + 1;
    char play;
    if(num == 1){
        char play = 'r';
    }
    else if (num == 2){
        char play = 'p';
    }
    else{
        char play = 's';
    }
    return play;
}

char Algorithm2(char opp_array[]){
    //completly random algorithm
    int num = rand() % 3 + 1;
    char play;
    if(num == 1){
        char play = 'r';
    }
    else if (num == 2){
        char play = 'p';
    }
    else{
        char play = 's';
    }
    return play;
}


