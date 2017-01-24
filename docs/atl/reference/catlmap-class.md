---
title: "Classe de CAtlMap | Microsoft Docs"
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
  - "ATL.CAtlMap"
  - "CAtlMap"
  - "ATL::CAtlMap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlMap"
ms.assetid: 5e2fe028-8e6d-4686-93df-1433d2080ec3
caps.latest.revision: 21
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlMap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para criar e gerenciar um objeto de mapa.  
  
## Sintaxe  
  
```  
  
      template<  
   typename K,  
   typename V,  
   class KTraits = CElementTraits< K >,  
   class VTraits = CElementTraits< V >  
>  
class CAtlMap  
```  
  
#### Parâmetros  
 `K`  
 o tipo de elemento chave.  
  
 v  
 O tipo de elemento de valor.  
  
 `KTraits`  
 O código usado para copiar ou mover elementos chaves.  Consulte [classe de CElementTraits](../../atl/reference/celementtraits-class.md) para obter mais detalhes.  
  
 `VTraits`  
 O código usado para copiar ou mover elementos de valor.  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlMap::KINARGTYPE](../Topic/CAtlMap::KINARGTYPE.md)|Tipo usado quando uma chave é passada como um argumento de entrada|  
|[CAtlMap::KOUTARGTYPE](../Topic/CAtlMap::KOUTARGTYPE.md)|Tipo usado quando uma chave é retornada como um argumento de saída.|  
|[CAtlMap::VINARGTYPE](../Topic/CAtlMap::VINARGTYPE.md)|Tipo usado quando um valor é passado como um argumento de entrada.|  
|[CAtlMap::VOUTARGTYPE](../Topic/CAtlMap::VOUTARGTYPE.md)|Tipo usado quando um valor é passado como um argumento de saída.|  
  
### Classes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Classe de CAtlMap::CPair](../Topic/CAtlMap::CPair%20Class.md)|Uma classe que contém os elementos da chave e valor.|  
  
