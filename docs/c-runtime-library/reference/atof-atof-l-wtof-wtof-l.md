---
title: "atof, _atof_l, _wtof, _wtof_l | Microsoft Docs"
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
  - "_wtof_l"
  - "atof"
  - "_atof_l"
  - "_wtof"
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
  - "_tstof"
  - "_ttof"
  - "atof"
  - "stdlib/atof"
  - "math/atof"
  - "_atof_l"
  - "stdlib/_atof_l"
  - "math/_atof_l"
  - "_wtof"
  - "corecrt_wstdlib/_wtof"
  - "_wtof_l"
  - "corecrt_wstdlib/_wtof_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função tstof"
  - "Função atof_l"
  - "Função _atof_l"
  - "Função atof"
  - "Função _tstof"
  - "Função _ttof"
  - "Função wtof"
  - "Função _wtof_l"
  - "Função ttof"
  - "Função wtof_l"
  - "Função _wtof"
  - "conversão de cadeia de caracteres para valores de ponto flutuante"
ms.assetid: eb513241-c9a9-4f5c-b7e7-a49b14abfb75
caps.latest.revision: 26
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# atof, _atof_l, _wtof, _wtof_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter uma cadeia de caracteres para duplo.  
  
## Sintaxe  
  
```  
double atof(  
   const char *str   
);  
double _atof_l(  
   const char *str,  
   _locale_t locale  
);  
double _wtof(  
   const wchar_t *str   
);  
double _wtof_l(  
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
 Cada função retorna o valor de `double` gerado interpretando os caracteres de entrada como um número.  O valor de retorno será 0,0 se a entrada não pode ser convertida em um valor desse tipo.  
  
 Em todos os casos fora do escopo, o errno é definido como `ERANGE`.  Se o parâmetro passado for `NULL`, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL` e retornarão 0.  
  
## Comentários  
 Essas funções convertem uma cadeia de caracteres a um valor de precisão dupla, de ponto flutuante.  
  
 A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretados como um valor numérico do tipo especificado.  A função deixa de ler a cadeia de caracteres de entrada no primeiro caractere que ela não reconhece ser parte de um número.  Esse caractere pode ser o caractere nulo \(\\ “0 " ou L \\ 0 '\) que encerra a cadeia de caracteres.  
  
 O argumento de `str` a `atof` e a `_wtof` tem o seguinte formato:  
  
 \[`whitespace`\] \[`sign`\] \[`digits`\] \[`.digits`\] \[ {`d` &#124; `D` &#124; `e` &#124; `E` }\[`sign`\]`digits`\]  
  
 `whitespace` consiste no espaço ou nos caracteres de tabulação, que são ignorados; `sign` está mais \(\+\) ou menos \(–\); e `digits` é um ou mais dígitos decimais.  Se nenhum dígito aparecer antes do ponto decimal, pelo menos um deve aparecer após o ponto decimal.  Os dígitos decimais podem ser seguido por um expoente, que consiste em uma letra introdução \(`d`, `D`, `e`, ou `E`\) e um inteiro decimal opcionalmente assinado.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado em vez da localidade atual.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tstof`|`atof`|`atof`|`_wtof`|  
|`_ttof`|`atof`|`atof`|`_wtof`|  
  
## Requisitos  
  
|Rotinas|Cabeçalho necessário|  
|-------------|--------------------------|  
|`atof`|\<math.h e\> stdlib.h \<\>|  
|`_atof_l`|\<math.h e\> stdlib.h \<\>|  
|`_wtof`, `_wtof_l`|\<stdlib.h\> ou \<wchar.h\>|  
  
## Exemplo  
 Esse programa mostra como os números armazenados como cadeias de caracteres poderão ser convertidos em valores numéricos usando a função de `atof` .  
  
```  
// crt_atof.c  
//  
// This program shows how numbers stored as   
// strings can be converted to numeric  
// values using the atof function.  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
    char    *str = NULL;  
    double  value = 0;  
  
    // An example of the atof function  
    // using leading and training spaces.  
    str = "  3336402735171707160320 ";  
    value = atof( str );  
    printf( "Function: atof( \"%s\" ) = %e\n", str, value );  
  
    // Another example of the atof function  
    // using the 'd' exponential formatting keyword.  
    str = "3.1412764583d210";  
    value = atof( str );  
    printf( "Function: atof( \"%s\" ) = %e\n", str, value );  
  
    // An example of the atof function  
    // using the 'e' exponential formatting keyword.  
    str = "  -2309.12E-15";  
    value = atof( str );  
    printf( "Function: atof( \"%s\" ) = %e\n", str, value );  
  
}  
```  
  
  **Função: atof \(“3336402735171707160320 "\) \= 3.336403e\+021**  
**Função: atof \(“”\) \= 3.141276e\+210 3.1412764583d210**  
**Função: atof \(“”\) \= \-2.309120e\-012 \-2309.12E\-15**   
## Equivalência do .NET Framework  
  
-   [System::Convert::ToSingle](https://msdn.microsoft.com/en-us/library/system.convert.tosingle.aspx)  
  
-   [System::Convert::ToDouble](https://msdn.microsoft.com/en-us/library/system.convert.todouble.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [\_ecvt](../../c-runtime-library/reference/ecvt.md)   
 [\_fcvt](../Topic/_fcvt.md)   
 [\_gcvt](../../c-runtime-library/reference/gcvt.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [atodbl, atodbl\_l, atoldbl, atoldbl\_l, atoflt, atoflt\_l](../../c-runtime-library/reference/atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)