---
title: Funções &lt;hash_set&gt;
ms.date: 11/04/2016
f1_keywords:
- hash_set/std::swap
- hash_set/std::swap (hash_multiset)
ms.assetid: 557a0162-3728-4537-97dc-f9f6cc7ece94
ms.openlocfilehash: d7df6b3c5dc0d0d493d17b3e9995bc4758ffd6d4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370594"
---
# <a name="lthash_setgt-functions"></a>Funções &lt;hash_set&gt;

|||
|-|-|
|[Trocar](#swap)|[swap (hash_multiset)](#swap_hash_multiset)|

## <a name="swap"></a><a name="swap"></a>Trocar

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Troca os elementos de dois hash_sets.

```cpp
void swap(
    hash_set <Key, Traits, Allocator>& left,
    hash_set <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O hash_set fornecendo os elementos a serem trocados, ou os hash_set cujos elementos devem ser trocados com os da hash_set *esquerda.*

*Deixou*\
O hash_set cujos elementos devem ser trocados com os da hash_set *direita.*

### <a name="remarks"></a>Comentários

A `swap` função modelo é um algoritmo especializado na classe `left.`de`right`contêineres hash_set para executar a [troca](../standard-library/hash-set-class.md#swap)de funções do membro ( ). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

**modelo \<classe T> void swap(T&, T&),**

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da função de membro [hash_multiset::swap](../standard-library/hash-set-class.md#swap) para obter um exemplo que usa a versão de modelo do `swap`.

## <a name="swap-hash_multiset"></a><a name="swap_hash_multiset"></a>swap (hash_multiset)

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Troca os elementos de dois hash_multisets.

```cpp
void swap(hash_multiset <Key, Traits, Allocator>& left, hash_multiset <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O hash_multiset fornecendo os elementos a serem trocados, ou os hash_multiset cujos elementos devem ser trocados com os da hash_multiset *esquerda.*

*Deixou*\
O hash_multiset cujos elementos devem ser trocados com os da hash_multiset *direita.*

### <a name="remarks"></a>Comentários

A `swap` função modelo é um algoritmo especializado na classe `left.`container`right`hash_multiset para executar a [troca](../standard-library/hash-multiset-class.md#swap)de funções do membro ( ). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

**modelo \<classe T> void swap(T&, T&),**

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da classe de membro [hash_multiset::swap](../standard-library/hash-multiset-class.md#swap) para obter um exemplo que usa a versão de modelo do `swap`.

## <a name="see-also"></a>Confira também

[hash_set hash_set<>](../standard-library/hash-set.md)
