---
title: 'Comptr:: Operator! = operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::operator!=
dev_langs:
- C++
ms.assetid: 63647240-dec7-4eb9-9272-96c07d01493c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ce6e3357582abe94fdc538932e49e773c37f116b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46384683"
---
# <a name="comptroperator-operator"></a>Operador ComPtr::operator!=

Indica se dois **ComPtr** objetos não forem iguais.

## <a name="syntax"></a>Sintaxe

```cpp
bool operator!=(
   const ComPtr<T>& a,
   const ComPtr<U>& b
);

bool operator!=(
   const ComPtr<T>& a,
   decltype(__nullptr)  
);

bool operator!=(
   decltype(__nullptr),
   const ComPtr<T>& a
);
```

### <a name="parameters"></a>Parâmetros

*a*<br/>
Uma referência a um **ComPtr** objeto.

*b*<br/>
Uma referência a outro **ComPtr** objeto.

## <a name="return-value"></a>Valor de retorno

A primeira produz do operador **verdadeira** se objeto *um* não é igual ao objeto *b*; caso contrário, **false**.

Os operadores de segundo e terceiro yield **verdadeira** se objeto *um* não é igual a **nullptr**; caso contrário, **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)<br/>
[Classe ComPtr](../windows/comptr-class.md)