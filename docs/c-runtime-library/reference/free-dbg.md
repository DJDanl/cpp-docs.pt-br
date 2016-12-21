---
title: "_free_dbg | Microsoft Docs"
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
  - "_free_dbg"
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
  - "_free_dbg"
  - "free_dbg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "blocos de memória, desalocando"
  - "liberando memória"
  - "Função _free_dbg"
  - "Função free_dbg"
ms.assetid: fc5e8299-616d-48a0-b979-e037117278c6
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _free_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Libera um bloco de memória no heap \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
void _free_dbg(   
   void *userData,  
   int blockType   
);  
```  
  
#### Parâmetros  
 `userData`  
 Ponteiro para o bloco de memória alocado seja liberado.  
  
 `blockType`  
 Tipo do bloco de memória alocado a ser lançado: `_CLIENT_BLOCK`, `_NORMAL_BLOCK`, ou `_IGNORE_BLOCK`.  
  
## Comentários  
 A função de `_free_dbg` é uma versão de depuração da função de [livre](../../c-runtime-library/reference/free.md) .  Quando [\_DEBUG](../Topic/_DEBUG.md) não for definido, cada chamada a `_free_dbg` será reduzido para uma chamada a `free`.  `free` e `_free_dbg` liberam um bloco de memória heap de base, mas `_free_dbg` acomode dois recursos de depuração: a capacidade de manter bloqueios liberados na lista vinculada do heap para simular a memória baixa condições e um parâmetro em blocos para liberar a alocação específica digita.  
  
 `_free_dbg` executa uma verificação de validade em todos os arquivos e locais especificados no bloco antes de executar a operação livre.  O aplicativo não deve fornecer essas informações.  Quando um bloco de memória é liberado, o gerenciador de heap de depuração automaticamente verifica a integridade dos buffers em ambos os lados da parte do usuário e emite um relatório de erro se a substituição ocorreu.  Se o campo de bit de `_CRTDBG_DELAY_FREE_MEM_DF` do sinalizador de [\_crtDbgFlag](../Topic/_crtDbgFlag.md) for definido, o bloco liberado será preenchido com o valor 0xDD, atribuído `_FREE_BLOCK` em blocos, e mantido na lista vinculada do heap de blocos de memória.  
  
 Se ocorrer um erro em liberar a memória, `errno` é definido com informações do sistema operacional na natureza da falha.  Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 Para obter informações sobre como os blocos de memória são atribuídos, inicializados, e gerenciados na versão de depuração da heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  Para obter informações sobre o bloco de alocação digitar e como elas são usadas, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  Para obter informações sobre as diferenças entre chamar uma função padrão do heap e sua versão de depuração em uma compilação de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_free_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Para obter um exemplo de como usar `_free_dbg`, consulte [crt\_dbg2](http://msdn.microsoft.com/pt-br/21e1346a-6a17-4f57-b275-c76813089167).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md)