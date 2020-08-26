---
title: Funções &lt;hash_set&gt;
ms.date: 11/04/2016
f1_keywords:
- hash_set/std::swap
- hash_set/std::swap (hash_multiset)
ms.assetid: 557a0162-3728-4537-97dc-f9f6cc7ece94
ms.openlocfilehash: 1774b0b29c7750e716f1f56def5d29ac329abec0
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845803"
---
# <a name="lthash_setgt-functions"></a>Funções &lt;hash_set&gt;

[permuta](#swap)\
[trocar (hash_multiset)](#swap_hash_multiset)

## <a name="swap"></a><a name="swap"></a> permuta

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Troca os elementos de dois hash_sets.

```cpp
void swap(
    hash_set <Key, Traits, Allocator>& left,
    hash_set <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O hash_set que fornece os elementos a serem trocados ou o hash_set cujos elementos devem ser alterados com aqueles do hash_set *à esquerda*.

*mantida*\
O hash_set cujos elementos devem ser trocados pelos do hash_set *direito*.

### <a name="remarks"></a>Comentários

A `swap` função de modelo é um algoritmo especializado na classe de contêiner hash_set para executar a função de membro `left.` [swap](../standard-library/hash-set-class.md#swap)( `right` ). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

**troca de void de modelo \<class T> (t&, t&),**

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da função de membro [hash_multiset::swap](../standard-library/hash-set-class.md#swap) para obter um exemplo que usa a versão de modelo do `swap`.

## <a name="swap-hash_multiset"></a><a name="swap_hash_multiset"></a> trocar (hash_multiset)

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Troca os elementos de dois hash_multisets.

```cpp
void swap(hash_multiset <Key, Traits, Allocator>& left, hash_multiset <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O hash_multiset que fornece os elementos a serem trocados ou o hash_multiset cujos elementos devem ser alterados com aqueles do hash_multiset *à esquerda*.

*mantida*\
O hash_multiset cujos elementos devem ser trocados pelos do hash_multiset *direito*.

### <a name="remarks"></a>Comentários

A `swap` função de modelo é um algoritmo especializado na classe de contêiner hash_multiset para executar a função de membro `left.` [swap](../standard-library/hash-multiset-class.md#swap)( `right` ). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

**troca de void de modelo \<class T> (t&, t&),**

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da classe de membro [hash_multiset::swap](../standard-library/hash-multiset-class.md#swap) para obter um exemplo que usa a versão de modelo do `swap`.

## <a name="see-also"></a>Confira também

[<hash_set>](../standard-library/hash-set.md)
