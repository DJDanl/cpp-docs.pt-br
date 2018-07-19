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
ms.openlocfilehash: 29b23ec4afe32d1aa383afd4fdaf3ca280d49161
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38955254"
---
# <a name="ltvectorgt-functions"></a>Funções &lt;vetor&gt;


## <a name="swap"></a>  swap

Troca os elementos de dois vetores.

```cpp
template <class Type, class Allocator>
void swap(vector<Type, Allocator>& left, vector<Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*right*  
 O vetor que fornece os elementos a serem trocados ou um vetor cujos elementos são trocados por aqueles do vetor *esquerdo*.

*left*  
 O vetor cujos elementos são trocados por aqueles do vetor *certa*.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado no vetor de classe de contêiner para executar a função de membro `left`. [Vector:: swap](../standard-library/vector-class.md) *(à direita*). Essas são instâncias de ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **template** \< **class T**> **void swap**( **T&**, **T&**), no algoritmo de classe funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Consulte o exemplo de código da função membro [vector::swap](../standard-library/vector-class.md) para obter um exemplo que usa a versão de modelo do `swap`.

## <a name="see-also"></a>Consulte também

[\<vector>](../standard-library/vector.md)<br/>
