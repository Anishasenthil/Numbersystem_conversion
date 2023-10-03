#include<iostream>
#include<cmath>
#include<string>
using namespace std;
void decimalToBinary(int dnum,char ans[],char ans1[])
{
    int t=0,count=0,j=0,i=0,k=0;
    while(dnum>0)
    {
        int rem=0;
        rem = dnum%2;
        ans[k++]=rem + '0';
        dnum=dnum/2;
        count++;
    }
    for(i=count-1;i>=0;i--)
    {
        if(ans[i] == '1')
        {
            break;
        }
    }
    for(int j=i;j>=0;j--)
    {
        ans1[t++]=ans[j];
    }
    ans1[t] = '\0';
}
void decimalToOctal(int dnum,int ans2[],int ans3[])
{
    int k=0,count=0,i,t=0;
    while(dnum>0)
    {
        int rem=0;
        rem = dnum%8;
        ans2[k++]=rem;
        dnum=dnum/8;
        count++;
    }
    for(i=count-1;i>=0;i--)
    {
        ans3[t++]=ans2[i];
    }
}

void decimalToHexadecimal(int dnum,char ans4[],char ans5[])
{
    int k=0,count=0,i,t=0;
    char rem1;
    while(dnum>0)
    {
        int rem=0;
        rem = dnum%16 ;
        if(rem > 9)
        {
            if(rem == 10)
                rem1='A';
            else if(rem == 11)
                rem1='B';
            else if(rem == 12)
                rem1='C';
            else if(rem == 13)
                rem1='D';
            else if(rem == 14)
                rem1 = 'E';
            else if(rem == 15)
                rem1 = 'F';
        }
        else
        {
            rem1 = rem + '0';
        }
        ans4[k++]=rem1;
        dnum=dnum/16;
        count++;
    }
    for(i=count-1;i>=0;i--)
    {
        if(ans4[i]>9)
        {
            switch(ans4[i])
            {
            case 10:
                ans4[i]='A';
                break;
            case 11:
                ans4[i]='B';
                break;
            case 12:
                ans4[i]='C';
                break;
            case 13:
                ans4[i]='D';
                break;
            case 14:
                ans4[i]='E';
                break;
            case 15:
                ans4[i]='F';
                break;
            }
        }
        ans5[t++]=ans4[i];
    }
    ans5[t]='\0';
}
//////
int BinaryTodecimal(int dnum)
{
    int rem=0,val=0,power=0;
    int ans3=0;
    while(dnum>0)
    {
      rem=dnum%10;
      val=rem*pow(2,power);
      ans3+=val;
      power++;
      dnum=dnum/10;
    }
    return ans3;
}

void BinaryToOctal(int dnum,int ans6[],int ans7[])
{
    int rem=0,k=0,count=0,t=0;
 while(dnum>0)
 {
    rem =  dnum%1000;
   if(rem == 000)
    rem = 0;
   else if((rem == 001)||( rem == 1))
    rem =1;
   else if((rem == 010)||(rem == 10))
    rem = 2;
   else if((rem == 011)||(rem ==11))
    rem = 3;
   else if(rem == 100)
    rem = 4;
   else if(rem == 101)
    rem = 5;
   else if(rem == 110)
    rem = 6;
   else if(rem == 111)
    rem = 7;
   ans6[k++]=rem;
   dnum=dnum/1000;
   count++;
}
 for(int i=count-1;i>=0;i--)
     ans7[t++]=ans6[i];
}

void BinaryToHexadecimal(int dnum,char ans8[],char ans9[])
{
    int mul,sum=0,rem1=0,rem=0,count=0,k=0,t=0;
    while(dnum>0)
    {
         sum=0;char hexdig;mul=1;
         rem=dnum%10000;
         while(rem>0)
         {
             rem1=rem%10;
             sum+=(rem1*mul);
             rem=rem/10;
             mul*=2;
         }
         if(sum>9)
         {
             switch(sum)
            {
            case 10:
                hexdig='A';
                break;
            case 11:
                hexdig='B';
                break;
            case 12:
                hexdig='C';
                break;
            case 13:
                hexdig='D';
                break;
            case 14:
                hexdig='E';
                break;
            case 15:
                hexdig='F';
                break;
            }
         }
         else
         {
            hexdig=sum+'0';
         }
         ans8[k++]=hexdig;
         dnum=dnum/10000;
         count++;
    }
    for(int i=count-1;i>=0;i--)
         ans9[t++]=ans8[i];
}
//////////

