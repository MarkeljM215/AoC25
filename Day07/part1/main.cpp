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



        //izpis matrike
        
        for (int n = 0; n < vse.size(); n++)
        {
            for (int k = 0; k < vrsta1.size(); k++)
            {
                std::cout<<vse[n][k];
                
            }
            std::cout <<std::endl;
        }
      
    std::cout<<"Tole je rezultat "<<vrednost<<std::endl;
    


    
   input_file.close();
    return 0;
}