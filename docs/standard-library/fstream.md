---
title: "&lt;fstream&gt; | Microsoft Docs"
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
  - "std::<fstream>"
  - "<fstream>"
  - "std.<fstream>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho fstream"
ms.assetid: 660de351-0489-41df-b239-40e0cdcab46b
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;fstream&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define várias classes que oferecem suporte a operações de iostreams em seqüências armazenadas em arquivos externos.  
  
## Sintaxe  
  
```  
  
#include <fstream>  
  
```  
  
### DefsTipo  
  
|||  
|-|-|  
|[filebuf](../Topic/filebuf.md)|Um tipo`basic_filebuf`especializadas em`char`parâmetros de modelo.|  
|[fstream](../Topic/fstream.md)|Um tipo`basic_fstream`especializadas em`char`parâmetros de modelo.|  
|[ifstream](../Topic/ifstream.md)|Um tipo`basic_ifstream`especializadas em`char`parâmetros de modelo.|  
|[ofstream](../Topic/ofstream.md)|Um tipo`basic_ofstream`especializadas em`char`parâmetros de modelo.|  
|[wfstream](../Topic/wfstream.md)|Um tipo`basic_fstream`especializadas em`wchar_t`parâmetros de modelo.|  
|[wifstream](../Topic/wifstream.md)|Um tipo`basic_ifstream`especializadas em`wchar_t`parâmetros de modelo.|  
|[wofstream](../Topic/wofstream.md)|Um tipo`basic_ofstream`especializadas em`wchar_t`parâmetros de modelo.|  
|[wfilebuf](../Topic/wfilebuf.md)|Um tipo`basic_filebuf`especializadas em`wchar_t`parâmetros de modelo.|  
  
### Classes  
  
|||  
|-|-|  
|[basic\_filebuf](../standard-library/basic-filebuf-class.md)|A classe de modelo descreve um buffer de fluxo que controla a transmissão de elementos do tipo**Elem**cujas características de caractere são determinadas pela classe**Tr**para e de uma sequência de elementos armazenados em um arquivo externo.|  
|[basic\_fstream](../standard-library/basic-fstream-class.md)|A classe de modelo descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe[basic\_filebuf](../standard-library/basic-filebuf-class.md)\<**ElemTr**\>, com elementos do tipo**Elem**cujas características de caractere são determinadas pela classe**Tr**.|  
|[basic\_ifstream](../standard-library/basic-ifstream-class.md)|A classe de modelo descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe[basic\_filebuf](../standard-library/basic-filebuf-class.md)\<**ElemTr**\>, com elementos do tipo**Elem**cujas características de caractere são determinadas pela classe**Tr**.|  
|[basic\_ofstream](../standard-library/basic-ofstream-class.md)|A classe de modelo descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo da classe[basic\_filebuf](../standard-library/basic-filebuf-class.md)\<**ElemTr**\>, com elementos do tipo**Elem**cujas características de caractere são determinadas pela classe**Tr**.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)