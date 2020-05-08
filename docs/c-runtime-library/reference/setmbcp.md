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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 18712661b2bda1eaaf0c583b922ad73a781b4abc
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82918824"
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

*código*<br/>
Nova configuração de página de código para rotinas multibyte independentes da localidade.

## <a name="return-value"></a>Valor retornado

Retorna 0 se a página de código é definida com êxito. Se um valor de página de código inválido for fornecido para *CodePage*, retornará-1 e a configuração da página de código não será alterada. Define **errno** como **EINVAL** se ocorrer uma falha de alocação de memória.

## <a name="remarks"></a>Comentários

A função **_setmbcp** especifica uma nova página de código multibyte. Por padrão, o sistema de tempo de execução define automaticamente a página de código multibyte para a página de código ANSI padrão do sistema. A configuração de página de código multibyte afeta todas as rotinas multibyte que não são dependentes da localidade. No entanto, é possível instruir **_setmbcp** a usar a página de código definida para a localidade atual (consulte a lista de constantes de manifesto e os resultados de comportamento associados a seguir). Para obter uma lista das rotinas de multibyte que dependem da página de código de localidade em vez da página de código multibyte, consulte [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md).

A página de código multibyte também afeta o processamento de caracteres multibyte pelas rotinas de biblioteca em tempo de execução a seguir:

||||
|-|-|-|
|[Funções _exec](../../c-runtime-library/exec-wexec-functions.md)|[_mktemp](mktemp-wmktemp.md)|[_stat](stat-functions.md)|
|[_fullpath](fullpath-wfullpath.md)|[Funções _spawn](../../c-runtime-library/spawn-wspawn-functions.md)|[_tempnam](tempnam-wtempnam-tmpnam-wtmpnam.md)|
|[_makepath](makepath-wmakepath.md)|[_splitpath](splitpath-wsplitpath.md)|[tmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)|

Além disso, todas as rotinas de biblioteca de tempo de execução que recebem argumentos de programa *argv* ou *envp* de caractere multibyte como parâmetros (como as famílias **_exec** e **_spawn** ) processam essas cadeias de caracteres de acordo com a página de código multibyte. Portanto, essas rotinas também são afetadas por uma chamada para **_setmbcp** que altera a página de código multibyte.

O argumento *CodePage* pode ser definido como qualquer um dos seguintes valores:

- **_MB_CP_ANSI** Use a página de código ANSI obtida do sistema operacional na inicialização do programa.

- **_MB_CP_LOCALE** Use a página de código da localidade atual Obtida de uma chamada anterior para [setlocale](setlocale-wsetlocale.md).

- **_MB_CP_OEM** Use a página de código OEM obtida do sistema operacional na inicialização do programa.

- **_MB_CP_SBCS** Use a página de código de byte único. Quando a página de código é definida como **_MB_CP_SBCS**, uma rotina como [_ismbblead](ismbblead-ismbblead-l.md) sempre retorna false.

- **_MB_CP_UTF8** Use UTF-8.  Quando a página de código é definida como **_MB_CP_UTF8**, uma rotina como [_ismbblead](ismbblead-ismbblead-l.md) sempre retorna false.

- Qualquer outro valor de página de código válido, independentemente de o valor ser um ANSI, OEM ou outra página de código com suporte do sistema operacional (exceto UTF-7, que não tem suporte).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_setmbcp**|\<mbctype.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[_getmbcp](getmbcp.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
