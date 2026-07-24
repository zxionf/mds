#include "binary_tree.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace zx;

template <typename T>
void pre_order_recursive(const bin_tree<T> * const root)
{
    if (root == nullptr) return;
    std::cout << root->data << " ";
    pre_order_recursive(root->left);
    pre_order_recursive(root->right);
}

template <typename T>
void pre_order_iterative(const bin_tree<T> * const root)
{
    if (root == nullptr) return;
    std::stack<const bin_tree<T> *> stack;
    stack.push(root);
    while(!stack.empty())
    {
        auto cur = stack.top();
        stack.pop();
        std::cout << cur->data << " ";
        if (cur->right != nullptr) stack.push(cur->right);
        if (cur->left != nullptr) stack.push(cur->left);
    }
}

template <typename T>
void in_order_recursive(const bin_tree<T> * const root)
{
    if (root == nullptr) return;
    in_order_recursive(root->left);
    std::cout << root->data << " ";
    in_order_recursive(root->right);
}

template <typename T>
void in_order_iterative(const bin_tree<T> * const root)
{
    if (root == nullptr) return;
    std::stack<const bin_tree<T> *> stack;
    const bin_tree<T> *cur = root;
    while(cur != nullptr || !stack.empty())
    {
        // 将指针移动到最左边并且记录路径
        while(cur != nullptr)
        {
            stack.push(cur);
            cur = cur->left;
        }
        cur = stack.top();
        stack.pop();
        std::cout << cur->data << " ";
        cur = cur->right;
    }
}

template <typename T>
void post_order_recursive(const bin_tree<T> * const root)
{
    if (root == nullptr) return;
    post_order_recursive(root->left);
    post_order_recursive(root->right);
    std::cout << root->data << " ";
}

template <typename T>
void post_order_iterative(const bin_tree<T> * const root)
{
    if (root == nullptr) return;
    std::stack<const bin_tree<T> *> stack;
    const bin_tree<T> *cur = root;
    const bin_tree<T> *pre = nullptr;
    while (cur != nullptr || !stack.empty())
    {
        while (cur != nullptr)
        {
            stack.push(cur);
            cur = cur->left;
        }
        auto top = stack.top();
        if (top->right != nullptr && top->right != pre)
        {
            cur = top->right;
        }
        else
        {
            std::cout << top->data << " ";
            pre = top;
            stack.pop();
        }
    }
}

template <typename T>
int get_tree_depth(const bin_tree<T> * const root)
{
    if (root == nullptr) return 0;
    return std::max(get_tree_depth(root->left), get_tree_depth(root->right)) + 1;
}

template <typename T>
void level_order(const bin_tree<T> * const root)
{
    if (root == nullptr) return;
    std::queue<const bin_tree<T> *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        auto cur = queue.front();
        queue.pop();
        std::cout << cur->data << " ";
        if (cur->left != nullptr) queue.push(cur->left);
        if (cur->right != nullptr) queue.push(cur->right);
    }
}

int main()
{
    bin_tree<char> *root = new bin_tree<char>('A',
        new bin_tree<char>('B',
            new bin_tree<char>('D'),
            nullptr),
        new bin_tree<char>('C',
            new bin_tree<char>('E'),
            new bin_tree<char>('F')));
    //           A
    //          / \
    //         B   C
    //        /   / \
    //       D   E   F
    std::cout << "pre order: \n";
    pre_order_recursive(root);
    std::cout << std::endl;
    // A B D C E F
    pre_order_iterative(root);
    std::cout << '\n' << std::endl;

    std::cout << "in order: \n";
    in_order_recursive(root);
    std::cout << std::endl;
    // D B A E C F
    in_order_iterative(root);
    std::cout << '\n' << std::endl;

    std::cout << "post order: \n";
    post_order_recursive(root);
    std::cout << std::endl;
    // D B E F C A
    post_order_iterative(root);
    std::cout << '\n' << std::endl;

    std::cout << "level order: \n";
    level_order(root);
    std::cout << '\n' << std::endl;

    std::cout << "tree depth: " << get_tree_depth(root) << std::endl;
}