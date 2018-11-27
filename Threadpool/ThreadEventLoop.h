#pragma once

#include "../Reactor/EventLoop.h"
#include "Thread.h"
#include <vector>

class ThreadEventLoop{
private:
	SP_EventLoop loop;
	UP_Thread thread;
	void Loop();

public:
	static void* operator new(size_t size){
		return use_memory(2);
	}

	static void operator delete(void *p){
		free_memory(2,p);
	}
	ThreadEventLoop();
	~ThreadEventLoop();
	void start();
	SP_EventLoop getLoop();
};

typedef std::shared_ptr<ThreadEventLoop> SP_ThreadEventLoop;
