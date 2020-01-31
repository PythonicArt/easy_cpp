# 简要介绍
1. c++数据结构和算法笔记, 主要是一些知识点
2. 一些示例程序
3. LeetCode题解

## 目录
**cpp_example**
一些刷题过程中遇到的语言问题, 主要是代码示例
**pass**
通过简单测试(并不是acc)的题解及思路分析

## 源代码
**solution.cpp**
写代码的文件, 使用类或是函数的形式封装

**main.cpp**
提供测试用例, 调用solution.cpp中的题解方法, 进行简单的对比测试

## 可执行文件
**compile.bat**
**output.exe**
编译脚本 compile.bat, 会编译 main.cpp, solution.cpp源代码, 生成output.exe
通过执行output.exe会显示所有测试用例的通过情况
**to.exe**
to.exe filename
当solution.cpp代码通过， 将代码复制到 /pass/filename.cpp

# 环境要求
* atom编辑器， 语法检查工具使用linter-clang. (可自行选择)
* 编译器 clang [下载地址](http://releases.llvm.org/download.html)
* windows下还需要 visual stdio.
* 尽量使用最新的版本
