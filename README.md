# mju-class-ds-vagrant
Vagrant와 VirtualBox를 이용한 실습 환경 구축

## 인스톨 하기 전에 꼭 확인할 사항
  1. 윈도의 경우 한글 이름을 가진 디렉토리 처리에 문제가 있을 수 있습니다.
  2. 특히 vagrant는 사용자 홈 디렉토리 아래에 자동으로 여러 파일을 설치하므로 사용자 이름이 한글인 경우 문제가 생길 수 있습니다.
  3. 가능하면 영문 사용자 명을 가진 새로운 사용자를 한 명 추가 해서 해당 사용자로 접속해서 vagrant를 설치하세요.
     - 제어판 > 사용자 계정 > 에서 사용자 추가 등 할 수 있습니다.
    
## 인스톨

  1. Git을 설치해주세요. (https://git-scm.com )
  2. Github Desktop 설치 (https://desktop.github.com/): 만일 Git 사용에 익숙하다면 terminal에서 git을 사용하는 것도 좋습니다. Linux나 Mac OS에서는 command line tool을 활용해보세요.
  3. install virtual box (https://www.virtualbox.org/wiki/Downloads)
     - 현재 최신 버전은 5.0.14입니다. 학과 일부 PC에서 4.3.12 버전만 정상적으로 동작하는 일이 있었습니다. 혹시 최신 버전 설치하고 제대로 아래 과정들이 안되는 경우, 최신 버전을 삭제하고 4.3.12 버전을 설치한 후 아래 과정들을 다시 실행해보세요.
     - VirtualBox는 자신의 컴퓨터 속에 가상의 컴퓨터를 실행할 수 있도록 하는 SW입니다.
  4. install vagrant (https://www.vagrantup.com/downloads.html)
     - 가상의 컴퓨터 설정이나 환경을 동일하게 맞춰줄 수 있는 프로그램입니다. 이 프로그램을 가지고 우리 실습용 환경을 모두 동일하게 유지하게 됩니다.
  5. Github에 회원 가입 후 로그인 하고 이 페이지에 다시 들어오세요.
  6. 이 페이지 오른쪽에 "Clone in Desktop" 버튼 (Download ZIP 버튼 왼쪽의 모니터 속으로 화살표가 내려오는 모습의 버튼)을 누르면 본인 컴퓨터에 이 저장소의 소스가 다운로드 됩니다. 본인이 작업할 디렉토리에다가 clone하면 됩니다. 새로운 github 인터페이스에서는 상단의 clone 주소 옆에 컴퓨터로 다운받는 형태의 아이콘이 있습니다. 이 아이콘 누르면 디렉토리를 정할 수 있습니다. 가능하면 사용하기 좋도록 c:\projects\ 같은 디렉토리를 만들어서 정하시면 됩니다.
    - 혹시 위의 내용이 제대로 안되는 사람은 '윈도탐색창'에서 c:\projects 디렉토리를 열고 마우스 오른쪽 버튼을 누르면 "Git Bash Here"라는 명령이 보일꺼예요. 이걸 눌러서 Bash 창을 열고 아래와 같은 명령을 실행해 보세요.
    
      ```
git clone https://github.com/dongseop/mju-class-ds-vagrant.git
      ```
      
  7. `cd mju-class-ds-vagrant` 해서 다운 받은 디렉토리로 이동하세요. 혹은, 윈도 참색창에서 Git Bash Here 명령을 이용해서 Bash 창을 열고, `cd c:\projects\mju-class-ds-vagrant` 하셔도 되요.
  8. `vagrant up` 이 명령을 수행하면 가상 머신이 하나 생성됩니다. 중간에 우분투 리눅스 이미지를 다운 받는 과정이 있어서 시간이 많이 걸리므로 네트워크 상태가 좋은 곳에서 실행하세요.
  9. 혹시 중간에 에러난 사람들은 다음 명령을 차례로 수행하세요.
    - `vagrant destroy`
    - `git pull`
    - `vagrant up`
    - 문제가 없다면 vagrant ssh 했을 때 자동으로 접속되어야 합니다.
  10. 이 때 화면 뒤에 VirtualBox의 화면에 우분투 터미널이 뜰텐데, 이 창은 무시하세요.
  11. vagrant up을 했던 Git Bash 창에서 `vagrant ssh`를 하면 아래와 같이 서버에 접속이 됩니다.

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
  - Atom: https://atom.io/
  - SublimeText: http://www.sublimetext.com/3  (한글 문제가 있을 수 있습니다.)
  
