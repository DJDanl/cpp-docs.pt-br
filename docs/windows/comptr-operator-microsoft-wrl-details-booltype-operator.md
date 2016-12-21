---
title: "ComPtr::operator Microsoft::WRL::Details::BoolType Operador | Microsoft Docs"
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
ms.assetid: cfba6521-fb30-4fb8-afb2-cfab1cb5e0b8
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ComPtr::operator Microsoft::WRL::Details::BoolType Operador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica se um ComPtr está gerenciando o tempo de vida do objeto de uma interface.  
  
## Sintaxe  
  
```  
WRL_NOTHROW operator Microsoft::WRL::Details::BoolType() const;  
```  
  
## Valor de retorno  
 Se uma interface é associada a este ComPtr, o endereço do membro de dados de [BoolStruct::Member](../Topic/BoolStruct::Member%20Data%20Member.md) ; caso contrário, `nullptr`.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)   
 [Método ComPtr::Get](../windows/comptr-get-method.md)