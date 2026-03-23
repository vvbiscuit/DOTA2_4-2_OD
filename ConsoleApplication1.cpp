#include <windows.h>
#include <iostream>
#include <random>

/**
 * 模拟鼠标滚轮滚动
 * @param delta 滚动量，正数向上滚动，负数向下滚动。通常一个刻度为 120。
 */
void SimulateMouseWheel(int delta)
{
    // 初始化一个 INPUT 结构，类型为鼠标输入
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL; // 滚轮事件
    input.mi.mouseData = delta;           // 滚动量

    // 发送输入事件
    UINT sent = SendInput(1, &input, sizeof(INPUT));
    if (sent != 1)
    {
        std::cerr << "发送输入失败，错误码：" << GetLastError() << std::endl;
    }
}

int main()
{
    // 随机数引擎（使用真随机数种子）
    std::random_device rd;
    std::mt19937 gen(rd());

    // 定义整数分布，范围 [min, max]
    int min = 8, max = 30;
    std::uniform_int_distribution<int> dis(min, max);

    while (true)
    {
        // 生成随机数1
        int random_num_1 = dis(gen);
        // std::cout << "模拟鼠标向上滚动一个刻度（120）..." << std::endl;
        Sleep(15);
        SimulateMouseWheel(120 * random_num_1); // 向上滚动
        // std::cout << "random_num_1 = " << random_num_1 << std::endl;

        // Sleep(1000);  // 暂停 1 秒

        // 生成随机数2
        int random_num_2 = dis(gen);
        // std::cout << "模拟鼠标向下滚动一个刻度（-120）..." << std::endl;
        Sleep(15);
        SimulateMouseWheel(-120 * random_num_2); // 向下滚动
        // std::cout << "random_num_2 = " << random_num_2 << std::endl;
    }

    return 0;
}