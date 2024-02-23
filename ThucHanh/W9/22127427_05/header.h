#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CItem {
protected:
    string name;
    int size;
    bool isReadOnly;
    bool is_Hidden;

public:
    CItem(const string &name, int size) : name(name), size(size), isReadOnly(false), is_Hidden(false) {}

    const string &getName() const { 
        return name; 
    }
    int getSize() const { 
        return size; 
    }
    bool isHidden() const { 
        return is_Hidden;
    }

    virtual void print(bool) const = 0;
};

class CFile : public CItem {
public:
    CFile(const string &name, int size) : CItem(name, size) {}
    void print(bool) const override;
};

class CFolder : public CItem {
private:
    vector<CItem *> items;

public:
    CFolder(const string &name) : CItem(name, 0) {}

    void add(CItem *);
    void print(bool) const override;
};