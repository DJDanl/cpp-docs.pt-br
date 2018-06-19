---
title: _setmbcp | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _setmbcp
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
- api-ms-win-crt-locale-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _setmbcp
- setmbcp
dev_langs:
- C++
helpviewer_keywords:
- setmbcp function
- _setmbcp function
- multibyte code pages
ms.assetid: cfde53b5-0b73-4684-81b1-a8d3aafc85de
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 91993171def417adfc389420d1376e5a71f8cda0
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32408062"
---
# <a name="setmbcp"></a>_setmbcp

Define uma nova página de código multibyte.

## <a name="syntax"></a>Sintaxe

```C
int _setmbcp(
   int codepage
);
```

### <a name="parameters"></a>Parâmetros

*Página de código*<br/>
Nova configuração de página de código para rotinas multibyte independentes da localidade.

## <a name="return-value"></a>Valor de retorno

Retorna 0 se a página de código é definida com êxito. Se um valor de página de código inválido é fornecido para *codepage*, retorna -1 e a configuração de página de código é alterada. Conjuntos de **errno** para **EINVAL** se ocorrer uma falha de alocação de memória.

## <a name="remarks"></a>Comentários

O **setmbcp** função especifica uma nova página de código multibyte. Por padrão, o sistema de tempo de execução define automaticamente a página de código multibyte para a página de código ANSI padrão do sistema. A configuração de página de código multibyte afeta todas as rotinas multibyte que não são dependentes da localidade. No entanto, é possível instruir o **setmbcp** para usar a página de código definida para a localidade atual (consulte a seguinte lista de constantes de manifesto e associados a resultados de comportamento). Para obter uma lista das rotinas de multibyte que dependem da página de código de localidade em vez da página de código multibyte, consulte [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md).

A página de código multibyte também afeta o processamento de caracteres multibyte pelas rotinas de biblioteca em tempo de execução a seguir:

||||
|-|-|-|
|[Funções _exec](../../c-runtime-library/exec-wexec-functions.md)|[_mktemp](mktemp-wmktemp.md)|[_stat](stat-functions.md)|
|[_fullpath](fullpath-wfullpath.md)|[Funções _spawn](../../c-runtime-library/spawn-wspawn-functions.md)|[_tempnam](tempnam-wtempnam-tmpnam-wtmpnam.md)|
|[_makepath](makepath-wmakepath.md)|[_splitpath](splitpath-wsplitpath.md)|[tmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)|

Além disso, todas as rotinas de biblioteca de tempo de execução que recebem caracteres multibyte *argv* ou *envp* argumentos como parâmetros de programa (como o **EXEC** e **spawn** famílias) processar essas cadeias de caracteres de acordo com a página de código multibyte. Portanto, essas rotinas também serão afetadas por uma chamada para **setmbcp** que altera a página de código multibyte.

O *codepage* argumento pode ser definido para qualquer um dos seguintes valores:

- **_MB_CP_ANSI** obtido de página de código ANSI do uso do sistema operacional na inicialização do programa.

- **_MB_CP_LOCALE** use a página de código da localidade atual, obtida de uma chamada anterior para [setlocale](setlocale-wsetlocale.md).

- **_MB_CP_OEM** obtido de página de código OEM do uso do sistema operacional na inicialização do programa.

- **_MB_CP_SBCS** use a página de código de byte único. Quando a página de código é definida como **_MB_CP_SBCS**, uma rotina, como [ismbblead](ismbblead-ismbblead-l.md) sempre retorna false.

- Qualquer outro valor de página de código válido, independentemente de ser um valor ANSI, OEM ou outra página de código com suporte pelo sistema operacional (exceto UTF-7 e UTF-8, que não têm suporte).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_setmbcp**|\<mbctype.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[_getmbcp](getmbcp.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
