#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void dopelnienie(int temp, std::string& str)
{
    for (int i = 0; i < temp; i++)
        str += '0';
}

std::string dodawanie(std::string a, std::string b)
{
    std::string wynik = "";
    const int DLa = a.length();
    const int DLb = b.length();
    int N;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (DLa > DLb)
    {
        int temp = DLa - DLb;
        dopelnienie(temp, b);
        N = DLa;
    }
    else
    {
        int temp = DLb - DLa;
        dopelnienie(temp, a);
        N = DLb;
    }
    int reszta = 0;
    for (int i = 0; i < N; i++)
    {
        int w = a[i] + b[i] + reszta - 2*'0';
        wynik += std::to_string(w % 10);
        if (w % 10 == w)
            reszta = 0;
        else
            reszta = 1;
    }
    if (reszta)
        wynik += '1';
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

void mnowl(const int N, std::string a, std::string b, std::vector<std::string> &dodatki)
{
    std::string zera = "";
    for (int i = 0; i < N; i++)
    {
        std::string tmp = "";

        int temp = b[i] - '0';
        for (int j = 0; j < temp; j++)
        {
            tmp = dodawanie(tmp, a);
        }
        tmp += zera;
        dodatki.push_back(tmp);
        zera += '0';
    }
}

std::string mnozenie(std::string a, std::string b)
{
    std::string wynik = "";
    std::vector<std::string> dodatki;
    const int DLa = a.length();
    const int DLb = b.length();
    if (DLa > DLb)
    {
        const int N = DLb;
        mnowl(N, a, b, dodatki);       
    }
    else
    {
        const int N = DLa;
        mnowl(N, b, a, dodatki);
    }
    for (auto el : dodatki)
        wynik = dodawanie(el, wynik);
    if (wynik == "")
        return "0";
    return wynik;
}

bool mniejsze(std::string a, std::string b)
{
    if (a.length() > b.length())
        return true;
    std::vector<std::string> x = {a,b};
    sort(x.begin(), x.end());
    return x[0] == b && a != b;
}

std::string dzielenie(std::string a, std::string b)
{
    std::string wynik = "0";
    std::string temp = "0";
    while (mniejsze(a,temp))
    {
        temp = mnozenie(b, wynik);
        wynik = dodawanie(wynik, "1");
    }
    return wynik;
}

int main()
{
    std::cout << dodawanie("1230345","1123123123123") << '\n';
    //std::cout << mnozenie("11", "3") << '\n';
    //std::cout << dzielenie("121", "11");
}