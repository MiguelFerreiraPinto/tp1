#include <string>
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

typedef struct date{
    int day;
    int month;
    int year;

} Date;

typedef struct dado{
    string name;
    Date dates [3];
} Dado;

void printDate(Date date);

void printDado(const Dado &dado);

void printDados(const vector<Dado> &dados);

void readfile(vector<Dado> &dados, string filename);

void sortVector(vector<Dado> &dados);

int partitionNames(vector<Dado> &dados, int low, int high);

void swap(Dado &a, Dado &b);

void quickSortNames(vector<Dado> &dados, int low, int high);

void quickSortDates(Date datas[], int low, int high);

void insertionSortDates(Date datas[], int low, int high);