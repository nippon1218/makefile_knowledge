## Makefile介绍

[TOC]

### 一: Makefile的规则

``` makefile
target ... : prerequisites ... command
...
...
```
target 也就是一个目标文件，可以是 Object File，也可以是执行文件。还可以是一个 标签（Label），对于标签这种特性，在后续的“伪目标”章节中会有叙述。 prerequisites 就是，要生成那个 target 所需要的文件或是目标。 command 也就是 make 需要执行的命令。（任意的 Shell 命令）
这是一个文件的依赖关系， 也就是说， target 这一个或多个的目标文件依赖于 prerequisites 中的文件，其生成规则定义在 command 中。说白一点就是说，prerequisites 中如果有一个以上的文件比 target 文件要新的话，command 所定义的命令就会被执行。这 就是 Makefile 的规则。也就是 Makefile 中最核心的内容。

说到底，Makefile 的东西就是这样一点，好像我的这篇文档也该结束了。呵呵。还不尽然，这是<font color = red>Makefile</font>的主线和核心，但要写好一个Makefile还不够，我会以后面一点一点 地结合我的工作经验给你慢慢到来。内容还多着呢。：）

### 二：示例
```makefile
edit : main.o kbd.o command.o display.o \ 
insert.o search.o files.o utils.o 
cc -o edit main.o kbd.o command.o display.o \ 
insert.o search.o files.o utils.o

main.o : main.c defs.h 
cc -c main.c 
kbd.o : kbd.c defs.h command.h 
cc -c kbd.c command.o : command.c defs.h command.h cc -c command.c 
display.o : display.c defs.h buffer.h 
cc -c display.c 
insert.o : insert.c defs.h buffer.h 
cc -c insert.c 
search.o : search.c defs.h buffer.h 
cc -c search.c 
files.o : files.c defs.h buffer.h command.h 
cc -c files.c
utils.o : utils.c defs.h 
cc -c utils.c 
clean :
rm edit main.o kbd.o command.o display.o \ 
insert.o search.o files.o utils.o
```

反斜杠`（\）`是换行符的意思。这样比较便于 Makefile 的易读。我们可以把这个内容保 存在文件为“Makefile”或“makefile”的文件中，然后在该目录下直接输入命令“make” 就可以生成执行文件 edit。如果要删除执行文件和所有的中间目标文件，那么，只要简单 地执行一下“make clean”就可以了。

在这个 makefile 中，目标文件（target）包含：执行文件 edit 和中间目标文件（*.o）， 依赖文件（prerequisites）就是冒号后面的那些 .c 文件和 .h 文件。每一个 .o 文件都 有一组依赖文件，而这些 .o 文件又是执行文件 edit 的依赖文件。依赖关系的实质上就是 说明了目标文件是由哪些文件生成的，换言之，目标文件是哪些文件更新的。

在定义好依赖关系后，后续的那一行定义了如何生成目标文件的操作系统命令，一定要 以一个 Tab 键作为开头。记住，make 并不管命令是怎么工作的，他只管执行所定义的命令。 make 会比较 targets 文件和 prerequisites 文件的修改日期，如果 prerequisites 文件的 日期要比 targets 文件的日期要新，或者 target 不存在的话，那么，make 就会执行后续定 义的命令。

这里要说明一点的是，clean 不是一个文件，它只不过是一个动作名字，有点像 C 语言 中的 lable 一样，其冒号后什么也没有，那么，make 就不会自动去找文件的依赖性，也就 不会自动执行其后所定义的命令。要执行其后的命令，就要在 make 命令后明显得指出这个 lable 的名字。这样的方法非常有用，我们可以在一个 makefile 中定义不用的编译或是和 编译无关的命令，比如程序的打包，程序的备份，等等。


### 三：make如何工作

在默认的方式下，也就是我们只输入 `make` 命令。那么，
 1、make 会在当前目录下找名字叫“Makefile”或“makefile”的文件。 
 2、如果找到，它会找文件中的第一个目标文件（target），在上面的例子中，他会找到 “edit”这个文件，并把这个文件作为最终的目标文件。

3、如果 edit 文件不存在，或是 edit 所依赖的后面的 .o 文件的文件修改时间要比 edit 这个文件新，那么，他就会执行后面所定义的命令来生成 edit 这个文件。

4、如果 edit 所依赖的.o 文件也存在，那么 make 会在当前文件中找目标为.o 文件的依 赖性，如果找到则再根据那一个规则生成.o 文件。（这有点像一个堆栈的过程）

5、当然，你的 C 文件和 H 文件是存在的啦，于是 make 会生成 .o 文件，然后再用 .o 文 件生命 make 的终极任务，也就是执行文件 edit 了。

这就是整个 make 的依赖性，make 会一层又一层地去找文件的依赖关系，直到最终编译出第一个目标文件。在找寻的过程中，如果出现错误，比如最后被依赖的文件找不到，那么 make 就会直接退出，并报错，而对于所定义的命令的错误，或是编译不成功，make 根本不 理。make 只管文件的依赖性，即，如果在我找了依赖关系之后，冒号后面的文件还是不在， 那么对不起，我就不工作啦。

通过上述分析，我们知道，像 clean 这种，没有被第一个目标文件直接或间接关联，那 么它后面所定义的命令将不会被自动执行， 不过， 我们可以显示要 make 执行。 即命令 ——“make clean”，以此来清除所有的目标文件，以便重编译。

于是在我们编程中，如果这个工程已被编译过了，当我们修改了其中一个源文件，比如 file.c，那么根据我们的依赖性，我们的目标 file.o 会被重编译（也就是在这个依性关系 后面所定义的命令），于是 file.o 的文件也是最新的啦，于是 file.o 的文件修改时间要比 edit 要新，所以 edit 也会被重新链接了（详见 edit 目标文件后定义的命令）。

而如果我们改变了“command.h”，那么，kdb.o、command.o 和 files.o 都会被重编译， 并且，edit 会被重链接。




