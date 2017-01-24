---
title: "Fun&#231;&#245;es Bessel: j0, J1, Jn, y0, y1, Yn | Microsoft Docs"
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
  - "_j0"
  - "_j1"
  - "_jn"
  - "_y0"
  - "_y1"
  - "_yn"
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
  - "api-ms-win-crt-math-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "c.bessel"
  - "_j0"
  - "_j1"
  - "_jn"
  - "_y0"
  - "_y1"
  - "_yn"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Funções Bessel"
  - "Função _j0"
  - "Função _j1"
  - "Função _jn"
  - "Função _y0"
  - "Função _y1"
  - "Função _yn"
ms.assetid: a21a8bf1-df9d-4ba0-a8c2-e7ef71921d96
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es Bessel: j0, J1, Jn, y0, y1, Yn
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Computa a função de Bessel do tipo primeiro ou segundo, de pedidos n, 1 ou 0. The Bessel funções são comumente usadas em matemática ondas eletromagnéticas teoria.  
  
## Sintaxe  
  
```  
double _j0(   
   double x   
);  
double _j1(   
   double x   
);  
double _jn(   
   int n,  
   double x   
);  
double _y0(   
   double x   
);  
double _y1(   
   double x   
);  
double _yn(   
   int n,  
   double x   
);  
```  
  
#### Parâmetros  
 `x`  
 Valor de ponto flutuante.  
  
 `n`  
 Ordem de inteiro da função de Bessel.  
  
## Valor de retorno  
 Todas essas rotinas retorna uma função de Bessel de `x`. Se `x` é negativo no `_y0`, `_y1`, ou `_yn` funções, os conjuntos de rotina `errno` para `EDOM`, imprime um `_DOMAIN` mensagem de erro para `stderr`, e retorna `_HUGE_VAL`. Você pode modificar o tratamento de erro ao usar `_matherr`.  
  
## Comentários  
 O `_j0`, `_j1`, e `_jn` rotinas retornam Bessel funções do primeiro tipo: pedidos 0, 1 e n, respectivamente.  
  
|Entrada|Exceção SEH|Exceção Matherr|  
|-------------|-----------------|---------------------|  
|± `QNAN`,`IND`|`INVALID`|`_DOMAIN`|  
  
 O `_y0`, `_y1`, e `_yn` rotinas retornam Bessel funções do segundo tipo: pedidos 0, 1 e n, respectivamente.  
  
|Entrada|Exceção SEH|Exceção Matherr|  
|-------------|-----------------|---------------------|  
|± `QNAN`,`IND`|`INVALID`|`_DOMAIN`|  
|± 0|`ZERODIVIDE`|`_SING`|  
|&#124; x &#124; \< 0,0|`INVALID`|`_DOMAIN`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_j0`, `_j1`, `_jn`, `_y0`, `_y1`, `_yn`|\< Cmath \> \(C\+\+\), \< Math \> \(C, C\+\+\)|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
  
```  
// crt_bessel1.c  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   double x = 2.387;  
   int n = 3, c;  
  
   printf( "Bessel functions for x = %f:\n", x );  
   printf( " Kind   Order  Function     Result\n\n" );  
   printf( " First  0      _j0( x )     %f\n", _j0( x ) );  
   printf( " First  1      _j1( x )     %f\n", _j1( x ) );  
   for( c = 2; c < 5; c++ )  
      printf( " First  %d      _jn( %d, x )  %f\n", c, c, _jn( c, x ) );  
   printf( " Second 0      _y0( x )     %f\n", _y0( x ) );  
   printf( " Second 1      _y1( x )     %f\n", _y1( x ) );  
   for( c = 2; c < 5; c++ )  
      printf( " Second %d      _yn( %d, x )  %f\n", c, c, _yn( c, x ) );  
}  
```  
  
```Output  
Funções Bessel para x = 2.387000: j0 tipo ordem função resultado primeiro 0 (x) J1 de primeiro 1 0.009288 (0.522941 primeiro 2 Jn (x 2) x) 0.428870 3 primeiras Jn (3, x) 4 primeiro 0.195734 Jn (4 x) 0.063131 segundo y0 0 (x) y1 de 1 segundo 0.511681 (x) Yn 0.094374 2 segundo (2, x)-0.432608 segundo 3 Yn (3, x)-0.819314 segundo 4 Yn (4 -1.626833 x)  
```  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [\_matherr](../../c-runtime-library/reference/matherr.md)