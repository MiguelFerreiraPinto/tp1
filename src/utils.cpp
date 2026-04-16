#include "../include/utils.h"
#include <cctype>

using namespace std;

void printDate(Date date)
{
    cout << date.day << "/" << date.month << "/" << date.year;
}

void printDado(const Dado &dado)
{
    cout << "Name: " << dado.name << endl;
    cout << "Dates: " << endl;
    for (int i = 0; i < 3; i++)
    {
        printDate(dado.dates[i]);
        cout << endl;
    }
}

void printDados(const vector<Dado> &dados)
{
    for (const auto &dado : dados)
    {
        printDado(dado);
        cout << endl;
    }
}

void readfile(vector<Dado> &dados, string filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            // Formato: NomeDDMMYYDDMMYYDDMMYY
            // Encontrar onde termina o nome (antes dos primeiros 6 dígitos)
            size_t i = 0;
            while (i < line.length() && !isdigit(line[i]))
            {
                i++;
            }
            
            string name = line.substr(0, i);
            Dado dado;
            dado.name = name;
            
            // Ler 3 datas de 6 dígitos cada (DDMMYY)
            for (int j = 0; j < 3; j++)
            {
                string dateStr = line.substr(i + j * 6, 6);
                int day = stoi(dateStr.substr(0, 2));
                int month = stoi(dateStr.substr(2, 2));
                int year = stoi(dateStr.substr(4, 2));
                
                Date date = {day, month, year};
                dado.dates[j] = date;
            }
            dados.push_back(dado);
        }
        file.close();
    }
}

void sortVector(vector<Dado> &dados)
{
    for (size_t i = 0; i < dados.size(); i++)
    {
        insertionSortDates(dados[i].dates, 0, 2);
    }
    quickSortNames(dados, 0, dados.size() - 1);
}

void swap(Dado &a, Dado &b)
{
    Dado temp = a;
    a = b;
    b = temp;
}

int partitionNames(vector<Dado> &dados, int low, int high)
{
    string pivot = dados[high].name;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (dados[j].name < pivot)
        {
            i++;
            swap(dados[i], dados[j]);
        }
    }
    swap(dados[i + 1], dados[high]);
    return i + 1;
}

void insertionSortDates(Date datas[], int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        Date key = datas[i];
        int j = i - 1;
        while (j >= low && (datas[j].year > key.year || 
               (datas[j].year == key.year && datas[j].month > key.month) ||
               (datas[j].year == key.year && datas[j].month == key.month && datas[j].day > key.day)))
        {
            datas[j + 1] = datas[j];
            j--;
        }
        datas[j + 1] = key;
    }
}

void quickSortDates(Date datas[], int low, int high)
{
    if (low < high)
    {
        insertionSortDates(datas, low, high);
    }
}

void quickSortNames(vector<Dado> &dados, int low, int high)
{
    if (low < high)
    {
        int pi = partitionNames(dados, low, high);
        quickSortNames(dados, low, pi - 1);
        quickSortNames(dados, pi + 1, high);
    }
}
