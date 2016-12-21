---
title: "Classe unorm | Microsoft Docs"
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
  - "amp_short_vectors/Concurrency::graphics::unorm"
  - "amp/Concurrency::graphics::unorm"
dev_langs: 
  - "C++"
ms.assetid: bc30bd20-6452-4d5f-9158-3b11c4c16ed2
caps.latest.revision: 8
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe unorm
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Representa um número unorm.  Cada elemento é um número de ponto flutuante no intervalo de \[0.0f, 1.0f\].  
  
## Sintaxe  
  
```  
class unorm;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor unorm::unorm](../Topic/unorm::unorm%20Constructor.md)|Sobrecarregado.  Construtor padrão.  Inicializar em 0.0f.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|unorm::operator\-\- Operador||  
|Operador de flutuante unorm::operator|Operador de conversão.  Converter o número unorm a um valor de ponto flutuante.|  
|Operador unorm::operator\*\=||  
|Operador unorm::operator\/\=||  
|Operador unorm::operator\+\+||  
|Operador unorm::operator\+\=||  
|Operador unorm::operator\=||  
|Operador unorm::operator\-\=||  
  
## Hierarquia de Herança  
 `unorm`  
  
## Requisitos  
 **Cabeçalho:** amp\_short\_vectors.h  
  
 **Namespace:** Concurrency::graphics  
  
## Consulte também  
 [Namespace Concurrency::graphics](../../../parallel/amp/reference/concurrency-graphics-namespace.md)