---
title: _setmbcp
ms.date: 4/2/2020
api_name:
- _setmbcp
- _o__setmbcp
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
- api-ms-win-crt-locale-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _setmbcp
- setmbcp
helpviewer_keywords:
- setmbcp function
- _setmbcp function
- multibyte code pages
ms.assetid: cfde53b5-0b73-4684-81b1-a8d3aafc85de
ms.openlocfilehash: 61086471c6194aaa8434d291647978bf891a8aea
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337600"
---
# <a name="_setmbcp"></a>_setmbcp

Define uma nova página de código multibyte.

## <a name="syntax"></a>Sintaxe

```C
int _setmbcp(
   int codepage
);
```

### <a name="parameters"></a>Parâmetros

*Codepage*<br/>
Nova configuração de página de código para rotinas multibyte independentes da localidade.

## <a name="return-value"></a>Valor retornado

Retorna 0 se a página de código é definida com êxito. Se um valor de página de código inválido for fornecido para *a página de código,* retorna -1 e a configuração da página de código será inalterada. Define **errno** para **EINVAL** se ocorrer uma falha de alocação de memória.

## <a name="remarks"></a>Comentários

A função **_setmbcp** especifica uma nova página de código multibyte. Por padrão, o sistema de tempo de execução define automaticamente a página de código multibyte para a página de código ANSI padrão do sistema. A configuração de página de código multibyte afeta todas as rotinas multibyte que não são dependentes da localidade. No entanto, é possível instruir **_setmbcp** a usar a página de código definida para o local atual (veja a lista a seguir de constantes manifestas e resultados de comportamento associados). Para obter uma lista das rotinas de multibyte que dependem da página de código de localidade em vez da página de código multibyte, consulte [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md).

A página de código multibyte também afeta o processamento de caracteres multibyte pelas rotinas de biblioteca em tempo de execução a seguir:

||||
|-|-|-|
|[Funções _exec](../../c-runtime-library/exec-wexec-functions.md)|[_mktemp](mktemp-wmktemp.md)|[_stat](stat-functions.md)|
|[_fullpath](fullpath-wfullpath.md)|[Funções _spawn](../../c-runtime-library/spawn-wspawn-functions.md)|[_tempnam](tempnam-wtempnam-tmpnam-wtmpnam.md)|
|[_makepath](makepath-wmakepath.md)|[_splitpath](splitpath-wsplitpath.md)|[tmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)|

Além disso, todas as rotinas de biblioteca em tempo de execução que recebem argumentos de programa *sargv* de caracteres multibytes ou *envp* como parâmetros (como o **_exec** e **_spawn** famílias) processam essas strings de acordo com a página de código multibyte. Portanto, essas rotinas também são afetadas por uma chamada para **_setmbcp** que altera a página de código multibyte.

O argumento *de página de código* pode ser definido como qualquer um dos seguintes valores:

- **_MB_CP_ANSI _MB_CP_ANSI.** Use a página de código ANSI obtida do sistema operacional na inicialização do programa.

- **_MB_CP_LOCALE** Use a página de código do local atual obtida a partir de uma chamada anterior para [setlocale](setlocale-wsetlocale.md).

- **_MB_CP_OEM** Use a página de código OEM obtida do sistema operacional na inicialização do programa.

- **_MB_CP_SBCS _MB_CP_SBCS.** Use a página de código single byte. Quando a página de código é definida como **_MB_CP_SBCS**, uma rotina como [_ismbblead](ismbblead-ismbblead-l.md) sempre retorna falsa.

- **_MB_CP_UTF8 _MB_CP_UTF8** Use UTF-8.  Quando a página de código é definida como **_MB_CP_UTF8,** uma rotina como [_ismbblead](ismbblead-ismbblead-l.md) sempre retorna falsa.

- Qualquer outro valor de página de código válido, independentemente de o valor ser uma página de código ANSI, OEM ou outra página de código suportada pelo sistema operacional (exceto UTF-7, que não é suportado).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_setmbcp**|\<mbctype.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[_getmbcp](getmbcp.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
