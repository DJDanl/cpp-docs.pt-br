---
title: Classe conditional
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::conditional
helpviewer_keywords:
- conditional class
- conditional
ms.assetid: ece9f539-fb28-4e26-a79f-3264bc984493
ms.openlocfilehash: be81a1bc32f2f86f1d79970868933bddb8dc3620
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50523013"
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

*B*<br/>
O valor que determina o tipo selecionado.

*T1*<br/>
O resultado de tipo quando B é true.

*T2*<br/>
O resultado de tipo quando B é false.

## <a name="remarks"></a>Comentários

O membro de modelo typedef `conditional<B, T1, T2>::type` for avaliada como *T1* quando *B* for avaliada como **true**e é avaliada como *T2* quando  *B* for avaliada como **falso**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
