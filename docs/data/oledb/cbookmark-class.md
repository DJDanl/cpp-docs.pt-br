---
title: "Classe CBookmark | Microsoft Docs"
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
  - "ATL.CBookmark"
  - "ATL::CBookmark<nSize>"
  - "CBookmark"
  - "ATL.CBookmark<nSize>"
  - "ATL::CBookmark"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CBookmark"
ms.assetid: bc942f95-6f93-41d9-bb6e-bcdae4ae0b7a
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CBookmark
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Contém um valor indicador no buffer.  
  
## Sintaxe  
  
```  
template < DBLENGTH nSize = 0 >  
class CBookmark : public CBookmarkBase  
template < >  
class CBookmark< 0 > : public CBookmarkBase  
```  
  
#### Parâmetros  
 `nSize`  
 O tamanho do buffer do medidor em bytes.  Quando `nSize` for zero, o buffer do medidor será criado dinamicamente em tempo de execução.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[CBookmark](../../data/oledb/cbookmark-class.md)|O construtor|  
|[GetBuffer](../../data/oledb/cbookmark-getbuffer.md)|Recupera o ponteiro para o buffer.|  
|[GetSize](../../data/oledb/cbookmark-getsize.md)|Recupera o tamanho do buffer em bytes.|  
|[SetBookmark](../../data/oledb/cbookmark-setbookmark.md)|Define o valor do medidor.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador \=](../../data/oledb/cbookmark-operator-equal.md)|Atribui uma classe de `CBookmark` a outra.|  
  
## Comentários  
 **CBookmark\<0\>** é uma especialização do modelo de `CBookmark`; o buffer é criado dinamicamente em tempo de execução.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)