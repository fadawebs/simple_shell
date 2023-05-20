
# Simple_shell
![233871011-48a38205-ac8b-4c3a-bbb9-16618cd5fd5b](https://user-images.githubusercontent.com/36473098/233871153-f188a94d-8860-4218-811d-cdd65685d8b9.jpg)

## Background Context
Write a simple UNIX command interpreter.
 ^ “The Gates of Shell”, by [Spencer Cheng](https://intranet.alxswe.com/rltoken/AtYRSM03vJDrko9xHodxFQ), featuring [Julien Barbier](https://intranet.alxswe.com/rltoken/-ezXgcyfhc8qU1DeUInLUA)


## Resources
### Read or watch:

[Unix shell](https://en.wikipedia.org/wiki/Unix_shell) <br>
[Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell) <br>
[Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson) <br>
[Everything you need to know to start coding your own shell concept page](https://intranet.alxswe.com/concepts/64) <br>
man or help:

sh (Run sh as well)


## List of allowed functions and system calls
* access (man 2 access)<br>
* chdir (man 2 chdir)<br>
* close (man 2 close)<br>
* closedir (man 3 closedir)<br>
* execve (man 2 execve)<br>
* exit (man 3 exit)<br>
* _exit (man 2 _exit)<br>
* fflush (man 3 fflush)<br>
* fork (man 2 fork)<br>
* free (man 3 free)<br>
* getcwd (man 3 getcwd)<br>
* getline (man 3 getline)<br>
* getpid (man 2 getpid)<br>
* isatty (man 3 isatty)<br>
* kill (man 2 kill)<nr>
* malloc (man 3 malloc)<br>
* open (man 2 open)<br>
* opendir (man 3 opendir)<br>
* perror (man 3 perror)<br>
* read (man 2 read)<br>
* readdir (man 3 readdir)<br>
* signal (man 2 signal)<br>
* stat (__xstat) (man 2 stat)<br>
* lstat (__lxstat) (man 2 lstat)<br>
* fstat (__fxstat) (man 2 fstat)<br>
* strtok (man 3 strtok)<br>
* wait (man 2 wait)<br>
* waitpid (man 2 waitpid)<br>
* wait3 (man 2 wait3)<br>
* wait4 (man 2 wait4)<br>
* write (man 2 write)<br>


## Requirements
### General
* Allowed editors: vi, vim, emacs <br>
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89` <br>
* All your files should end with a new line <br>
* A `README.md` file, at the root of the folder of the project is mandatory <br>
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl <br>
* Your shell should not have any memory leaks <br>
* No more than 5 functions per file <br>
* All your header files should be `include guarded` <br>
* Use system calls only when you need to (why?) <br>
* Write a README with the description of your project <br>
* You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.


## env_listment

<!-- ubuntu -->
<a href="https://ubuntu.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Ubuntu&color=E95420&logo=Ubuntu&logoColor=E95420&labelColor=2F333A" alt="Suite CRM"></a>
OS: Ubuntu 20.04 LTS
<!-- bash -->
<a href="https://www.gnu.org/software/bash/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GNU%20Bash&color=4EAA25&logo=GNU%20Bash&logoColor=4EAA25&labelColor=2F333A" alt="terminal"></a>
<!-- c -->	<a href="https://www.cprogramming.com/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=C%20Language&color=5C6BC0&logo=c&logoColor=A8B9CC&labelColor=2F333A" alt="C Low level programming language"></a>
Language: C
Compiler: gcc 9.3.0
<!-- vim -->
<a href="https://www.vim.org/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Vim&color=019733&logo=Vim&logoColor=019733&labelColor=2F333A" alt="Suite CRM"></a>
Editor: VIM 8.1.2269
<!-- git -->
<a href="https://git-scm.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Git&color=F05032&logo=Git&logoColor=F05032&labelColor=2F333A" alt="git distributed version control system"></a>
Control version: Git
<!-- github -->
<a href="https://github.com" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GitHub&color=181717&logo=GitHub&logoColor=f2f2f2&labelColor=2F333A" alt="Github"></a>

Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

<br>


## Compilation 
Your shell will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Testing
Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### Example
```
_atoi.c     env_list.c  getenv.c     history.c  main.c    README.md     string.c
AUTHORS     errors.c   getinfo.c    hsh        memory.c  realloc.c     string1.c
builtin.c   errors1.c  getLine.c    lists.c    output/   shell.h       tokenizer.c
builtin1.c  exits.c    help_files/  lists1.c   parser.c  shell_loop.c  vars.c
```


## Flowchart
![flowchart drawio (2)](https://user-images.githubusercontent.com/36473098/234982394-336a9845-c20f-454c-882d-869c880f174f.png)
[Source File / Collaboration](https://drive.google.com/file/d/13yyknT52N1JvjNwGSeiQgjS7pCeDGAea/view?usp=sharing)



## Contributors
<!-- github -->
<a href="https://github.com" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GitHub&color=181717&logo=GitHub&logoColor=f2f2f2&labelColor=2F333A" alt="Github"></a>

Beekaz Okafor [Github](https://github.com/beekaz)   <br>
Theophilus Samuel [GitHub](https://github.com/ConnectedDot)
