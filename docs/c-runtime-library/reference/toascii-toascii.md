---
title: toascii, __toascii
ms.date: 11/04/2016
apiname:
- __toascii
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
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- __toascii
- toascii
- ctype/toascii
- ctype/__toascii
helpviewer_keywords:
- toascii function
- string conversion, to ASCII characters
- __toascii function
- ASCII characters, converting to
ms.assetid: a07c0608-b0e2-4da2-a20c-7b64d6a9b77c
ms.openlocfilehash: 22f76bdbdb21eb5b3cc9a226c111e321ee2fd0ce
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50578961"
---
# <a name="toascii-toascii"></a>toascii, __toascii

Converte caracteres em ASCII de 7 bits por truncamento.

## <a name="syntax"></a>Sintaxe

```C
int __toascii(
   int c
);
#define toascii __toascii
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Caractere a ser convertido.

## <a name="return-value"></a>Valor de retorno

**ToAscii** converte o valor de *c* para ASCII de 7 bits, intervalo e retorna o resultado. Não há valor retornado reservado para indicar um erro.

## <a name="remarks"></a>Comentários

O **ToAscii** rotina converte o caractere especificado em um caractere ASCII truncando-o para os 7-bits de ordem inferior. Nenhuma outra transformação é aplicada.

O **ToAscii** rotina é definida como uma macro, a menos que a macro do pré-processador ctype_disable_macros é definido. Para fins de compatibilidade **toascii** é definido como uma macro somente quando [ &#95; &#95;STDC&#95; &#95; ](../../preprocessor/predefined-macros.md) não está definido ou está definido como 0; caso contrário, será indefinido.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**ToAscii**, **ToAscii**|C: \<ctype.h><br /><br /> C++: \<cctype> ou \<ctype.h>|

O **toascii** macro é uma extensão POSIX e **ToAscii** é uma implementação específica da Microsoft da extensão POSIX. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
[Funções to](../../c-runtime-library/to-functions.md)<br/>
