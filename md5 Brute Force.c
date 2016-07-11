#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/md5.h>
#define MAXDIGIT 10

int compare(char *,int );

int main()
{
    char cset[]="abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
    int csetSize = strlen(cset);
    char value[MAXDIGIT];
    int digitVal[MAXDIGIT] = {0};
    int currentDigit=1, crs=0, i=0;
    int tmp1=10,tmp=1;
    
    // while( currentDigit<MAXDIGIT )
    while(tmp)
    {   
        while( digitVal[0]<csetSize )
        {
            for(i=0; i<currentDigit; i++)
                value[i] = cset[digitVal[i]];
            value[currentDigit] = '\0';
            tmp=compare(value,currentDigit);
            if(tmp==0) break;
            digitVal[0]++;
        }
        
        // CRS islemlerinden sorumlu
        while( digitVal[crs]==csetSize )
        {
            crs++;
            
            for(i=0; i<crs; i++)
                digitVal[i]=0;
            
            if( crs == currentDigit )
            {
                currentDigit++;
                break;
            }
            else
                digitVal[crs]++;
        }
        crs=0;
    }
return 0;
}

int compare(char myval[MAXDIGIT],int length)
{
    int i,a,con=0;
    unsigned char digest[16];
    char hash[16];
    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5,myval,strlen(myval));
    MD5_Final(digest, &md5);
    for(i=0;i<16;++i)
        snprintf(&(hash[i*2]),16*2,"%02x",(unsigned int)digest[i]);
        char den[]="4124bc0a9335c27f086f24ba207a4912";
        con=0;
        for(a=0;a<32;a++)
        {
            if(hash[a]!=den[a]);
            else con++;
        }
        if(con==32) 
        {
            printf("\n%s",myval);
            return 0;
        }
        else return 1;
        
}