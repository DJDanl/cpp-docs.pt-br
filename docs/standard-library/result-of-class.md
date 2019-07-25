---
title: Classe result_of
ms.date: 02/21/2019
f1_keywords:
- type_traits/std::result_of
- type_traits/std::result_of_t
- type_traits/std::result_of::type
helpviewer_keywords:
- std::result_of
- std::result_of_t
- std::result_of::type
ms.assetid: 5374a096-4b4a-4712-aa97-6852c5cdd6be
ms.openlocfilehash: 5a3265cfe4b2629bf02925ea6e3eeb0c4acb1e0e
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68451211"
---
# <a name="resultof-class"></a>Classe result_of

Determina o tipo de retorno do tipo callable que usa os tipos de argumento especificados. Adicionado em C++ 14, preterido em C++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template<class>
struct result_of; // Causes a static assert

template <class Fn, class... ArgTypes>
struct result_of<Fn(ArgTypes...)>;

// Helper type
template<class T>
   using result_of_t = typename result_of<T>::type;
```

### <a name="parameters"></a>Parâmetros

*FN*\
O tipo callable para consulta.

*ArgTypes*\
Os tipos de lista de argumentos para o tipo callable para consulta.

## <a name="remarks"></a>Comentários

Use este modelo para determinar no momento da compilação o tipo de `Fn`resultado`ArgTypes`de (), em que *FN* é um tipo callable, referência a função ou referência a um tipo que possa ser chamado, invocado usando uma lista de argumentos dos tipos em *ArgTypes*. O membro `type` da classe de modelo nomeia o tipo de resultado de `decltype(std::invoke(declval<Fn>(), declval<ArgTypes>()...))` se a expressão não avaliada `std::invoke(declval<Fn>(), declval<ArgTypes>()...)` está bem formada. Caso contrário, a classe de modelo não terá nenhum membro `type`. O tipo *FN* e todos os tipos no pacote de parâmetros *ArgTypes* devem ser tipos completos, **void**ou matrizes de limite desconhecido. Preterido em favor do [invoke_result](invoke-result-class.md) em c++ 17.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[classe invoke_result](invoke-result-class.md)
