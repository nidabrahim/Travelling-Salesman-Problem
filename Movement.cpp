#ifndef __MOVE__CPP
#define __MOVE__CPP

#include "Solution.cpp"

/**
 * 
 *  NIDABRAHIM YOUSSEF
 *  F2 - G12
 * 
 * **/

class Shift{

    unsigned besti, bestj;
    float bestDetour, minDetour;

    public:
        Shift();
        bool scan(const Solution &);
        double commit(Solution &);

};

Shift::Shift(){
    this->besti = -1;
    this->bestj = -1;
    this->bestDetour = 0;
    this->minDetour = -1000;
}

bool Shift::scan(const Solution & s){

    bool ameliore = false;
    float initDetour = s.getVal();
    for(int i = 1; i < s.getSize()-1 ; i++){
        for(int j = i+1; j < s.getSize()-1 ; j++){

            float oldDetour = s.detour(s.seq_sommets[i-1],s.seq_sommets[i]) + s.detour(s.seq_sommets[i],s.seq_sommets[i+1]) + s.detour(s.seq_sommets[j],s.seq_sommets[j+1]);
            float newDetour = s.detour(s.seq_sommets[i-1],s.seq_sommets[i+1]) + s.detour(s.seq_sommets[j],s.seq_sommets[i]) + s.detour(s.seq_sommets[i],s.seq_sommets[j+1]);
            float res = oldDetour-newDetour;

            if( res > 0 && res > minDetour ){
                    this->besti = i;
                    this->bestj = j;
                    this->bestDetour = initDetour - oldDetour + newDetour;
                    minDetour = res;
                    std::cout << "Shift >> (" << besti  << ", " << bestj << ") = " << this->bestDetour << std::endl;
                    ameliore = true;
                
            }
        }
    }

    return ameliore;
}

double Shift::commit(Solution & s){

    Solution s_ = s;

    int i;
    for( i=besti ; i<bestj ; i++){
        s.seq_sommets[i] = s_.seq_sommets[i+1];
    }
    s.seq_sommets[i] = s_.seq_sommets[besti];
    i++;
    for( int j=bestj+1 ; j<s.getSize() ; i++,j++){
        s.seq_sommets[i] = s_.seq_sommets[j];
    }
    s.eval();
    //s.afficher();std::cout << s.getVal();
    return s.getVal();
}

class Swap{

    unsigned besti, bestj;
    float bestDetour, minDetour;

    public:
        Swap();
        bool scan(const Solution &);
        double commit(Solution &);

};

Swap::Swap(){
    this->besti = -1;
    this->bestj = -1;
    this->bestDetour = 0;
    this->minDetour = -1000;
}

bool Swap::scan(const Solution & s){

    bool ameliore = false;
    float initDetour = s.getVal();
    for(int i = 1; i < s.getSize()-1 ; i++){
        for(int j = i+1; j < s.getSize()-1 ; j++){

            float oldDetour, newDetour;
            if(i != j-1){
                oldDetour = s.detour(s.seq_sommets[i-1],s.seq_sommets[i]) + s.detour(s.seq_sommets[i],s.seq_sommets[i+1]) 
                            + s.detour(s.seq_sommets[j-1],s.seq_sommets[j]) + s.detour(s.seq_sommets[j],s.seq_sommets[j+1]);
                newDetour = s.detour(s.seq_sommets[i-1],s.seq_sommets[j]) + s.detour(s.seq_sommets[j],s.seq_sommets[i+1]) 
                            + s.detour(s.seq_sommets[j-1],s.seq_sommets[i]) + s.detour(s.seq_sommets[i],s.seq_sommets[j+1]);
            }else{
                oldDetour = s.detour(s.seq_sommets[i-1],s.seq_sommets[i]) + s.detour(s.seq_sommets[i],s.seq_sommets[i+1]) 
                            + s.detour(s.seq_sommets[j],s.seq_sommets[j+1]);
                newDetour = s.detour(s.seq_sommets[i-1],s.seq_sommets[i+1]) + s.detour(s.seq_sommets[j],s.seq_sommets[i]) 
                            + s.detour(s.seq_sommets[i],s.seq_sommets[j+1]);
            }
            float res = oldDetour-newDetour;

            if( res > 0 && res > minDetour ){
                    this->besti = i;
                    this->bestj = j;
                    this->bestDetour = initDetour - oldDetour + newDetour;
                    minDetour = res;
                    std::cout << "Swap >> (" << besti  << ", " << bestj << ") = " << this->bestDetour << std::endl;
                    ameliore = true;
            }
        }
    }

    return ameliore;
}

