---
title: _mbbtombc, _mbbtombc_l
ms.date: 4/2/2020
api_name:
- _mbbtombc_l
- _mbbtombc
- _o__mbbtombc
- _o__mbbtombc_l
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _mbbtombc_l
- _mbbtombc
- mbbtombc_l
- mbbtombc
helpviewer_keywords:
- mbbtombc_l function
- mbbtombc function
- _mbbtombc_l function
- _mbbtombc function
ms.assetid: 78593389-b0fc-43b6-8c1f-2a6bf702d64e
ms.openlocfilehash: b2088ea83729a74a60e75d1710529480f34cd638
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919599"
---
# <a name="_mbbtombc-_mbbtombc_l"></a>_mbbtombc, _mbbtombc_l

Converte um caractere multibyte de um byte em um caractere multibyte de dois bytes correspondente.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
unsigned int _mbbtombc(
   unsigned int c
);
unsigned int _mbbtombc_l(
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*&*<br/>
Caractere de um byte a ser convertido.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Se **_mbbtombc** converter o *c*com êxito, ele retornará um caractere multibyte; caso contrário, retornará *c*.

## <a name="remarks"></a>Comentários

A função **_mbbtombc** converte um determinado caractere multibyte de byte único em um caractere multibyte de byte duplo correspondente. Os caracteres devem estar dentro do intervalo 0x20-0x7E ou 0xA1-0xDF a ser convertido.

O valor de saída é afetado pela configuração da configuração de categoria de **LC_CTYPE** da localidade; consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessa função são idênticas, exceto que **_mbbtombc** usa a localidade atual para esse comportamento dependente de localidade e **_mbbtombc_l** , em vez disso, usa o parâmetro de localidade que é passado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Em versões anteriores, **_mbbtombc** foi chamado de **hantozen**. Para obter um novo código, use **_mbbtombc**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbbtombc**|\<mbstring.h>|
|**_mbbtombc_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[_mbctombb, _mbctombb_l](mbctombb-mbctombb-l.md)<br/>
