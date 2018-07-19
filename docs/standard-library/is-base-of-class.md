---
title: Classe is_base_of | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::is_base_of
dev_langs:
- C++
helpviewer_keywords:
- is_base_of class
- is_base_of
ms.assetid: 436f6213-1d4c-4ffc-a588-fc7c4887dd86
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 43f4aec5796db6a277b6bfb1edecdcd2e7f5c455
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38954611"
---
# <a name="isbaseof-class"></a>Classe is_base_of

Testa se um tipo é a base de outro.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Base, class Derived>
struct is_base_of;
```

### <a name="parameters"></a>Parâmetros

*Base* a classe base para testar.

*Derivado* o tipo derivado para testar.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Base* é uma classe base do tipo *derivada*, caso contrário, será falsa.

## <a name="example"></a>Exemplo

```cpp
#include <type_traits>
#include <iostream>

struct base
    {
    int val;
    };

struct derived
    : public base
    {
    };

int main()
    {
    std::cout << "is_base_of<base, base> == " << std::boolalpha
        << std::is_base_of<base, base>::value << std::endl;
    std::cout << "is_base_of<base, derived> == " << std::boolalpha
        << std::is_base_of<base, derived>::value << std::endl;
    std::cout << "is_base_of<derived, base> == " << std::boolalpha
        << std::is_base_of<derived, base>::value << std::endl;

    return (0);
    }
```

```Output
is_base_of<base, base> == true
is_base_of<base, derived> == true
is_base_of<derived, base> == false
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[Classe is_convertible](../standard-library/is-convertible-class.md)<br/>
