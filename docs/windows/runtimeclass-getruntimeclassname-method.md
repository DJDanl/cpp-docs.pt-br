---
title: "M&#233;todo RuntimeClass::GetRuntimeClassName | Microsoft Docs"
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
  - "implements/Microsoft::WRL::RuntimeClass::GetRuntimeClassName"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetRuntimeClassName"
ms.assetid: f6388163-fe65-4948-a4bc-ae6826f480e7
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo RuntimeClass::GetRuntimeClassName
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém o nome da classe de tempo de execução do objeto atual de RuntimeClass.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   GetRuntimeClassName  
)(_Out_ HSTRING* runtimeName);  
```  
  
## Parâmetros  
 `runtimeName`  
 Quando esta operação concluir, o nome da classe de tempo de execução.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que declara o erro.  
  
## Comentários  
 Um erro de afirmar é emitido se o \_\_WRL\_FORCE\_INSPECTABLE\_CLASS\_MACRO de \_\_WRL\_STRICT\_\_or não é definido.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe RuntimeClass](../windows/runtimeclass-class.md)