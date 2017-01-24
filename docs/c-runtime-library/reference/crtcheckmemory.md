---
title: "_CrtCheckMemory | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_CrtCheckMemory"
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
  - "CrtCheckMemory"
  - "_CrtCheckMemory"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _CrtCheckMemory"
  - "Função CrtCheckMemory"
ms.assetid: 457cc72e-60fd-4177-ab5c-6ae26a420765
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtCheckMemory
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Confirma a integridade dos blocos de memória alocado no heap de depuração \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
  
int _CrtCheckMemory( void );  
```  
  
## Valor de retorno  
 Se tiver êxito, `_CrtCheckMemory` retornará TRUE; caso contrário, a função retornará FALSE.  
  
## Comentários  
 A função de `_CrtCheckMemory` valida a memória alocada pelo gerenciador de heap de depuração verificando o heap de base subjacente e inspecionando cada bloco de memória.  Se uma inconsistência de erro ou de memória é encontrada no heap de base subjacente, nas informações de cabeçalho de depuração, ou nos buffers de substituição, `_CrtCheckMemory` gerencie um relatório de depuração com informações que descrevem a condição de erro.  Quando [\_DEBUG](../Topic/_DEBUG.md) não for definido, as chamadas para `_CrtCheckMemory` serão removidos durante pré\-processamento.  
  
 O comportamento de `_CrtCheckMemory` pode ser controlado definindo os campos de bit do sinalizador de [\_crtDbgFlag](../Topic/_crtDbgFlag.md) usando a função de [\_CrtSetDbgFlag](../../c-runtime-library/reference/crtsetdbgflag.md) .  Girando o bit de **\_CRTDBG\_CHECK\_ALWAYS\_DF** coloque resultados em `_CrtCheckMemory` que está sendo chamado sempre que uma operação de alocação de memória é solicitada.  Embora esse método lenta a execução, é útil para capturar erros rapidamente.  Girando o campo de bit de **\_CRTDBG\_ALLOC\_MEM\_DF** OFF faz `_CrtCheckMemory` verificar o heap e retorne imediatamente **Verdadeiro**.  
  
 Como essa função retorna **Verdadeiro** ou **Falso**, pode ser transmitido para um de macros de [\_ASSERT](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md) para criar um mecanismo simples de tratamento de erros de depuração.  O exemplo a seguir faz com que uma falha de asserção se o dano for detectado no heap:  
  
```  
_ASSERTE( _CrtCheckMemory( ) );  
```  
  
 Para obter mais informações sobre como `_CrtCheckMemory` pode ser usado com outras funções de depuração, consulte [Funções de relatório do estado heap](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Heap_State_Reporting_Functions).  Para obter uma visão geral do gerenciamento da memória e de heap de depuração, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtCheckMemory`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Versões de depuração das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
## Exemplo  
 Para obter um exemplo de como usar `_CrtCheckMemory`, consulte [crt\_dbg1](http://msdn.microsoft.com/pt-br/17b4b20c-e849-48f5-8eb5-dca6509cbaf9).  
  
## Equivalência do .NET Framework  
 [System::Diagnostics::PerformanceCounter](https://msdn.microsoft.com/en-us/library/system.diagnostics.performancecounter.aspx)  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [\_crtDbgFlag](../Topic/_crtDbgFlag.md)   
 [\_CrtSetDbgFlag](../../c-runtime-library/reference/crtsetdbgflag.md)