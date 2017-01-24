---
title: "atodbl, atodbl_l, atoldbl, atoldbl_l, atoflt, atoflt_l | Microsoft Docs"
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
  - "_atoldbl"
  - "_atoldbl_l"
  - "_atodbl"
  - "_atoflt"
  - "_atoflt_l"
  - "_atodbl_l"
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
  - "_atoflt"
  - "_atoflt_l"
  - "atodbl_l"
  - "atoflt_l"
  - "_atoldbl"
  - "_atoldbl_l"
  - "atodbl"
  - "_atodbl_l"
  - "atoldbl"
  - "atoflt"
  - "atoldbl_l"
  - "_atodbl"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _atodbl"
  - "Função _atoldbl_l"
  - "Função atoflt"
  - "Função atoflt_l"
  - "Função atoldbl"
  - "Função _atoldbl"
  - "Função atodbl_l"
  - "Função _atoflt_l"
  - "Função atoldbl_l"
  - "Função atodbl"
  - "conversão de cadeia de caracteres para valores de ponto flutuante"
  - "Função _atoflt"
  - "Função _atodbl_l"
ms.assetid: 2d2530f4-4bd4-42e3-8083-f2d2fbc8432a
caps.latest.revision: 22
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# atodbl, atodbl_l, atoldbl, atoldbl_l, atoflt, atoflt_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte uma cadeia de caracteres em um double \(`_atodbl`\), double longo \(`_atoldbl`\), ou float \(`_atoflt`\).  
  
## Sintaxe  
  
```  
int _atodbl(  
   _CRT_DOUBLE * value,  
   char * str  
);  
int _atodbl_l (  
   _CRT_DOUBLE * value,  
   char * str,  
   locale_t locale  
);  
int _atoldbl(  
   _LDOUBLE * value,  
   char * str  
);  
int _atoldbl_l (  
   _LDOUBLE * value,  
   char * str,  
   locale_t locale  
);  
int _atoflt(  
   _CRT_FLOAT * value,  
   const char * str  
);  
int _atoflt_l(  
   _CRT_FLOAT * value,  
   const char * str,  
   locale_t locale  
);  
```  
  
#### Parâmetros  
 `value`  
 O valor double, long double ou float que é gerado convertendo a cadeia de caracteres em um valor de ponto flutuante.  Esses valores são envolvidos em uma estrutura.  
  
 `str`  
 A cadeia de caracteres a ser analisada para conversão em um valor de ponto flutuante.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Retorna 0 se tiver êxito.  Os códigos de erro possíveis são `_UNDERFLOW` ou `_OVERFLOW`, que são definidos no arquivo de cabeçalho Math.h.  
  
## Comentários  
 Essas funções convertem uma cadeia de caracteres em um valor de ponto flutuante.  A diferença entre essas funções e a família de funções `atof` é que essas funções não geram o código de ponto flutuante e não causam exceções de hardware.  Em vez disso, as condições de erro são relatadas como códigos de erro.  
  
 Se uma cadeia de caracteres não tiver uma interpretação válida como um valor de ponto flutuante, `value` é definido como zero e o valor de retorno é zero.  
  
 As versões dessas funções que têm o sufixo de `_l` são idênticas às versões que não têm, exceto que elas usam o parâmetro de localidade que é informado em vez da localidade de thread atual.  
  
## Requisitos  
  
|Rotinas|Cabeçalho necessário|  
|-------------|--------------------------|  
|`_atodbl`, `_atoldbl`, `_atoflt`<br /><br /> `_atodbl_l`, `_atoldbl_l`, `_atoflt_l`|\<stdlib.h\>|  
  
## Exemplo  
  
```  
// crt_atodbl.c  
// Uses _atodbl to convert a string to a double precision  
// floating point value.  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main()  
{  
   char str1[256] = "3.141592654";  
   char abc[256] = "abc";  
   char oflow[256] = "1.0E+5000";  
   _CRT_DOUBLE dblval;  
   _CRT_FLOAT fltval;  
   int retval;  
  
   retval = _atodbl(&dblval, str1);  
  
   printf("Double value: %lf\n", dblval.x);  
   printf("Return value: %d\n\n", retval);  
  
   retval = _atoflt(&fltval, str1);  
   printf("Float value: %f\n", fltval.f);  
   printf("Return value: %d\n\n", retval);  
  
   // A non-floating point value: returns 0.  
   retval = _atoflt(&fltval, abc);  
   printf("Float value: %f\n", fltval.f);  
   printf("Return value: %d\n\n", retval);  
  
   // Overflow.  
   retval = _atoflt(&fltval, oflow);  
   printf("Float value: %f\n", fltval.f);  
   printf("Return value: %d\n\n", retval);  
  
   return 0;  
}  
```  
  
  **Valor double: 3,141593**  
**Valor de retorno: 0**  
**Valor de flutuante: 3,141593**  
**Valor de retorno: 0**  
**Valor de flutuação: 0,000000**  
**Valor de retorno: 0**  
**Valor de flutuante: 1.\#INF00**  
**Valor de retorno: 3**   
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [atof, \_atof\_l, \_wtof, \_wtof\_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)