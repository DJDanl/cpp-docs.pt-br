---
title: Classe add_rvalue_reference
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::add_rvalue_reference
helpviewer_keywords:
- add_rvalue_reference Class
ms.assetid: 76b0cb7c-1031-45d0-b409-f03ab0297580
ms.openlocfilehash: 64694f2428c1dd536df4d242a17f3f011cfb290c
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456546"
---
# <a name="addrvaluereference-class"></a>Classe add_rvalue_reference

Criará um tipo de referência de rvalue do parâmetro de modelo, se for um tipo de objeto ou de função. Caso contrário, devido à semântica de recolhimento de referência, o tipo será igual ao do parâmetro de modelo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct add_rvalue_reference;

template <class T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser modificado.

## <a name="remarks"></a>Comentários

A `add_rvalue_reference` classe tem um membro chamado `type`, que é um alias para o tipo de uma referência rvalue para o parâmetro de modelo *T*. A semântica de recolhimento de referência significa que, para tipos de não-objeto e não de função *t*, `T&&` é um *t*. Por exemplo, quando *T* é um tipo de referência lvalue `add_rvalue_reference<T>::type` , é o tipo de referência lvalue, não uma referência rvalue.

Para sua conveniência \<, type_traits > define um modelo auxiliar `add_rvalue_reference_t`,, cujo alias é `type` o membro `add_rvalue_reference`de.

## <a name="example"></a>Exemplo

Este exemplo de código usa static_assert para mostrar como os tipos de referência de rvalue são criados usando `add_rvalue_reference` e `add_rvalue_reference_t`, e como o resultado de `add_rvalue_reference` em um tipo de referência de lvalue não é uma referência de rvalue, mas recolhe ao tipo de referência de lvalue.

```cpp
// ex_add_rvalue_reference.cpp
// Build by using: cl /EHsc /W4 ex_add_rvalue_reference.cpp
#include <type_traits>
#include <iostream>
#include <string>

using namespace std;
int main()
{
    static_assert(is_same<add_rvalue_reference<string>::type, string&&>::value,
        "Expected add_rvalue_reference_t<string> to be string&&");
    static_assert(is_same<add_rvalue_reference_t<string*>, string*&&>::value,
        "Expected add_rvalue_reference_t<string*> to be string*&&");
    static_assert(is_same<add_rvalue_reference<string&>::type, string&>::value,
        "Expected add_rvalue_reference_t<string&> to be string&");
    static_assert(is_same<add_rvalue_reference_t<string&&>, string&&>::value,
        "Expected add_rvalue_reference_t<string&&> to be string&&");
    cout << "All static_assert tests of add_rvalue_reference passed." << endl;
    return 0;
}

/*Output:
All static_assert tests of add_rvalue_reference passed.
*/
```

## <a name="requirements"></a>Requisitos

Cabeçalho: \<type_traits >

Namespace: std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Classe add_lvalue_reference](../standard-library/add-lvalue-reference-class.md)\
[Classe is_rvalue_reference](../standard-library/is-rvalue-reference-class.md)
