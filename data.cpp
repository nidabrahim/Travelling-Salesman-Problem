#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>

/**
 * 
 *  NIDABRAHIM YOUSSEF
 *  F2 - G12
 * 
 * **/


#define MAX_NODE 300 

class Data{

    float mat[MAX_NODE][3];
    int n,m;

    public:
        Data(const std::string &);
        float* operator()(int);
        int getSize();
        float detour(int, int);
        friend std::ostream& operator<<(std::ostream&, Data );
};

Data::Data(const std::string & filename){

    int continu, i;
    float id, x ,y;
    std::string cline, line;
    char s1[50], s2[50], s3[50];
    std::ifstream is;
    is.open(filename.c_str());

    m = 3;

    if(is.fail()){
        std::cerr << "Error : enable to open" << std::endl;
        exit(1);
    }

    /*for(int i=0; i<6; i++){
        getline(is, line);
        sscanf(line.c_str(), "%s %s", s1, s2);
        if( s1[0] == 'D' ){
             n = (int) atoi(s2);
        }  
        std::cout << s1 << " "<< s2 << std::endl;
    }
    getline(is, line);getline(is, line);
    std::cout << line << "\n" << std::endl;*/
    
    do{
        getline(is, line);
    }while(line != "NODE_COORD_SECTION");

    i = 0;
    continu = 1;
    do{
        getline(is, cline);
        if(cline == "EOF" ) continu = 0;
        else{
                sscanf(cline.c_str(), "%f %f %f", &id, &x, &y);
                mat[i][0] = id;
                mat[i][1] = x;
                mat[i][2] = y;
                i++;
        }
    }while(continu == 1);
    n = i--;
}

int Data::getSize(){
    return this->n;
}

float* Data::operator()(int i){

    return mat[i];
}

float Data::detour(int i, int j){
    
    return std::sqrt( std::pow(mat[i][1] - mat[j][1],2) + std::pow(mat[i][2] - mat[j][2],2) );
}

std::ostream& operator<<(std::ostream& o, Data data){

    std::cout << "Nomdre du sommet : " << data.getSize() << std::endl;
    for(int i = 0; i<data.getSize(); i++){
    
        o << "( " << data(i)[0] << " , " << data(i)[1] << " , " << data(i)[2] << " )"<< std::endl;
    }
}
