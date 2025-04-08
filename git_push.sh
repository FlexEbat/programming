#!/bin/bash

# Переходим в папку с вашим проектом
cd /d/CodeSources

# Получаем последние изменения с удалённого репозитория
git pull origin main --rebase

# Проверяем, есть ли изменения
if [[ $(git status --porcelain) ]]; then
    # Если есть изменения, добавляем их в индекс
    git add .

    # Делаем коммит
    git commit -m "Auto commit"

    # Отправляем изменения в удалённый репозиторий
    git push -u origin main
else
    echo "No changes to commit, everything is up-to-date."
fi
