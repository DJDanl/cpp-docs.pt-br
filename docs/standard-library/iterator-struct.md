---
title: Struct iterator
ms.date: 11/04/2016
f1_keywords:
- xutility/std::iterator
helpviewer_keywords:
- iterator class
- iterator struct
ms.assetid: c74c8000-8b18-4829-9b71-6103c4229b74
ms.openlocfilehash: b45cdb5c3d4608296cca34ad6a0be6e25b588d28
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222297"
---
# <a name="iterator-struct"></a>Struct iterator

Uma estrutura base vazia usada para garantir que uma classe de iterador definida pelo usuário funcione corretamente com `iterator_trait` s.

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

Observe que `value_type` não deve ser um tipo constante, mesmo se os `pointer` pontos em um objeto de **`const`** `Type` e referência designarem um objeto de **`const`** `Type` .

## <a name="example"></a>Exemplo

Consulte [iterator_traits](../standard-library/iterator-traits-struct.md) para ver um exemplo de como declarar e usar os tipos na classe base do iterador.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<iterator>

**Namespace:** std

## <a name="see-also"></a>Confira também

[\<iterator>](../standard-library/iterator.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
