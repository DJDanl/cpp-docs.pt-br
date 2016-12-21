---
title: "_CrtDoForAllClientObjects | Microsoft Docs"
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
  - "_CrtDoForAllClientObjects"
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
  - "_CrtDoForAllClientObjects"
  - "CrtDoForAllClientObjects"
  - "crtdbg/_CrdDoForAllClientObjects"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _CrtDoForAllClientObjects"
  - "Função CrtDoForAllClientObjects"
ms.assetid: d0fdb835-3cdc-45f1-9a21-54208e8df248
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtDoForAllClientObjects
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chama uma função fornecida pelo aplicativo para todos os `_CLIENT_BLOCK` tipos no heap \(somente versão de depuração\).  
  
## Sintaxe  
  
```  
void _CrtDoForAllClientObjects(   
   void ( * pfn )( void *, void * ),  
   void *context  
);  
```  
  
#### Parâmetros  
 `pfn`  
 Ponteiro para a função de retorno de chamada de função fornecida pelo aplicativo. O primeiro parâmetro para essa função aponta para os dados. O segundo parâmetro é o ponteiro de contexto que é passado para a chamada para `_CrtDoForAllClientObjects`.  
  
 `context`  
 Ponteiro para o contexto fornecido pelo aplicativo para passar para a função fornecida pelo aplicativo.  
  
## Comentários  
 O `_CrtDoForAllClientObjects` a função pesquisa a lista vinculada do heap por blocos de memória com o `_CLIENT_BLOCK` tipo e chama a função fornecida pelo aplicativo quando um bloco desse tipo é encontrada. O bloco encontrado e o `context` parâmetro são passados como argumentos para a função fornecida pelo aplicativo. Durante a depuração, um aplicativo pode acompanhar um grupo específico de alocações de chamar explicitamente a depuração de funções de heap para alocar a memória e especificando que os blocos de ser atribuído a `_CLIENT_BLOCK` tipo de bloco. Esses blocos podem ser rastreados separadamente e relatados de modo diferente durante a detecção de vazamento e relatório de estado da memória.  
  
 Se o `_CRTDBG_ALLOC_MEM_DF` campo de bit de [\_crtDbgFlag](../Topic/_crtDbgFlag.md) sinalizador não está ativado, `_CrtDoForAllClientObjects` retorna imediatamente. Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, as chamadas para `_CrtDoForAllClientObjects` são removidas durante o pré\-processamento.  
  
 Para obter mais informações sobre o `_CLIENT_BLOCK` Digite e como ele pode ser usado por outras funções de depuração, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap). Para obter informações sobre como blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
 Se `pfn` for `NULL`, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) é definido como `EINVAL` e a função retorna.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtDoForAllClientObjects`|\< crtdbg. h \>, \< errno. h \>|  
  
 Para obter informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
 **Bibliotecas:** versões de depuração de universal Runtime bibliotecas C somente.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [\_CrtSetDbgFlag](../../c-runtime-library/reference/crtsetdbgflag.md)   
 [Funções de relatório do estado heap](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Heap_State_Reporting_Functions)   
 [\_CrtReportBlockType](../Topic/_CrtReportBlockType.md)