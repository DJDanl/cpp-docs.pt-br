---
title: ispunct, iswpunct, _ispunct_l, _iswpunct_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- ispunct
- _iswpunct_l
- iswpunct
- _ispunct_l
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
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- iswpunct
- _istpunct
- ispunct
dev_langs:
- C++
helpviewer_keywords:
- _istpunct function
- _ispunct_l function
- iswpunct function
- ispunct function
- istpunct function
- ispunct_l function
- _iswpunct_l function
- iswpunct_l function
ms.assetid: 94403240-85c8-40a4-9c2b-e3e95c729c76
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9509270906de3f0a9c7a20fd5f126ecffcafcff0
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32402664"
---
# <a name="ispunct-iswpunct-ispunctl-iswpunctl"></a>ispunct, iswpunct, _ispunct_l, _iswpunct_l

Determina se um inteiro representa um caractere de pontuação.

## <a name="syntax"></a>Sintaxe

```C
int ispunct(
   int c
);
int iswpunct(
   wint_t c
);
int _ispunct_l(
   int c,
   _locale_t locale
);
int _iswpunct_l(
   wint_t c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Inteiro a ser testado.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Cada essas rotinas retornará zero se *c* é uma representação específica de um caractere de pontuação. **ispunct** retorna um valor diferente de zero para qualquer caractere imprimível que não é um caractere de espaço ou um caractere para a qual **isalnum** é diferente de zero. **iswpunct** retorna um valor diferente de zero para qualquer caractere imprimível ampla que não é o caractere de espaço ampla nem um caractere largo para o qual **iswalnum** é diferente de zero. Cada uma dessas rotinas retornará 0 se *c* não satisfaz a condição de teste.

O resultado da condição de teste para o **ispunct** função depende do **LC_CTYPE** configuração de categoria da localidade, consulte [setlocale, wsetlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções que não têm o **_l** o uso de sufixo a localidade atual para qualquer comportamento dependente de localidade; as versões que têm o **_l** sufixo são idênticas, exceto que eles usam o localidade que é transmitida em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

O comportamento de **ispunct** e **ispunct_l** será indefinido se *c* não é EOF ou no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca de depuração CRT é usada e *c* não é uma desses valores, o aumento de funções uma asserção.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_** **istpunct**|**ispunct**|[_ismbcpunct](ismbcgraph-functions.md)|**iswpunct**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**ispunct**|\<ctype.h>|
|**iswpunct**|\<ctype.h> ou \<wchar.h>|
|**_ispunct_l**|\<ctype.h>|
|**_iswpunct_l**|\<ctype.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
