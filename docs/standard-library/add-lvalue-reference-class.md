---
title: Classe add_lvalue_reference
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::add_lvalue_reference
helpviewer_keywords:
- add_lvalue_reference
ms.assetid: 9933afc2-ad0d-465d-98fe-7d547fa3efe2
ms.openlocfilehash: 6317b6665adb7f3a06da564fcf049d0b64eb42e8
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456573"
---
# <a name="addlvaluereference-class"></a>Classe add_lvalue_reference

Cria referência para tipo do tipo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct add_lvalue_reference;

template <class T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser modificado.

## <a name="remarks"></a>Comentários

Uma instância do modificador de tipo contém um tipo modificado que é *t* se *t* for uma referência lvalue, caso `T&`contrário.

## <a name="example"></a>Exemplo

```cpp
#include <type_traits>
#include <iostream>

using namespace std;
int main()
{
    int val = 0;
    add_lvalue_reference_t<int> p = (int&)val;
    p = p;  // to quiet "unused" warning
    cout << "add_lvalue_reference_t<int> == "
        << typeid(p).name() << endl;

    return (0);
}
```

```Output
add_lvalue_reference_t<int> == int
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Classe remove_reference](../standard-library/remove-reference-class.md)
