# Test for Linux
It's my Linux operator system test.

## 1.Process
  by using fork(),parent creat a child process.<br>
  using vfork(),parent was altered by child process.<br>
  if child don't exit,child will be a orphan process after parent exit.Then bash will adopt this child process.<br>
  if parent process don't wait child'quit,child process will be a zombie process,which is occupying the computer'source all the time.<br>
  the difference between wait() and waitpid().<br>
  the difference between exit() and \_exit().<br>
  
## 2.IO
  we use system calling write(),read(),open(),close() other than fopen(),fclose(),fread(),fclose() in lib.<br>
  system calling hasn't buffer and lib function has buffer,duplicating in child process.<br>
  distinction between soft link and hard link.<br>

## 3.Communication
>### 1.anonymous pipe
  pipe() and pipe2(),pipe2() can set a method which will set erron when pipe was be filled with datas or pipe hasn't datas to read.<br>
  pipe description can be duplicated by fork() to child process that refer to same pipe.<br>
  if close read of pipe(pipe\[0]),process will receive a signal which will close process.<br>
  pipe() only was used in Biological process.<br>

>### 2.FIFO
  make FIFO file used to communication.<br>
  a FIFO special file is simmilar to a pipe,and they have the similar function and property.<br>
  after creat a FIFO file,operation of FIFO is like operating a reguler file.<br>
  use mkfifo() to create a FIFO file,umask() to change permission.<br>
  if close write of FIFO,read of FIFO can read until FIFO resources were used up.<br>
  if close read of FIFO,process will exit immediately.<br>
  while process is finished,the FIFO is also finished.<br>

>### 3.message queue

