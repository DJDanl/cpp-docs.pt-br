---
title: "atol, _atol_l, _wtol, _wtol_l | Microsoft Docs"
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
  - "atol"
  - "_wtol_l"
  - "_wtol"
  - "_atol_l"
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
  - "_atol_l"
  - "_ttol_l"
  - "_tstol_l"
  - "_tstol"
  - "_wtol"
  - "_ttol"
  - "_wtol_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função tstol"
  - "Função atol"
  - "Função ttol"
  - "Função _atol_l"
  - "Função _tstol_l"
  - "conversão de cadeia de caracteres, inteiros"
  - "Função _tstol"
  - "Função _ttol"
  - "Função _ttol_l"
  - "Função atol_l"
  - "Função wtol_l"
  - "Função _wtol_l"
  - "Função wtol"
  - "Função _wtol"
ms.assetid: cedfc21c-2d64-4e9c-bd04-bdf60b12db46
caps.latest.revision: 22
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# atol, _atol_l, _wtol, _wtol_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter uma cadeia de caracteres em um inteiro.  
  
## Sintaxe  
  
```  
long atol(  
   const char *str   
);  
long _atol_l(  
   const char *str,  
   _locale_t locale  
);  
long _wtol(  
   const wchar_t *str   
);  
long _wtol_l(  
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
 Cada função retorna o valor de `long` gerado interpretando os caracteres de entrada como um número.  O valor de retorno é 0L para `atol` se a entrada não pode ser convertida em um valor desse tipo.  
  
 No caso de estouro integrais com grandes valores positivos, `atol` retorna `LONG_MAX`; no caso de estouro integrais com grandes valores negativos, `LONG_MIN` é retornado.  Em todos os casos fora do intervalo, `errno` será definido como `ERANGE`.  Se o parâmetro passado for `NULL`, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL` e retornarão 0.  
  
## Comentários  
 Essas funções convertem uma cadeia de caracteres a um valor inteiro longo \(`atol`\).  
  
 A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretados como um valor numérico do tipo especificado.  A função deixa de ler a cadeia de caracteres de entrada no primeiro caractere que ela não reconhece ser parte de um número.  Esse caractere pode ser o caractere de `NULL` \(“\\ 0 " ou L \\ 0 '\) que encerra a cadeia de caracteres.  
  
 O argumento `str` para `atol` tem o seguinte formato:  
  
 \[`whitespace`\] \[`sign`\] \[`digits`\]\]  
  
 Um `whitespace` consiste no espaço ou em caracteres da guia, que são ignorados; `sign` é mais \(\+\) ou menos \(–\); e `digits` é um ou mais dígitos.  
  
 `_wtol` é idêntico a `atol` exceto que usa uma cadeia de caracteres amplas.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado em vez da localidade atual.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tstol`|`atol`|`atol`|`_wtol`|  
|`_ttol`|`atol`|`atol`|`_wtol`|  
  
## Requisitos  
  
|Rotinas|Cabeçalho necessário|  
|-------------|--------------------------|  
|`atol`|\<stdlib.h\>|  
|`_atol_l`, `_wtol`, `_wtol_l`|\<stdlib.h e\> wchar.h \<\>|  
  
## Exemplo  
 Esse programa mostra como os números armazenados como cadeias de caracteres poderão ser convertidos em valores numéricos usando a função de `atol` .  
  
```  
// crt_atol.c  
// This program shows how numbers stored as  
// strings can be converted to numeric values  
// using the atol functions.  
#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h>  
  
int main( void )  
{  
    char    *str = NULL;  
    long    value = 0;  
  
    // An example of the atol function  
    // with leading and trailing white spaces.  
    str = "  -2309 ";  
    value = atol( str );  
    printf( "Function: atol( \"%s\" ) = %d\n", str, value );  
  
    // Another example of the atol function   
    // with an arbitrary decimal point.  
    str = "314127.64";  
    value = atol( str );  
    printf( "Function: atol( \"%s\" ) = %d\n", str, value );  
  
    // Another example of the atol function  
    // with an overflow condition occurring.  
    str = "3336402735171707160320";  
    value = atol( str );  
    printf( "Function: atol( \"%s\" ) = %d\n", str, value );  
    if (errno == ERANGE)  
    {  
       printf("Overflow condition occurred.\n");  
    }  
}  
```  
  
  **Função: atol \(“\-2309 "\) \= \-2309**  
**Função: atol \(“314127,64 "\) \= 314127**  
**Função: atol \(“3336402735171707160320 "\) \= 2147483647**  
**Ocorreu uma condição de estouro.**   
## Equivalência do .NET Framework  
  
-   [System::Convert::ToInt32](https://msdn.microsoft.com/en-us/library/system.convert.toint32.aspx)  
  
-   [System::Convert::ToUInt32](https://msdn.microsoft.com/en-us/library/system.convert.touint32.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [\_ecvt](../../c-runtime-library/reference/ecvt.md)   
 [\_fcvt](../Topic/_fcvt.md)   
 [\_gcvt](../../c-runtime-library/reference/gcvt.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [atodbl, atodbl\_l, atoldbl, atoldbl\_l, atoflt, atoflt\_l](../../c-runtime-library/reference/atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)