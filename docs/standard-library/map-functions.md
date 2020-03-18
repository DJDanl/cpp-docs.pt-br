---
title: Funções &lt;map&gt;
ms.date: 11/04/2016
f1_keywords:
- map/std::swap (map)
- map/std::swap (multimap)
ms.assetid: 7cb3d1a5-7add-4726-a73f-61927eafd466
ms.openlocfilehash: e7876b37bfc006eaecf2f1e36273c5ae8689dad4
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79419969"
---
# <a name="ltmapgt-functions"></a>Funções &lt;map&gt;

## <a name="swap_multimap"></a>alternar (mapa)

Troca os elementos de dois mapas.

```cpp
template <class key, class T, class _Pr, class _Alloc>
void swap(
    map<Key, Traits, Compare, Alloctor>& left,
    map<Key, Traits, Compare, Alloctor>& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
O mapa que fornece os elementos a serem trocados ou o mapa cujos elementos devem ser trocados com aqueles do mapa *à esquerda*.

\ *à esquerda*
O mapa cujos elementos devem ser trocados com os da *direita*do mapa.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado no mapa de classes de contêiner para executar a função de membro `left`. [swap](../standard-library/map-class.md#swap)(`right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **modelo** \< **classe t**> **anular permuta**( **t &** , **t &** ), na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da função de membro [map::swap](../standard-library/map-class.md#swap) para obter uma amostra que utiliza a versão de modelo do `swap`.

## <a name="swap"></a>swap (Multimap)

Troca os elementos de dois multimaps.

```cpp
template <class key, class T, class _Pr, class _Alloc>
void swap(
    multimap<Key, Traits, Compare, Alloctor>& left,
    multimap<Key, Traits, Compare, Alloctor>& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
O Multimap que fornece os elementos a serem trocados ou o Multimap cujos elementos devem ser alterados com aqueles do Multimap *Left*.

\ *à esquerda*
O Multimap cujos elementos devem ser trocados pelos do Multimap *direito*.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado no mapa da classe de contêiner a ser executado na classe de contêiner Multimap para executar a função de membro `left`. [swap](../standard-library/multimap-class.md#swap) (`right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **modelo** \< **classe t**> **anular permuta**( **t &** , **t &** ), na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da função de membro [multimap::swap](../standard-library/multimap-class.md#swap) para obter uma amostra que utiliza a versão de modelo do `swap`.
