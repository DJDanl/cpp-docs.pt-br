---
title: "Macro _countof | Microsoft Docs"
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
apitype: "DLLExport"
f1_keywords: 
  - "_countof"
  - "countof"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Macro _countof"
  - "macro countof"
ms.assetid: 86198767-f7e5-4beb-898d-3cbbf60350a3
caps.latest.revision: 15
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Macro _countof
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Calcule o número de elementos em uma matriz alocados estaticamente.  
  
## Sintaxe  
  
```  
size_t _countof(   
   array  
);  
```  
  
#### Parâmetros  
 `array`  
 O nome de uma matriz.  
  
## Valor de retorno  
 O número de elementos na matriz, expressada como um `size_t`.  
  
## Comentários  
 Verifique se `array` é, na verdade, uma matriz, e não um ponteiro.  Em C, `_countof` produzirá resultados incorretos se `array` é um ponteiro.  Em C\+\+, `_countof` não será compilado se `array` é um ponteiro.  
  
## Requisitos  
  
|Macro|Cabeçalho necessário|  
|-----------|--------------------------|  
|`_countof`|\<stdlib.h\>|  
  
## Exemplo  
  
```  
// crt_countof.cpp  
#define _UNICODE  
#include <stdio.h>  
#include <stdlib.h>  
#include <tchar.h>  
  
int main( void )  
{  
   _TCHAR arr[20], *p;  
   printf( "sizeof(arr) = %zu bytes\n", sizeof(arr) );  
   printf( "_countof(arr) = %zu elements\n", _countof(arr) );  
   // In C++, the following line would generate a compile-time error:  
   // printf( "%zu\n", _countof(p) ); // error C2784 (because p is a pointer)  
  
   _tcscpy_s( arr, _countof(arr), _T("a string") );  
   // unlike sizeof, _countof works here for both narrow- and wide-character strings  
}  
```  
  
  **sizeof\(arr\) \= 40 bytes**  
**\_countof\(arr\) \= 20 elementos**   
## Consulte também  
 [Operador sizeof](../../cpp/sizeof-operator.md)