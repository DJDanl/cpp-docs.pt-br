---
title: "adapter (STL/CLR) | Microsoft Docs"
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
  - "<cliext/adapter>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho &lt;adapter&gt; [STL/CLR]"
  - "Cabeçalho &lt;cliext/adapter&gt; [STL/CLR]"
  - "adaptador [STL/CLR]"
ms.assetid: 71ce7e51-42b6-4f70-9595-303791a97677
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# adapter (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O cabeçalho `<cliext/adapter>` de STL\/CLR especifica duas classes de modelo \(`collection_adapter` e `range_adapter`\), e a função `make_collection`do modelo.  
  
## Sintaxe  
  
```  
#include <cliext/adapter>  
```  
  
## Comentários  
  
|Classe|Descrição|  
|------------|---------------|  
|[collection\_adapter](../Topic/collection_adapter%20\(STL-CLR\).md)|Envolve a coleção de \(BCL\) da biblioteca de classes base como um intervalo.|  
|[range\_adapter](../dotnet/range-adapter-stl-clr.md)|Encapsula o intervalo como uma coleção de BCL.|  
  
|Função|Descrição|  
|------------|---------------|  
|[make\_collection](../dotnet/make-collection-stl-clr.md)|Cria um adaptador de intervalo usando um par de iterador.|  
  
## Requisitos  
 cliext \<\/adaptador de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)