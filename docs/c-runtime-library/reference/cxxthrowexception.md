---
title: _CxxThrowException
ms.date: 11/04/2016
api_name:
- _CxxThrowException
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- CxxThrowException
- _CxxThrowException
helpviewer_keywords:
- _CxxThrowException function
- CxxThrowException function
ms.assetid: 0b90bef5-b7d2-46e0-88e2-59e531e01a4d
ms.openlocfilehash: a5b614d25502ddd5a58aedcf2ec843b2b1ab9d47
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70942035"
---
# <a name="_cxxthrowexception"></a>_CxxThrowException

Cria o registro de exceção e chama o ambiente de tempo de execução para iniciar o processamento da exceção.

## <a name="syntax"></a>Sintaxe

```C
extern "C" void __stdcall _CxxThrowException(
   void* pExceptionObject
   _ThrowInfo* pThrowInfo
);
```

### <a name="parameters"></a>Parâmetros

*pExceptionObject*<br/>
O objeto que gerou a exceção.

*pThrowInfo*<br/>
As informações necessárias para processar a exceção.

## <a name="remarks"></a>Comentários

Esse método é incluído em um arquivo somente de compilador que o compilador usa para processar exceções. Não chame o método diretamente do código.

## <a name="requirements"></a>Requisitos

**Original** Throw.cpp

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
