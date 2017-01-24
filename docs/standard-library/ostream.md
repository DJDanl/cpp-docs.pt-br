---
title: "&lt;ostream&gt; | Microsoft Docs"
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
  - "std.<ostream>"
  - "<ostream>"
  - "ostream/std::<ostream>"
  - "std::<ostream>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho ostream"
ms.assetid: 90c3b6fb-57cd-4ae7-99b8-8512f24a67d2
caps.latest.revision: 20
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;ostream&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define a classe de modelo[basic\_ostream](../Topic/basic_ostream%20Class.md)que faz a mediação inserções para o iostreams.  O cabeçalho também define vários manipuladores relacionados.  \(Esse cabeçalho é geralmente incluído para você, por outro os cabeçalhos iostreams.  Você raramente precisa incluí\-lo diretamente.\)  
  
## Sintaxe  
  
```  
  
#include <ostream>  
  
```  
  
### DefsTipo  
  
|||  
|-|-|  
|[ostream](../Topic/ostream.md)|Cria um tipo de`basic_ostream`que é especializada em`char`e`char_traits`especializadas em`char`.|  
|[wostream](../Topic/wostream.md)|Cria um tipo de`basic_ostream`que é especializada em`wchar_t`e`char_traits`especializadas em`wchar_t`.|  
  
### Manipuladores  
  
|||  
|-|-|  
|[endl](../Topic/endl.md)|Termina uma linha e libera o buffer.|  
|[extremidades](../Topic/ends%20\(Standard%20C++%20Library\).md)|Finaliza uma cadeia de caracteres.|  
|[flush](../Topic/flush%20\(Standard%20C++%20Library\).md)|Libera o buffer.|  
||Troca os valores da esquerda`basic_ostream`objeto parâmetro para aqueles direita`basic_ostream`objeto parâmetro.|  
  
### Operadores  
  
|||  
|-|-|  
|[Operador \<\<](../Topic/operator%3C%3C%20\(%3Costream%3E\).md)|Grava o fluxo de vários tipos.|  
  
### Classes  
  
|||  
|-|-|  
|[basic\_ostream](../Topic/basic_ostream%20Class.md)|A classe de modelo descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)