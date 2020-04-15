---
title: isleadbyte, _isleadbyte_l
ms.date: 4/2/2020
api_name:
- _isleadbyte_l
- isleadbyte
- _o__isleadbyte_l
- _o_isleadbyte
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
- api-ms-win-crt-string-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _istleadbyte
- _isleadbyte_l
- isleadbyte
helpviewer_keywords:
- lead bytes
- _isleadbyte_l function
- _istleadbyte function
- istleadbyte function
- isleadbyte function
ms.assetid: 3b2bcf09-d82b-4803-9e80-59d04942802a
ms.openlocfilehash: dddf1d669f77805df8e00f506b6427603ac8fd9f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81343837"
---
# <a name="isleadbyte-_isleadbyte_l"></a>isleadbyte, _isleadbyte_l

Determina se um caractere é o byte inicial de um caractere multibyte.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int isleadbyte( int c );
int _isleadbyte_l( int c );
```

### <a name="parameters"></a>Parâmetros

*C*<br/>
Inteiro a ser testado.

## <a name="return-value"></a>Valor retornado

**isleadbyte** retorna um valor não zero se o argumento satisfaz a condição de teste ou 0 se não o fizer. No local "C" e nas localidades do conjunto de caracteres single-byte (SBCS), **isleadbyte** sempre retorna 0.

## <a name="remarks"></a>Comentários

A macro **isleadbyte** retorna um valor não zero se seu argumento for o primeiro byte de um caractere multibyte. **isleadbyte** produz um resultado significativo para qualquer argumento inteiro de -1 (**EOF**) a **UCHAR_MAX** (0xFF), inclusive.

O tipo de argumento esperado de **isleadbyte** é **int;** se um caractere assinado for aprovado, o compilador pode convertê-lo em um inteiro por extensão de sinal, produzindo resultados imprevisíveis.

A versão desta função com o **sufixo _l** é idêntica, exceto que ele usa a localidade passada em vez da localidade atual para seu comportamento dependente da localidade.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_istleadbyte**|Sempre retorna falso|**_isleadbyte**|Sempre retorna falso|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isleadbyte**|\<ctype.h>|
|**_isleadbyte_l**|\<ctype.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
