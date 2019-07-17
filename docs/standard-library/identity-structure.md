---
title: Estrutura identity
ms.date: 11/04/2016
f1_keywords:
- utility/std::identity
helpviewer_keywords:
- identity class
- identity structure
ms.assetid: 990756fd-7969-4b39-ad7e-0878e8dac8fd
ms.openlocfilehash: 49b2c1eb3ca03f9bf9199bdbca49348866ff0a7e
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68246160"
---
# <a name="identity-structure"></a>Estrutura identity

Um struct que fornece uma definição de tipo como o parâmetro do modelo.

## <a name="syntax"></a>Sintaxe

```cpp
struct identity {
   typedef Type type;
   Type operator()(const Type& left) const;
};
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
O valor a ser identificado.

## <a name="remarks"></a>Comentários

A classe contém a definição de tipo público `type`, que é a mesma do parâmetro de modelo Type. Ela é usada em conjunto com a função de modelo [forward](../standard-library/utility-functions.md#forward) para garantir que o parâmetro da função tem o tipo desejado.

Para compatibilidade com o código anterior, a classe define também a função identity `operator()` que retorna o argumento *esquerdo*.
