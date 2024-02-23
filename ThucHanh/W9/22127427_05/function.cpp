#include "header.h"

void CFile::print(bool print_hidden_items) const {
    if (!is_Hidden || print_hidden_items)
        cout << "File: " << name << " - (Size: " << size << " bytes)" << endl;
}

void CFolder::add(CItem *item) {
    items.push_back(item);
    size += item->getSize();
}

void CFolder::print(bool print_hidden_items) const {
    cout << "Folder: " << name << " - (Size: " << size << " bytes)" << endl;
    for (const CItem *item : items) {
        if (!item->isHidden() || print_hidden_items)
            item->print(print_hidden_items);
    }
}