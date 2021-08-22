＃QtLingo

QtLingoは、Qtの翻訳を簡単にするアプリケーションです。
通常のフローでは、ファイルを編集して単語を翻訳に置き換えます。
これは私にはやりすぎです、
だから私はそれを簡単にすることにしました、
このアプリケーションを実行し、プロジェクトのフォルダの場所と名前を指定してプロジェクトを設定します。
.tsファイルが必要な場所を指定します。
および.qmファイルの宛先。
そしてそれをコンパイルし、
そしてそれはあなたにqmakeまたはcmakeの設定を与えるでしょう、
そのコードでファイルを更新するだけです。
プロジェクトをデプロイし、
それはすべて完了し、それ以上のことは何もしません。

＃＃ 状態

[！[Appveyorビルドステータス]（https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true）]（https://ci.appveyor.com/project/Light-Wizzard/qtlingo）

###：パッケージ：**ダウンロード：**

 -：penguin：[Linux zip]（https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x86.zip）
 -：office：[Windows 64 zip]（https://github.com/Light-Wizzard/QtLingo/releases/download/Windows64/QtLingo-Windows-x64.zip）
 -：apple：現在利用できない[Apple zip]（https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo.zip）

＃ドキュメンテーション

Doxygenファイルをこのサイトにアップロードしようとしていますが、今のところ機能していません。
[ドキュメント]（https://light-wizzard.github.io/QtLingo/）

＃GitHubプロジェクトおよび使用されるその他のプロジェクト

私はこれのためにGitHubアプリケーションに使用します、
翻訳には、https：//github.com/crow-translate/crow-translateでcrow-translateを使用します。
およびQOnlineTranslator（https://github.com/crow-translate/QOnlineTranslator）、
.tsファイルを解析するには、https：//github.com/nen777w/ts_toolでts_toolを使用します。
https://wiki.qt.io/Simple_encryption_with_SimpleCrypt#Versionsを使用しました。

＃ プロセス

最初に[コンパイル]をクリックして、選択した言語に従ってプロジェクトの翻訳ファイルを更新します。
これらはすべてアプリにコンパイルされるため、コンパイルと呼びます。
次に、[すべて受け入れる]をクリックするか、QtLingusticを使用して各翻訳にアクセスします。
次に、[ヘルプ]、[ReadMe]、および[これらのファイルの翻訳]の更新をクリックします。
言語コードを使用してファイルを作成する。

＃Doxygen

私はusignDoxygenを文書化しようとしました、あなたはそれを以下のコマンドから実行することができます。

`` `bash
doxygen Doxyfile

また

ドキシウィザード
`` `

＃問題

インターネット接続のダウンに対処する。

`` `
クリティカル：「ソケット操作がタイムアウトしました」（../QtLingo/src/MainWindow.cpp:2280、MainWindow::translateWithReturn(const QString＆、QOnlineTranslator :: Engine、QOnlineTranslator :: Language、QOnlineTranslator :: Language、QOnlineTranslator :: Language） :: <lambda（）>）
重要：「ホストwww.bing.comが見つかりません」（../QtLingo/src/MainWindow.cpp:2280、MainWindow::translateWithReturn(const QString＆、QOnlineTranslator :: Engine、QOnlineTranslator :: Language、QOnlineTranslator :: Language、QOnlineTranslator ::言語）:: <lambda（）>）
重要：「ホストtranslate.yandex.comが見つかりません」（../QtLingo/src/MainWindow.cpp:2280、MainWindow::translateWithReturn(const QString＆、QOnlineTranslator :: Engine、QOnlineTranslator :: Language、QOnlineTranslator :: Language、QOnlineTranslator ::言語）:: <lambda（）>）
重要：「ホストtranslate.googleapis.comが見つかりません」（../QtLingo/src/MainWindow.cpp:2280、MainWindow::translateWithReturn(const QString＆、QOnlineTranslator :: Engine、QOnlineTranslator :: Language、QOnlineTranslator :: Language、QOnlineTranslator ::言語）:: <lambda（）>）

`` `

＃クレジット

上にリストしたいくつかのGitHubプロジェクトを使用しましたが、それ以外はすべて
ジェフリースコットフレッシャーによって書かれた肉の光の魔法使い

###ファイルの終わり