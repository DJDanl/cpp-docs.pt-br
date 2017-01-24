---
title: "Classe DontUseNewUseMake | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::DontUseNewUseMake"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe DontUseNewUseMake"
ms.assetid: 8b38d07b-fc14-4cea-afb9-4c1a7dde0093
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe DontUseNewUseMake
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
class DontUseNewUseMake;  
```  
  
## Comentários  
 Impede usando o operador `new` em RuntimeClass.  Em virtude disso, você deve usar [Crie a função](../windows/make-function.md) em vez disso.  
  
## Membros  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[DontUseNewUseMake::operator Operador new](../windows/dontusenewusemake-operator-new-operator.md)|Sobrecarregar o operador `new` e impede que seja usado em RuntimeClass.|  
  
## Hierarquia de Herança  
 `DontUseNewUseMake`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)   
 [Função Make](../windows/make-function.md)