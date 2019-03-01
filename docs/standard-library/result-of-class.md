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
ms.openlocfilehash: f60a3ef6528da33fd1117fc940e961e9fe0987df
ms.sourcegitcommit: 4299caac2dc9e806c74ac833d856a3838b0f52a1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2019
ms.locfileid: "57006546"
---
# <a name="resultof-class"></a>Classe result_of

Determina o tipo de retorno do tipo callable que usa os tipos de argumento especificados. Adicionado no C++ 14, preterida no c++17.

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

*Fn*<br/>
O tipo callable para consulta.

*ArgTypes*<br/>
Os tipos de lista de argumentos para o tipo callable para consulta.

## <a name="remarks"></a>Comentários

Use este modelo para determinar no tempo de compilação o tipo de resultado `Fn`(`ArgTypes`), onde *Fn* é um tipo callable, referência à função ou referência ao tipo callable, invocada usando uma lista dos tipos de argumentos na  *ArgTypes*. O membro `type` da classe de modelo nomeia o tipo de resultado de `decltype(std::invoke(declval<Fn>(), declval<ArgTypes>()...))` se a expressão não avaliada `std::invoke(declval<Fn>(), declval<ArgTypes>()...)` está bem formada. Caso contrário, a classe de modelo não terá nenhum membro `type`. O tipo *Fn* e todos os tipos de pacote de parâmetros *ArgTypes* devem ser tipos completos, **void**, ou matrizes de limite desconhecido. Preterido em favor da [invoke_result](invoke-result-class.md) no c++17.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[invoke_result class](invoke-result-class.md)<br/>
