#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>
using namespace std;

class IItem
{
protected:
    int indent = 1;
public:
    virtual ~IItem(){}
    virtual int getSize() = 0;
    virtual void print() = 0;
    void setIndent(int i) { indent = i;}
};

class File : public IItem {
    string name; 
    int size;
public:
    File (string n, int s) : name(n), size(s) {}
    ~File() {}
    int getSize() override {
        return size;
    }
    void print() override {
        cout << "(" << name << ", " << size << ")" << endl;
    }
};

class Folder : public IItem {
    string name; 
    vector<IItem*> items;
public:
    Folder (string n) : name(n) {}
    ~Folder() {}
    void add(IItem* item) {
        items.push_back(item);
    }
    int getSize() override {
        int size = 0;
        for (auto i : items) {
            size += i->getSize();
        }
        return size;
    }
    void print() override {
        cout << "[" << name << "]" << endl;
        for (auto i : items) {
            i->setIndent(indent + 1);
            for(int a=0; a<indent; a++)
                cout << "\t";
            i->print();
        }
    }
};

int main()
{
    // 조건1. Folder와 File의 객체를 생성할수 있어야 합니다.
    Folder* rootFolder = new Folder("ROOT");
    Folder* aaaaFolder = new Folder("AAAA");
    Folder* bbbbFolder = new Folder("BBBB");

    File* file1 = new File("a.txt", 10); // 파일은 이름과 크기가 있습니다.
    File* file2 = new File("b.txt", 20);
    File* file3 = new File("c.txt", 30);
    File* file4 = new File("d.txt", 40);
    
    // 조건2. 폴더 안에 파일 및 다른 폴더를 넣을 수 있어야 합니다.
    rootFolder->add(aaaaFolder);
    rootFolder->add(bbbbFolder);
    rootFolder->add(file1);

    aaaaFolder->add(file2);
    aaaaFolder->add(file3);
    
    bbbbFolder->add(file4);

    // 조건3. 파일과 폴더 크기를 출력할수 있어야 합니다.
    //       폴더는 자신만의 크기는 없지만 구할수는 있습니다.
    cout << file1->getSize()      << endl;  // 10
    cout << aaaaFolder->getSize() << endl;  // 50
    cout << rootFolder->getSize() << endl;  // 100

    // 조건4. 화면 출력
    file1->print();  // 파일이므로 이름과 크기만 출력해 주세요.
                     // ex) (a.txt, 10)

    rootFolder->print();  // ROOT 폴더 전체의 모양을 보기좋게 출력해 주세요.
                          // [ROOT]
                          //        [AAAA]
                          //            (b.txt, 20)
                          //            (b.txt, 30)
                          //        [BBBB]
                          //            (d.txt, 40)
                          //        (a.txt, 10)

    // 조건5. 폴더 제거시 폴더 안에 있는 모든 파일과 폴더가 제거되게 해주세요.
    delete rootFolder;
    return 0;
}