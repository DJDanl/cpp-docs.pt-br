---
title: operator&gt;=
ms.date: 11/04/2016
f1_keywords:
- operator>=
- std::>=
- std.operator>=
- '>='
- std.>=
- std::operator>=
helpviewer_keywords:
- '>= operator, comparing specific objects'
- operator >=
- operator>=
ms.assetid: 14fbebf5-8b75-4afa-a51b-3112d31c07cf
ms.openlocfilehash: 9994456a1345276af426bddd883fa7c53d7b93d0
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220286"
---
# <a name="operatorgt"></a>operator&gt;=

> [!NOTE]
> Este tópico é no Microsoft C++ como um exemplo não funcional de contêineres usados na documentação do C++ biblioteca padrão. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

Sobrecarregue **operator>=** para comparar dois objetos da classe de modelo [Container](../standard-library/sample-container-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
bool operator>=(
    const Container <Ty>& left,
    const Container <Ty>& right);
```

## <a name="return-value"></a>Valor de retorno

Retorna `!(left < right)`.

## <a name="see-also"></a>Consulte também

[\<sample container>](../standard-library/sample-container.md)<br/>
