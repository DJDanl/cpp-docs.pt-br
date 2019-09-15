---
title: toascii, __toascii
ms.date: 11/04/2016
api_name:
- __toascii
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
- api-ms-win-crt-convert-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: 09df829511b38b87cb41e32a59bee9f38a9b8f32
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957466"
---
# <a name="toascii-__toascii"></a>toascii, __toascii

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

**__toascii** converte o valor de *c* para o intervalo ASCII de 7 bits e retorna o resultado. Não há valor retornado reservado para indicar um erro.

## <a name="remarks"></a>Comentários

A rotina **__toascii** converte o caractere determinado em um caractere ASCII truncando-o para os 7 bits de ordem inferior. Nenhuma outra transformação é aplicada.

A rotina **__toascii** é definida como uma macro, a menos que a macro de pré-processador _CTYPE_DISABLE_MACROS seja definida. Para compatibilidade com versões anteriores, **toascii** é definido como uma macro somente quando [ &#95; &#95;stdc&#95; ](../../preprocessor/predefined-macros.md) não está definido ou é definido como 0; caso contrário, ele será indefinido.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**toascii**, **__toascii**|C: \<ctype.h><br /><br /> C++: \<cctype> ou \<ctype.h>|

A macro **toascii** é uma extensão POSIX e **__toascii** é uma implementação específica da Microsoft da extensão POSIX. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
[Funções to](../../c-runtime-library/to-functions.md)<br/>
