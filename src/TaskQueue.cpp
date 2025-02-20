#include "TaskQueue.h"
#include <iostream>

#include <functional>
#include <mutex>
#include <queue>
#include <condition_variable>


using namespace std;



void TaskQueue::TaskPush(function<void()> task){
    lock_guard<mutex> lock(_queueMutex); // thread will take lock
    _queue.push(task); 
    _cv.notify_one(); // notify thread to wake up, lock lost when out of scope
}


function<void()> TaskQueue::TaskPop(){
    unique_lock<mutex> lock(_queueMutex); // thread aquires lock

    while(_queue.empty()){
        _cv.wait(lock); // if queue is empty thread releases lock
    }

    function<void()> task = _queue.front();
    _queue.pop();
    return task;
}

void TaskQueue::NotifyAll(){
    _cv.notify_all();
}