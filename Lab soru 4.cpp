#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Öðrenci yapýsý
struct Ogrenci {
    int ogrenciNo;
    char ad[50];
    struct Ogrenci* next;
};

// Öðrenci listesine yeni öðrenci ekleme fonksiyonu
struct Ogrenci* ogrenciEkle(struct Ogrenci* head, int no, const char* ad) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->ogrenciNo = no;
    strcpy(yeniOgrenci->ad, ad);
    yeniOgrenci->next = head;
    return yeniOgrenci;
}

// Öðrenci adýna göre arama yapma fonksiyonu
struct Ogrenci* ogrenciAraAd(struct Ogrenci* head, const char* hedefAd) {
    struct Ogrenci* gecici = head;
    while (gecici != NULL) {
        if (strcmp(gecici->ad, hedefAd) == 0) {
            return gecici; 
        }
        gecici = gecici->next;
    }
    return NULL; // Eþleþme bulunamadý  NULL döndür
}

int main() {
    struct Ogrenci* liste = NULL;

    // Öðrenci kayýtlarý 
    liste = ogrenciEkle(liste, 1, "enes");
    liste = ogrenciEkle(liste, 2, "saliha");
    liste = ogrenciEkle(liste, 3, "rukiye");
    liste = ogrenciEkle(liste, 4, "mert");

    // Kullanýcýdan aranacak öðrencinin adý
    char arananAd[50];
    printf("Aranacak ogrencinin adini girin: ");
    scanf("%s", arananAd);

    // Öðrenci adýna göre arama yap
    struct Ogrenci* sonuc = ogrenciAraAd(liste, arananAd);

    if (sonuc != NULL) {
        printf("Ogrenci Bulundu: Ogrenci No %d, Adý: %s\n", sonuc->ogrenciNo, sonuc->ad);
    } else {
        printf("Ogrenci Bulunamadý: %s\n", arananAd);
    }

    // Belleði temizle
    while (liste != NULL) {
        struct Ogrenci* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}

