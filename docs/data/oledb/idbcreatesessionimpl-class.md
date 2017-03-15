---
title: "Classe IDBCreateSessionImpl | Microsoft Docs"
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
  - "IDBCreateSessionImpl"
  - "ATL.IDBCreateSessionImpl"
  - "ATL::IDBCreateSessionImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe IDBCreateSessionImpl"
ms.assetid: 48c02c5c-8362-45ac-af8e-bb119cf8c5c7
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe IDBCreateSessionImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma implementação da interface de [IDBCreateSession](https://msdn.microsoft.com/en-us/library/ms724076.aspx) .  
  
## Sintaxe  
  
```  
template <class T, class SessionClass>  
class ATL_NO_VTABLE IDBCreateSessionImpl   
   : public IDBCreateSession  
```  
  
#### Parâmetros  
 `T`  
 HIS CLASS, DERIVADO FROM  
  
 `SessionClass`  
 O objeto de sessão.  
  
## Membros  
  
### Métodos da interface  
  
|||  
|-|-|  
|[CreateSession](../../data/oledb/idbcreatesessionimpl-createsession.md)|Cria uma nova sessão do objeto de fonte de dados e retorna a interface solicitada na sessão recém\-criada.|  
  
## Comentários  
 Uma interface obrigatória em objetos de fonte de dados.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)