# mju-class-ds-vagrant
Vagrant와 VirtualBox를 이용한 실습 환경 구축

## 인스톨

  1. github 가입 후 ssh key 등록
    - Settings 메뉴 아래의 SSH-Key 항목 참고하여 키 생성 및 등록
    - Github for Windows를 사용해도 됨. (https://windows.github.com/)
  2. install virtual box (https://www.virtualbox.org/wiki/Downloads)
  3. install vagrant (https://www.vagrantup.com/downloads.html)
  4. `git clone git@github.com:dongseop/mju-class-ds-vagrant.git`
  5. `cd mju-class-ds-vagrant`
  6. `vagrant up`

## 사용법
  - 서버 접속: `vagrant ssh`
  - Synced 디렉토리: `cd /vagrant`
  - 컴파일: `gcc ....`
  - Scons (make와 유사한 빌드 툴): `scons`

## 실습 1 컴파일 및 실행
   ```
$ vagrant ssh
Welcome to Ubuntu 14.04.2 LTS (GNU/Linux 3.13.0-45-generic x86_64)

 * Documentation:  https://help.ubuntu.com/

  System information as of Tue Feb 24 22:26:38 UTC 2015

  System load:  0.22              Processes:           79
  Usage of /:   2.8% of 39.34GB   Users logged in:     0
  Memory usage: 24%               IP address for eth0: 10.0.2.15
  Swap usage:   0%

  Graph this data and manage this system at:
    https://landscape.canonical.com/

  Get cloud support with Ubuntu Advantage Cloud Guest:
    http://www.ubuntu.com/business/services/cloud

0 packages can be updated.
0 updates are security updates.


vagrant@vagrant-ubuntu-trusty-64:~$ cd /vagrant/exercises/ex1-hello/
vagrant@vagrant-ubuntu-trusty-64:/vagrant/exercises/ex1-hello$ scons
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
gcc -o hello.o -c hello.c
gcc -o hello hello.o
scons: done building targets.
vagrant@vagrant-ubuntu-trusty-64:/vagrant/exercises/ex1-hello$ ./hello
Hello, world!
vagrant@vagrant-ubuntu-trusty-64:/vagrant/exercises/ex1-hello$
   ```
   
  
