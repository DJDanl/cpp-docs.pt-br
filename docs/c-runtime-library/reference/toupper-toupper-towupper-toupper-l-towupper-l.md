---
title: toupper, _toupper, towupper, _toupper_l, _towupper_l
ms.date: 11/04/2016
api_name:
- _toupper_l
- towupper
- toupper
- _towupper_l
- _toupper
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- towupper
- _toupper
- _totupper
- toupper
helpviewer_keywords:
- _toupper function
- towupper function
- uppercase, converting strings to
- totupper function
- string conversion, to different characters
- towupper_l function
- toupper_l function
- string conversion, case
- _toupper_l function
- _towupper_l function
- _totupper function
- case, converting
- characters, converting
- toupper function
ms.assetid: cdef1b0f-b19c-4d11-b7d2-cf6334c9b6cc
ms.openlocfilehash: e17f139789b2c37292764f2e4508b59cddd2c03e
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957915"
---
# <a name="toupper-_toupper-towupper-_toupper_l-_towupper_l"></a>toupper, _toupper, towupper, _toupper_l, _towupper_l

Converta caractere em maiúscula.

## <a name="syntax"></a>Sintaxe

```C
int toupper(
   int c
);
int _toupper(
   int c
);
int towupper(
   wint_t c
);
int _toupper_l(
   int c ,
   _locale_t locale
);
int _towupper_l(
   wint_t c ,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Caractere a ser convertido.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas rotinas converte uma cópia de *c*, se possível, e retorna o resultado.

Se *c* for um caractere largo para o qual **iswlower** é diferente de zero e houver um caractere largo correspondente para o qual [iswupper](isupper-isupper-l-iswupper-iswupper-l.md) é diferente de zero, **towupper** retornará o caractere largo correspondente; caso contrário, **towupper** retornará *c* inalterado.

Não há valor retornado reservado para indicar um erro.

Para que o **ToUpper** forneça os resultados esperados, [__isascii](isascii-isascii-iswascii.md) e [islow](islower-iswlower-islower-l-iswlower-l.md) devem retornar diferentes de zero.

## <a name="remarks"></a>Comentários

Cada uma dessas rotinas converte determinada letra minúscula em maiúscula, se for possível e relevante. A conversão de casos de **towupper** é específica da localidade. Somente caracteres relevantes à localidade atual são alterados quanto a maiúsculas e minúsculas. As funções sem o sufixo **_L** usam a localidade definida atualmente. As versões dessas funções com o sufixo **_L** pegam a localidade como um parâmetro e usam isso em vez da localidade definida no momento. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Para que o **ToUpper** forneça os resultados esperados, [__isascii](isascii-isascii-iswascii.md) e [IsUpper](isupper-isupper-l-iswupper-iswupper-l.md) devem retornar diferentes de zero.

[Rotinas de conversão de dados](../../c-runtime-library/data-conversion.md)

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_totupper**|**toupper**|**_mbctoupper**|**towupper**|
|**_totupper_l**|**_toupper_l**|**_mbctoupper_l**|**_towupper_l**|

> [!NOTE]
> **_toupper_l** e **_towupper_l** não têm nenhuma dependência de localidade e não devem ser chamados diretamente. Eles são fornecidos para uso interno pelo **_totupper_l**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**toupper**|\<ctype.h>|
|**_toupper**|\<ctype.h>|
|**towupper**|\<ctype.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo em [Funções to](../../c-runtime-library/to-functions.md).

## <a name="see-also"></a>Consulte também

[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
[Funções to](../../c-runtime-library/to-functions.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
