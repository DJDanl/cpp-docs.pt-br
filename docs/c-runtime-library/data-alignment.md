---
title: "Alinhamento de dados | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "data.alignment"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "alinhamento de dados [C++]"
ms.assetid: 35ac3d2d-a4b3-421b-954f-b7372b1f18e1
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Alinhamento de dados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As seguintes funções de tempo de execução C oferecem suporte ao alinhamento de dados.  
  
### Rotinas do alinhamento  
  
|Rotina|Uso|Equivalente a .NET Framework|  
|------------|---------|----------------------------------|  
|[\_aligned\_free](../c-runtime-library/reference/aligned-free.md)|Libera um bloco de memória que foi atribuído com [\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md)ou [\_aligned\_offset\_malloc](../c-runtime-library/reference/aligned-offset-malloc.md).|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_free\_dbg](../c-runtime-library/reference/aligned-free-dbg.md)|Libera um bloco de memória que foi atribuído com [\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) depuração \(somente\).|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md)|Aloca memória em um limite de alinhamento especificado.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_malloc\_dbg](../Topic/_aligned_malloc_dbg.md)|Aloca memória em um limite de alinhamento especificado com espaço adicional para um cabeçalho de depuração e substituem buffers \(versão de depuração somente\).|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_msize](../c-runtime-library/reference/aligned-msize.md)|Retorna o tamanho de um bloco de memória alocado no heap.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_msize\_dbg](../c-runtime-library/reference/aligned-msize-dbg.md)|Retorna o tamanho de um bloco de memória alocado no heap \(versão de depuração somente\).|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_offset\_malloc](../c-runtime-library/reference/aligned-offset-malloc.md)|Aloca memória em um limite de alinhamento especificado.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_offset\_malloc\_dbg](../c-runtime-library/reference/aligned-offset-malloc-dbg.md)|Aloca memória em um limite de alinhamento especificado \(versão de depuração somente\).|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_offset\_realloc](../c-runtime-library/reference/aligned-offset-realloc.md)|Altera o tamanho de um bloco de memória que é atribuído com [\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../c-runtime-library/reference/aligned-offset-malloc.md).|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_offset\_realloc\_dbg](../c-runtime-library/reference/aligned-offset-realloc-dbg.md)|Altera o tamanho de um bloco de memória que é atribuído com [\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) \(versão de depuração somente\).|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_offset\_recalloc](../c-runtime-library/reference/aligned-offset-recalloc.md)|Altera o tamanho de um bloco de memória que é atribuído com [\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_offset\_recalloc\_dbg](../c-runtime-library/reference/aligned-offset-recalloc-dbg.md)|Altera o tamanho de um bloco de memória que é atribuído com [\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0 \(versão de depuração somente\).|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_realloc](../c-runtime-library/reference/aligned-realloc.md)|Altera o tamanho de um bloco de memória que é atribuído com [\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../c-runtime-library/reference/aligned-offset-malloc.md).|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_realloc\_dbg](../c-runtime-library/reference/aligned-realloc-dbg.md)|Altera o tamanho de um bloco de memória que é atribuído com [\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) \(versão de depuração somente\).|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_recalloc](../c-runtime-library/reference/aligned-recalloc.md)|Altera o tamanho de um bloco de memória que é atribuído com [\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_aligned\_recalloc\_dbg](../c-runtime-library/reference/aligned-recalloc-dbg.md)|Altera o tamanho de um bloco de memória que é atribuído com [\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0 \(versão de depuração somente\).|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)