＃QtLingoについて

QtLingoは、Qt ComputerTranslationsを簡単にするアプリケーションです。
そして私が今まで見たことがない何か、
つまり、これはQtTranslationsの新しい概念です。

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

私はこれのためにGitHubアプリケーションに使用します、
翻訳には、https：//github.com/crow-translate/crow-translateでcrow-translateを使用します。
およびQOnlineTranslator（https://github.com/crow-translate/QOnlineTranslator）、
.tsファイルを解析するには、https：//github.com/nen777w/ts_toolでts_toolを使用します。

まず、選択した言語に従ってプロジェクトの翻訳ファイルを更新します。
それから私はすべての言語を翻訳します、
次に、翻訳ファイルを更新し、展開用に.qmファイルにコンパイルします。

ジェフリースコットフレッシャー脚本の作品