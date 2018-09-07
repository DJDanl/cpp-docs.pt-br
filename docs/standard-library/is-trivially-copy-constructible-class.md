---
title: Classe is_trivially_copy_constructible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::is_trivially_copy_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_copy_constructible
ms.assetid: 4274cef5-afdd-4f2d-bc83-7562e7944ddf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1924b82f7c3035ea2aecb463199558c9ead45c91
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44102059"
---
# <a name="istriviallycopyconstructible-class"></a>Classe is_trivially_copy_constructible

Testa se o tipo tem um construtor de cópia trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_trivially_copy_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é uma classe que tem um construtor de cópia trivial, caso contrário, será falsa.

Um construtor de cópia para uma classe *T* será trivial se ele é declarado implicitamente, a classe *T* não tem funções virtuais ou bases virtuais, todas as bases diretas da classe *T* ter construtores triviais de cópia, as classes de todos os membros de dados não estáticos do tipo de classe tiverem construtores triviais de cópia e as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem construtores triviais de cópia.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
