---
title: isalnum, iswalnum, _isalnum_l, _iswalnum_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _iswalnum_l
- _isalnum_l
- iswalnum
- isalnum
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
- _istalnum_l
- _iswalnum_l
- iswalnum
- _isalnum_l
- isalnum
- _istalnum
dev_langs:
- C++
helpviewer_keywords:
- _istalnum function
- _ismbcalnum_l function
- iswalnum function
- isalnum function
- istalnum function
- _isalnum_l function
- _istalnum_l function
- _iswalnum_l function
ms.assetid: 0dc51306-ade8-4944-af27-e4176fc89093
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f78a3d946ad5c19107ba22278209e08cef82b212
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="isalnum-iswalnum-isalnuml-iswalnuml"></a>isalnum, iswalnum, _isalnum_l, _iswalnum_l

Determina se um inteiro representa um caractere alfanumérico.

## <a name="syntax"></a>Sintaxe

```C
int isalnum( int c );
int iswalnum( wint_t c );
int _isalnum_l( int c,  _locale_t locale );
int _iswalnum_l( wint_t c, _locale_t locale );
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Inteiro a ser testado.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Cada essas rotinas retornará zero se *c* é uma representação específica de um caractere alfanumérico. **isalnum** retorna um valor diferente de zero se **isalpha** ou **isdigit** é diferente de zero para *c*, ou seja, se *c* está dentro do intervalos de A - Z, a - z ou 0 - 9. **iswalnum** retorna um valor diferente de zero se **iswalpha** ou **iswdigit** é diferente de zero para *c*. Cada uma dessas rotinas retornará 0 se *c* não satisfaz a condição de teste.

As versões dessas funções que têm o **_l** sufixo use o parâmetro de localidade que é passado em vez da localidade atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

O comportamento de **isalnum** e **isalnum_l** será indefinido se *c* não é EOF ou no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca de depuração CRT é usada e *c* não é uma desses valores, o aumento de funções uma asserção.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**istalnum**|**isalnum**|[_ismbcalnum](ismbcalnum-functions.md)|**iswalnum**|
|**istalnum_l**|**_isalnum_l**|**_ismbcalnum_l**|**_iswalnum_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isalnum**|\<ctype.h>|
|**iswalnum**|\<ctype.h> ou \<wchar.h>|
|**_isalnum_l**|\<ctype.h>|
|**_iswalnum_l**|\<ctype.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
