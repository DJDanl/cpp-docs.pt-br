---
title: Classe decay
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::decay
helpviewer_keywords:
- decay class
ms.assetid: 96baa2fd-c8e0-49af-be91-ba375ba7f9dc
ms.openlocfilehash: 23c2cff37e67e78ba68c37468c110d7a3725b785
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394047"
---
# <a name="decay-class"></a>Classe decay

Produz o tipo passado por valor. Torna o tipo não referência, não const, não volátil ou cria um ponteiro para o tipo com base em uma função ou em um tipo de matriz.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct decay;

template <class T>
using decay_t = typename decay<T>::type;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser modificado.

## <a name="remarks"></a>Comentários

Use o modelo de decay para produzir o tipo resultante como se o tipo tivesse sido passado por valor como um argumento. O membro de classe de modelo typedef `type` mantém um tipo modificado que é definido nos seguintes estágios:

- O tipo `U` é definido como `remove_reference<T>::type`.

- Se `is_array<U>::value` for verdadeiro, o tipo modificado `type` será `remove_extent<U>::type *`.

- Caso contrário, se `is_function<U>::value` for verdadeiro, o tipo modificado `type` será `add_pointer<U>::type`.

- Caso contrário, o tipo modificado `type` será `remove_cv<U>::type`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
