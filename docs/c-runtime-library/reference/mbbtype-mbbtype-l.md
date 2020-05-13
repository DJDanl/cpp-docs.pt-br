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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: dca59f2d31cc5ad843a48e9825ef6a617d46ae4a
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919596"
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

*&*<br/>
O caractere a ser testado.

*type*<br/>
O tipo de byte para o qual testar.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

**_mbbtype** retorna o tipo de byte em uma cadeia de caracteres. Essa decisão é sensível ao contexto, conforme especificado pelo valor do *tipo*, que fornece a condição de teste de controle. *Type* é o tipo do byte anterior na cadeia de caracteres. As constantes de manifesto na tabela a seguir são definidas em Mbctype.h.

|Valor do *tipo*|**_mbbtype** testes para|Valor retornado|*&*|
|---------------------|--------------------------|------------------|---------|
|Qualquer valor exceto 1|Byte único ou byte inicial válido|**_MBC_SINGLE** (0)|Byte único (0x20-0x7E, 0xA1-0xDF)|
|Qualquer valor exceto 1|Byte único ou byte inicial válido|**_MBC_LEAD** (1)|Byte de Lead de caractere multibyte (0x81-0x9F, 0xE0-0xFC)|
|Qualquer valor exceto 1|Byte único ou byte inicial válido|**_MBC_ILLEGAL**<br /><br /> (-1)|Caractere inválido (qualquer valor, exceto 0x20-0x7E, 0xA1-0xDF, 0x81-0x9F, 0xE0-0xFC|
|1|Byte final válido|**_MBC_TRAIL** (2)|Byte à direita de caractere multibyte (0x40-0x7E, 0x80-0xFC)|
|1|Byte final válido|**_MBC_ILLEGAL**<br /><br /> (-1)|Caractere inválido (qualquer valor, exceto 0x20-0x7E, 0xA1-0xDF, 0x81-0x9F, 0xE0-0xFC|

## <a name="remarks"></a>Comentários

A função **_mbbtype** determina o tipo de um byte em um caractere multibyte. Se o valor do *tipo* for qualquer valor, exceto 1, **_mbbtype** testes para um byte de um byte único ou de cliente potencial válido de um caractere multibyte. Se o valor do *tipo* for 1, **_mbbtype** testes para um byte final válido de um caractere multibyte.

O valor de saída é afetado pela configuração da configuração de categoria de **LC_CTYPE** da localidade; consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md) para obter mais informações. A versão **_mbbtype** dessa função usa a localidade atual para esse comportamento dependente de localidade; a versão **_mbbtype_l** é idêntica, exceto pelo fato de usar o parâmetro Locale que é passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Em versões anteriores, **_mbbtype** foi chamado de **chkctype**. Para obter um novo código, use **_mbbtype** em vez disso.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_mbbtype**|\<mbstring.h>|\<mbctype.h>*|
|**_mbbtype_l**|\<mbstring.h>|\<mbctype.h>*|

\* Para obter definições de constantes de manifesto que são usadas como valores retornados.

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
