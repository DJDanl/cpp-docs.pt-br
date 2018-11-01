---
title: _CxxThrowException
ms.date: 11/04/2016
apiname:
- _CxxThrowException
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
apitype: DLLExport
f1_keywords:
- CxxThrowException
- _CxxThrowException
helpviewer_keywords:
- _CxxThrowException function
- CxxThrowException function
ms.assetid: 0b90bef5-b7d2-46e0-88e2-59e531e01a4d
ms.openlocfilehash: 925b72a120b31029b76fa38bee73eea003511cd2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50550326"
---
# <a name="cxxthrowexception"></a>_CxxThrowException

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

**Fonte:** Throw.cpp

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
