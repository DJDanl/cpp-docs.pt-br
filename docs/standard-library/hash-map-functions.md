---
title: "Funções &lt;hash_map&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- hash_map/std::swap
- hash_map/std::swap (hash_map)
ms.assetid: 28748cd0-71f7-41b9-b068-579183645fba
caps.latest.revision: "9"
manager: ghogen
ms.openlocfilehash: 4b98135f1b72c66938d00f16649d011a27369473
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="lthashmapgt-functions"></a>Funções &lt;hash_map&gt;
|||  
|-|-|  
|[swap](#swap)|[swap (hash_map)](#swap_hash_map)|  
  
##  <a name="swap_hash_map"></a>  swap (hash_map)  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_map](../standard-library/unordered-map-class.md).  
  
 Troca os elementos de dois hash_maps.  
  
```
void swap(
    hash_map <Key, Type, Traits, Alloctor>& left,
    hash_map <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O hash_map cujos elementos serão trocados por aqueles do `left` do mapa.  
  
 `left`  
 O hash_map cujos elementos serão trocados por aqueles do `right` do mapa.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo é um algoritmo especializado na classe de contêiner hash_map para executar a função membro `left.`[swap](../standard-library/basic-ios-class.md#swap)*(right*). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **template \<class T> void swap(T&, T&)**, no arquivo de cabeçalho do algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.  
  
##  <a name="swap"></a>  swap  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).  
  
 Troca os elementos de dois hash_multimaps.  
  
```
void swap(
    hash_multimap <Key, Type, Traits, Alloctor>& left,
    hash_multimap <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O hash_multimap cujos elementos serão trocados por aqueles do `left` do mapa.  
  
 `left`  
 O hash_multimap cujos elementos serão trocados por aqueles do `right` do mapa.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo é um algoritmo especializado na classe de contêiner hash_multimap para executar a função de membro `left.`[swap](../standard-library/hash-multimap-class.md#swap)*(right*`)`. Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, **template \<class T> void swap(T&, T&)**, no arquivo de cabeçalho do algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.  
  
## <a name="see-also"></a>Consulte também  
 [<hash_map>](../standard-library/hash-map.md)



