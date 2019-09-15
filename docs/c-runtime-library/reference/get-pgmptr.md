---
title: _get_pgmptr
ms.date: 11/04/2016
api_name:
- _get_pgmptr
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- get_pgmptr
- _get_pgmptr
helpviewer_keywords:
- get_pgmptr function
- _get_pgmptr function
- pgmptr global variable
- _pgmptr global variable
ms.assetid: 29f16a9f-a685-4721-add3-7fad4f67eece
ms.openlocfilehash: 4f9a3b19cc7eb1870b87ec46b7923987ec646e32
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70955759"
---
# <a name="_get_pgmptr"></a>_get_pgmptr

Obtém o valor atual da variável global **_pgmptr** .

## <a name="syntax"></a>Sintaxe

```C
errno_t _get_pgmptr(
   char **pValue
);
```

### <a name="parameters"></a>Parâmetros

*pValue*<br/>
Um ponteiro para uma cadeia de caracteres a ser preenchida com o valor atual da variável **_pgmptr** .

## <a name="return-value"></a>Valor de retorno

Retorna zero se tiver êxito; um código de erro em caso de falha. Se o **valor**de válido for NULL, o manipulador de parâmetro *inválido será* invocado conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função definirá **errno** como **EINVAL** e retornará **EINVAL**.

## <a name="remarks"></a>Comentários

Somente chame **_get_pgmptr** se o seu programa tiver um ponto de entrada estreito, como **Main ()** ou **WinMain ()** . A variável global **_pgmptr** contém o caminho completo para o executável associado ao processo. Para obter mais informações, consulte [_pgmptr, _wpgmptr](../../c-runtime-library/pgmptr-wpgmptr.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_pgmptr**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[_get_wpgmptr](get-wpgmptr.md)<br/>
