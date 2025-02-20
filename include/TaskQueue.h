#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>


class TaskQueue {
private:
    std::queue<std::function<void()>> _queue; // holds tasks
    std::condition_variable _cv;
    std::mutex _queueMutex; // locks queue so only one thread can access

public:
    void TaskPush(std::function<void()>);
    std::function<void()> TaskPop();
    void NotifyAll();

};

#endif