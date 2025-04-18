#!/bin/bash

# Переходим в папку с вашим проектом
cd /d/CodeSources

# Получаем последние изменения с удалённого репозитория
git pull origin main --rebase

# Добавляем все изменения в индекс
git add .

# Делаем коммит (можно добавить автоматическое сообщение)
git commit -m "New changes"

# Отправляем изменения в удалённый репозиторий
git push -u origin main
