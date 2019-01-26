### Folk this master repo to your account 
Click Fork button on the top right. You can find it next to "Watch" and "Star" button


### Clone this master repo to your local machine
Once the fork repo is created, click "Clone or Download" button and copy url, or copy `https://github.com/YourUserName/cppeeps.git`

In your bash/terminal,

```
git clone https://github.com/YourUserName/cppeeps.git
```

### Set upstream
```
git remote add upstream https://github.com/rjisoo/cppeeps.git
```

If you type
`
git remote -v
`
you should see the log like this:
```
origin	https://github.com/YourUserName/cppeeps.git (fetch)
origin	https://github.com/YourUserName/cppeeps.git (push)
upstream	https://github.com/rjisoo/cppeeps.git (fetch)
upstream	https://github.com/rjisoo/cppeeps.git (push)
```

### Set push command
```
git push -u origin master
```

after run this command once, you can push to your forked repo by just typing
```
git push
```
