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

[！[Appveyor Build Status]（https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true）]（https://ci.appveyor.com/project/Light-Wizzard/qtlingo）

###：パッケージ：**ダウンロード：**

-：penguin：[Linux x64 zip]（https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Ubuntu-Release-x64.zip）
-：office：[Windows x64 zip]（https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-Windows-Release-x64.zip）
-：apple：[Apple x64 zip]（https://github.com/Light-Wizzard/QtLingo/releases/download/continuous/QtLingo-MacOs-Release-x64.zip）

Windows（7および10でテスト済み）：zipをダウンロードして解凍し、
そして、デプロイAppDirフォルダー内のファイルQtLingo.exeを実行します。

私は持っていないので、Appleはテストしません。

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

私はDoxygenを使用していますが、以下のコマンドから実行できます。

`` `bash
doxygen Doxyfile

また

ドキシウィザード
`` `

ドキュメントの下にDoxygenドキュメントがあります。

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