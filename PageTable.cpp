#include "PageTable.h"
#include <iostream>

PageTable::PageTable(int numPages) : pages(numPages) {
   // pages.resize(numPages);
    for (int i = 0; i < pages.size(); i++) {
        pages.at(i).assigned = false;
        pages.at(i).frame = -1;
    }
}

void PageTable::assignFrame(int PageNumber, int frameNumber) {
    pages[PageNumber].assigned = true;
    pages[PageNumber].frame = frameNumber;
}

int PageTable::translate(int virtualAddress) {
    int pageSize = 4096;
    int pageNumber = virtualAddress / pageSize;
    int offset = virtualAddress % pageSize;

    if (pageNumber >= pages.size() + 1 || !pages[pageNumber].assigned) {
        return -1;
    }

    return pages[pageNumber].frame * pageSize + offset;
}
