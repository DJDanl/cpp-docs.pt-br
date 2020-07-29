---
title: Classe is_pod
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_pod
helpviewer_keywords:
- is_pod class
- is_pod
ms.assetid: d73ebdee-746b-4082-9fa4-2db71432eb0e
ms.openlocfilehash: 1398da92890072d8aa8a6f07c61920fe3bee1776
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212235"
---
# <a name="is_pod-class"></a>Classe is_pod

Testa se o tipo é um POD.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_pod;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

`is_pod<T>::value`é **`true`** se o tipo *T* é um pod (dados antigos simples). Caso contrário, é **`false`** .

Tipos aritméticos, tipos de enumeração, tipos de ponteiro e tipos de ponteiro para membro são POD.

Uma versão qualificada para CV de um tipo POD também é um tipo POD.

Uma matriz de POD também é POD.

Um struct ou união, de que todos os membros de dados não estáticos forem POD, também será POD se não tiver:

- nenhum construtor declarado pelo usuário.

- nenhum membro de dados não estáticos particular ou protegido.

- Nenhuma classe base.

- nenhuma função virtual.

- nenhum membro de dados não estáticos do tipo de referência.

- nenhum operador de atribuição de cópia definido pelo usuário.

- nenhum destruidor definido pelo usuário.

Portanto, é possível compilar recursivamente structs e matrizes POD que contêm structs e matrizes POD.

## <a name="example"></a>Exemplo

```cpp
// std__type_traits__is_pod.cpp
// compile with: /EHsc
#include <type_traits>
#include <iostream>

struct trivial {
    int val;
};

struct throws {
    throws() {}  // User-declared ctor, so not POD

    int val;
};

int main() {
    std::cout << "is_pod<trivial> == " << std::boolalpha
        << std::is_pod<trivial>::value << std::endl;
    std::cout << "is_pod<int> == " << std::boolalpha
        << std::is_pod<int>::value << std::endl;
    std::cout << "is_pod<throws> == " << std::boolalpha
        << std::is_pod<throws>::value << std::endl;

    return (0);
}
```

```Output
is_pod<trivial> == true
is_pod<int> == true
is_pod<throws> == false
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)
