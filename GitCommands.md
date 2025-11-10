## SSH Key Generation steps 
**To Create the ssh basic key pairs**

    cd ~
    cd .ssh 
    mkdir .ssh 
    cd .ssh 
    pwd 
    ssh-keygen -t rsa -C "<email id>"

**Check the access to**

    Github 
        ssh -T git@github.com 
    bitbucket  
        ssh -Tvvv git@bitbucket.org 

## Git Frequently Used Commands 
**Configuring**

    Git Config (Global/User-level) Syntax 
        git config --global setting value 

    Configure User and Email 
        git config --global user.name "Revanth K Bayyana" 
        git config --global user.email "<email id>" 

    Listing All Global Configuration Settings 
        git config --global --list 

    Seeing Git's User-based Config file 
        cat ~/.gitconfig 

**Fresh Start**

    pwd 
    cd <projects>/ 
    git init <git-proj-name> 
>Note: [git-proj-folder] is optional. If not supplied, Git will initialize the current directory. 


**Commands for committing**
    
    git add README.md
    git commit -m "Initial commit"

>Note: Staging commands as below for more clarity

| Command | Description |
|---|---|
| git add .   | adds new + modified, skips deleted  |
| git add -u   | adds modified + deleted, skips new |
| git add -A  | adds all (new, modified, deleted)  |


    git push  (to main)

    git push origin <branch> (to the branch)

    git push -u origin <branch-name>  (to the new branch branch-name)
    



 
 **!! Important push**   

    git push --force-with-lease
>Note: When you rebase or rewrite commit history intentionally.
    `--force-with-lease` is safer — it won’t overwrite others’ work.


**Unstage the files or directories**
    
    git restore --staged .
    git restore --staged build/compile_commands.json
**Git graphs**

    git log --oneline --graph --name-only


**Create alias for long commands as below**

    git config --global alias.loggraph "log --oneline --graph --color"
Then  we can use the below custom command

    git loggraph

**Git amending one of the commits**

1. Start the interactive Rebase until or one below commits (for the below done for one commit before)

    `git rebase -i HEAD~3 `

    It opens a editor with 3 commit hashes with `pick` 

        pick 18627eb 1st commit
        pick 121a66a 2nd commit
        pick dae18d0 3rd commit



    then we need to change the `pick` → `edit` for the commit which we wanted to modify then save and close the editor.

        pick 18627eb 1st commit
        edit 121a66a 2nd commit
        pick dae18d0 3rd commit



2. Do the necessary modification which we wanted to do for the files

    `git add -u (or)`
    `git add .`

3.  Then proceed with amending the commit
    
    `git commit --amend`

    This opens your editor to amend the commit message. 
4. Continue Rebase for applying the other commits

    `git rebase --continue`
    Then it opens the Apllying the remaining commits until it finishes the rebase.
5. Push the final changes..... Done!!



test


<pre>
Code block for testing

</pre>