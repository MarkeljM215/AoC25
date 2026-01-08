#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    // Branje datoteke 
    std::ifstream input_file("input.txt");

    if (!input_file)
    {
        std::cerr << "could not open file .\n";
        return 1;
    }

    std::string line;
    std::string crka;
    std::vector<int> seznam1;
    long long vsota = 0;
    long long stevilka1 = 0;

    while (std::getline(input_file, line))
    {
        seznam1 = {};
        // Zapisem vsako stevilko posebej v vector 
        for (int m = 0; m < line.size(); m++)
        {
            crka = line[m];
            int temp = std::stoi(crka);
            seznam1.push_back(temp);
        }

        // --- GREEDY ALGORITEM ---
        // 
        int ciljna_dolzina = 12;
        
        while (seznam1.size() > ciljna_dolzina) 
        {
            bool odstranjeno = false;
            
            // Gremo čez števke in iščemo prvo, ki je manjša od naslednje
            for (int i = 0; i < (int)seznam1.size() - 1; i++) 
            {
                if (seznam1[i] < seznam1[i + 1]) 
                {
                    seznam1.erase(seznam1.begin() + i);
                    odstranjeno = true;
                    break;
                }
            }

            // Če nobena števka ni bila manjša od desne (npr. 987654), 
            // odstranimo zadnjo, da zmanjšamo število.
            if (!odstranjeno) 
            {
                seznam1.pop_back();
            }
        }

        // Izracunamo stevilo iz vektorja 
        stevilka1 = 0;
        for (int l = 0; l < seznam1.size(); l++)
        {
            stevilka1 = stevilka1 * 10 + seznam1[l];
        }
        vsota = vsota + stevilka1;
    }

    std::cout << "Tole je vsota " << vsota << std::endl;
    input_file.close();
    return 0;
}