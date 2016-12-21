---
title: "BEGIN_PROVIDER_COLUMN_MAP | Microsoft Docs"
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
  - "BEGIN_PROVIDER_COLUMN_MAP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro BEGIN_PROVIDER_COLUMN_MAP"
ms.assetid: 506b8c0f-6be9-4c97-ba81-c4b7f7d428fa
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# BEGIN_PROVIDER_COLUMN_MAP
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Marca o início das entradas da coluna do provedor.  
  
## Sintaxe  
  
```  
  
BEGIN_PROVIDER_COLUMN_MAP(  
theClass   
)  
  
```  
  
#### Parâmetros  
 `theClass`  
 \[in\] o nome da classe esse mapa pertence.  
  
## Exemplo  
 Aqui está um mapa de exemplo da coluna do provedor:  
  
 [!CODE [NVC_OLEDB_Provider#4](../CodeSnippet/VS_Snippets_Cpp/NVC_OLEDB_Provider#4)]  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Macros para modelos de provedor de banco de dados OLE](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)