# 1-1. Set up environment
```
$ brew install asdf
$ echo -e "\n. $(brew --prefix asdf)/libexec/asdf.sh" >> ~/.zshrc
$ exec $SHELL -l
$ echo "yarn\ntypescript\nts-node\ntypesync\nnpm-check-updates" > .default-npm-packages
$ asdf plugin add nodejs
$ asdf install nodejs latest
$ asdf global nodejs latest
```
# 1-2. Create a project with Vite
```
$ yarn create vite hello-world --template=react-ts
$ cd hello-world
$ yarn
$ yarn dev
$ yarn dev - --port 3001
```
