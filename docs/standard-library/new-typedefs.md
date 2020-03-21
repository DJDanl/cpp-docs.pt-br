---
title: Typedefs &lt;new&gt;
ms.date: 11/04/2016
f1_keywords:
- new/std::new_handler
ms.assetid: aef01de1-06b5-4b6c-aebc-2c9f423d7e47
ms.openlocfilehash: 30bd84a1d69d3d8f24cd36450a18b23b92c3c2c6
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076435"
---
# <a name="ltnewgt-typedefs"></a>Typedefs &lt;new&gt;

## <a name="hardware_constructive_interference_size"></a><a name="hardware_constructive_interference_size"></a>hardware_constructive_interference_size

```cpp
inline constexpr size_t hardware_constructive_interference_size = implementation-defined;
```

### <a name="remarks"></a>Comentários

Esse número é o tamanho máximo recomendado de memória contígua ocupada por dois objetos acessados com a localidade temporal por threads simultâneos. Deve ser pelo menos `alignof(max_align_t)`.

### <a name="example"></a>Exemplo

```cpp
struct together {
    atomic<int> dog;
    int puppy;
};

struct kennel {
    // Other data members...
    alignas(sizeof(together)) together pack;
    // Other data members...
};

static_assert(sizeof(together) <= hardware_constructive_interference_size);
```

## <a name="hardware_destructive_interference_size"></a><a name="hardware_destructive_interference_size"></a>hardware_destructive_interference_size

```cpp
inline constexpr size_t hardware_destructive_interference_size = implementation-defined;
```

### <a name="remarks"></a>Comentários

Esse número é o deslocamento mínimo recomendado entre dois objetos acessados simultaneamente para evitar degradação de desempenho adicional devido à contenção introduzida pela implementação. Deve ser pelo menos `alignof(max_align_t)`.

### <a name="example"></a>Exemplo

```cpp
struct keep_apart {
    alignas(hardware_destructive_interference_size) atomic<int> cat;
    alignas(hardware_destructive_interference_size) atomic<int> dog;
};
```

## <a name="new_handler"></a><a name="new_handler"></a>new_handler

O tipo aponta para uma função adequada para uso como um manipulador new.

```cpp
typedef void (*new_handler)();
```

### <a name="remarks"></a>Comentários

Esse tipo de função de manipulador é chamado por **operador novo** ou `operator new[]` quando eles não podem atender a uma solicitação de armazenamento adicional.

### <a name="example"></a>Exemplo

Consulte [set_new_handler](../standard-library/new-functions.md#set_new_handler) para obter um exemplo usando `new_handler` como um valor retornado.
