---
title: "PROPERTY_INFO_ENTRY_VALUE | Microsoft Docs"
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
  - "PROPERTY_INFO_ENTRY_VALUE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro PROPERTY_INFO_ENTRY_VALUE"
ms.assetid: 9690f7f3-fb20-4a7e-a75f-8a3a1cb1ce0d
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# PROPERTY_INFO_ENTRY_VALUE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma propriedade específica em um conjunto de propriedades.  
  
## Sintaxe  
  
```  
  
PROPERTY_INFO_ENTRY_VALUE(  
dwPropID  
, value )  
```  
  
#### Parâmetros  
 *dwPropID*  
 \[in\] valor de [DBPROPID](https://msdn.microsoft.com/en-us/library/ms723882.aspx) que pode ser usado junto com o GUID do conjunto de propriedades para identificar uma propriedade.  
  
 *valor*  
 \[in\] o valor da propriedade do tipo `DWORD`.  
  
## Comentários  
 Com esta macro, você pode especificar diretamente o valor da propriedade do tipo `DWORD`.  Para definir a propriedade para o valor padrão definido em ATLDB.H, use [PROPERTY\_INFORMATION\_ENTRY](../../data/oledb/property-info-entry.md).  Para definir o valor, os sinalizadores, e as opções para a propriedade, use [PROPERTY\_INFORMATION\_ENTRY\_EX](../../data/oledb/property-info-entry-ex.md).  
  
## Exemplo  
 Consulte [BEGIN\_PROPSET\_MAP](../Topic/BEGIN_PROPSET_MAP.md).  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Macros para modelos de provedor de banco de dados OLE](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)