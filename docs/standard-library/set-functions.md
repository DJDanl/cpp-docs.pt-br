---
title: Funções &lt;set&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- set/std::swap (map)
- set/std::swap (multiset)
ms.assetid: d1277d14-8502-46c0-b820-bcda820f9406
ms.openlocfilehash: b25194dc1cdc45bc93d9e5188715e3ea01258af4
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38966326"
---
# <a name="ltsetgt-functions"></a>Funções &lt;set&gt;

|||
|-|-|
|[swap (map)](#swap)|[swap (multiset)](#swap_multiset)|

## <a name="swap"></a>  swap  (map)

Troca os elementos de dois conjuntos.

```cpp
template <class Key, class Traits, class Allocator>
void swap(set<Key, Traits, Allocator>& left, set<Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*à direita* o conjunto que fornece os elementos a serem trocados ou o conjunto cujos elementos serão trocados com aqueles do set *esquerdo*.

*à esquerda* o set cujos elementos são trocados por aqueles do set *direito*.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado na classe de contêiner set para executar a função de membro `left.` [permuta](../standard-library/set-class.md#swap)(`right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

`template`\< **classT**> **void swap**( **T&**, **T&**)

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da classe de membro [set::swap](../standard-library/set-class.md#swap) para obter um exemplo que usa a versão de modelo de `swap`.

## <a name="swap_multiset"></a>  swap  (multiset)

Troca os elementos de dois multisets.

```cpp
template <class Key, class Traits, class Allocator>
void swap(multiset<Key, Traits, Allocator>& left, multiset<Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*à direita* multiset que fornece os elementos a serem trocados ou o multiset cujos elementos deverão ser trocados com aqueles do multiset *esquerdo*.

*à esquerda* o multiset cujos elementos deverão ser trocados com aqueles do multiset *direito*.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado na classe de contêiner multiset para executar a função de membro `left.` [permuta](../standard-library/multiset-class.md#swap)(`right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

`template`\< **classT**> **void swap**( **T&**, **T&**)

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da classe de membro [multiset::swap](../standard-library/multiset-class.md#swap) para obter um exemplo que usa a versão de modelo de `swap`.

## <a name="see-also"></a>Consulte também

[\<set>](../standard-library/set.md)<br/>
