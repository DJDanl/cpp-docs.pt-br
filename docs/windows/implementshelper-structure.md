---
title: Estrutura ImplementsHelper | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::ImplementsHelper
dev_langs:
- C++
helpviewer_keywords:
- ImplementsHelper structure
ms.assetid: b857ba80-81bd-4e53-92b6-210991954243
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4ff40e03bf464d4c6f434b491c8b48d2b797d72b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46440519"
---
# <a name="implementshelper-structure"></a>Estrutura ImplementsHelper

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename RuntimeClassFlagsT,
   typename ILst,
   bool IsDelegateToClass
>
friend struct Details::ImplementsHelper;
```

### <a name="parameters"></a>Parâmetros

*RuntimeClassFlagsT*<br/>
Um campo de sinalizadores que especifica um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) enumeradores.

*ILst*<br/>
Uma lista de IDs de interface.

*IsDelegateToClass*<br/>
Especificar **verdadeira** se a instância atual do `Implements` é uma classe base da primeira ID de interface no *ILst*; caso contrário, **false**.

## <a name="remarks"></a>Comentários

Ajuda a implementar o [implementa](../windows/implements-structure.md) estrutura.

Esse modelo percorre uma lista de interfaces e os adiciona como classes base e como as informações necessárias para habilitar `QueryInterface`.

## <a name="members"></a>Membros

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ImplementsHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)