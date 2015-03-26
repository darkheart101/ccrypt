#include<stdio.h>
#include<string.h>

void main(void){

	int i,j,key,plain_len;
	char ABC[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char abc[] = {"abcdefghijklmonpqrstuvwxyz"};
	char plain[255];
	
	printf("Set your key first:\n");
	scanf("%d",&key);
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
				printf("%c",ABC[(j+key)%26]);
				break;
			}	
		}
	}
	printf("\n");
	
}
