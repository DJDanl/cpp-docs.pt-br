---
title: _mbbtype, _mbbtype_l
ms.date: 4/2/2020
api_name:
- _mbbtype
- _mbbtype_l
- _o__mbbtype
- _o__mbbtype_l
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
- _mbbtype_l
- mbbtype
- mbbtype_l
- _mbbtype
helpviewer_keywords:
- _mbbtype function
- _mbbtype_l function
- mbbtype function
- mbbtype_l function
ms.assetid: b8e34b40-842a-4298-aa39-0bd2d8e51c2a
ms.openlocfilehash: 7e2e818ed70ec393e4f81008f76ca9efe9cfa7e7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81341407"
---
# <a name="_mbbtype-_mbbtype_l"></a>_mbbtype, _mbbtype_l

Retorna o tipo de byte, com base no byte anterior.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _mbbtype(
   unsigned char c,
   int type
);
int _mbbtype_l(
   unsigned char c,
   int type,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*C*<br/>
O caractere a ser testado.

*type*<br/>
O tipo de byte para o qual testar.

*Localidade*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

**_mbbtype** retorna o tipo de byte em uma seqüência. Esta decisão é sensível ao contexto, conforme especificado pelo valor do *tipo,* que fornece a condição de teste de controle. *tipo* é o tipo do byte anterior na string. As constantes de manifesto na tabela a seguir são definidas em Mbctype.h.

|Valor do *tipo*|**testes de _mbbtype** para|Valor retornado|*C*|
|---------------------|--------------------------|------------------|---------|
|Qualquer valor exceto 1|Byte único ou byte inicial válido|**_MBC_SINGLE** (0)|Byte único (0x20 - 0x7E, 0xA1 - 0xDF)|
|Qualquer valor exceto 1|Byte único ou byte inicial válido|**_MBC_LEAD** (1)|Byte de chumbo de caractere multibyte (0x81 - 0x9F, 0xE0 - 0xFC)|
|Qualquer valor exceto 1|Byte único ou byte inicial válido|**_MBC_ILLEGAL**<br /><br /> ( -1)|Caractere inválido (qualquer valor exceto 0x20 - 0x7E, 0xA1 - 0xDF, 0x81 - 0x9F, 0xE0 - 0xFC|
|1|Byte final válido|**_MBC_TRAIL** (2)|Byte de caráter multibyte (0x40 - 0x7E, 0x80 - 0xFC)|
|1|Byte final válido|**_MBC_ILLEGAL**<br /><br /> ( -1)|Caractere inválido (qualquer valor exceto 0x20 - 0x7E, 0xA1 - 0xDF, 0x81 - 0x9F, 0xE0 - 0xFC|

## <a name="remarks"></a>Comentários

A função **_mbbtype** determina o tipo de byte em um caractere multibyte. Se o valor do *tipo* for de qualquer valor, exceto 1, **_mbbtype** testes para um byte único válido ou byte de chumbo de um caractere multibyte. Se o valor do *tipo* for 1, **_mbbtype** testes para um byte de trilha válido de um caractere multibyte.

O valor de saída é afetado pela configuração da configuração da categoria **LC_CTYPE** do local; consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md) para obter mais informações. A **versão _mbbtype** desta função usa o local atual para este comportamento dependente da localidade; a versão **_mbbtype_l** é idêntica, exceto que usa o parâmetro local que é passado em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Em versões anteriores, **_mbbtype** foi nomeado **chkctype**. Para novo código, use **_mbbtype** em vez disso.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_mbbtype**|\<mbstring.h>|\<mbctype.h>*|
|**_mbbtype_l**|\<mbstring.h>|\<mbctype.h>*|

\* Para obter definições de constantes de manifesto que são usadas como valores retornados.

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
