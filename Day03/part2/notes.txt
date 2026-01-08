#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
        //vnasanje datoteke
    std::ifstream input_file("input.txt");

    //preverimo ce input fileo bstaja
    if (!input_file)
    {
        std::cerr << "could not open file .\n";
    }

     //branje datoteke
        std::string line;
        std::string crka;
        std::vector<int> seznam1;
        std::vector<int> seznam2;
        std::vector<int> seznam3;
        int temp;
        long long vsota= 0;
        long long stevilka1 = 0;

    while (std::getline(input_file, line))
    {
        seznam1 = {};
        //zapisem vsako stevilko posebej v vector
    for (int m = 0; m < line.size(); m++)
     {
        crka = line[m];
        temp = std::stoi(crka);
        seznam1.push_back(temp);    
     }

//DDOANO


//zmanjsujem vector dokler ni velikosti 11 clenov
for (int i = seznam1.size(); i> 12 ; i--)
{
    

     //izberem 1 najvecje vector ce odstranim 1 člen
     int once = 0;
    //ponastavim vrednosti na zacetku zanke
    seznam2 = seznam1;
    seznam3 = seznam1;
     for (int j = 0; j < seznam1.size(); j++)
     {
        //prvic izvedem da dobim prvo primerjalno stevilo
        if (once == 0)
        {
            seznam1.erase(seznam1.begin());
            once = 1;
        }
        //dam nazaj osnovnos stanje da lahko zbrisem eno drugio cifo 
        seznam2 = seznam3;
        //odstranim eno stevilko
       seznam2.erase(seznam2.begin() + j);
        
        //preverim velikost stevilke
        for (int k = 0; k < seznam2.size(); k++)
        {
        if(seznam2[k]<seznam1[k])
        {
          break;  
        }
        else if (seznam2[k] > seznam1[k])
         {
             seznam1 = seznam2;
         }
        
        }
    }


} 

//izracunam stevilo iz vektorja in jih seštejem
stevilka1 = 0;
for (int l = 0; l < seznam1.size(); l++)
{
    stevilka1 = stevilka1 * 10 +seznam1[l]; 
}
//std::cout<<stevilka1<<std::endl;
vsota = vsota + stevilka1;

             
        }
           


std::cout<<"Tole je vsota "<<vsota<<std::endl;
input_file.close();
    return 0;
}