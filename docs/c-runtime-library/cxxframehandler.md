---
title: __CxxFrameHandler
ms.date: 11/04/2016
apiname:
- __CxxFrameHandler
apilocation:
- msvcr110.dll
- msvcrt.dll
- msvcr80.dll
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr90.dll
- msvcr120.dll
apitype: DLLExport
f1_keywords:
- __CxxFrameHandler
helpviewer_keywords:
- __CxxFrameHandler
ms.assetid: b79ac97f-425a-42ae-9b91-8beaef935333
ms.openlocfilehash: d059df597826c68f4f51eb85f592b7eb44ac7d1f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432108"
---
# <a name="cxxframehandler"></a>__CxxFrameHandler

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

## <a name="return-value"></a>Valor retornado

Um dos valores da *expressão de filtro* usados pela [instrução try-except](../cpp/try-except-statement.md).

## <a name="remarks"></a>Comentários

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|__CxxFrameHandler|excpt.h, ehdata.h|