#ifndef CLASS_CPP
#define CLASS_CPP

#include "class.h"
#include <algorithm>
#include <cctype>

// 默认构造
// 这里的 "Person<T>::Person()" 意味着：
//  - 左侧的 "Person<T>" 指定了这是模板类 Person 在具体类型 T 下的一个实例化。
//  - 后面的 "::Person()" 指明我们在为这个特定的 Person<T> 类型，定义它的默认构造函数。
// 组合起来就是：为模板类 Person 针对类型 T，提供一个名为 Person 的构造函数实现。
// (Default constructor)
template<typename T>
Person<T>::Person()
    : name_(), email_(), age_(0) {}

// 带参构造
template<typename T>
Person<T>::Person(const T &name, const T &email, int age)
    : name_(name), email_(), age_(age)
{
    setEmail(email);
}
// getName
// 这里的 "const T& Person<T>::getName() const" 分解说明：
//  - "template<typename T>"：说明这是针对模板参数 T 的实现。
//  - "Person<T>::"：指明这是模板类 Person 在具体类型 T 下的成员。
//  - "getName()"：成员函数名，用于获取 name_。
//  - 返回类型 "const T&"：
//      * 引用 (&) 表示不拷贝，直接返回成员的别名。
//      * const 保证调用者不能通过此引用修改成员。
//  - 函数末尾的 const：保证此方法不会修改对象的任何成员。
template<typename T>
T Person<T>::getName() const {
    return name_;
}

// getEmail
template<typename T>
T Person<T>::getEmail() const {
    return email_;
}
// getAge
template<typename T>
int Person<T>::getAge() const {
    return age_;
}

// setEmail —— 内部调用 formatEmail
template<typename T>
void Person<T>::setEmail(const T &email) {
    email_ = formatEmail(email);
}

// formatEmail：转小写示例
template<typename T>
std::string Person<T>::formatEmail(const T &email) const {
    std::string tmp = email;
    std::transform(tmp.begin(), tmp.end(), tmp.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return tmp;
}

#endif