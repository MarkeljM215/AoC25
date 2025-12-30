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
    std::string line;
    std::vector <std::string> besedilo;
    char presledek = ' ';

    

    while (getline(input_file,line))
    {

    
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i]== presledek)
        {
            line[i] = '_';
        }   
    }
    //Dodam nakonc se dodate da deluje
    line = line += "_";
    //linijo doam v vektor besedilo
    besedilo.push_back(line);

    }

//določimo še znake
std::vector<char> znaki;
std::string linija_znakov = besedilo[4];
for (long long i = 0; i < linija_znakov.size(); i++)
{

    if (linija_znakov[i] == '*')
    {
        znaki.push_back('*');
    }
    if (linija_znakov[i] == '+')
    {
        znaki.push_back('+');
    }
    
}



//računanje 
  long long rezultat = 0;
  long long rezultat_koncni= 0;


std::string vrstica1 = besedilo[0];
std::string vrstica2 = besedilo[1];
std::string vrstica3 = besedilo[2];
std::string vrstica4 = besedilo[3];





//sestavljanje stevil po stolpcih
std::vector<std::string> stevila;
std::string stevilka;

for (long long i = 0; i < vrstica1.size(); i++)
{
    stevilka.clear();
    stevilka += vrstica1[i];
    stevilka += vrstica2[i];
    stevilka += vrstica3[i];
    stevilka += vrstica4[i];

    stevila.push_back(stevilka);

}
//seštevanje
long long stevilka_znaka = 0;
std::vector<long long> operacija {};
std::vector<long long> operacija1 {};
long long rezultat_vmesni =0;

for (long long  i = 0; i < stevila.size(); i++)
{
    if (stevila[i] != "____")
    {
        //najprej odsranim kar ni stevilka
        std::string s = stevila[i];
        long long s_as_number;
        s.erase(std::remove(s.begin(), s.end(), '_'), s.end());
        //pretvorim v številko
        s_as_number = std::stoi(s);
        //shranim v vektor
        operacija.push_back(s_as_number);
    }
    else
    {
        //konec stevil
        rezultat_vmesni = 0;
        //glede na znak seštejem zmozim
        if (znaki[stevilka_znaka] == '+')
        {
            for (int k = 0; k < operacija.size(); k++)
            {
                rezultat_vmesni = operacija[k] + rezultat_vmesni;
            } 
        }
        else
        {
            rezultat_vmesni = 1;
            for (int l = 0; l < operacija.size(); l++)
            {
                rezultat_vmesni = operacija[l] * rezultat_vmesni;
            } 
        }
        rezultat_koncni = rezultat_vmesni + rezultat_koncni;
        stevilka_znaka = stevilka_znaka + 1;
        //pobrisem operacija
        operacija1 = operacija;
        operacija = {};


    }

}


std::cout << "Rezultat  je: " << rezultat_koncni << std::endl;


return 0;

}