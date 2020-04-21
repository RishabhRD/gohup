# gohup
gohup is a utility to execute any command immune to SIGHUP. That means, program would still execute if you close the terminal.

## How is it different from nohup?
- It does not create any nohup.out
- It ignores any output to stdout and stderr
- It let's you to continue your workflow as you run the command.

## Philosphy behind it
gohup is based on simple philosphy, many times we just need to execute the program in backgroud regardless of its output from our terminal
and continue our workflow without any interrption. This program let's you do that, so you can just run the program and forget about it or 
work on it if it's GUI application.

## Is it a replacement to nohup?
Not fully. If you need the program's output executing upon this kind of program then nohup is your requirement for that task. However, if you just need a background 
process or a GUI application without need of any log or output, and you want to continue with your terminal wokflow without any interruption
gohup is suitable for the task.
