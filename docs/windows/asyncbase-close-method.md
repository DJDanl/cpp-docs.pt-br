---
title: "M&#233;todo AsyncBase::Close | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncBase::Close"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Close"
ms.assetid: a52b1124-754b-4393-b491-64aae0c22f1c
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::Close
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fecha a operação assíncrona.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   Close  
)(void) override;  
```  
  
## Valor de retorno  
 S\_OK se a operação fecha ou é fechada; já caso contrário, E\_ILLEGAL\_STATE\_CHANGE.  
  
## Comentários  
 Close\(\) é uma implementação padrão de IAsyncInfo::Close, e não faz nenhum trabalho atual.  Para fechar de fato uma operação assíncrona, substitua o método virtual puro de OnClose\(\) .  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)