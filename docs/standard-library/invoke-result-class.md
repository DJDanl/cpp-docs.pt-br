---
title: Classe invoke_result
ms.date: 02/21/2019
f1_keywords:
- type_traits/std::invoke_result
- type_traits/std::invoke_result_t
- type_traits/std::invoke_result::type
helpviewer_keywords:
- std::invoke_result
- std::invoke_result_t
- std::invoke_result::type
ms.openlocfilehash: a5f67935bde103cf10c1bd9948ac1388f5221322
ms.sourcegitcommit: f38f770bfda1c174d2b81fabda7c893b15bd83a1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/20/2020
ms.locfileid: "77473893"
---
# <a name="invoke_result-class"></a>Classe invoke_result

Determina o tipo de retorno do tipo callable que usa os tipos de argumento especificados no momento da compilação. Adicionado em C++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Callable, class... Args>
   struct invoke_result<Callable(Args...)>;

// Helper type
template<class Callable, class... Args>
   using invoke_result_t = typename invoke_result<Callable, Args...>::type;
```

### <a name="parameters"></a>parâmetros

\ *callable*
O tipo callable para consulta.

*Args*\
Os tipos de lista de argumentos para o tipo callable para consulta.

## <a name="remarks"></a>Comentários

Use este modelo para determinar o tipo de resultado de *callable*(*args*...) no momento da compilação, onde *callable* e todos os tipos em *args* são qualquer tipo completo, uma matriz de associação desconhecida ou uma `void`possivelmente qualificada por CV. O membro `type` do modelo de classe nomeia o tipo de retorno de *callable* quando invocado usando os *argumentos Arguments*.... O membro `type` só será definido se *chamável* puder ser chamado quando chamado usando os *argumentos Arguments...* em um contexto não avaliado. Caso contrário, o modelo de classe não tem nenhum membro `type`, que permite testes SFINAE em um determinado conjunto de tipos de argumentos no momento da compilação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits >

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)\
[invoke](functional-functions.md#invoke)
