---
title: "M&#233;todo AsyncBase::Start | Microsoft Docs"
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
  - "async/Microsoft::WRL::AsyncBase::Start"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Start"
ms.assetid: 67405c9d-0d1a-4c1e-8ea4-6ba01c1f90d9
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo AsyncBase::Start
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Começa uma operação assíncrona.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   Start  
)(void);  
```  
  
## Valor de retorno  
 S\_OK se o início da operação ou é iniciado; já caso contrário, E\_ILLEGAL\_STATE\_CHANGE.  
  
## Comentários  
 Start\(\) é uma implementação padrão de IAsyncInfo::Start, e não faz nenhum trabalho atual.  Para iniciar realmente uma operação assíncrona, substitua o método virtual puro de OnStart\(\) .  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)