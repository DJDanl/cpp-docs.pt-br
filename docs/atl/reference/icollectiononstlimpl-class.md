---
title: "Classe de ICollectionOnSTLImpl | Microsoft Docs"
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
  - "ATL.ICollectionOnSTLImpl"
  - "ATL::ICollectionOnSTLImpl"
  - "ICollectionOnSTLImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de ICollectionOnSTLImpl"
ms.assetid: 683c88b0-0d97-4779-a762-e493334ba7f9
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de ICollectionOnSTLImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece os métodos usados por uma classe de coleção.  
  
## Sintaxe  
  
```  
  
      template <  
   class T,  
   class CollType,  
   class ItemType,  
   class CopyItem,  
   class EnumType  
>  
class ICollectionOnSTLImpl :  
   public T  
```  
  
#### Parâmetros  
 `T`  
 Uma interface de coleção COM.  
  
 `CollType`  
 Uma classe do contêiner de STL.  
  
 *ItemType*  
 O tipo de item exposto pela interface do recipiente.  
  
 *CopyItem*  
 [classe de diretiva de impressão](../Topic/ATL%20Copy%20Policy%20Classes.md).  
  
 *EnumType*  
 [CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md)\- classe compatível do enumerador.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[ICollectionOnSTLImpl::get\_\_NewEnum](../Topic/ICollectionOnSTLImpl::get__NewEnum.md)|Retorna um objeto enumerator para a coleção.|  
|[ICollectionOnSTLImpl::get\_Count](../Topic/ICollectionOnSTLImpl::get_Count.md)|Retorna o número de elementos na coleção.|  
|[ICollectionOnSTLImpl::get\_Item](../Topic/ICollectionOnSTLImpl::get_Item.md)|Retorna o item solicitado a coleção.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[ICollectionOnSTLImpl::m\_coll](../Topic/ICollectionOnSTLImpl::m_coll.md)|a coleção.|  
  
## Comentários  
 Essa classe fornece a implementação para três métodos de uma interface de coleção: [get\_Count](../Topic/ICollectionOnSTLImpl::get_Count.md), [get\_Item](../Topic/ICollectionOnSTLImpl::get_Item.md), e [get\_\_NewEnum](../Topic/ICollectionOnSTLImpl::get__NewEnum.md).  
  
 Para usar esta classe:  
  
-   Defina \(ou empréstimo\) uma interface de coleção que você deseja implementar.  
  
-   A classe deriva de uma especialização de `ICollectionOnSTLImpl` com base em esta interface de coleção.  
  
-   Use a classe derivada para implementar todos os métodos de interface da coleção não tratada por `ICollectionOnSTLImpl`.  
  
> [!NOTE]
>  Se a interface de coleção é uma interface dupla, derive da classe [IDispatchImpl](../../atl/reference/idispatchimpl-class.md), passando a especialização de `ICollectionOnSTLImpl` como o primeiro parâmetro do modelo se você deseja ATL para fornecer a implementação dos métodos de `IDispatch` .  
  
-   Adicionar itens ao membro de [m\_coll](../Topic/ICollectionOnSTLImpl::m_coll.md) para preencher a coleção.  
  
 Para mais informações e exemplos, consulte [coleções e enumeradores de ATL](../../atl/atl-collections-and-enumerators.md).  
  
## Hierarquia de herança  
 `T`  
  
 `ICollectionOnSTLImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [exemplo de ATLCollections](../../top/visual-cpp-samples.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)