double Swap::commit(Solution & s){

    int temp = s.seq_sommets[besti];
    s.seq_sommets[besti] = s.seq_sommets[bestj];
    s.seq_sommets[bestj] = temp;
    
    s.eval();

    return s.getVal();
}


class Opt2{

    unsigned besti, bestj;
    float bestDetour, minDetour;

    public:
        Opt2();
        bool scan(const Solution &);
        double commit(Solution &);

};

Opt2::Opt2(){
    this->besti = -1;
    this->bestj = -1;
    this->bestDetour = 0;
    this->minDetour = -1000;
}

bool Opt2::scan(const Solution & s){

    bool ameliore = false;
    float initDetour = s.getVal();
    for(int i = 1; i < s.getSize()-1 ; i++){
        for(int j = i+1; j < s.getSize()-1 ; j++){
        
            float oldDetour = s.detour(s.seq_sommets[i],s.seq_sommets[i+1]) + s.detour(s.seq_sommets[j],s.seq_sommets[j+1]);
            float newDetour = s.detour(s.seq_sommets[i],s.seq_sommets[j]) + s.detour(s.seq_sommets[i+1],s.seq_sommets[j+1]);
            float res = oldDetour-newDetour;

            if( res > 0 && res > minDetour ){
                    this->besti = i;
                    this->bestj = j;
                    this->bestDetour = initDetour - oldDetour + newDetour;
                    minDetour = res;
                    std::cout << "Opt2 >> (" << besti  << ", " << bestj << ") = " << this->bestDetour << std::endl;
                    ameliore = true;
            }
        }
    }

    return ameliore;
}

double Opt2::commit(Solution & s){
    
    Solution s_ = s;
    for(int i=besti+1; i<=bestj; i++){
        s.seq_sommets[i] = s_.seq_sommets[bestj+besti+1-i];
    }
    s.eval();
    return s.getVal();
}

class Opt3{

    int besti, bestj, bestk;
    int combinaison;
    float bestDetour, minDetour;

    public:
        Opt3();
        bool scan(const Solution &);
        double commit(Solution &);

};

Opt3::Opt3(){
    this->besti = -1;
    this->bestj = -1;
    this->bestk = -1;
    this->combinaison = 0;
    this->bestDetour = 0;
    this->minDetour = -1000;
}

bool Opt3::scan(const Solution & s){

    bool ameliore = false;
    float initDetour = s.getVal();
    for(int i = 0; i < s.getSize()-2 ; i++){
        for(int j = i+1; j < s.getSize()-1 ; j++){
            for(int k = j+1; k < s.getSize()-1 ; k++){

                float oldDetour = s.detour(s.seq_sommets[i],s.seq_sommets[i+1]) + s.detour(s.seq_sommets[j],s.seq_sommets[j+1]) 
                                + s.detour(s.seq_sommets[k],s.seq_sommets[k+1]);
                float newDetour1 = s.detour(s.seq_sommets[i],s.seq_sommets[j+1]) + s.detour(s.seq_sommets[i+1],s.seq_sommets[k]) 
                                + s.detour(s.seq_sommets[j],s.seq_sommets[k+1]);
                float newDetour2 = s.detour(s.seq_sommets[i],s.seq_sommets[j+1]) + s.detour(s.seq_sommets[i+1],s.seq_sommets[k+1]) 
                                + s.detour(s.seq_sommets[j],s.seq_sommets[k]);
                float newDetour3 = s.detour(s.seq_sommets[i],s.seq_sommets[k]) + s.detour(s.seq_sommets[i+1],s.seq_sommets[j+1]) 
                                + s.detour(s.seq_sommets[j],s.seq_sommets[k+1]);
                float newDetour4 = s.detour(s.seq_sommets[i],s.seq_sommets[j]) + s.detour(s.seq_sommets[i+1],s.seq_sommets[k]) 
                                + s.detour(s.seq_sommets[j+1],s.seq_sommets[k+1]);
               
                if( newDetour1 < oldDetour && oldDetour-newDetour1 > minDetour 
                        && newDetour1 < newDetour2 && newDetour1 < newDetour3 && newDetour1 < newDetour4 ){
                    this->besti = i;
                    this->bestj = j;
                    this->bestk = k;
                    this->combinaison = 1;
                    this->bestDetour = initDetour - oldDetour + newDetour1;
                    this->minDetour = oldDetour-newDetour1;
                    ameliore = true;
                    
                    std::cout << "Opt3 >> (" << this->besti  << ", " << this->bestj << ", " << this->bestk << ") = " << this->bestDetour << std::endl;
                }
                else{
                   if(newDetour2 < oldDetour && oldDetour-newDetour2 > minDetour
                            && newDetour2 < newDetour1 && newDetour2 < newDetour3 && newDetour2 < newDetour4){
                        this->besti = i;
                        this->bestj = j;
                        this->bestk = k;
                        this->combinaison = 2;
                        this->bestDetour = initDetour - oldDetour + newDetour2;
                        this->minDetour = oldDetour-newDetour2;
                        ameliore = true;

                        std::cout << "Opt3 >> (" << this->besti  << ", " << this->bestj << ", " << this->bestk << ") = " << this->bestDetour << std::endl;
                   }
                   else{
                       if(newDetour3 < oldDetour && oldDetour-newDetour3 > minDetour
                                && newDetour3 < newDetour1 && newDetour3 < newDetour2 && newDetour3 < newDetour4){
                            this->besti = i;
                            this->bestj = j;
                            this->bestk = k;
                            this->combinaison = 3;
                            this->bestDetour = initDetour - oldDetour + newDetour3;
                            this->minDetour = oldDetour-newDetour3;
                            ameliore = true;
                            
                            std::cout << "Opt3 >> (" << this->besti  << ", " << this->bestj << ", " << this->bestk << ") = " << this->bestDetour << std::endl;
                       }
                       else{
                           if(newDetour4 < oldDetour && oldDetour-newDetour4 > minDetour
                                    && newDetour4 < newDetour1 && newDetour4 < newDetour2 && newDetour4 < newDetour3){
                                this->besti = i;
                                this->bestj = j;
                                this->bestk = k;
                                this->combinaison = 4;
                                this->bestDetour = initDetour - oldDetour + newDetour4;
                                this->minDetour = oldDetour-newDetour4;
                                ameliore = true;
                                
                                std::cout << "Opt3 >> (" << this->besti  << ", " << this->bestj << ", " << this->bestk << ") = " << this->bestDetour << std::endl;
                           }
                       }
                   }
                }
            }
        }
    }

    return ameliore;
}

