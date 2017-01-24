---
title: "_CrtSetReportHook | Microsoft Docs"
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
  - "_CrtSetReportHook"
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
  - "_CrtSetReportHook"
  - "CrtSetReportHook"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função CrtSetReportHook"
  - "Função _CrtSetReportHook"
ms.assetid: 1ae7c64f-8c84-4797-9574-b59f00f7a509
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtSetReportHook
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Instala uma função definida pelo cliente de relatório enganchando a no processo de relatório de depuração de tempo de execução C \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
_CRT_REPORT_HOOK _CrtSetReportHook(   
   _CRT_REPORT_HOOK reportHook   
);  
```  
  
#### Parâmetros  
 `reportHook`  
 Nova função definida pelo cliente de relatório para conectar no relatório de depuração de tempo de execução C o processo.  
  
## Valor de retorno  
 Retorna a função definida pelo cliente anterior do relatório.  
  
## Comentários  
 `_CrtSetReportHook` permite que um aplicativo usar sua própria função de relatório no processo de relatório da biblioteca de depuração de tempo de execução C.  No resultado, sempre que [\_CrtDbgReport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md) é chamado para gerar um relatório de depuração, a função de relatório do aplicativo é chamada primeiro.  Essa funcionalidade permite que um aplicativo executar operações como relatórios de depuração de filtragem para que possa se concentrarem em tipos específicos de alocação ou enviar um relatório aos destinos não disponíveis usando `_CrtDbgReport`.  Quando [\_DEBUG](../Topic/_DEBUG.md) não for definido, as chamadas para `_CrtSetReportHook` serão removidos durante pré\-processamento.  
  
 Para uma versão mais robusta de `_CrtSetReportHook`, consulte [\_CrtSetReportHook2](../../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md).  
  
 A função de `_CrtSetReportHook` instalar a nova função definida pelo cliente de relatório especificada em `reportHook` e retorna o gancho cliente definido anterior.  O exemplo a seguir demonstra como um gancho definido pelo cliente de relatório deve ser protótipo:  
  
```  
int YourReportHook( int reportType, char *message, int *returnValue );  
```  
  
 onde `reportType` é o tipo de relatório de depuração \(`_CRT_WARN`, `_CRT_ERROR`, ou `_CRT_ASSERT`\), `message` a mensagem é completamente montada do usuário de depuração a ser contidas no relatório e, `returnValue` é o valor especificado pela função definida pelo cliente de relatório que deve ser retornada por `_CrtDbgReport`.  Para obter uma descrição completa dos tipos de relatórios disponíveis, consulte a função de [\_CrtSetReportMode](../../c-runtime-library/reference/crtsetreportmode.md) .  
  
 Se a função definida pelo cliente de relatório manipula completamente a mensagem de depuração de modo que nenhum relatório adicional será necessário, a função deve retornar `TRUE`.  Quando a função retorna `FALSE`, `_CrtDbgReport` é chamado para gerar o relatório de depuração usando as configurações atuais para o tipo de relatório, o modo, e o arquivo.  Além disso, especificando o valor de retorno de `_CrtDbgReport` em `returnValue`, o aplicativo também pode controlar se uma quebra de depuração ocorre.  Para obter uma descrição completa de como o relatório de depuração estiver configurado e gerada, consulte `_CrtSetReportMode`, [\_CrtSetReportFile](../Topic/_CrtSetReportFile.md), e `_CrtDbgReport`.  
  
 Para obter mais informações sobre como usar outras funções gancho\- capazes de tempo de execução e de escrever suas próprias funções definidas pelo cliente de gancho, consulte [Gravação da função de gancho de depuração](../Topic/Debug%20Hook%20Function%20Writing.md).  
  
> [!NOTE]
>  Se seu aplicativo for compilado com `/clr` e a função de relatório é chamada depois que o aplicativo encerrou o main CLR, lançará uma exceção se a função chamar qualquer CRT do relatório funcionam.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtSetReportHook`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Versões de depuração das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [\_CrtGetReportHook](../../c-runtime-library/reference/crtgetreporthook.md)