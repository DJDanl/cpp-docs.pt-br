---
title: "Classe de CRBMap | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL.CRBMap"
  - "CRBMap"
  - "ATL::CRBMap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CRBMap"
ms.assetid: 658e94dc-e835-4356-aed1-1513e1f66969
caps.latest.revision: 18
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CRBMap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa uma estrutura de mapeamento, usando uma árvore binária Vermelho\- Preta.  
  
## Sintaxe  
  
```  
  
      template<   
   typename K,  
   typename V,  
   class KTraits = CElementTraits< K >,  
   class VTraits = CElementTraits< V >   
> class CRBMap : public CRBTree< K, V, KTraits, VTraits >  
```  
  
#### Parâmetros  
 `K`  
 o tipo de elemento chave.  
  
 *v*  
 O tipo de elemento de valor.  
  
 `KTraits`  
 O código usado para copiar ou mover elementos chaves.  Consulte [classe de CElementTraits](../../atl/reference/celementtraits-class.md) para obter mais detalhes.  
  
 `VTraits`  
 O código usado para copiar ou mover elementos de valor.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRBMap::CRBMap](../Topic/CRBMap::CRBMap.md)|o construtor.|  
|[CRBMap::~CRBMap](../Topic/CRBMap::~CRBMap.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRBMap::Lookup](../Topic/CRBMap::Lookup.md)|Chamar esse método para pesquisar chaves ou valores no objeto de `CRBMap` .|  
|[CRBMap::RemoveKey](../Topic/CRBMap::RemoveKey.md)|Chamar esse método para remover um elemento de objeto de `CRBMap` , usando a chave.|  
|[CRBMap::SetAt](../Topic/CRBMap::SetAt.md)|Chamar esse método para inserir um par do elemento no mapa.|  
  
## Comentários  
 `CRBMap` fornece suporte para uma matriz de mapeamento de qualquer tipo determinado, gerenciando uma matriz ordenada de chaves elementos e seus valores associados.  Cada chave pode ter apenas um valor associado.  Elementos \(consistindo de uma chave e um valor\) são armazenados em uma estrutura de árvore binária, usando o método de [CRBMap::SetAt](../Topic/CRBMap::SetAt.md) .  Elementos podem ser removidos usando o método de [CRBMap::RemoveKey](../Topic/CRBMap::RemoveKey.md) , que exclui o elemento com o valor de dado.  
  
 Percorrer a árvore é se torna possível por métodos como [CRBTree::GetHeadPosition](../Topic/CRBTree::GetHeadPosition.md), [CRBTree::GetNext](../Topic/CRBTree::GetNext.md), e [CRBTree::GetNextValue](../Topic/CRBTree::GetNextValue.md).  
  
 Os parâmetros de `KTraits` e de `VTraits` são classes dos traços que contêm qualquer código suplementar necessário copiar ou mover elementos.  
  
 `CRBMap` é derivado de [CRBTree](../../atl/reference/crbtree-class.md), que implementa uma árvore binária usando o algoritmo Vermelho\-Preto.  [CRBMultiMap](../../atl/reference/crbmultimap-class.md) é uma variação que permite vários valores para cada chave.  É muito `CRBTree`derivado de, e portanto compartilhamento muitos recursos com `CRBMap`.  
  
 Uma alternativa para ambos `CRBMap` e `CRBMultiMap` é oferecida pela classe de [CAtlMap](../../atl/reference/catlmap-class.md) .  Quando apenas um pequeno número de elementos precisam ser armazenados, considere usar a classe de [CSimpleMap](../../atl/reference/csimplemap-class.md) em vez de isso.  
  
 Para um exame mais completa das várias classes de coleção e seus recursos e características de desempenho, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Hierarquia de herança  
 [CRBTree](../../atl/reference/crbtree-class.md)  
  
 `CRBMap`  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Classe de CRBTree](../../atl/reference/crbtree-class.md)   
 [Classe de CAtlMap](../../atl/reference/catlmap-class.md)   
 [Classe de CRBMultiMap](../../atl/reference/crbmultimap-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)