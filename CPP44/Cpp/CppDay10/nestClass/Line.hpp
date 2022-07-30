#ifndef __WD_LINE_HPP__
#define __WD_LINE_HPP__

// 该头文件中看不到具体的Line的实现
// 只剩下接口
//
// 1. PIMP设计模式就完成了信息隐藏
// 2. 可以以最小的代价完成库的升级
// 当LineImple实现发生任何变化时，只要Line的接口保持不变
// 那库的使用者就不用重新编译代码
// 只需要用新的库文件替换旧的库文件，即可完成升级
class Line
{
public:
    Line(int x1, int y1, int x2, int y2);
    ~Line();
    void printLine() const;
private:
    class LineImpl; // 类的前向声明
    LineImpl * _pimpl; // 编译防火墙
};

#endif