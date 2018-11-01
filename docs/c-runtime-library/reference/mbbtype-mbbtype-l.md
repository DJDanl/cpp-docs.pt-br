---
title: _mbbtype, _mbbtype_l
ms.date: 11/04/2016
apiname:
- _mbbtype
- _mbbtype_l
apilocation:
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
apitype: DLLExport
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
ms.openlocfilehash: a6d17b99e4314c2ab836a16129ab8a0e6ac7720e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50467165"
---
# <a name="mbbtype-mbbtypel"></a>_mbbtype, _mbbtype_l

Retorna o tipo de byte, com base no byte anterior.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*c*<br/>
O caractere a ser testado.

*type*<br/>
O tipo de byte para o qual testar.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

**mbbtype** retorna o tipo de byte em uma cadeia de caracteres. Essa decisão é contextual, conforme especificado pelo valor de *tipo*, que fornece a condição de teste do controle. *tipo* é o tipo de byte anterior na cadeia de caracteres. As constantes de manifesto na tabela a seguir são definidas em Mbctype.h.

|Valor de *tipo*|**mbbtype** testa para|Valor retornado|*c*|
|---------------------|--------------------------|------------------|---------|
|Qualquer valor exceto 1|Byte único ou byte inicial válido|**_MBC_SINGLE** (0)|Byte único (0x20 – 0x7E, 0xA1 – 0xDF)|
|Qualquer valor exceto 1|Byte único ou byte inicial válido|**_MBC_LEAD** (1)|Byte inicial do caractere multibyte (0x81 – 0x9F, 0xE0 – 0xFC)|
|Qualquer valor exceto 1|Byte único ou byte inicial válido|**_MBC_ILLEGAL**<br /><br /> ( -1)|Caractere inválido (qualquer valor exceto 0x20 – 0x7E, 0xA1 – 0xDF, 0x81 – 0x9F, 0xE0 – 0xFC|
|1|Byte final válido|**_MBC_TRAIL** (2)|Byte à direita do caractere multibyte (0x40 – 0x7E, 0x80 – 0xFC)|
|1|Byte final válido|**_MBC_ILLEGAL**<br /><br /> ( -1)|Caractere inválido (qualquer valor exceto 0x20 – 0x7E, 0xA1 – 0xDF, 0x81 – 0x9F, 0xE0 – 0xFC|

## <a name="remarks"></a>Comentários

O **mbbtype** função determina o tipo de um byte em um caractere multibyte. Se o valor de *tipo* é qualquer valor exceto 1, **mbbtype** testes para um válido byte único ou byte inicial de um caractere multibyte. Se o valor de *tipo* é 1, **mbbtype** testes para um byte final válido de um caractere multibyte.

O valor de saída é afetado pela configuração da **LC_CTYPE** configuração da categoria da localidade; consulte [setlocale, wsetlocale](setlocale-wsetlocale.md) para obter mais informações. O **mbbtype** versão dessa função usa a localidade atual desse comportamento dependente da localidade; as **mbbtype_l** versão é idêntico, exceto que ele use o parâmetro de localidade passado em seu lugar . Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Em versões anteriores, **mbbtype** foi nomeado **chkctype**. Para código novo, use **mbbtype** em vez disso.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_mbbtype**|\<mbstring.h>|\<mbctype.h>*|
|**_mbbtype_l**|\<mbstring.h>|\<mbctype.h>*|

\* Para obter definições de constantes de manifesto que são usadas como valores retornados.

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
