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
ms.openlocfilehash: 9a981c40b9e525ba1ffc1f2198f2b6a859fd9ac7
ms.sourcegitcommit: b51703a96ee35ee2376d5f0775b70f03ccbe6d9a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/11/2020
ms.locfileid: "88086962"
---
# <a name="_setmbcp"></a>_setmbcp

Define uma nova página de código multibyte.

## <a name="syntax"></a>Sintaxe

```C
int _setmbcp(
   int codepage
);
```

### <a name="parameters"></a>parâmetros

*código*<br/>
Nova configuração de página de código para rotinas multibyte independentes da localidade.

## <a name="return-value"></a>Valor retornado

Retorna 0 se a página de código é definida com êxito. Se um valor de página de código inválido for fornecido para *CodePage*, retornará-1 e a configuração da página de código não será alterada. Define **errno** como **EINVAL** se ocorrer uma falha de alocação de memória.

## <a name="remarks"></a>Comentários

A função **_setmbcp** especifica uma nova página de código multibyte. Por padrão, o sistema de tempo de execução define automaticamente a página de código multibyte para a página de código ANSI padrão do sistema. A configuração de página de código multibyte afeta todas as rotinas multibyte que não são dependentes da localidade. No entanto, é possível instruir **_setmbcp** a usar a página de código definida para a localidade atual (consulte a lista de constantes de manifesto e os resultados de comportamento associados a seguir). Para obter uma lista das rotinas de multibyte que dependem da página de código de localidade em vez da página de código multibyte, consulte [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md).

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

## <a name="see-also"></a>Confira também

[_getmbcp](getmbcp.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
