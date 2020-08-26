---
title: Classe reference_wrapper
ms.date: 11/04/2016
f1_keywords:
- functional/std::reference_wrapper
- type_traits/std::reference_wrapper
- xrefwrap/std::reference_wrapper
- type_traits/std::reference_wrapper::get
- type_traits/std::reference_wrapper::operator()
- functional/std::reference_wrapper::result_type
- functional/std::reference_wrapper::type
- functional/std::reference_wrapper::get
- functional/std::reference_wrapper::operator()
helpviewer_keywords:
- std::reference_wrapper [C++]
- std::reference_wrapper [C++]
- std::reference_wrapper [C++], result_type
- std::reference_wrapper [C++], type
- std::reference_wrapper [C++], get
ms.assetid: 90b8ed62-e6f1-44ed-acc7-9619bd58865a
ms.openlocfilehash: 623e1480bdec85120e504c8dc71b28d017c8872a
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845062"
---
# <a name="reference_wrapper-class"></a>Classe reference_wrapper

Encapsula uma referência.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
class reference_wrapper
{
    typedef Ty type;

    reference_wrapper(Ty&) noexcept;
    operator Ty&() const noexcept;
    Ty& get() const noexcept;

    template <class... Types>
    auto operator()(Types&&... args) const ->
        decltype(std::invoke(get(), std::forward<Types>(args)...));
};
```

## <a name="remarks"></a>Comentários

Um `reference_wrapper<Ty>` é uma cópia construível e copia um wrapper atribuível em uma referência a um objeto ou uma função de tipo `Ty`, além de conter um ponteiro que aponta para um objeto desse tipo. Um `reference_wrapper` pode ser usado para armazenar referências em contêineres padrão e para passar objetos por referência a `std::bind`.

O tipo `Ty` deve ser um tipo de objeto ou um tipo de função ou uma falha de declaração estática no tempo de compilação.

As funções auxiliares [std::ref](functional-functions.md#ref) e [std::cref](functional-functions.md#cref) podem ser usadas para criar objetos `reference_wrapper`.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|-|-|
|[reference_wrapper](#reference_wrapper)|Constrói um `reference_wrapper`.|

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|-|-|
|[result_type](#result_type)|O tipo de resultado fraco da referência encapsulada.|
|[tipo](#type)|O tipo da referência encapsulada.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[get](#get)|Obtém a referência encapsulada.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador Ty&amp;](#op_ty_amp)|Obtém um ponteiro para a referência encapsulada.|
|[operador ()](#op_call)|Chama a referência encapsulada.|

## <a name="get"></a><a name="get"></a> Obter

Obtém a referência encapsulada.

```cpp
Ty& get() const noexcept;
```

### <a name="remarks"></a>Comentários

A função membro retorna a referência encapsulada.

### <a name="example"></a>Exemplo

```cpp
// std__functional__reference_wrapper_get.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int main() {
    int i = 1;
    std::reference_wrapper<int> rwi(i);

    std::cout << "i = " << i << std::endl;
    std::cout << "rwi = " << rwi << std::endl;
    rwi.get() = -1;
    std::cout << "i = " << i << std::endl;

    return (0);
}
```

```Output
i = 1
rwi = 1
i = -1
```

## <a name="operator-tyamp"></a><a name="op_ty_amp"></a> operador Ty&amp;

Obtém a referência encapsulada.

```cpp
operator Ty&() const noexcept;
```

### <a name="remarks"></a>Comentários

O operador de membro retorna `*ptr`.

### <a name="example"></a>Exemplo

```cpp
// std__functional__reference_wrapper_operator_cast.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int main() {
    int i = 1;
    std::reference_wrapper<int> rwi(i);

    std::cout << "i = " << i << std::endl;
    std::cout << "(int)rwi = " << (int)rwi << std::endl;

    return (0);
}
```

```Output
i = 1
(int)rwi = 1
```

## <a name="operator"></a><a name="op_call"></a> operador ()

Chama a referência encapsulada.

```cpp
template <class... Types>
auto operator()(Types&&... args);
```

### <a name="parameters"></a>parâmetros

*Digita*\
Os tipos da lista de argumentos.

*argumento*\
A lista de argumentos.

### <a name="remarks"></a>Comentários

O membro de modelo `operator()` retorna `std::invoke(get(), std::forward<Types>(args)...)`.

### <a name="example"></a>Exemplo

```cpp
// std__functional__reference_wrapper_operator_call.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val) {
    return (-val);
}

int main() {
    std::reference_wrapper<int (int)> rwi(neg);

    std::cout << "rwi(3) = " << rwi(3) << std::endl;

    return (0);
}
```

```Output
rwi(3) = -3
```

## <a name="reference_wrapper"></a><a name="reference_wrapper"></a> reference_wrapper

Constrói um `reference_wrapper`.

```cpp
reference_wrapper(Ty& val) noexcept;
```

### <a name="parameters"></a>parâmetros

*Ty*\
O tipo a ser encapsulado.

*Val*\
O valor a ser encapsulado.

### <a name="remarks"></a>Comentários

O construtor define o valor armazenado `ptr` para `&val`.

### <a name="example"></a>Exemplo

```cpp
// std__functional__reference_wrapper_reference_wrapper.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val) {
    return (-val);
}

int main() {
    int i = 1;
    std::reference_wrapper<int> rwi(i);

    std::cout << "i = " << i << std::endl;
    std::cout << "rwi = " << rwi << std::endl;
    rwi.get() = -1;
    std::cout << "i = " << i << std::endl;

    return (0);
}
```

```Output
i = 1
rwi = 1
i = -1
```

## <a name="result_type"></a><a name="result_type"></a> result_type

O tipo de resultado fraco da referência encapsulada.

```cpp
typedef R result_type;
```

### <a name="remarks"></a>Comentários

O typedef `result_type` é um sinônimo do tipo de resultado fraco de uma função encapsulada. Este typedef só é significativo para tipos de função.

### <a name="example"></a>Exemplo

```cpp
// std__functional__reference_wrapper_result_type.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val) {
    return (-val);
}

int main() {
    typedef std::reference_wrapper<int (int)> Mywrapper;
    Mywrapper rwi(neg);
    Mywrapper::result_type val = rwi(3);

    std::cout << "val = " << val << std::endl;

    return (0);
}
```

```Output
val = -3
```

## <a name="type"></a>Tipo<a name="type"></a>

O tipo da referência encapsulada.

```cpp
typedef Ty type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo do argumento de modelo `Ty`.

### <a name="example"></a>Exemplo

```cpp
// std__functional__reference_wrapper_type.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

int neg(int val) {
    return (-val);
}

int main() {
    int i = 1;
    typedef std::reference_wrapper<int> Mywrapper;
    Mywrapper rwi(i);
    Mywrapper::type val = rwi.get();

    std::cout << "i = " << i << std::endl;
    std::cout << "rwi = " << val << std::endl;

    return (0);
}
```

```Output
i = 1
rwi = 1
```
