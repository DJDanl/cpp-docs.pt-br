---
title: _mbccpy, _mbccpy_l
ms.date: 4/2/2020
api_name:
- _mbccpy
- _mbccpy_l
- _o__mbccpy
- _o__mbccpy_l
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
- _mbccpy
- tccpy
- ftccpy
- mbccpy
- _tccpy
- _ftccpy
helpviewer_keywords:
- _tccpy function
- _tccpy_l function
- tccpy_l function
- tccpy function
- mbccpy function
- _mbccpy_l function
- _mbccpy function
- mbccpy_l function
ms.assetid: 13f4de6e-7792-41ac-b319-dd9b135433aa
ms.openlocfilehash: 45f93e370e11cf38fc17da3557b21c636fcbc623
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81341257"
---
# <a name="_mbccpy-_mbccpy_l"></a>_mbccpy, _mbccpy_l

Copia um caractere multibyte de uma cadeia de caracteres para outra. Estão disponíveis versões mais seguras dessas funções, consulte [_mbccpy_s, _mbccpy_s_l](mbccpy-s-mbccpy-s-l.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
void _mbccpy(
   unsigned char *dest,
   const unsigned char *src
);
void _mbccpy_l(
   unsigned char *dest,
   const unsigned char *src,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*dest*<br/>
Destino da cópia.

*src*<br/>
Caracteres multibyte para copiar.

*Localidade*<br/>
Localidade a usar.

## <a name="remarks"></a>Comentários

A função **_mbccpy** copia um caractere multibyte *de src* para *dest*.

Essa função valida seus parâmetros. Se **_mbccpy** for aprovado um ponteiro nulo para *dest* ou *src,* o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL**.

**_mbccpy** usa o local atual para qualquer comportamento dependente do local. **_mbccpy_l** é idêntica ao **_mbccpy** exceto que **_mbccpy_l** usa o local passado para qualquer comportamento dependente da localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

**Observação de Segurança** Use uma cadeia de caracteres terminada em nulo. A cadeia de caracteres terminada em nulo não deve exceder o tamanho do buffer de destino. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer). Os problemas de estouro de buffer são um método frequente de ataque ao sistema, resultando em uma elevação de privilégio sem garantia.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tccpy**|É mapeado para um macro ou uma função embutida|**_mbccpy**|É mapeado para um macro ou uma função embutida|
|**_tccpy_l**|n/d|**_mbccpy_l**|n/d|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbccpy**|\<mbctype.h>|
|**_mbccpy_l**|\<mbctype.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)<br/>
