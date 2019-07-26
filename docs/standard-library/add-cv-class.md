---
title: Classe add_cv
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::add_cv
helpviewer_keywords:
- add_cv class
- add_cv
ms.assetid: a5572c78-a097-45d7-b476-ed4876889dea
ms.openlocfilehash: 0cc63558ea392976bd6a3c5a43735c592e4606b4
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456588"
---
# <a name="addcv-class"></a>Classe add_cv

Torna **const volatile** tipo do tipo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct add_cv;

template <class T>
using add_cv_t = typename add_cv<T>::type;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser modificado.

## <a name="remarks"></a>Comentários

Uma instância do tipo `add_cv<T>` modificado tem um  `type` typedef de membro equivalente a *T* modificado por [add_volatile](../standard-library/add-volatile-class.md) e [add_const](../standard-library/add-const-class.md), a menos que *T* já tenha os qualificadores CV, seja uma referência ou seja um funcionamento.

O tipo auxiliar `add_cv_t<T>` é um atalho para acessar o typedef `type` do membro `add_cv<T>`.

## <a name="example"></a>Exemplo

```cpp
// add_cv.cpp
// compile by using: cl /EHsc /W4 add_cv.cpp
#include <type_traits>
#include <iostream>

struct S {
    void f() {
        std::cout << "invoked non-cv-qualified S.f()" << std::endl;
    }
    void f() const {
        std::cout << "invoked const S.f()" << std::endl;
    }
    void f() volatile {
        std::cout << "invoked volatile S.f()" << std::endl;
    }
    void f() const volatile {
        std::cout << "invoked const volatile S.f()" << std::endl;
    }
};

template <class T>
void invoke() {
    T t;
    ((T *)&t)->f();
}

int main()
{
    invoke<S>();
    invoke<std::add_const<S>::type>();
    invoke<std::add_volatile<S>::type>();
    invoke<std::add_cv<S>::type>();
}
```

```Output
invoked non-cv-qualified S.f()
invoked const S.f()
invoked volatile S.f()
invoked const volatile S.f()
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Classe remove_const](../standard-library/remove-const-class.md)\
[Classe remove_volatile](../standard-library/remove-volatile-class.md)
