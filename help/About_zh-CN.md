# QtLingo 关于

QtLingo 是一个使 Qt 计算机翻译更容易的应用程序，
和我从未见过的东西，
所以它是 Qt Translations 的一个新概念。

正常流程会让您编辑文件并用翻译替换单词，
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

为此，我习惯使用 GitHub 应用程序，
对于翻译，我在 https://github.com/crow-translate/crow-translate 使用 crow-translate，
和 QOnlineTranslator 在 https://github.com/crow-translate/QOnlineTranslator，
并解析 .ts 文件，我在 https://github.com/nen777w/ts_tool 使用 ts_tool。

首先，我将根据您选择的语言更新您的项目翻译文件，
然后我会翻译所有的语言，
然后更新翻译文件并将它们编译成 .qm 文件以进行部署。

杰弗里·斯科特·弗莱舍 编剧