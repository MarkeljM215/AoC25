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
   // int vrsta_stevec;
        std::string line;
        std::vector<char> vrsta1;
        std::vector<char> fake_vrsta{
 '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
 '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
 '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
 '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
 '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
 '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
 '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
 '.','.'};
       // std::vector<char> fake_vrsta{'.','.','.','.','.','.','.','.','.','.','.','.'};
        std::vector<std::vector<char>> vse;
        char fake_znak = '.';
        vse.push_back(fake_vrsta);
    while (std::getline(input_file, line))
    {
        //vrsta_stevec = 0;    
        vrsta1 = {};
        vrsta1.push_back(fake_znak);
            for (int j = 0; j < line.size(); j++)
            {   

                vrsta1.push_back(line[j]);

            } 
        vrsta1.push_back(fake_znak);
 
        //shranim vrsto v matriko
        vse.push_back(vrsta1); 
        }
        //dodam eno fake vrsto
        
        vse.push_back(fake_vrsta);

        //izpis(pregled) celotne matrike;
        int vrednost;
        int rez;


int rezultat1 = 0;
for (int q = 0; q < 50; q++)
{
           for (int m = 1; m < vse.size()-1; m++)
        {
            for (int l = 1; l < vrsta1.size()-1; l++)
            {
                
                //m je vrstica v matriki
                //l je stolpec v matriki
                if (vse[m][l]== '@')
                    {
                    //8 polj
                    vrednost = 0;
                    //zograj levo
                    if (vse[m-1][l-1] == '.')
                    {
                        vrednost += 1;
                    }
                    //zgoraj sredina
                    if (vse[m][l-1] == '.')
                    {
                        vrednost += 1;
                    }
                    //zgoraj desno
                     if (vse[m+1][l-1] == '.')
                    {
                        vrednost += 1;
                    }
                    //sredina desno
                     if (vse[m+1][l] == '.')
                    {
                        vrednost += 1;
                    }
                    //sredina levo
                     if (vse[m-1][l] == '.')
                    {
                        vrednost += 1;
                    }
                    //spodaj levo
                     if (vse[m-1][l+1] == '.')
                    {
                        vrednost += 1;
                    }
                    //spodaj sredina
                     if (vse[m][l+1] == '.')
                    {
                        vrednost += 1;
                    }
                    //spodaj desno
                     if (vse[m+1][l+1] == '.')
                    {
                        vrednost += 1;
                    }
                    

                    if (vrednost > 4 )
                    {
                        vse[m][l] = '.';
                        
                        rezultat1 = rezultat1 +1;
                    }
                    
                    }
                
            }
        }
}


 







        //izpis matrike
        int rezultat = 0;
        for (int n = 0; n < vse.size(); n++)
        {
            for (int k = 0; k < vrsta1.size(); k++)
            {
                std::cout<<vse[n][k];
                if (vse[n][k] == 'X')
                {
                    rezultat += 1 ;
                }
                
            }
            std::cout <<std::endl;
        }
      
    std::cout<<"Tole je rezultat "<<rezultat1<<std::endl;
    


    
   input_file.close();
    return 0;
}