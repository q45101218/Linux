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

>### 3.message queue(system V)
  firstly you should create a message queue to service your communication by msgget(),and you must use msgctl() to destory it when the message queue created.<br>
  if you don't use msgget() to destory massage queue you create,the message queue always stay in your IPC,though the process which use the message queue or create message queue end.<br>
  the message queue is a full duplex way to be used to process communication<br>
  use msgsnd() to send message queue information,and use msgrec() to receive the information that is in message queue.<br>

>### 4.shared memory(system V)
  shared memory must be most efficient way beacasue kornel directly control it.<br>

>### 5.semaphore(system V)
  use semget() to create a set of semaphore.<br>

## 4.signal
  use signal() to set signal and handler function,and when recieve the special signal which we use signal() setting signal,the process will use handler function to handle the signal.<br>


## 5.thread(POSIX)
  create POXIS version thread though pthread\_create(),and then PCB add a struct to administrate this thread.<br>
  when you want to get the information about id of thread,you can use pthread\_self(),or though the pthread\_create() to get the id.<br>
