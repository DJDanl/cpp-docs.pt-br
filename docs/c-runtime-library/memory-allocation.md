---
title: "Aloca&#231;&#227;o de mem&#243;ria | Microsoft Docs"
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
  - "c.memory"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "alocação de memória, Rotinas "
  - "memória, alocação"
  - "memória, gerenciando"
ms.assetid: b4470556-a128-4782-9943-2ccf7a7d9979
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aloca&#231;&#227;o de mem&#243;ria
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use estas rotinas para alocar, liberar e realocar memória.  
  
### Rotinas de alocação da memória  
  
|Rotina|Uso|Equivalente ao .NET Framework|  
|------------|---------|-----------------------------------|  
|[\_alloca](../c-runtime-library/reference/alloca.md), [\_malloca](../c-runtime-library/reference/malloca.md)|Alocar memória da pilha|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[calloc](../c-runtime-library/reference/calloc.md)|Alocar armazenamento para matriz, inicializando cada byte em bloco alocado como 0|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_calloc\_dbg](../c-runtime-library/reference/calloc-dbg.md)|Versão de depuração de `calloc`; disponível apenas em versões de depuração das bibliotecas de tempo de execução|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[operador delete](../c-runtime-library/operator-delete-crt.md)|Liberar bloco alocado|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[operador delete&#91;&#93;](../c-runtime-library/delete-operator-crt.md)|Liberar bloco alocado|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_expand](../Topic/_expand.md)|Expandir ou reduzir bloco de memória sem movê\-lo|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_expand\_dbg](../Topic/_expand_dbg.md)|Versão de depuração de `_expand`; disponível apenas em versões de depuração das bibliotecas de tempo de execução|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[free](../c-runtime-library/reference/free.md)|Liberar bloco alocado|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_free\_dbg](../c-runtime-library/reference/free-dbg.md)|Versão de depuração de `free`; disponível apenas em versões de depuração das bibliotecas de tempo de execução|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_freea](../c-runtime-library/reference/freea.md)|Liberar bloco alocado da pilha|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_get\_heap\_handle](../c-runtime-library/reference/get-heap-handle.md)|Obter Win32 HANDLE do heap CRT.|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_heapadd](../c-runtime-library/heapadd.md)|Adicionar memória ao heap|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_heapchk](../c-runtime-library/reference/heapchk.md)|Verificar consistência do heap|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_heapmin](../c-runtime-library/reference/heapmin.md)|Liberar memória não usada no heap|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_heapset](../c-runtime-library/heapset.md)|Preencher entradas do heap com valor especificado|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_heapwalk](../Topic/_heapwalk.md)|Retornar informações sobre cada entrada no heap|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[malloc](../c-runtime-library/reference/malloc.md)|Alocar bloco de memória do heap|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_malloc\_dbg](../c-runtime-library/reference/malloc-dbg.md)|Versão de depuração de `malloc`; disponível apenas em versões de depuração das bibliotecas de tempo de execução|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_msize](../Topic/_msize.md)|Retornar tamanho do bloco alocado|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_msize\_dbg](../c-runtime-library/reference/msize-dbg.md)|Versão de depuração de `_msize`; disponível apenas em versões de depuração das bibliotecas de tempo de execução|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[new](../c-runtime-library/operator-new-crt.md)|Alocar bloco de memória do heap|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[new&#91;&#93;](../c-runtime-library/new-operator-crt.md)|Alocar bloco de memória do heap|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_query\_new\_handler](../c-runtime-library/reference/query-new-handler.md)|Retornar endereço da rotina atual do novo manipulador conforme definido `_set_new_handler`|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_query\_new\_mode](../c-runtime-library/reference/query-new-mode.md)|Retornar inteiro indicando novo modo de manipulador definido por `_set_new_mode` para `malloc`|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[realloc](../c-runtime-library/reference/realloc.md)|Realocar bloco para novo tamanho|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_realloc\_dbg](../c-runtime-library/reference/realloc-dbg.md)|Versão de depuração de `realloc`; disponível apenas em versões de depuração das bibliotecas de tempo de execução|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_set\_new\_handler](../Topic/_set_new_handler.md)|Habilitar mecanismo de tratamento de erros quando o operador `new` falhar \(ao alocar memória\) e habilitar a compilação de STL \(Bibliotecas de Modelo Padrão\)|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_set\_new\_mode](../c-runtime-library/reference/set-new-mode.md)|Definir novo modo do manipulador `malloc`|Não aplicável.  Para chamar a função C padrão, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)