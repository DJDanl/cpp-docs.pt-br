---
title: "Classe norm | Microsoft Docs"
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
  - "amp_short_vectors/Concurrency::graphics::norm"
dev_langs: 
  - "C++"
ms.assetid: 73002f3d-c25e-4119-bcd3-4c46c9b6abf1
caps.latest.revision: 8
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe norm
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Representa um número norm.  Cada elemento é um número de ponto flutuante no intervalo \[\-1.0f, 1.0f\].  
  
## Sintaxe  
  
```  
class norm;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor norm::norm](../Topic/norm::norm%20Constructor.md)|Sobrecarregado.  Construtor padrão.  Inicializar em 0.0f.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|Operador norm::operator\-||  
|Operador norm::operator\-\-||  
|Operador norm::operator float|Operador de conversão.  Converte o número norm para um valor de ponto flutuante.|  
|Operador norm::operator\*\=||  
|Operador norm::operator\/\=||  
|Operador norm::operator\+\+||  
|Operador norm::operator\+\=||  
|Operador norm::operator\=||  
|Operador norm::operator\-\=||  
  
## Hierarquia de Herança  
 `norm`  
  
## Requisitos  
 **Cabeçalho:** amp\_short\_vectors.h  
  
 **Namespace:** Concurrency::graphics  
  
## Consulte também  
 [Namespace Concurrency::graphics](../../../parallel/amp/reference/concurrency-graphics-namespace.md)