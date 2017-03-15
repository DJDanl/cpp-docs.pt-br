---
title: "M&#233;todo RuntimeClass::Release | Microsoft Docs"
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
  - "implements/Microsoft::WRL::RuntimeClass::Release"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método de liberação"
ms.assetid: 0bd6f9e2-ad90-4de6-adef-a6286f458cb6
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo RuntimeClass::Release
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Executa uma operação de versão do COM o objeto atual de RuntimeClass.  
  
## Sintaxe  
  
```  
STDMETHOD_(  
   ULONG,  
   Release  
)();  
```  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que declara o erro.  
  
## Comentários  
 Se a contagem de referência se tornará zero, o objeto de RuntimeClass será excluído.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe RuntimeClass](../windows/runtimeclass-class.md)