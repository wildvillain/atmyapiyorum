#ifndef KISISELHESAP_H
#define KISISELHESAP_H
#include "banka.h"
#include <string>



class kisiselhesap: public banka
{

public:
        int sifre,hspno;

       void hesapbakma(){
        sifre = kisisifre; 
        hspno = kisihesapno;
    }
     void hesapokuma(){
        std::cout<<"\n"<<kisiadi<<" bey  Hesap no:"<<kisihesapno<<" Hesap ici para miktari:"<<hesapicipara<<std::endl;
        
    }

};


#endif