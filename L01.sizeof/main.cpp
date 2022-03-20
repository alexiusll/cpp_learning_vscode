/*
 * @Author: linkenzone
 * @Date: 2022-03-15 16:09:48
 * @Descripttion: Do not edit
 */
#include <iostream>

using namespace std;

class class_test_01 {
  virtual void func(){};
};

class class_test_02 {
  virtual void func(){};
  virtual void func02(){};
};

class class_test_03 {
  virtual void func(){};
  virtual void func02(){};

private:
  int n = 0;
  double m = 0;
};

class class_test_noV {
  void func(){};
  void func02(){};
};

class class_test_empty {};

class class_v_son : public class_test_01 {};

class class_son : public class_test_noV {};

struct struct_01 {
  int a;
  void *b;
};

struct struct_02 {
  int a;
  int b;
};

struct struct_03 {
  double a;
  short b;
};

struct struct_04 {
  double a; // 8
  int b; // 4
  char c; // 1 
};

int main() {
  int *a;
  void *point_void;

  *a = 1;

  short short_num = 1;
  float float_num = 0.1;
  double double_num = 0.1;
  long long_num = -1;
  long long long_long_num = -1;
  char char_c = 'c';
  char char_c_list[] = "hello world ";
  int int_num_list[3];
  unsigned int us_int = 1;

  cout << "--- point ---" << endl;
  cout << "int*:" << sizeof(a) << endl;
  cout << "point_void:" << sizeof(point_void) << endl;

  cout << "--- num ---" << endl;
  cout << "int:" << sizeof(*a) << endl;
  cout << "short:" << sizeof(short_num) << endl;
  cout << "float:" << sizeof(float) << endl;
  cout << "double:" << sizeof(double_num) << endl;
  cout << "long:" << sizeof(long_num) << endl;
  cout << "long long:" << sizeof(long_long_num) << endl;
  cout << "unsigned int:" << sizeof(us_int) << endl;


  cout << "--- char ---" << endl;
  cout << "char:" << sizeof(char_c) << endl;

  cout << "--- char[] ---" << endl;
  cout << "char[]:" << sizeof(char_c_list) << endl;

  cout << "--- int[] ---" << endl;
  cout << "int[]:" << sizeof(int_num_list) << endl;

  cout << "--- 类 ---" << endl;
  cout << "空类大小:" << sizeof(class_test_empty) << endl;
  cout << "无虚函数 的类大小:" << sizeof(class_test_noV) << endl;
  cout << "1个虚函数 类大小:" << sizeof(class_test_01) << endl;
  cout << "2个虚函数 类大小:" << sizeof (class_test_02) << endl;
  cout << "2个虚函数 + 部分数据 类大小:" << sizeof(class_test_03) << endl;

  cout << "继承：无虚函数 类大小:" << sizeof(class_son) << endl;
  cout << "继承：2个虚函数 类大小:" << sizeof(class_v_son) << endl;

  cout << "--- 字节对齐 ---" << endl;
  cout << "int 和 void*:" << sizeof(struct_01) << endl;
  cout << "int 和 int:" << sizeof(struct_02) << endl;
  cout << "double 和 short:" << sizeof(struct_03) << endl;
  cout << "double 和 int 和 char:" << sizeof(struct_04) << endl;
  
}