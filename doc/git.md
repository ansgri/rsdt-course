Банк тезисов
------------

Посмотреть tracking info для веток

    git branch -vv

Выгрузка данных из удаленного репозитория

    git fetch origin-private

Установить tracking upstream reference:

    git branch -u origin/master

Это нужно делать, если команда `git pull origin` говорит следующее:
  > _You asked to pull from the remote 'origin', but did not specify
a branch.
  > Because this is not the default configured remote for your current branch, you must specify a branch on the command line._

Находясь в feature branch, учесть изменения, произошедшие в его основе (обычно master):

    git merge master

Вот этого лучше никогда не делать из-за того, что команда содержит в себе неявный merge:

    git pull remote-name branch-name

Вместо этого лучше всегда пользоваться только `git pull remote-name`, поскольку она производит объединения согласно tracking info.

Ответ на "warning: push.default is unset": см. http://stackoverflow.com/questions/13148066/; если кратко, то matching запушит все отслежываемые в данном удаленном репозитории ветки, а simple — только текущую. Говорят, безопасней пользоваться simple, но тогда нужно не забывать публиковать все интересующие ветки по отдельности.

    git config --global push.default simple

Псевдонимы
    
    git config --global alias.ci commit
    git config --global alias.st status    


