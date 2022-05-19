/*
 * @Author: linkenzone
 * @Date: 2022-04-15 16:32:09
 * @Descripttion: Do not edit
 */

#include <iostream>
#include <vector>

using namespace std;

class TextBlock
{
public:
    TextBlock(const string& str){
        text = str;
    }
    const char &operator[](size_t pos) const
    {
        cout << "const 版本 operator[]" << endl;
        return text[pos];
    }

    char &operator[](size_t pos)
    {
        cout << "operator[]" << endl;
        return text[pos];
    }

private:
    string text;
};

void print(const TextBlock& ctb)
{
    cout << ctb[0];
}

int main()
{
    //* --- const_iterator 的使用 ---
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    const vector<int>::iterator iter = vec.begin(); //* iter 的作用像 T* const
    *iter = 10;
    // ++iter; //! 错误的！iter 是 const

    std::vector<int>::const_iterator cIner = vec.begin(); //* cIter的作用像个 const T*
    //! 错误的！ *cIter 是 const
    // *cIner = 10;
    ++cIner; // 没问题，改变 cIter

    //* --- const 成员函数 ---
    TextBlock tb("Hello");
    print(tb);

}