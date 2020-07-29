---
title: Classe is_literal_type
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_literal_type
helpviewer_keywords:
- is_literal_type
ms.assetid: a03a4ebb-ee66-48d6-91bb-41cf72b2401f
ms.openlocfilehash: d5b750755f2499c89e91e497ed03244a11484871
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212248"
---
# <a name="is_literal_type-class"></a>Classe is_literal_type

Testa se um tipo pode ser usado como uma **`constexpr`** variável ou ser construído, usado por ou retornado de **`constexpr`** funções.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_literal_type;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se manterá true se o tipo *T* for um *tipo literal*, caso contrário, será false. Um tipo literal é **`void`** , um tipo escalar, um tipo de referência, uma matriz de tipo literal ou um tipo de classe literal. Um tipo de classe literal é um tipo de classe que tem um destruidor trivial, é um tipo de agregação ou tem pelo menos um construtor não movido, não cópia e **`constexpr`** todas as suas classes base e membros de dados não estáticos são tipos literais não voláteis. Embora o tipo de um literal seja sempre um tipo literal, o conceito de um tipo literal inclui qualquer coisa que o compilador possa avaliar como **`constexpr`** em tempo de compilação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)
