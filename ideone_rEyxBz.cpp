#include <iostream>
#include<stdlib.h>
#include "mystring.h"

using namespace std;

MyString ::MyString ()
{
   //allocate memory for the string
   str = (char *)malloc(sizeof(char) * 100);
   len = 0;
}

MyString:: MyString(const char *s)
{
   
   int length = string(s).length();;
   str = (char *)malloc(sizeof(char) * length);
   int pos = 0;
   while(s[pos]!='\0')
   {
       str[pos] = s[pos];
       pos++;
   }
   str[pos] = '\0';
   len = length;
}

MyString:: MyString (MyString &s)
{

   len = s.len;
   str = (char *)malloc(sizeof(char) * len);
   int pos = 0;
   while(s.str[pos]!='\0')
   {
       str[pos] = s.str[pos];
       pos++;
   }
   str[pos] = '\0';
}

MyString:: ~MyString()
{
   cout<<this<<" Object Destroyed"<<endl;
}


ostream& operator <<(ostream& os, MyString& s)
{
   //print string and length of a string
   os << "String: "<<s.str<<endl;
   os<<"Length: "<<s.len<<endl;
   return os;
}




MyString& MyString:: operator=(MyString& s)
{
   //copy contents of s.str and s.len to the str and len
   len = s.len;
   str = (char *)malloc(sizeof(char) * len);
   int pos = 0;
   while(s.str[pos]!='\0')
   {
       str[pos] = s.str[pos];
       pos++;
   }
   str[pos] = '\0';
   return *this;
}
MyString& MyString:: operator+(MyString& s)
{
   //add string
   int pos = 0;
  
   while(s.str[pos]!='\0')
   {
       str[pos + len] = s.str[pos];
       pos++;
   }
   str[pos +len] = '\0';
   len += s.len;
   return *this;
  
}
