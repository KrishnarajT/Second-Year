#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;

class WordNode
{
    string word;
    string definition;
    WordNode *left;
    WordNode *right;
    friend class BinarySearchTree;
};

class BinarySearchTree
{
public:
    WordNode *root;
    BinarySearchTree()
    {
        root = NULL;
    }
    void create_root()
    {
        root = new WordNode;
        cout << "Enter the data: " << endl;
        cin >> root->word;
        cin >> root->definition;
        root->left = NULL;
        root->right = NULL;
        create_recursive(root);
    }
    void create_recursive(WordNode *Node)
    {
        int choice = 0;
        WordNode *new_node;
        cout << "Enter if you want to enter a left node (1/0): "
             << "for the node -- " << Node->word << ":  " << Node->definition << "-- ";
        cin >> choice;
        if (choice == 1)
        {
            new_node = new WordNode;
            cout << "Enter the data: ";
            cin >> new_node->word;
            cin >> new_node->definition;
            Node->left = new_node;
            create_recursive(new_node);
        }
        cout << "Enter if you want to enter a right node (1/0): "
             << "for the node -- " << Node->word << ":  " << Node->definition << "-- ";
        cin >> choice;
        if (choice == 1)
        {
            new_node = new WordNode;
            cout << "Enter the data: ";
            cin >> new_node->word;
            cin >> new_node->definition;
            Node->right = new_node;
            create_recursive(new_node);
        }
    }
    void create_root_and_tree_iteratively()
    {
        WordNode *temp, *current_word;
        int choice = 0;
        root = new WordNode;
        cout << "Enter the Word: ";
        cin >> root->word;
        cout << "Enter the definition of the word: ";
        cin >> root->definition;
        bool flag = false;
        cout << "Do you want to enter more Nodes? (0/1) " << endl;
        cin >> choice;
        while (choice == 1)
        {
            temp = root;
            flag = false;
            current_word = new WordNode;
            cout << "Enter the Word: ";
            cin >> current_word->word;
            cout << "Enter the definition of the word: ";
            cin >> current_word->definition;

            while (!flag)
            {
                if (strcmp(current_word->word.c_str(), temp->word.c_str()) < 0)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = current_word;
                        flag = true;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = current_word;
                        flag = true;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
            cout << "Do you want to enter another word? (1/0): ";
            cin >> choice;
        }
    }

    // breadth First Search using queue.
    void bfs()
    {
        WordNode *temp = root;
        queue<WordNode *> q;
        q.push(temp);
        while (!q.empty())
        {
            temp = q.front();
        
            cout << temp->word << " : " << temp->definition << endl;
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }

    WordNode *create_copy_recursive(WordNode *temp)
    {
        if (temp == NULL)
        {
            return NULL;
        }
        else
        {
            WordNode *new_node = new WordNode;
            new_node->word = temp->word;
            new_node->definition = temp->definition;
            new_node->left = create_copy_recursive(temp->left);
            new_node->right = create_copy_recursive(temp->right);
            return new_node;
        }
    }

    void mirror_recursive(WordNode *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        else
        {
            WordNode *temp1;
            // Swapping
            temp1 = temp->left;
            temp->left = temp->right;
            temp->right = temp1;

            // Recursively calling the function
            mirror_recursive(temp->left);
            mirror_recursive(temp->right);
        }
    }

    WordNode *create_mirror_tree_recursive()
    {
        WordNode *mirror_tree = create_copy_recursive(root);
        mirror_recursive(mirror_tree);
        return mirror_tree;
    }

    void inorder_iterative(WordNode *temp)
    {
        if (!temp)
        {
            return;
        }

        stack<WordNode *> s;
        WordNode *current = temp;

        while (current != NULL || s.empty() == false)
        {
            while (current != NULL)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->word << " : " << current->definition << endl;
            current = current->right;
        }
    }
    void preorder_iterative(WordNode *temp)
    {
        if (!temp)
        {
            return;
        }

        stack<WordNode *> s;
        s.push(temp);

        while (s.empty() == false)
        {
            WordNode *current = s.top();
            cout << current->word << " : " << current->definition << endl;
            s.pop();

            if (current->right)
            {
                s.push(current->right);
            }
            if (current->left)
            {
                s.push(current->left);
            }
        }
    }
    void postorder_iterative(WordNode *temp)
    {
        if (!temp)
        {
            return;
        }

        stack<WordNode *> s1;
        stack<WordNode *> s2;

        s1.push(temp);

        while (s1.empty() == false)
        {
            WordNode *current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left)
            {
                s1.push(current->left);
            }
            if (current->right)
            {
                s1.push(current->right);
            }
        }
        while (s2.empty() == false)
        {
            WordNode *current = s2.top();
            cout << current->word << " : " << current->definition << endl;
            s2.pop();
        }
    }
};

int main()
{
    int choice = 0;
    BinarySearchTree main_tree, mirror_tree, copy_tree;

    while (choice != 8)
    {
        cout << "\nWhat would like to do? " << endl;
        cout << "\n\nWelcome to ADS Assignment 2 - Binary Tree Traversals\n\nWhat would you like to do? " << endl;
        cout << "1. Create a Binary Search Tree"
             << endl;
        cout << "2. Traverse the Tree Inorder Iteratively"
             << endl;
        cout << "3. Traverse the Tree PreOrder Iteratively"
             << endl;
        cout << "4. Traverse the Tree PostOrder Iteratively"
             << endl;
        cout << "5. Traverse it using BFS"
             << endl;
        cout << "6. Create a Copy of the tree Recursively"
             << endl;
        cout << "7. Create a Mirror of the Tree Recursively"
             << endl;
        cout << "8. Exit" << endl
             << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            main_tree.create_root_and_tree_iteratively();
            break;
        case 2:
            cout << "Traversing through the Binary Tree Inorder Iteratively: " << endl;
            main_tree.inorder_iterative(main_tree.root);
            break;
        case 3:
            cout << "Traversing through the Binary Tree PreOrder Iteratively: " << endl;
            main_tree.preorder_iterative(main_tree.root);
            break;
        case 4:
            cout << "Traversing through the Binary Tree PostOrder Iteratively: " << endl;
            main_tree.postorder_iterative(main_tree.root);
            break;
        case 5:
            cout << "Traversing through the Binary Tree using BFS: " << endl;
            main_tree.bfs();
            break;
        case 6:
            cout << "Creating a copy of the tree" << endl;
            copy_tree.root = copy_tree.create_copy_recursive(main_tree.root);
            cout << "Traversing through the Binary Tree Inorder Iteratively: " << endl;
            copy_tree.inorder_iterative(copy_tree.root);
            cout << "Traversing via Breadth First Search: " << endl;
            copy_tree.bfs();
            break;
        case 7:
            cout << "Creating a mirror of the tree" << endl;
            mirror_tree.root = main_tree.create_mirror_tree_recursive();
            cout << "Traversing through the Binary Tree Inorder Iteratively: " << endl;
            mirror_tree.inorder_iterative(mirror_tree.root);
            cout << "Traversing via Breadth First Search: " << endl;
            mirror_tree.bfs();
            break;
        case 8:
            cout << "Exiting the program" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}
