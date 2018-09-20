---
title: 'Construtor Event:: Event (biblioteca de modelos C++ do Windows Runtime) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Event::Event
dev_langs:
- C++
ms.assetid: 21495297-9612-4095-9256-16e168cc0021
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8bd9f02935d0d88976fd3b62c7276f106519fa74
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46381004"
---
# <a name="eventevent-constructor-windows-runtime-c-template-library"></a>Construtor Event::Event (Biblioteca em Tempo de Execução C++ do Windows Runtime )

Inicializa uma nova instância dos **evento** classe.

## <a name="syntax"></a>Sintaxe

```cpp
explicit Event(
   HANDLE h = HandleT::Traits::GetInvalidValue()  
);
WRL_NOTHROW Event(
   _Inout_ Event&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Manipular um evento. Por padrão, *h* é inicializado como **nullptr**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe Event (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/event-class-windows-runtime-cpp-template-library.md)