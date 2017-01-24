---
title: "PROPERTY_INFO_ENTRY | Microsoft Docs"
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
  - "PROPERTY_INFO_ENTRY"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro PROPERTY_INFO_ENTRY"
ms.assetid: f7bd23d6-52b4-4d6a-aa9a-1fca9834c8dc
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# PROPERTY_INFO_ENTRY
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma propriedade específica em um conjunto de propriedades.  
  
## Sintaxe  
  
```  
  
PROPERTY_INFO_ENTRY(  
dwPropID   
)  
  
```  
  
#### Parâmetros  
 *dwPropID*  
 \[in\] A [DBPROPID](https://msdn.microsoft.com/en-us/library/ms723882.aspx) valor que pode ser usado em conjunto com a propriedade GUID para identificar uma propriedade do conjunto.  
  
## Comentários  
 Essa macro define o valor da propriedade do tipo `DWORD` para um valor padrão definido em ATLDB. H. Para definir a propriedade como um valor de sua escolha, use [PROPERTY\_INFO\_ENTRY\_VALUE](../../data/oledb/property-info-entry-value.md). Para definir o [VARTYPE](http://msdn.microsoft.com/pt-br/317b911b-1805-402d-a9cb-159546bc88b4) e [DBPROPFLAGS](https://msdn.microsoft.com/en-us/library/ms724342.aspx) para a propriedade ao mesmo tempo, use [PROPERTY\_INFO\_ENTRY\_EX](../../data/oledb/property-info-entry-ex.md).  
  
## Exemplo  
 Consulte [BEGIN\_PROPSET\_MAP](../Topic/BEGIN_PROPSET_MAP.md).  
  
## Requisitos  
 **Cabeçalho:** atldb.h  
  
## Consulte também  
 [Macros para modelos de provedor de banco de dados OLE](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)