### Membros de dados de CPair  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPair::m\_key](../Topic/CAtlMap::CPair::m_key.md)|O membro de dados que armazena o elemento chave.|  
|[CPair::m\_value](../Topic/CAtlMap::CPair::m_value.md)|O membro de dados que armazena o elemento de valor.|  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlMap::CAtlMap](../Topic/CAtlMap::CAtlMap.md)|o construtor.|  
|[CAtlMap::~CAtlMap](../Topic/CAtlMap::~CAtlMap.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlMap::AssertValid](../Topic/CAtlMap::AssertValid.md)|Chamar esse método para fazer com que AFIRMAR se `CAtlMap` é inválido.|  
|[CAtlMap::DisableAutoRehash](../Topic/CAtlMap::DisableAutoRehash.md)|Chamar esse método para desativar repita automático do objeto de `CAtlMap` .|  
|[CAtlMap::EnableAutoRehash](../Topic/CAtlMap::EnableAutoRehash.md)|Chamar esse método para ativar repita automático do objeto de `CAtlMap` .|  
|[CAtlMap::GetAt](../Topic/CAtlMap::GetAt.md)|Chamar esse método para retornar o elemento em uma posição especificada no mapa.|  
|[CAtlMap::GetCount](../Topic/CAtlMap::GetCount.md)|Chamar esse método para recuperar o número de elementos no mapa.|  
|[CAtlMap::GetHashTableSize](../Topic/CAtlMap::GetHashTableSize.md)|Chamar esse método para determinar o número de compartimentos no hash do mapa \- tabela.|  
|[CAtlMap::GetKeyAt](../Topic/CAtlMap::GetKeyAt.md)|Chamar esse método para recuperar a chave armazenada na posição determinada no objeto de `CAtlMap` .|  
|[CAtlMap::GetNext](../Topic/CAtlMap::GetNext.md)|Chamar esse método para obter um ponteiro para os seguintes pares do elemento armazenados no objeto de `CAtlMap` .|  
|[CAtlMap::GetNextAssoc](../Topic/CAtlMap::GetNextAssoc.md)|Obtém o próximo elemento para iterar.|  
|[CAtlMap::GetNextKey](../Topic/CAtlMap::GetNextKey.md)|Chamar esse método para recuperar a próxima chave do objeto de `CAtlMap` .|  
|[CAtlMap::GetNextValue](../Topic/CAtlMap::GetNextValue.md)|Chamar esse método para obter o valor do objeto de `CAtlMap` seguir.|  
|[CAtlMap::GetStartPosition](../Topic/CAtlMap::GetStartPosition.md)|Chamar esse método para iniciar uma iteração de mapa.|  
|[CAtlMap::GetValueAt](../Topic/CAtlMap::GetValueAt.md)|Chamar esse método para recuperar o valor armazenado em uma determinada posição no objeto de `CAtlMap` .|  
|[CAtlMap::InitHashTable](../Topic/CAtlMap::InitHashTable.md)|Chamar esse método para inicializar o tabela de hash.|  
|[CAtlMap::IsEmpty](../Topic/CAtlMap::IsEmpty.md)|Chamar esse método para testar um objeto de mapa vazia.|  
|[CAtlMap::Lookup](../Topic/CAtlMap::Lookup.md)|Chamar esse método para pesquisar chaves ou valores no objeto de `CAtlMap` .|  
|[CAtlMap::Rehash](../Topic/CAtlMap::Rehash.md)|Chamar esse método para repetir o objeto de `CAtlMap` .|  
|[CAtlMap::RemoveAll](../Topic/CAtlMap::RemoveAll.md)|Chamar esse método para remover todos os elementos de objeto de `CAtlMap` .|  
|[CAtlMap::RemoveAtPos](../Topic/CAtlMap::RemoveAtPos.md)|Chamar esse método para remover o elemento na posição determinada no objeto de `CAtlMap` .|  
|[CAtlMap::RemoveKey](../Topic/CAtlMap::RemoveKey.md)|Chamar esse método para remover um elemento de objeto de `CAtlMap` , usando a chave.|  
|[CAtlMap::SetAt](../Topic/CAtlMap::SetAt.md)|Chamar esse método para inserir um par do elemento no mapa.|  
|[CAtlMap::SetOptimalLoad](../Topic/CAtlMap::SetOptimalLoad.md)|Chamar esse método para definir a carga ideal do objeto de `CAtlMap` .|  
|[CAtlMap::SetValueAt](../Topic/CAtlMap::SetValueAt.md)|Chamar esse método para alterar o valor armazenado em uma determinada posição no objeto de `CAtlMap` .|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlMap::operator](../Topic/CAtlMap::operator.md)|Substitui ou adiciona um novo elemento a `CAtlMap`.|  
  
## Comentários  
 `CAtlMap` fornece suporte para uma matriz de mapeamento de qualquer tipo determinado, gerenciando uma matriz não ordenada de chaves elementos e seus valores associados.  Elementos \(consistindo de uma chave e um valor\) são armazenados usando um algoritmo de hash, permitindo que uma grande quantidade de dados com eficiência é armazenada e recuperadas.  
  
 Os parâmetros de `KTraits` e de `VTraits` são classes dos traços que contêm qualquer código suplementar necessário copiar ou mover elementos.  
  
 Uma alternativa a `CAtlMap` é oferecida pela classe de [CRBMap](../../atl/reference/crbmap-class.md) .  `CRBMap` armazena pares chave\/valor também, mas diferentes características de desempenho das visualizações.  O tempo tirados para inserir um item, para pesquisar uma chave, ou para excluir uma chave de um objeto de `CRBMap` são *de log do pedido \(em\)* *em* , onde é o número de elementos.  Para `CAtlMap`, todas essas operações normalmente assumem um tempo constantes, embora os piores de hipotéticos podem ser de pedido *. Em.* Portanto, no caso `CAtlMap` típicos, é mais rápido.  
  
 Outra diferença entre `CRBMap` e `CAtlMap` torna\-se aparente para percorrer os elementos armazenados.  Em `CRBMap`, os elementos são visitados em uma ordem classificada.  Em `CAtlMap`, os elementos não são ordenados, e nenhum pedido pode ser inferido.  
  
 Quando um pequeno número de elementos precisam ser armazenados, considere usar a classe de [CSimpleMap](../../atl/reference/csimplemap-class.md) em vez de isso.  
  
 Para obter mais informações, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Exemplo de famoso](../../top/visual-cpp-samples.md)   
 [exemplo de UpdatePV](../../top/visual-cpp-samples.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)