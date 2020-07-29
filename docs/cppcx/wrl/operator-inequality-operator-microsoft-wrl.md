---
title: operator!= Operador (Microsoft::WRL)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::operator!=
ms.assetid: 785435da-87a6-4454-9bce-9d288a96dc26
ms.openlocfilehash: af7088348cd3f52b38f0277fb7d0a973a1ca0e4b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226887"
---
# <a name="operator-operator-microsoftwrl"></a>operator!= Operador (Microsoft::WRL)

Operador de desigualdade para objetos [ComPtr](comptr-class.md) e [ComPtrRef](comptrref-class.md) .

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

### <a name="parameters"></a>parâmetros

*um*<br/>
O objeto à esquerda.

*b*<br/>
O objeto correto.

## <a name="return-value"></a>Valor retornado

**`true`** Se os objetos não forem iguais; caso contrário, **`false`** .

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft:: WRL](microsoft-wrl-namespace.md)
