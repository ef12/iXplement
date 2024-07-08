---
title: main
---
# Introduction

This document will walk you through the implementation of the main function in the <SwmPath>[Core/Src/main.cpp](/Core/Src/main.cpp)</SwmPath> file.

The main function is the entry point of the application and is responsible for initializing the peripherals, the application, and starting the operating system kernel.

We will cover:

1. Why the peripherals are initialized first.


2. The purpose of initializing the application.


3. The reason for starting the operating system kernel.


4. Why there is an infinite loop at the end of the main function.

# Initializing the peripherals

The first operation in the main function is the initialization of the peripherals. This is done by calling the <SwmToken path="/Core/Src/main.cpp" pos="35:1:3" line-data="  peripherals_init();">`peripherals_init()`</SwmToken> function. This is important because the peripherals (like GPIOs, UARTs, etc.) need to be set up before they can be used by the application. This setup usually involves configuring the peripheral's registers and enabling it.

# Initializing the application

After the peripherals have been initialized, the application is initialized by calling the <SwmToken path="/Core/Src/main.cpp" pos="36:1:3" line-data="  app_init();">`app_init()`</SwmToken> function. This function is responsible for setting up the application-specific resources and tasks. It is important to initialize the application after the peripherals because the application might depend on the peripherals being ready.

# Starting the operating system kernel

Once the peripherals and the application have been initialized, the operating system kernel is started by calling the <SwmToken path="/Core/Src/main.cpp" pos="37:1:3" line-data="  osKernelStart();">`osKernelStart()`</SwmToken> function. This function starts the scheduler of the operating system, which in turn starts executing the tasks that were created during the application initialization. Starting the operating system kernel is crucial for multitasking applications, as it allows multiple tasks to run concurrently.

# Infinite loop at the end of the main function

The last part of the main function is an infinite loop. This loop is necessary because the main function should never return in an embedded system. If the main function were to return, it would result in undefined behavior because there is no operating system to return to. The infinite loop ensures that the main function keeps running indefinitely.

<SwmMeta version="3.0.0" repo-id="Z2l0aHViJTNBJTNBaVhwbGVtZW50JTNBJTNBZWYxMg==" repo-name="iXplement"><sup>Powered by [Swimm](https://app.swimm.io/)</sup></SwmMeta>
