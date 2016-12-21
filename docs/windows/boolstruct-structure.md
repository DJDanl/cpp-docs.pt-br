---
title: "Estrutura BoolStruct | Microsoft Docs"
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
  - "internal/Microsoft::WRL::Details::BoolStruct"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura BoolStruct"
ms.assetid: 666eae78-e81d-4fb7-a9e4-1ba617d6d4cd
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura BoolStruct
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
struct BoolStruct;  
```  
  
## Comentários  
 A estrutura de BoolStruct define se um ComPtr está gerenciando o tempo de vida do objeto de uma interface.  BoolStruct é usado internamente pelo operador de [BoolType \(\)](../windows/comptr-operator-microsoft-wrl-details-booltype-operator.md) .  
  
## Membros  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados BoolStruct::Member](../Topic/BoolStruct::Member%20Data%20Member.md)|Especifica que [ComPtr](../windows/comptr-class.md) é, ou não for, gerenciando o tempo de vida do objeto de uma interface.|  
  
## Hierarquia de Herança  
 `BoolStruct`  
  
## Requisitos  
 **Cabeçalho:** internal.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)   
 [ComPtr::operator Microsoft::WRL::Details::BoolType Operador](../windows/comptr-operator-microsoft-wrl-details-booltype-operator.md)