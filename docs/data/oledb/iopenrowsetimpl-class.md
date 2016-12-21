---
title: "Classe IOpenRowsetImpl | Microsoft Docs"
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
  - "IOpenRowsetImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe IOpenRowsetImpl"
ms.assetid: d259cedc-1db4-41cf-bc9f-5030907ab486
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe IOpenRowsetImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a implementação da interface de `IOpenRowset` .  
  
## Sintaxe  
  
```  
template <class SessionClass>  
class IOpenRowsetImpl : public IOpenRowset  
```  
  
#### Parâmetros  
 `SessionClass`  
 A sua classe derivada, de `IOpenRowsetImpl`.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[CreateRowset](../../data/oledb/iopenrowsetimpl-createrowset.md)|Cria um objeto de conjunto de linhas.  Não chamado diretamente pelo usuário.|  
|[OpenRowset](../Topic/IOpenRowsetImpl::OpenRowset.md)|Abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela ou índice base. \(Não em ATLDB.H\)|  
  
## Comentários  
 A interface de [IOpenRowset](https://msdn.microsoft.com/en-us/library/ms716946.aspx) é obrigatória para um objeto de sessão.  Abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela ou índice base.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)