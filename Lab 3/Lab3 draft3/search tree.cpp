#include <iostream>
#include <iomanip>
#include <fstream>

struct student {
    static bool isBooksTakenAKey;

    std::string name;
    int booksTaken;
    int ticketNumber;
    student() {
        name = "";
        ticketNumber = 0;
        booksTaken = 0;
    }
    void set(std::string name, int booksTaken, int ticketNumber) {
        this->name = name;
        this->booksTaken = booksTaken;
        this->ticketNumber = ticketNumber;
    }
    void changeKey() {
        isBooksTakenAKey = !isBooksTakenAKey;
    }
    friend std::ostream& operator << (std::ostream& os, const student& dt) {
        os << std::setw(20) << dt.name << "\t" << dt.ticketNumber << "\t" << dt.booksTaken;
        return os;
    }
    bool operator >(student field) {
        if(isBooksTakenAKey)
            return this->booksTaken > field.booksTaken;
        else 
            return this->ticketNumber > field.ticketNumber;
    }
};

bool student::isBooksTakenAKey = true;

class node {
    student data;
    node* leftBranch;
    node* rightBranch;
public:
    node();
    void friend insert(node*& node, student data);
    void friend show(node* node, int level);
    void friend preOrder(node* node);
    void friend postOrder(node* node);
    void friend postOrder(node* node);
    void friend symmetricOrder(node* node);
    void friend erase(node* node);
    void friend toFileHelper(node* node, std::fstream& file);
    void friend toFile(node* node, std::string filename);
};

node::node()
{
    data;
    leftBranch = nullptr;
    rightBranch = nullptr;
}

void insert(node*& root, student data) {
    if (root == nullptr) {
        root = new node;
        root->data = data;
        root->leftBranch = nullptr;
        root->rightBranch = nullptr;
    }
    else {
        if (root->data > data) {
            insert(root->leftBranch, data);
        }
        else {
            insert(root->rightBranch, data);
        }
    }
}

void show(node* node, int level = 0)
{
    if (node) {
        show(node->rightBranch, level + 1);
        for (int i = 0; i < level; i++)
            std::cout << "\t\t";
        std::cout << node->data.booksTaken << "|" << node->data.ticketNumber << std::endl;
        show(node->leftBranch, level + 1);
    }
}

void preOrder(node* node) {
    if (node != nullptr) {
        std::cout << node->data << std::endl;
        preOrder(node->leftBranch);
        preOrder(node->rightBranch);
    }
}

void postOrder(node* node) {
    if (node != nullptr) {
        postOrder(node->leftBranch);
        postOrder(node->rightBranch);
        std::cout << node->data << std::endl;
    }
}

void symmetricOrder(node* node) {
    if (node != nullptr) {
        symmetricOrder(node->leftBranch);
        std::cout << node->data << std::endl;
        symmetricOrder(node->rightBranch);
    }
}

void erase(node* node)
{
    if (!node)
        return;
    erase(node->leftBranch);
    erase(node->rightBranch);
    delete node;
    return;
}

void fill_default(node*& node) {
    std::string namesArray[] = { "Clint Clark", "Prince Chaney", "Ashton Patterson", "Marshall Dickson", "Ashley Johns", "Simeon Frey", "Valentine Koch", "Elsworth Vaughn", "Stephen Clements", "Hays Petty" };
    int booksTakenArray[] = { 67, 76, 37, 34, 57, 13, 4, 10, 99, 74 };
    int ticketNumberArray[] = { 2401, 9587, 2793, 2963, 2237, 0240, 1936, 8369, 6468, 0714 };
    student temp;

    for (int i{}; i < 10; i++) {
        temp.set(namesArray[i], booksTakenArray[i], ticketNumberArray[i]);
        insert(node, temp);
    }
}

void clone(node*& from, node*& to) {
    student temp;
    temp.changeKey();
    fill_default(to);
    erase(from);
}

void toFileHelper(node* pnode, std::fstream& file) {
    if (pnode != nullptr) {
        file << pnode->data << "\n";
        toFileHelper(pnode->leftBranch, file);
        toFileHelper(pnode->rightBranch, file);
    }
}

void toFile(node* pnode, std::string filename = "file.txt") {
    std::fstream file(filename);
    toFileHelper(pnode, file);
    file.close();
}

void menu() {
    std::cout << "1 - Insert " << "\n";
    std::cout << "2 - Post Order" << "\n";
    std::cout << "3 - Pre Order" << "\n";
    std::cout << "4 - Symmetric Order" << "\n";
    std::cout << "5 - Clone" << "\n";
    std::cout << "6 - To File" << "\n";
}

int main()
{    
    node* root = nullptr;
    node* root2 = nullptr;

    short op{};
    short op2{};
    bool run = true;

    student t;
    std::string name;
    int books{};
    int ticket{};

    std::cout << "1 - Default (fill from arrays, cloning and printin cloned tree, save to file)" << std::endl;
    std::cout << "2 - Manually " << std::endl;
    std::cin >> op;

    switch (op) {
    case 1:
        fill_default(root);
        clone(root, root2);
        show(root2);
        toFile(root2);
        erase(root2);
        break;
    case 2:
        while (run) {
            menu();
            switch (op)
            {
            case 1:
                std::cout << "Enter name > ";
                std::cin >> name;
                std::cout << "Enter how many books taken > ";
                std::cin >> books;
                std::cout << "Enter ticket number > ";
                std::cin >> ticket;
                
                t.set(name, books, ticket);
                insert(root, t);
                break;
            case 2:
                postOrder(root);
                break;
            case 3:
                preOrder(root);
                break;
            case 4:
                symmetricOrder(root);
                break;
            case 5:
                clone(root, root2);
                break;
            case 6:
                toFile(root2);
            default:
                break;
            }
        }
    }
}