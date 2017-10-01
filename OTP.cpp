// OTP(One Time Password) generator program in C++

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

string OTPgenerator(int OTPlength)
{
    srand(time(NULL));  // Seed
    string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";  // All possible characters of OTP
    int n = str.length();

    string OTP;  // String to store the OTP
    for(int i=0 ; i<OTPlength ; i++)
        OTP.push_back(str[rand() % n]);

    return OTP;
}

int main()
{
    cout << "Your OTP is : " << OTPgenerator(6) << endl;
    return 0;
}
