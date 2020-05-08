---
title: _ismbcgraph, _ismbcgraph_l, _ismbcprint, _ismbcprint_l, _ismbcpunct, _ismbcpunct_l, _ismbcblank, _ismbcblank_l, _ismbcspace, _ismbcspace_l
ms.date: 4/2/2020
api_name:
- _ismbcpunct_l
- _ismbcblank
- _ismbcprint
- _ismbcgraph_l
- _ismbcblank_l
- _ismbcpunct
- _ismbcprint_l
- _ismbcspace_l
- _ismbcspace
- _ismbcgraph
- _o__ismbcblank
- _o__ismbcblank_l
- _o__ismbcgraph
- _o__ismbcgraph_l
- _o__ismbcprint
- _o__ismbcprint_l
- _o__ismbcpunct
- _o__ismbcpunct_l
- _o__ismbcspace
- _o__ismbcspace_l
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
- _ismbcspace
- _ismbcgraph
- _ismbcpunct
- ismbcspace_l
- ismbcgraph
- _ismbcgraph_l
- _ismbcprint
- _ismbcspace_l
- ismbcprint
- ismbcgraph_l
- ismbcspace
- ismbcpunct
helpviewer_keywords:
- ismbcspace_l function
- _ismbcprint_l function
- ismbcspace function
- ismbcpunct function
- _ismbcspace_l function
- _ismbcprint function
- ismbcprint function
- _ismbcgraph function
- ismbcgraph_l function
- _ismbcpunct_l function
- ismbcpunct_l function
- ismbcprint_l function
- _ismbcpunct function
- ismbcgraph function
- _ismbcgraph_l function
- _ismbcspace function
ms.assetid: 8e0a5f47-ba64-4411-92a3-3c525d16e3be
ms.openlocfilehash: 5f2c8b595de323994aa670a8e0fee9e562897e49
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919757"
---
# <a name="_ismbcgraph-_ismbcgraph_l-_ismbcprint-_ismbcprint_l-_ismbcpunct-_ismbcpunct_l-_ismbcblank-_ismbcblank_l-_ismbcspace-_ismbcspace_l"></a>_ismbcgraph, _ismbcgraph_l, _ismbcprint, _ismbcprint_l, _ismbcpunct, _ismbcpunct_l, _ismbcblank, _ismbcblank_l, _ismbcspace, _ismbcspace_l

Determina se o caractere é um caractere gráfico, um caractere de exibição, um caractere de pontuação ou um caractere de espaço.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _ismbcgraph(
   unsigned int c
);
int _ismbcgraph_l(
   unsigned int c,
   _locale_t locale
);
int _ismbcprint(
   unsigned int c
);
int _ismbcprint_l(
   unsigned int c,
   _locale_t locale
);
int _ismbcpunct(
   unsigned int c
);
int _ismbcpunct_l(
   unsigned int c,
   _locale_t locale
);
int _ismbcblank(
   unsigned int c
);
int _ismbcblank_l(
   unsigned int c,
   _locale_t locale
);
int _ismbcspace(
   unsigned int c
);
int _ismbcspace_l(
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*&*<br/>
Caractere a ser determinado.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Cada uma dessas rotinas retornará um valor diferente de zero se o caractere satisfizer a condição de teste, ou 0 se não satisfizer. Se *c* <= 255 e houver uma rotina de **_ismbb** correspondente (por exemplo, **_ismbcalnum** corresponde a **_ismbbalnum**), o resultado será o valor de retorno da rotina de **_ismbb** correspondente.

As versões dessas funções são idênticas, exceto pelo fato de que aquelas que têm o sufixo **_L** usam a localidade passada para seu comportamento dependente de localidade, em vez da localidade atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções testa um determinado caractere multibyte quanto a uma determinada condição.

|Rotina|Condição de teste|Exemplo da página de código 932|
|-------------|--------------------|---------------------------|
|**_ismbcgraph**|Graphic|Retornará zero se e somente se *c* for uma representação de byte único de qualquer caractere ASCII ou katakana imprimível, exceto um espaço em branco ().|
|**_ismbcprint**|Imprimível|Retornará zero se e somente se *c* for uma representação de byte único de qualquer caractere ASCII ou katakana imprimível, incluindo um espaço em branco ().|
|**_ismbcpunct**|Pontuação|Retornará zero se e somente se *c* for uma representação de byte único de qualquer caractere de Pontuação ASCII ou katakana.|
|**_ismbcblank**|Espaço ou tabulação horizontal|Retornará zero se e somente se *c* for um espaço ou um caractere de tabulação horizontal: *c*= 0x20 ou *c*= 0x09.|
|**_ismbcspace**|Espaço em branco|Retornará zero se e somente se *c* for um caractere de espaço em branco: *c*= 0x20 ou 0x09<=*c*<= 0x0D.|

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_ismbcgraph**|\<mbstring.h>|
|**_ismbcgraph_l**|\<mbstring.h>|
|**_ismbcprint**|\<mbstring.h>|
|**_ismbcprint_l**|\<mbstring.h>|
|**_ismbcpunct**|\<mbstring.h>|
|**_ismbcpunct_l**|\<mbstring.h>|
|**_ismbcblank**|\<mbstring.h>|
|**_ismbcblank_l**|\<mbstring.h>|
|**_ismbcspace**|\<mbstring.h>|
|**_ismbcspace_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Locale](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[Rotinas _ismbc](../../c-runtime-library/ismbc-routines.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
[Rotinas de _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
