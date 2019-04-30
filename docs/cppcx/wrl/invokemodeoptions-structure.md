---
title: Estrutura InvokeModeOptions
ms.date: 03/22/2018
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::InvokeModeOptions
helpviewer_keywords:
- InvokeModeOptions structure
- InvokeMode enum
ms.openlocfilehash: 0e5b45042c9959b87ad5db97ab755e49de469149
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386038"
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