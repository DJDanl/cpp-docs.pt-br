---
title: Funções &lt;hash_set&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- hash_set/std::swap
- hash_set/std::swap (hash_multiset)
ms.assetid: 557a0162-3728-4537-97dc-f9f6cc7ece94
ms.openlocfilehash: ad8041ff6a4abab84272d2bbbdee290bfce4eff6
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38961871"
---
# <a name="lthashsetgt-functions"></a>Funções &lt;hash_set&gt;

|||
|-|-|
|[swap](#swap)|[swap (hash_multiset)](#swap_hash_multiset)|

## <a name="swap"></a>  swap

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Troca os elementos de dois hash_sets.

```cpp
void swap(
    hash_set <Key, Traits, Allocator>& left,
    hash_set <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*à direita* hash_set que fornece os elementos a serem trocados ou o hash_set cujos elementos deverão ser trocados do hash_set *esquerdo*.

*à esquerda* hash_set cujos elementos deverão ser trocados do hash_set *direito*.

### <a name="remarks"></a>Comentários

O `swap` função de modelo é um algoritmo especializado na classe de contêiner hash_set para executar a função de membro `left.` [swap](../standard-library/hash-set-class.md#swap)(`right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

**modelo \<classe T> void swap(T&, T&),**

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da função de membro [hash_multiset::swap](../standard-library/hash-set-class.md#swap) para obter um exemplo que usa a versão de modelo do `swap`.

## <a name="swap_hash_multiset"></a>  swap (hash_multiset)

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).

Troca os elementos de dois hash_multisets.

```cpp
void swap(hash_multiset <Key, Traits, Allocator>& left, hash_multiset <Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*à direita* hash_multiset que fornece os elementos a serem trocados ou o hash_multiset cujos elementos deverão ser trocados do hash_multiset *esquerdo*.

*à esquerda* hash_multiset cujos elementos deverão ser trocados do hash_multiset *direito*.

### <a name="remarks"></a>Comentários

O `swap` função de modelo é um algoritmo especializado na classe de contêiner hash_multiset para executar a função de membro `left.` [swap](../standard-library/hash-multiset-class.md#swap)(`right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

**modelo \<classe T> void swap(T&, T&),**

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da classe de membro [hash_multiset::swap](../standard-library/hash-multiset-class.md#swap) para obter um exemplo que usa a versão de modelo do `swap`.

## <a name="see-also"></a>Consulte também

[<hash_set>](../standard-library/hash-set.md)<br/>
