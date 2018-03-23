---
title: Estrutura de InvokeModeOptions | Microsoft Docs
ms.custom: ''
ms.date: 03/22/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::InvokeModeOptions
- event/Microsoft::WRL::InvokeMode
dev_langs:
- C++
helpviewer_keywords:
- InvokeModeOptions structure
- InvokeMode enum
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b27789f582b383530a675da83456a100780760b4
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="invokemodeoptions-structure"></a>Estrutura InvokeModeOptions

Especifica se acionar todos os eventos na fila de delegado ou parar acionados depois que um erro será gerado. Os valores permitidos são especificados no `InvokeMode` enum.

## <a name="syntax"></a>Sintaxe

```
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

 **Cabeçalho:** event.h

 **Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft:: wrl](../windows/microsoft-wrl-namespace.md)
[Microsoft::WRL::AgileEventSource classe](../windows/agileeventsource-class.md)