namespace zx
{
    template <typename T>
    class bin_tree
    {
        public:
            T data;
            bin_tree* left{nullptr};
            bin_tree* right{nullptr};
            bin_tree() = default;
            bin_tree(const T& data) : data{data} {}
            bin_tree(const T& data, bin_tree* l, bin_tree* r): data(data), left(l), right(r) {}
            ~bin_tree()
            {
                if (left != nullptr) delete left;
                if (right != nullptr) delete right;
            }
    };
}
