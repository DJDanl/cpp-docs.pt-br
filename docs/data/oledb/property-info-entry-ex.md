---
title: "PROPERTY_INFO_ENTRY_EX | Microsoft Docs"
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
  - "PROPERTY_INFO_ENTRY_EX"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro PROPERTY_INFO_ENTRY_EX"
ms.assetid: af32dfcd-4c50-449d-af3b-48d21bd67a04
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# PROPERTY_INFO_ENTRY_EX
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma propriedade específica em um conjunto de propriedades.  
  
## Sintaxe  
  
```  
  
PROPERTY_INFO_ENTRY_EX(  
dwPropID  
,  
vt  
,  
dwFlags  
,  
value  
,  
options  
)  
  
```  
  
#### Parâmetros  
 *dwPropID*  
 \[in\] A [DBPROPID](https://msdn.microsoft.com/en-us/library/ms723882.aspx) valor que pode ser usado em conjunto com a propriedade GUID para identificar uma propriedade do conjunto.  
  
 *VT*  
 \[in\] O [VARTYPE](http://msdn.microsoft.com/pt-br/317b911b-1805-402d-a9cb-159546bc88b4) dessa entrada de propriedade.  
  
 `dwFlags`  
 \[in\] A [DBPROPFLAGS](https://msdn.microsoft.com/en-us/library/ms724342.aspx) valor que descreve esta entrada de propriedade.  
  
 *Valor*  
 \[in\] O valor da propriedade do tipo `DWORD`.  
  
 `options`  
 O **DBPROPOPTIONS\_REQUIRED** ou **DBPROPOPTIONS\_SETIFCHEAP**. Normalmente, um provedor não precisa definir `options` como ele é definido pelo consumidor.  
  
## Comentários  
 Com essa macro, você pode especificar diretamente o valor da propriedade do tipo `DWORD` bem como opções e sinalizadores. Simplesmente definir uma propriedade para um valor padrão definido em ATLDB. H, use [PROPERTY\_INFO\_ENTRY](../../data/oledb/property-info-entry.md). Para definir uma propriedade com um valor de sua escolha, sem opções de configuração ou sinalizadores, use [PROPERTY\_INFO\_ENTRY\_VALUE](../../data/oledb/property-info-entry-value.md).  
  
## Exemplo  
 Consulte [BEGIN\_PROPSET\_MAP](../Topic/BEGIN_PROPSET_MAP.md).  
  
## Requisitos  
 **Cabeçalho:** atldb.h  
  
## Consulte também  
 [Macros para modelos de provedor de banco de dados OLE](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)