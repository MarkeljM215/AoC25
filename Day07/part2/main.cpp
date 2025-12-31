#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
        std::vector<char> vrsta1;

        std::vector<std::vector<char>> vse;
        
    while (std::getline(input_file, line))
    {
        //vrsta_stevec = 0;    
        vrsta1 = {};
        
            for (int j = 0; j < line.size(); j++)
            {   

                vrsta1.push_back(line[j]);

            } 
       
        //shranim vrsto v matriko
        vse.push_back(vrsta1); 
        }
        
        //izpis(pregled) celotne matrike;
        int vrednost = 0;
        int rez;

        //enako kot part 1 samo splitanje dela
        for (int m = 1; m < vse.size(); m++)
        {
            for (int l = 0; l < vrsta1.size(); l++)
            {
                
                //m je vrstica v matriki
                //l je stolpec v matriki
                //zacetni pogoj
                if (vse[m-1][l]== 'S')
                    {
                    vse[m][l] = '|';
  
                    }
                //pogoj 1 spliting
                if (vse[m][l]== '^' && vse[m-1][l] =='|')
                {
                    //edn prej
                    vse[m][l-1] = '|';
                    //edn kasnej
                    vse[m][l+1] = '|';
                    //štejem kolikokrat naredim tale korak
                    vrednost = vrednost + 1;
                }
                //pogoj dve podaljševanje
                if (vse[m][l] == '.' && vse[m-1][l] == '|')
                {
                    vse[m][l] = '|';
                }
                
            }
        }

//kreiram nadomestno kopijo matrike, kateri ima števila namesto karakterjev
long long vrstice = vse.size();
long long stolpci = vse[0].size();
std::vector<std::vector<long long>> matrika(vrstice, std::vector<long long>(stolpci, 0));



//v spodnjo vrstico zakodiram začetno vrednost ;

for (int h = 0; h < vrsta1.size(); h++)
{
    if (vse[vse.size()-3][h]== '|'&& vse[vse.size()-2][h] =='^')
    {
        vse[vse.size()-3][h] = '2';
        matrika[vse.size()-3][h] = 2;
    }
    if (vse[vse.size()-3][h]== '|'&& vse[vse.size()-2][h] =='|')
    {
        vse[vse.size()-3][h] = '1';
        matrika[vse.size()-3][h] = 1;
    }
    
}



//grem sppodaj gor po algoritmu od vrabica
for (int o = vse.size()-5; o > 0; o = o - 2)
{
    for (int p = 0; p < vse.size(); p++)
    {
        //o je vrstica v matrii
        //p je stolpec v matriki
        //spodaj spliter iz te tocke sta vn dve poti
        if (vse[o][p] == '|' && vse[o+1][p] =='^')
        {
            matrika[o][p] = (matrika[o+2][p-1]+matrika[o+2][p+1]);
        }
        //spodaj crta iz te tocke je samo ena pot
        if (vse[o][p] == '|' && vse[o+1][p] =='|')
        {
            matrika[o][p] =(matrika[o+2][p]) ;
        }

    }
    
}
     
            
//izpis stevila
        for (int n = 0; n < vse[0].size(); n++)
        {
            int k = 1;
            if(matrika[k][n] != 0)
            {
                std::cout<<matrika[k][n];
                std::cout <<std::endl;
                
            }
            
        }


    
   input_file.close();
    return 0;
}