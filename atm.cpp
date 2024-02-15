#include <iostream>
#include <string>

#define MAX_KISI_SAYISI 8



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
        hesapicipara = hesapicipara + s;
        std::cout<<"Hesabinizda kalan para miktari :"<<hesapicipara<<std::endl;
       }
       
       
        
        
    };

    void parayatirma(int s){
       
        hesapicipara = hesapicipara + s;
        std::cout<<"\nHesabinizdaki para miktari :"<<hesapicipara<<std::endl;
      
    };

    void sifredegisme(int s){
        if (s<10000 && s>999)
        {   int sifretekrar;
            
            std::cout<<"Onaylamak icin sifreyi yeniden girin: ";
            std::cin>>sifretekrar;
            if (sifretekrar == s)
            {
                kisisifre = s;
                std::cout<<"\nSifre basari ile degistirilmistir!";
                
            }
            else
            {
                std::cout<<"\nSifre degistirilemedi!!";
            }
            
            
        }
        else{ std::cout<<"4 hanelik bir sifre gir!!"<<std::endl;}
        
    };

    //~hesapsilme();


};

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
                std::cout<<"İslem yapilamadi!\nLutfen daha sonra tekrar deneyiniz!\n";
                return 0;
            }   
            parayatirmabool = 0;
            

        }
        return atmicipara;

        std::cout<<std::endl<< atmicipara << std::endl;
    }

};


class kisi
{   
public:
    std::string kisiadi;
    std::string kisiemail;
    size_t kisitel;


};

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


int main(){


    //Kişisel bilgilerin girildiği kısım 
    std::string ad = "Yalcin Firat";
    std::string email = "yalcinking36@gmail.com";
    size_t numara = 5319524232;
    std::string ad2 = "Akif hoca";
    std::string email2 = "akifking36@gmail.com";
    size_t numara2 = 5322938365;
    std::string ad3 = "Sekiz Doga";
    std::string email3 = "sekizking36@gmail.com";
    size_t numara3 = 5319524232;
    std::string ad4 = "Hikaru Nakamura";
    std::string email4 = "nakamuraking36@gmail.com";
    size_t numara4 = 5322938365;
    std::string ad5 = "Magnus Carlsen";
    std::string email5 = "magnustheking36@gmail.com";
    size_t numara5 = 5319524232;
    std::string ad6 = "Vilademir Kramnik";
    std::string email6 = "vilacheatdetectengine36@gmail.com";
    size_t numara6 = 5319524232;
    std::string ad7 = "Fabiano Caruana";
    std::string email7 = "carokang36@gmail.com";
    size_t numara7 = 5319524232;
    std::string ad8 = "Sabo Pasha";
    std::string email8 = "sabopasha36@gmail.com";
    size_t numara8 = 5319524232;

    //class'lar için objelerin oluşturulduğu kısım
    kisi kisiler[MAX_KISI_SAYISI] = { {ad , email, numara } , {ad2 , email2, numara2},{ad3 , email3, numara3},{ad4 , email4, numara4}, 
    {ad5 , email5, numara5}, {ad6 , email6, numara6},{ad7 , email7, numara7},{ad8 , email8, numara8} };
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
    
    int hspno = 3056,sifre = 3056;  
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








/*

struct Bank {
    int hesapno, sifre;
    float hesapicipara;
    std::string ad;
};




void hesapBilgileriniGoster(Bank hesaplar[], int hesapSayisi, int hesapNo, int sifre) {
    for (int i = 0; i < hesapSayisi; ++i) {
        if (hesaplar[i].hesapno == hesapNo && hesaplar[i].sifre == sifre) {
            std::cout << "Hesap no: " << hesaplar[i].hesapno << "\n"
                      << "Hesap ici para: " << hesaplar[i].hesapicipara << "\n"
                      << "Hesap kisi adi: " << hesaplar[i].ad << "\n";
            return;
        }
    }
    std::cout << "Hesap bulunamadi veya sifre yanlis.\n";
}



void hesapEkle(Bank hesaplar[], int& hesapSayisi) {
    if (hesapSayisi < MAX_HESAP_SAYISI) {
        std::cout << "Yeni hesap bilgilerini girin:\n";
        std::cout << "Hesap no: ";
        std::cin >> hesaplar[hesapSayisi].hesapno;
        std::cout << "Sifre: ";
        std::cin >> hesaplar[hesapSayisi].sifre;
        std::cout << "Hesap ici para: ";
        std::cin >> hesaplar[hesapSayisi].hesapicipara;
        std::cout << "Ad: ";
        std::cin >> hesaplar[hesapSayisi].ad;
        ++hesapSayisi;
        std::cout << "Hesap basariyla eklendi.\n";
    } else {
        std::cout << "Maksimum hesap sayisina ulasildi. Yeni hesap eklenemez.\n";
    }
}

int main() {
    Bank hesaplar[MAX_HESAP_SAYISI] = {
        {5065, 5065, 4800.456, "Yalcin"},
        {4065, 4065, 15400.2, "Akif"},
        {3065, 3065, 17300.256, "Mehmet"},     
    };
    int hesapSayisi = 3; // Başlangıçta mevcut hesap sayısı

    int secim, hesapNo, sifre;

    do {
        std::cout << "\nMenu:\n"
                  << "1. Hesap Goruntule\n"
                  << "2. Hesap Ekle\n"
                  << "3. Cikis\n"
                  << "Seciminizi yapin: ";
        std::cin >> secim;

        switch (secim) {
            case 1:
                std::cout << "Hesap no girin: ";
                std::cin >> hesapNo;
                std::cout << "Sifre girin: ";
                std::cin >> sifre;
                hesapBilgileriniGoster(hesaplar, hesapSayisi, hesapNo, sifre);
                break;
            case 2:
                hesapEkle(hesaplar, hesapSayisi);
                break;
            case 3:
                break;
            default:
                std::cout << "Gecersiz secim. Lutfen tekrar deneyin.\n";
        }
    } while (secim != 3);

    return 0;
}
*/