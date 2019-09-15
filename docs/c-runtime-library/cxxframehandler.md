---
title: __CxxFrameHandler
ms.date: 11/04/2016
api_name:
- __CxxFrameHandler
api_location:
- msvcr110.dll
- msvcrt.dll
- msvcr80.dll
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr90.dll
- msvcr120.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- __CxxFrameHandler
helpviewer_keywords:
- __CxxFrameHandler
ms.assetid: b79ac97f-425a-42ae-9b91-8beaef935333
ms.openlocfilehash: 4cb5ae10d4281c4a7167db7adf4ea6788ad3e3c0
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70944507"
---
# <a name="__cxxframehandler"></a>__CxxFrameHandler

Função CRT interna. Usada pelo CRT para identificar quadros estruturados de exceção.

## <a name="syntax"></a>Sintaxe

```cpp
EXCEPTION_DISPOSITION __CxxFrameHandler(
      EHExceptionRecord  *pExcept,
      EHRegistrationNode *pRN,
      void               *pContext,
      DispatcherContext  *pDC
   )
```

#### <a name="parameters"></a>Parâmetros

*pExcept*<br/>
Registro de exceção passado para as instruções `catch` possíveis.

*pRN*<br/>
Informações dinâmicas sobre o registro de ativação usado para identificar a exceção. Para obter mais informações, consulte ehdata.h.

*pContext*<br/>
Contexto. (Não usado em processadores da Intel.)

*pDC*<br/>
Informações adicionais sobre a entrada da função e o registro de ativação.

## <a name="return-value"></a>Valor de retorno

Um dos valores da *expressão de filtro* usados pela [instrução try-except](../cpp/try-except-statement.md).

## <a name="remarks"></a>Comentários

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|__CxxFrameHandler|excpt.h, ehdata.h|