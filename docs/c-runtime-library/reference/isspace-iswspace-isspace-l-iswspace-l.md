---
title: isspace, iswspace, _isspace_l, _iswspace_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- iswspace
- _isspace_l
- _iswspace_l
- isspace
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
- iswspace
- _istspace
- isspace
dev_langs:
- C++
helpviewer_keywords:
- iswspace function
- isspace function
- _iswspace_l function
- _isspace_l function
- iswspace_l function
- isspace_l function
- _istspace function
- istspace function
ms.assetid: b851e0c0-36bb-4dac-a1a3-533540939035
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 404fee8d74cec18c277f6c076a7cc41065a8b242
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32402241"
---
# <a name="isspace-iswspace-isspacel-iswspacel"></a>isspace, iswspace, _isspace_l, _iswspace_l

Determina se um inteiro representa um caractere de espaço.

## <a name="syntax"></a>Sintaxe

```C
int isspace(
   int c
);
int iswspace(
   wint_t c
);
int _isspace_l(
   int c,
   _locale_t locale
);
int _iswspace_l(
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

Cada essas rotinas retornará zero se *c* é uma representação específica de um caractere de espaço. **isspace** retorna um valor diferente de zero se *c* é um caractere de espaço em branco (0x09-0x0D ou 0x20). O resultado da condição de teste para o **isspace** função depende do **LC_CTYPE** configuração de categoria da localidade, consulte [setlocale, wsetlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções que não têm o **_l** o uso de sufixo a localidade atual para qualquer comportamento dependente de localidade; as versões que têm o **_l** sufixo são idênticas, exceto que eles usam o localidade que é transmitida em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

**iswspace** retorna um valor diferente de zero se *c* é um caractere largo que corresponde a um caractere de espaço em branco padrão.

O comportamento de **isspace** e **isspace_l** será indefinido se *c* não é EOF ou no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca de depuração CRT é usada e *c* não é uma desses valores, o aumento de funções uma asserção.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_** **istspace**|**isspace**|[_ismbcspace](ismbcgraph-functions.md)|**iswspace**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isspace**|\<ctype.h>|
|**iswspace**|\<ctype.h> ou \<wchar.h>|
|**_isspace_l**|\<ctype.h>|
|**_iswspace_l**|\<ctype.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
