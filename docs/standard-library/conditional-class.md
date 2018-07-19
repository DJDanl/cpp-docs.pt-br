---
title: Classe conditional | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::conditional
dev_langs:
- C++
helpviewer_keywords:
- conditional class
- conditional
ms.assetid: ece9f539-fb28-4e26-a79f-3264bc984493
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 57e01cbfd7cb291ff7d2651e3244b74ae96adbea
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38962394"
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

*B* o valor que determina o tipo selecionado.

*T1* o resultado de tipo quando B é true.

*T2* o resultado de tipo quando B é false.

## <a name="remarks"></a>Comentários

O membro de modelo typedef `conditional<B, T1, T2>::type` for avaliada como *T1* quando *B* for avaliada como **true**e é avaliada como *T2* quando  *B* for avaliada como **falso**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
