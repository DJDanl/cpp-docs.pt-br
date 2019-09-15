---
title: _mbcjistojms, _mbcjistojms_l, _mbcjmstojis, _mbcjmstojis_l
ms.date: 11/04/2016
api_name:
- _mbcjistojms
- _mbcjmstojis
- _mbcjistojms_l
- _mbcjmstojis_l
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
- mbcjistojms
- _mbcjistojms
- _mbcjistojms_l
- _mbcjmstojis_l
- _mbcjmstojis
- mbcjmstojis_l
- mbcjistojms_l
- mbcjmstojis
helpviewer_keywords:
- _mbcjmstojis_l function
- _mbcjistojms function
- mbcjmstojis function
- _mbcjistojms_l function
- _mbcjmstojis function
- mbcjistojms function
- mbcjmstojis_l function
- mbcjistojms_l function
ms.assetid: dece5127-b337-40a4-aa10-53320a2c9432
ms.openlocfilehash: 6bf1109cfba93042bd00acde4812706c1bbf7a01
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70952598"
---
# <a name="_mbcjistojms-_mbcjistojms_l-_mbcjmstojis-_mbcjmstojis_l"></a>_mbcjistojms, _mbcjistojms_l, _mbcjmstojis, _mbcjmstojis_l

Converte entre caracteres JIS (Japan Industry Standard) e JMS (Japan Microsoft).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
unsigned int _mbcjistojms(
   unsigned int c
);
unsigned int _mbcjistojms_l(
   unsigned int c,
   _locale_t locale
);
unsigned int _mbcjmstojis(
   unsigned int c
);
unsigned int _mbcjmstojis_l(
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Caractere a ser convertido.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

No Japão, essas funções retornarão um caractere convertido ou retornam 0 se nenhuma conversão for possível. Em uma localidade não japonesa, essas funções retornam o caractere passado.

## <a name="remarks"></a>Comentários

A função **_mbcjistojms** converte um caractere padrão do setor do Japão (JIS) em um caractere kanji (Shift JIS) da Microsoft. O caractere será convertido somente se os bytes de Lead e de trilha estiverem no intervalo 0x21-0x7E. Se o byte de avaliação ou cliente potencial estiver fora desse intervalo, **errno** será definido como **EILSEQ**. Para obter mais informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

A função **_mbcjmstojis** converte um caractere Shift JIS em um caractere JIS. O caractere será convertido somente se o byte de Lead estiver no intervalo 0x81-0x9F ou 0xE0-0xFC e o byte final estiver no intervalo 0x40-0x7E ou 0x80-0xFC. Observe que alguns pontos de código nesse intervalo não têm um caractere atribuído e, portanto, não podem ser convertidos.

O valor *c* deve ser um valor de 16 bits cujos 8 bits superiores representem o byte de Lead do caractere a ser convertido e cujos 8 bits inferiores representam o byte da trilha.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Em versões anteriores, **_mbcjistojms** e **_mbcjmstojis** eram chamados **jistojms** e **jmstojis**, respectivamente. **_mbcjistojms**, **_mbcjistojms_l**, **_mbcjmstojis** e **_mbcjmstojis_l** devem ser usados em seu lugar.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbcjistojms**|\<mbstring.h>|
|**_mbcjistojms_l**|\<mbstring.h>|
|**_mbcjmstojis**|\<mbstring.h>|
|**_mbcjmstojis_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
