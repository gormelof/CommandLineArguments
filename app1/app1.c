// Sistem Programlama
// Soru 1
// Dosya adı: app1.c
// @gormelof

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main fonksiyonu standardında iki
 * parametre vardır:
 * argc: konsolda programı çalıştırırken
 * parametrelerin sayısını tutar 
 * (program adınıda parametre olarak görür.)
 * argv: bir dizi işaretcisidir. Yine konsolda
 * program çalıştıtırken kullandığımız parametreleri
 * tutar.
*/

int main(int argc, char *argv[]) {

	char hex[50]; // değerleri hexadecimal'e dönüştürürken kullanılacak dizi

	int N = atoi(argv[1]); // char olarak gelen main parametresini(konsoldan gelen) integer'a dönüştürür ve dizi boyutu yapar

	int i; // döngü sayacı

	unsigned long dizi[N]; // ilk dizi
	unsigned char yeni_dizi[N]; // dizinin dönüşüm yapılmış halini tutacak yeni dizi

	srand(time(NULL)); // random sayı üretmek için kullandığımız dizi

	// dizi elemanlarını random atayıp ekrana gerekli formatlarda bastığımız döngü
	for(int i = 0; i < N; i++) {
		dizi[i] = rand(); // diziye random değerler atınıyor

		printf("Elemanin degeri             -> dizi[%d]  = %lu\n", i, dizi[i]);
		sprintf(hex, "%lx", dizi[i]); // dizi elemanının hexadecimal değere dönüşümü
		printf("Elemanin hexadecimal degeri -> dizi[%d]  = 0x%s\n", i, hex);
		printf("Elemanin adresi             -> &dizi[%d] = %p\n", i, &dizi[i]);
	}

	printf("\n--------------------------------------------------\n\n");

	// type casting işlemi yaptığımız ve yeni değerlerin basıldığı döngü
	for(int i = 0; i < N; i++) {
		yeni_dizi[i] = (unsigned char) dizi[i]; // type casting

		printf("Elemanin degeri             -> yeni_dizi[%d]  = %u\n", i, yeni_dizi[i]);
		sprintf(hex, "%x", yeni_dizi[i]); // dizi elemanının hexadecimal değere dönüşümü
		printf("Elemanin hexadecimal degeri -> yeni_dizi[%d]  = 0x%s\n", i, hex);
		printf("Elemanin adresi             -> &yeni_dizi[%d] = %p\n", i, &yeni_dizi[i]);
	}

	return 0;
}