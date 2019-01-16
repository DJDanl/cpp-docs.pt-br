---
title: Estrutura InvokeModeOptions
ms.date: 03/22/2018
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::InvokeModeOptions
helpviewer_keywords:
- InvokeModeOptions structure
- InvokeMode enum
ms.openlocfilehash: ff16c6c5a2ce09313283198fe0b86e95d572e46c
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335481"
---
# <a name="invokemodeoptions-structure"></a>Estrutura InvokeModeOptions

Especifica se deve acionar todos os eventos na fila de delegado ou parar o acionamento depois que um erro será gerado. Os valores permitidos são especificados no `InvokeMode` enum.

## <a name="syntax"></a>Sintaxe

```cpp
enum InvokeMode
{
   StopOnFirstError = 1,
   FireAll = 2,
};

struct InvokeModeOptions
{
   static const InvokeMode invokeMode = invokeModeValue;
};
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)<br/>
[Classe Microsoft::WRL::AgileEventSource](agileeventsource-class.md)