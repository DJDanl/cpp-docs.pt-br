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
ms.openlocfilehash: 7fa95b3037538ccbbf27fa5b9749dc21f72670cd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410909"
---
# <a name="vectorltboolgtreferenceoperator-bool"></a>vector&lt;bool&gt;::reference::operator bool

Fornece uma conversão implícita da `vector<bool>::reference` à **bool**.

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

[vetor\<bool >:: classe de referência](../standard-library/vector-bool-reference-class.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
