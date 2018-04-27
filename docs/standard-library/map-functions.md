---
title: Funções &lt;map&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- map/std::swap (map)
- map/std::swap (multimap)
ms.assetid: 7cb3d1a5-7add-4726-a73f-61927eafd466
caps.latest.revision: 6
manager: ghogen
ms.openlocfilehash: 6a83feab5c477f222dc192c1c916e5cbb93e637d
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="ltmapgt-functions"></a>Funções &lt;map&gt;

|||
|-|-|
|[swap (map)](#swap)|[swap (multimap)](#swap_multimap)|

## <a name="swap_multimap"></a>  swap  (map)

Troca os elementos de dois mapas.

```cpp
template <class key, class T, class _Pr, class _Alloc>
void swap(
    map<Key, Traits, Compare, Alloctor>& left,
    map<Key, Traits, Compare, Alloctor>& right);
```

### <a name="parameters"></a>Parâmetros

`right` O mapa fornecendo os elementos a ser trocada, ou o mapa cujos elementos são sejam trocadas com aquelas do mapa `left`.

`left` O mapa cujos elementos são sejam trocadas com aquelas do mapa `right`.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado no mapa de classe de contêiner para executar a função de membro `left`.[ permuta](../standard-library/map-class.md#swap)( `right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **template** \< **class T**> **void swap**( **T&**, **T&**), no algoritmo de classe funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da função de membro [map::swap](../standard-library/map-class.md#swap) para obter uma amostra que utiliza a versão de modelo do `swap`.

## <a name="swap"></a>  swap  (multimapa)

Troca os elementos de dois multimaps.

```cpp
template <class key, class T, class _Pr, class _Alloc>
void swap(
    multimap<Key, Traits, Compare, Alloctor>& left,
    multimap<Key, Traits, Compare, Alloctor>& right);
```

### <a name="parameters"></a>Parâmetros

`right` Os vários mapeamentos fornecendo os elementos a ser trocado ou vários mapeamentos cujos elementos são sejam trocadas com aqueles de vários mapeamentos `left`.

`left` Os vários mapeamentos cujos elementos são sejam trocadas com aqueles de vários mapeamentos `right`.

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado no mapa de classe de contêiner para executar em multimap de classe de contêiner para executar a função de membro `left`.[ permuta](../standard-library/multimap-class.md#swap) ( `right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **template** \< **class T**> **void swap**( **T&**, **T&**), no algoritmo de classe funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

### <a name="example"></a>Exemplo

Veja o exemplo de código da função de membro [multimap::swap](../standard-library/multimap-class.md#swap) para obter uma amostra que utiliza a versão de modelo do `swap`.

## <a name="see-also"></a>Consulte também

[\<map>](../standard-library/map.md)<br/>
