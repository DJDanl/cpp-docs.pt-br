---
title: Classe is_nothrow_destructible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- type_traits/std::is_nothrow_destructible
dev_langs:
- C++
helpviewer_keywords:
- is_nothrow_destructible
ms.assetid: 0bbd8a28-e312-4d72-bd28-aac027f974d3
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 14a28261ee1d5e3e58cc36e6adf0ac1da08b1b28
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="isnothrowdestructible-class"></a>Classe is_nothrow_destructible

Testa se o tipo é destrutível e se o compilador tiver conhecimento de que o destruidor não efetua lançamentos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_nothrow_destructible;
```

### <a name="parameters"></a>Parâmetros

`T` O tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `T` for um tipo destrutível e se o compilador tiver conhecimento de que o destruidor não efetua lançamentos. Caso contrário, será falsa.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
