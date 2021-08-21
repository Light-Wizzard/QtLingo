＃ギャラクシー電卓2

Galaxy Calculator 2には、4つの電卓が組み込まれています。

1.：milky_way：銀河電卓
2.：confounded：Madness Calculator
3.：earth_americas：惑星電卓
4 .：コンピューター：電卓

QtQMLとJavaScriptを使用して記述された最初のGalaxyCalculatorのプロジェクトファイルを使用しました。
これはQtC ++とウィジェットを使用しています。
したがって、すべてのリンクを修正してこの新しいプロジェクトに変換する機会が得られるまで、ドキュメントは奇抜なものになる可能性があります。
TravisとAppYeyerのプロジェクトを作成する必要があるので、これは進行中の作業です。

ギャラクシー、マッドネス、プラネットの計算機は、アイザックニュートン卿の計算に基づいています。
数学ニコラテスラを含むように更新されました、
このようにして、私がトリナリー数学と呼ぶ新しいタイプの数学を発明しました。これは、銀河の計算に使用されます。

このプロジェクトはオープンソースであり、ライセンスは必要ありません。これはQt C ++アプリです。
デスクトップやその他のデバイスで実行されるため、このアプリへの移植に使用したbashスクリプトが含まれています。

このアプリは、QtがサポートするすべてのOS（Linux、Windows、MAC、Android、iOS）用にコンパイルできます。
QtがサポートするすべてのOSと同様に、これはすべてではないにしてもほとんどの一般的なOSで実行されるはずです。

サポートされているすべてのQtOSのインストーラーと実行可能ファイルを作成しようとしますが、現在は次のようになっています。

バッジが緑色の場合、アプリをダウンロードできるはずです。そうでない場合は、
作業中の可能性もありますが、更新には数分しかかかりません。

このプロジェクトは進行中であるため、ファイルが破損する可能性がありますが、いずれかのマシンでコンパイルした場合はソースコードを実行する必要があります。

QtインストーラーフレームワークはLinuxおよびおそらくWindowsで機能していますが、インストーラーはダウンロードされません。
仕事中、私は以下のWindows 10のインストーラーを持っていますが、8についてはわかりませんが、7についてはわかりません。

##目次

1. [ステータス]（https://github.com/Light-Wizzard/Galaxy-Calculator-2#Status）
2. [開発-進捗状況]（https://github.com/Light-Wizzard/Galaxy-Calculator-2#Development-Progress）
3. [背景]（https://github.com/Light-Wizzard/Galaxy-Calculator-2#Background）
4. [スクリーンショット]（https://github.com/Light-Wizzard/Galaxy-Calculator-2#Screen-Shots）
5. [スクリーンショット]（https://github.com/Light-Wizzard/Galaxy-Calculator-2#3rd-Party-Code）
6. [Wiki]（https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki）
7。 [Doxygen Documentation]（https://light-wizzard.github.io/Galaxy-Calculator-2）

＃ 状態

[！[Appveyor Build Status]（https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true）]（https://ci.appveyor.com/project/Light-Wizzard/Galaxy-計算機-2）

##：パッケージ：**ダウンロード：**

 -：penguin：[Linux]（https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage）
 -：penguin ：： inbox_tray：[Linux ZSync]（https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-x86_64.AppImage.zsync）
 -：penguin ：： outbox_tray：[Linuxインストーラーが動作中]（https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2-Linux-Installer）
 -：office：[Windows zip]（https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2-Windows.zip）
 -：office ：： outbox_tray：[Windowsインストーラーexe]（https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/GalaxyCalculator2.exe）
 -：apple：[Apple]（https://github.com/Light-Wizzard/Galaxy-Calculator-2/releases/download/continuous/Galaxy-Calculator-2.dmg）

Windows（7および10でテスト済み）：zipをダウンロードして解凍し、デプロイフォルダー内でGalaxy-Calculator-2.exeファイルを実行します。

私の本はすべてhttp://LightWizzard.comからオンラインで無料で入手できますが、印刷したり、ePubをデバイスにプッシュしたりするにはお金がかかります。

私はここで私の本を公表していません、あなたは私の本でそれらを無料で読むことができます
[GithubアカウントLight-Wizzard / The-Principles-Of-The-Trinary-Universe]（https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe）、
ただし、印刷された本、またはePubをダウンロードせずにデバイスのePubリーダーから簡単に配信できるようにするために料金を支払う必要があります。

印刷された本とePubは次の場所で入手できます。

