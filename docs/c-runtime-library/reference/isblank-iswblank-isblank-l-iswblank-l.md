---
title: isblank, iswblank, _isblank_l, _iswblank_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- isblank
- _isblank_l
- iswblank
- _iswblank_l
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
- _iswblank_l
- isblank
- _istblank_l
- _istblank
- _isblank_l
- iswblank
dev_langs:
- C++
ms.assetid: 33ce96c0-f387-411a-8283-c3d2a69e56bd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d2787be85aa4e12bf22d1be14f90568891b83824
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32403307"
---
# <a name="isblank-iswblank-isblankl-iswblankl"></a>isblank, iswblank, _isblank_l, _iswblank_l

Determina se um inteiro representa um caractere em branco.

## <a name="syntax"></a>Sintaxe

```C
int isblank(
   int c
);
int iswblank(
   wint_t c
);
int _isblank_l(
   int c,
   _locale_t locale
);
int _iswblank_l(
   wint_t c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Inteiro a ser testado.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Cada essas rotinas retornará zero se *c* é uma representação específica de um espaço ou caractere de tabulação horizontal, ou é um de um conjunto específico de localidade de caracteres que são usados para separar palavras em uma linha de texto. **isblank** retorna um valor diferente de zero se *c* é um caractere de espaço (0x20) ou caractere de guia horizontal (0x09). O resultado da condição de teste para o **isblank** funções depende de **LC_CTYPE** categoria de configuração da localidade; para obter mais informações, consulte [setlocale, wsetlocale](setlocale-wsetlocale.md). As versões dessas funções que não têm o **_l** o uso de sufixo a localidade atual para qualquer comportamento dependente de localidade; as versões que têm o **_l** sufixo são idênticas, exceto que eles usam o localidade que é transmitida em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

**iswblank** retorna um valor diferente de zero se *c* é um caractere largo que corresponde a um padrão espaço ou caractere de tabulação horizontal.

O comportamento de **isblank** e **_isblank_l** será indefinido se *c* não é EOF ou no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca de depuração CRT é usada e *c* não é uma desses valores, o aumento de funções uma asserção.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_istblank**|**isblank**|[_ismbcblank](ismbcgraph-functions.md)|**iswblank**|
|**_istblank_l**|**_isblank_l**|[_ismbcblank_l](ismbcgraph-functions.md)|**_iswblank_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isblank**|\<ctype.h>|
|**iswblank**|\<ctype.h> ou \<wchar.h>|
|**_isblank_l**|\<ctype.h>|
|**_iswblank_l**|\<ctype.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
