---
title: Funções &lt;set&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- set/std::swap (map)
- set/std::swap (multiset)
ms.assetid: d1277d14-8502-46c0-b820-bcda820f9406
caps.latest.revision: 7
manager: ghogen
ms.openlocfilehash: 29579adf6b9556635862985b324e27ebea416bc0
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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

`right` O conjunto de fornecer os elementos a ser trocado ou o conjunto cujos elementos devem ser trocadas com aqueles do conjunto de `left`.

`left` O conjunto cujos elementos devem ser trocadas com aqueles do conjunto de `right`.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado na classe de contêiner set para executar a função membro `left.`[swap](../standard-library/set-class.md#swap)( `right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

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

`right` O multiconjunto fornecendo os elementos a ser trocado ou o multiconjunto cujos elementos são sejam trocadas com aqueles o multiconjunto `left`.

`left` O multiconjunto cujos elementos são sejam trocadas com aqueles o multiconjunto `right`.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado na classe de contêiner multiset para executar a função membro `left.`[swap](../standard-library/multiset-class.md#swap)( `right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo

`template`\< **classT**> **void swap**( **T&**, **T&**)

na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da classe de membro [multiset::swap](../standard-library/multiset-class.md#swap) para obter um exemplo que usa a versão de modelo de `swap`.

## <a name="see-also"></a>Consulte também

[\<set>](../standard-library/set.md)<br/>
