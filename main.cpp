#include "Movement.cpp"
#include <time.h>
#include <string.h>

/**
 * 
 *  NIDABRAHIM YOUSSEF
 *  F2 - G12
 * 
 * **/

bool vnd(Solution & S){
    bool stop, ameliore = false;
    Shift * sh = new Shift();
    Swap * swap = new Swap();
    do{
        stop = false;
        if(sh->scan(S)){ 
            sh->commit(S);
            ameliore = true;
        }
        else{
            if(swap->scan(S)){
                swap->commit(S);
                ameliore = true;
            }
            else{
                Opt2 * opt2 = new Opt2();
                if(opt2->scan(S)){
                    opt2->commit(S);
                    ameliore = true;
                }
                else{
                    Opt3 * opt3 = new Opt3();
                    if(opt3->scan(S)){
                        opt3->commit(S);
                        ameliore = true;
                    } 
                    else stop = true;
                }
            } 
        }

    }while(stop == false);

    return ameliore;
}


int main(int ,char** argv){

    double temps = 0;
    clock_t start;

    std::string filename = "INSTANCES/" + std::string(argv[1]);

 /* CONSTRUCTION *******************************************************/
    std::cout << "\nConstruction : ";
    start = clock();
    Solution * sol = new Solution(filename);
    temps = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
    sol->afficher();
    std::cout << "\nCout : " << sol->getVal() << std::endl;
    printf("Recherche terminee en %.2f seconde(s)!\n", temps);

/**********************************************************************/

std::cout << "\nAmelioration : ";

 /* SWAP *************************************************************/
/*    std::cout << "\nSwap : "<< std::endl;
    Solution * solswap = new Solution(filename);
    Swap * swap = new Swap();
    start = clock();
    if(swap->scan(*solswap)){
        swap->commit(*solswap);
        temps = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
        solswap->afficher();
        std::cout << "\nCout : " << solswap->getVal() << std::endl;
        printf("Recherche terminee en %.2f seconde(s)!\n", temps);

    }
*/
/**********************************************************************/

 /* SHIFT *************************************************************/
/*    std::cout << "\nShift : "<< std::endl;
    Solution * solshift = new Solution(filename);
    Shift * shift = new Shift();
    start = clock();
    if(shift->scan(*solshift)){
        shift->commit(*solshift);
        temps = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
        solshift->afficher();
        std::cout << "\nCout : " << solshift->getVal() << std::endl;
        printf("Recherche terminee en %.2f seconde(s)!\n", temps);

    }
*/
/**********************************************************************/

/* 2-OPT *************************************************************/
/*    std::cout << "\n2-opt : "<< std::endl;
    Solution * solopt2 = new Solution(filename);
    Opt2 * opt2 = new Opt2();
    start = clock();
    if(opt2->scan(*solopt2)){
        opt2->commit(*solopt2);
        temps = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
        solopt2->afficher();
        std::cout << "\nCout : " << solopt2->getVal() << std::endl;
        printf("Recherche terminee en %.2f seconde(s)!\n", temps);

    }
*/
/**********************************************************************/

/* 3-OPT *************************************************************/
/*    std::cout << "\n3-opt : "<< std::endl;
    Solution * solopt3 = new Solution(filename);
    Opt3 * opt3 = new Opt3();
    start = clock();
    if(opt3->scan(*solopt3)){
        opt3->commit(*solopt3);
        temps = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
        solopt3->afficher();
        std::cout << "\nCout : " << solopt3->getVal() << std::endl;
        printf("Recherche terminee en %.2f seconde(s)!\n", temps);

    }
*/
/**********************************************************************/

/* HEURISTIQUE HYBRIDE ************************************************/
    std::cout << "\nHeuristique Hybride : "<< std::endl;
    start = clock();
    if(vnd(*sol)){
        temps = (double)(clock()-start)/(double)CLOCKS_PER_SEC;
        std::cout << "\nResultat : ";
        sol->afficher();
        std::cout << "\nCout : " << sol->getVal() << std::endl;
        printf("Recherche terminee en %.2f seconde(s)!\n", temps);
    }

/**********************************************************************/


    return 0;
}