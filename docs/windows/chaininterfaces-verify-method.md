---
title: 'Método chaininterfaces:: Verify | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::ChainInterfaces::Verify
dev_langs:
- C++
helpviewer_keywords:
- Verify method
ms.assetid: c591e130-8686-4130-ba69-1aaedc250038
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e6dbc595714cbecf2ad13db13051866e31e5ebcd
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42581052"
---
# <a name="chaininterfacesverify-method"></a>Método ChainInterfaces::Verify

Verifica se cada interface definido pelos parâmetros de modelo *I0* por meio *I9* herda `IUnknown` e/ou `IInspectable`e que *I0* herda de *I1* por meio *I9*.

## <a name="syntax"></a>Sintaxe

```cpp
WRL_NOTHROW __forceinline static void Verify();
```

## <a name="remarks"></a>Comentários

Se a operação de verificação falhar, uma **static_assert** emite uma mensagem de erro que descreve a falha.

Parâmetros de modelo *I0* e *I1* são necessários e os parâmetros *I2* por meio de *I9* são opcionais.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)