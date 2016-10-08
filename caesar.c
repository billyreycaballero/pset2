#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int cypher(int key, int k, int t, string text);

int main(int argc, string argv[])
{   
    if(argv[1] == NULL)
    {
        printf("lack of argv[1]\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        int k = key%26;
    
        printf("");
    
        string text = GetString();
        int t = strlen(text);
    
        cypher(key, k, t, text);
    
        return 0;
    }
}   


int cypher(int key, int k, int t, string text)
{
    for(int i = 0; i < t; i++)
    {
        if((text[i] >= 'A') && (text[i] <= 'Z')) 
        {
            if(k == 0)
            {
                if((((int)text[i])- 64 + key) <= 26)  
                {
                    printf("%c", (char)((int)text[i] + key));
                }
                else
                {
                    printf("%c", (char)((int)text[i] + k));
                }
            }
            else
            {
                if((((int)text[i])- 64 + k) <= 26)  
                {
                    printf("%c", (char)((int)text[i] + k));
                }
                else
                {
                    printf("%c", (char)(((int)text[i] - 64) + k + 38));
                }
            }
        }
        else if((text[i] >= 'a') && (text[i] <= 'z'))
        {
            if(k == 0)
            {
                if((((int)text[i])- 96 + key) <= 26)  
                {
                    printf("%c", (char)((int)text[i] + key));
                }
                else
                {
                    printf("%c", (char)((int)text[i] + k));
                }
            }
            else
            {
                if((((int)text[i])- 96 + k) <= 26)  
                {
                    printf("%c", (char)((int)text[i] + k));
                }
                else
                {
                    printf("%c", ((char)((int)text[i]) - 96) + k +70 );
                }
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    
    return 0;
}


