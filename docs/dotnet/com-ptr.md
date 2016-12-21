---
title: "com::ptr | Microsoft Docs"
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
  - "ptr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "com::ptr"
ms.assetid: ee302e3c-8fed-4875-a372-2e55003718d3
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# com::ptr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um wrapper para um objeto COM que pode ser usado como um membro de uma classe de CLR.  O wrapper também automatiza gerenciamento do tempo de vida do objeto COM, liberando referências propriedade no objeto quando seu destruidor é chamado.  Análoga a [Classe de CComPtr](../atl/reference/ccomptr-class.md).  
  
## Sintaxe  
  
```  
#include <msclr\com\ptr.h>  
```  
  
## Comentários  
 [Classe com::ptr](../dotnet/com-ptr-class.md) é \<definido no msclr \\ COM \\ arquivos\> de ptr.h.  
  
## Consulte também  
 [Biblioteca de suporte do C\+\+](../dotnet/cpp-support-library.md)