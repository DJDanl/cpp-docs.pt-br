---
title: "Classe IColumnsInfoImpl | Microsoft Docs"
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
  - "ATL.IColumnsInfoImpl<T>"
  - "ATL::IColumnsInfoImpl"
  - "IColumnsInfoImpl"
  - "ATL.IColumnsInfoImpl"
  - "ATL::IColumnsInfoImpl<T>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe IColumnsInfoImpl"
ms.assetid: ba74c1c5-2eda-4452-8b57-84919fa0d066
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe IColumnsInfoImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma implementação da interface de [IColumnsInfo](https://msdn.microsoft.com/en-us/library/ms724541.aspx) .  
  
## Sintaxe  
  
```  
template <class T>  
class ATL_NO_VTABLE IColumnsInfoImpl :   
   public IColumnsInfo,    
   public CDBIDOps  
```  
  
#### Parâmetros  
 `T`  
 A sua classe derivada, de `IColumnsInfoImpl`.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[GetColumnInfo](../../data/oledb/icolumnsinfoimpl-getcolumninfo.md)|Retorna os metadados da coluna necessários para a maioria dos consumidores.|  
|[MapColumnIDs](../../data/oledb/icolumnsinfoimpl-mapcolumnids.md)|Retorna uma matriz dos ordinais das colunas em um conjunto de linhas que são identificadas pelos IDs de coluna especificados.|  
  
## Comentários  
 Uma interface obrigatória em conjuntos de linhas e em comandos.  Para alterar o comportamento da implementação de `IColumnsInfo` do provedor, você precisa modificar o mapa da coluna do provedor.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)