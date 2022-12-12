#include <iostream>

using namespace::std;
constexpr auto SPACE = 10;


template <class T>
class tree_element {
    public:
        T value;
        struct tree_element* left;
        struct tree_element* right;
    tree_element* create_tree_element(T i);
    void insert_into_tree(tree_element* root, tree_element* elem);
    void print_tree(tree_element* cur_elem);
    tree_element* del_elem(tree_element* root, T aData);
    void print2D(tree_element* root, int space);
};


template <class T>
tree_element<T>* create_tree_element(T i) {
    tree_element<T>* elem = new tree_element<T>;
    elem->value = i;
    elem->left = nullptr;
    elem->right = nullptr;
    return elem;
}


template <class T>
//Добавление элемента в дерево
void insert_into_tree(tree_element<T>* root, tree_element<T>* elem) {
    if (elem->value < root->value) {
        if (root->left == nullptr) {
            root->left = elem;
        }
        else {
            insert_into_tree(root->left, elem);
        };
    }
    else {
        if (root->right == nullptr) {
            root->right = elem;
        }
        else {
            insert_into_tree(root->right, elem);
        }
    }
}
template <class T>
//стандартная печать дерева
void print_tree(tree_element<T>* cur_elem) {
    if (cur_elem->left != nullptr) {
        print_tree(cur_elem->left);
    }
    std::cout << "Value " << cur_elem->value << std::endl;
    if (cur_elem->right != nullptr) {
        print_tree(cur_elem->right);
    }
}


//удаление элемента
template <class T>
tree_element<T>* del_elem(tree_element<T>* root, T aData) {
    if (root == NULL)
        return root;
    if (aData == root->value) {
        tree_element<T>* tmp;
        if (root->right == NULL)
            tmp = root->left;
        else {
            tree_element<T>* ptr = root->right;
            if (ptr->left == NULL) {
                ptr->left = root->left;
                tmp = ptr;
            }
            else {
                tree_element<T>* pmin = ptr->left;
                while (pmin->left != NULL) {
                    ptr = pmin;
                    pmin = ptr->left;
                }
                ptr->left = pmin->right;
                pmin->left = root->left;
                pmin->right = root->right;
                tmp = pmin;
            }
        }
        delete root;
        return tmp;
    }
    else if (aData < root->value)
        root->left = del_elem(root->left, aData);
    else
        root->right = del_elem(root->right, aData);
    return root;
}

template <class T>
void print2D(tree_element<T>* root, int space) {
    if (root == nullptr)
        return;
    space += SPACE;
    print2D(root->right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
        cout << " ";
    cout << root->value << "\n";
    print2D(root->left, space);
};



int main() {
    //корень
    tree_element<float>* root = create_tree_element((float)2.1);
    //добавляем элементы,то что при создании - и есть часть шаблонного программирования

    tree_element<float>* el = create_tree_element((float)4.5);
    insert_into_tree(root, el);


    tree_element<float>* el1 = create_tree_element((float)7.4);
    insert_into_tree(root, el1);

    tree_element<float>* el2 = create_tree_element((float)11.23);
    insert_into_tree(root, el2);

    tree_element<float>* el3 = create_tree_element((float)134.435);
    insert_into_tree(root, el3);

    del_elem(root, (float)4.5);
    print_tree(root);
    print2D(root, 1);
}
