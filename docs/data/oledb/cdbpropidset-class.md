---
title: "Classe CDBPropIDSet | Microsoft Docs"
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
  - "CDBPropIDSet"
  - "ATL.CDBPropIDSet"
  - "ATL::CDBPropIDSet"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CDBPropIDSet"
ms.assetid: 52bb806c-9581-494d-9af7-50d8a4834805
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CDBPropIDSet
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Herda da estrutura de **DBPROPIDSET** e adiciona um construtor que inicializa campo\-chave como também o método de acesso de [AddPropertyID](../../data/oledb/cdbpropidset-addpropertyid.md) .  
  
## Sintaxe  
  
```  
class CDBPropIDSet : public tagDBPROPIDSET  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[AddPropertyID](../../data/oledb/cdbpropidset-addpropertyid.md)|Adiciona uma propriedade ao conjunto de ID da propriedade.|  
|[CDBPropIDSet](../../data/oledb/cdbpropidset-cdbpropidset.md)|Construtor.|  
|[SetGUID](../Topic/CDBPropIDSet::SetGUID.md)|Define o GUID do conjunto de ID da propriedade.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador \=](../../data/oledb/cdbpropidset-operator-equal.md)|Atribui o conteúdo de uma ID de propriedade definido para outro.|  
  
## Comentários  
 Os consumidores de OLE DB usam estruturas de **DBPROPIDSET** para passar uma matriz de IDs de propriedade para que o consumidor deseja obter informações de propriedade.  As propriedades identificadas em uma única estrutura de [DBPROPIDSET](https://msdn.microsoft.com/en-us/library/ms717981.aspx) pertencem a um conjunto de propriedades.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)