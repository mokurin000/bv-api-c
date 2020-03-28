# BV_codec

__[原文地址](https://www.zhihu.com/question/381784377/answer/1099438784)__

[![GitHub release](https://img.shields.io/github/release/poly000/bv-api-c.svg)](https://github.com/poly000/bv-api-c/releases)
[![CodeFactor](https://www.codefactor.io/repository/github/poly000/bv-api-c/badge)](https://www.codefactor.io/repository/github/poly000/bv_codec)
[![LICENSE](https://img.shields.io/github/license/poly000/bv-api-c)](LICENSE)

\_main和main是两个版本

* [_main.c 适用于大量转换（速度更快）。](_main.c)

* [main.c 更灵活。](main.c)

感谢雪炭对我的指导（我把优先级搞错了……）

# 使用方法（_main和main）

* 输入av号时请使用阿拉伯数字，例如：314，106

* 输入BV号时请直接输入，例如：BV1xx411c7XW，BV1xx411c7mu



av106会被 main.c 识别为BV号（

_[inputfile](example/inputfile)_ ， _[inputfile0](example/inputfile0)_ ， _[inputfile1](example/inputfile1)_ 是输入文件示例

请勿在使用\_main.c时为输入文件添加空行，

否则最后一个BV号/av号会重复打印。

可以在cmd执行 ```main.exe < inputfile的路径 > 输出文件的路径``` 以进行批量操作，

或者 ```_main.exe < inputfile0的路径 > 输出文件的路径```（av转BV），

```_main.exe < inputfile1的路径 > 输出文件的路径```（BV转av）

现在，你也可以将对应文件格式的文件拖进去。
