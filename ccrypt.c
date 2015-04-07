#include<stdio.h>
#include<string.h>

#define MAXBUFFERSIZE 255

int main(void){

	int i,j,key,plain_len,choise=0,letter,char_count;
	char ABC[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char abc[] = {"abcdefghijklmonpqrstuvwxyz"};
	/*char plain[MAXBUFFERSIZE];*/
	char crypto[MAXBUFFERSIZE];
	char ch,key_ch,plain;
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
	}
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
	if(choise == 1){
		
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

		for(i=0;i<plain_len;i++){
			if(isspace((int)buffer[i])!=0){
				printf(" ");
			}
			else{
				for(j=0;j<26;j++){
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
	}

	if(choise == 2){
		printf("\nYour key is: %d",key);
		printf("\nInsert your cryptic text:");
		scanf("%s",crypto);
		plain_len = strlen(crypto);
	
		for(i=0;i<plain_len;i++){
			for(j=0;j<26;j++){
				letter = (j-key)%26;
				if(letter < 0)
					letter = 26 + letter;
				if(crypto[i] == abc[j]){
					printf("plaintext[%d] = %c\n",i,abc[letter]);
					break;
				}else if(crypto[i] == ABC[j]){
					printf("plaintext[%d] = %c\n",i,ABC[letter]);
					break;
				}	
			}
		}
		printf("\n");
	}
	if(choise == 3)
		return 0;

	
	
}
