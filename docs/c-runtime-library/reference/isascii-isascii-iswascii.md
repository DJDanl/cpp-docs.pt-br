---
title: isascii, __isascii, iswascii
ms.date: 4/2/2020
api_name:
- iswascii
- __isascii
- _o_iswascii
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
- api-ms-win-crt-string-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- iswascii
- istascii
- __isascii
- _istascii
- isascii
- ctype/isascii
- ctype/__isascii
- corecrt_wctype/iswascii
helpviewer_keywords:
- __isascii function
- _isascii function
- isascii function
- _istascii function
- istascii function
- iswascii function
ms.assetid: ba4325ad-7cb3-4fb9-b096-58906d67971a
ms.openlocfilehash: aeb9c27fee4d179cc16caa50c6f0aae521402beb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81343918"
---
# <a name="isascii-__isascii-iswascii"></a>isascii, __isascii, iswascii

Determina se um dado caractere é um caractere ASCII.

## <a name="syntax"></a>Sintaxe

```C
int __isascii(
   int c
);
int iswascii(
   wint_t c
);

#define isascii __isascii
```

### <a name="parameters"></a>Parâmetros

*C*<br/>
Inteiro a ser testado.

## <a name="return-value"></a>Valor retornado

Cada uma dessas rotinas retorna não zero se **c** é uma representação particular de um caractere ASCII. **__isascii** retorna um valor não zero se **c** for um caractere ASCII (na faixa 0x00 - 0x7F). **iswascii** retorna um valor não zero se **c** é uma representação de amplo caráter de um caractere ASCII. Cada uma dessas rotinas retorna 0 se **c** não satisfaz a condição de teste.

## <a name="remarks"></a>Comentários

Tanto **__isascii** quanto **iswascii** são implementados como macros, a menos que a _CTYPE_DISABLE_MACROS de macro pré-processador seja definida.

Para compatibilidade retrógrada, **isascii** é implementado como macro somente se [&#95;&#95;&#95;&#95;STDC](../../preprocessor/predefined-macros.md) não for definida ou for definida como 0; caso contrário, é indefinido.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_istascii**|**__isascii**|**__isascii**|**iswascii**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isascii**, **__isascii**|C: \<ctype.h><br /><br /> C++: \<cctype> ou \<ctype.h>|
|**iswascii**|C: \<wctype.h>, \<ctype.h> ou \<wchar.h><br /><br /> C++: \<cwctype>, \<cctype>, \<wctype.h>, \<ctype.h> ou \<wchar.h>|

As funções **isascii**, **__isascii** e **iswascii** são específicas da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
