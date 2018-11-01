---
title: _get_pgmptr
ms.date: 11/04/2016
apiname:
- _get_pgmptr
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- get_pgmptr
- _get_pgmptr
helpviewer_keywords:
- get_pgmptr function
- _get_pgmptr function
- pgmptr global variable
- _pgmptr global variable
ms.assetid: 29f16a9f-a685-4721-add3-7fad4f67eece
ms.openlocfilehash: 40c9f237aadb5f44066bcbf40fe378fb2ce96fc5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50562494"
---
# <a name="getpgmptr"></a>_get_pgmptr

Obtém o valor atual de **pgmptr** variável global.

## <a name="syntax"></a>Sintaxe

```C
errno_t _get_pgmptr( 
   char **pValue 
);
```

### <a name="parameters"></a>Parâmetros

*pValue*<br/>
Um ponteiro para uma cadeia de caracteres a ser preenchido com o valor atual de **pgmptr** variável.

## <a name="return-value"></a>Valor de retorno

Retorna zero se tiver êxito; um código de erro em caso de falha. Se *pValue* é **nulo**, o manipulador de parâmetro inválido será invocado conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** à **EINVAL** e retorna **EINVAL**.

## <a name="remarks"></a>Comentários

Apenas chame **get_pgmptr** se seu programa tem um ponto de entrada estreitas, como **Main ()** ou **WinMain**. O **pgmptr** variável global contém o caminho completo para o executável associado ao processo. Para obter mais informações, consulte [_pgmptr, _wpgmptr](../../c-runtime-library/pgmptr-wpgmptr.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_pgmptr**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[_get_wpgmptr](get-wpgmptr.md)<br/>
