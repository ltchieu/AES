#define _CRT_SECURE_NO_WARNINGS
#include "aes.h"

void main() {

	uint8_t key[16];
	uint8_t Ptext[16];
	uint8_t CText[16];
	uint8_t* w = new uint8_t; //expand key
	int choice;
	
	printf("\n");
	printf("---------------MENU---------------\n");
	printf("|1. Ma Hoa                      |\n");
	printf("|2. Giai Ma                     |\n");
	printf("|0. De thoat chuong trinh       |\n");
	printf("---------------------------------\n");
	printf("Moi nhap lua chon: ");
	scanf("%d", &choice);


	try
	{
		switch (choice)
		{
		case 1:
			printf("Nhap Khoa k: ");
			nhapMangThapLucPhan(key);
			printf("\nNhap PlainText: ");
			nhapMangThapLucPhan(Ptext);

			KeyExpansion(key, w, Rcon, s_box); // key schedule

			printf("\nPlaintext message:\n");
			for (int i = 0; i < 4; i++) {
				printf("%02x %02x %02x %02x ", Ptext[4 * i + 0], Ptext[4 * i + 1], Ptext[4 * i + 2], Ptext[4 * i + 3]);
			}
			printf("\n");

			aes_cipher(Ptext, w, CText);

			printf("Ciphered message:\n");
			for (int i = 0; i < 4; i++) {
				printf("%02x %02x %02x %02x ", CText[4 * i + 0], CText[4 * i + 1], CText[4 * i + 2], CText[4 * i + 3]);
			}
			printf("\n");
			break;

		case 2:
			printf("Nhap Khoa k: ");
			nhapMangThapLucPhan(key);
			printf("\nNhap CipherText: ");
			nhapMangThapLucPhan(CText);

			KeyExpansion(key, w, Rcon, s_box); // key schedule

			printf("Ciphered message:\n");
			for (int i = 0; i < 4; i++) {
				printf("%02x %02x %02x %02x ", CText[4 * i + 0], CText[4 * i + 1], CText[4 * i + 2], CText[4 * i + 3]);
			}
			printf("\n");
			des_cipher(Ptext, w, CText);

			printf("Plaintext message:\n");
			for (int i = 0; i < 4; i++) {
				printf("%02x %02x %02x %02x ", Ptext[4 * i + 0], Ptext[4 * i + 1], Ptext[4 * i + 2], Ptext[4 * i + 3]);
			}
			printf("\n");
			break;
		default:
			break;
		}
	}
	catch (int errCode)
	{
		if (errCode == 101)
			printf("Do dai chuoi hex khong dung. Vui long nhap chuoi co 32 ky tu.\n");
	}	
}