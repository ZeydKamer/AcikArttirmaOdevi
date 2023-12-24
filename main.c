#include <stdio.h>

typedef struct{
    char urunAdi[40];
    double MevcutFiyat;
}   ArttirmaUrunu;
    void artirmayiBaslat(ArttirmaUrunu *urun){
        printf("Acik arttirma basladi!\n");
        while(1){
            double teklif;
            printf("Mevcut teklif: %.2lf TL\n", urun->MevcutFiyat);
            printf("Yeni teklifinizi verin (-1 cikis): ");
            scanf("%lf", &teklif);
            if(teklif == -1){
                printf("Acik arttirma sona erdi. %s isimli urun %lf TL'ye satilmistir.\n", urun->urunAdi, urun->MevcutFiyat);
                break;
            }
            else if(teklif>urun->MevcutFiyat){
                urun->MevcutFiyat = teklif;
                printf("Yeni teklif alindi!\n");
            }
            else{
                printf("Gecersiz teklif. Teklif mevcut fiyattan yuksek olmak zorundadir.\n");
            }
        }
    }

int main() {

    ArttirmaUrunu urun;

    printf("Lutfen urun adini giriniz: ");
    scanf("%s", urun.urunAdi);

    printf("Lutfen baslangic fiyatini giriniz: ");
    scanf("%lf", &urun.MevcutFiyat);

    artirmayiBaslat(&urun);

    return 0;
}