double Opt3::commit(Solution & s){

    Solution s_ = s;

    switch(this->combinaison){
        case 1: 
                
               /* for(int i=besti+1 ; i<=bestj ; i++){
                    s.seq_sommets[i] = s_.seq_sommets[bestj+1-besti-1+i];
                }
                int j;
                for( int i=besti+1,j=bestj+1 ; i<=bestj ; i++,j++){
                    s.seq_sommets[j] = s_.seq_sommets[i];
                }
                for( int i=bestk+1 ; i<s.getSize() ; i++,j++){
                    s.seq_sommets[j] = s_.seq_sommets[i];
                }*/

                int i;
                i = besti+1;
                for( int j=bestj+1 ; j<=bestk ; i++,j++){
                    s.seq_sommets[i] = s_.seq_sommets[j];
                }
                for( int j=besti+1 ; j<=bestj ; i++,j++){
                    s.seq_sommets[i] = s_.seq_sommets[j];
                }
                for( int j=bestk+1 ; j<s.getSize() ; i++,j++){
                    s.seq_sommets[i] = s_.seq_sommets[j];
                }
                

                break;

        case 2: 
                int i2;
                i2 = besti+1;
                for( int j=bestj+1 ; j<=bestk ; i2++,j++){
                    s.seq_sommets[i2] = s_.seq_sommets[j];
                }
                for( int j=bestj ; j>=besti+1 ; i2++,j--){
                    s.seq_sommets[i2] = s_.seq_sommets[j];
                }
                for( int j=bestk+1 ; j<s.getSize() ; i2++,j++){
                    s.seq_sommets[i2] = s_.seq_sommets[j];
                }

                break;

        case 3: 
                int i3;
                i3 = besti+1;
                for( int j=bestk ; j>=bestj+1 ; i3++,j--){
                    s.seq_sommets[i3] = s_.seq_sommets[j];
                }
                for( int j=besti+1 ; j<=bestj ; i3++,j++){
                    s.seq_sommets[i3] = s_.seq_sommets[j];
                }
                for( int j=bestk+1 ; j<s.getSize() ; i3++,j++){
                    s.seq_sommets[i3] = s_.seq_sommets[j];
                }

                break;
        
        case 4: 
                int i4;
                i4 = besti+1;
                for( int j=bestj ; j>=besti+1 ; i4++,j--){
                    s.seq_sommets[i4] = s_.seq_sommets[j];
                }
                for( int j=bestk ; j>=bestj+1 ; i4++,j--){
                    s.seq_sommets[i4] = s_.seq_sommets[j];
                }
                for( int j=bestk+1 ; j<s.getSize() ; i4++,j++){
                    s.seq_sommets[i4] = s_.seq_sommets[j];
                }
        
                break;
    }

    s.eval();

    return s.getVal();

}

#endif