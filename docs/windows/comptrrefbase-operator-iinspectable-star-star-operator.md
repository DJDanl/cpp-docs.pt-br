---
title: "ComPtrRefBase::operator Operador IInspectable** | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "client/Microsoft::WRL::Details::ComPtrRefBase::operator IInspectable**"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador IInspectable** Operador"
ms.assetid: 06ac1051-606c-449b-a566-cac78ca53762
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ComPtrRefBase::operator Operador IInspectable**
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
operator IInspectable**() const;  
```  
  
## Comentários  
 Converte o membro de dados atual de [ptr\_](../windows/comptrrefbase-ptr-data-member.md) à ponteiro\-à\-um\-ponteiro\- à interface de IInspectable.  
  
 Um erro é emitido se o ComPtrRefBase atual não se deriva de IInspectable.  
  
 Isso converte estará disponível apenas se **\_\_WRL\_CLASSIC\_COM\_\_** é definido.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Classe ComPtrRefBase](../windows/comptrrefbase-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)