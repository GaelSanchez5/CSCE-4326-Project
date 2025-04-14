#pragma once
#include <vector>

struct Page{
    bool assigned;
    int frame;
};

class PageTable {
public:
    PageTable(int numPages);
    int translate(int virtualAddress);
    void assignFrame(int PageNumber, int frame);
    std::vector<Page> pages;
};
