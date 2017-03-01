---
title: "Funções &lt;map&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 7cb3d1a5-7add-4726-a73f-61927eafd466
caps.latest.revision: 6
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 85c900f2263ae1c1089478badc85388e3b5e8548
ms.openlocfilehash: d322b318ac4206c5bc27b81299190d129548ef9f
ms.lasthandoff: 02/25/2017

---
# <a name="ltmapgt-functions"></a>Funções &lt;map&gt;
|||  
|-|-|  
|[swap (map)](#swap)|[swap (multimap)](#swap_multimap)|  
  
##  <a name="a-nameswapmultimapa--swap--map"></a><a name="swap_multimap"></a>  swap  (map)
 Troca os elementos de dois mapas.  
  
```  
template <class key, class T, class _Pr, class _Alloc>  
void swap(
    map<Key, Traits, Compare, Alloctor>& left,  
    map<Key, Traits, Compare, Alloctor>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O mapa que fornece os elementos a serem trocados ou o mapa cujos elementos devem ser trocados por aqueles que estão no mapa ` left`.  
  
 ` left`  
 O mapa cujos elementos devem ser trocados por aqueles que estão no mapa ` right`.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo é um algoritmo especializado no mapa de classe de contêiner para executar a função de membro ` left.`[swap](../standard-library/map-class.md#map__swap)*(right*). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **template** \< **class T**> **void swap**( **T&**, **T&**), no algoritmo de classe funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de código da função de membro [map::swap](../standard-library/map-class.md#map__swap) para obter uma amostra que utiliza a versão de modelo do `swap`.  
  
##  <a name="a-nameswapa--swap--multimap"></a><a name="swap"></a>  swap  (multimapa)
 Troca os elementos de dois multimaps.  
  
```  
template <class key, class T, class _Pr, class _Alloc>  
void swap(
    multimap<Key, Traits, Compare, Alloctor>& left,  
    multimap<Key, Traits, Compare, Alloctor>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O multimap que fornece os elementos que serão trocados ou o multimap cujos elementos deverão ser trocados com aqueles do multimap ` left`.  
  
 ` left`  
 O multimapa cujos elementos deverão ser trocados com aqueles do multimapa ` right`.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo é um algoritmo especializado no mapa de classe de contêiner para executar a função de membro ` left.`[swap](../standard-library/multimap-class.md#multimap__swap) ( ` right`) no multimapa de classe de contêiner. Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **template** \< **class T**> **void swap**( **T&**, **T&**), no algoritmo de classe funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de código da função de membro [multimap::swap](../standard-library/multimap-class.md#multimap__swap) para obter uma amostra que utiliza a versão de modelo do `swap`.  
  
## <a name="see-also"></a>Consulte também  
 [\<map>](../standard-library/map.md)

