---
title: Macro _countof
ms.date: 03/22/2018
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
helpviewer_keywords:
- countof macro
- _countof macro
ms.assetid: 86198767-f7e5-4beb-898d-3cbbf60350a3
ms.openlocfilehash: 60b4350d6cf14a545de67de0bdaee70ee2099006
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50536130"
---
# <a name="countof-macro"></a>Macro _countof

Calcula o número de elementos em uma matriz alocada estaticamente.

## <a name="syntax"></a>Sintaxe

```C
#define _countof(array) (sizeof(array) / sizeof(array[0]))
```

### <a name="parameters"></a>Parâmetros

*array*<br/>
O nome de uma matriz.

## <a name="return-value"></a>Valor de retorno

O número de elementos na matriz, expressada como uma **size_t**.

## <a name="remarks"></a>Comentários

**countof** é implementado como uma macro de pré-processador do tipo função. A versão do C++ tem maquinário de modelo extra para detectar no tempo de compilação se um ponteiro é passado em vez de uma matriz declarada estaticamente.

Certifique-se de que *matriz* é, na verdade, uma matriz, e não um ponteiro. Em C, **countof** produz resultados incorretos se *matriz* é um ponteiro. No C++, **countof** Falha na compilação se *matriz* é um ponteiro.  Uma matriz é passada como um parâmetro para uma função *decai para um ponteiro*, que significa que, dentro da função, você não pode usar **countof** para determinar a extensão da matriz.

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
