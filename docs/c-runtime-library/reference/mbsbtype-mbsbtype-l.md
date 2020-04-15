---
title: _mbsbtype, _mbsbtype_l
ms.date: 4/2/2020
api_name:
- _mbsbtype_l
- _mbsbtype
- _o__mbsbtype
- _o__mbsbtype_l
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
- mbsbtype
- mbsbtype_l
- _mbsbtype_l
- _mbsbtype
helpviewer_keywords:
- _mbsbtype function
- mbsbtype function
- _mbsbtype_l function
- mbsbtype_l function
ms.assetid: 0d5dd91a-d32d-4f98-ac57-98dfc9e98eac
ms.openlocfilehash: d71a061d9af5028c9bc6b4008f9904606a233592
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81340867"
---
# <a name="_mbsbtype-_mbsbtype_l"></a>_mbsbtype, _mbsbtype_l

Retorna o tipo de byte em uma cadeia de caracteres.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _mbsbtype(
   const unsigned char *mbstr,
   size_t count
);
int _mbsbtype_l(
   const unsigned char *mbstr,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*Mbstr*<br/>
Endereço de uma sequência de caracteres multibyte.

*contagem*<br/>
Deslocamento do byte do início da cadeia de caracteres.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**_mbsbtype** e **_mbsbtype_l** retorna um valor inteiro indicando o resultado do teste no byte especificado. As constantes de manifesto na tabela a seguir são definidas em Mbctype.h.

|Valor retornado|Tipo de byte|
|------------------|---------------|
|**_MBC_SINGLE** (0)|Caractere de um byte. Por exemplo, na página de código 932, **_mbsbtype** retorna 0 se o byte especificado estiver dentro da faixa 0x20 - 0x7E ou 0xA1 - 0xDF.|
|**_MBC_LEAD** (1)|Byte inicial do caractere multibyte. Por exemplo, na página de código 932, **_mbsbtype** retorna 1 se o byte especificado estiver dentro da faixa 0x81 - 0x9F ou 0xE0 - 0xFC.|
|**_MBC_TRAIL** (2)|Byte à direita do caractere multibyte. Por exemplo, na página de código 932, **_mbsbtype** retorna 2 se o byte especificado estiver dentro da faixa 0x40 - 0x7E ou 0x80 - 0xFC.|
|**_MBC_ILLEGAL** (-1)|**Seqüência null,** caractere inválido ou byte nulo encontrado antes do byte na *contagem* de deslocamento em *mbstr*.|

## <a name="remarks"></a>Comentários

A função **_mbsbtype** determina o tipo de byte em uma seqüência de caracteres multibytes. A função examina apenas o byte na *contagem* de deslocamento em *mbstr,* ignorando caracteres inválidos antes do byte especificado.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. A versão desta função sem o sufixo **_l** usa a localidade atual para este comportamento dependente da localidade; a versão com o **sufixo _l** é idêntica, exceto que ele usa o parâmetro local passado em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se a seqüência de entrada for **NULL,** o manipulador de parâmetros inválidos será invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e a função retorna **_MBC_ILLEGAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_mbsbtype**|\<mbstring.h>|\<mbctype.h>*|
|**_mbsbtype_l**|\<mbstring.h>|\<mbctype.h>*|

\* Para constantes de manifesto usadas como valores retornados.

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
