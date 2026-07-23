#include <iostream>
#include <format>
#include <vector>
#include <assert.h>

namespace zx
{
    template <typename T, typename Comparator = std::less<T>>
    class priority_queue
    {
    private:
        std::vector<T> _vec;
        Comparator cmp;
        void _make()
        {
            // _percolate_up(, , );
        }
        void _percolate_up(const int pos)
        {
            int cur_pos = pos;
            int parent_pos = (cur_pos - 1) / 2;
            while (cur_pos > 0 && !cmp(_vec[cur_pos], _vec[parent_pos]))
            {
                std::swap(_vec[cur_pos],_vec[parent_pos]);

                cur_pos = parent_pos;
                parent_pos = (cur_pos - 1) / 2;
            }
            
        }
        void _percolate_down()
        {
            int cur_pos = 0;
            int child_pos = cur_pos * 2 + 1;
            while(child_pos < _vec.size())
            {
                // 定位到更大的孩子
                if (child_pos + 1 < _vec.size() && cmp(_vec[child_pos], _vec[child_pos+1]))
                {
                    ++ child_pos;
                }

                // 如果孩子更小则已经满足堆结构
                if (!cmp(_vec[cur_pos], _vec[child_pos])) return;

                std::swap(_vec[cur_pos],_vec[child_pos]);

                cur_pos = child_pos;
                child_pos = cur_pos  * 2 + 1;
            }
        }
    public:
        void push(T t)
        {
            _vec.push_back(t);
            _percolate_up(_vec.size()-1);
        }
        void pop()
        {
            assert(_vec.size() > 0);

            std::swap(_vec[0], _vec[_vec.size()-1]);
            _vec.pop_back();
            if(!_vec.empty()) _percolate_down();
        }
        T first()
        {
            assert(_vec.size() > 0);

            return _vec[0];
        }
    };
}

int main()
{
    zx::priority_queue<int, std::greater<int>> que;
    que.push(2);
    que.push(3);
    std::cout << std::format("{}\n", que.first());
    que.pop();
    std::cout << std::format("{}\n", que.first());
}
