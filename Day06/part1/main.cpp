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
        std::cerr << "coould not open file .\n";
    }
    

        //Branje beseda po beseda 
    std::string word;
    std::vector<long long> stevila;
    std::vector<char> znaki;
    std::vector<long long> umesno;
    char znak;
    long long stevilo;

    while (input_file >> word)
    {
       if (word == "+" || word == "*")
       {
        //vzamemem samo prvi člen stringa ki ma itak samo enga
        znak = word[0];
        znaki.push_back(znak);
       }
       else
       {
        //ostalo vržem v števila

        stevilo = std::stoll(word);
        stevila.push_back(stevilo);  
       }
    }


//računanje 
 long long rezultat = 0;
 long long rezultat_koncni= 0;


for (long long i = 0; i < (stevila.size()/4); i++)
{
    long long rezultat = 0;
    if(znaki[i] == '+')
    {
      rezultat = (stevila[i]) + (stevila[i+1000]) + (stevila[i+2000]) + (stevila[i+3000]);   
    }
    else
    {
      rezultat = (stevila[i]) * (stevila[i+1000]) * (stevila[i+2000]) * (stevila[i+3000]);
    }
    
    rezultat_koncni = rezultat_koncni + rezultat;


    
}


std::cout << "Rezultat  je: " << rezultat_koncni << std::endl;


return 0;

}