---
title: Classe aligned_storage
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::aligned_storage
helpviewer_keywords:
- aligned_storage class
- aligned_storage
ms.assetid: f255e345-1f05-4d07-81e4-017f420839fb
ms.openlocfilehash: 8a4e907faa6175b9e03f5367d09501aaea388bce
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456473"
---
# <a name="alignedstorage-class"></a>Classe aligned_storage

Cria tipo alinhado adequadamente.

## <a name="syntax"></a>Sintaxe

```cpp
template <std::size_t Len, std::size_t Align>
struct aligned_storage;

template <std::size_t Len, std::size_t Align = alignment_of<max_align_t>::value>
using aligned_storage_t = typename aligned_storage<Len, Align>::type;
```

### <a name="parameters"></a>Parâmetros

*Len*\
O tamanho do objeto.

*Alinha*\
O alinhamento do objeto.

## <a name="remarks"></a>Comentários

O typedef `type` do membro do modelo é um sinônimo para um tipo de Pod com *alinhamento e* *Len*de tamanho. *Align* deve ser igual a `alignment_of<T>::value` para algum tipo `T`ou para o alinhamento padrão.

## <a name="example"></a>Exemplo

```cpp
#include <type_traits>
#include <iostream>

typedef std::aligned_storage<sizeof (int),
    std::alignment_of<double>::value>::type New_type;
int main()
    {
    std::cout << "alignment_of<int> == "
        << std::alignment_of<int>::value << std::endl;
    std::cout << "aligned to double == "
        << std::alignment_of<New_type>::value << std::endl;

    return (0);
    }
```

```Output
alignment_of<int> == 4
aligned to double == 8
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Classe alignment_of](../standard-library/alignment-of-class.md)
