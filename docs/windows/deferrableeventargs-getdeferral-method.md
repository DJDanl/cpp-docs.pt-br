---
title: "M&#233;todo DeferrableEventArgs::GetDeferral | Microsoft Docs"
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
ms.assetid: ef6dc7c5-b0be-4b85-8507-d3fd97f2185d
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo DeferrableEventArgs::GetDeferral
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém uma referência para o [adiamento](http://go.microsoft.com/fwlink/?LinkId=526520) objeto que representa um evento adiado.  
  
## Sintaxe  
  
```cpp  
HRESULT GetDeferral([out, retval] Windows::Foundation::IDeferral** result)  
```  
  
#### Parâmetros  
 `result`  
 Um ponteiro que fará referência a [adiamento](http://go.microsoft.com/fwlink/?LinkId=526520) objeto quando a chamada é concluída.  
  
## Valor de retorno  
 S\_OK se for bem\-sucedida; Caso contrário, um HRESULT que indica o erro.  
  
## Comentários  
 Para obter um exemplo de código, consulte [Classe DeferrableEventArgs](../windows/deferrableeventargs-class.md).  
  
## Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl  
  
## Consulte também  
 [Classe DeferrableEventArgs](../windows/deferrableeventargs-class.md)