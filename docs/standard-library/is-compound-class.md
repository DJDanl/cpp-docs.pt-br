---
title: Classe is_compound | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- type_traits/std::is_compound
dev_langs:
- C++
helpviewer_keywords:
- is_compound class
- is_compound
ms.assetid: bdad1167-cf3f-4f37-8321-62a5df159ead
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 54bc403b363a2ff5ff55a3555411952018940119
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="iscompound-class"></a>Classe is_compound

Testa se o tipo especificado não é fundamental.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_compound;
```

### <a name="parameters"></a>Parâmetros

`Ty` O tipo de consulta.

## <a name="remarks"></a>Comentários

Contém uma instância do predicado de tipo `false` se o tipo de `Ty` é um tipo fundamental (ou seja, se [is_fundamental](../standard-library/is-fundamental-class.md)\<Ty > contém `true`); caso contrário, ele contém `true`. Portanto, o predicado será `true` se `Ty` for um tipo de matriz, um tipo de função, um ponteiro para `void` ou um objeto ou uma função, uma referência, uma classe, uma união, uma enumeração ou um ponteiro para um membro de classe não estática ou uma forma *qualificada por CV* de um deles.

## <a name="example"></a>Exemplo

```cpp
// std__type_traits__is_compound.cpp
// compile with: /EHsc
#include <type_traits>
#include <iostream>

struct trivial
    {
    int val;
    };

int main()
    {
    std::cout << "is_compound<trivial> == " << std::boolalpha
        << std::is_compound<trivial>::value << std::endl;
    std::cout << "is_compound<int[]> == " << std::boolalpha
        << std::is_compound<int[]>::value << std::endl;
    std::cout << "is_compound<int()> == " << std::boolalpha
        << std::is_compound<int()>::value << std::endl;
    std::cout << "is_compound<int&> == " << std::boolalpha
        << std::is_compound<int&>::value << std::endl;
    std::cout << "is_compound<void *> == " << std::boolalpha
        << std::is_compound<void *>::value << std::endl;
    std::cout << "is_compound<int> == " << std::boolalpha
        << std::is_compound<int>::value << std::endl;

    return (0);
    }

```

```Output
is_compound<trivial> == true
is_compound<int[]> == true
is_compound<int()> == true
is_compound<int&> == true
is_compound<void *> == true
is_compound<int> == false
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[Classe is_class](../standard-library/is-class-class.md)<br/>
