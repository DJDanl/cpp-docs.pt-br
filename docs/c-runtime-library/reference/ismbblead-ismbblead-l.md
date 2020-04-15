---
title: _ismbblead, _ismbblead_l
description: Descreve as funções de _ismbblead e _ismbblead_l da Biblioteca de Tempo de Execução da Microsoft C (CRT).
ms.date: 4/2/2020
api_name:
- _ismbblead_l
- _ismbblead
- _o__ismbblead
- _o__ismbblead_l
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- ismbblead_l
- istlead
- _ismbblead
- _ismbblead_l
- ismbblead
- _istlead
helpviewer_keywords:
- _ismbblead_l function
- ismbblead function
- _ismbblead function
- istlead function
- ismbblead_l function
- _istlead function
ms.assetid: 2abc6f75-ed5c-472e-bfd0-e905a1835ccf
ms.openlocfilehash: ee3085d49a27f2f3c97c6578463cf3a0598b73c7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81343573"
---
# <a name="_ismbblead-_ismbblead_l"></a>_ismbblead, _ismbblead_l

Testa um personagem para determinar se é um byte principal de um caractere multibyte.

## <a name="syntax"></a>Sintaxe

```C
int _ismbblead(
   unsigned int c
);
int _ismbblead_l(
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*C*\
Inteiro a ser testado.

*Localidade*\
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Retorna um valor não zero se o inteiro *c* for o primeiro byte de um caractere multibyte.

## <a name="remarks"></a>Comentários

Caracteres multibyte consistem em um byte inicial seguido de um byte à direita. Bytes iniciais são diferenciados por estarem em um intervalo específico de um determinado conjunto de caracteres. Por exemplo, apenas na página de código 932, os bytes de chumbo variam de 0x81 - 0x9F e 0xE0 - 0xFC.

**_ismbblead** usa o local atual para comportamento dependente de localidades. **_ismbblead_l** é idêntica, exceto que usa o local passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Quando o local é UTF-8, **_ismbblead** e **_ismbblead_l** sempre retornam 0 (falso), se *c* é um byte de chumbo ou não.

**_ismbblead** e **_ismbblead_l** são específicos da Microsoft, não fazem parte da biblioteca Padrão C. Não recomendamos usá-los onde quiser código portátil. Para compatibilidade padrão C, use **mbrlen** em vez disso.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos de rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_istlead**|Sempre retorna falso|**_ismbblead**|Sempre retorna falso|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_ismbblead**|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|
|**_ismbblead_l**|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|

\* Para constantes de manifesto para as condições de teste.

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Classificação de byte](../../c-runtime-library/byte-classification.md)\
[_ismbb rotinas](../../c-runtime-library/ismbb-routines.md)\
[mbrlen](mbrlen.md)
