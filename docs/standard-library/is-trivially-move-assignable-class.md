---
title: Classe is_trivially_move_assignable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- type_traits/std::is_trivially_move_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_move_assignable
ms.assetid: 374f7322-0706-4bc1-a1a5-4191d0315e28
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ee7fb3e92064ebced6390c0eaf81fc68552381ca
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="istriviallymoveassignable-class"></a>Classe is_trivially_move_assignable

Testa se o tipo tem um operador de atribuição de movimentação trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_trivially_move_assignable;
```

### <a name="parameters"></a>Parâmetros

`Ty` O tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `Ty` for uma classe com um operador de atribuição de movimentação trivial; caso contrário, será falsa.

Um operador de atribuição de movimentação para uma classe `Ty` será trivial se:

for fornecido implicitamente

a classe `Ty` não tiver funções virtuais

a classe `Ty` não tiver bases virtuais

as classes de todos os membros de dados não estáticos do tipo de classe tiverem operadores de atribuição de movimentação trivial

as classes de todos os membros de dados não estáticos da matriz de tipo da classe tiverem operadores de atribuição de movimentação trivial

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
