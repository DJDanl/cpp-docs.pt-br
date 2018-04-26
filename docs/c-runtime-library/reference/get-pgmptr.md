---
title: _get_pgmptr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- get_pgmptr function
- _get_pgmptr function
- pgmptr global variable
- _pgmptr global variable
ms.assetid: 29f16a9f-a685-4721-add3-7fad4f67eece
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6af6203f8c6f40335a132f21929abf3cc4ce1808
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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
Um ponteiro para uma cadeia de caracteres a ser preenchida com o valor atual de **pgmptr** variável.

## <a name="return-value"></a>Valor de retorno

Retorna zero se tiver êxito; um código de erro em caso de falha. Se *pValue* é **nulo**, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, esta função define **errno** para **EINVAL** e retorna **EINVAL**.

## <a name="remarks"></a>Comentários

Somente chamar **get_pgmptr** se seu programa tiver um ponto de entrada específica, como **Main** ou **WinMain**. O **pgmptr** variável global contém o caminho completo para o executável associado ao processo. Para obter mais informações, consulte [_pgmptr, _wpgmptr](../../c-runtime-library/pgmptr-wpgmptr.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_pgmptr**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[_get_wpgmptr](get-wpgmptr.md)<br/>
