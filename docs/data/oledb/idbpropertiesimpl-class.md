---
title: "Classe IDBPropertiesImpl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "IDBPropertiesImpl"
  - "ATL.IDBPropertiesImpl"
  - "ATL.IDBPropertiesImpl<T>"
  - "ATL::IDBPropertiesImpl<T>"
  - "ATL::IDBPropertiesImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe IDBPropertiesImpl"
ms.assetid: a7f15a8b-95b2-4316-b944-d5d03f8d74ab
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe IDBPropertiesImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma implementação da interface de `IDBProperties` .  
  
## Sintaxe  
  
```  
template <class T>   
class ATL_NO_VTABLE IDBPropertiesImpl   
   : public IDBProperties, public CUtlProps<T>  
```  
  
#### Parâmetros  
 `T`  
 A sua classe derivada, de `IDBPropertiesImpl`.  
  
## Membros  
  
### Métodos da interface  
  
|||  
|-|-|  
|[GetProperties](../../data/oledb/idbpropertiesimpl-getproperties.md)|Retorna os valores das propriedades nos grupos de propriedades de fonte de dados, de informações da fonte de dados, e inicialização definidas atualmente no objeto de fonte de dados ou os valores das propriedades no grupo de propriedades de inicialização que são definidas atualmente no enumerador.|  
|[GetPropertyInfo](../../data/oledb/idbpropertiesimpl-getpropertyinfo.md)|Retorna informações sobre todas as propriedades suportadas pelo provedor.|  
|[SetProperties](../../data/oledb/idbpropertiesimpl-setproperties.md)|Define propriedades grupos na propriedade da fonte de dados e a inicialização, para objetos de fonte de dados, ou o grupo de propriedades de inicialização, para enumeradores.|  
  
## Comentários  
 [IDBProperties](https://msdn.microsoft.com/en-us/library/ms719607.aspx) é uma interface obrigatória para objetos de fonte de dados e uma interface opcional para enumeradores.  No entanto, se expõe um enumerador [IDBInitialize](https://msdn.microsoft.com/en-us/library/ms713706.aspx), deve expor `IDBProperties`.  implementa `IDBProperties` de`IDBPropertiesImpl` usando uma função estática definida por [BEGIN\_PROPSET\_MAP](../Topic/BEGIN_PROPSET_MAP.md).  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)