struct tree_node
{
    int val;
    tree_node* left;
    tree_node* right;
    tree_node():val(0), left(nullptr), right(nullptr){}
    tree_node(int value): val(value), left(nullptr), right(nullptr){}
    tree_node(int value, tree_node* _left, tree_node* _right):val(value),left(_left), right(_right){}
};
