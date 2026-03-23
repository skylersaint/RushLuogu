# Luogu C++ 练习工程

这是一个适合刷洛谷题目的 C++ 项目骨架：

- 每道题一个源文件，放在 `problems/` 目录下
- 使用 `CMake` 自动扫描并生成对应可执行文件
- 提供题目模板和快速新建脚本，方便长期练习多道题

## 目录结构

```text
.
├── CMakeLists.txt
├── include/
│   └── cp.hpp
├── problems/
│   └── P1001.cpp
├── scripts/
│   ├── build.sh
│   ├── new_problem.sh
│   └── run.sh
└── templates/
    └── problem.cpp
```

## 环境要求

- CMake 3.16+
- 支持 C++17 的编译器

## 新建构建目录并编译

推荐直接使用项目自带脚本，它会自动选择可用的编译器：

```bash
./scripts/build.sh
```

在当前这台 macOS 机器上，脚本会优先使用 Homebrew 的 `g++-15`，避开系统 `AppleClang` 标准库不完整的问题。

如果你的系统编译器本身可用，也可以手动执行：

```bash
cmake -S . -B build
cmake --build build
```

使用脚本时，可执行文件会在 `build/<compiler>/bin/` 目录下。

## 运行示例题

```bash
./scripts/run.sh P1001
```

如果你想给程序输入数据，可以这样：

```bash
printf "20 22\n" | ./scripts/run.sh P1001
```

## 新增一道洛谷题

```bash
./scripts/new_problem.sh P1002
```

执行后会自动创建：

```text
problems/P1002.cpp
```

然后重新编译：

```bash
./scripts/build.sh
```

之后运行：

```bash
./scripts/run.sh P1002
```

## 模板说明

模板已经包含竞赛里常用的输入输出初始化：

- `ios::sync_with_stdio(false);`
- `cin.tie(nullptr);`
- `cp.hpp` 常用标准库头文件集合，避免 macOS 下 `bits/stdc++.h` 不可用的问题

你只需要专注写题解逻辑。
