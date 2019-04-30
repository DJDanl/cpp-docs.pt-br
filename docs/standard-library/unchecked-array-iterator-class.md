---
title: Classe unchecked_array_iterator
ms.date: 11/04/2016
f1_keywords:
- stdext::unchecked_array_iterator
ms.assetid: 693b3b30-4e3a-465b-be06-409700bc50b1
ms.openlocfilehash: 9b3db474bedca50922334bd4dbd09c71d4e6e987
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399337"
---
# <a name="uncheckedarrayiterator-class"></a>Classe unchecked_array_iterator

A classe `unchecked_array_iterator` permite que você encapsule uma matriz ou um ponteiro em um iterador não verificado. Use essa classe como um wrapper (usando a função [make_unchecked_array_iterator](../standard-library/iterator-functions.md#make_unchecked_array_iterator)) para matrizes ou ponteiros brutos como uma maneira direcionada de gerenciar avisos de ponteiros não verificados, em vez de silenciar esses avisos globalmente. Se possível, prefira a versão verificada dessa classe, [checked_array_iterator](../standard-library/checked-array-iterator-class.md).

> [!NOTE]
> Essa classe é uma extensão da Microsoft da Biblioteca Padrão C++. O código implementado usando essa função não é portátil para ambientes de criação do C++ Standard que não oferecem suporte a essa extensão da Microsoft.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Iterator>
class unchecked_array_iterator;
```

## <a name="remarks"></a>Comentários

Essa classe é definida no namespace [stdext](../standard-library/stdext-namespace.md).

Esta é a versão não verificada da [classe checked_array_iterator](../standard-library/checked-array-iterator-class.md) e dá suporte a todos os mesmos membros e sobrecargas. Para obter mais informações sobre o recurso de iterador verificado com exemplos de código, consulte [Checked Iterators](../standard-library/checked-iterators.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[\<iterator>](../standard-library/iterator.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
