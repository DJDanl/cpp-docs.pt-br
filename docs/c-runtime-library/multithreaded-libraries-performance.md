---
title: "Desempenho de bibliotecas multithread | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "bibliotecas, com multithread"
  - "bibliotecas com multithread"
  - "desempenho, multithreading"
  - "threading [C++], desempenho"
ms.assetid: faa5d808-087c-463d-8f0d-8c478d137296
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Desempenho de bibliotecas multithread
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O CRT de thread único não está mais disponível.  Este tópico discute como obter o máximo desempenho das bibliotecas multi\-threaded.  
  
## Aumentando o desempenho  
 O desempenho das bibliotecas multi\-threaded foi aprimorado e é semelhante ao do desempenho das bibliotecas de thread único agora eliminadas.  Para essas situações quando mesmo alto desempenho é necessário, há vários novos recursos.  
  
-   O bloqueio de forma independente de fluxo permite que você impede um fluxo e então use [Funções \(\_nolock\)](../c-runtime-library/nolock-functions.md) que acessa o fluxo diretamente.  Isso permite que o uso de bloqueio é içado fora de loops críticos.  
  
-   a localidade do thread reduz os custos de acesso à localidade para cenários de vários threads \(consulte [\_configthreadlocale](../c-runtime-library/reference/configthreadlocale.md)\).  
  
-   As funções de localidade dependente \(com os nomes que terminam em \_l\) levam a localidade como um parâmetro, removendo os custos substanciais \(por exemplo, [printf, \_printf\_l, wprintf, \_wprintf\_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)\).  
  
-   As otimizações para páginas de código comum reduzem o custo de muitas operações curtos.  
  
-   Definindo [\_CRT\_DISABLE\_PERFCRIT\_LOCKS](../c-runtime-library/crt-disable-perfcrit-locks.md) força todas as operações de E\/S para assumir um modelo de thread único de E\/S e usar os formulários de \_nolock de funções.  Isso permite altamente a I\/O\-based aplicativos de thread único obter o melhor desempenho.  
  
-   A possibilidade de identificador de heap de CRT permite que você habilite heap \(LFH\) de fragmentação do windows baixo para o heap de CRT substancialmente, o que pode melhorar o desempenho em cenários bem dimensionados.  
  
## Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)