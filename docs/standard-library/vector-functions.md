---
title: Funções &lt;vetor&gt;
ms.date: 11/04/2016
f1_keywords:
- vector/std::swap
ms.assetid: 6cdcf043-eef6-4330-83f0-4596fb9f968a
helpviewer_keywords:
- std::swap [vector]
ms.openlocfilehash: bf28e44b4f603b1e4d6a87f0c28b42d6cc159980
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224546"
---
# <a name="ltvectorgt-functions"></a>Funções &lt;vetor&gt;

## <a name="swap"></a><a name="swap"></a>permuta

Troca os elementos de dois vetores.

```cpp
template <class Type, class Allocator>
void swap(vector<Type, Allocator>& left, vector<Type, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O vetor que fornece os elementos a serem alternados ou o vetor cujos elementos devem ser trocados com os do vetor *à esquerda*.

*mantida*\
O vetor cujos elementos devem ser trocados por aqueles do vetor *à direita*.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado no vetor de classe de contêiner para executar a função de membro `left` . [vector:: swap](../standard-library/vector-class.md) *(direita*). Essas são instâncias de ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **`template`** \< **class T**> **void swap**( **t&**, **t&**), na classe Algorithm funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Consulte o exemplo de código da função membro [vector::swap](../standard-library/vector-class.md) para obter um exemplo que usa a versão de modelo do `swap`.
