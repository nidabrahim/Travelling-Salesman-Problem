#include "Data.cpp"

/**
 * 
 *  NIDABRAHIM YOUSSEF
 *  F2 - G12
 * 
 * **/


class Solution{
    
    Data * data;
    float val;

    public: 
        std::vector<int> seq_sommets;
        Solution(std::string);
        void init();
        int addSequence(int);
        int getSize() const;
        void afficher();
        void eval();
        float eval(int, int) const;
        float detour(int, int) const;
        float getVal() const;
        float getVal();
};

Solution::Solution(std::string filename){
    data = new Data(filename);
    //std::cout << *data;
    init();
    eval();
}

void Solution::init(){
    int x = (int) rand() % data->getSize();
    seq_sommets.push_back(x);
    do{
        x = addSequence(x);
    }while(seq_sommets.size() != data->getSize());
}

int Solution::addSequence(int ind_top_seq){

    int minDetour = 10000, ind_candidat;
    for(int i = 0 ; i < data->getSize() ; i++ ){
        int h = 0;
        while(h < seq_sommets.size() && seq_sommets[h] != i+1 ) h++;

        if( h == seq_sommets.size() ){
            int detour = data->detour(ind_top_seq,i+1);
            if(detour < minDetour){
                minDetour = detour;
                ind_candidat = i+1;
            }
        }
    }
    seq_sommets.push_back(ind_candidat);
    return ind_candidat;
}

 int Solution::getSize() const {
    return seq_sommets.size();
 }

void Solution::afficher(){
    std::cout << "\nSequence : ";
    for(int i=0 ; i<seq_sommets.size() ; i++ ){
        std::cout << seq_sommets[i] << " ";
    }
}

void Solution::eval() {
    int i = 0;
    this->val = 0;
    for( i=0 ; i<seq_sommets.size()-1 ; i++ ){
        this->val += data->detour(seq_sommets[i] , seq_sommets[i+1]);
    }
    if(i == seq_sommets.size()-1) this->val += data->detour(seq_sommets[i] , seq_sommets[0]);
}

float Solution::eval(int a, int b) const {
    float det = 0;
    for(int i=a ; i<b ; i++ ){
        det += data->detour(seq_sommets[i] , seq_sommets[i+1]);
    }
    return det;
}


float Solution::detour(int i, int j) const {
    
    return data->detour(i,j);
}

float Solution::getVal() const {
    return this->val;
}

float Solution::getVal() {
    return this->val;
}
