# Test for Linux
It's my Linux operator system test.

>1.Process
  by using fork(),parent creat a child process.
  using vfork(),parent was altered by child process.
  if child don't exit,child will be a orphan process after parent exit.Then bash will adopt this child process.
  if parent process don't wait child'quit,child process will be a zombie process,which is occupying the computer'source all the time.
  the difference between wait() and waitpid().
  the difference between exit() and _exit().
