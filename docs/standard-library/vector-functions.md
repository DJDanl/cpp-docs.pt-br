---
title: Funções &lt;vector&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- vector/std::swap
ms.assetid: 6cdcf043-eef6-4330-83f0-4596fb9f968a
helpviewer_keywords:
- std::swap [vector]
caps.latest.revision: 10
manager: ghogen
ms.openlocfilehash: ec6b11a94fbf1b8b736db111a65cf720a1a9438c
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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
