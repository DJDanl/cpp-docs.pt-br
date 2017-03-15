---
title: "M&#233;todo ClassFactory::QueryInterface | Microsoft Docs"
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
  - "module/Microsoft::WRL::ClassFactory::QueryInterface"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método QueryInterface"
ms.assetid: 9593881f-4585-4d70-8ca6-b328918d4d6b
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo ClassFactory::QueryInterface
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Recupera um ponteiro para a interface especificada pelo parâmetro.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   QueryInterface  
)(REFIID riid, _Deref_out_ void **ppvObject);  
```  
  
#### Parâmetros  
 `riid`  
 Uma ID de interface  
  
 `ppvObject`  
 Quando esta operação for concluída, um ponteiro para a interface especificada pelo parâmetro `riid`.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que descreve a falha.  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe ClassFactory](../windows/classfactory-class.md)