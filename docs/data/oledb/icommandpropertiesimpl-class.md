---
title: "Classe ICommandPropertiesImpl | Microsoft Docs"
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
  - "ICommandPropertiesImpl"
  - "ATL.ICommandPropertiesImpl"
  - "ATL::ICommandPropertiesImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ICommandPropertiesImpl"
ms.assetid: b3cf6aea-527e-4f0d-96e0-669178b021a2
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe ICommandPropertiesImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma implementação da interface de [ICommandProperties](https://msdn.microsoft.com/en-us/library/ms723044.aspx) .  
  
## Sintaxe  
  
```  
template <class T, class PropClass = T>  
class ATL_NO_VTABLE ICommandPropertiesImpl   
   : public ICommandProperties, public CUtlProps<PropClass>  
```  
  
#### Parâmetros  
 `T`  
 A sua classe derivada, de  
  
 `PropClass`  
 A classe de propriedades.  
  
## Membros  
  
### Métodos da interface  
  
|||  
|-|-|  
|[GetProperties](../../data/oledb/icommandpropertiesimpl-getproperties.md)|Retorna a lista de propriedades do grupo de propriedades de conjunto de linhas que são solicitadas atualmente para o conjunto de linhas.|  
|[SetProperties](../Topic/ICommandPropertiesImpl::SetProperties.md)|Define propriedades no grupo de propriedades do conjunto de linhas.|  
  
## Comentários  
 Isso é obrigatório em comandos.  A implementação é fornecida por uma função estática definida pela macro de [BEGIN\_PROPSET\_MAP](../Topic/BEGIN_PROPSET_MAP.md) .  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)