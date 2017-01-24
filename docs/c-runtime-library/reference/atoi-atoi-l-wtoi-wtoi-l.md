---
title: "atoi, _atoi_l, _wtoi, _wtoi_l | Microsoft Docs"
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
  - "_wtoi"
  - "_wtoi_l"
  - "atoi"
  - "_atoi_l"
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
  - "_tstoi"
  - "_wtoi"
  - "_ttoi"
  - "atoi"
  - "_atoi_l"
  - "_wtoi_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _atoi_l"
  - "Função ttoi"
  - "Função atoi_l"
  - "conversão de cadeia de caracteres, inteiros"
  - "Função _wtoi"
  - "Função wtoi_l"
  - "Função tstoi"
  - "Função _ttoi"
  - "Função _tstoi"
  - "Função _wtoi_l"
  - "Função atoi"
  - "Função wtoi"
ms.assetid: ad7fda30-28ab-421f-aaad-ef0b8868663a
caps.latest.revision: 22
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# atoi, _atoi_l, _wtoi, _wtoi_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter uma cadeia de caracteres em inteiro.  
  
## Sintaxe  
  
```  
int atoi(  
   const char *str   
);  
int _wtoi(  
   const wchar_t *str   
);  
int _atoi_l(  
   const char *str,  
   _locale_t locale  
);  
int _wtoi_l(  
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
 Cada função retorna o valor de `int` gerado interpretando os caracteres de entrada como um número.  O valor de retorno é 0 para `atoi` e `_wtoi`, se a entrada não pode ser convertida em um valor desse tipo.  
  
 No caso de estouro integrais com grandes valores negativos, `LONG_MIN` é retornado.  `atoi` e `_wtoi` retornam `INT_MAX` e `INT_MIN` nessas condições.  Em todos os casos fora do intervalo, `errno` será definido como `ERANGE`.  Se o parâmetro passado for `NULL`, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL` e retornarão 0.  
  
## Comentários  
 Essas funções convertem uma cadeia de caracteres a um valor inteiro \(`atoi` e `_wtoi`\).  A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretados como um valor numérico do tipo especificado.  A função deixa de ler a cadeia de caracteres de entrada no primeiro caractere que ela não reconhece ser parte de um número.  Esse caractere pode ser o caractere nulo \(\\ “0 " ou L \\ 0 '\) que encerra a cadeia de caracteres.  
  
 O argumento de `str` a `atoi`e a `_wtoi` tem o seguinte formato:  
  
 \[`whitespace`\] \[`sign`\] \[`digits`\]\]  
  
 Um `whitespace` consiste no espaço ou em caracteres da guia, que são ignorados; `sign` é mais \(\+\) ou menos \(–\); e `digits` é um ou mais dígitos.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado em vez da localidade atual.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tstoi`|`atoi`|`atoi`|`_wtoi`|  
|`_ttoi`|`atoi`|`atoi`|`_wtoi`|  
  
## Requisitos  
  
|Rotinas|Cabeçalho necessário|  
|-------------|--------------------------|  
|`atoi`|\<stdlib.h\>|  
|`_atoi_l`, `_wtoi`, `_wtoi_l`|\<stdlib.h\> ou \<wchar.h\>|  
  
## Exemplo  
 Esse programa mostra como os números armazenados como cadeias de caracteres poderão ser convertidos em valores numéricos usando as funções de `atoi` .  
  
```  
// crt_atoi.c  
// This program shows how numbers   
// stored as strings can be converted to  
// numeric values using the atoi functions.  
  
#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h>  
  
int main( void )  
{  
    char    *str = NULL;  
    int     value = 0;  
  
    // An example of the atoi function.  
    str = "  -2309 ";  
    value = atoi( str );  
    printf( "Function: atoi( \"%s\" ) = %d\n", str, value );  
  
    // Another example of the atoi function.  
    str = "31412764";  
    value = atoi( str );  
    printf( "Function: atoi( \"%s\" ) = %d\n", str, value );  
  
    // Another example of the atoi function   
    // with an overflow condition occuring.  
    str = "3336402735171707160320";  
    value = atoi( str );  
    printf( "Function: atoi( \"%s\" ) = %d\n", str, value );  
    if (errno == ERANGE)  
    {  
       printf("Overflow condition occurred.\n");  
    }  
}  
```  
  
  **Função: atoi \(“\-2309 "\) \= \-2309**  
**Função: atoi \(“31412764 "\) \= 31412764**  
**Função: atoi \(“3336402735171707160320 "\) \= 2147483647**  
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