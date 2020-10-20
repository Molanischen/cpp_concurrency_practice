#include <iostream>
#include <thread> // 此头文件主要声明了std::thread线程类
#include <chrono>

void Hello()
{
    // sleep
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Hello World!" << std::endl;
}

int main()
{
    // create
    std::thread example(&Hello);

    // wait for end
    // 调用该函数会阻塞当前线程。阻塞调用者(caller)所在的线程直至被join的std::thread对象标识的线程执行结束
    example.join();

    return 0;
}

// mutex和std::lock_guard的使用
// 头文件是#include <mutex>，mutex是用来保证线程同步的，防止不同的线程同时操作同一个共享数据。
// 但使用lock_guard则相对安全，它是基于作用域的，能够自解锁，当该对象创建时，它会像m.lock()一样获得互斥锁，当生命周期结束时，它会自动析构(unlock)，不会因为某个线程异常退出而影响其他线程。示例：