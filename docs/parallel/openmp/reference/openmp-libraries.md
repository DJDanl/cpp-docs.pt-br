---
title: "OpenMP Libraries | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: f89abf97-67e3-4327-bc30-43f85b9533a2
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# OpenMP Libraries
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Discute os arquivos. lib que compõem as bibliotecas de tempo de execução do OpenMP no Visual C\+\+.  
  
 As bibliotecas a seguintes contêm as funções de biblioteca run\-time do OpenMP do Visual C\+\+.  
  
|Biblioteca de tempo de execução do OpenMP|Características|  
|-----------------------------------------------|---------------------|  
|VCOMP.LIB|Vários segmentos, dynamic link \(biblioteca de importação para VCOMP.LIB\).|  
|VCOMPD.LIB|Vários segmentos, dynamic link \(biblioteca de importação para VCOMPD.TAMPA\) \(depuração\)|  
  
 Se \_ Debug é definido em uma compilação e se `#include omp.h` está no código\-fonte, VCOMPD.LIB será a biblioteca padrão.  Caso contrário, VCOMP.LIB será usado.  
  
 Você pode usar [\/NODEFAULTLIB \(ignorar bibliotecas\)](../../../build/reference/nodefaultlib-ignore-libraries.md) para remover a biblioteca padrão e explicitamente a ligação com a biblioteca de sua escolha.  
  
 As DLLs do OpenMP estão no diretório redistribuível do Visual C\+\+ e precisam ser distribuídos com aplicativos que usam o OpenMP.  
  
## Consulte também  
 [Library Reference](../../../parallel/openmp/reference/openmp-library-reference.md)