---
title: Funções &lt;set&gt;
ms.date: 11/04/2016
f1_keywords:
- set/std::swap (map)
- set/std::swap (multiset)
ms.assetid: d1277d14-8502-46c0-b820-bcda820f9406
ms.openlocfilehash: a3a63fb86caa3485b1ee14538c3eb1f1ff72923e
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78875754"
---
# <a name="ltsetgt-functions"></a>Funções &lt;set&gt;

## <a name="swap"></a>alternar (mapa)

Troca os elementos de dois conjuntos.

```cpp
template <class Key, class Traits, class Allocator>
void swap(set<Key, Traits, Allocator>& left, set<Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
O conjunto que fornece os elementos a serem trocados, ou o conjunto cujos elementos devem ser trocados com aqueles do conjunto *à esquerda*.

\ *à esquerda*
O conjunto cujos elementos devem ser trocados pelos do conjunto *direito*.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado na classe de contêiner definida para executar a função de membro `left.`[permuta](../standard-library/set-class.md#swap)(`right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

`template` \< **classt**> **void swap**( **t &** , **t &** )

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da classe de membro [set::swap](../standard-library/set-class.md#swap) para obter um exemplo que usa a versão de modelo de `swap`.

## <a name="swap_multiset"></a>troca (multiconjunto)

Troca os elementos de dois multisets.

```cpp
template <class Key, class Traits, class Allocator>
void swap(multiset<Key, Traits, Allocator>& left, multiset<Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
O MultiSet que fornece os elementos a serem trocados ou o multiconjunto cujos elementos devem ser trocados por aqueles do multiconjunto *esquerdo*.

\ *à esquerda*
O multiconjunto cujos elementos devem ser trocados por aqueles do *direito*de multiconjunto.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado na classe de contêiner MultiSet para executar a função de membro `left.`[permuta](../standard-library/multiset-class.md#swap)(`right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

`template` \< **classt**> **void swap**( **t &** , **t &** )

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da classe de membro [multiset::swap](../standard-library/multiset-class.md#swap) para obter um exemplo que usa a versão de modelo de `swap`.
