---
title: Macro _countof | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
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
ms.translationtype: MT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 71d4310525f1d96184749b5b0b24cb0cf1da8512
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
