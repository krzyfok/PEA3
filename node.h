#pragma once

#include <vector>
using namespace std;

struct node {
    int granica; // lower bound
    int wierzcholek; // numer wierzchołka
    vector<int> do_odwiedzenia; // wierzchołki do odwiedzenia
    vector<int> trasa; // trasa

    node() : granica(0), wierzcholek(0) {}
};

struct CompareNode {
    bool operator()(const node a, const node b) {
        return a.granica > b.granica; 
    }
};
