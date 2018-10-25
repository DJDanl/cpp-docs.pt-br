---
title: 'operador! = operador (Microsoft:: wrl) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::operator!=
dev_langs:
- C++
ms.assetid: 785435da-87a6-4454-9bce-9d288a96dc26
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 946577b3309924c49c9040c5758a4c3ece0a6bfa
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50065909"
---
# <a name="operator-operator-microsoftwrl"></a>operator!= Operador (Microsoft::WRL)

Operador de desigualdade para [ComPtr](../windows/comptr-class.md) e [ComPtrRef](../windows/comptrref-class.md) objetos.

## <a name="syntax"></a>Sintaxe

```cpp
WRL_NOTHROW bool operator!=(
   const ComPtr<T>& a,
   const ComPtr<U>& b
);
WRL_NOTHROW bool operator!=(
   const ComPtr<T>& a,
   decltype(__nullptr)
);
WRL_NOTHROW bool operator!=(
   decltype(__nullptr),
   const ComPtr<T>& a
);
WRL_NOTHROW bool operator!=(
   const Details::ComPtrRef<ComPtr<T>>& a,
   const Details::ComPtrRef<ComPtr<U>>& b
);
WRL_NOTHROW bool operator!=(
   const Details::ComPtrRef<ComPtr<T>>& a,
   decltype(__nullptr)
);
WRL_NOTHROW bool operator!=(
   decltype(__nullptr),
   const Details::ComPtrRef<ComPtr<T>>& a
);
WRL_NOTHROW bool operator!=(
   const Details::ComPtrRef<ComPtr<T>>& a,
   void* b
);
WRL_NOTHROW bool operator!=(
   void* b,
   const Details::ComPtrRef<ComPtr<T>>& a
);
```

### <a name="parameters"></a>Parâmetros

*a*<br/>
O objeto à esquerda.

*b*<br/>
O objeto à direita.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se os objetos não forem iguais; caso contrário, **falso**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)