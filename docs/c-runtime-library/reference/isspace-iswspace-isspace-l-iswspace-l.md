---
title: isspace, iswspace, _isspace_l, _iswspace_l
ms.date: 4/2/2020
api_name:
- iswspace
- _isspace_l
- _iswspace_l
- isspace
- _o_isspace
- _o_iswspace
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
- ntoskrnl.exe
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- iswspace
- _istspace
- isspace
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
ms.openlocfilehash: 43d66a191427e886941fd3dcac5dc6b71146b68a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81342759"
---
# <a name="isspace-iswspace-_isspace_l-_iswspace_l"></a>isspace, iswspace, _isspace_l, _iswspace_l

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

*C*<br/>
Inteiro a ser testado.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Cada uma dessas rotinas retorna não zero se *c* é uma representação particular de um personagem espacial. **isspace** retorna um valor não zero se *c* é um caractere espaço branco (0x09 - 0x0D ou 0x20). O resultado da condição de teste para a função **isspace** depende da **configuração da** categoria LC_CTYPE do local; consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções que não possuem o **sufixo _l** utilizam a localidade atual para qualquer comportamento dependente da localidade; as versões que têm o **sufixo _l** são idênticas, exceto que eles usam o local que é passado em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

**iswspace** retorna um valor não zero se *c* é um caractere amplo que corresponde a um caractere padrão de espaço branco.

O comportamento do **isspace** e **da _isspace_l** é indefinido se *c* não é EOF ou na faixa 0 a 0xFF, inclusive. Quando uma biblioteca CRT depurada é usada e *c* não é um desses valores, as funções levantam uma afirmação.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_** **istspace**|**Isspace**|[_ismbcspace](ismbcgraph-functions.md)|**Iswspace**|

## <a name="remarks"></a>Comentários

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**Isspace**|\<ctype.h>|
|**Iswspace**|\<ctype.h> ou \<wchar.h>|
|**_isspace_l**|\<ctype.h>|
|**_iswspace_l**|\<ctype.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
