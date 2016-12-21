---
title: "Classe ISessionPropertiesImpl | Microsoft Docs"
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
  - "ISessionPropertiesImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ISessionPropertiesImpl"
ms.assetid: ca0ba254-c7dc-4c52-abec-cf895a0c6a63
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe ISessionPropertiesImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma implementação da interface de [ISessionProperties](https://msdn.microsoft.com/en-us/library/ms713721.aspx) .  
  
## Sintaxe  
  
```  
template <class T, class PropClass = T>  
class ATL_NO_VTABLE ISessionPropertiesImpl :  
   public ISessionProperties,    
   public CUtlProps<PropClass>  
```  
  
#### Parâmetros  
 `T`  
 A sua classe derivada, de `ISessionPropertiesImpl`.  
  
 `PropClass`  
 Uma classe da propriedade usuário definível que usa como padrão `T`.  
  
## Membros  
  
### Métodos da interface  
  
|||  
|-|-|  
|[GetProperties](../../data/oledb/isessionpropertiesimpl-getproperties.md)|Retorna a lista de propriedades no grupo de propriedades de sessão que são definidas atualmente na sessão.|  
|[SetProperties](../../data/oledb/isessionpropertiesimpl-setproperties.md)|Define propriedades no grupo de propriedades de sessão.|  
  
## Comentários  
 Uma interface obrigatória em sessões.  Esta classe implementa propriedades de sessão chama uma função estática definida por [o conjunto de propriedades](../Topic/BEGIN_PROPSET_MAP.md).  O mapa do conjunto de propriedades deve ser especificado em sua classe da sessão.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)