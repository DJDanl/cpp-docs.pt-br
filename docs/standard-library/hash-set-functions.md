---
title: Funções &lt;hash_set&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- hash_set/std::swap
- hash_set/std::swap (hash_multiset)
ms.assetid: 557a0162-3728-4537-97dc-f9f6cc7ece94
ms.openlocfilehash: 083d928198d8d83d8a56d8a74a6204e94c86aa67
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33846279"
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

`right` O hash_set fornecendo os elementos a ser trocado ou o hash_set cujos elementos são sejam trocadas com aqueles o hash_set `left`.

`left` O hash_set cujos elementos são sejam trocadas com aqueles o hash_set `right`.

### <a name="remarks"></a>Comentários

A função de modelo `swap` é um algoritmo especializado na classe de contêiner hash_set para executar a função membro `left.`[swap](../standard-library/hash-set-class.md#swap)( `right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

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

`right` O hash_multiset fornecendo os elementos a ser trocado ou o hash_multiset cujos elementos são sejam trocadas com aqueles o hash_multiset `left`.

`left` O hash_multiset cujos elementos são sejam trocadas com aqueles o hash_multiset `right`.

### <a name="remarks"></a>Comentários

A função de modelo `swap` é um algoritmo especializado na classe de contêiner hash_multiset para executar a função membro `left.`[swap](../standard-library/hash-multiset-class.md#swap)( `right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

**modelo \<classe T> void swap(T&, T&),**

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da classe de membro [hash_multiset::swap](../standard-library/hash-multiset-class.md#swap) para obter um exemplo que usa a versão de modelo do `swap`.

## <a name="see-also"></a>Consulte também

[<hash_set>](../standard-library/hash-set.md)<br/>
