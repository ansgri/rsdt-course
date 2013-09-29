Настройка рабочей станции Windows
=================================

Введение
--------

Описаны все этапы настройки компьютера от абсолютно чистого состояния до успешно собирающегося в Visual Studio 2008 SP1 на Windows 7 [cpp-boilerplate-minimal](https://github.com/ansgri/cpp-boilerplate-minimal).

Контрольный список
------------------

1. Базовая система 
    1. Установить Windows
    1. Установить обновления Windows
        * Потребуется множество загрузок и перезагрузок, пока новые не перестанут появляться
    1. Установить архиватор
        * _[7-zip](http://www.7-zip.org/) is strongly recommended_
    1. Установить драйвера для аппаратного обеспечения
        * для типичного ноутбука минимальный набор обычно включает чипсет, дисплей, тачпад
1. Базовые средства разработки
    1. Установить Visual Studio 2008
        * Если она в виде образа диска (.iso), установить эмулятор дисковода (_Alcohol 52% is recommended_), либо выпотрошить образ архиватором
        * Берем _английскую_ версию
        * Выбираем Custom Install, там выключаем все компоненты, кроме C++, но C++ ставим всю полностью
    1. Установить Service Pack 
        * В нем, например, набор библиотек `tr1`, без которых жить нельзя
    1. Установить CMake
        * Когда спросит, добавлять ли в путь, стоит согласиться (add to path for all users)
    1. Установить текстовый редактор
        * _[Sublime Text](http://www.sublimetext.com/3) is strongly recommended_
            * Не забудьте [пролистать документацию](http://docs.sublimetext.info/en/latest/index.html), установить [Package Control](https://sublime.wbond.net/), затем через него All Autocomplete и CMake
        * Альтернативы: Emacs, Vim, Notepad++
    1. Установить TortoiseSVN
        * Не забудьте в списке компонентов включить 'install command-line tools'
    1. Установить TortoiseGit
        1. Установить MsysGit
        2. Установить собственно TortoiseGit
    1. Установить Python 2.7 (т.е. самую новую двойку)
        * Если ОС x64, важно взять x64
        * Руководство по настройке питона выйдет отдельным томом
1. Специальные библиотеки
    1. Установить boost
        * Готовые сборки новых версий раздобыть проблематично, так что собираем из исходников
        1. Команда сборки примерно такая: `bootstrap && b2 shared variant=release threading=multi runtime-link=shared`
        1. Создать переменную окружения @BOOST_ROOT@, указать на корень распакованных и собранных исходников
        1. Добавить в системную переменную `PATH` путь к *.dll (примерно ёboost_1_54_0\stage\lib`) 
    1. Установить OpenCV
        * Скорей всего легко настраивается при установке готового дистрибутива, но интересней-то собрать из исходников
        1. `git clone git://github.com/Itseez/opencv.git`
        2. `git checkout 2.4.6` (или другая версия; чтобы посмотреть имеющиеся, выполнить `git tag`)
        3. `mkdir build.user && cd build.user && cmake .. && start OpenCV.sln`
        4. Собрать всё (F7) в Debug и Release конфигурациях
        5. Собрать проект `CMake Targets/INSTALL` в Debug и Release конфигурациях
        6. Создать переменную окружения `OpenCV_DIR`, указав в ней полный путь папки install, появившейся рядом с OpenCV.sln
        7. Добавить в системную переменную `PATH` путь к *.dll (примерно `opencv\build.user\install\bin`)
1. Проверка сборки cpp-boilerplate-minimal
    1. `git clone https://github.com/ansgri/cpp-boilerplate-minimal.git`
    2. `cd cpp-boilerplate-minimal && mkdir build.vc9 && cmake ..`
    3. `start cppbp.sln`, собрать всё (F7)
    4. Запустить `ocv_camshift.exe` (папка `bin.win32.{debug|release}`)
        * Если при запуске ругается на отстутствие dll-библиотек, значит, забыли добавить OpenCV в системный путь
