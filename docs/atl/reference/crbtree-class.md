---
title: "Classe de CRBTree | Microsoft Docs"
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
  - "ATL.CRBTree"
  - "CRBTree"
  - "ATL::CRBTree"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CRBTree"
ms.assetid: a1b1cb63-38e4-4fc2-bb28-f774d1721760
caps.latest.revision: 18
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CRBTree
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para criar e utilizar uma árvore Vermelho\- Preta.  
  
## Sintaxe  
  
```  
  
      template<  
   typename K,  
   typename V,  
   class KTraits = CElementTraits< K >,  
   class VTraits = CElementTraits< V >  
> class CRBTree  
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
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRBTree::KINARGTYPE](../Topic/CRBTree::KINARGTYPE.md)|Digite usado quando uma chave é passada como um argumento de entrada.|  
|[CRBTree::KOUTARGTYPE](../Topic/CRBTree::KOUTARGTYPE.md)|Tipo usado quando uma chave é retornada como um argumento de saída.|  
|[CRBTree::VINARGTYPE](../Topic/CRBTree::VINARGTYPE.md)|Tipo usado quando um valor é passado como um argumento de entrada.|  
|[CRBTree::VOUTARGTYPE](../Topic/CRBTree::VOUTARGTYPE.md)|Tipo usado quando um valor é passado como um argumento de saída.|  
  
### Classes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Classe de CRBTree::CPair](../Topic/CRBTree::CPair%20Class.md)|Uma classe que contém os elementos da chave e valor.|  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRBTree::~CRBTree](../Topic/CRBTree::~CRBTree.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRBTree::FindFirstKeyAfter](../Topic/CRBTree::FindFirstKeyAfter.md)|Chamar esse método para encontrar a posição do elemento que usa a chave disponível a seguir.|  
|[CRBTree::GetAt](../Topic/CRBTree::GetAt.md)|Chamar esse método para obter o elemento em uma determinada posição na árvore.|  
|[CRBTree::GetCount](../Topic/CRBTree::GetCount.md)|Chamar esse método para obter o número de elementos na árvore.|  
|[CRBTree::GetHeadPosition](../Topic/CRBTree::GetHeadPosition.md)|Chamar esse método para obter o valor da posição do elemento no início da árvore.|  
|[CRBTree::GetKeyAt](../Topic/CRBTree::GetKeyAt.md)|Chamar esse método para obter a chave de uma determinada posição na árvore.|  
|[CRBTree::GetNext](../Topic/CRBTree::GetNext.md)|Chamar esse método para obter um ponteiro para um elemento armazenado no objeto de `CRBTree` , e em seguida a posição para o próximo elemento.|  
|[CRBTree::GetNextAssoc](../Topic/CRBTree::GetNextAssoc.md)|Chamar esse método para obter a chave e o valor de um elemento armazenado no mapa e a posição para ir para o próximo elemento.|  
|[CRBTree::GetNextKey](../Topic/CRBTree::GetNextKey.md)|Chamar esse método para obter a chave de um elemento armazenado na árvore de e para avançar a posição para o próximo elemento.|  
|[CRBTree::GetNextValue](../Topic/CRBTree::GetNextValue.md)|Chamar esse método para obter o valor de um elemento armazenado na árvore de e para avançar a posição para o próximo elemento.|  
|[CRBTree::GetPrev](../Topic/CRBTree::GetPrev.md)|Chamar esse método para obter um ponteiro para um elemento armazenado no objeto de `CRBTree` , e atualizar a posição ao elemento anterior.|  
|[CRBTree::GetTailPosition](../Topic/CRBTree::GetTailPosition.md)|Chamar esse método para obter o valor da posição do elemento na parte final da árvore.|  
|[CRBTree::GetValueAt](../Topic/CRBTree::GetValueAt.md)|Chamar esse método para recuperar o valor armazenado em uma determinada posição no objeto de `CRBTree` .|  
|[CRBTree::IsEmpty](../Topic/CRBTree::IsEmpty.md)|Chamar esse método para testar um objeto vazio da árvore.|  
|[CRBTree::RemoveAll](../Topic/CRBTree::RemoveAll.md)|Chamar esse método para remover todos os elementos de objeto de **CRBTree** .|  
|[CRBTree::RemoveAt](../Topic/CRBTree::RemoveAt.md)|Chamar esse método para remover o elemento na posição determinada no objeto de **CRBTree** .|  
|[CRBTree::SetValueAt](../Topic/CRBTree::SetValueAt.md)|Chamar esse método para alterar o valor armazenado em uma determinada posição no objeto de `CRBTree` .|  
  
## Comentários  
 Uma árvore Vermelho\- Preta é uma árvore de busca binária que usa um bit adicional de informações pelo nó para garantir que permanece equilibrado “,” isto é, a altura da árvore não aumenta desproporcionalmente grande e não afeta o desempenho.  
  
 Esta classe de modelo destina\-se a ser usada por [CRBMap](../../atl/reference/crbmap-class.md) e por [CRBMultiMap](../../atl/reference/crbmultimap-class.md).  O volume dos métodos que compõem essas classes derivadas é fornecido por `CRBTree`.  
  
 Para um exame mais completa das várias classes de coleção e seus recursos e características de desempenho, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)