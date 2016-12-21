---
title: "atoll, _atoll_l, _wtoll, _wtoll_l | Microsoft Docs"
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
  - "_wtoll"
  - "_atoll_l"
  - "_wtoll_l"
  - "atoll"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-convert-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_tstoll_l"
  - "_wtoll"
  - "_atoll_l"
  - "_ttoll"
  - "_tstoll"
  - "_wtoll_l"
  - "atoll"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _atoll_l"
  - "Função _wtoll"
  - "Função _wtoll_l"
  - "Função atoll"
ms.assetid: 5e85fcac-b351-4882-bff2-6e7c469b7fa8
caps.latest.revision: 7
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# atoll, _atoll_l, _wtoll, _wtoll_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte uma cadeia de caracteres para um inteiro `long long`.  
  
## Sintaxe  
  
```  
long long atoll(  
   const char *str   
);  
long long _wtoll(  
   const wchar_t *str   
);  
long long _atoll_l(  
   const char *str,  
   _locale_t locale  
);  
long long _wtoll_l(  
   const wchar_t *str,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `str`  
 Cadeia de caracteres a ser convertida.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Cada função retorna o valor `long long` que é gerado pela interpretação dos caracteres de entrada como um número.  O valor de retorno para `atoll` é 0 se a entrada não puder ser convertida em um valor desse tipo.  
  
 Para overflow com grandes valores integrais positivos, `atoll` retorna `LLONG_MAX`, e para overflow com grandes valores integrais negativos, ele retorna `LLONG_MIN`.  
  
 Em todos os casos fora do intervalo, `errno` será definido como `ERANGE`.  Se o parâmetro transmitido for `NULL`, o manipulador de parâmetros inválidos será invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL` e retornarão 0.  
  
## Comentários  
 Essas funções convertem uma cadeia de caracteres em um valor inteiro de `long long`.  
  
 A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretados como um valor numérico do tipo especificado.  A função deixa de ler a cadeia de caracteres de entrada no primeiro caractere que ela não reconhece ser parte de um número.  Esse caractere pode ser o caractere nulo \("\\0" ou L "\\ 0"\) que termina a cadeia de caracteres.  
  
 O argumento `str` para `atoll` tem o seguinte formato:  
  
```  
[whitespace] [sign] [digits]  
```  
  
 Um `whitespace` consiste no espaço ou em caracteres da guia, que são ignorados; `sign` é mais \(\+\) ou menos \(–\); e `digits` é um ou mais dígitos.  
  
 `_wtoll` é idêntico a `atoll` exceto que usa uma cadeia de caracteres abrangente como parâmetro.  
  
 As versões dessas funções que têm o sufixo de `_l` são idênticas às versões que não têm, exceto aquelas que usam o parâmetro de localidade que é passado em vez da localidade de thread atual.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tstoll`|`atoll`|`atoll`|`_wtoll`|  
|`_tstoll_l`|`_atoll_l`|`_atoll_l`|`_wtoll_l`|  
|`_ttoll`|`_atoll`|`_atoll`|`_wtoll`|  
  
## Requisitos  
  
|Rotinas|Cabeçalho necessário|  
|-------------|--------------------------|  
|`atoll`, `_atoll_l`|\<stdlib.h\>|  
|`_wtoll`, `_wtoll_l`|\<stdlib.h\> ou \<wchar.h\>|  
  
## Exemplo  
 Este programa mostra como usar as funções de `atoll` para converter números armazenados como cadeias de caracteres em valores numéricos.  
  
```  
// crt_atoll.c  
// Build with: cl /W4 /Tc crt_atoll.c  
// This program shows how to use the atoll   
// functions to convert numbers stored as   
// strings to numeric values.  
#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h>  
  
int main(void)  
{  
    char *str = NULL;  
    long long value = 0;  
  
    // An example of the atoll function  
    // with leading and trailing white spaces.  
    str = "  -27182818284 ";  
    value = atoll(str);  
    printf("Function: atoll(\"%s\") = %lld\n", str, value);  
  
    // Another example of the atoll function   
    // with an arbitrary decimal point.  
    str = "314127.64";  
    value = atoll(str);  
    printf("Function: atoll(\"%s\") = %lld\n", str, value);  
  
    // Another example of the atoll function  
    // with an overflow condition occurring.  
    str = "3336402735171707160320";  
    value = atoll(str);  
    printf("Function: atoll(\"%s\") = %lld\n", str, value);  
    if (errno == ERANGE)  
    {  
       printf("Overflow condition occurred.\n");  
    }  
}  
```  
  
  **Função: atoll\(" \-27182818284 "\) \= \-27182818284**  
**Função: atoll\("314127.64"\) \= 314127**  
**Função: atoll\("3336402735171707160320"\) \= 9223372036854775807**  
**Ocorreu uma condição de estouro.**   
## Equivalência do .NET Framework  
  
-   [System::Convert::ToInt64](https://msdn.microsoft.com/en-us/library/system.convert.toint64.aspx)  
  
-   [System::Convert::ToUInt64](https://msdn.microsoft.com/en-us/library/system.convert.touint64.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [\_ecvt](../../c-runtime-library/reference/ecvt.md)   
 [\_fcvt](../Topic/_fcvt.md)   
 [\_gcvt](../../c-runtime-library/reference/gcvt.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [atodbl, atodbl\_l, atoldbl, atoldbl\_l, atoflt, atoflt\_l](../../c-runtime-library/reference/atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)