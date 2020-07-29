---
title: '&lt;operador Operator (Microsoft:: WRL)'
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::operator<
ms.assetid: bfae0e1c-1648-482b-99c2-3217d62aba46
ms.openlocfilehash: b438f823814e21e2da43f698471d782c88626628
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226874"
---
# <a name="operatorlt-operator-microsoftwrl"></a>&lt;operador Operator (Microsoft:: WRL)

Determina se o endereço de um objeto é menor que o outro.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T, class U>
bool operator<(const ComPtr<T>& a, const ComPtr<U>& b) throw();
template<class T, class U>
bool operator<(const Details::ComPtrRef<ComPtr<T>>& a, const Details::ComPtrRef<ComPtr<U>>& b) throw();
```

### <a name="parameters"></a>parâmetros

*um*<br/>
O objeto à esquerda.

*b*<br/>
O objeto correto.

## <a name="return-value"></a>Valor retornado

**`true`** Se o endereço de *a* for menor que o endereço de *b*; caso contrário, **`false`** .

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft:: WRL](microsoft-wrl-namespace.md)
