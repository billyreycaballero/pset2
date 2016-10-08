#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(void)
{
    printf("");
    string name = GetString();
    int n = strlen(name);
    printf("%c", toupper(name[0])); 
    
    for(int i = 0; i < n; i++)
    {
        if(name[i] == (char)32)
        {
            printf("%c", toupper(name[i+1]));
        }
    }
    printf("\n");
    
    return 0;
}
