#include <iostream>
#include "banka.h"
#include "atm.h"
#include "kisiselhesap.h"
#include "kisi.h"
#include "fonksiyonlar.h"

#define MAX_KISI_SAYISI 8


int main(){
    //objeolusturma();
    
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
    
    //Hesap şifre girip hesabı bulduğumuz kısım
    bool sayimi;
    int length = 0,length1 = 0;
    std::string hspno1,sifre1,str;
    int hspno,sifre;
    int dogrulama = 0,dogrulama1 = 0 ;
    std::cout<<"\nHesap no gir: ";
    std::cin>>hspno1;
    length = hspno1.length();
    for (char c : hspno1)
    {
         if (!std::isdigit(c))
    {
        sayimi = false;
        break;
    }
    else
    {
        sayimi = true;
    }
    }
    if (sayimi)
    {
        
        hspno = stoi(hspno1);
        str = std::to_string(hspno); 
        length1 = str.length();
    }

    
    
    if (length1 == length)
    {
        dogrulama = 1;
    }
    else
    {
        dogrulama = 0;
    }
    
    std::cout<<"\nSifre gir: ";
    std::cin>>sifre1;
    length = sifre1.length();
    
    for (char c : sifre1)
    {
         if (!std::isdigit(c))
    {
        sayimi = false;
        break;
    }
    else
    {
        sayimi = true;
    }
    }
    if (sayimi)
    {
        
        sifre = stoi(sifre1);
        str = std::to_string(sifre);  
        length1 = str.length();
    }
    if (length1 == length)
    {
        dogrulama1 = 1;
    }
    else
    {
        dogrulama1 = 0;
    }





    
    if (dogrulama1 && dogrulama || !dogrulama1&&dogrulama)
    {
        

        int count = 1, hangikisi = 0,sifresayac = 0;
        for (int i = 0; i < MAX_KISI_SAYISI; i++)
        {
            
            kisiselhesap[i].hesapbakma();
            if (hspno == kisiselhesap[i].hspno  )
            {   

                
                if (sifre == kisiselhesap[i].sifre)
                {
                    kisiselhesap[i].hesapokuma();
                    break;
                }
                else
                {
                    
                    std::cout<<"\nSifreniz yanlis! Tekrar sifre giriniz : ";
                    sifresayac++;
                    if (sifresayac != 3)
                    {
                        std::cin>>sifre1;
                        length = sifre1.length();
                                    for (char c : sifre1)
                                    {
                                        if (!std::isdigit(c))
                                    {
                                        sayimi = false;
                                        break;
                                    }
                                    else
                                    {
                                        sayimi = true;
                                    }
                                    }
                                    if (sayimi)
                                    {
                                        
                                        sifre = stoi(sifre1);
                                        str = std::to_string(sifre);  
                                        length1 = str.length();
                                    }
                        
                        
                        if (length1 == length && sifre == kisiselhesap[i].sifre)
                        {   
                            kisiselhesap[i].hesapokuma();
                            break;
                        }
                        else
                        {
                            std::cout<<"Sifreyi 2 kez yanlis girdiniz hesap bloklandi!";
                            return 0;

                        }
                    }
                    
                }
                
                
                
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





        std::string islem1;
        int islem = 0;


        while (islem != 4)
            {

                int kont = 0;


                
                std::cout<<"Islem seciniz: \n1. Para cekme \n2. Para yatirma \n3. Sifre degisme \n4. Cikis \nSecilen islem : ";
                std::cin>>islem1;
                length = islem1.length();
                for (char c : islem1)
                {
                    if (!std::isdigit(c))
                    {
                        sayimi = false;
                        break;
                    }
                    else {sayimi = true;}
                    }
                if (sayimi)
                {
                    islem = stoi(islem1);
                    str = std::to_string(islem);
                    length1 = str.length();
                }
                
                
                if (length1 == length)
                {
                    std::string yatirma1,cekme1,cikisistegi1,x1,yenisifre1,yenisifre2;
                    int x,cikisistegi,cekme,yatirma,yenisifre,yenisifre3;

                        if (islem == 1)
                        {
                            std::cout<<"\nNe kadar para cekmek istiyorsunuz: ";
                            std::cin>>cekme1;
                            length = cekme1.length();
                            for (char c : cekme1)
                            {
                                if (!std::isdigit(c)) {sayimi = false;}
                                else{ sayimi=true;}
                                
                            }
                            if (sayimi)
                            {
                                cekme =  stoi(cekme1);
                                str = std::to_string(cekme);
                                length1 = str.length();
                            }
                            
                            
                            
                            if (length1 == length)
                            {
                                kisiselhesap[hangikisi].paracekme(cekme);
                                atm.paracekmebool = 1;
                                x = atm.atmiciparadegisimi(cekme);
                                if (x == 0)
                            {
                                kisiselhesap[hangikisi].parayatirma(cekme);            
                            }
                            kisiselhesap[hangikisi].hesapokuma();
                            std::cout<<"Baska bir islem yapmak ister misiniz?\n1. Evet \n2. Hayir: ";
                            std::cin>>cikisistegi1;
                            length1 = cikisistegi1.length();
                            for (char c : cikisistegi1)
                            {
                                if (!std::isdigit(c))
                                {
                                    sayimi = false;
                                    break;
                                }
                                else{sayimi = true;}
                            }
                            if (sayimi)
                            {
                                cikisistegi = stoi(cikisistegi1);
                                str  = std::to_string(cikisistegi);
                                length1 = str.length();
                            }
                            else
                            {
                                std::cout<<"Yanlis deger girdiniz. Ana menuye yonlendirildiniz.\n";
                            }
                            



                            
                            if (length1 = length)
                            {
                                if (cikisistegi == 2)
                            {
                                std::cout<<"......Cikis yapiliyorr......\nCikis Yapildi. Iyi gunler dileriz.";
                                return 0;
                            }
                            }
                            else
                            {
                                std::cout<<"Yanlis deger girdiniz. Ana menuye yonlendirildiniz.";
                            }
                            
                            }
                            else
                            {
                                std::cout<<"Yanlis deger girdiniz. Ana menuye yonlendirildiniz.";
                            }
                            
                            
                            
                            ;
                        }
                        else if (islem == 2)
                        {
                            std::cout<<"\nNe kadar para yatirmak istiyorsunuz: ";
                            std::cin>>yatirma1;
                            length = yatirma1.length();
                            for (char c : yatirma1)
                            {
                                if(!std::isdigit(c)){sayimi = false;break;}
                                else{sayimi = true;}
                            }
                            if (sayimi)
                            {
                                 yatirma = stoi(yatirma1);
                                str = std::to_string(yatirma);
                                length1 = str.length();
                            }
                            
                           
                            if (length1 == length)
                            {
                                
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
                            std::cin>>cikisistegi1;
                            length1 = cikisistegi1.length();
                            for (char c : cikisistegi1)
                            {
                                if (!std::isdigit(c))
                                {
                                    sayimi = false;
                                    break;
                                }
                                else{sayimi = true;}
                            }
                            if (sayimi)
                            {
                                cikisistegi = stoi(cikisistegi1);
                                str  = std::to_string(cikisistegi);
                                length1 = str.length();
                            }
                            else
                            {
                                std::cout<<"Yanlis deger girdiniz. Ana menuye yonlendirildiniz.\n";
                            }
                            if (length1 = length)
                            {
                                if (cikisistegi == 2)
                            {
                                std::cout<<"......Cikis yapiliyorr......\nCikis Yapildi. Iyi gunler dileriz.";
                                return 0;
                            }
                            }
                            else
                            {
                                std::cout<<"Yanlis deger girdiniz. Ana menuye yonlendirildiniz.";
                            }
                            
                            }
                            else
                            {
                                std::cout<<"Yanlis deger girdiniz. Ana menuye yonlendirildiniz.";
                            }
                        
                            
                            



                            ;
                        }
                        else if (islem == 3)
                        {
                            
                            std::cout<<"lutfen yeni sifreyi girin : ";
                            std::cin>>yenisifre1;
                            length = yenisifre1.length();
                            for (char c : yenisifre1)
                            {
                                if(!std::isdigit(c)){sayimi = false;break;}
                                else { sayimi = true;}
                            }
                            if (sayimi)
                            {
                                yenisifre = stoi(yenisifre1);
                                str =  std::to_string(yenisifre);
                                length1 = str.length();
                            }
                            


                            


                            if (length1 == length)
                            {  
                            kisiselhesap[hangikisi].sifredegisme(yenisifre);   
                            }
                            else
                            {

                            std::cout<<"Sifreniz degistirilememistir! Invalid deger girdiniz.\n";
                            }
                            if (kont)
                            {
                                return 0;
                            }
                            else
                            {
                                std::cout<<"Ana menuye yonlendirildiniz!\n";
                            }
                            
                            
                            
                        }
                        else if (islem == 4)
                        {
                            std::cout<<"Cikis yapildi";
                        }
                        else
                        {
                            std::cout<<"\n****************Invalid Num*****************\n****************Syntax ErroR****************\n*****Lutfen gecerli bir islem seciniz!!*****\n";
                        }

                }
                else
                {
                    std::cout<<"Duzgun bir islem secin lutfen!!";
                }
                
                

            
                
                        
            }

        }

        else if (!dogrulama)
        {
            std::cout<<"Boyle bir hesap yoktur, cikis yapiliyor. \n";
        }



   


    std::cout<<"Boyle bir hesap yoktur.";
    return 0;
}


