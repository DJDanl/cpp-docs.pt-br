---
title: Classe aligned_union | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::aligned_union
dev_langs:
- C++
helpviewer_keywords:
- aligned_union
ms.assetid: 9931a44d-3a67-4f29-a0f6-d47a7cf560ac
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4017fceab100689847ea99df80016aaba2fbd10f
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44107650"
---
# <a name="alignedunion-class"></a>Classe aligned_union

Fornece um tipo POD alinhado adequadamente e grande o suficiente para armazenar um tipo de união e o tamanho necessário.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Len, class... Types>
struct aligned_union;

template <std::size_t Len, class... Types>
using aligned_union_t = typename aligned_union<Len, Types...>::type;
```

### <a name="parameters"></a>Parâmetros

*Len*<br/>
O valor de alinhamento do maior tipo na união.

*Tipos*<br/>
Os tipos distintos na união subjacente.

## <a name="remarks"></a>Comentários

Use a classe de modelo para obter o alinhamento e o tamanho necessários para armazenar uma união no armazenamento não inicializado. O typedef do membro `type` nomeia um tipo POD adequado para o armazenamento de qualquer tipo listado na *tipos*; o tamanho mínimo é *Len*. O membro estático `alignment_value` do tipo `std::size_t` contém o alinhamento mais estrito exigido de todos os tipos listados na *tipos*.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar `aligned_union` para alocar um buffer de pilha alinhado para colocar uma união.

```cpp
// std__type_traits__aligned_union.cpp
#include <iostream>
#include <type_traits>

union U_type
{
    int i;
    float f;
    double d;
    U_type(float e) : f(e) {}
};

typedef std::aligned_union<16, int, float, double>::type aligned_U_type;

int main()
{
    // allocate memory for a U_type aligned on a 16-byte boundary
    aligned_U_type au;
    // do placement new in the aligned memory on the stack
    U_type* u = new (&au) U_type(1.0f);
    if (nullptr != u)
    {
        std::cout << "value of u->i is " << u->i << std::endl;
        // must clean up placement objects manually!
        u->~U_type();
    }
}
```

```Output
value of u->i is 1065353216
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[Classe alignment_of](../standard-library/alignment-of-class.md)<br/>
