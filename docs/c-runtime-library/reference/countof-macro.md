---
title: Macro _countof
ms.date: 03/22/2018
api_location:
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _countof
- countof
helpviewer_keywords:
- countof macro
- _countof macro
ms.assetid: 86198767-f7e5-4beb-898d-3cbbf60350a3
ms.openlocfilehash: 3debd63da7d218e29f31847034c69d89b4691643
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70942683"
---
# <a name="_countof-macro"></a>Macro _countof

Computa o número de elementos em uma matriz alocada estaticamente.

## <a name="syntax"></a>Sintaxe

```C
#define _countof(array) (sizeof(array) / sizeof(array[0]))
```

### <a name="parameters"></a>Parâmetros

*array*<br/>
O nome de uma matriz.

## <a name="return-value"></a>Valor de retorno

O número de elementos na matriz, expressos como um **size_t**.

## <a name="remarks"></a>Comentários

**_countof** é implementado como uma macro de pré-processador de função. A C++ versão tem máquinas de modelo extras para detectar em tempo de compilação se um ponteiro for passado em vez de uma matriz declarada estaticamente.

Verifique se a *matriz* é, na verdade, uma matriz, não um ponteiro. Em C, **_countof** produz resultados errados se a *matriz* é um ponteiro. No C++, **_countof** falha ao compilar se *matriz* é um ponteiro.  Uma matriz passada como um parâmetro para uma função *decays a um ponteiro*, o que significa que, dentro da função, você não pode usar **_countof** para determinar a extensão da matriz.

## <a name="requirements"></a>Requisitos

|Macro|Cabeçalho necessário|
|-----------|---------------------|
|**_countof**|\<stdlib.h>|

## <a name="example"></a>Exemplo

```cpp
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

[Operador sizeof](../../cpp/sizeof-operator.md)<br/>
