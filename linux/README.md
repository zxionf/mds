# gnu/linux

|快捷键|效果|
|--|--|
|ctl+u|删除当前行|
|ctl+w|删除当前词|

|项|效果|
|--|--|
|*|匹配非隐藏文件|
|.[!.]*|匹配以点开头，第二个不是点的|
|.|匹配当前目录|
|.*|匹配当前目录和父目录|

## 常用命令

```bash
# 重命名文件夹
mv name new-name
# 查看当前目录下文件大小
du -sh */
# 查看当前目录下文件大小
du -sh */ | sort -hr 
```

## 技巧

非交互式登录使用bash，交互式登录使用fish(需要保持默认终端为bash)  

```bash
# 写到.bashrc文件中
if [[ $- == *i* ]] && command -v fish &>/dev/null; then
    exec fish
fi
```
