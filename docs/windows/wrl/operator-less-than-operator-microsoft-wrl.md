---
title: 'operador&lt; operador (Microsoft:: wrl)'
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::operator<
ms.assetid: bfae0e1c-1648-482b-99c2-3217d62aba46
ms.openlocfilehash: 8b9d9936eabb75b58eabde487db8d1eb42abc9dd
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335443"
---
# <a name="operatorlt-operator-microsoftwrl"></a>operador&lt; operador (Microsoft:: wrl)

Determina se o endereço de um objeto é menor que outro.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T, class U>
bool operator<(const ComPtr<T>& a, const ComPtr<U>& b) throw();
template<class T, class U>
bool operator<(const Details::ComPtrRef<ComPtr<T>>& a, const Details::ComPtrRef<ComPtr<U>>& b) throw();
```

### <a name="parameters"></a>Parâmetros

*a*<br/>
O objeto à esquerda.

*b*<br/>
O objeto à direita.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o endereço de *um* é menor que o endereço do *b*; caso contrário, **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)