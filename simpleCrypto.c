# include <stdio.h>
#include <stdlib.h>
# include <stdint.h>
#include <string.h>
int length(char* text) {
    int index = 0; 
    int size = 0; 

    while (text[index] != '\0') {
        size++;
        index++; 
    }

    return size;
}
char* Encrypt(char* text, int32_t shift){
  int size = length(text);
  char* encryptedText = (char*)malloc(20 * sizeof(char));
  
  char shifted[2];
  for(int i = 0; i < size; i++){
    
    shifted[0] = (text[i] + shift);
    if(shifted[0]> 'z'){
      shifted[0] = shifted[0]+(-26);
    }
    shifted[1] = '\0';
    strcat(encryptedText, shifted);

  }

  return encryptedText;
}
char* Decrypt(char* text, int32_t shift) {
    int size = strlen(text);
    char* decryptedText = (char*)malloc((size + 1) * sizeof(char)); 
    decryptedText[0] = '\0'; 

    for (int i = 0; i < size; i++) {
        char c = text[i];
        char result = c + shift;
        decryptedText[i] = result;
    }
    decryptedText[size] = '\0'; 
  
    return decryptedText;
}


int main(){
    char* resultEncrypt = Encrypt("teste", 2);
    printf("result encrypt: %s\n", resultEncrypt);
    int shift = -2;

    char* decrypted = Decrypt(resultEncrypt, shift);
    printf("Decrypted: %s\n", decrypted);

}




