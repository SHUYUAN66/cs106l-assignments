#ifndef CLASS_H
#define CLASS_H

#include <string>
// 通用模板类声明
template<typename T>
class Person {
public:
    // 默认构造
    // 提供一个无参版本，使得可以创建一个初始值已定义的 Person 对象，
    // 例如放入容器时无需立即提供 name/email/age。
    Person();
    // 自定义构造
    // 这里 name 和 email 用 const T& 传参：
    //  - 避免拷贝开销（按引用传递）
    //  - const 保证函数内部不会修改外部对象
    // age 用 int 值传递：
    //  - 基本类型传值开销极小，按值更直观
    Person(const T &name, const T &email, int age);
    // getters
    // 1) 返回 T （按值）
    //    - 会返回成员的拷贝，调用者可安全持有，不会受到原对象生命周期限制。
    //    - 适合 T 类型较小或需要独立副本的场景。
    // 2) 返回 const T& （按引用，常量引用）
    //    - 返回对成员的只读引用，避免了拷贝开销。
    //    - 要确保返回值在原对象生命周期内有效，否则会悬空引用。
    // 根据测试要求，使用返回 T 的签名；如需引用，可改为 'const T& getName() const'。
    T getName() const;
    T getEmail() const;
    int getAge() const;
    

    // setter
    void setEmail(const T &email);
    // 1. 避免对传入参数做不必要的拷贝（按引用传递），
    // 2. const 保证你在函数内部不会修改调用者传进来的对象。
    // 不推荐写成 void setEmail(T email) const 或类似带 const 的签名，因为：
        // 1. Setter 本就要修改内部状态，它自身不应该是 const 方法。
        // 2. 参数可以按值或按引用传入，但方法尾部加 const 会阻止它修改 this 对象，这和 setter 的初衷相冲突。
private:
    T    name_;
    T    email_;
    int  age_;

    // 私有工具函数：示例格式化邮箱
    std::string formatEmail(const T &email) const;
};
// Getter 可根据需要返回 T 或 const T&，两者语义都对；
// Setter 参数用 const T& 很常见，但方法本身不能加尾部 const，因为它要修改成员。
       


#include "class.cpp"
#endif