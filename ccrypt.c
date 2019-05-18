/* 
==============================================================
This is a very simple implementation of the Caesar cipher.
You can cipher and de-cipher text capital or small letters.
The cipher and de-cipher does not apply on special characters
as !,(,),*,-,_ and so on. Also works only with latin alphabet.


Author: Thodoris Kouleris
Date: 14 Apr. 2015

=============================================================
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXBUFFERSIZE 255

int encrypt(int key){
	int plain_len,letter,char_count;
	char ABC[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char abc[] = {"abcdefghijklmonpqrstuvwxyz"};
	char plain;
	char buffer[MAXBUFFERSIZE];

	printf("\nYour key is: %d",key);
	printf("\nInsert your plain text:");
			
	plain = getchar();
	char_count = 0;
	
	while( (plain != '\n')  &&  (char_count < MAXBUFFERSIZE)) {
		buffer[char_count++] = plain;
		plain = getchar();
	}
	buffer[char_count] = 0x00;   
	plain_len = strlen(buffer);
			
	printf("Encrypted text:\n");
	for(int i=0;i<plain_len;i++){
		if(isspace((int)buffer[i])!=0){
			printf(" ");
		}
		else{
			for(int j=0;j<26;j++){
				if(buffer[i] == abc[j]){
					printf("%c",abc[(j+key)%26]);
					break;
				}else if(buffer[i] == ABC[j]){
					printf("%c",ABC[(j+key)%26]);
					break;
				}
				if(j == 25){ /*If the plain character is not in the alphabet or is not space then print whatever the plaincharacter is */
					printf("%c",buffer[i]);
				}	
			}
		}
	}
	printf("\n");
	printf("----------------------------\n");

	return 0;
}

int decrypt(int key){
	int letter,char_count,crypto_len;
	char ABC[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char abc[] = {"abcdefghijklmonpqrstuvwxyz"};
	char crypto;
	char buffer[MAXBUFFERSIZE];

	printf("\nYour key is: %d",key);
	printf("\nInsert your cryptic text:");
	
	crypto = getchar();
	char_count = 0;
	
	while( (crypto != '\n')  &&  (char_count < MAXBUFFERSIZE)) {
		buffer[char_count++] = crypto;
		crypto = getchar();
	}
	buffer[char_count] = 0x00;   
	crypto_len = strlen(buffer);
		
	printf("Decrypted text:\n");	
	for( int i = 0 ; i < crypto_len ; i++ ){
		if(isspace((int)buffer[i])!=0){
			printf(" ");
		}
		else{
			for( int j = 0 ; j < 26 ; j++ ){
				letter = (j-key)%26;
				if(letter < 0)
					letter = 26 + letter;
				if(buffer[i] == abc[j]){
					printf("%c",abc[letter]);
					break;
				}else if(buffer[i] == ABC[j]){
					printf("%c",ABC[letter]);
					break;
				}
				if(j == 25){
					printf("%c",buffer[i]);
				}
			}
		}
	}
	printf("\n");
	printf("----------------------------\n");
	
	return 0;
}

int main(void){

	int i,j,key,choise=0,char_count;
	char ABC[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char abc[] = {"abcdefghijklmonpqrstuvwxyz"};
	char ch,key_ch;
	char buffer[MAXBUFFERSIZE];
	
	while(choise <=0 || choise > 3){
		printf("[1] Encrypt\n[2] Decrypt\n[3] Exit\nChoose 1,2 or 3:");
	
		ch = getchar();
		char_count = 0;
	
		while( (ch != '\n')  &&  (char_count < MAXBUFFERSIZE)) {
			buffer[char_count++] = ch;
			ch = getchar();
		}
		buffer[char_count] = 0x00;      /* null terminate buffer */
		choise = atoi( buffer );
	
		if(choise!=3){
			key = 0;
			while(key <= 0){
				printf("Set your key first:\n");
				key_ch = getchar();
				char_count = 0;
			
				while( (key_ch != '\n')  &&  (char_count < MAXBUFFERSIZE)) {
					buffer[char_count++] = key_ch;
					key_ch = getchar();
				}
				buffer[char_count] = 0x00;      /* null terminate buffer */
				key = atoi( buffer );
			}
		
			key = key % 26;

		}

		/* --- Encryption --- */
		if(choise == 1)	choise = encrypt(key);


		/* --- Decryption --- */
		if(choise == 2) choise = decrypt(key);

		/* Exit */
		if(choise == 3) return 0;
	}	
}
