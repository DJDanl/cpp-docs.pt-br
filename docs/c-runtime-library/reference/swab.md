---
title: _swab
ms.date: 11/04/2016
apiname:
- _swab
- stdlib/_swab
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
- api-ms-win-crt-utility-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _swab
- stdlib/_swab
helpviewer_keywords:
- _swab function
- swapping bytes
- swab function
- bytes, swapping
ms.assetid: 017142f2-050c-4f6a-8b49-6b094f58ec94
ms.openlocfilehash: 64753383bcb94947e6b413b5f55ac6e2d9c7dbca
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50603028"
---
# <a name="swab"></a>_swab

Troca bytes.

## <a name="syntax"></a>Sintaxe

```C
void _swab(
   char *src,
   char *dest,
   int n
);
```

## <a name="parameters"></a>Parâmetros

*src*<br/>
Dados a serem copiados e trocados.

*dest*<br/>
Local de armazenamento para os dados trocados.

*n*<br/>
Número de bytes a serem copiados e trocados.

## <a name="return-value"></a>Valor retornado

O **swab** função não retorna um valor. A função definirá **errno** para **EINVAL** se o *src* ou *dest* ponteiro é nulo ou *n* for menor que zero e o parâmetro inválido manipulador é invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

Se *n* for par, o **swab** função cópias *n* bytes do *src*, trocará cada par de bytes adjacentes e armazenará o resultado em *dest*. Se *n* for ímpar **swab** copiará e trocará os primeiros *n*-1 bytes de *src*, e o byte final não é copiado. O **swab** função geralmente é usada para preparar dados binários para transferência para uma máquina que usa uma ordem de byte diferente.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_swab**|C: \<stdlib.h> C++: \<cstdlib> ou \<stdlib.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_swab.c

#include <stdlib.h>
#include <stdio.h>

char from[] = "BADCFEHGJILKNMPORQTSVUXWZY";
char to[] =   "...........................";

int main()
{
    printf("Before: %s  %d bytes\n        %s\n\n", from, sizeof(from), to);
    _swab(from, to, sizeof(from));
    printf("After:  %s\n        %s\n\n", from, to);
}
```

```Output
Before: BADCFEHGJILKNMPORQTSVUXWZY  27 bytes
        ...........................

After:  BADCFEHGJILKNMPORQTSVUXWZY
        ABCDEFGHIJKLMNOPQRSTUVWXYZ.
```

## <a name="see-also"></a>Consulte também

[Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)<br/>
