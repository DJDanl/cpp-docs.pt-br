---
title: "CAccessorBase::ReleaseAccessors | Microsoft Docs"
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
  - "CAccessorBase::ReleaseAccessors"
  - "CAccessorBase.ReleaseAccessors"
  - "ReleaseAccessors"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método ReleaseAccessors"
ms.assetid: f08bc88e-0552-4a9c-9c65-b4061094649a
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CAccessorBase::ReleaseAccessors
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Libera os acessadores criados pela classe.  
  
## Sintaxe  
  
```  
  
      HRESULT ReleaseAccessors(  
   IUnknown* pUnk   
);  
```  
  
#### Parâmetros  
 *punk*  
 \[in\] ponteiro da interface de **IUnknown** para o objeto COM para que os acessadores foram criados.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Chamado de [CAccessorRowset::Close](../Topic/CAccessorRowset::Close.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CAccessorBase](../../data/oledb/caccessorbase-class.md)