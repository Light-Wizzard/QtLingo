# 银河计算器 2

Galaxy Calculator 2 内置了 4 个计算器：

1. :milky_way: 银河计算器
2. :confounded: 疯狂计算器
3. :earth_americas: 行星计算器
4. :computer: 计算器

我使用了我的第一个 Galaxy Calculator 中的项目文件，它是使用 Qt QML 和 JavaScript 编写的，
这个使用 Qt C++ 和 Widgets，
所以文档可能很古怪，直到我有机会修复所有链接并将它们转换为这个新项目，
我将不得不制作 Travis 和 AppYyer 项目，所以这是一项正在进行的工作。

银河、疯狂和行星计算器基于艾萨克·牛顿爵士的计算，
并更新为包括数学尼古拉特斯拉，
因此发明了一种新的数学类型，我称之为三元数学，用于计算星系。

这个项目是开源的，不需要许可证，这是一个 Qt C++ 应用程序，
将在桌面和其他设备上运行，包括我用来移植到这个应用程序的 bash 脚本。

此应用程序可以针对 Qt 支持的任何操作系统编译：Linux、Windows、MAC、Android 和 iOS，
以及 Qt 支持的每个操作系统，所以它应该可以在大多数流行的操作系统上运行。

我将尝试为所有支持的 Qt 操作系统制作安装程序和可执行文件，目前我有：

如果徽章是绿色的，您应该可以下载应用程序，如果不是，
可能是我正在处理它，但更新只需要几分钟。

这个项目正在运行，所以文件可能会损坏，但如果在任何机器上编译源代码应该运行。

Qt 安装程序框架适用于 Linux 和 Windows，但安装程序无法下载，
在工作中，我在下面有一个适用于 Windows 10 的安装程序，不确定是 8，但不是 7。

## 目录

1. [状态](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Status)
2. [开发-进度](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Development-Progress)
3. [背景](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Background)
4. [屏幕截图](https://github.com/Light-Wizzard/Galaxy-Calculator-2#Screen-Shots)
5. [屏幕截图](https://github.com/Light-Wizzard/Galaxy-Calculator-2#3rd-Party-Code)
6. [维基](https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)
7. [Doxygen 文档](https://light-wizzard.github.io/Galaxy-Calculator-2)

# 状态

[![Appveyor 构建状态](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/Galaxy-计算器-2)

## :package: **下载:**

 - :penguin: [Linux](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage)
 - :penguin: :inbox_tray: [Linux ZSync](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage.zsync)
 - :penguin: :outbox_tray: [Linux Installer in work](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-Linux-Installer)
 - :office: [Windows zip](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2-Windows.zip)
 - :office: :outbox_tray: [Windows Installer exe](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2.exe)
 - :apple: [Apple](https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2.dmg)

Windows（在 7 和 10 上测试让我知道 8 是否有效）：下载 zip 并解压缩，然后运行部署文件夹中的 Galaxy-Calculator-2.exe 文件。

我所有的书都可以在 http://LightWizzard.com 上免费在线，但打印它们或将 ePub 推送到您的设备需要花钱。

我不在这里宣传我的书，你可以在我的网站上免费阅读
[Github 账号 Light-Wizzard/The-Principles-Of-The-Trinary-Universe](https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe)，
但是您必须为印刷书籍付费，或者通过您的设备 ePub 阅读器轻松交付 ePub，而无需下载它。

印刷书籍和 ePub 可在以下位置获得：

露露
* :book: :computer: http://www.lulu.com/spotlight/LightWizzard

亚马逊
* :book: 书 https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
* :computer: ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

你也可以在任何一家主要的书店买到它，但我建议你阅读它，如果你想知道关于数学的所有细节，你不会在代码中找到那么多。

如果你没有看到你的操作系统，只需下载，解压到一个文件夹，用必须安装的 Qt Creator 打开，然后编译或运行它。

# 开发进度

你必须了解三元科学和三元宇宙才能理解银河计算器，
但基本上 Trinary 与 Trinity 对 Isaac Newton 爵士的含义相同，它描述了交流电或交流电，
父亲是+1，儿子是-1，圣灵或大自然母亲的精神是0，所以它是三元逻辑：+1、-1和0作为逻辑级别，
我使用三位一体这个名字是因为牛顿讨厌基督的教导。

有一个配置屏幕是您配置银河的地方，您可以命名银河，设置它的太阳大小（以英里为单位），
设置它的生命行星大小（以英里为单位），设置三元引擎的数量，请参阅帮助以获取更多详细信息，
和以英里为单位的银河半径，以及您要打印的轨道数。

由于某些设备的权限，我删除了本地存储功能。

＃ 背景

Galaxy Calculator 是一个一键式计算器，它记录轨道编号，在该轨道上需要多少个三元引擎，
其以每小时英里为单位的太阳最小和最大速度、宜居行星频率、以英里为单位的太阳轨道距离和轨道频率，
艾萨克·牛顿爵士用它来确定文明的终结何时发生，根据他和我的计算，
这将发生在军队仍在使用的儒略历下的 2060 年，或者今天使用的格里高利历下的 2061 年，
这是给公众的相同计算，但很少有人知道他是如何计算的，我写了一个新公式，因为我找不到他的原始方程。

艾萨克牛顿爵士烧毁了他的 2060 计算副本，他写道，这对他的灵魂来说很重，所以他不得不放手，
并写道任何想知道的人都可以弄清楚，所有公式都在圣经中，36年后我确实找到了它们。

这个 Galaxy Calculator 是为了使用而编写的，在我考虑了创建这个页面的 bash 脚本之后：

http://LightWizzard.com/books/trinary.universe/appendix.a.html

bash 脚本不仅创建了页面，还计算了表值。

我希望这可以帮助每个人想象应用程序需要做什么，这只是绘制和绘制星系周围星星的路径。

这不是 Galaxy Simulator，只是一个 Graph 和 Plot，理解这一点非常重要，
我想编写一个仅使用法律和规则或电子设备构建的银河模拟器，
那个项目将被称为银河模拟器，以及为什么这个项目只被称为一个 银河计算器，
但我正在考虑使用 Qt 3D Studio 来模拟模拟器。

更多信息请参见：[Wiki](https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki)

这是一项正在进行的工作，请报告任何错误和评论。

# 屏幕截图

![银河配置](/doc/images/screenshot-config.png?raw=true "银河配置")

![银河计算器](/doc/images/screenshot-galaxy.png?raw=true "银河计算器")

![能量计算器](/doc/images/screenshot-energy.png?raw=true "能量计算器")

![疯狂计算器](/doc/images/screenshot-madness.png?raw=true "疯狂计算器")

![世界计算器](/doc/images/screenshot-world.png?raw=true "行星计算器")

![计算器](/doc/images/screenshot-calc.png?raw=true "计算器")


# 第三方代码

[QCalculator](https://github.com/xenotux/qcalc)
https://github.com/xenotux/qcalc

适用于 Windows 的 GMP Dll
https://osdn.net/projects/mingw/releases/69295

适用于 Windows 的 MPFR Dll
https://osdn.net/projects/mingw/releases/69297


README.md 结束