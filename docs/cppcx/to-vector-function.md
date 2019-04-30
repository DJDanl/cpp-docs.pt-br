---
title: Função to_vector
ms.date: 12/30/2016
f1_keywords:
- collection/Windows::Foundation::Collections::to_vector
helpviewer_keywords:
- to_vector Function
ms.assetid: 9cdd5123-7243-4def-a1d3-162e0bf6219e
ms.openlocfilehash: 4fa4e9c620519cc6bb2f96d346ded88b6cc826ae
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62404618"
---
# <a name="tovector-function"></a>Função to_vector

Retorna um `std::vector` cujo valor é igual ao da coleção subjacente ao parâmetro IVector ou IVectorView especificado.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
inline ::std::vector<T> to_vector(IVector<T>^ v);

template <typename T>
inline ::std::vector<T> to_vector(IVectorView<T>^ v);
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O parâmetro de tipo de modelo.

*v*<br/>
Uma interface de IVector ou IVectorView que fornece acesso a um objeto Vector ou VectorView subjacente.

### <a name="return-value"></a>Valor de retorno

### <a name="requirements"></a>Requisitos

**Cabeçalho:** collection.h

**Namespace:** Windows::Foundation::Collections

## <a name="see-also"></a>Consulte também

[Namespace Windows::Foundation::Collections](../cppcx/windows-foundation-collections-namespace-c-cx.md)
