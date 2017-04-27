---
title: "Funções &lt;set&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- set/std::swap (map)
- set/std::swap (multiset)
ms.assetid: d1277d14-8502-46c0-b820-bcda820f9406
caps.latest.revision: 7
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: fb2b30dc58b7ba65dd13a07cec8456ea4adeb5e1
ms.lasthandoff: 02/25/2017

---
# <a name="ltsetgt-functions"></a>Funções &lt;set&gt;
|||  
|-|-|  
|[swap (map)](#swap)|[swap (multiset)](#swap_multiset)|  
  
##  <a name="swap"></a>  swap  (map)
 Troca os elementos de dois conjuntos.  
  
```
template <class Key, class Traits, class Allocator>  
void swap(set<Key, Traits, Allocator>& left, set<Key, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O set que fornece os elementos a serem trocados ou o set cujos elementos devem ser trocados por aqueles que estão no set `left`.  
  
 `left`  
 O set cujos elementos serão trocados por aqueles do set `right`.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo é um algoritmo especializado na classe de contêiner set para executar a função membro `left``.`[swap](../standard-library/set-class.md#set__swap)( `right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo  
  
 `template`\< **classT**> **void swap**( **T&**, **T&**)  
  
 na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de código da classe de membro [set::swap](../standard-library/set-class.md#set__swap) para obter um exemplo que usa a versão de modelo de `swap`.  
  
##  <a name="swap_multiset"></a>  swap  (multiset)
 Troca os elementos de dois multisets.  
  
```
template <class Key, class Traits, class Allocator>  
void swap(multiset<Key, Traits, Allocator>& left, multiset<Key, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O multiset que fornece os elementos que serão trocados ou o multiset cujos elementos deverão ser trocados com aqueles do multiset `left`.  
  
 `left`  
 O multiset cujos elementos deverão ser trocados com aqueles do multiset `right`.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo é um algoritmo especializado na classe de contêiner multiset para executar a função membro `left``.`[swap](../standard-library/multiset-class.md#multiset__swap)( `right`). Trata-se de uma instância da ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo  
  
 `template`\< **classT**> **void swap**( **T&**, **T&**)  
  
 na classe de algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de código da classe de membro [multiset::swap](../standard-library/multiset-class.md#multiset__swap) para obter um exemplo que usa a versão de modelo de `swap`.  
  
## <a name="see-also"></a>Consulte também  
 [\<set>](../standard-library/set.md)




