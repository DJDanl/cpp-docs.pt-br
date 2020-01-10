---
title: _ismbblead, _ismbblead_l
description: Descreve as funções de _ismbblead e _ismbblead_l do Microsoft C Runtime Library (CRT).
ms.date: 01/08/2020
api_name:
- _ismbblead_l
- _ismbblead
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
ms.openlocfilehash: 6a7bb992eeeb9c66a7cbdea0ed34cf797d374617
ms.sourcegitcommit: 7bd3567fc6a0e7124aab51cad63bbdb44a99a848
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/08/2020
ms.locfileid: "75755048"
---
# <a name="_ismbblead-_ismbblead_l"></a>_ismbblead, _ismbblead_l

Testa um caractere para determinar se é um byte de Lead de um caractere multibyte.

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

\ de *c*
Inteiro a ser testado.

\ de *localidade*
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Retorna um valor diferente de zero se o inteiro *c* for o primeiro byte de um caractere multibyte.

## <a name="remarks"></a>Comentários

Caracteres multibyte consistem em um byte inicial seguido de um byte à direita. Bytes iniciais são diferenciados por estarem em um intervalo específico de um determinado conjunto de caracteres. Por exemplo, na página de código 932 somente, os bytes de Lead variam de 0x81-0x9F e 0xE0-0xFC.

**_ismbblead** usa a localidade atual para o comportamento dependente de localidade. o **_ismbblead_l** é idêntico, exceto pelo fato de que ele usa a localidade passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Quando a localidade é UTF-8, **_ismbblead** e **_ismbblead_l** sempre retorna 0 (false), se *c* é um byte de cliente potencial ou não.

**_ismbblead** e **_ismbblead_l** são específicos da Microsoft, não fazem parte da biblioteca C padrão. Não recomendamos que você os use onde desejar código portátil. Para compatibilidade com C padrão, use **mbrlen** em vez disso.

### <a name="generic-text-routine-mappings"></a>Mapeamentos de rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_istlead**|Sempre retorna falso|**_ismbblead**|Sempre retorna falso|

## <a name="requirements"></a>Requisitos do

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_ismbblead**|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|
|**_ismbblead_l**|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|

\* Para constantes de manifesto para as condições de teste.

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Veja também

\ de [classificação de bytes](../../c-runtime-library/byte-classification.md)
[rotinas de _ismbb](../../c-runtime-library/ismbb-routines.md)\
[mbrlen](mbrlen.md)
