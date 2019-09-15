---
title: _ismbclower, _ismbclower_l, _ismbcupper, _ismbcupper_l
ms.date: 11/04/2016
api_name:
- _ismbclower
- _ismbclower_l
- _ismbcupper_l
- _ismbcupper
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
- _ismbcupper
- _ismbclower
helpviewer_keywords:
- _ismbcupper function
- ismbclower function
- _ismbclower_l function
- ismbcupper_l function
- _ismbclower function
- ismbcupper function
- ismbclower_l function
- _ismbcupper_l function
ms.assetid: 17d89587-65bc-477c-ba8f-a84e63cf59e7
ms.openlocfilehash: 6a64a0d9be83733fa5482eee84ce6576dd32c221
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70953794"
---
# <a name="_ismbclower-_ismbclower_l-_ismbcupper-_ismbcupper_l"></a>_ismbclower, _ismbclower_l, _ismbcupper, _ismbcupper_l

Verifica se um caractere multibyte está em letras minúsculas ou maiúsculas.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _ismbclower(
   unsigned int c
);
int _ismbclower_l(
   unsigned int c,
   _locale_t locale
);
int _ismbcupper(
   unsigned int c
);
int _ismbcupper_l(
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Caractere a ser testado.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas rotinas retornará um valor diferente de zero se o caractere satisfizer a condição de teste ou 0 se não satisfizer. Se *c*< = 255 e houver uma rotina **_ismbb** correspondente (por exemplo, **_ismbcalnum** corresponde a **_ismbbalnum**), o resultado será o valor de retorno da rotina **_ismbb** correspondente.

## <a name="remarks"></a>Comentários

Cada uma dessas funções testa um determinado caractere multibyte quanto a uma determinada condição.

As versões dessas funções com o sufixo **_L** são idênticas, exceto pelo fato de que usam a localidade passada em vez da localidade atual para seu comportamento dependente de localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

|Rotina|Condição de teste|Exemplo da página de código 932|
|-------------|--------------------|---------------------------|
|**_ismbclower**|Alfabético minúsculo|Retornará zero se e somente se *c* for uma representação de byte único de uma letra ASCII minúscula em inglês: 0x61 < =*c*< = 0x7A.|
|**_ismbclower_l**|Alfabético minúsculo|Retornará zero se e somente se *c* for uma representação de byte único de uma letra ASCII minúscula em inglês: 0x61 < =*c*< = 0x7A.|
|**_ismbcupper**|Alfabético maiúsculo|Retornará zero se e somente se *c* for uma representação de byte único de uma letra ASCII em letras maiúsculas: 0x41 < =*c*< = 0x5A.|
|**_ismbcupper_l**|Alfabético maiúsculo|Retornará zero se e somente se *c* for uma representação de byte único de uma letra ASCII em letras maiúsculas: 0x41 < =*c*< = 0x5A.|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_ismbclower**|\<mbstring.h>|
|**_ismbclower_l**|\<mbstring.h>|
|**_ismbcupper**|\<mbstring.h>|
|**_ismbcupper_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Rotinas _ismbc](../../c-runtime-library/ismbc-routines.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
[Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
