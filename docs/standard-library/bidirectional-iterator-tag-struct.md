---
title: Struct bidirectional_iterator_tag
ms.date: 11/04/2016
f1_keywords:
- xutility/std::bidirectional_iterator_tag
helpviewer_keywords:
- bidirectional_iterator_tag class
- bidirectional_iterator_tag struct
ms.assetid: 9ac06066-b8ae-44b6-bee4-b05855f6a31a
ms.openlocfilehash: c8296ddf30c0e2a3d34e69cbf079c0477e0e8b7a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62414068"
---
# <a name="bidirectionaliteratortag-struct"></a>Struct bidirectional_iterator_tag

Uma classe que fornece um tipo de retorno para `iterator_category` função que representa um iterador bidirecional.

## <a name="syntax"></a>Sintaxe

```cpp
struct bidirectional_iterator_tag    : public forward_iterator_tag {};
```

## <a name="remarks"></a>Comentários

As classes de marca de categoria são usadas como marcas de compilação para seleção de algoritmos. A função de modelo precisa encontrar a categoria mais específica de seu argumento iterador para que ela possa usar o algoritmo mais eficiente no tempo de compilação. Para cada iterador do tipo `Iterator`, `iterator_traits`< `Iterator`>:: **iterator_category** deve ser definido para ser a marcação de categoria mais específica possível que descreva o comportamento do iterador.

O tipo é o mesmo que **iterador** \< **Iter**>:: **iterator_category** quando `Iter` descreve um objeto que pode servir como um bidirecional iterador.

## <a name="example"></a>Exemplo

Consulte [random_access_iterator_tag](../standard-library/random-access-iterator-tag-struct.md) para obter um exemplo de como usar `bidirectional_iterator_tag`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Struct forward_iterator_tag](../standard-library/forward-iterator-tag-struct.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
