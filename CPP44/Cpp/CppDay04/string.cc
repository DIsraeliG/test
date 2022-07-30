    #include <iostream>
    #include <string>

    using std::cout;
    using std::endl;
    using std::string;

    void test0()
    {
        string s1; // 默认初始化，s1是一个空字符串
        cout << "s1: " << s1 << endl;
        cout << "s1.size(): " << s1.size() << endl; // 返回s1中字符的个数
        cout << "s1.empty(): " << s1.empty() << endl; // 判断字符串是否为空
        
        // 将C风格字符串转换成C++风格字符串
        string s2("hello"); // 直接初始化
        cout << "s2: " << s2 << endl;
        cout << "s2.length(): " << s2.length() << endl; // 返回字符串的长度
        cout << "s2.empty(): " << s2.empty() << endl;

        string s3 = "world"; // 拷贝初始化
        cout << "s3: " << s3 << endl;

        cout << (s2 != s3) << endl;

        cout << "执行加法操作" << endl;
        string s4 = s2 + "wuhan" + s3; // 字符串拼接操作
        cout << "s4: " << s4 << endl;

        cout << "执行附加操作" << endl;
        s2.append(s3); // 字符串append(附加)操作
        s2.append(10, 'a');
        s2.append(",wuhan");
        cout << "s2: " << s2 << endl;

        // 将C++风格的字符串转换成C风格的字符串
        cout << "转换成C风格字符串操作" << endl;
        printf("s4: %s\n", s4.c_str());
        printf("s4: %s\n", s4.data());

        cout << endl << "C++风格字符串用下标访问某一个字符" << endl;
        for(size_t idx = 0; idx < s4.size(); ++idx){
            cout << s4[idx] << " ";
        }
        cout << endl; 

        // 遍历元素
        cout << endl << "C++风格字符串增强for循环" << endl;
        // auto关键字表示自动进行推导
        // & 引用符号：直接操作元素本身；如果没有使用引用，就会进行复制，操作的是副本
        // 冒号左边表示任一元素，右边表示容器
        for(auto & ch : s4){
            cout << ch << " ";
        }
        cout << endl;

        // 迭代器简单理解，就是指针
        cout << endl << "C++风格字符串迭代器访问" << endl;
        auto it = s4.begin();
        while(it != s4.end()){
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        cout << endl << "C++风格字符串进行子串截取操作" << endl;
        string s5 = s4.substr(5, 5);
        cout << "s5: " << s5 << endl;

        auto pos = s4.find("world");
        cout << "pos: " << pos << endl;
        pos = s4.find(s5);
        cout << "pos: " << pos << endl;
    }

    int main()
    {
        test0();
        return 0;
    }