
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "color.hpp" //imports cool hpp file i found that lets you change the colour of the terminal text || uses "" cause its looking in local directory https://github.com/aafulei/color-console


int main(){

    std::cout<<"Welcome to the game\n\nenter your Name:";
    std::string name = "";
    std::cin>> name;
    

    bool cashout = false;
    int startCredits = 30;
    int credits = startCredits;
    int cost = 1;
    //tracking stats
    int nothing = 0;
    int match2 = 0;
    int match3 = 0;

    while (cashout == false && credits>0){

        std::cout<<"Current Credits: "<<credits<<"\nEntry Cost: 1 Credit\n\nProceed? (y/n)\n";
        std::string cont;
        std::cin>>cont;
        if (cont == "y"){//maybe needs to be .equls or smth
            //ACTUAL SLOT CODE
            int num1 = rand() % 10;
            int num2 = rand() % 10;
            int num3 = rand() % 10;
            credits = credits- cost;

            std::cout<<"\n\nResults :O \n"<<std::setw(10)<<dye::aqua(num1)<<std::setw(10)<<dye::aqua(num2)<<std::setw(10)<<dye::aqua(num3)<<"\n";

            if (( num1==num2) && (num2==num3)){

                std::cout<<dye::green("\nMAXX WIN! 100x :D\n");
                credits += (cost*100);
                match3 += 1;

            }else if((num1==num2 && num2!=num3)||(num1!=num2 && num2==num3)){

                std::cout<<dye::yellow("\nNice Match! 5x :)\n");
                credits = credits+ cost*5;
                match2 += 1;

            }else{

                std::cout<<dye::red("\nNo win -1 coin :C\n");
                nothing += 1;

            }



        }else if(cont == "n"){
            cashout = true;
            std::cout<<"Final Credits: "<<credits<<"\n Your stats:\n"<<dye::red("0 Matches: ")<<nothing<<dye::yellow("   2 Match: ")<<match2<<dye::green("   3 Match: ")<<match3<<"\n";

            if (credits > startCredits){

                std::cout<<(startCredits-credits)<<" profit!";

            }else if ( credits > 0 && credits<startCredits){

                std::cout<<credits<<" credits remain. Leaving the tables with something atleast hehe!";

                break;


            }else{

                std::cout<<"LOOOOOOOOOOL YOU LOSE AXXAXAX";

            }

        }else{
            std::cout<<"Please select either the y or n key :c";

        }



    }

    if (credits<1){

        std::cout<<"Credits: "<<credits<<"\n\nUh oh, Brokie! eheheh";
        std::cout<<"Final Credits: "<<credits<<"\n Your stats:\n"<<dye::red("0 Matches: ")<<nothing<<dye::yellow("   2 Match: ")<<match2<<dye::green("   3 Match: ")<<match3<<"\n";

    }

    return 0;
}