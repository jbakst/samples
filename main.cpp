/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jbakst
 *
 * Created on October 18, 2017, 6:58 PM
 */

#include <cstdlib>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

std::future<void> task;

void doBackgroundTask() {
    std::cout << "doBackgroundTask" << "\n";
    std::this_thread::sleep_for(2s);
}

std::future<void> doTask() {
    //task = std::async(std::launch::async, [](){doBackgroundTask();});
    return std::async(std::launch::async, []() {
        doBackgroundTask();
    });
}

/*
 * 
 */
int main(int argc, char** argv) {

    std::cout << "starting task" << "\n";
    std::future<void> t = doTask();
    std::cout << "task started" << "\n";
    t.wait();
    std::cout << "task ended" << "\n";

    return 0;
}