---
title: "Suporte a IDispatch e IErrorInfo | Microsoft Docs"
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
  - "IErrorInfo"
  - "IDispatch"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método ISupportErrorInfoImpl"
  - "IErrorInfo classe suppor na ATL"
  - "Classe IDispatchImpl"
  - "Suporte de classe IDispatch em ATL"
ms.assetid: 7db2220f-319d-4ce9-9382-d340019f14f7
caps.latest.revision: 16
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte a IDispatch e IErrorInfo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar a classe de modelo [IDispatchImpl](../atl/reference/idispatchimpl-class.md) para fornecer uma implementação padrão da `IDispatch Interface` parte de qualquer interface dupla em seu objeto.  
  
 Se o objeto usa o `IErrorInfo` interface para relatar erros de volta para o cliente, em seguida, o objeto deve suportar o `ISupportErrorInfo Interface` interface. A classe de modelo [ISupportErrorInfoImpl](../atl/reference/isupporterrorinfoimpl-class.md) fornece uma maneira fácil de implementar isso, se você tiver apenas uma única interface que gera erros em seu objeto.  
  
## Consulte também  
 [Fundamentos de objetos COM de ATL](../atl/fundamentals-of-atl-com-objects.md)