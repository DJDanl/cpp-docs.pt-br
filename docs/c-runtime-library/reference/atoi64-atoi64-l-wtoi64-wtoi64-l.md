---
title: "_atoi64, _atoi64_l, _wtoi64, _wtoi64_l | Microsoft Docs"
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
  - "_atoi64_l"
  - "_wtoi64"
  - "_atoi64"
  - "_wtoi64_l"
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
  - "_atoi64"
  - "_tstoi64"
  - "_ttoi64"
  - "wtoi64"
  - "_tstoi64_l"
  - "atoi64"
  - "_wtoi64_l"
  - "_wtoi64"
  - "wtoi64_l"
  - "_atoi64_l"
  - "atoi64_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função tstoi64"
  - "Função wtoi64"
  - "Função atoi64_l"
  - "Função _ttoi64"
  - "conversão de cadeia de caracteres, inteiros"
  - "Função wtoi64_l"
  - "Função atoi64"
  - "Função _tstoi64"
  - "Função _atoi64_l"
  - "Função _wtoi64_l"
  - "Função ttoi64"
  - "Função _wtoi64"
  - "Função _atoi64"
ms.assetid: 2c3e30fd-545d-4222-8364-0c5905df9526
caps.latest.revision: 24
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _atoi64, _atoi64_l, _wtoi64, _wtoi64_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte uma cadeia de caracteres em um inteiro de 64 bits.  
  
## Sintaxe  
  
```  
__int64 _atoi64(  
   const char *str   
);  
__int64 _wtoi64(  
   const wchar_t *str   
);  
__int64 _atoi64_l(  
   const char *str,  
   _locale_t locale  
);  
__int64 _wtoi64_l(  
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
 Cada função retorna o valor de `__int64` gerado interpretando os caracteres de entrada como um número.  O valor de retorno é 0 para `_atoi64` se a entrada não pode ser convertida em um valor desse tipo.  
  
 No caso de estouro integrais com grandes valores positivos, `_atoi64` retorna `I64_MAX` e `I64_MIN` no caso de estouro com grandes valores negativos integrais.  
  
 Em todos os casos fora do intervalo, `errno` será definido como `ERANGE`.  Se o parâmetro passado for `NULL`, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL` e retornarão 0.  
  
## Comentários  
 Essas funções convertem uma cadeia de caracteres a um valor inteiro de 64 bits.  
  
 A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretados como um valor numérico do tipo especificado.  A função deixa de ler a cadeia de caracteres de entrada no primeiro caractere que ela não reconhece ser parte de um número.  Esse caractere pode ser o caractere nulo \(\\ “0 " ou L \\ 0 '\) que encerra a cadeia de caracteres.  
  
 O argumento `str` para `_atoi64` tem o seguinte formato:  
  
```  
[whitespace] [sign] [digits]]  
```  
  
 Um `whitespace` consiste no espaço ou em caracteres da guia, que são ignorados; `sign` é mais \(\+\) ou menos \(–\); e `digits` é um ou mais dígitos.  
  
 `_wtoi64` é idêntico a `_atoi64` exceto que usa uma cadeia de caracteres abrangente como parâmetro.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado em vez da localidade atual.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tstoi64`|`_atoi64`|`_atoi64`|`_wtoi64`|  
|`_ttoi64`|`_atoi64`|`_atoi64`|`_wtoi64`|  
  
## Requisitos  
  
|Rotinas|Cabeçalho necessário|  
|-------------|--------------------------|  
|`_atoi64`, `_atoi64_l`|\<stdlib.h\>|  
|`_wtoi64`, `_wtoi64_l`|\<stdlib.h\> ou \<wchar.h\>|  
  
## Exemplo  
 Esse programa mostra como os números armazenados como cadeias de caracteres poderão ser convertidos em valores numéricos usando as funções de `_atoi64` .  
  
```  
// crt_atoi64.c  
// This program shows how numbers stored as  
// strings can be converted to numeric values  
// using the _atoi64 functions.  
#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h>  
  
int main( void )  
{  
    char    *str = NULL;  
    __int64 value = 0;  
  
    // An example of the _atoi64 function  
    // with leading and trailing white spaces.  
    str = "  -2309 ";  
    value = _atoi64( str );  
    printf( "Function: _atoi64( \"%s\" ) = %d\n", str, value );  
  
    // Another example of the _atoi64 function   
    // with an arbitrary decimal point.  
    str = "314127.64";  
    value = _atoi64( str );  
    printf( "Function: _atoi64( \"%s\" ) = %d\n", str, value );  
  
    // Another example of the _atoi64 function  
    // with an overflow condition occurring.  
    str = "3336402735171707160320";  
    value = _atoi64( str );  
    printf( "Function: _atoi64( \"%s\" ) = %d\n", str, value );  
    if (errno == ERANGE)  
    {  
       printf("Overflow condition occurred.\n");  
    }  
}  
```  
  
  **Função: \_atoi64 \(“\-2309 "\) \= \-2309**  
**Função: \_atoi64 \(“314127,64 "\) \= 314127**  
**Função: \_atoi64 \(“3336402735171707160320 "\) \= \-1**  
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