#include<stdio.h>
#include<string.h>

#define MAXBUFFERSIZE 255

int main(void){

	int i,j,key,plain_len,choise=0,letter,char_count;
	char ABC[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char abc[] = {"abcdefghijklmonpqrstuvwxyz"};
	char plain[255];
	char crypto[255];
	char ch;
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
	if(choise == 1){
		printf("Set your key first:\n");
		scanf("%d",&key);
		/*
		while(key<=0){
			printf("Set your key first (key > 0)\n");
			scanf("%d",&key);
		}*/
		key = key % 26;
		
		printf("\nYour key is: %d",key);
		printf("\nInsert your plain text:");
		scanf("%s",plain);
		plain_len = strlen(plain);
	
		key = key%26;
		printf("%d\n",key);

		for(i=0;i<plain_len;i++){
			for(j=0;j<26;j++){
				if(plain[i] == abc[j]){
					printf("crypto[%d] = %c\n",i,abc[(j+key)%26]);
					break;
				}else if(plain[i] == ABC[j]){
					printf("crypto[%d] = %c\n",i,ABC[(j+key)%26]);
					break;
				}	
			}
		}
		printf("\n");
	}

	if(choise == 2){
		printf("Set your key first:\n");
		scanf("%d",&key);
		key = key % 26;
		printf("\nYour key is: %d",key);
		printf("\nInsert your cryptic text:");
		scanf("%s",crypto);
		plain_len = strlen(crypto);
	
		key = key%26;
		printf("%d\n",key);

		for(i=0;i<plain_len;i++){
			for(j=0;j<26;j++){
				letter = (j-key)%26;
				if(letter < 0)
					letter = 26 + letter;
				if(crypto[i] == abc[j]){
					printf("plaintext[%d] = %c\n",i,abc[letter]);
					break;
				}else if(plain[i] == ABC[j]){
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