ルル
*：book ：： computer：http：//www.lulu.com/spotlight/LightWizzard

アマゾン
*：book：Book https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
*：コンピューター：ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

主要な書店でも入手できますが、数学の詳細をすべて知りたい場合は、コードにあまり記載されていないので、読むことをお勧めします。

OSが表示されない場合は、ダウンロードしてフォルダーに解凍し、インストールする必要のあるQt Creatorで開いて、コンパイルまたは実行するだけです。

＃開発の進捗状況

Galaxy Calculatorを理解するには、TrinaryScienceとTrinaryUniverseを理解する必要があります。
しかし、基本的にトリナリーは、トリニティがアイザックニュートン卿に対して行ったのと同じ意味を持ち、交流またはACについて説明しています。
父は+1、息子は-1、聖霊または母なる自然の精神は0であるため、論理レベルとして+ 1、-1、0の3値論理です。
ニュートンがキリストの教えを嫌っていたので、私はトリナリーという名前を使います。

銀河を構成する構成画面があります。銀河に名前を付けたり、太陽のサイズを直径マイルで設定したりできます。
生きている惑星のサイズを直径マイルで設定し、トリナリーエンジンの数を設定します。詳細については、ヘルプを参照してください。
直径マイル単位の銀河の半径、および印刷するトラックの数。

一部のデバイスの権限のため、ローカルストレージ機能を削除しました。

＃ バックグラウンド

Galaxy Calculatorは、ボタンを1回クリックするだけで計算でき、トラック番号、そのトラックに乗るのに必要なTrinaryEngineの数を記録します。
その太陽の最小速度と最大速度（マイル/時）、住みやすい惑星の周波数、太陽の軌道距離（マイル）、およびトラックの周波数、
アイザックニュートン卿が文明の終焉がいつ起こるかを決定するために使用したものであり、彼と私の計算によれば、
これは、2060年に軍がまだ使用しているユリウス暦で、または2061年に現在使用されているグレゴリオ暦で発生します。
これは一般に与えられたのと同じ計算でしたが、彼がどのように計算したかを知っている人はほとんどいませんでした。彼の元の方程式が見つからなかったので、私は新しい式を書きました。

アイザックニュートン卿は彼の2060計算のコピーを燃やしました、彼はそれが彼の魂に重いと書いたので、彼はそれを手放さなければなりませんでした、
そして、知りたい人は誰でもそれを理解できると書きました。すべての公式は聖書にあります。36年後、私はそれらすべてを見つけました。

このGalaxyCalculatorは、このページを作成したbashスクリプトについて考えた後、使用するために作成されました。

http://LightWizzard.com/books/trinary.universe/appendix.a.html

bashスクリプトは、ページを作成するだけでなく、テーブルの値を計算しました。

これが、アプリケーションが何をする必要があるかを誰もが視覚化するのに役立つことを願っています。それは、銀河の周りの星の経路をグラフ化してプロットすることだけです。

これはGalaxySimulatorではなく、グラフとプロットのみであり、理解することが非常に重要です。
法と規則または電子機器のみを使用して構築されたGalaxySimulatorを作成したいと思います。
そのプロジェクトはGalaxySimulatorと呼ばれ、なぜこのプロジェクトは ギャラクシー電卓、
しかし、私はQt 3DStudioを使用してシミュレータをシミュレートすることを検討しています。

詳細については、[Wiki]（https://github.com/Light-Wizzard/Galaxy-Calculator-2/wiki）を参照してください。

これは進行中の作業です。バグやコメントがあれば報告してください。

＃スクリーンショット

！[Galaxy構成]（/ doc / images / screenshot-config.png？raw = true "Galaxy構成"）

！[Galaxy Calculator]（/ doc / images / screenshot-galaxy.png？raw = true "Galaxy Calculator"）

！[エネルギー計算機]（/ doc / images / screenshot-energy.png？raw = true "エネルギー計算機"）

！[Madness Calculator]（/ doc / images / screenshot-madness.png？raw = true "Madness Calculator"）

！[World Calculator]（/ doc / images / screenshot-world.png？raw = true "Planet Calculator"）

！[電卓]（/ doc / images / screenshot-calc.png？raw = true "電卓"）


＃サードパーティコード

[QCalculator]（https://github.com/xenotux/qcalc）
https://github.com/xenotux/qcalc

Windows用GMPDll
https://osdn.net/projects/mingw/releases/69295

Windows用のMPFRDLL
https://osdn.net/projects/mingw/releases/69297


README.mdの終わり