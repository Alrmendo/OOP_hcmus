#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CItem {
protected:
    string name;
    int size;
    bool readOnly;
    bool hidden;
public:
    CItem(const string&);
    CItem(const string&, int);

    virtual int sizeOfItem();
    virtual void print(bool);
    virtual string getName();
    virtual CItem* removeByName(const string&);
    virtual CItem* findByName(const string&);
    virtual void setHidden(bool, bool);
};

class CFolder:public CItem {
private:
    vector<CItem*> listOfItem;
public:
    CFolder(const string&);
    ~CFolder();

    int sizeOfItem();
    void add(CItem*);
    void print(bool);
    CItem* removeByName(const string&);
    CItem* findByName(const string&);
    void setHidden(bool, bool);
};

class CFile: public CItem {
public:
    CFile(const string&, int);
    int sizeOfItem();

    void print(bool);
    CItem* removeByName(const string&);
    CItem* findByName(const string&);
    void setHidden(bool, bool);
};