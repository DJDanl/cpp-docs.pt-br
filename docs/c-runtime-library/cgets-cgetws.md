---
title: "_cgets, _cgetws | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_cgetws"
  - "_cgets"
apilocation: 
  - "msvcr100.dll"
  - "msvcr110.dll"
  - "msvcr80.dll"
  - "msvcr120.dll"
  - "msvcr90.dll"
  - "msvcrt.dll"
  - "msvcr110_clr0400.dll"
apitype: "DLLExport"
f1_keywords: 
  - "cgetws"
  - "_cgetws"
  - "_cgets"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _cgetws"
  - "cadeias de caracteres [C++], obtendo do console"
  - "console, obtendo cadeias de caracteres de"
  - "Função _cgets"
  - "Função cgetws"
  - "Função cgets"
ms.assetid: 4d5e134a-58c3-4f62-befd-5d235b0212f4
caps.latest.revision: 32
caps.handback.revision: 32
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _cgets, _cgetws
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém uma cadeia de caracteres no console. Versões mais seguras dessas funções estão disponíveis; consulte [\_cgets\_s, \_cgetws\_s](../Topic/_cgets_s,%20_cgetws_s.md).  
  
> [!IMPORTANT]
>  Essas funções são obsoletas. A partir do Visual Studio 2015, eles não estão disponíveis no CRT. As versões seguras dessas funções, cgets\_s e cgetws\_s, ainda estão disponíveis. Para obter informações sobre essas funções alternativas, consulte [\_cgets\_s, \_cgetws\_s](../Topic/_cgets_s,%20_cgetws_s.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no tempo de execução do Windows. Para obter mais informações, consulte [funções de CRT não têm suportadas com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
char *_cgets(   
   char *buffer   
);  
wchar_t *_cgetws(  
   wchar_t *buffer  
);  
template <size_t size>  
char *_cgets(   
   char (&buffer)[size]  
); // C++ only  
template <size_t size>  
wchar_t *_cgetws(  
   wchar_t (&buffer)[size]  
); // C++ only  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento de dados.  
  
## Valor de retorno  
 `_cgets` e `_cgetws` retornar um ponteiro para o início da cadeia de caracteres, `buffer[2]`. Se `buffer` for `NULL`, essas funções para invocar o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../c-runtime-library/parameter-validation.md). Se a execução puder continuar, retorne `NULL` e defina `errno` para `EINVAL`.  
  
## Comentários  
 Essas funções ler uma cadeia de caracteres do console e armazenar a cadeia de caracteres e seu comprimento no local apontado pela `buffer`. O `buffer` parâmetro deve ser um ponteiro para uma matriz de caracteres. O primeiro elemento da matriz, `buffer[0]`, deve conter o comprimento máximo \(em caracteres\) da cadeia de caracteres a ser lido. A matriz deve conter elementos suficientes para manter a cadeia de caracteres, um caractere nulo de terminação \('\\0'\) e 2 bytes adicionais. A função lê caracteres até um retorno de carro – linha feed combinação \(CR\-LF\) ou o número especificado de caracteres é lido. A cadeia de caracteres é armazenada começando em `buffer[2]`. Se a função lê uma CR\-LF, ele armazena o caractere nulo \('\\0'\). A função, em seguida, armazena o comprimento real da cadeia de caracteres no segundo elemento de matriz, `buffer[1]`.  
  
 Como todas as chaves de edição estão ativas quando `_cgets` ou`_cgetws` é chamada enquanto em um console de janela, pressione a tecla F3 repete a última entrada digitada.  
  
 No C\+\+, essas funções têm sobrecargas de modelo que invocam as contrapartes seguros, mais recentes dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|Rotina TCHAR. h|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_cgetts`|`_cgets`|`_cgets`|`_cgetws`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_cgets`|\< conio.h \>|  
|`_cgetws`|\< conio.h \> ou \< WCHAR \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_cgets.c  
// compile with: /c /W3  
// This program creates a buffer and initializes  
// the first byte to the size of the buffer. Next, the  
// program accepts an input string using _cgets and displays  
// the size and text of that string.  
  
#include <conio.h>  
#include <stdio.h>  
#include <errno.h>  
  
int main( void )  
{  
   char buffer[83] = { 80 };  // Maximum characters in 1st byte  
   char *result;  
  
   printf( "Input line of text, followed by carriage return:\n");  
  
   // Input a line of text:  
   result = _cgets( buffer ); // C4996  
   // Note: _cgets is deprecated; consider using _cgets_s  
   if (!result)  
   {  
      printf( "An error occurred reading from the console:"  
              " error code %d\n", errno);  
   }  
   else  
   {     
      printf( "\nLine length = %d\nText = %s\n",  
              buffer[1], result );  
   }  
}  
```  
  
```Output  
  
A line of input.Linha de texto, seguido por um retorno de carro de entrada: comprimento da linha = 16 Text = uma linha de entrada.  
```  
  
## Consulte também  
 [Console e E\/S de porta](../c-runtime-library/console-and-port-i-o.md)   
 [\_getch, \_getwch](../Topic/_getch,%20_getwch.md)