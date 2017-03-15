---
title: "Classe IGetDataSourceImpl | Microsoft Docs"
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
  - "IGetDataSourceImpl"
  - "ATL.IGetDataSourceImpl<T>"
  - "ATL.IGetDataSourceImpl"
  - "ATL::IGetDataSourceImpl"
  - "ATL::IGetDataSourceImpl<T>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe IGetDataSourceImpl"
ms.assetid: d63f3178-d663-4f01-8c09-8aab2dd6805a
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe IGetDataSourceImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma implementação do objeto de [IGetDataSource](https://msdn.microsoft.com/en-us/library/ms709721.aspx) .  
  
## Sintaxe  
  
```  
template <class T>  
class ATL_NO_VTABLE IGetDataSourceImpl : public IGetDataSource  
```  
  
#### Parâmetros  
 `T`  
 A sua classe derivada, de `IGetDataSourceImpl`.  
  
## Membros  
  
### Métodos da interface  
  
|||  
|-|-|  
|[GetDataSource](../Topic/IGetDataSourceImpl::GetDataSource.md)|Retorna um ponteiro de interface no objeto de fonte de dados que criou a sessão.|  
  
## Comentários  
 Esta é uma interface obrigatória na sessão para obter um ponteiro de interface do objeto de fonte de dados.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)