---
title: "Classe strstream | Microsoft Docs"
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
  - "std::strstream"
  - "strstream"
  - "std.strstream"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe strstream"
ms.assetid: 63f3be31-9e36-42b1-9715-a474a5997e2a
caps.latest.revision: 21
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe strstream
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe[strstreambuf](../standard-library/strstreambuf-class.md).  
  
## Sintaxe  
  
```  
  
class strstream : public iostream  
  
```  
  
## Comentários  
 O objeto armazena um objeto da classe`strstreambuf`.  
  
> [!NOTE]
>  Essa classe foi preterida.  Considere o uso de[stringstream](../Topic/stringstream.md)ou[wstringstream](../Topic/wstringstream.md)em vez disso.  
  
### Construtores  
  
|||  
|-|-|  
|[strstream](../Topic/strstream::strstream.md)|Constrói um objeto do tipo`strstream`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[Congelamento](../Topic/strstream::freeze.md)|Faz com que um buffer de fluxo para estar disponível por meio de operações de buffer de fluxo.|  
|[pcount](../Topic/strstream::pcount.md)|Retorna uma contagem do número de elementos escritos para a sequência controlada.|  
|[rdbuf](../Topic/strstream::rdbuf.md)|Retorna um ponteiro para o fluxo associado do`strstreambuf`objeto.|  
|[STR](../Topic/strstream::str.md)|Chamadas[Congelar](../Topic/strstreambuf::freeze.md)e, em seguida, retorna um ponteiro para o início da sequência controlada.|  
  
## Requisitos  
 **Cabeçalho:**\< strstream \>  
  
 **Namespace:** std  
  
## Consulte também  
 [iostream](../Topic/iostream.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)