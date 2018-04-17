#include<stdio.h>
#include<string.h>

void PSArray(char *pat, int M, int *lps);
 
// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    int lps[M];
    
    int flag = 0;
 
    // Preprocess the pattern (calculate ps[] array)
    PSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            printf("Found pattern at index %d \n", i-j);
            j = lps[j-1];
            flag = 1;
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i += 1;
        }
        
    }
    
    if(flag == 0)
    {
    	printf("\n Does not match!!!");
	}
}
 
 
void PSArray(char *pat, int M, int *lps)
{
    
    int len = 0;
 
    lps[0] = 0; 
 
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0)
            {
                len = lps[len-1];
 
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
// beginning of main function
/*
int main()
{
    //char *txt = "ABABCABABCDABABCABA";
    //char *pat = "ABABCABAB";
    
    char txt[50];
    char pat[30];
    
    printf("\n Enter the string:");
    scanf("%s",txt);
    
    printf("\n Enter the pattern to be searched:");
    scanf("%s",pat);
    
    KMPSearch(pat, txt);
    return 0;
}
*/

int main()

{

    char txt[100];

    char pat[50];

    char option;

    int choice;

   

    

    do{

                system("cls");


               

                printf("\n\nEnter any  text or sentence :\n\t");

                //getchar();
                fflush(stdin);

                gets(txt);

               

                do{

               

                                                printf("\n\nEnter the pattern You Wnat to search in the String : \t");

                                                //getchar();

                                               fflush(stdin);

                                gets(pat);

                                KMPSearch(pat, txt);

   

    

                                printf("\n\nDO you want to search more Press 1 for Yes  :\t");

                                scanf("%d",&choice);

                                                }while(choice == 1);

                                /*if(choice == 1)

                                {

                                goto a;

                                                }*/

   

                                printf("\n\n\nDo you want to Check the pattern again\nPress Y or y for Continue..\n\tEnter your option here :\t ");

                                getchar();

                                scanf("%c",&option);

                                //getchar();

    }while(option == 'y' || option == 'Y');

    return 0;

}
