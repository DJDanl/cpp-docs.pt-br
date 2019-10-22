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
ms.openlocfilehash: ab575ac31936e7003f19fc2ceb3c5b1727d0728c
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688993"
---
# <a name="result_of-class"></a>Classe result_of

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

*Fn* \
O tipo callable para consulta.

@No__t_1 *ArgTypes*
Os tipos de lista de argumentos para o tipo callable para consulta.

## <a name="remarks"></a>Comentários

Use este modelo para determinar no momento da compilação o tipo de resultado de `Fn` (`ArgTypes`), em que *FN* é um tipo callable, referência a função ou referência a um tipo que possa ser chamado, invocado usando uma lista de argumentos dos tipos em *ArgTypes*. O `type` membro do modelo de classe nomeia o tipo de resultado de `decltype(std::invoke(declval<Fn>(), declval<ArgTypes>()...))` se a expressão não avaliada `std::invoke(declval<Fn>(), declval<ArgTypes>()...)` estiver bem formada. Caso contrário, o modelo de classe não terá nenhum membro `type`. O tipo *FN* e todos os tipos no pacote de parâmetros *ArgTypes* devem ser tipos completos, **void**ou matrizes de limite desconhecido. Preterido em favor do [invoke_result](invoke-result-class.md) em c++ 17.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[classe invoke_result](invoke-result-class.md)
