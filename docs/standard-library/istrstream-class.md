---
title: "Classe istrstream | Microsoft Docs"
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
  - "istrstream"
  - "std::istrstream"
  - "std.istrstream"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe istrstream"
ms.assetid: c2d41c75-bd2c-4437-bd77-5939ce1b97af
caps.latest.revision: 20
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe istrstream
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).  
  
## Sintaxe  
  
```  
  
class istrstream : public istream  
  
```  
  
## Comentários  
 O objeto armazena um objeto da classe `strstreambuf`.  
  
> [!NOTE]
>  Essa classe foi preterida. Considere o uso de [istringstream](../Topic/istringstream.md) ou [wistringstream](../Topic/wistringstream.md) em vez disso.  
  
### Construtores  
  
|||  
|-|-|  
|[istrstream](../Topic/istrstream::istrstream.md)|Constrói um objeto do tipo `istrstream`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[rdbuf](../Topic/istrstream::rdbuf.md)|Retorna um ponteiro para o fluxo associado do `strstreambuf` objeto.|  
|[STR](../Topic/istrstream::str.md)|Chamadas [Congelar](../Topic/strstreambuf::freeze.md), e, em seguida, retorna um ponteiro para o início da sequência controlada.|  
  
## Requisitos  
 **Cabeçalho:** \< strstream \>  
  
 **Namespace:** std  
  
## Consulte também  
 [istream](../Topic/istream.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)