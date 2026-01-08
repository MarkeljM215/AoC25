#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
struct Povezava {
    int drugi_clen;
    int prvi_clen;
    long long razdalja;



};


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
        std::vector<int> vrsta1;

        std::vector<std::vector<int>> vse;
        
    while (std::getline(input_file, line))
    { 
        vrsta1 = {};
        
                //splitanje stvari pri ,
    std::stringstream ss(line); 
	std::string range;
    char del = ',';
    int stevilka;
    int prazen = 0;
    //spraznem vektor


        while (getline(ss, range, del))
            {
              stevilka= std::stoi(range);
                vrsta1.push_back(stevilka); 
            }
            //shranim vector v matriko
            vse.push_back(vrsta1);


    }

//izračunam vse povezave in structe shranim v vektor
    std::vector<Povezava> seznam_povezav;

    for (int i = 0; i < vse.size(); i++)
    {
        for (int l = i+1; l < vse.size(); l++)
        {
            //računanje razdalje
            long long dx = vse[i][0] - vse[l][0];
            long long dy = vse[i][1] - vse[l][1];
            long long dz = vse[i][2] - vse[l][2];
            long long d2 = dx*dx + dy*dy + dz*dz;

            //struktura za struct
            Povezava nova;
            nova.prvi_clen = i;
            nova.drugi_clen = l;
            nova.razdalja = d2;

            //dodam v vektor
            seznam_povezav.push_back(nova);
        }
        
    }
    
    //presortiram glede na razdaljo
    std::sort(seznam_povezav.begin(), seznam_povezav.end(), [](const Povezava& a, const Povezava& b) {
    return a.razdalja < b.razdalja;
});
//naredimo zacetni vektor z niclami, ki ga nato spreminjamo
std::vector<int> skupina;
for (int n = 0; n < vse.size(); n++)
{
    skupina.push_back(n);
}

//nasatvimo povezave
int stevec_povezav = 0;
long long poz_1_clen;
long long poz_2_clen;
long long rezultat = 0;
//preverjamo kako so sedaj povezave narejen
for (int k = 0; k < seznam_povezav.size(); k++)
{
    //nastavimo kok je max povezav (part 2 nastaavim ko gledam izpis v terminalu ali je zmnozek 0;
    if (stevec_povezav == 5700)
    {
        long long x = vse[poz_1_clen][0];
        long long y = vse[poz_2_clen][0];
        rezultat = (x) *(y);
        std::cout << vse[poz_1_clen][0] << "    " << vse[poz_2_clen][0] << " njun zmnozek " << rezultat <<std::endl;
        
        break;
    }
    stevec_povezav = stevec_povezav +1;

    poz_1_clen = seznam_povezav[k].prvi_clen;
    poz_2_clen = seznam_povezav[k].drugi_clen;

    //pogledamo v vektor na te pozicije kok pise da je grupa
    int grupa1 = skupina[poz_1_clen];
    int grupa2 = skupina[poz_2_clen];

    if (grupa1 != grupa2)
    {
       
        
        //preverimo ce je se kje druga grupa da jo spremenimo v prvo
        for (int h = 0; h < skupina.size(); h++)
        {
            if (skupina[h]== grupa2)
            {
                skupina[h] = grupa1;
            }
            
        }

    }

}

//stetje povezav v vektorju
std::vector<int> maks_stevila;
int poz_max_num = 0;
poz_max_num = *max_element(skupina.begin(),skupina.end());
//naredim vektor poven nul
for (int o = 0; o < poz_max_num+1; o++)
{
    maks_stevila.push_back(0);    
}
//preberem stevilo v skupini in na isto mesto v mask stevila pristejem 1ko ce to stevilo sreečam
for (int m = 0; m < skupina.size(); m++)
{
    maks_stevila[skupina[m]] = maks_stevila[skupina[m]] +1;
}
//poiscem prva tri najvecja stevila in njihove indekse
int prvo_mesto = 0;
int drugo_mesto = 0;
int tretje_mesto = 0;

int pon1 =0;
int pon2 = 0;
int pon3 =0;
for (int j = 0; j < maks_stevila.size(); j++)
{
    //maks stevilo je veje od prvega člena zamenjam prvi člen in vse zamaknem navzdol
    if(maks_stevila[j]>= pon1)
    {
        //zamenjam tretje mesto mesto drugim
        pon3 = pon2;
        tretje_mesto = drugo_mesto;
        //zamenjam drugo mesto s prvim
        pon2 = pon1;
        drugo_mesto = prvo_mesto;
        //novo vrednost shranim v prvo mesto
        pon1 = maks_stevila[j];
        prvo_mesto = j;
    }
    //mamks stevilo je vecje od drugega člena
    else if (maks_stevila[j]>= pon2)
    {
        //zamenjam tretje mesto mesto drugim
        pon3 = pon2;
        tretje_mesto = drugo_mesto;
        //novo vrednost shranim v drugo mesto
        pon2 = maks_stevila[j];
        drugo_mesto = j;
    }
    //maks stevilo je vecje od trenutnega tretjega
        else if (maks_stevila[j]>= pon3)
    {
        //novo vrednost shranim v tretje mesto mesto
        pon3 = maks_stevila[j];
        tretje_mesto = j;

    }



}
//zmnozim dobljeno
int rezultat_max = 0;
rezultat_max = pon1 * pon2;
std::cout << "Tole je prvo mesto " << prvo_mesto << " in kolikokrat se ponovi " << pon1 << std::endl;
std::cout << "Tole je drugo mesto " << drugo_mesto << " in kolikokrat se ponovi " << pon2 << std::endl;
std::cout << "Tole je rezultat zmnozka ponovitev " << rezultat_max << std::endl;
std::cout << "Če rezultat zmnozkov ni nič povecaj stevilo ponovitev rocno v programu ! "<< std::endl;
  

return 0;

}