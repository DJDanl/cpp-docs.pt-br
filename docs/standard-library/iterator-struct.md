---
title: Struct iterator
ms.date: 11/04/2016
f1_keywords:
- xutility/std::iterator
helpviewer_keywords:
- iterator class
- iterator struct
ms.assetid: c74c8000-8b18-4829-9b71-6103c4229b74
ms.openlocfilehash: 1dd62a6141e690d3bd4dcad69aa107c126a0f386
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50631394"
---
# <a name="iterator-struct"></a>Struct iterator

Um struct vazio de base usado para garantir que uma classe de iterador definida pelo usuário funcione corretamente com `iterator_trait`s.

## <a name="syntax"></a>Sintaxe

```cpp
struct iterator {
   typedef Category iterator_category;
   typedef Type value_type;
   typedef Distance difference_type;
   typedef Distance distance_type;
   typedef Pointer pointer;
   typedef Reference reference;
   };
```

## <a name="remarks"></a>Comentários

O struct de modelo atua como um tipo base para todos os iteradores. Ele define os tipos de membro

- `iterator_category` (um sinônimo do parâmetro de modelo `Category`).

- `value_type` (um sinônimo do parâmetro de modelo `Type`).

- `difference_type` (um sinônimo do parâmetro de modelo `Distance`).

- `distance_type` (um sinônimo do parâmetro de modelo `Distance`)

- `pointer` (um sinônimo do parâmetro de modelo `Pointer`).

- `reference` (um sinônimo do parâmetro de modelo `Reference`).

Observe que `value_type` não deve ser um tipo constante mesmo que `pointer` aponte para um objeto de **const** `Type` e a referência designe um objeto do **const** `Type`.

## <a name="example"></a>Exemplo

Consulte [iterator_traits](../standard-library/iterator-traits-struct.md) para ver um exemplo de como declarar e usar os tipos na classe base do iterador.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<iterator>](../standard-library/iterator.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
