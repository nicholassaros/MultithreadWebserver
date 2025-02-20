#include "ThreadPool.h"
#include "TaskQueue.h"

#include <thread>
#include <mutex>
#include <functional>

using namespace std;


ThreadPool::ThreadPool(TaskQueue& taskQueue, int numThreads)
    : _taskQueue(taskQueue), _numThreads(numThreads) {

        for(int i = 0; i<_numThreads; i++){
            // add thread to the workers vector
            _workers.push_back(thread(&ThreadPool::Worker, this));
        }
    }

void ThreadPool::Worker(){
    while(true){
        function<void()> task = _taskQueue.TaskPop();

        unique_lock<mutex> lock(mtx);
        if(stop && !task){
            return;
        }

        task();
    }
}

ThreadPool::~ThreadPool(){
    unique_lock<mutex> lock(mtx);
    stop = true;
    _taskQueue.NotifyAll();
    lock.unlock();

    for(auto& worker : _workers){
        worker.join();
    }
}