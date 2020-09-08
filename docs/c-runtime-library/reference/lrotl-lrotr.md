---
title: _lrotl, _lrotr
description: 'Referência de API para _lrotl e _lrotr; que gira bits à esquerda (_lrotl) ou à direita (_lrotr). '
ms.date: 04/04/2018
api_name:
- _lrotl
- _lrotr
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
- api-ms-win-crt-utility-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- lrotr
- lrotl
- _lrotr
- _lrotl
helpviewer_keywords:
- lrotl function
- bits
- _lrotr function
- lrotr function
- rotating bits
- _lrotl function
- bits, rotating
ms.assetid: d42f295b-35f9-49d2-9ee4-c66896ffe68e
ms.openlocfilehash: ccd14f7aa6ba3c1278063593aecee20c6789110d
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89555001"
---
# <a name="_lrotl-_lrotr"></a>_lrotl, _lrotr

Gira bits para a esquerda (**_lrotl**) ou para a direita (**_lrotr**).

## <a name="syntax"></a>Sintaxe

```C
unsigned long _lrotl( unsigned long value, int shift );
unsigned long _lrotr( unsigned long value, int shift );
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
O valor a ser girado.

*shift*<br/>
O número de bits para deslocar *value*.

## <a name="return-value"></a>Valor Retornado

Ambas as funções retornam o valor girado. Não há nenhum retorno de erro.

## <a name="remarks"></a>Comentários

As funções **_lrotl** e **_lrotr** giram *valor* por bits de *deslocamento* . **_lrotl** gira o valor à esquerda, em direção a bits mais significativos. **_lrotr** gira o valor certo, em direção a bits menos significativos. Ambas as funções encapsulam bits girados de uma extremidade do *value* para a outra.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_lrotl**, **_lrotr**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_lrot.c

#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   unsigned long val = 0x0fac35791;

   printf( "0x%8.8lx rotated left eight bits is 0x%8.8lx\n",
            val, _lrotl( val, 8 ) );
   printf( "0x%8.8lx rotated right four bits is 0x%8.8lx\n",
            val, _lrotr( val, 4 ) );
}
```

```Output
0xfac35791 rotated left eight bits is 0xc35791fa
0xfac35791 rotated right four bits is 0x1fac3579
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[_rotl, _rotl64, _rotr, _rotr64](rotl-rotl64-rotr-rotr64.md)<br/>
