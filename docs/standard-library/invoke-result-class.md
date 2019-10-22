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
ms.openlocfilehash: 8cd72e62fcb65209482fd9677afcc2ec83356feb
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689515"
---
# <a name="invoke_result-class"></a>Classe invoke_result

Determina o tipo de retorno do tipo callable que usa os tipos de argumento especificados no momento da compilação. Adicionado em C++ 17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Callable, class... Args>
   struct invoke_result<Callable(Args...)>;

// Helper type
template<lass Callable, class... Args>
   using invoke_result_t = typename invoke_result<Callable, Args...>::type;
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *callable*
O tipo callable para consulta.

*Args* \
Os tipos de lista de argumentos para o tipo callable para consulta.

## <a name="remarks"></a>Comentários

Use este modelo para determinar o tipo de resultado de *callable*(*args*...) no momento da compilação, onde *callable* e todos os tipos em *args* são qualquer tipo completo, uma matriz de associação desconhecida ou uma `void` possivelmente qualificada por CV. O membro `type` do modelo de classe nomeia o tipo de retorno de *callable* quando invocado usando os *argumentos Arguments*.... O membro `type` só será definido se *chamável* puder ser chamado quando chamado usando os *argumentos Arguments...* em um contexto não avaliado. Caso contrário, o modelo de classe não tem nenhum membro `type`, que permite testes SFINAE em um determinado conjunto de tipos de argumentos no momento da compilação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Chame](functional-functions.md#invoke)
