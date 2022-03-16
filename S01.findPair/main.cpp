/*
 * @Author: linkenzone
 * @Date: 2022-03-15 09:49:16
 * @Descripttion: Do not edit
 */

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &input){
    cout << '[';
    for (auto i: input)
        cout << i << ',';

    cout << ']' << endl;
}

void input_test_data(vector<int> &input){
    vector<int> _input = {1,2,3,4,5};
    input.swap(_input);
}

int main(){
    vector<int> input;
    input_test_data(input);

    // 打印数据
    print(input);

}
