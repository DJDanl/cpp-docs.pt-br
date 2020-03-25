---
title: operator== Operador (Microsoft::WRL)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::operator==
ms.assetid: 94f383a5-17a9-40c7-9d9c-778acdc54b27
ms.openlocfilehash: f9a3ea9e33adc8a26f34324a8660c835f08b3007
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213657"
---
# <a name="operator-operator-microsoftwrl"></a>operator== Operador (Microsoft::WRL)

Operador de igualdade para objetos [ComPtr](comptr-class.md) e [ComPtrRef](comptrref-class.md) .

## <a name="syntax"></a>Sintaxe

```cpp
WRL_NOTHROW bool operator==(
   const ComPtr<T>& a,
   const ComPtr<U>& b
);
WRL_NOTHROW bool operator==(
   const ComPtr<T>& a,
   decltype(__nullptr)
);
WRL_NOTHROW bool operator==(
   decltype(__nullptr),
   const ComPtr<T>& a
);
WRL_NOTHROW bool operator==(
   const Details::ComPtrRef<ComPtr<T>>& a,
   const Details::ComPtrRef<ComPtr<U>>& b
);
WRL_NOTHROW bool operator==(
   const Details::ComPtrRef<ComPtr<T>>& a,
   decltype(__nullptr)
);
WRL_NOTHROW bool operator==(
   decltype(__nullptr),
   const Details::ComPtrRef<ComPtr<T>>& a
);
WRL_NOTHROW bool operator==(
   const Details::ComPtrRef<ComPtr<T>>& a,
   void* b
);
WRL_NOTHROW bool operator==(
   void* b,
   const Details::ComPtrRef<ComPtr<T>>& a
);
```

### <a name="parameters"></a>parâmetros

*a*<br/>
O objeto à esquerda.

*b*<br/>
O objeto correto.

## <a name="return-value"></a>Valor retornado

**true** se os objetos forem iguais; caso contrário, **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
