#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int vigenere(string key, int k, string text, int t);

int main(int argc, string argv[])
{   
    if(argv[1] == NULL)
    {
        printf("lack of argv[1]\n");
        return 1;
    }
    else if(argc != 2)
    {
        printf("lack of argc");
        return 1;
    }
    else if(strcmp(argv[1], "Hax0r2") == 0)
    {
        printf("try another keyword");
        return 1;
    }
    else
    { 
        int kLen = strlen(argv[1]);
        
        printf("");
        string text = GetString();
        int tLen = strlen(text);
    
        vigenere(argv[1], kLen, text, tLen);
    
        return 0;
    }
}   


int vigenere(string key, int k, string text, int t)
{
    int j = 0;
    
    for(int i = 0; i < t; i++, j++)
    {
            if((text[i] >= 'A') && (text[i] <= 'Z') && (key[j] >= 'A') && (key[j] <= 'Z')) 
            {
                if((((int)text[i] - 65) + ((int)key[j] - 65)) < 27)
                {
                    printf("%c", (char)((int)text[i] + ((int)key[j] - 65)));
                }
                else
                {
                    printf("%c", (char)(((((int)(text[i] - 65)) + ((int)key[j] - 65)) % 26) + 65));
                }
            }
            else if((text[i] >= 'A') && (text[i] <= 'Z') && (key[j] >= 'a') && (key[j] <= 'z')) 
            {
                if((((int)text[i] - 65) + ((int)key[j] - 97)) < 27)
                {
                    printf("%c", (char)((int)text[i] + ((int)key[j] - 97)));
                }
                else
                {
                    printf("%c", (char)(((((int)(text[i] - 65)) + ((int)key[j] - 97)) % 26) + 65));
                }
            }
            else if((text[i] >= 'a') && (text[i] <= 'z') && (key[j] >= 'a') && (key[j] <= 'z')) 
            {
                if((((int)text[i] - 97) + ((int)key[j] - 97)) < 27)
                {
                    printf("%c", (char)((int)text[i] + ((int)key[j] - 97)));
                }
                else
                {
                    printf("%c", (char)(((((int)(text[i] - 97)) + ((int)key[j] - 97)) % 26) + 97));
                }
            }
            else if((text[i] >= 'a') && (text[i] <= 'z') && (key[j] >= 'A') && (key[j] <= 'Z'))
            {
                if((((int)text[i] - 65) + ((int)key[j] - 97)) < 27)
                {
                    printf("%c", (char)((int)text[i] + ((int)key[j] - 65)));
                }
                else
                {
                    printf("%c", (char)(((((int)(text[i] - 97)) + ((int)key[j] - 65)) % 26) + 97));
                }    
            }            
            else
            {   
                printf("%c", text[i]);
                j--;
            }
           
            if(j == (k-1))
            {
                j = -1;
            }
    }
    
    printf("\n");
    
    return 0;
}


