---
title: Struct input_iterator_tag
ms.date: 11/04/2016
f1_keywords:
- xutility/std::input_iterator_tag
helpviewer_keywords:
- input_iterator_tag class
- input_iterator_tag struct
ms.assetid: ad68a4c6-f315-4ce1-8b74-c1fc71bd1577
ms.openlocfilehash: 5478a8f9fa6013202a1ea8dd838eedb80b9c367e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50493919"
---
# <a name="inputiteratortag-struct"></a>Struct input_iterator_tag

Uma classe que fornece um tipo de retorno para `iterator_category` função que representa um iterador de entrada.

## <a name="syntax"></a>Sintaxe

struct input_iterator_tag {};

## <a name="remarks"></a>Comentários

As classes de marca de categoria são usadas como marcas de compilação para seleção de algoritmos. A função de modelo precisa encontrar a categoria mais específica do argumento iterador para que ela possa usar o algoritmo mais eficiente em tempo de compilação. Para cada iterador do tipo `Iterator`, `iterator_traits`< `Iterator`> **::iterator_category** deve ser definido para ser a marca de categoria mais específica que descreve o comportamento do iterador.

O tipo é o mesmo que **iterador** \< **Iter**> **:: iterator_category** quando `Iter` descreve um objeto que pode servir como um iterador de entrada.

## <a name="example"></a>Exemplo

Ver [iterator_traits](../standard-library/iterator-traits-struct.md) ou [random_access_iterator_tag](../standard-library/random-access-iterator-tag-struct.md) para obter um exemplo de como usar `iterator_tag`s.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
