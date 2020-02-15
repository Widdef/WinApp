#pragma once
#include <thread>
#include "threadListClass.h"
#include <atomic>

std::atomic<bool> gameScreenThread(true);
std::thread* menuThread;
std::thread* windowThread;


//threadList thStatus;
