# Морфологические фильтры в обработке документов

Лабораторная работа

Задание: улучшить (с точки зрения человека) изображение документа с целью облегчения его прочтения.

Класс изображений — фотографии рукописных документов на линованной бумаге.
	* фотографии, чтобы были проблемы с неравномерностью освещения (рудиментарная цветоконстантность)
	* рукописных, чтобы важно было сохранить градации серого для сохранения читаемости
	* на линованной бумаге, чтобы можно было просто сделать разворот.


Решение
	* 

Продолжения задачи
	
	* уменьшить (downscale) изображение с сохранением или увеличением его четкости или контрастности (high-contrast downscale)
	* устранить шум с фона, чтобы он был "гладкий" (попробовать билатеральный фильтр)
	* сделать то же, но в цвете (придется понять, что мы хотим: покрасить в "идеально-чернильный" синий или таки оценить по картинке — с соблюдением цветоконстантности)
	* выправить искажения

## Возможные проблемы

*Буст не поставлен.* Буст не сильно нужен, можно убрать.
*OpenCV не загружает изображения.* Нужно проверить установку, возможно, соответствующие кодеки не собрались. Решение — переустановка.
