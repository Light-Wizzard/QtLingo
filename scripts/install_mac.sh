#!/bin/bash
#
# Last Update: 25 Auguest 2021
#
# shell?check -x scripts/install.sh
#
echo "install MacOS"
#
export PATH="/usr/local/sbin:/usr/local/opt/qt5/bin:$PATH";
brew cleanup;
brew config;
brew doctor || true;
brew install qt5 cmake binutils create-dmg openssl@1.1 curl;
brew link qt5 --force;
export PATH="$(brew --prefix qt5)/bin:$PATH";
export CMAKE_PREFIX_PATH="$(brew --prefix qt5)";
#    curl -fsS -o scripts/QtInstallerFramework-macOS.dmg "https://download.qt.io/official_releases/qt-installer-framework/$MY_QT_IF_VERSION/QtInstallerFramework-macOS-x86_64-$MY_QT_IF_VERSION.dmg";
#    # make it executable
#    chmod +x scripts/QtInstallerFramework-macOS.dmg;
# ****************************** End of install.sh ****************************
