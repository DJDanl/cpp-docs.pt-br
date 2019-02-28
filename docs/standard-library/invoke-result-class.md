---
title: Classe de invoke_result
ms.date: 02/21/2019
f1_keywords:
- type_traits/std::invoke_result
- type_traits/std::invoke_result_t
- type_traits/std::invoke_result::type
helpviewer_keywords:
- std::invoke_result
- std::invoke_result_t
- std::invoke_result::type
ms.openlocfilehash: 7c03240d3ee666fcda30562279a8dbda2ca8dc7b
ms.sourcegitcommit: 4299caac2dc9e806c74ac833d856a3838b0f52a1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2019
ms.locfileid: "57006867"
---
# <a name="invokeresult-class"></a>Classe de invoke_result

Determina o tipo de retorno do tipo callable que usa os tipos de argumento especificado em tempo de compilação. Adicionado no c++17.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Callable, class... Args>
   struct invoke_result<Callable(Args...)>;

// Helper type
template<lass Callable, class... Args>
   using invoke_result_t = typename invoke_result<Callable, Args...>::type;
```

### <a name="parameters"></a>Parâmetros

*pode ser chamado*<br/>
O tipo callable para consulta.

*Args*<br/>
Os tipos de lista de argumentos para o tipo callable para consulta.

## <a name="remarks"></a>Comentários

Use este modelo para determinar o tipo de resultado *Callable*(*Args*...) em tempo de compilação, onde *Callable* e todos os tipos no *Args* são qualquer tipo completo, uma matriz de limite desconhecido ou uma possivelmente qualificada por cv `void`. O `type` membro da classe modelo nomeia o tipo de retorno *Callable* quando invocada usando os argumentos *Args*... O `type` membro é definido somente se *Callable* pode ser chamado quando invocado usando os argumentos *Args*... em um contexto não avaliado. Caso contrário, a classe de modelo não tem nenhum membro `type`, que permite a SFINAE testes em um determinado conjunto de tipos de argumento em tempo de compilação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[invoke](functional-functions.md#invoke)
