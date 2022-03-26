#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "dzialania.h"

void dopelnienie(int temp, std::string& str)
{
    for (int i = 0; i < temp; i++)
        str += '0';
}

void przemiana(int& N, std::string& a, std::string& b)
{
    const int DLa = a.length();
    const int DLb = b.length();
    int temp = DLa - DLb;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (temp > 0)
    {
        dopelnienie(temp, b);
        N = DLa;
    }
    else
    {
        temp *= -1;
        dopelnienie(temp, a);
        N = DLb;
    }
}

std::string dodawanie(std::string skladnik1, std::string skladnik2)
{
    std::string suma = "";
    int N;
    bool reszta = 0;
    przemiana(N, skladnik1, skladnik2);
    for (int i = 0; i < N; i++)
    {
        int w = skladnik1[i] + skladnik2[i] + reszta - 2 * '0';
        suma += std::to_string(w % 10);
        reszta = (w % 10 - w)/10;
    }
    if (reszta)
        suma += '1';
    reverse(suma.begin(), suma.end());
    return suma;
}

std::string odejmowanie(std::string a, std::string b)
{
    std::string roznica = "";
    int N;
    bool odejma = 0;
    przemiana(N, a, b);
    for (int i = 0; i < N; i++)
    {
        a[i] -= '0';
        b[i] -= '0';
        if (a[i] < b[i])
        {
            a[i + 1] -= 1;
            a[i] += 10;
        }
        roznica += std::to_string(a[i] - b[i]);
    }
    std::reverse(roznica.begin(), roznica.end());
    if(roznica[0] == '0')
        roznica.erase(0, 1);
    return roznica;
}

std::string mnozenie_pojedyncze(std::string a, char b)
{
    std::string iloczyn = "";
    const int N = a.length();
    const int x = b - '0';
    int reszta = 0;
    reverse(a.begin(), a.end());
    for (int i = 0; i < N; i++)
    {
        char z = (a[i] - '0')*x+reszta;
        char dod = z % 10;
        iloczyn += dod + '0';
        reszta = z - dod;
    }
    return iloczyn;
}

std::string mnozenie(std::string a, std::string b)
{
    std::string wynik = "";
    const int DLa = a.length();
    const int DLb = b.length();
    const int X = DLb;
    std::vector<std::string> tab;
    for (int i = 0; i < DLb; i++)
    {
        tab.push_back(mnozenie_pojedyncze(a, b[i]));
        for (int j = 0; j < i; j++)
            tab[i] += '0';
    }
    for (auto el : tab)
        wynik = dodawanie(wynik, el);
    return wynik;
}

bool mniejsze(std::string a, std::string b)
{
    if (a.length() > b.length())
        return true;
    std::vector<std::string> x = { a,b };
    sort(x.begin(), x.end());
    return x[0] == b && a != b;
}

std::string dzielenie_calkowite(std::string dzielna, std::string dzielnik)
{
    if (dzielnik == "0")
        return "ERROR";
    if (!mniejsze(dzielna, dzielnik))
        return "0";
    std::string iloraz = "0";
    std::string temp = "0";
    while (mniejsze(dzielna, dzielnik))
    {
        dzielna = odejmowanie(dzielna, dzielnik);
        iloraz = dodawanie(iloraz, "1");
    }
    iloraz = dodawanie(iloraz, "1");
    return iloraz;
}

std::string silnia(std::string a)
{
    std::string wynik = "1";
    std::string zmienna = "1";
    while (mniejsze(a, zmienna))
    {
        wynik = mnozenie(wynik, zmienna);
        zmienna = dodawanie(zmienna, "1");
    }
    return mnozenie(wynik, a);
}