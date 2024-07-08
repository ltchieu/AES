#pragma

#ifndef AES_H
#define AES_H

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

#define MAXCol 100
#define Nb 4

extern uint8_t s_box[256];
extern uint8_t Rcon[11];

		// khai bao ham

	// Cac ham ma hoa
void AddAroundKey(uint8_t Key[], uint8_t Result[], int r);
void SubBytes(uint8_t Result[]);
void ShiftRows(uint8_t Result[]);
void ShiftRow(uint8_t Result[], int row, int shift);
void MixColumns(uint8_t Result[], uint8_t Mix_box[]);
void aes_cipher(uint8_t Ptext[], uint8_t key[], uint8_t CipherText[]);


	//Cac ham sinh khoa vong
uint8_t rot_word(uint8_t* w);
void sub_word(uint8_t w[], uint8_t s_box[]);
void KeyExpansion(uint8_t* key, uint8_t* w, uint8_t* Rcon, uint8_t s_box[]);


	// Mot so ham phu tro
int Nhan2(uint8_t w);
int Nhan3(uint8_t w);
int nhapMangThapLucPhan(uint8_t arr[]);


// Cac ham Giai ma
void des_cipher(uint8_t Ptext[], uint8_t w[], uint8_t CipherText[]);
void invShiftRows(uint8_t Result[]);
void invShiftRow(uint8_t Result[], int row, int shift);
void invSubBytes(uint8_t Result[]);
void invMixColumns(uint8_t Result[], uint8_t invMix_box[]);
#endif 


