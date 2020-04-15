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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 5d26b06da1dcf8c53abda5d4ff2ee06ec3e7cd11
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81341423"
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

*C*<br/>
Caractere de um byte a ser convertido.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Se **_mbbtombc** converte *c*com sucesso, ele retorna um caractere multibyte; caso contrário, ele retorna *c*.

## <a name="remarks"></a>Comentários

A função **_mbbtombc** converte um caractere multibyte de um determinado byte para um caractere multibyte de duplo byte correspondente. Os caracteres devem estar dentro da faixa 0x20 - 0x7E ou 0xA1 - 0xDF a serem convertidos.

O valor de saída é afetado pela configuração da configuração da categoria **LC_CTYPE** do local; consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md) para obter mais informações. As versões desta função são idênticas, exceto que **_mbbtombc** usa o local atual para este comportamento dependente da localidade e **_mbbtombc_l** em vez disso usa o parâmetro local que é passado dentro Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Em versões anteriores, **_mbbtombc** foi nomeado **hantozen**. Para novo código, use **_mbbtombc**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbbtombc**|\<mbstring.h>|
|**_mbbtombc_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[_mbctombb, _mbctombb_l](mbctombb-mbctombb-l.md)<br/>
