---
title: "_aligned_msize_dbg | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_aligned_msize_dbg"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_aligned_msize_dbg"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_aligned_msize_dbg"
ms.assetid: f1c44af0-3f66-4033-81d1-d71d3afecba0
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_msize_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna o tamanho de um bloco de memória alocado no heap \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
size_t _aligned_msize_dbg(  
   void *memblock,  
   size_t alignment,  
   size_t offset  
);  
```  
  
#### Parâmetros  
 \[entrada\] `memblock`  
 Ponteiro para o bloco de memória.  
  
 \[entrada\] `alignment`  
 O valor de alinhamento, que deve ser uma potência de inteiro de 2.  
  
 \[entrada\] `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
## Valor de retorno  
 Retorna o tamanho \(em bytes\) como um número inteiro sem sinal.  
  
## Comentários  
 Os valores de `alignment` e de `offset` devem ser iguais aos valores passados para a função que alocou o bloco.  
  
 `_aligned_msize_dbg` é uma versão de depuração da função de [\_aligned\_msize](../../c-runtime-library/reference/aligned-msize.md) .  Quando [\_DEBUG](../Topic/_DEBUG.md) não for definido, cada chamada a `_aligned_msize_dbg` será reduzido para uma chamada a `_aligned_msize`.  `_aligned_msize` e `_aligned_msize_dbg` calcular o tamanho de um bloco de memória heap de base, mas `_aligned_msize_dbg` adicionar um recurso de depuração: Inclui os buffers em ambos os lados da parte do usuário do bloco de memória em tamanho retornado.  
  
 Essa função valida seu parâmetro.  Se `memblock` for um ponteiro nulo ou `alignment` não é uma potência de 2, `_msize` invoca um manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se o erro é tratado, a função `errno` define a `EINVAL` e retorna \-1.  
  
 Para obter informações sobre como os blocos de memória são atribuídos, inicializados, e gerenciados na versão de depuração da heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  Para obter informações sobre o bloco de alocação digitar e como elas são usadas, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  Para obter informações sobre as diferenças entre chamar uma função padrão do heap e sua versão de depuração em uma compilação de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_aligned_msize_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Versões de depuração das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)