---
title: Macro _countof | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
apitype: DLLExport
f1_keywords:
- _countof
- countof
dev_langs:
- C++
helpviewer_keywords:
- countof macro
- _countof macro
ms.assetid: 86198767-f7e5-4beb-898d-3cbbf60350a3
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 3e9ffe81a1e0bb7369bf79a9c771336676e1a759
ms.lasthandoff: 02/25/2017

---
# <a name="countof-macro"></a>Macro _countof
Calcula o número de elementos em uma matriz alocada estaticamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t _countof(   
   array  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `array`  
 O nome de uma matriz.  
  
## <a name="return-value"></a>Valor de retorno  
 O número de elementos na matriz, expresso como um `size_t`.  
  
## <a name="remarks"></a>Comentários  
 Verifique se `array` é realmente uma matriz, não um ponteiro. No C, `_countof` produzirá resultados incorretos se `array` for um ponteiro. No C++, `_countof` não será compilado se `array` for um ponteiro.  
  
## <a name="requirements"></a>Requisitos  
  
|Macro|Cabeçalho necessário|  
|-----------|---------------------|  
|`_countof`|\<stdlib.h>|  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
sizeof(arr) = 40 bytes  
_countof(arr) = 20 elements  
```  
  
## <a name="see-also"></a>Consulte também  
 [Operador sizeof](../../cpp/sizeof-operator.md)
