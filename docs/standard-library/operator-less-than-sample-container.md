---
title: operator&lt; (&lt;sample container&gt;)
ms.date: 11/04/2016
f1_keywords:
- std::operator<
- operator<
- std.<
- <
- std.operator<
- std::<
helpviewer_keywords:
- < operator, comparing specific objects
- operator<, valarrays
- < operator
- operator <, valarrays
ms.assetid: 31027dd6-53be-428b-b950-1dcb25393597
ms.openlocfilehash: fc2a14d882b5ccfbfdaae543c76ca673f9018a59
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72687331"
---
# <a name="operatorlt-ltsample-containergt"></a>operator&lt; (&lt;sample container&gt;)

> [!NOTE]
> Este tópico está na documentação da C++ Microsoft como um exemplo não funcional de contêineres usados na biblioteca C++ padrão. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

O operador de sobrecargas **<** para comparar dois objetos do [contêiner](../standard-library/sample-container-class.md)de modelo de classe.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
bool operator<(
    const Container <Ty>& left,
    const Container <Ty>& right);
```

## <a name="return-value"></a>Valor retornado

Retorna `lexicographical_compare(left.begin, left.end, right.begin, right.end)`.

## <a name="see-also"></a>Consulte também

[\<sample container>](../standard-library/sample-container.md)\
[iniciar](../standard-library/container-class-begin.md) \
[end](../standard-library/container-class-end.md)