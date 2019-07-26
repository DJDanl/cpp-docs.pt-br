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
ms.openlocfilehash: ca2d21a7706248cd84ca3591eb717e4081972f9c
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68452115"
---
# <a name="vectorltboolgtreferenceoperator-bool"></a>vector&lt;bool&gt;::reference::operator bool

Fornece uma conversão implícita de `vector<bool>::reference` para **bool**.

## <a name="syntax"></a>Sintaxe

```cpp
operator bool() const;
```

## <a name="return-value"></a>Valor de retorno

O valor booliano do elemento do objeto [vector\<bool>](../standard-library/vector-bool-class.md).

## <a name="remarks"></a>Comentários

O objeto `vector<bool>` não pode ser modificado por esse operador.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<vector>

**Namespace:** std

## <a name="see-also"></a>Consulte também

Classe [vector\<bool>::reference](../standard-library/vector-bool-reference-class.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
