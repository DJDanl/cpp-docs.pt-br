---
title: "&lt; streambuf &gt; | Microsoft Docs"
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
  - "std::<streambuf>"
  - "<streambuf>"
  - "streambuf/std::<streambuf>"
  - "std.<streambuf>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho streambuf"
ms.assetid: 4365b25c-5831-488b-b9c2-867bfe961b89
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; streambuf &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inclua o cabeçalho padrão do iostreams \< streambuf \> para definir a classe de modelo [basic\_streambuf](../standard-library/basic-streambuf-class.md), que é básico para a operação das classes iostreams. Esse cabeçalho é geralmente incluído para você por outro dos cabeçalhos iostreams; Você raramente precisa incluí\-lo diretamente.  
  
## Sintaxe  
  
```  
  
#include <streambuf>  
  
```  
  
### Typedefs  
  
|||  
|-|-|  
|[streambuf](../Topic/streambuf.md)|Uma especialização de `basic_streambuf` que usa `char` como os parâmetros do modelo.|  
|[wstreambuf](../Topic/wstreambuf.md)|Uma especialização de `basic_streambuf` que usa `wchar_t` como os parâmetros do modelo.|  
  
### Classes  
  
|||  
|-|-|  
|[Classe basic\_streambuf](http://msdn.microsoft.com/pt-br/d9c706ba-ce01-43e0-b0b2-a558fc53ea8d)|A classe de modelo descreve uma classe base abstrata para derivar um buffer de fluxo, que controla a transmissão de elementos em uma representação específica de um fluxo.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)