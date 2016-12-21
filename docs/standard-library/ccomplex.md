---
title: "&lt;ccomplex&gt; | Microsoft Docs"
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
  - "<ccomplex>"
dev_langs: 
  - "C++"
ms.assetid: a9fcb5f0-88e3-464b-a5fd-d1afb8cd7e6f
caps.latest.revision: 15
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;ccomplex&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inclui o cabeçalho STL [\<complex\>](../Topic/%3Ccomplex%3E.md), que inclui efetivamente o cabeçalho da biblioteca C Padrão \<complex.h\> e adiciona os nomes associados ao namespace `std`.  
  
## Sintaxe  
  
```cpp  
  
#include <ccomplex>  
  
```  
  
## Comentários  
 A inclusão desse cabeçalho garante que os nomes declarados usando vinculação externa no cabeçalho da biblioteca C Padrão sejam declarados no namespace `std`.  
  
 O nome `clog`, declarado em \<complex.h\>, não é definido no namespace `std` por causa de conflitos em potencial com o `clog` declarado em [\<iostream\>](../standard-library/iostream.md).  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Visão geral da STL](../standard-library/cpp-standard-library-overview.md)