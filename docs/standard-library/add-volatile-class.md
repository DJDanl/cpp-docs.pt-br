---
title: Classe add_volatile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- type_traits/std::add_volatile
dev_langs:
- C++
helpviewer_keywords:
- add_volatile class
- add_volatile
ms.assetid: cde57277-d764-402d-841e-97611ebaab14
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d66f7c315fe406a7ac7cbcb3abe706ae702cdf13
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="addvolatile-class"></a>Classe add_volatile

Cria um tipo volátil do tipo especificado.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct add_volatile;

template <class T>
using add_volatile_t = typename add_volatile<T>::type;
```

### <a name="parameters"></a>Parâmetros

*T* digite para modificar.

## <a name="remarks"></a>Comentários

Uma instância de `add_volatile<T>` tem um typedef do membro `type` que será *T* se *T* for uma referência, uma função ou um tipo qualificado como volátil, caso contrário, será `volatile` *T*. O alias `add_volatile_t` é um atalho para acessar o typedef do membro `type`.

## <a name="example"></a>Exemplo

```cpp
#include <type_traits>
#include <iostream>

int main()
{
    std::add_volatile_t<int> *p = (volatile int *)0;

    p = p;  // to quiet "unused" warning
    std::cout << "add_volatile<int> == "
        << typeid(*p).name() << std::endl;

    return (0);
}
```

```Output
add_volatile<int> == int
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[Classe remove_volatile](../standard-library/remove-volatile-class.md)<br/>
