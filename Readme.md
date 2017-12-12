# Test for Linux
It's my Linux operator system test.

##1.Process
  >by using fork(),parent creat a child process.<br>
  >using vfork(),parent was altered by child process.<br>
  >if child don't exit,child will be a orphan process after parent exit.Then bash will adopt this child process.<br>
  >if parent process don't wait child'quit,child process will be a zombie process,which is occupying the computer'source all the time.<br>
  >the difference between wait() and waitpid().<br>
  >the difference between exit() and _exit().<br>
