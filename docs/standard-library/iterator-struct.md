---
title: Struct iterator
ms.date: 11/04/2016
f1_keywords:
- xutility/std::iterator
helpviewer_keywords:
- iterator class
- iterator struct
ms.assetid: c74c8000-8b18-4829-9b71-6103c4229b74
ms.openlocfilehash: 64c9be76cb92d818e40714dd141ded3a8cc17c8a
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68455614"
---
# <a name="iterator-struct"></a>Struct iterator

Uma estrutura base vazia usada para garantir que uma classe de iterador definida pelo usuário funcione `iterator_trait`corretamente com s.

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

Observe que `value_type` não deve ser um tipo constante, mesmo `pointer` se os pontos em um objeto de **const** `Type` e referência designarem um objeto de **const** `Type`.

## <a name="example"></a>Exemplo

Consulte [iterator_traits](../standard-library/iterator-traits-struct.md) para ver um exemplo de como declarar e usar os tipos na classe base do iterador.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<iterator>](../standard-library/iterator.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
