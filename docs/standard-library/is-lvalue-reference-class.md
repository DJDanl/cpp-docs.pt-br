---
title: Classe is_lvalue_reference | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- type_traits/std::is_lvalue_reference
dev_langs:
- C++
helpviewer_keywords:
- is_lvalue_reference class
- is_lvalue_reference
ms.assetid: 7f11896b-935c-4de1-9c87-9d0127f904e2
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6c3dc413835dfcbb04594e356ef86bc06da7aa8f
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="islvaluereference-class"></a>Classe is_lvalue_reference

Testa se o tipo é uma referência lvalue.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_lvalue_reference;
```

### <a name="parameters"></a>Parâmetros

`Ty` O tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância deste predicado de tipo será verdadeira se o tipo `Ty` for uma referência a um objeto ou a uma função; caso contrário, será falsa. Observe que `Ty` pode não ser uma referência rvalue. Para obter mais informações sobre rvalues, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[Lvalues e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md)<br/>
