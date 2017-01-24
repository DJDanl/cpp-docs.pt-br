---
title: "Classe de CRBMultiMap | Microsoft Docs"
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
  - "CRBMultiMap"
  - "ATL.CRBMultiMap"
  - "ATL::CRBMultiMap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CRBMultiMap"
ms.assetid: 94d3ec0c-3e30-4ab7-a101-d8da4fb8add3
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CRBMultiMap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa uma estrutura de mapeamento permite que cada chave pode ser associada com mais de um valor, usando uma árvore binária Vermelho\- Preta.  
  
## Sintaxe  
  
```  
  
      template<  
   typename K,  
   typename V,  
   class KTraits = CElementTraits< K >,  
   class VTraits = CElementTraits< V >  
> class CRBMultiMap : public CRBTree< K, V, KTraits, VTraits >  
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
|[CRBMultiMap::CRBMultiMap](../Topic/CRBMultiMap::CRBMultiMap.md)|o construtor.|  
|[CRBMultiMap::~CRBMultiMap](../Topic/CRBMultiMap::~CRBMultiMap.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRBMultiMap::FindFirstWithKey](../Topic/CRBMultiMap::FindFirstWithKey.md)|Chamar esse método para encontrar a posição do primeiro elemento com uma chave determinada.|  
|[CRBMultiMap::GetNextValueWithKey](../Topic/CRBMultiMap::GetNextValueWithKey.md)|Chamar esse método para obter o valor associado com uma chave determinada, e atualizar o valor de posição.|  
|[CRBMultiMap::GetNextWithKey](../Topic/CRBMultiMap::GetNextWithKey.md)|Chamar esse método para obter o elemento associado com uma chave determinada, e atualizar o valor de posição.|  
|[CRBMultiMap::Insert](../Topic/CRBMultiMap::Insert.md)|Chamar esse método para inserir um par do elemento no mapa.|  
|[CRBMultiMap::RemoveKey](../Topic/CRBMultiMap::RemoveKey.md)|Chamar esse método para remover todos os elementos chave\/valor para uma determinada chave.|  
  
## Comentários  
 `CRBMultiMap` fornece suporte para uma matriz de mapeamento de qualquer tipo determinado, gerenciando uma matriz ordenada de elementos chaves e valores.  A o contrário da classe de [CRBMap](../../atl/reference/crbmap-class.md) , cada chave pode ser associado com mais de um valor.  
  
 Elementos \(consistindo de uma chave e um valor\) são armazenados em uma estrutura de árvore binária, usando o método de [CRBMultiMap::Insert](../Topic/CRBMultiMap::Insert.md) .  Elementos podem ser removidos usando o método de [CRBMultiMap::RemoveKey](../Topic/CRBMultiMap::RemoveKey.md) , que exclui todos os elementos que correspondem a chave determinada.  
  
 Percorrer a árvore é se torna possível por métodos como [CRBTree::GetHeadPosition](../Topic/CRBTree::GetHeadPosition.md), [CRBTree::GetNext](../Topic/CRBTree::GetNext.md), e [CRBTree::GetNextValue](../Topic/CRBTree::GetNextValue.md).  Potencialmente acessar os vários valores por chave é possível usando os métodos de [CRBMultiMap::FindFirstWithKey](../Topic/CRBMultiMap::FindFirstWithKey.md), de [CRBMultiMap::GetNextValueWithKey](../Topic/CRBMultiMap::GetNextValueWithKey.md), e de [CRBMultiMap::GetNextWithKey](../Topic/CRBMultiMap::GetNextWithKey.md) .  Consulte o exemplo para [CRBMultiMap::CRBMultiMap](../Topic/CRBMultiMap::CRBMultiMap.md) para uma ilustração de este na prática.  
  
 Os parâmetros de `KTraits` e de `VTraits` são classes dos traços que contêm qualquer código suplementar necessário copiar ou mover elementos.  
  
 `CRBMultiMap` é derivado de [CRBTree](../../atl/reference/crbtree-class.md), que implementa uma árvore binária usando o algoritmo Vermelho\-Preto.  Uma alternativa a `CRBMultiMap` e a `CRBMap` é oferecida pela classe de [CAtlMap](../../atl/reference/catlmap-class.md) .  Quando apenas um pequeno número de elementos precisam ser armazenados, considere usar a classe de [CSimpleMap](../../atl/reference/csimplemap-class.md) em vez de isso.  
  
 Para um exame mais completa das várias classes de coleção e seus recursos e características de desempenho, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Hierarquia de herança  
 [CRBTree](../../atl/reference/crbtree-class.md)  
  
 `CRBMultiMap`  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Classe de CRBTree](../../atl/reference/crbtree-class.md)   
 [Classe de CAtlMap](../../atl/reference/catlmap-class.md)   
 [Classe de CRBMap](../../atl/reference/crbmap-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)