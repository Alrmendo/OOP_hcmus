#include "header.h"

// CItem
CItem::CItem(const string& nameOfItem) {
    name = nameOfItem;
    size = 0;
    readOnly = false;
    hidden = false;
}

CItem::CItem(const string& nameOfItem, int sizeOfItem) {
    name = nameOfItem;
    size = sizeOfItem;
    readOnly = false;
    hidden = false;
}

int CItem::sizeOfItem() {
    return 0;
}

void CItem::print(bool isHidden) {

}

string CItem::getName() {
    return name;
}

CItem* CItem::removeByName(const string& name) {
    return NULL;
}

CItem* CItem::findByName(const string& name) {
    return NULL;
}

void CItem::setHidden(bool setSuper, bool setSub) {
    hidden = true;
}

// CFolder
CFolder::CFolder(const string& nameOfFolder): CItem(nameOfFolder) {

}

CFolder::~CFolder() {
    listOfItem.clear();
}

int CFolder::sizeOfItem() {
    return size;
}

void CFolder::add(CItem* inItem) {
    listOfItem.push_back(inItem);
    size = size + inItem->sizeOfItem();
}

void CFolder::print(bool isHidden) {
    if(isHidden==true) {
        cout << "Folder: " << name << " - (Size: " << size << " bytes)" << endl;
        for(int i=0; i<listOfItem.size(); i++) {
            listOfItem[i]->print(isHidden);
        }
    }
    else {
        if(hidden!=true) {
            cout << "Folder: " << name << " - (Size: " << size << " bytes)" << endl;
            for(int i=0; i<listOfItem.size(); i++) {
                listOfItem[i]->print(isHidden);
            }
        }
    }
}

CItem* CFolder::removeByName(const string& nameOfFolder) {
    for(int i = 0; i < listOfItem.size(); i++) {
        if (listOfItem[i]->getName() == nameOfFolder) {
            listOfItem.erase(listOfItem.begin() + i);
            return this;  // Stop searching after removing the item
        } else {
            CItem* result = listOfItem[i]->removeByName(nameOfFolder);
            if (result != NULL) {
                return result;  // Return if the item is found and removed
            }
        }
    }
    return NULL;  // Return NULL if the item is not found
}

CItem* CFolder::findByName(const string& nameOfFolder) {
    for(int i = 0; i < listOfItem.size(); i++) {
        if (listOfItem[i]->getName() == nameOfFolder) {
            return listOfItem[i];  // Return immediately if the item is found
        } else {
            CItem* result = listOfItem[i]->findByName(nameOfFolder);
            if (result != NULL) {
                return result;  // Return if the item is found in the subfolder
            }
        }
    }
    return NULL;  // Return NULL if the item is not found
}

void CFolder::setHidden(bool setSuper, bool setSub) {
    if(setSub == true) {
        for(int i=0; i<listOfItem.size(); i++) {
            listOfItem[i]->CItem::setHidden(setSuper, setSub);
        }
    } else if(setSub !=true && setSuper == true) {
        hidden = true;
    }
}

//CFILE
CFile::CFile(const string& nameOfFile, int sizeOfFile):CItem(nameOfFile, sizeOfFile) {

}

int CFile::sizeOfItem() {
    return size;
}

void CFile::print(bool isHidden) {
    if (isHidden==true) {
        cout << "File: " << name << " - (Size: " << size << " bytes)" << endl;
    } else {
        if(hidden!=true) {
            cout << "File: " << name << " - (Size: " << size << " bytes)" << endl;
        }
    }
}

CItem* CFile::removeByName(const string& nameOfFile) {
    return this;
}

CItem* CFile::findByName(const string& nameOfFile) {
    CItem* temp = NULL;
    if (name == nameOfFile) temp = this;
    return temp;
}

void CFile::setHidden(bool setSuper, bool setSub) {
    if (setSub == true) hidden = true;
}