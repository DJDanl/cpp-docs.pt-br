---
title: Funções &lt;map&gt;
ms.date: 11/04/2016
f1_keywords:
- map/std::swap (map)
- map/std::swap (multimap)
ms.assetid: 7cb3d1a5-7add-4726-a73f-61927eafd466
ms.openlocfilehash: 8cc4a82e08963902f9ba5c21ace759c47bdd0014
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228213"
---
# <a name="ltmapgt-functions"></a>Funções &lt;map&gt;

## <a name="swap-map"></a><a name="swap_multimap"></a>alternar (mapa)

Troca os elementos de dois mapas.

```cpp
template <class key, class T, class _Pr, class _Alloc>
void swap(
    map<Key, Traits, Compare, Alloctor>& left,
    map<Key, Traits, Compare, Alloctor>& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O mapa que fornece os elementos a serem trocados ou o mapa cujos elementos devem ser trocados com aqueles do mapa *à esquerda*.

*mantida*\
O mapa cujos elementos devem ser trocados com os da *direita*do mapa.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado no mapa de classes de contêiner para executar a função de membro `left` .[ swap](../standard-library/map-class.md#swap)( `right` ). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **`template`** \< **class T**> **void swap**( **t&**, **t&**), na classe Algorithm funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da função de membro [map::swap](../standard-library/map-class.md#swap) para obter uma amostra que utiliza a versão de modelo do `swap`.

## <a name="swap-multimap"></a><a name="swap"></a>swap (Multimap)

Troca os elementos de dois multimaps.

```cpp
template <class key, class T, class _Pr, class _Alloc>
void swap(
    multimap<Key, Traits, Compare, Alloctor>& left,
    multimap<Key, Traits, Compare, Alloctor>& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O Multimap que fornece os elementos a serem trocados ou o Multimap cujos elementos devem ser alterados com aqueles do Multimap *Left*.

*mantida*\
O Multimap cujos elementos devem ser trocados pelos do Multimap *direito*.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado no mapa da classe de contêiner a ser executado na classe de contêiner Multimap para executar a função de membro `left` .[ swap](../standard-library/multimap-class.md#swap) ( `right` ). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **`template`** \< **class T**> **void swap**( **t&**, **t&**), na classe Algorithm funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da função de membro [multimap::swap](../standard-library/multimap-class.md#swap) para obter uma amostra que utiliza a versão de modelo do `swap`.
