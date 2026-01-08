#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

// Uporabimo map za graf
typedef std::map<std::string, std::vector<std::string>> Graf;
//dam globalno spremenljivko da mi jo ne prepisuje in jo imajo vsi
int stetje_poti = 0;

void poisciVsePoti(std::string trenutna, 
                    std::string cilj, 
                    Graf graf, 
                    std::vector<std::string> pot) {
    
    // 1. Trenutno točko dodamo v svojo LOKALNO kopijo poti
    pot.push_back(trenutna);
    
    // preverimo če smo že tam
    if (trenutna == cilj) 
    {
        stetje_poti = stetje_poti + 1;
    } 
    else {
        // shranim glede na trenutno točko vse sosede od točke
        std::vector<std::string> sosedje = graf[trenutna];
        //s pomočjo zanke se od vsakega soseda sprehodim do konca, ko pridem na konec grem cez zgornji if pristejem 1
        //nato se vrnem in nadaljujem z nasledjim.
        for (int i = 0; i < sosedje.size(); i++) {
            poisciVsePoti(sosedje[i], cilj, graf, pot);
        }
    }

}

int main() {
    Graf graf;

    //vnasanje datoteke
    std::ifstream input_file("input.txt");

    //preverimo ce input fileo bstaja
    if (!input_file)
    {
        std::cerr << "could not open file .\n";
    }

        //branje datoteke
        std::string line;

       
 while (std::getline(input_file, line))
    {
        //splitanje stvari pri ,
    std::stringstream ss(line); 
	std::string range;
    std::string trenutni_kljuc;
    char del = ' ';
    //spraznem vektor
    int temp = 0;

        while (getline(ss, range, del))
            {
                //preberem prvi člen in ga shranim kot kljuc ter odstranim :
              if(temp == 0)
             {
                range.pop_back();
                temp = 1;
                trenutni_kljuc = range;
             }
             //ostale člene dodam kot člene pod trenutni ključ
             else
             {
              graf[trenutni_kljuc].push_back(range); 
             }
            }


    }
    // Začnemo s praznim vektorjem
    std::vector<std::string> zacetnaPot;
    
    poisciVsePoti("you", "out", graf, zacetnaPot);
    std::cout <<"Najdeno stevilo poti "<< stetje_poti<<std::endl;
    return 0;
}