---
title: Classe is_trivially_default_constructible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::is_trivially_default_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_default_constructible
ms.assetid: 653ecd73-909f-4dd8-b95a-d1164d1c2da4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8f2bd65fa7145325fd4c5c2f1a2483851d0738b7
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="istriviallydefaultconstructible-class"></a>Classe is_trivially_default_constructible

Testa se um tipo tem um construtor padrão trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_trivially_default_constructible;
```

### <a name="parameters"></a>Parâmetros

`Ty` O tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo `Ty` for uma classe que tem um construtor trivial; caso contrário, será falsa.

Um construtor padrão de uma classe `Ty` será trivial se:

- for um construtor padrão declarado implicitamente

- a classe `Ty` não tiver funções virtuais

- a classe `Ty` não tiver bases virtuais

- todas as bases diretas da classe `Ty` tiverem construtores triviais

- as classes de todos os membros de dados não estáticos do tipo de classe tiverem construtores triviais

- as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem construtores triviais

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
