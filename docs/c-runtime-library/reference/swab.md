---
title: _swab
ms.date: 4/2/2020
api_name:
- _swab
- stdlib/_swab
- _o__swab
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _swab
- stdlib/_swab
helpviewer_keywords:
- _swab function
- swapping bytes
- swab function
- bytes, swapping
ms.assetid: 017142f2-050c-4f6a-8b49-6b094f58ec94
ms.openlocfilehash: f7fe23cd9c1b2eab52ebe50904d0bb18fe16cea6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81362963"
---
# <a name="_swab"></a>_swab

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

A função **de cotonete** não retorna um valor. A função define **errno** para **EINVAL** se o ponteiro *src* ou *dest* for nulo ou *n* for menor que zero, e o manipulador de parâmetros inválido for invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md).

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

Se *n* estiver mesmo, a função **_swab** copia *n* bytes do *src,* troca cada par de bytes adjacentes e armazena o resultado em *dest*. Se *n* for estranho, **_swab** copia e troca os primeiros *bytes n*-1 *de src*, e o byte final não é copiado. A função **_swab** é normalmente usada para preparar dados binários para transferência para uma máquina que usa uma ordem de byte diferente.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_swab**|C: \<stdlib.h> C++: \<cstdlib> ou \<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)<br/>
