---
title: "_CrtMemCheckpoint | Microsoft Docs"
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
  - "_CrtMemCheckpoint"
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
  - "CrtMemCheckpoint"
  - "_CrtMemCheckpoint"
  - "crtdbg/_CrtMemCheckpoint"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função CrtMemCheckpoint"
  - "Função _CrtMemCheckpoint"
ms.assetid: f1bacbaa-5a0c-498a-ac7a-b6131d83dfbc
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtMemCheckpoint
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém o estado atual do heap de depuração e armazena em um aplicativo fornecido `_CrtMemState` estrutura \(somente versão de depuração\).  
  
## Sintaxe  
  
```  
void _CrtMemCheckpoint(  
   _CrtMemState *state   
);  
```  
  
#### Parâmetros  
 `state`  
 Ponteiro para `_CrtMemState` estrutura para preencher com o ponto de verificação de memória.  
  
## Comentários  
 O `_CrtMemCheckpoint` função cria um instantâneo do estado atual do heap de depuração a qualquer momento. Esse instantâneo pode ser usado por outras funções de estado de heap como [\_CrtMemDifference](../Topic/_CrtMemDifference.md) para ajudar a detectar vazamentos de memória e outros problemas. Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, as chamadas para `_CrtMemState` são removidas durante o pré\-processamento.  
  
 O aplicativo deve passar um ponteiro para uma instância previamente alocada a `_CrtMemState` estrutura, definida em crtdbg. h, no `state` parâmetro. Se `_CrtMemCheckpoint` encontra um erro durante a criação do ponto de verificação, a função gera uma `_CRT_WARN` Depurar relatório descrevendo o problema.  
  
 Para obter mais informações sobre funções de estado de heap e a `_CrtMemState` estrutura, consulte [Funções de relatório do estado heap](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Heap_State_Reporting_Functions). Para obter mais informações sobre como blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
 Se `state` for `NULL`, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) é definido como `EINVAL` e a função retorna.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtMemCheckpoint`|\< crtdbg. h \>, \< errno. h \>|  
  
 Para obter informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
 **Bibliotecas:** versões de depuração de apenas o UCRT.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [\_CrtMemDifference](../Topic/_CrtMemDifference.md)