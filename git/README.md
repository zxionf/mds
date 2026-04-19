当前HEAD, 前一个版本HEAD^, 前两个版本HEAD^^, 前一百个版本HEAD~100  
git reset --hard HEAD^ ,回退到上一个版本的已提交状态  
git reset --soft HEAD^ ,回退到上一个版本的未提交状态  
git reset --mixed HEAD^ ,回退到上一个版本的已添加但未提交状态  
git checkout -- file ,丢弃工作区的修改  
git remote add origin gitpath ,添加远程仓库  
git push -u origin master ,推送,-u创建并关联到master分支  
git checkout -b dev ,创建并切换到dev分支  
git switch -c dev ,创建并切换到dev分支  
git branch dev ,创建dev分支  
git checkou dev ,切换到dev分支  
git branch ,查看当前分支  
git merge dev ,合并dev分支  
git branch -d <name> ,删出分支  
git stash ,暂存工作区  
git merge --no-ff -m "merged bug fix 101" issue-101  
git stash list  
git stash pop ,恢复并删除stash内容  
git stash apply ,恢复stash内容  
git stash drop ,删除stash内容  