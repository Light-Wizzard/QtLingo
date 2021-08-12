#!/bin/bash
# Qt AppVeyor
#
# Last Update: 27 July 2021
#
# shell?check -x scripts/install.sh
#
echo "install Unix"
#
if [[ "$APPVEYOR_BUILD_WORKER_IMAGE" = "Ubuntu" ]]; then
#
    #wget -c -nv "https://download.qt.io/official_releases/qt-installer-framework/$MY_QT_IF_VERSION/QtInstallerFramework-linux-x64-$MY_QT_IF_VERSION.run" -O scripts/QtInstallerFramework-linux.run
#    curl -fsS -o scripts/QtInstallerFramework-linux.run "https://download.qt.io/official_releases/qt-installer-framework/$MY_QT_IF_VERSION/QtInstallerFramework-linux-x64-$MY_QT_IF_VERSION.run";
#    if [ -f scripts/QtInstallerFramework-linux.run ]; then
#        # make it executable
#        chmod +x scripts/QtInstallerFramework-linux.run;
#        ls -las scripts/;
#    else
#        echo -e "Error downloading QtInstallerFramework-linux";
#    fi
    # Python
    sudo add-apt-repository ppa:deadsnakes/ppa -y;
    sudo apt-get update -qq && sudo apt-get install -qq;
    if [[ "$MY_UPGRADE_OS" = "true" ]]; then sudo apt-get upgrade -qqy; fi
    # Developer tools and libsqlite3
    sudo apt install -qqy build-essential cmake software-properties-common libssl-dev zlib1g-dev libncurses5-dev libncursesw5-dev;
    sudo apt install -qqy libffi-dev mesa-common-dev libglu1-mesa-dev freeglut3-dev libegl1-Mesa-dev libmesa-dev;
    sudo apt install -qqy libgdbm-dev libdb5.3-dev libbz2-dev libexpat1-dev liblzma-dev tk-dev flex bison checkinstall libsqlite3-dev;
    sudo apt install -qqy libreadline-dev libgl-dev libpulse-mainloop-glib0 libgles2-mesa-dev libglfw3-dev libgl1-mesa-dev;
    sudo apt install -qqy libfreetype6-dev libfontconfig1-dev libdbus-1-dev libxi-dev xnviewmp libgstreamer-plugins-base1.0-0;
    sudo apt install -qqy libgstreamer0.10-0 libgstreamer-plugins-base0.10-0 libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev;
    # Python
    if [[ "$MY_PYTHON_REQUIRED" = "true" ]]; then sudo apt-get install -qqy python3.9-dev python3-venv; fi
    # Required by LinuxDeploy
    sudo apt-get install -qqy libxcb-icccm4 libxcb-image0 libxcb-keysyms1 libxcb-render-util0 libxcb-xinerama0 libxcb-xkb-dev libxkbcommon-x11-0 libgtk2.0-dev;
fi
#
#if [[ "$APPVEYOR_BUILD_WORKER_IMAGE" = "macos" ]]; then
#    #
#    wget -c -nv "https://download.qt.io/official_releases/qt-installer-framework/$MY_QT_IF_VERSION/QtInstallerFramework-macOS-x86_64-$MY_QT_IF_VERSION.dmg" -O scripts/QtInstallerFramework-macOS.dmg
#    # make it executable
#    chmod +x scripts/QtInstallerFramework-macOS.dmg;
#fi
