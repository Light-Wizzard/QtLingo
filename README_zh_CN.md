#QtLingo

QtLingo 是一个使 Qt 翻译更容易的应用程序，
正常流程会让你编辑文件并用它们的翻译替换单词，
这对我来说太多了
所以我决定让它更容易，
运行此应用程序并通过为其提供项目的文件夹位置和名称来设置项目，
给它你想要 .ts 文件的位置，
和 .qm 文件的目的地，
并编译它，
它将为您提供 qmake 或 cmake 的配置，
只需使用该代码更新您的文件，
并部署您的项目，
一切都完成了，没什么可做的。

＃＃ 地位

[![Appveyor 构建状态](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/qtlingo)

###：包：**下载：**

- :penguin: [Linux x64 zip ](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x64.zip)
- :office: [Windows x64 zip](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Windows-Release-x64.zip)
- :apple: [Apple x64 zip](https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-MacOs-Release-x64.zip)

Windows（在 7 和 10 上测试让我知道 8 是否有效）：下载 zip 并解压缩，
并运行部署 AppDir 文件夹中的文件 QtLingo.exe。

苹果没有测试，因为我没有。

# 文档

我正在尝试将 Doxygen 文件上传到此站点，但目前无法正常工作。
[文档](https://light-wizzard.github.io/QtLingo/)

# GitHub Projects 和其他用到的项目

为此，我习惯使用 GitHub 应用程序，
对于翻译，我在 https://github.com/crow-translate/crow-translate 使用 crow-translate，
和 QOnlineTranslator 在 https://github.com/crow-translate/QOnlineTranslator，
并解析 .ts 文件，我在 https://github.com/nen777w/ts_tool 使用 ts_tool，
我使用了 https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versions。

＃ 过程

首先单击编译以根据您选择的语言更新您的项目翻译文件，
我称之为编译，因为这些是编译到您的应用程序中的所有文件，
然后单击全部接受或使用 Qt Lingustic 接受每个翻译，
然后点击更新帮助和自述文件和翻译这些文件，
使用语言代码创建文件。

# 多氧

我使用 Doxygen，你可以从下面的命令运行它。

```bash
Doxygen 文件

或者

强力精灵
``

我在 docs 下有 Doxygen 文档。

＃ 问题

处理 Internet 连接中断。

``
严重：“套接字操作超时” (../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator::Language) ::<拉姆达()>)
关键：“找不到主机 www.bing.com”（../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator ::语言)::<lambda()>)
关键：“找不到主机 translate.yandex.com”（../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator ::语言)::<lambda()>)
关键：“找不到主机 translate.googleapis.com”（../QtLingo/src/MainWindow.cpp:2280, MainWindow::translateWithReturn(const QString&, QOnlineTranslator::Engine, QOnlineTranslator::Language, QOnlineTranslator::Language, QOnlineTranslator ::语言)::<lambda()>)

``

# 学分

我使用了上面列出的一些 GitHub 项目，其他一切都是
由杰弗里·斯科特·弗莱舍（Jeffrey Scott Flesher）撰写，肉身中的光明巫师

### 文件结束