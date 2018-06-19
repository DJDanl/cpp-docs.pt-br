---
title: Funções &lt;vector&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- vector/std::swap
ms.assetid: 6cdcf043-eef6-4330-83f0-4596fb9f968a
helpviewer_keywords:
- std::swap [vector]
ms.openlocfilehash: dbcb2524736bcb99693f3a4b27790c3447d58fe3
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33856170"
---
# <a name="ltvectorgt-functions"></a>Funções &lt;vetor&gt;


## <a name="swap"></a>  swap

Troca os elementos de dois vetores.

```cpp
template <class Type, class Allocator>
void swap(vector<Type, Allocator>& left, vector<Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

`right` O vetor de fornecer os elementos a ser trocado ou vetor cujos elementos são sejam trocadas com aquelas do vetor `left`.

`left` O vetor cujos elementos são sejam trocadas com aquelas do vetor `right`.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializadas sobre o vetor de classe de contêiner para executar a função de membro `left`. [Vector:: swap](../standard-library/vector-class.md) *(direita*). Essas são instâncias de ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **template** \< **class T**> **void swap**( **T&**, **T&**), no algoritmo de classe funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Consulte o exemplo de código da função membro [vector::swap](../standard-library/vector-class.md) para obter um exemplo que usa a versão de modelo do `swap`.

## <a name="see-also"></a>Consulte também

[\<vector>](../standard-library/vector.md)<br/>
