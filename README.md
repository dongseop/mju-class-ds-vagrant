# mju-class-ds-vagrant
Vagrant와 VirtualBox를 이용한 실습 환경 구축

## 인스톨

  1. Github for Windows 설치 (https://windows.github.com/)
  2. install virtual box (https://www.virtualbox.org/wiki/Downloads)
     - 학과 일부 PC에서 4.3.12 버전만 정상적으로 동작하는 일이 있었습니다. 혹시 최신 버전 설치하고 제대로 아래 과정들이 안되는 경우, 최신 버전을 삭제하고 4.3.12 버전을 설치한 후 아래 과정들을 다시 실행해보세요.
  3. install vagrant (https://www.vagrantup.com/downloads.html)
  4. Github에 회원 가입 후 로그인 하고 이 페이지에 다시 들어오세요.
  5. 이 페이지 오른쪽에 "Clone in Desktop"이라는 버튼을 누르면 본인 컴퓨터에 이 저장소의 소스가 다운로드 됩니다. 본인이 작업할 디렉토리에다가 clone하면 됩니다.
  6. `cd mju-class-ds-vagrant` 해서 다운 받은 디렉토리로 이동하세요.
  6. `vagrant up` 이 명령을 수행하면 가상 머신이 하나 생성됩니다. 중간에 우분투 리눅스 이미지를 다운 받는 과정이 있어서 시간이 많이 걸리므로 네트워크 상태가 좋은 곳에서 실행하세요.
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
  
