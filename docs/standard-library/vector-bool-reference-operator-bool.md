---
title: vector&lt;bool&gt;::reference::operator bool
ms.date: 11/04/2016
f1_keywords:
- operatorbool
- vector<bool>::reference::operatorbool
- bool
- std::vector<bool>::reference::operatorbool
helpviewer_keywords:
- BOOL operator
- reference::operator bool
ms.assetid: b0e57869-18cc-4296-9061-da502f30120d
ms.openlocfilehash: bb757fee9d6ec824a99557c409b1c4f02f48db5d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215381"
---
# <a name="vectorltboolgtreferenceoperator-bool"></a>vector&lt;bool&gt;::reference::operator bool

Fornece uma conversão implícita de `vector<bool>::reference` para **`bool`** .

## <a name="syntax"></a>Sintaxe

```cpp
operator bool() const;
```

## <a name="return-value"></a>Valor retornado

O valor booliano do elemento do objeto [de \<bool> vetor](../standard-library/vector-bool-class.md) .

## <a name="remarks"></a>Comentários

O objeto `vector<bool>` não pode ser modificado por esse operador.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<vector>

**Namespace:** std

## <a name="see-also"></a>Confira também

[\<bool>classe vector:: Reference](../standard-library/vector-bool-reference-class.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
