---
title: 'Constante chaininterfaces:: Iidcount | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::ChainInterfaces::IidCount
dev_langs:
- C++
helpviewer_keywords:
- IidCount constant
ms.assetid: d4a90aa0-513c-4e99-b978-e12149734936
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a97ea483bddb0ed6b2fadce1f9daa50eab82591a
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42596899"
---
# <a name="chaininterfacesiidcount-constant"></a>Constante ChainInterfaces::IidCount

O número total de IDs contidas nas interfaces especificadas pelos parâmetros de modelo de interface *I0* por meio *I9*.

## <a name="syntax"></a>Sintaxe

```cpp
static const unsigned long IidCount = Details::InterfaceTraits<I0>::IidCount + Details::InterfaceTraits<I1>::IidCount + Details::InterfaceTraits<I2>::IidCount + Details::InterfaceTraits<I3>::IidCount + Details::InterfaceTraits<I4>::IidCount + Details::InterfaceTraits<I5>::IidCount + Details::InterfaceTraits<I6>::IidCount + Details::InterfaceTraits<I7>::IidCount + Details::InterfaceTraits<I8>::IidCount + Details::InterfaceTraits<I9>::IidCount;
```

## <a name="return-value"></a>Valor de retorno

O número total de identificadores de interface.

## <a name="remarks"></a>Comentários

Parâmetros de modelo *I0* e *I1* são necessários e os parâmetros *I2* por meio de *I9* são opcionais. A contagem IID de cada interface normalmente é 1.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)