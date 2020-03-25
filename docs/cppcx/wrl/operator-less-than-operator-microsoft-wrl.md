---
title: 'operador operador&lt; (Microsoft:: WRL)'
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::operator<
ms.assetid: bfae0e1c-1648-482b-99c2-3217d62aba46
ms.openlocfilehash: 04f5598667f7e0e036f0a55cd3f9cc52b5356299
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213636"
---
# <a name="operatorlt-operator-microsoftwrl"></a>operador operador&lt; (Microsoft:: WRL)

Determina se o endereço de um objeto é menor que o outro.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T, class U>
bool operator<(const ComPtr<T>& a, const ComPtr<U>& b) throw();
template<class T, class U>
bool operator<(const Details::ComPtrRef<ComPtr<T>>& a, const Details::ComPtrRef<ComPtr<U>>& b) throw();
```

### <a name="parameters"></a>parâmetros

*a*<br/>
O objeto à esquerda.

*b*<br/>
O objeto correto.

## <a name="return-value"></a>Valor retornado

**true** se o endereço de *a* for menor que o endereço de *b*; caso contrário, **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
