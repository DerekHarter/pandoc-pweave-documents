#!/usr/bin/env bash
#
# Basic configuration, make sure box is up to date and add some
# generally useful packages like build-essential and python

# make sure initially everything up to date
apt -y update
apt -y dist-upgrade

# set time zone and hostname
timedatectl set-timezone America/Chicago
hostnamectl set-hostname pandocknit

# install desktop environment so can run graphical tools from the vagrant box
# make sure that the virtualbox display is set to VMSVGA
apt -y install ubuntu-desktop
apt -y install virtualbox-guest-x11 virtualbox-guest-utils
#shutdown -r now
systemctl set-default graphical.target
systemctl isolate graphical.target

# general build tools needed for this project
apt -y install build-essential gdb csh wget htop sshfs python dos2unix git uncrustify astyle doxygen graphviz clang-format emacs vim ripgrep

# python 3 distribution with needed packages, using anaconda python distribution
# install all useful python/scipy/numpy scientific libraries in conda
# install the pandoc tools from anaconda python
wget -c https://repo.anaconda.com/archive/Anaconda3-2021.11-Linux-x86_64.sh
bash Anaconda3-2021.11-Linux-x86_64.sh -b -p /opt/anaconda3

export PATH="/opt/anaconda3/bin:$PATH"
addgroup conda # group for people who need to use conda
chgrp -R conda /opt/anaconda3
chmod 770 -R /opt/anaconda3
adduser vagrant conda

/opt/anaconda3/bin/conda install -y numpy scipy matplotlib pandas seaborn keras tensorflow statsmodels


# pandoc and pweave tools for markdown/rst conversion
/opt/anaconda3/bin/conda install -y pandoc
apt -y install python3 python3-pweave python3-pypandoc python3-pandocfilters python3-pygments pandoc python3-matplotlib python3-seaborn python3-numpy python3-pandas python3-scipy python3-statsmodels
apt -y install python-is-python3

# LaTeX tools for building pdf from markdown
apt -y install  texlive texlive-base texlive-bibtex-extra texlive-fonts-extra  texlive-latex-recommended texlive-latex-extra texlive-fonts-recommended texlive-pictures texlive-science biber
