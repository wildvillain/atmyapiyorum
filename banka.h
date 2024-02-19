#ifndef BANKA_H
#define BANKA_H
#include <string>



class banka
{
protected:
    std::string kisiadi;
    std::string kisiemail;
    size_t kisitel;
    int kisisifre;
    int kisihesapno;
    float hesapicipara;
    

    public:
    //void hesapsilme();

    void hesapacma(std::string ad , std::string email , size_t no, int sifre, int hesapno, float para){
        kisiadi = ad;
        kisiemail = email;
        kisitel = no;
        kisisifre = sifre;
        kisihesapno = hesapno ;
        hesapicipara = para;
    };

    void paracekme(int s){ 
       if (s < hesapicipara)
       {
        hesapicipara = hesapicipara - s;
        std::cout<<"\nHesabinizda kalan para miktari :"<<hesapicipara<<std::endl;
       }
       else
       {
        std::cout<<"\nHesabinizdan para cekilemedi!!"<<std::endl;
        std::cout<<"Hesabinizda kalan para miktari :"<<hesapicipara<<std::endl;
       }
       
       
        
        
    };

    void parayatirma(int s){
       
        hesapicipara = hesapicipara + s;
        std::cout<<"\nHesabinizdaki para miktari :"<<hesapicipara<<std::endl;
      
    };

    void sifredegisme(int s){
        if (s<10000 && s>999)
        {   int kont = 0;
            std::string sifretekrar1;
            int sifretekrar;

            std::cout<<"Onaylamak icin sifreyi yeniden girin: ";
            std::cin>>sifretekrar1;
            int length = sifretekrar1.length();
            sifretekrar = stoi(sifretekrar1);
            std::string str =  std::to_string(sifretekrar);
            int length1 = str.length();
            if (length1 == length)
            {
                if (sifretekrar == s)
            {
                kisisifre = s;
                std::cout<<"\nSifre basari ile degistirilmistir!";
                kont++;
                
            }
            else
            {
                std::cout<<"\nSifre degistirilemedi!!";
            }
            }
            
            
            
        }
        else{ std::cout<<"4 hanelik bir sifre gir!!"<<std::endl;}

        
    };

    //~hesapsilme();


};



#endif
