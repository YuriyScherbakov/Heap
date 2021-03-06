﻿#include <string.h>
#include <iostream>
#pragma warning(disable : 4996)

char* InpText(char* string);           //Получает строку от пользователя.
double upper(int i, char* text);       //Приводит к нижнему регистру.


int main(void)
{
    char text[80];
    char* textPtrAccessory = NULL;
    char* textPtr = { 0 };
    char  tmp;
    int length = 0;
  
    
    fflush(stdout);

    textPtr = (char*)malloc(80);                 
    if (textPtr)
    {
        sprintf(text, "%s", InpText(textPtr));      //Полученную строку посимвольно сохраняем в массив.
        length=strlen(text);                      //Получаем количество символов.
    }

    textPtr = textPtrAccessory;

    textPtrAccessory = (char*)realloc(textPtrAccessory, sizeof(char) * (length + 1));    //изменяем размер массива под нашу строку.
    if (textPtrAccessory != NULL)
    {
        textPtr = textPtrAccessory;
    }
    else
    {
        printf("Program operation failed! \n");
    }

    free(textPtrAccessory);

    for (int i = 0; i < length; i++)                            //Посимвольно сортируем строку.
    {
        for (int j = i + 1; j < length - 1; j++)
        {

            if (upper(j, textPtr) < upper(i, textPtr))
            {
                tmp = textPtr[i];
                textPtr[i] = textPtr[j];
                textPtr[j] = tmp;
            }
        }
    }

    for (int i = 0; i <= length; i++)                          //Выводим результат на консоль
        printf("%c", textPtr[i]);
    printf(" \n");

    free(textPtr);
    return 0;
}
double upper(int i, char* text)   //Приведение к нижнему регистру.
{
    double a;

    if (text[i] < 97)
    {
        a = text[i] + 31.5;
    }
    else
    {
        a = text[i];
    }
    return a;
}

char* InpText(char* string)       //Получение указателя на строку из консоли, максимальный размер строки задаётся.
{

    int ch;
    int i = 0;
    int inputlength = 80;

       for (i = 0; i < inputlength - 1 && (((ch = getchar()) != '\n') && (ch != EOF)); i++)
    {
        string[i] = ch;
        
    }
    string[i] = '\0';
    
    return string;
}

