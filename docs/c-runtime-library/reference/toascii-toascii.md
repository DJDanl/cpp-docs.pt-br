---
title: toascii, __toascii | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- toascii function
- string conversion, to ASCII characters
- __toascii function
- ASCII characters, converting to
ms.assetid: a07c0608-b0e2-4da2-a20c-7b64d6a9b77c
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 62b94724e95738c424ee04b0fbccfad1fdf6951c
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

**ToAscii** converte o valor de *c* para ASCII de 7 bits de intervalo e retorna o resultado. Não há valor retornado reservado para indicar um erro.

## <a name="remarks"></a>Comentários

O **ToAscii** rotina converte o caractere especificado em um caractere ASCII, truncando-o para os bits de ordem inferior 7. Nenhuma outra transformação é aplicada.

O **ToAscii** rotina é definida como uma macro, a menos que o macro pré-processador _CTYPE_DISABLE_MACROS está definido. Para compatibilidade com versões anteriores, **toascii** é definido como uma macro somente quando [ &#95; &#95;STDC&#95; &#95; ](../../preprocessor/predefined-macros.md) não está definido ou está definido como 0; caso contrário, será indefinido.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**ToAscii**, **ToAscii**|C: \<ctype.h><br /><br /> C++: \<cctype> ou \<ctype.h>|

O **toascii** macro é uma extensão de POSIX e **ToAscii** é uma implementação específica da Microsoft da extensão POSIX. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
[Funções to](../../c-runtime-library/to-functions.md)<br/>
