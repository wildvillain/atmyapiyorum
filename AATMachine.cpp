#include <iostream>
#include <string>
#include "banka.h"
#include "atm.h"
#include "kisiselhesap.h"
#include "kisi.h"
#include "fonksiyonlar.h"

#define MAX_KISI_SAYISI 8




int main(){

    
    kisi kisiler[MAX_KISI_SAYISI] = { {ad , email, numara } , {ad2 , email2, numara2},{ad3 , email3, numara3},{ad4 , email4, numara4}, 
    {ad5 , email5, numara5}, {ad6 , email6, numara6},{ad7 , email7, numara7},{ad8 , email8, numara8} };
    
    //class'lar için objelerin oluşturulduğu kısım
    
    atm atm;
    banka banka;
    kisiselhesap kisiselhesap[MAX_KISI_SAYISI];// std::cout<<kisiler[0].kisiadi<<"\n";

    //Hesapların açıldığı kısım
    kisiselhesap[0].hesapacma(kisiler[0].kisiadi,kisiler[0].kisiemail,kisiler[0].kisitel,5056,5056,1800.85);
    kisiselhesap[1].hesapacma(kisiler[1].kisiadi,kisiler[1].kisiemail,kisiler[1].kisitel,6056,6056,1849.85);
    kisiselhesap[2].hesapacma(kisiler[2].kisiadi,kisiler[2].kisiemail,kisiler[2].kisitel,7056,7056,16198.85);
    kisiselhesap[3].hesapacma(kisiler[3].kisiadi,kisiler[3].kisiemail,kisiler[3].kisitel,8056,8056,52.85);
    kisiselhesap[4].hesapacma(kisiler[4].kisiadi,kisiler[4].kisiemail,kisiler[4].kisitel,9056,9056,619.85);
    kisiselhesap[5].hesapacma(kisiler[5].kisiadi,kisiler[5].kisiemail,kisiler[5].kisitel,1056,1056,9159.85);
    kisiselhesap[6].hesapacma(kisiler[6].kisiadi,kisiler[6].kisiemail,kisiler[6].kisitel,2056,2056,400891.85);
    kisiselhesap[7].hesapacma(kisiler[7].kisiadi,kisiler[7].kisiemail,kisiler[7].kisitel,3056,3056,19802.85);
    
    //hesap şifre girip hesabı bulduğumuz kısım
    
    int hspno ,sifre ;  
    std::cout<<"\nHesap no gir: ";
    std::cin>>hspno;
    std::cout<<"\nSifre gir: ";
    std::cin>>sifre;  
    int count = 1, hangikisi = 0;
    for (int i = 0; i < MAX_KISI_SAYISI; i++)
    {
        kisiselhesap[i].hesapbakma();
        

        if (hspno == kisiselhesap[i].hspno && sifre == kisiselhesap[i].sifre)
        {   
            kisiselhesap[i].hesapokuma();
            break;
        }
        else if (count == MAX_KISI_SAYISI)
        {
            count = 1;
            std::cout<<"Boyle bir hesap bulunmamaktadir!\n";
            hangikisi = 0;
            return 0;
        }
        
        count++;
        hangikisi++;
    }

    int islem =0;


    while (islem != 4)
    {
    std::cout<<"Islem seciniz: \n1. Para cekme \n2. Para yatirma \n3. Sifre degisme \n4. Cikis \nSecilen islem : ";
    std::cin>>islem;
    int yatirma =0;
    int cekme =0;
    int x ;
    

        switch (islem)
        {
        case 1:
            
            std::cout<<"\nNe kadar para cekmek istiyorsunuz: ";
            std::cin>>cekme;
            kisiselhesap[hangikisi].paracekme(cekme);
            atm.paracekmebool = 1;
            x = atm.atmiciparadegisimi(cekme);
            if (x == 0)
            {
                kisiselhesap[hangikisi].parayatirma(cekme);            
            }
            kisiselhesap[hangikisi].hesapokuma();
            std::cout<<"Baska bir islem yapmak ister misiniz?\n1. Evet \n2. Hayir: ";
            std::cin>>islem;
            if (islem == 2)
            {
                std::cout<<"......Cikis yapiliyorr......\nCikis Yapildi. Iyi gunler dileriz.";
                return 0;
            };
            break;
        case 2:
            
            std::cout<<"\nNe kadar para yatirmak istiyorsunuz: ";
            std::cin>>yatirma;
            kisiselhesap[hangikisi].parayatirma(yatirma);
            atm.parayatirmabool = 1;
            x = atm.atmiciparadegisimi(yatirma);
            if (x == 0)
            {
                kisiselhesap[hangikisi].paracekme(yatirma);            
            }
            
        
            // kisiselhesap[hangikisi].hesapicipara = kisiselhesap[hangikisi].hesapicipara - 100000
            
            kisiselhesap[hangikisi].hesapokuma();
            std::cout<<"Baska bir islem yapmak ister misiniz?\n1. Evet \n2. Hayir: ";
            std::cin>>islem;
            if (islem == 2)
            {   
                std::cout<<"......Cikis yapiliyorr......\nCikis Yapildi. Iyi gunler dileriz.";
                return 0;
            };
            break;
        case 3:
            int yenisifre;
            std::cout<<"lutfen yeni sifreyi girin : ";
            std::cin>>yenisifre;
            kisiselhesap[hangikisi].sifredegisme(yenisifre);
            return 0;
            break;
        case 4:
            std::cout<<"Cikis yapildi";
            break;
        default:
        std::cout<<"\n****************Invalid Num*****************\n****************Syntax ErroR****************\n*****Lutfen gecerli bir islem seciniz!!*****\n";
            break;
        }

    }


    return 0;
}

