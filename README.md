# BV_codec

[原文地址](https://www.zhihu.com/question/381784377/answer/1099438784)

[![GitHub release](https://img.shields.io/github/v/release/poly000/BV_codec.svg)]()

emmm \_main和main是两个版本

* [_main.c 适用于大量转换（速度更快）。](_main.c)

* [main.c 更灵活。](main.c)

感谢雪炭对我的指导（我把优先级搞错了……）

# 使用方法：

* 输入av号时请使用阿拉伯数字，例如：314，106

* 输入BV号时请直接输入，例如：BV1xx411c7XW，BV1xx411c7mu



av106会被 main.c 识别为BV号（


_[inputfile](inputfile)_ 是一个输入文件示例

注：结尾不要有空白，因为觉得加个scanf()和ungetc()很影响效率。

否则最后一个BV号/av号会重复打印。（\_main.c）

可以在cmd执行 ```main.exe < inputfile > outputfile``` 以进行批量操作，

或者 ```_main.exe < inputfile0 > outputfile```（av转BV），

```_main.exe < inputfile1 > outputfile```（BV转av）