int OctalTodecimal(int dnum)
{
    int power=0,rem=0,sum=0;
    while(dnum>0)
    {
        rem=dnum%10;
        sum+=rem*pow(8,power);
        power++;
        dnum=dnum/10;
    }
    return sum;
}

int OctalTobinary(int dnum,int binary[5][3],int result[5][3])
{
    int rem=0,i=0,j=0,k;
    while(dnum>0)
    {
        rem=dnum%10;
        for(i =0;i<3;i++)
        {
            binary[j][i]=rem%2;
            rem=rem/2;
        }
        j++;
        dnum=dnum/10;
    }
    for(i=j-1;i>=0;i--)
    {
        for(k=2;k>=0;k--)
        {
            result[i][k]=binary[i][k];
        }
    }
    result[i][k]='\0';
    return j;
}

void OctalToHexadecimal(int dnum,char ans10[],char ans11[])
{
    int power=0,sum=0,rem=0,t=0;
    char rem1;int k=0,count=0,i;
    while(dnum>0)
    {
        rem=dnum%10;
        sum+=rem * pow(8,power);
        dnum=dnum/10;
        power++;
    }
     while(sum>0)
    {
        int rem=0;
        rem = sum%16 ;
        if(rem > 9)
        {
            if(rem == 10)
                rem1='A';
            else if(rem == 11)
                rem1='B';
            else if(rem == 12)
                rem1='C';
            else if(rem == 13)
                rem1='D';
            else if(rem == 14)
                rem1 = 'E';
            else if(rem == 15)
                rem1 = 'F';
        }
        else
        {
            rem1 = rem + '0';
        }
        ans10[k++]=rem1;
        sum=sum/16;
        count++;
    }
    for(i=count-1;i>=0;i--)
    {
        if(ans10[i]>9)
        {
            switch(ans10[i])
            {
            case 10:
                ans10[i]='A';
                break;
            case 11:
                ans10[i]='B';
                break;
            case 12:
                ans10[i]='C';
                break;
            case 13:
                ans10[i]='D';
                break;
            case 14:
                ans10[i]='E';
                break;
            case 15:
                ans10[i]='F';
                break;
            }
        }
        ans11[t++]=ans10[i];
    }
    ans11[t]='\0';
}
//////
int HexadecimalTodecimal( char dnum[])
{
    int len=0;char rem;int power=0,dig=0,sum=0;
    for(int q = 0;dnum[q] != '\0' ; q++)
    {
        len++;
    }
    for(int i=len-1;i>=0;i--)
    {
        rem = dnum[i];
        if(rem == 'A')
            dig=10;
        else if(rem == 'B')
            dig =11;
        else if(rem == 'C')
            dig =12;
        else if(rem =='D')
            dig=13;
        else if(rem == 'E')
            dig=14;
        else if(rem == 'F')
            dig=15;
        else
            dig = rem - '0'; // CONVERTING FROM CHAR TO INT  whereas  dig = rem +'0'; // CONVERTING FROM INT TO CHAR
        sum+=dig*pow(16,power);
        power++;
    }
    return sum;
}
int  HexaTobinary(char dnum[],int binary2[20][4],int result2[20][4])
{
    int rem,k;
    int i=0,j=0,p=0,len=0,dig=0;
    for(int q = 0;dnum[q] != '\0' ; q++)
    {
        len++;
    }
     for(int i=len-1;i>=0;i--)
     {
        rem = dnum[i];
        if(rem == 'A')
            dig = 10;
        else if(rem == 'B')
            dig =11;
        else if(rem == 'C')
            dig =12;
        else if(rem =='D')
            dig=13;
        else if(rem == 'E')
            dig=14;
        else if(rem == 'F')
            dig=15;
        else
           dig = rem - '0';
        for(p =0;p<4;p++)
        {
            binary2[j][p]=dig%2;
            dig=dig/2;
        }
        j++;
     }
    for(i=j-1;i>=0;i--)
    {
        for(k=3;k>=0;k--)
        {
            result2[i][k]=binary2[i][k];
        }
    }
    result2[i][k]='\0';
    return j;
}
void HexaToOctal(char dnum[],int ans12[],int ans13[])
{
    int len=0,dig=0,sum=0,power=0,t=0;
    int k=0,count=0,i;
    for(int q = 0;dnum[q] != '\0' ; q++)
    {
        len++;
    }
    for(int i=len-1;i>=0;i--)
    {
        char rem=dnum[i];
        if(rem == 'A')
            dig = 10;
        else if(rem == 'B')
            dig =11;
        else if(rem == 'C')
            dig =12;
        else if(rem =='D')
            dig=13;
        else if(rem == 'E')
            dig=14;
        else if(rem == 'F')
            dig=15;
        else
            dig =rem - '0';
        sum+=dig*pow(16,power);
        power++;
    }
    while(sum>0)
    {
        int rem=0;
        rem = sum%8;
        ans12[k++]=rem;
        sum=sum/8;
        count++;
    }
    for(i=count-1;i>=0;i--)
    {
        ans13[t++]=ans12[i];
    }
}
int main()
{
    int num=0,number=0,number1=0,bin=0,i=0,j=0,len=0,BtD=0,len1=0;
    char number2[50];
    char ans[50];
    char ans1[50];
    int ans2[50] = {0};
    int ans3[50] = {0};
    char ans4[50];
    char ans5[50];
    int ans6[50] = {0};
    int ans7[50] = {0};
    char ans8[50];
    char ans9[50];
    int binary[5][3];
    int result[5][3];
    char ans10[50];
    char ans11[50];
    int binary2[20][4];
    int result2[20][4];
    int ans12[50]={0};
    int ans13[50]={0};
    cout<<"                                Number System Conversions   "<<endl<<endl;
    cout<<"Decimal to Others system conversions "<<endl<<endl;
    cout<<"Enter DECIMAL no : ";
    cin>>num;
    cout<<"Decimal -> Binary : ";
    decimalToBinary(num,ans,ans1);
    puts(ans1);
    cout<<"Decimal -> Octal: ";
    decimalToOctal(num,ans2,ans3);
    while(ans3[len++] != '\0');
    len--;
    for(int p=0;p<len;p++)
    {
        cout<<ans3[p];
    }
    cout<<endl;
    cout<<"Decimal -> Hexadecimal : ";
    decimalToHexadecimal(num,ans4,ans5);
    puts(ans5);
    cout<<endl<<endl;
    /////////////

    cout<<"Binary to Others system conversions "<<endl<<endl;
    cout<<"Enter BINARY no [10 dig] : ";
    cin>>number;

    cout<<"Binary -> Decimal : ";
    BtD=BinaryTodecimal(number);
    cout<<BtD;
    cout<<endl;
    cout<<"Binary -> Octal : ";
    BinaryToOctal(number,ans6,ans7);
    while(ans7[len++] != '\0');
    len--;
    for(int p=0;p<len;p++)
    {
        cout<<ans7[p];
    }
    cout<<endl;
    cout<<"Binary -> Hexadecimal : ";
    BinaryToHexadecimal(number,ans8,ans9);
    puts(ans9);
    cout<<endl<<endl;
    //////////

    cout<<"Octal to Others system conversions "<<endl<<endl;
    cout<<"Enter OCTAL no : ";
    cin>>number1;

    cout<<"Octal -> Decimal : ";
    int Otd=OctalTodecimal(number1);
    cout<<Otd;
    cout<<endl;

    cout<<"Octal -> Binary : ";
    int j_val=OctalTobinary(number1,binary,result);


   for(i=j_val-1;i>=0;i--)
    {
        for(int k=2;k>=0;k--)
        {
            cout<<result[i][k];
        }
    }
    cout<<endl;
   cout<<"Octal -> Hexadecimal : ";
   OctalToHexadecimal(number1,ans10,ans11);
   puts(ans11);
   cout<<endl<<endl;
   //////////
   cout<<"Hexadecimal to Others system conversions "<<endl<<endl;
    cout<<"Enter HEXADECIMAL no : ";
    fflush(stdin);
    gets(number2);

   cout<<"Hexadecimal -> Decimal: ";
   int Htd=HexadecimalTodecimal(number2);
   cout<<Htd;
    cout<<endl;
    cout<<"Hexadecimal -> Binary: ";
    int j_val1=HexaTobinary(number2,binary2,result2);
    for(i=j_val1-1;i>=0;i--)
    {
        for(int k=3;k>=0;k--)
        {
            cout<<result2[i][k];
        }
    }
    cout<<endl;
    cout<<"Hexadecimal -> Octal: ";
    HexaToOctal(number2,ans12,ans13);
    while(ans13[len++] != '\0');
    len--;
    for(int p=0;p<len;p++)
    {
        cout<<ans13[p];
    }
    cout<<endl<<endl;
    return(0);
}

