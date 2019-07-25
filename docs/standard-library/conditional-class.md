---
title: Classe conditional
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::conditional
helpviewer_keywords:
- conditional class
- conditional
ms.assetid: ece9f539-fb28-4e26-a79f-3264bc984493
ms.openlocfilehash: b8f0f69cc1e4f6966bc9ccb63fe529436295badd
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68457322"
---
# <a name="conditional-class"></a>Classe conditional

Selecione um dos dois tipos, dependendo da condição especificada.

## <a name="syntax"></a>Sintaxe

```cpp
template <bool B, class T1, class T2>
struct conditional;

template <bool _Test, class _T1, class _T2>
using conditional_t = typename conditional<_Test, _T1, _T2>::type;
```

### <a name="parameters"></a>Parâmetros

*B*\
O valor que determina o tipo selecionado.

*T1*\
O resultado de tipo quando B é true.

*T2*\
O resultado de tipo quando B é false.

## <a name="remarks"></a>Comentários

O `conditional<B, T1, T2>::type` typedef do membro do modelo é avaliado como *T1* quando *b* é avaliado como **true**e é avaliado como *T2* quando *b* é avaliado como **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
