---
title: "Classe CUtlProps | Microsoft Docs"
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
  - "CUtlProps"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CUtlProps"
ms.assetid: bb525178-765c-4e23-a110-c0fd70c05437
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CUtlProps
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As propriedades das ferramentas para uma variedade de propriedade OLE DB interface \(por exemplo, `IDBProperties`, `IDBProperties`, e `IRowsetInfo`\).  
  
## Sintaxe  
  
```  
template < class T >  
class ATL_NO_VTABLE CUtlProps : public CUtlPropsBase  
```  
  
#### Parâmetros  
 `T`  
 A classe que contém `BEGIN_PROPSET_MAP`.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[GetPropValue](../Topic/CUtlProps::GetPropValue.md)|Obtém uma propriedade de um conjunto de propriedades.|  
|[IsValidValue](../../data/oledb/cutlprops-isvalidvalue.md)|Usado para validar um valor antes de definir uma propriedade.|  
|[OnInterfaceRequested](../../data/oledb/cutlprops-oninterfacerequested.md)|Trata solicitações para uma interface opcional quando um consumidor chama um método em uma interface de criação do objeto.|  
|[OnPropertyChanged](../../data/oledb/cutlprops-onpropertychanged.md)|Chamado depois de definir uma propriedade para tratar encadeou propriedades.|  
|[SetPropValue](../../data/oledb/cutlprops-setpropvalue.md)|Define uma propriedade em um conjunto de propriedades.|  
  
## Comentários  
 A maioria desta classe é um detalhes de implementação.  
  
 `CUtlProps` contém dois membros para definir propriedades internamente: [GetPropValue](../Topic/CUtlProps::GetPropValue.md) e [SetPropValue](../../data/oledb/cutlprops-setpropvalue.md).  
  
 Para obter mais informações sobre macros usados em um mapa do conjunto de propriedades, consulte [BEGIN\_PROPSET\_MAP](../Topic/BEGIN_PROPSET_MAP.md) e [END\_PROPSET\_MAP](../../data/oledb/end-propset-map.md).  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)