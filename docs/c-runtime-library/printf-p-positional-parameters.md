---
title: "Par&#226;metros posicionais printf_p | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr120.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr90.dll"
  - "msvcr80.dll"
  - "msvcr100.dll"
apitype: "DLLExport"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _printf_p, parâmetros posicionais"
  - "Função printf_p, parâmetros posicionais"
ms.assetid: beb4fd85-a7aa-4665-9085-2c907a5b9ab0
caps.latest.revision: 17
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Par&#226;metros posicionais printf_p
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Parâmetros posicionais fornecem a capacidade de especificar pelo número de argumentos deve ser substituído em um campo em uma cadeia de caracteres de formato.  O seguinte parâmetro posicional`printf`funções estão disponíveis:  
  
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)  
 [\_printf\_p, \_printf\_p\_l, \_wprintf\_p, \_wprintf\_p\_l](../c-runtime-library/reference/printf-p-printf-p-l-wprintf-p-wprintf-p-l.md)  
  
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)  
 [sprintf\_p, sprintf\_p\_l, swprintf\_p, swprintf\_p\_l](../c-runtime-library/reference/sprintf-p-sprintf-p-l-swprintf-p-swprintf-p-l.md)  
  
 [\_cprintf, \_cprintf\_l, \_cwprintf, \_cwprintf\_l](../c-runtime-library/reference/cprintf-cprintf-l-cwprintf-cwprintf-l.md)  
 [\_cprintf\_p, \_cprintf\_p\_l, \_cwprintf\_p, \_cwprintf\_p\_l](../c-runtime-library/reference/cprintf-p-cprintf-p-l-cwprintf-p-cwprintf-p-l.md)  
  
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)  
 [\_fprintf\_p, \_fprintf\_p\_l, \_fwprintf\_p, \_fwprintf\_p\_l](../c-runtime-library/reference/fprintf-p-fprintf-p-l-fwprintf-p-fwprintf-p-l.md)  
  
 [vprintf, \_vprintf\_l, vwprintf, \_vwprintf\_l](../c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l.md)  
 [\_vprintf\_p, \_vprintf\_p\_l, \_vwprintf\_p, \_vwprintf\_p\_l](../c-runtime-library/reference/vprintf-p-vprintf-p-l-vwprintf-p-vwprintf-p-l.md)  
  
 [vfprintf, \_vfprintf\_l, vfwprintf, \_vfwprintf\_l](../c-runtime-library/reference/vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md)  
 [\_vfprintf\_p, \_vfprintf\_p\_l, \_vfwprintf\_p, \_vfwprintf\_p\_l](../c-runtime-library/reference/vfprintf-p-vfprintf-p-l-vfwprintf-p-vfwprintf-p-l.md)  
  
 [vsprintf, \_vsprintf\_l, vswprintf, \_vswprintf\_l, \_\_vswprintf\_l](../c-runtime-library/reference/vsprintf-vsprintf-l-vswprintf-vswprintf-l-vswprintf-l.md)  
 [\_vsprintf\_p, \_vsprintf\_p\_l, \_vswprintf\_p, \_vswprintf\_p\_l](../Topic/_vsprintf_p,%20_vsprintf_p_l,%20_vswprintf_p,%20_vswprintf_p_l.md)  
  
## Especificando parâmetros posicionais  
  
##### Indexação de parâmetro  
 Por padrão as funções posicionais comportam idêntico à posição não aquelas, se nenhuma formatação posicional estiver presente.  Parâmetros posicionais são especificados usando o formato "`%m$x`", onde`m`denota um número ordinal que indica a posição do parâmetro na lista de parâmetros, que precedem a cadeia de caracteres de formato e `x`indica o tipo de caractere de campo do tipo especificado no`printf`função.  Os parâmetros na lista são indexados a partir do valor de 1 para o primeiro elemento na lista e assim por diante.  Para obter informações adicionais sobre os caracteres de campo de tipo, consulte[Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md).  
  
 Para obter um exemplo desse comportamento:  
  
```  
_printf_p("%1$s %2$s", "November", "10");  
```  
  
 impressão  
  
```  
November 10  
```  
  
 A ordem dos números usados não precisa corresponder a ordem dos argumentos fornecido.  Assim, o seguinte é válido:  
  
```  
_printf_p("%2$s %1$s", "November", "10");  
```  
  
 impressão  
  
```  
10 November  
```  
  
 Parâmetro pode ser usado mais de uma vez durante a formatação, diferentemente em tradicional cadeias de formato, então esse  
  
```  
_printf_p("%1$d times %1$d is %2$d", 10, 100);  
```  
  
 impressão  
  
```  
10 times 10 is 100  
```  
  
 No entanto, todos os argumentos devem ser usados pelo menos uma vez em algum lugar na cadeia de caracteres de formato.  
  
 O número máximo de parâmetros posicionais permitido em uma cadeia de caracteres de formato é fornecido pelo`_ARGMAX`.  
  
##### Largura e precisão  
 Quando o \* símbolo é usado para especificar que a largura ou precisão deve ser determinado a partir de um argumento, em seguida, a posição do valor largura ou precisão deve aparecer imediatamente seguinte a \* símbolo.  Por exemplo,  
  
```  
_printf_p("%1$*2$s","Hello", 10);  
```  
  
 ou  
  
```  
_printf_p("%2$*1$s",10, "Hello");  
```  
  
##### Misturando argumentos posicionais posicional e não  
 Parâmetros posicionais não podem ser combinados com parâmetros não posicionais na mesma cadeia de caracteres de formato.  No entanto,`printf_p`e funções relacionadas ainda oferece suporte a parâmetros não posicionais em cadeias de caracteres de formato que contém sem parâmetros posicionais.  
  
## Exemplo  
  
```  
// positional_args.c  
// Positional arguments allow the specification of the order  
// in which arguments are consumed in a formatting string.  
  
#include <stdio.h>  
  
int main(int argc, char *argv[])  
{  
    int     i = 1,  
            j = 2,  
            k = 3;  
    double  x = 0.1,  
            y = 0.2,  
            z = 0.3;  
    char    *s1 = "abc",  
            *s2 = "def",  
            *s3 = "ghi";  
  
    // If positional arguments are unspecified,  
    // normal input order is used.  
    _printf_p("%d %d %d\n", i, j, k);  
  
    // Positional args are numbers indicating the  
    // argument enclosed in curly braces.  
    _printf_p("%3$d %1$d %2$d\n", i, j, k);  
  
    // The same positional argument may be reused.  
    _printf_p("%1$d %2$d %1$d\n", i, j);  
  
    _printf_p("%1$s %2$s %3$s\n", s1, s2, s3);  
  
    _printf_p("%3$s %1$s %2$s\n", s1, s2, s3);  
}  
```  
  
  **1 2 3**  
**3 1 2**  
**1 2 1**  
**ghi do abc def**  
**GHI abc def**   
## Consulte também  
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)   
 [Especificação de largura printf](../c-runtime-library/printf-width-specification.md)   
 [Especificação da precisão](../c-runtime-library/precision-specification.md)