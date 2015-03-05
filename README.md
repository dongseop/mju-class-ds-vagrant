# mju-class-ds-vagrant
Vagrant와 VirtualBox를 이용한 실습 환경 구축

## 인스톨

  1. github 가입 후 ssh key 등록 혹은 Github for Windows 설치
    - Settings 메뉴 아래의 SSH-Key 항목 참고하여 키 생성 및 등록
    - Github for Windows를 사용해도 됨. (https://windows.github.com/)
  2. install virtual box (https://www.virtualbox.org/wiki/Downloads)
  3. install vagrant (https://www.vagrantup.com/downloads.html)
  4. `git clone git@github.com:dongseop/mju-class-ds-vagrant.git`
  5. `cd mju-class-ds-vagrant`
  6. `vagrant up`
  7. 혹시 중간에 에러난 사람들은 다음 명령을 차례로 수행하세요.
    - `vagrant destroy`
    - `git pull`
    - `vagrant up`
    - 문제가 없다면 vagrant ssh 했을 때 자동으로 접속되어야 합니다.

## 사용법
  - 서버 접속: `vagrant ssh`
  - Synced 디렉토리: `cd /vagrant`
  - 컴파일: `gcc ....`
  - Scons (make와 유사한 빌드 툴): `scons`

## 실습 1 컴파일 및 실행
   ```
$ vagrant ssh
Welcome to Ubuntu 14.04.2 LTS (GNU/Linux 3.13.0-46-generic i686)

 * Documentation:  https://help.ubuntu.com/

  System information as of Thu Mar  5 09:12:03 UTC 2015

  System load:  0.93              Processes:           74
  Usage of /:   2.8% of 39.34GB   Users logged in:     0
  Memory usage: 16%               IP address for eth0: 10.0.2.15
  Swap usage:   0%                IP address for eth1: 192.168.33.10

  Graph this data and manage this system at:
    https://landscape.canonical.com/

  Get cloud support with Ubuntu Advantage Cloud Guest:
    http://www.ubuntu.com/business/services/cloud


Last login: Thu Mar  5 09:12:04 2015 from 10.0.2.2
vagrant@vagrant-ubuntu-trusty-32:~$
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
   
  
### 윈도용 텍스트 에디터 (소스코드 편집) 추천
  - SublimeText: http://www.sublimetext.com/3
  
