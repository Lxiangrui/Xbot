# Xbot
复刻稚晖君的开源写字机器人项目
---
title: X-bot
date: 2021-10-23 21:41:29
tags: 写字机器人
categories: DIY

---

# X-bot

## 前言

这个项目是我在稚辉君的视频里面看见的，是一个完全开源的项目，而且对他来说是一个比较简单的项目，但对于我这种没有什么DIY经验的同学来说，还是有点难的，不过可能我运气比较好吧，在他的视频评论区下面找到了一个大佬，他帮助了我很多,最后好像玩着玩着断断续续一直弄了1个多月才做好。

## 展示环节！

<div style="position: relative; width: 100%; height: 0; padding-bottom: 75%;"><iframe 
src="https://www.bilibili.com/video/BV1EL4y187Hd?spm_id_from=333.999.0.0" scrolling="no" border="0" 
frameborder="no" framespacing="0" allowfullscreen="true" style="position: absolute; width: 90%; 
height: 100%; left: 0; top: 0;"> </iframe></div>



## 关于机械臂

这个项目里面的机械结构叫做 CoreXY结构
[![5W3KoQ.jpg](https://z3.ax1x.com/2021/10/24/5W3KoQ.jpg)](https://imgtu.com/i/5W3KoQ)
CoreXY（主要是并联运动）意味着电机（通常是DIY级平台上最大的惯性源）是固定的。这允许快速加速。(但是我的好像不是很快可能还要调试一下)
CoreXY它的原理是通过两个电机同时控制XY的移动，左右两个电机同向的时候，往X轴移动，两个电机反向的时候往Y轴移动。；两个电机的同时作用，力量比单个电机控制一轴来得要稳定，还能减少了XY平台上面一个电机的重量。接下来的衍生的结构也是一样的原理。

## 关于控制方式

这个项目采用的是GRBL
GRBL是国外大牛编写的一套arduino单片机的G代码编译和运动控制的开源程序，而在这个项目里，稚辉君将GRBL移植到了STM32平台，可能当时在15年左右stm32比较便宜吧，性价比较高，而在现在2021的现在stm32的价格是以前的几倍不止/(ㄒoㄒ)/~~，话说回来，Grbl经常被用于DIY制作小型CNC调刻机或者写字机。

## 不同之处

### 硬件方面

因为对于稚辉君还是追求极致性能不考虑成本的~，咱们还是得考虑成本的，所以一些地方做出了改变，其中有步进电机的驱动电路是用的A4988,也是DIY项目常用的驱动模块。然后因为现在的我也没有稚辉君那样的技术力,开始我也是采用的网上PCB打板后，然后在tb购买元器件，焊接完后，就是一直点亮不了  /(ㄒoㄒ)/~~，也检查了很久，最后就放弃了这个方案，换成了洞洞板。
[![5W1fx0.md.jpg](https://z3.ax1x.com/2021/10/24/5W1fx0.md.jpg)](https://imgtu.com/i/5W1fx0)
报废的板子我 >:(
[![5WQvf1.md.jpg](https://z3.ax1x.com/2021/10/24/5WQvf1.md.jpg)](https://imgtu.com/i/5WQvf1)
我采用的是洞洞板焊接电路，同时安装了stm32103c8t6对应的排母，便于拆卸。
[![5W19Cn.md.jpg](https://z3.ax1x.com/2021/10/24/5W19Cn.md.jpg)](https://imgtu.com/i/5W19Cn)
然后与上位机的连接方式我这里用了3种
1、直接使用ch340串口连接电脑和写字机；
2、使用无线串口连接；
3、使用蓝牙模块hc_06，作为串口连接。

### 软件上位机

我使用的上位机是评论区大佬分享给我的，是奎享免费版，比较低的版本，可能网上下载不到了，如果有人要的话，可以联系我。

# 总结

这次的项目其实我的工作并不是很多，大多数代码，硬件，机械结构都是稚辉君开源的，可我应该还是学到一些东西的。
比如了解了GRBL这种控制方式，步进电机的使用，熟悉了蓝牙模块的使用，上位机的强大功能。
但这个项目有些地方我还是没有搞清楚，比如稚辉君是如何将GRBL从arduino移植到stm32的，这是个问题更多来源于我的技术不够，需要继续学习了解，还有稚辉君使用的上位机应该是他自己编写的，能够很好的适配。
所以，我准备还是得继续学习stm32这个平台，之前只是看了我们学校日常课程的内容，看来必须得继续学啊！同时计划学习c#编写上位机程序，那样以后也可以用unity，岂不美滋滋！！O(∩_∩)O
所以这就是这期博客的全部内容了。

希望和大家一起玩耍，能看到这里的都是人才啊🤣😂🤣😂，当然应该不太可能有人会看到这里哈，因为这个项目对于入行的大佬们确实实在是太简单了，而对于现在的我来说正好，所以其实我这里更多的是给自己的一个总结吧。
