---
title: _get_wpgmptr
ms.date: 4/2/2020
api_name:
- _get_wpgmptr
- _o__get_wpgmptr
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
- api-ms-win-crt-runtime-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- get_wpgmptr
- _get_wpgmptr
helpviewer_keywords:
- _wpgmptr global variable
- get_wpgmptr function
- wpgmptr global variable
- _get_wpgmptr function
ms.assetid: a77cdd13-2303-4b7c-9a60-8debdbef2011
ms.openlocfilehash: 1e54d3dbdc837c491f5b39d33a9b8197094ac60b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81344858"
---
# <a name="_get_wpgmptr"></a>_get_wpgmptr

Obtém o valor atual da **variável global _wpgmptr.**

## <a name="syntax"></a>Sintaxe

```C
errno_t _get_wpgmptr(
   wchar_t **pValue
);
```

### <a name="parameters"></a>Parâmetros

*pValue*<br/>
Um ponteiro para uma seqüência a ser preenchido com o valor atual da variável **_wpgmptr.**

## <a name="return-value"></a>Valor retornado

Retorna zero se tiver êxito; um código de erro em caso de falha. Se *pValue* for **NULL,** o manipulador de parâmetros inválidos será invocado conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função define **errno** para **EINVAL** e retorna **EINVAL**.

## <a name="remarks"></a>Comentários

Só chame **_get_wpgmptr** se o seu programa tiver um ponto de entrada amplo, como **wmain()** ou **wWinMain().** A variável global **_wpgmptr** contém o caminho completo para o executável associado ao processo como uma seqüência de caracteres amplos. Para obter mais informações, consulte [_pgmptr, _wpgmptr](../../c-runtime-library/pgmptr-wpgmptr.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_wpgmptr**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[_get_pgmptr](get-pgmptr.md)<br/>
