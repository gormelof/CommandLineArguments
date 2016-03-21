// Sistem Programlama
// Soru 2
// Dosya adı: app2.c
// @gormelof

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

/**
 * yine main fonksiyonu parametrelerinden(argc, argv) faydalanıyoruz.
 * bu sefer komut satırı için option(seçenek) belirleyerek işlemler yapılıyor.
 * getopt() fonksiyonu bu programda anahtar fonksiyon (kilit oyuncu, başrol, vs.)
*/
int main(int argc, char *argv[]) {

	int t_flag = 0, c_flag = 0; // bu flag'leri seçenekleri belirlemek için tanımlıyoruz
	int ch, i; // döngü değişkenleri

	// -t, -c gibi parametreleri bu döngü içerisinde belirliyoruz.
	while((ch = getopt(argc, argv, "t:c:")) != -1) {
		switch(ch) {
			case 't':
			printf("t secenegi seçildi\n");
			t_flag = 1; // -t seçeneği için t_flag aktif oldu
			// t_arg = optarg;
			break;
			case 'c':
			printf("c secenegi secildi\n");
			c_flag = 1; // -c seçeneği için c_flag aktif oldu
			// c_arg = optarg;
			break;
		}
	}

	// toplam için etkisiz eleman = 0
	// çarpım için etkisiz eleman = 1
	int toplam = 0, carpim = 1;
	
	if(argc == 1) { // tek parametre program adıdır, bu bizim işimize yaramaz yanlış kullanım
		printf("Gecersiz giris. Dogru kullanım orenegi: \"./program -c 1 2 3 4\" \n");
	} else if(t_flag == 1 && c_flag == 0) { // -t'nin aktif olduğu kısım
		for(int i = 2; i < argc; i++) {
			toplam += atoi(argv[i]); // parametreler atoi() fonksiyonu ile int dönüşümü yapılarak işleme sokuluyor
		}
		printf("Toplam = %d\n", toplam); // toplam sonucu ekrana basılıyor
	} else if(t_flag == 0 && c_flag == 1) { // -c'nin aktif olduğu kısım
		for(int i = 2; i < argc; i++) {
			carpim *= atoi(argv[i]); // parametreler atoi() fonksiyonu ile int dönüşümü yapılarak işleme sokuluyor
		}
		printf("Carpim = %d\n", carpim); // çarpım sonucu ekrana basılıyor
	} else {
		printf("Gecersiz islem!\n"); // seçenek belirlenemedi o zaman işlemde yok canısı :)
	}

	return 0;
}