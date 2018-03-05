---
title: "Parâmetros posicionais printf_p | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apilocation:
- msvcr120.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr90.dll
- msvcr80.dll
- msvcr100.dll
apitype: DLLExport
dev_langs:
- C++
helpviewer_keywords:
- _printf_p function, positional parameters
- printf_p function, positional parameters
ms.assetid: beb4fd85-a7aa-4665-9085-2c907a5b9ab0
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 10d48a899b2d2e6ad644c385c2b2116353c20f8e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="printfp-positional-parameters"></a>Parâmetros posicionais printf_p
Parâmetros posicionais fornecem a capacidade de especificar por número quais dos argumentos deve ser substituído em um campo de uma cadeia de caracteres. As funções `printf` do seguinte parâmetro posicional estão disponíveis:  
  
| Funções printf não posicionais | Equivalentes de parâmetro posicional |  
|---|---|  
|[printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)|[_printf_p, _printf_p_l, _wprintf_p, _wprintf_p_l](../c-runtime-library/reference/printf-p-printf-p-l-wprintf-p-wprintf-p-l.md)|  
|[sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)|[_sprintf_p, _sprintf_p_l, _swprintf_p, _swprintf_p_l](../c-runtime-library/reference/sprintf-p-sprintf-p-l-swprintf-p-swprintf-p-l.md)|  
|[_cprintf, _cprintf_l, _cwprintf, _cwprintf_l](../c-runtime-library/reference/cprintf-cprintf-l-cwprintf-cwprintf-l.md)|[_cprintf_p, _cprintf_p_l, _cwprintf_p, _cwprintf_p_l](../c-runtime-library/reference/cprintf-p-cprintf-p-l-cwprintf-p-cwprintf-p-l.md)|  
|[fprintf, _fprintf_l, fwprintf, _fwprintf_l](../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)|[_fprintf_p, _fprintf_p_l, _fwprintf_p, _fwprintf_p_l](../c-runtime-library/reference/fprintf-p-fprintf-p-l-fwprintf-p-fwprintf-p-l.md)|  
|[vprintf, _vprintf_l, vwprintf, _vwprintf_l](../c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l.md)|[_vprintf_p, _vprintf_p_l, _vwprintf_p, _vwprintf_p_l](../c-runtime-library/reference/vprintf-p-vprintf-p-l-vwprintf-p-vwprintf-p-l.md)|  
|[vfprintf, _vfprintf_l, vfwprintf, _vfwprintf_l](../c-runtime-library/reference/vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md)|[_vfprintf_p, _vfprintf_p_l, _vfwprintf_p, _vfwprintf_p_l](../c-runtime-library/reference/vfprintf-p-vfprintf-p-l-vfwprintf-p-vfwprintf-p-l.md)|  
|[vsprintf, _vsprintf_l, vswprintf, _vswprintf_l, \__vswprintf_l](../c-runtime-library/reference/vsprintf-vsprintf-l-vswprintf-vswprintf-l-vswprintf-l.md)|[_vsprintf_p, _vsprintf_p_l, _vswprintf_p, _vswprintf_p_l](../c-runtime-library/reference/vsprintf-p-vsprintf-p-l-vswprintf-p-vswprintf-p-l.md)|  
  
## <a name="how-to-specify-positional-parameters"></a>Como especificar parâmetros posicionais  
  
### <a name="parameter-indexing"></a>Indexação de parâmetro  
Por padrão, se nenhuma formatação posicional estiver presente, as funções posicionais tem comportamento idêntico as não posicionais. Especifique o parâmetro posicional para formatar usando `%n$` no início do especificador de formato, em que `n` é a posição do parâmetro para o formato na lista de parâmetros. A posição de parâmetro começa em 1 para o primeiro argumento após a cadeia de caracteres de formato. O restante do especificador de formato segue as mesmas regras que o `printf` especificador de formato. Para obter mais informações, consulte [Sintaxe de especificação de formato: funções printf e wprintf](../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).  
  
Aqui está um exemplo de formatação posicional:  
  
```C  
_printf_p("%1$s %2$s", "November", "10");  
```  
  
Isso imprime:  
  
```  
November 10  
```  
  
A ordem dos números usada não precisa corresponder à ordem dos argumentos fornecidos. Por exemplo, isso é uma cadeia de caracteres de formato válido:  
  
```C  
_printf_p("%2$s %1$s", "November", "10");  
```  
  
Isso imprime:  
  
```  
10 November  
```  
  
Ao contrário de cadeias de caracteres de formato tradicional, parâmetros posicionais podem ser usados mais de uma vez em uma cadeia de caracteres de formato. Por exemplo,  
  
```C  
_printf_p("%1$d times %1$d is %2$d", 10, 100);  
```  
  
Isso imprime:  
  
```  
10 times 10 is 100  
```  
  
Todos os argumentos devem ser usados pelo menos uma vez em algum lugar na cadeia de caracteres de formato. O número máximo de parâmetros posicionais permitidos em uma cadeia de caracteres de formato é dado por `_ARGMAX`.  
  
### <a name="width-and-precision"></a>Largura e Precisão  
Você pode usar `*n$` para especificar um parâmetro posicional como um especificador de precisão ou de largura, em que `n` é a posição da largura ou precisão do parâmetro na lista de parâmetros. A posição do valor de largura ou precisão deve aparecer imediatamente seguinte ao \* símbolo. Por exemplo,  
  
```C  
_printf_p("%1$*2$s","Hello", 10);  
```  
  
ou  
  
```C  
_printf_p("%2$*1$s", 10, "Hello");  
```  
  
### <a name="mixing-positional-and-non-positional-arguments"></a>Combinando argumentos posicionais e não posicionais  
Parâmetros posicionais não podem ser combinados com parâmetros não posicionais na mesma cadeia de caracteres de formato. Se qualquer formatação posicional for usada, todos os especificadores de formato devem usar a formatação posicional. No entanto, `printf_p` e funções relacionadas ainda dão suporte a parâmetros não posicionais em cadeias de caracteres de formato que não contém parâmetros posicionais.  
  
## <a name="example"></a>Exemplo  
  
```C  
// positional_args.c  
// Build by using: cl /W4 positional_args.c  
// Positional arguments allow the specification of the order  
// in which arguments are consumed in a formatting string.  
  
#include <stdio.h>  
  
int main()  
{  
    int     i = 1,  
            j = 2,  
            k = 3;  
    double  x = 0.1,  
            y = 2.22,  
            z = 333.3333;  
    char    *s1 = "abc",  
            *s2 = "def",  
            *s3 = "ghi";  
  
    // If positional arguments are unspecified,  
    // normal input order is used.  
    _printf_p("%d %d %d\n", i, j, k);  
  
    // Positional arguments are numbers followed by a $ character.  
    _printf_p("%3$d %1$d %2$d\n", i, j, k);  
  
    // The same positional argument may be reused.  
    _printf_p("%1$d %2$d %1$d\n", i, j);  
  
    // The positional arguments may appear in any order.
    _printf_p("%1$s %2$s %3$s\n", s1, s2, s3);  
    _printf_p("%3$s %1$s %2$s\n", s1, s2, s3);  
  
    // Precision and width specifiers must be int types.  
    _printf_p("%3$*5$f %2$.*4$f %1$*4$.*5$f\n", x, y, z, j, k);  
}  
```  
  
```Output  
1 2 3
3 1 2
1 2 1
abc def ghi
ghi abc def
333.333300 2.22 0.100
```  
  
## <a name="see-also"></a>Consulte também  
 [Sintaxe de especificação de formato: funções printf e wprintf](../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)