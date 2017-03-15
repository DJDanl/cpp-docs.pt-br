---
title: "M&#233;todo HStringReference::CopyTo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
ms.assetid: 179d9b14-1ced-4b16-b297-19ca1e92a462
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo HStringReference::CopyTo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Copia o objeto HStringReference atual para um objeto HSTRING.  
  
## Sintaxe  
  
```  
  
HRESULT CopyTo(  
   _Out_ HSTRING *str  
   ) const throw();  
```  
  
#### Parâmetros  
 `str`  
 O HSTRING que recebe a cópia.  
  
## Comentários  
 Este método chama a função [WindowsDuplicateString](http://msdn.microsoft.com/library/br224634.aspx).  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HStringReference](../windows/hstringreference-class.md)