---
title: "_CrtDumpMemoryLeaks | Microsoft Docs"
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
  - "_CrtDumpMemoryLeaks"
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
  - "CRTDBG_LEAK_CHECK_DF"
  - "CRTDBG_CHECK_CRT_DF"
  - "_CRTDBG_LEAK_CHECK_DF"
  - "CrtDumpMemoryLeaks"
  - "_CrtDumpMemoryLeaks"
  - "_CRTDBG_CHECK_CRT_DF"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função CrtDumpMemoryLeaks"
  - "Macro CRTDBG_LEAK_CHECK_DF"
  - "Macro _CRTDBG_LEAK_CHECK_DF"
  - "Função _CrtDumpMemoryLeaks"
  - "Macro CRTDBG_CHECK_CRT_DF"
  - "Macro _CRTDBG_CHECK_CRT_DF"
ms.assetid: 71b2eab4-7f55-44e8-a55a-bfea4f32d34c
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtDumpMemoryLeaks
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Despejos todos os blocos de memória heap de depuração quando um vazamento de memória durante \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
  
int _CrtDumpMemoryLeaks( void );  
```  
  
## Valor de retorno  
 `_CrtDumpMemoryLeaks` retornará TRUE se um vazamento de memória for localizado.  Caso contrário, a função retornará FALSE.  
  
## Comentários  
 A função de `_CrtDumpMemoryLeaks` determina se um vazamento de memória ocorreu desde o início da execução do programa.  Quando um escape for localizado, as informações de cabeçalho de depuração para todos os objetos no heap será despejada em um formato legível usuário.  Quando [\_DEBUG](../Topic/_DEBUG.md) não for definido, as chamadas para `_CrtDumpMemoryLeaks` serão removidos durante pré\-processamento.  
  
 `_CrtDumpMemoryLeaks` é chamado no final da execução de programa para verificar se toda a memória alocada pelo aplicativo seja liberada.  A função pode ser chamada automaticamente no encerramento de programa ativando o campo de bit de `_CRTDBG_LEAK_CHECK_DF` do sinalizador de [\_crtDbgFlag](../Topic/_crtDbgFlag.md) usando a função de [\_CrtSetDbgFlag](../../c-runtime-library/reference/crtsetdbgflag.md) .  
  
 `_CrtDumpMemoryLeaks` [\_CrtMemCheckpoint](../../c-runtime-library/reference/crtmemcheckpoint.md) chama para obter o estado atual do heap e verifique o estado dos blocos que não foram liberados.  Quando um bloco unfreed for encontrado, `_CrtDumpMemoryLeaks` chama [\_CrtMemDumpAllObjectsSince](../Topic/_CrtMemDumpAllObjectsSince.md) para despejar informações para todos os objetos alocados no heap desde o início da execução do programa.  
  
 Por padrão, os blocos internos de tempo de execução C \(`_CRT_BLOCK`\) não são incluídos em operações de despejo de memória.  A função de [\_CrtSetDbgFlag](../../c-runtime-library/reference/crtsetdbgflag.md) pode ser usada para ativar o bit de `_CRTDBG_CHECK_CRT_DF` de `_crtDbgFlag` para incluir estes blocos no processo de detecção de escape.  
  
 Para obter mais informações sobre as funções de estado da heap e a estrutura de `_CrtMemState`, consulte [Funções de relatório do estado heap](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Heap_State_Reporting_Functions).  Para obter mais informações sobre como os blocos de memória são atribuídos, inicializados, e gerenciados na versão de depuração da heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtDumpMemoryLeaks`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Versões de depuração das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
## Exemplo  
 Para obter um exemplo de como usar `_CrtDumpMemoryLeaks`, consulte [crt\_dbg1](http://msdn.microsoft.com/pt-br/17b4b20c-e849-48f5-8eb5-dca6509cbaf9).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)