---
title: Classe de evento (biblioteca de modelos C++ do Windows Runtime) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Event
dev_langs:
- C++
ms.assetid: 55dfc9fc-62d4-4bb2-9d85-5b6dd88569e8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b40e9c5e04c21cdbcc56581e02751edc84e4617d
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42606283"
---
# <a name="event-class-windows-runtime-c-template-library"></a>Classe Event (Biblioteca em Tempo de Execução C++ do Windows Runtime )

Representa um evento.

## <a name="syntax"></a>Sintaxe

```cpp
class Event : public HandleT<HandleTraits::EventTraits>;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor Event::Event (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/event-event-constructor-windows-runtime-cpp-template-library.md)|Inicializa uma nova instância dos **evento** classe.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador Event::operator=](../windows/event-operator-assign-operator.md)|Atribui especificado **evento** referência atual **evento** instância.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HandleT`

`Event`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)