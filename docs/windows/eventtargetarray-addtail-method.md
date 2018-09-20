---
title: 'Método eventtargetarray:: Addtail | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::EventTargetArray::AddTail
dev_langs:
- C++
helpviewer_keywords:
- AddTail method
ms.assetid: d0fafab9-049c-40e0-a40c-d126c9ee63e6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ab0219c8893ff7ad35e29f9dd8b18be18caf8eb9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46378118"
---
# <a name="eventtargetarrayaddtail-method"></a>Método EventTargetArray::AddTail

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
void AddTail(
   _In_ IUnknown* element
);
```

### <a name="parameters"></a>Parâmetros

*Elemento*<br/>
Ponteiro para o manipulador de eventos para acrescentar.

## <a name="remarks"></a>Comentários

Acrescenta o manipulador de eventos especificado ao final da matriz interna de manipuladores de eventos.

**AddTail()** se destina a ser usado internamente pelo apenas o `EventSource` classe.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe EventTargetArray](../windows/eventtargetarray-class.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)