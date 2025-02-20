#ifndef THREADPOOL_H
#define THREADPOOL_H

#include "TaskQueue.h"
#include <thread>
#include <mutex>


class ThreadPool {
public:
    ThreadPool(TaskQueue&,int);
    ~ThreadPool();
    void Worker();

private:
    TaskQueue& _taskQueue;
    std::vector<std::thread> _workers;
    std::mutex mtx;
    int _numThreads;
    bool stop = false;
};


#endif