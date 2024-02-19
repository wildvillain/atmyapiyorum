#ifndef ATM_H
#define ATM_H
#include "banka.h"
#include <string>



class atm : public banka 
{
private:
std::string adres = "Kayseri mahallesi 8. sokak no: 87 Mamak/Ankara";
float atmicipara = 80000;
const int atmno = 1234;
const int atmmin = 2000;
const int atmmax = 500000;

public:
    bool paracekmebool ,parayatirmabool;
    
    int atmiciparadegisimi(int s){
        if (paracekmebool)
        {
            atmicipara = atmicipara - s;
            if (atmicipara<atmmin)
            {
                atmicipara = atmicipara  + s;
                std::cout<<"Islem yapilamadi! lutfen daha sonra tekrar deneyiniz!\n";
                return 0;
            }
            paracekmebool = 0;
            
        }
        else if (parayatirmabool)
        {
            atmicipara = atmicipara + s ;
            if (atmicipara>atmmax)
            {
                
                atmicipara = atmicipara - s;
                std::cout<<"Islem yapilamadi!\nLutfen daha sonra tekrar deneyiniz!\n";
                return 0;
            }   
            parayatirmabool = 0;
            

        }
        return atmicipara;

        std::cout<<std::endl<< atmicipara << std::endl;
    }

};

#endif
