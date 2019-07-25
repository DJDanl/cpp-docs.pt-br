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
ms.openlocfilehash: 2b2051b0c854151cff9b439f5ec0a951c25a6387
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68447634"
---
# <a name="invokeresult-class"></a>Classe invoke_result

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

*Acessível*\
O tipo callable para consulta.

*Argumento*\
Os tipos de lista de argumentos para o tipo callable para consulta.

## <a name="remarks"></a>Comentários

Use este modelo para determinar o tipo de resultado de *callable*(*args*...) no momento da compilação, onde *callable* e todos os tipos em *args* são de qualquer tipo completo, uma matriz de associação desconhecida ou uma possivelmente `void`qualificada para CV. O `type` membro da classe de modelo nomeia o tipo de retorno de *callable* quando invocado usando os *argumentos Arguments*.... O `type` membro só será definido se *chamável* puder ser chamado quando invocado usando os *argumentos Arguments*... em um contexto não avaliado. Caso contrário, a classe de modelo não `type`tem nenhum membro, que permite testes SFINAE em um determinado conjunto de tipos de argumentos no momento da compilação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[invoke](functional-functions.md#invoke)
