---
title: "&lt;strstream&gt; | Microsoft Docs"
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
  - "std.<strstream>"
  - "std::<strstream>"
  - "<strstream>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho strstream"
ms.assetid: eaa9d0d4-d217-4f28-8a68-9b9ad7b1c0f5
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;strstream&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define várias classes que oferecem suporte a operações de iostreams em seqüências armazenadas em uma matriz alocada de `char` objeto.  Essas sequências facilmente são convertidas em cadeias de caracteres do C.  
  
## Sintaxe  
  
```  
  
#include <strstream>  
  
```  
  
## Comentários  
 Objetos do tipo `strstream` funcionam com `char` \*, que são cadeias de caracteres do C.  Use [\< sstream \>](../standard-library/sstream.md) para trabalhar com objetos do tipo [basic\_string](../standard-library/basic-string-class.md).  
  
> [!NOTE]
>  As classes em `<strstream>` são preteridos.  Considere o uso de classes em `<sstream>` em vez disso.  
  
### Classes  
  
|||  
|-|-|  
|[Classe strstreambuf](../standard-library/strstreambuf-class.md)|A classe descreve um buffer de fluxo que controla a transmissão de elementos em uma sequência de elementos armazenados em uma `char` objeto array.|  
|[Classe istrstream](../standard-library/istrstream-class.md)|A classe descreve um objeto que controla a extração de elementos e codificados objetos de um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|  
|[Classe ostrstream](../Topic/ostrstream%20Class.md)|A classe descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|  
|[Classe strstream](../standard-library/strstream-class.md)|A classe descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|  
  
## Consulte também  
 [\< Strstream \>](../standard-library/strstream.md)   
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)