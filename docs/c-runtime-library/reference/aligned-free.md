---
title: "_aligned_free | Microsoft Docs"
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
  - "_aligned_free"
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
  - "api-ms-win-crt-heap-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "aligned_free"
  - "_aligned_free"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _aligned_free"
  - "Função aligned_free"
ms.assetid: ed1ce952-cdfc-4682-85cc-f75d4101603d
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_free
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Libera um bloco de memória que foi atribuído com [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md).  
  
## Sintaxe  
  
```  
void _aligned_free (  
   void *memblock  
);  
```  
  
#### Parâmetros  
 `memblock`  
 Um ponteiro para o bloco de memória que foi retornado à função de `_aligned_malloc` ou de `_aligned_offset_malloc` .  
  
## Comentários  
 `_aligned_free` é marcado `__declspec(noalias)`, o que significa que a função não é garantida para modificar as variáveis globais.  Para obter mais informações, consulte [noalias](../../cpp/noalias.md).  
  
 Essa função não valida o parâmetro, diferentemente de outras funções \_aligned de CRT.  Se `memblock` é um ponteiro de `NULL` , essa função não simplesmente executa nenhuma ação.  Não altera `errno` e não chama o manipulador inválido do parâmetro.  Se ocorrer um erro na função devido a usar funções \_aligned anteriormente para atribuir o bloco de memória ou um desalinhamento de memória ocorre devido a qualquer calamidade imprevisto, a função gerencie um relatório de depuração de [Macros \_RPT, \_RPTF, \_RPTW, \_RPTFW](../Topic/_RPT,%20_RPTF,%20_RPTW,%20_RPTFW%20Macros.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_aligned_free`|\<malloc.h\>|  
  
## Exemplo  
 Para obter mais informações, consulte [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alinhamento de dados](../../c-runtime-library/data-alignment.md)